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
		}
		private void Planner5_Click(object sender, RoutedEventArgs e) {
			setAllButtons(leftGrid, true);
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
	}
}