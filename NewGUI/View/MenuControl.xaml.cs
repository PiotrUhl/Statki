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
	public partial class MenuControl : UserControl {

		public MenuControl() {
			InitializeComponent();
		}

		#region events
		private void StartGame_Click(object sender, RoutedEventArgs e) {
			((App)Application.Current).startGame();
		}
		#endregion
	}
}
