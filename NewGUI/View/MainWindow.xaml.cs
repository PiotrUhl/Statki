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

namespace NewGUI.View {
	public partial class MainWindow : Window {
		public MainWindow() {
			InitializeComponent();
			/*leftGrid.addShip(new ShipInfo { size = 4, point = new Point{ x = 1, y = 5 }, direction = Direction.HORIZONTAL, sunk = false });
			leftGrid.addShip(2, new Point{ x = 6, y = 2 }, Direction.VERTICAL);
			leftGrid.addShip(new ShipInfo { size = 5, point = new Point{ x = 9, y = 3 }, direction = Direction.VERTICAL, sunk = false });
			leftGrid.removeShip(new Point { x = 1, y = 5 });
			leftGrid.removeShip(new ShipInfo { size = 5, point = new Point { x = 9, y = 3 }, direction = Direction.VERTICAL, sunk = false });
			leftGrid.clearShips();*/
		}
	}
}
