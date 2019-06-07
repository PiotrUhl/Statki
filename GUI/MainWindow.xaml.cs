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
	/// <summary>
	/// Interaction logic for MainWindow.xaml
	/// </summary>

	public struct ShipInfo {
		public int size;
		public int x;
		public int y;
		public char direction;
		public bool sunk;
		public System.Windows.Shapes.Rectangle drawObj;
		public ShipInfo(DllInterface.ShipInfo other) {
			size = other.size;
			x = other.x+1;
			y = other.y + 1; ;
			direction = (char)other.direction;
			sunk = other.sunk;
			drawObj = null;
		}
	}
	public partial class MainWindow : Window {
		public List<ShipInfo> shipList = new List<ShipInfo>();
		private bool[,] shootedMap = new bool[10,10];
		public MainWindow() {
			#region Debug

			#endregion
			InitializeComponent();
		}

		private void TestButton_Click(object sender, RoutedEventArgs e) {
			//RenderNewShip(0);
			//LeftGrid.IsEnabled = true;
			DllInterface dllInterface = new DllInterface(this);
			dllInterface.initAndRun();
		}

		public void RenderShips() {
			foreach (ShipInfo k in shipList) {
				RenderShip(k);
			}
		}
		private void RenderShip(ShipInfo ship) {
			if (ship.drawObj == null) {
				ship.drawObj = new Rectangle {
					Margin = new Thickness(5),
					Stroke = Brushes.Black,
					Fill = Brushes.Black,
					RadiusX = 30,
					RadiusY = 30
				};
				LeftGrid.Children.Add(ship.drawObj);
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
		}

		private void Square_Click(object sender, RoutedEventArgs e) {
			MessageBox.Show(".");
		}
	}
}
