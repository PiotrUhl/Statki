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

		UIElement leftControl;
		UIElement rightControl;

		public MainWindow() {
			InitializeComponent();
			leftControl = leftGrid;
			rightControl = startMenu;
		}

		public void setLeftControl(UIElement control) {
			control.SetValue(Grid.ColumnProperty, 0);
			control.SetValue(Grid.RowProperty, 0);
			setGridElement(control, leftControl);
		}
		public void setRightControl(UIElement control) {
			control.SetValue(Grid.ColumnProperty, 1);
			control.SetValue(Grid.RowProperty, 0);
			setGridElement(control, rightControl);
		}
		private void setGridElement(UIElement control, UIElement old) {
			mainGrid.Children.Remove(old);
			mainGrid.Children.Add(control);
		}
	}
}
