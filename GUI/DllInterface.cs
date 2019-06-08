using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace GUI {
	public class DllInterface {
		private MainWindow window; //okno głowne programu

		//konstruktor
		public DllInterface(MainWindow window)  {
			this.window = window;
		}
		
		//inicjalizuje i uruchamia program
		public void initAndRun() {
			CallBacks callBacks = new CallBacks { //inicjalizacja callbacków
				out_registerBoard = in_registerBoard,
				out_sendShipsInfo = in_sendShipsInfo,
				out_sendShotMap = in_sendShotMap,
				out_error = in_error
			};
			InitData init = new InitData {
				boardsize = 10,
				player1type = PlayerType.HUMAN,
				player2type = PlayerType.AI
			};
			runProgram(init, callBacks);
		}

		#region dll methods
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void runProgram(InitData init, CallBacks callBacks); //uruchamia program
		#endregion

		#region callback
		//struktura przechowująca callbacki
		[StructLayout(LayoutKind.Sequential)]
		public struct CallBacks {
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_registerBoard out_registerBoard; //rejestruje id planszy
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_getCoords out_getCoords; //pobiera współrzędne strzału
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_sendShipsInfo out_sendShipsInfo; //wyświetla statki
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_sendShotMap out_sendShotMap; //wyświetla czy strzelono w pole
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_error out_error; ////wypisuje na ekranie błąd
		}

		//deklaracje delegat
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate void Dg_registerBoard(int nr, int id);
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate Point Dg_getCoords();
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate void Dg_sendShipsInfo([MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] IntPtr[] tab, int size, int id);
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate void Dg_sendShotMap(IntPtr tab, int size, int id);
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate void Dg_error(IntPtr error, byte critical);

		//definicje metod przekazywanych do biblioteki .dll
		//rejestruje id planszy
		private void in_registerBoard(int nr, int id) {
			if (nr == 1)
				window.leftId = id;
			else if (nr == 2)
				window.rightId = id;
			else
				throw new Exception("Invalid board number!");
		}
		//wyświetla statki
		private void in_sendShipsInfo(IntPtr[] tab, int size, int id) {
			for (int i = 0; i < size; i++) {
				window.shipList.Add((DllInterface.ShipInfo)Marshal.PtrToStructure(tab[i], typeof(ShipInfo)));
			}
			if (id == window.leftId)
				window.DrawShips(window.LeftGrid);
			else if (id == window.rightId)
				window.DrawShips(window.RightGrid);
			else
				throw new Exception("Invalid board id!");

		}
		//wyświetla czy strzelono w pole
		private void in_sendShotMap(IntPtr tab, int size, int id) {

			byte[] data = new byte[size];
			Marshal.Copy(tab, data, 0, size);
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					window.shotMap[i,j] = (ShotResult)data[i * 10 + j];
				}
			}
		}

		//wypisuje na ekranie błąd "error'; "critical" przerywa działanie programu
		private void in_error(IntPtr error, byte critical) {
			string errorString = Marshal.PtrToStringAnsi(error);
			System.Windows.MessageBox.Show(errorString);
			if (critical != 0) {
				//System.Windows.Application.Current.Shutdown();
				//window.Close();
				Environment.Exit(-1);
			}
		}

		//inne techniczne
		[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
		private struct ShipInfo { //informacje o pojedyńczym statku
			public int size;
			public int x;
			public int y;
			public byte direction;
			public byte sunk;
			public static implicit operator GUI.ShipInfo(DllInterface.ShipInfo self) {
				return new GUI.ShipInfo {
					size = self.size,
					x = self.x + 1,
					y = self.y + 1,
					direction = (char)self.direction,
					sunk = Convert.ToBoolean(self.sunk),
					drawObj = null
				};
			}
		}
		#endregion
	}
}
