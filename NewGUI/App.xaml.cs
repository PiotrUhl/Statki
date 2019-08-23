using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace NewGUI {

	public partial class App : Application {

		static App app; //statyczny obiekt, niezbędny dla statycznych callbacków
		static Thread coreThread;

		View.MainWindow mainWindow;

		Board board1;
		Board board2;

		//widoczność plansz
		bool board1visibility;
		bool board2visibility;

		App() {
			InitializeComponent();
		}

		[STAThread] //main
		static void Main(string[] args) {
			//toadd: testowanie biblioteki .dll

			app = new App();
			app.mainWindow = new View.MainWindow();
			app.Run(app.mainWindow);
		}

		//inicjalizuje callbacki
		private void initializeCallbacks() {
			DllInterface.setCall_msg(msg);
			DllInterface.setCall_enterPlannerMode(enterPlannerMode);
			DllInterface.setCall_getCoords(getCoords);
			DllInterface.setEvent_boardCreated(boardCreated);
			DllInterface.setEvent_playerMoved(playerMoved);
			DllInterface.setEvent_gameEnded(gameEnded);
		}

		//rozpoczyna grę
		public void startGame() {
			initializeCallbacks();
			InitData initData = new InitData {
				player1type = PlayerType.HUMAN,
				player2type = PlayerType.AI
			};
			board1visibility = true;
			board2visibility = false;
			MessageBox.Show("Game started"); //debug
			coreThread = new Thread(() => DllInterface.runProgram(initData));
			coreThread.IsBackground = true;
			coreThread.Start();
		}

		//zwraca referencję na planszę o danym id
		private Board selectBoard(int boardId) {
			if (boardId == 1)
				return board1;
			else if (boardId == 2)
				return board2;
			else
				throw new ArgumentException("Invalid boardId");
		}
		//zwraca referencję na planszę NIE o danym id
		private Board notSelectBoard(int boardId) {
			if (boardId == 1)
				return board2;
			else if (boardId == 2)
				return board1;
			else
				throw new ArgumentException("Invalid boardId");
		}

		//callback do tworzenia front-endowej wersji planszy
		public static void boardCreated(int boardId) {
			View.BoardControl view = app.mainWindow.Dispatcher.Invoke(() => {
				 return new View.BoardControl();
			});
			bool visibility;
			if (boardId == 1) {
				visibility = app.board1visibility;
			}
			else if (boardId == 2) {
				visibility = app.board2visibility;
			}
			else {
				throw new ArgumentException("Incorrect board id");
			}
			Board board = new Board(boardId, visibility, view);
			List<ShipInfo> list = DllInterface.getShipList(boardId);
			foreach (var k in list) {
				board.add(k);
			}
			if (boardId == 1) {
				app.board1 = board;
				app.mainWindow.Dispatcher.Invoke(() => app.mainWindow.setLeftControl(view));
			}
			else if (boardId == 2) {
				app.board2 = board;
				app.mainWindow.Dispatcher.Invoke(() => app.mainWindow.setRightControl(view));
			}
			else
				throw new ArgumentException("Invalid boardId");
		}

		//callback do włączenia trybu projektowania planszy
		public static void enterPlannerMode() {
			DllInterface.fillRandom();
		}

		//callback do pobierania współrzędnych strzału
		public static Point getCoords() {
			//return new Point(0, 0);
			return app.notSelectBoard(DllInterface.getCurrentPlayer()).getCoords();
		}

		//callback
		public static void msg(string msg, MsgType type, bool critical) {
			switch (type) {
				case MsgType.INFO:
					MessageBox.Show(msg, "Information", MessageBoxButton.OK, MessageBoxImage.Information);
					break;
				case MsgType.WARNING:
					MessageBox.Show(msg, "Warning", MessageBoxButton.OK, MessageBoxImage.Warning);
					break;
				case MsgType.ERROR:
					MessageBox.Show(msg, "Error", MessageBoxButton.OK, MessageBoxImage.Error);
					break;
				default:
					throw new InvalidEnumArgumentException("Invalid message type");
			}
		}

		//callback
		public static void gameEnded(int winner) {
			app.board1.showAllShips();
			app.board2.showAllShips();
			if (winner == 1) {
				MessageBox.Show("Wygrana", "Koniec gry", MessageBoxButton.OK, MessageBoxImage.Information);
			}
			else if (winner == 2) {
				MessageBox.Show("Przegrana", "Koniec gry", MessageBoxButton.OK, MessageBoxImage.Error);
			}
			else {
				MessageBox.Show("Remis", "Koniec gry", MessageBoxButton.OK, MessageBoxImage.Warning);
			}
		}

		//callback
		public static void playerMoved(int playerId) {
			Point point = DllInterface.getLastShotPoint();
			ShotResult result = DllInterface.getLastShotResult();
			//MessageBox.Show("Player " + playerId + " shooted field (" + point.x + ", " + point.y + ") with result: " + result + ".");
			Board board = app.selectBoard(DllInterface.getLastShotBoard());
			board.setState(point, result);
		}

		public static void debugShot(object sender, RoutedEventArgs e) {
			int x = (int)((Button)sender).GetValue(Grid.ColumnProperty);
			int y = (int)((Button)sender).GetValue(Grid.RowProperty);
			MessageBox.Show("Kliknięto pole (" + x + "," + y + ").", "Shot debug");
		}
	}
}