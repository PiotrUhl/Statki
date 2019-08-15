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
			Point point = new Point{
				x = 1, y = 5
			};
			LeftGrid.addShip(point, 4, Direction.HORIZONTAL);
		}
	}
}
