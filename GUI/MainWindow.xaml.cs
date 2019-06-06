﻿using System;
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

	public class DllInterface {
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void runProgram();
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern int addd(int a, int b);
	}

	struct Ship {
		public int size;
		public int x;
		public int y;
		public char direction;
		public bool sunk;
		public System.Windows.Shapes.Rectangle drawObj;
	}
	public partial class MainWindow : Window {
		private Ship[] shipList = new Ship[10];
		private bool[,] shootedMap = new bool[10,10];
		public MainWindow() {
			#region Debug
			shipList = new Ship[10];
			shipList[0].x = 6;
			shipList[0].y = 1;
			shipList[0].size = 4;
			shipList[0].direction = 'V';
			#endregion
			InitializeComponent();
		}

		private void TestButton_Click(object sender, RoutedEventArgs e) {
			RenderNewShip(0);
			LeftGrid.IsEnabled = true;

		}

		private void RenderNewShip(int number) {
			shipList[number].drawObj = new Rectangle {
				Margin = new Thickness(5),
				Stroke = Brushes.Black,
				Fill = Brushes.Black,
				RadiusX = 30,
				RadiusY = 30
			};
			shipList[number].drawObj.SetValue(Grid.ColumnProperty, shipList[number].x);
			shipList[number].drawObj.SetValue(Grid.RowProperty, shipList[number].y);
			if (shipList[number].direction == 'H') {
				shipList[number].drawObj.SetValue(Grid.ColumnSpanProperty, shipList[number].size);
				shipList[number].drawObj.SetValue(Grid.RowSpanProperty, 1);
			}
			else {
				shipList[number].drawObj.SetValue(Grid.ColumnSpanProperty, 1);
				shipList[number].drawObj.SetValue(Grid.RowSpanProperty, shipList[number].size);
			}
			shipList[number].drawObj.Visibility = Visibility.Visible;
			LeftGrid.Children.Add(shipList[number].drawObj);
		}

		private void Square_Click(object sender, RoutedEventArgs e) {
			MessageBox.Show(".");
		}
	}
}
