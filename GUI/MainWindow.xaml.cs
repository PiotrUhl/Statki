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

	public partial class MainWindow : Window {
		#region fields
		public List<ShipInfo> shipList = new List<ShipInfo>(); //lista wszystkich statków na planszy
		public ShotResult[,] shotMap = new ShotResult[10,10]; //informacja w które pola strzelano
		#endregion
		#region public methods
		public MainWindow() {
			InitializeComponent();
		}

		public void RenderShips() { //aktualizuje planszę rysując wszystkie statki z listy shipList
			foreach (ShipInfo k in shipList) {
				RenderShip(k);
			}
		}
		#endregion
		#region event handlers
		private void TestButton_Click(object sender, RoutedEventArgs e) {
			DllInterface dllInterface = new DllInterface(this);
			dllInterface.initAndRun();
		}
		private void Square_Click(object sender, RoutedEventArgs e) {
			MessageBox.Show(".");
		}
		#endregion
		#region private methods
		private void RenderShip(ShipInfo ship) { //rysuje bądź aktualizuje statek "ship" na planszy
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
		#endregion
	}
}