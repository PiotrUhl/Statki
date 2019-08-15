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

namespace NewGUI {
	public partial class MainWindow : Window {
		public MainWindow() {
			InitializeComponent();
			LeftGrid.addShip(new Point{	x = 1, y = 5}, 4, Direction.HORIZONTAL);
			LeftGrid.addShip(new Point{	x = 6, y = 2}, 2, Direction.VERTICAL);
			LeftGrid.addShip(new Point{	x = 9, y = 3}, 5, Direction.VERTICAL);
			LeftGrid.removeShip(new Point { x = 1, y = 5 });
			LeftGrid.clearShips();
		}
	}
}
