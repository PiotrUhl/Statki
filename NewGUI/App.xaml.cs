using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace NewGUI {

	public partial class App : Application {

		Board board1;
		Board board2;

		App() {
			InitializeComponent();
		}

		[STAThread] //main
		static void Main(string[] args) {
			App app = new App();
			View.MainWindow mainWindow = new View.MainWindow();
			app.Run(mainWindow);
		}

		//rozpoczyna grę
		public static void startGame() {
			MessageBox.Show("Game started"); //debug
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
		//callback do tworzenia front-endowej wersji planszy
		public void boardCreated(int boardId) {
			Board board = selectBoard(boardId);
			board = new Board(boardId, new View.BoardControl());
			List<ShipInfo> list = DllInterface.getShipList(boardId);
			foreach (var k in list) {
				board.add(k);
			}
		}
	}
}