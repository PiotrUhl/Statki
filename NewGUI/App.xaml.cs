using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace NewGUI {

	public partial class App : Application {

		App() {
			InitializeComponent();
		}

		[STAThread]
		static void Main(string[] args) {
			App app = new App();
			View.MainWindow mainWindow = new View.MainWindow();
			app.Run(mainWindow);

		}

	}

}
