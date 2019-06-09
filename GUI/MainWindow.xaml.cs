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
			//MessageBox.Show("Kliknięto pole (" + x + "," + y + ").");
			if (mode == Mode.PLANNER && selectedShip > 0 && selectedDirection != '0') {
				ShipInfo ship = new ShipInfo {
					size = selectedShip,
					x = x,
					y = y,
					direction = selectedDirection,
					sunk = false
				};
				if (DllInterface.placeShip(ship.size, ship.x-1, ship.y-1, ship.direction) == true) {
					DrawShip((Grid)square.Parent, ship);
					switch (ship.size) {
						case 5:
							PlannerCount5.Content = 1 - ++ship5placed;
							if (ship5placed == 1) {
								selectedShip = 0;
								PlannerLabel5.FontWeight = FontWeights.Light;
							}
							break;
						case 4:
							PlannerCount4.Content = 2 - ++ship4placed;
							if (ship4placed == 2) {
								selectedShip = 0;
								PlannerLabel4.FontWeight = FontWeights.Light;
							}
							break;
						case 3:
							PlannerCount3.Content = 3 - ++ship3placed;
							if (ship3placed == 3) {
								selectedShip = 0;
								PlannerLabel3.FontWeight = FontWeights.Light;
							}
							break;
						case 2:
							PlannerCount2.Content = 4 - ++ship2placed;
							if (ship2placed == 4) {
								selectedShip = 0;
								PlannerLabel2.FontWeight = FontWeights.Light;
							}
							break;
						default:
							throw new Exception("Incorrect ship size");
					}
					if (ship5placed == 1 && ship4placed == 2 && ship3placed == 3 && ship2placed == 4) {
						ButtonPlannerConfirm.IsEnabled = true;
					}
				}
			}
			else if (mode == Mode.GAME) {
				square.IsEnabled = false;
				shotPoint = new Point() {
					x = x-1,
					y = y-1
				};
				dllInterface.waitingForCoords.Set();
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
		private void PlannerButtonH_Click(object sender, RoutedEventArgs e) {
			selectedDirection = 'H';
			PlannerLabelH.FontWeight = FontWeights.Bold;
			PlannerLabelV.FontWeight = FontWeights.Normal;
		}
		private void PlannerButtonV_Click(object sender, RoutedEventArgs e) {
			selectedDirection = 'V';
			PlannerLabelH.FontWeight = FontWeights.Normal;
			PlannerLabelV.FontWeight = FontWeights.Bold;
		}
		private void ButtonPlannerConfirm_Click(object sender, RoutedEventArgs e) {
			BoardPlanner.Visibility = Visibility.Collapsed;
			rightGrid.Visibility = Visibility.Visible;
			setAllButtons(leftGrid, false);
			InitializeBoard(rightGrid, true);
			dllInterface.waitingInPlannerMode.Set();
		}
		private void ButtonPlannerRandom_Click(object sender, RoutedEventArgs e) {
			MessageBox.Show("Not yet implemented!");
		}
	}
}