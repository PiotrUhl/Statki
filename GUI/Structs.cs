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

	[StructLayout(LayoutKind.Sequential)]
	public struct Point { //punkt w kartezjańskim układzie współrzędnych
		public int x;
		public int y;
		/*public Point (int _x, int _y) {
			x = _x;
			y = _y;
		}*/
	};

	public struct ShipInfo { //informacje o pojedyńczym statku
		public int size;
		public int x;
		public int y;
		public char direction;
		public bool sunk;
		public System.Windows.Shapes.Rectangle drawObj;
	};

	[StructLayout(LayoutKind.Sequential)]
	public struct InitData { 
		public PlayerType player1type;
		public PlayerType player2type;
	};

	public enum ShotResult : byte { NONE = 0, MISS, HIT, SUNK } //informacje o wyniku strzału

	public enum PlayerType : byte { NONE = 0, HUMAN, AI, REMOTE } //typ gracza

	public enum Mode : byte { MENU = 0, PLANNER, GAME, ENDING } //aktywny tryb (część gry)
}