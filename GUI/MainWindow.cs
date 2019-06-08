using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using System.Runtime.InteropServices;

namespace GUI {
	public partial class MainWindow : Window {

		//handlery
		public Grid mainGrid;
		public Grid leftGrid;
		public Grid rightGrid;
		public List<ShipInfo> shipList = new List<ShipInfo>(); //lista wszystkich statków na planszy
		public Button[,] leftBoard = new Button[10, 10]; //lewa plansza

		private DllInterface dllInterface;
		public ShotResult[,] shotMap = new ShotResult[10, 10]; //informacja w które pola strzelano
		public int leftId;
		public int rightId;
		Mode mode = Mode.MENU; //aktywny tryb

		//planner
		int selectedShip = 0;
		int ship5placed = 0;
		int ship4placed = 0;
		int ship3placed = 0;
		int ship2placed = 0;

		//aktualizuje planszę rysując wszystkie statki z listy shipList
		public void DrawShips(Grid grid) {
			foreach (ShipInfo k in shipList) {
				DrawShip(grid, k);
				DisableSquaresUnderShip(k);
			}
		}

		//wchodzi w tryb plannerMode
		public void enterPlannerMode() {
			Dispatcher.Invoke(() => {
				BoardPlanner.Visibility = Visibility.Visible;
				setAllButtons(leftGrid, true);
			});
			mode = Mode.PLANNER;
		}

		//zmienia parametr IsEnabled wszystkich przycisków na planszy
		private void setAllButtons(Grid grid, bool val) {
			Button[,] board;
			if (grid.Name == "LeftGrid")
				board = leftBoard;
			else if (grid.Name == "RightGrid")
				board = leftBoard;
			else
				throw new Exception("Incorrect grid name");
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					board[i, j].IsEnabled = val;
				}
			}
		}

		//inicjalizuje planszę
		private void InitializeBoard(Grid grid) {
			Button[,] board;
			if (grid.Name == "LeftGrid")
				board = leftBoard;
			else if (grid.Name == "RightGrid")
				board = leftBoard;
			else
				throw new Exception("Incorrect grid name");
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					board[i, j] = new Button();
					board[i, j].SetValue(Grid.ColumnProperty, i + 1);
					board[i, j].SetValue(Grid.RowProperty, j + 1);
					board[i, j].Template = (ControlTemplate)FindResource("ButtonRectangle");
					board[i, j].IsEnabled = false;
					board[i, j].Click += Square_Click;
					grid.Children.Add(leftBoard[i, j]);
				}
			}
		}

		//wyłącza pola pod stawianym statkiem
		private void DisableSquaresUnderShip(ShipInfo ship) {
			int x = ship.x - 1;
			int y = ship.y - 1;
			for (int i = 0; i < ship.size; i++) {
				leftBoard[x, y].IsEnabled = false;
				if (ship.direction == 'H')
					x++;
				else if (ship.direction == 'V')
					y++;
				else
					throw new Exception("Invalid ship direction!"); //nie powinno nigdy wystąpić!
			}
		}

		//rysuje bądź aktualizuje statek "ship" na planszy
		private void DrawShip(Grid grid, ShipInfo ship) {
			if (ship.drawObj == null) {
				ship.drawObj = new Rectangle {
					Margin = new Thickness(5),
					Stroke = Brushes.Black,
					Fill = Brushes.Black,
					RadiusX = 30,
					RadiusY = 30
				};
				grid.Children.Add(ship.drawObj);
			}
			ship.drawObj.SetValue(Grid.ColumnProperty, ship.x);
			ship.drawObj.SetValue(Grid.RowProperty, ship.y);
			if (ship.direction == 'H') {
				ship.drawObj.SetValue(Grid.ColumnSpanProperty, ship.size);
				ship.drawObj.SetValue(Grid.RowSpanProperty, 1);
			}
			else {
				ship.drawObj.SetValue(Grid.ColumnSpanProperty, 1);
				ship.drawObj.SetValue(Grid.RowSpanProperty, ship.size);
			}
			if (ship.sunk == true) {
				ship.drawObj.Opacity = 0.75;
				ship.drawObj.Fill = Brushes.LightSlateGray;
				ship.drawObj.Stroke = Brushes.LightSlateGray;
			}
		}

		//usuwa statek z planszy
		private void DeleteShip(Grid grid, ShipInfo ship) {
			grid.Children.Remove(ship.drawObj);
		}
	}
}