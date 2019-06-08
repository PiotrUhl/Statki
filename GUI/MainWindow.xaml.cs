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
		//konstruktor
		public MainWindow() {
			InitializeComponent();
			mainGrid = (Grid)FindName("MainGrid");
			leftGrid = (Grid)FindName("LeftGrid");
			rightGrid = (Grid)FindName("RightGrid");
			InitializeBoard(leftGrid);
		}

		//event handlery
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
			if (mode == Mode.PLANNER && selectedShip > 0) {
				ShipInfo ship = new ShipInfo {
					size = selectedShip,
					x = x,
					y = y,
					direction = 'H',
					sunk = false
				};
				if (DllInterface.placeShip(ship.size, ship.x-1, ship.y-1, ship.direction) == true) {
					DrawShip((Grid)square.Parent, ship);
				}
			}
		}
		private void Planner5_Click(object sender, RoutedEventArgs e) {
			if (ship5placed < 1) {
				selectedShip = 5;
				PlannerLabel2.FontWeight = FontWeights.Normal;
				PlannerLabel3.FontWeight = FontWeights.Normal;
				PlannerLabel4.FontWeight = FontWeights.Normal;
				PlannerLabel5.FontWeight = FontWeights.Bold;
			}
		}
		private void Planner4_Click(object sender, RoutedEventArgs e) {
			if (ship4placed < 2) {
				selectedShip = 4;
				PlannerLabel2.FontWeight = FontWeights.Normal;
				PlannerLabel3.FontWeight = FontWeights.Normal;
				PlannerLabel4.FontWeight = FontWeights.Bold;
				PlannerLabel5.FontWeight = FontWeights.Normal;
			}
		}
		private void Planner3_Click(object sender, RoutedEventArgs e) {
			if (ship3placed < 3) {
				selectedShip = 3;
				PlannerLabel2.FontWeight = FontWeights.Normal;
				PlannerLabel3.FontWeight = FontWeights.Bold;
				PlannerLabel4.FontWeight = FontWeights.Normal;
				PlannerLabel5.FontWeight = FontWeights.Normal;
			}
		}
		private void Planner2_Click(object sender, RoutedEventArgs e) {
			if (ship2placed < 4) {
				selectedShip = 2;
				PlannerLabel2.FontWeight = FontWeights.Bold;
				PlannerLabel3.FontWeight = FontWeights.Normal;
				PlannerLabel4.FontWeight = FontWeights.Normal;
				PlannerLabel5.FontWeight = FontWeights.Normal;
			}
		}
		private void ButtonPlannerConfirm_Click(object sender, RoutedEventArgs e) {
			dllInterface.waitingInPlannerMode.Set();
		}
		private void ButtonPlannerRandom_Click(object sender, RoutedEventArgs e) {
			;
		}
	}
}