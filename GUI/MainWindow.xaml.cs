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
		#region GUI handlers
		public Grid mainGrid;
		public Grid leftGrid;
		public Grid rightGrid;
		public List<ShipInfo> shipList = new List<ShipInfo>(); //lista wszystkich statków na planszy
		public Button[,] leftBoard = new Button[10, 10]; //lewa plansza
		#endregion
		#region fields
		public ShotResult[,] shotMap = new ShotResult[10, 10]; //informacja w które pola strzelano
		public int leftId;
		public int rightId;
		private DllInterface dllInterface;
		#endregion
		#region public methods
		public MainWindow() {
			InitializeComponent();
			mainGrid = (Grid)FindName("MainGrid");
			leftGrid = (Grid)FindName("LeftGrid");
			rightGrid = (Grid)FindName("RightGrid");
			InitializeBoard(leftGrid);
		}

		//aktualizuje planszę rysując wszystkie statki z listy shipList
		public void DrawShips(Grid grid) {
			foreach (ShipInfo k in shipList) {
				DrawShip(grid, k);
				DisableSquaresUnderShip(k);
			}
		}

		//wchodzi w tryb plannerMode
		public void enterPlannerMode() {
			Dispatcher.Invoke(() =>	{
				BoardPlanner.Visibility = Visibility.Visible;
			});
		}
		#endregion
		#region event handlers
		private void StartButton_Click(object sender, RoutedEventArgs e) {
			dllInterface = new DllInterface(this);
			Menu.Visibility = Visibility.Collapsed;
			dllInterface.initAndRun();
		}
		private void Square_Click(object sender, RoutedEventArgs e) {
			Button square = (Button)sender;
			int x = (int)square.GetValue(Grid.ColumnProperty);
			int y = (int)square.GetValue(Grid.RowProperty);
			MessageBox.Show("Kliknięto pole (" + x + "," + y + ").");
		}
		private void Planner5_Click(object sender, RoutedEventArgs e) {
			;
		}
		private void Planner4_Click(object sender, RoutedEventArgs e) {
			;
		}
		private void Planner3_Click(object sender, RoutedEventArgs e) {
			;
		}
		private void Planner2_Click(object sender, RoutedEventArgs e) {
			;
		}
		private void ButtonPlannerConfirm_Click(object sender, RoutedEventArgs e) {
			dllInterface.waitingInPlannerMode.Set();
		}
		private void ButtonPlannerRandom_Click(object sender, RoutedEventArgs e) {
			;
		}
		#endregion
		#region private methods
		//inicjalizuje planszę
		void InitializeBoard(Grid grid) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					leftBoard[i, j] = new Button();
					leftBoard[i, j].SetValue(Grid.ColumnProperty, i+1);
					leftBoard[i, j].SetValue(Grid.RowProperty, j+1);
					leftBoard[i, j].Template = (ControlTemplate)FindResource("ButtonRectangle");
					//leftGrid[i, j].IsEnabled = false;
					leftBoard[i, j].Click += Square_Click;
					grid.Children.Add(leftBoard[i,j]);
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
		#endregion
	}
}