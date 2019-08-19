using System;
using System.Collections.Generic;
using System.ComponentModel;
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
	public partial class ShotMarkControl : UserControl {
		public ShotMarkControl(ShotResult shape) {
			InitializeComponent();
			switch (shape) {
				case ShotResult.MISS:
					initializeMISS();
					break;
				case ShotResult.HIT:
					initializeHIT();
					break;
				case ShotResult.SUNK:
					initializeSUNK();
					break;
				default:
					throw new InvalidEnumArgumentException("Invalid hot result");
			}
		}

		private void initializeMISS() {
			oMark.Stroke = new SolidColorBrush(Colors.Blue);
			oMark.Visibility = Visibility.Visible;
		}
		private void initializeHIT() {
			xLine1.Stroke = new SolidColorBrush(Colors.Red);
			xLine2.Stroke = new SolidColorBrush(Colors.Red);
			xMark.Visibility = Visibility.Visible;
		}
		private void initializeSUNK() {
			xLine1.Stroke = new SolidColorBrush(Colors.Yellow);
			xLine2.Stroke = new SolidColorBrush(Colors.Yellow);
			xMark.Visibility = Visibility.Visible;
		}
	}
}
