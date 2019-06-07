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
				out_sendShipsInfo = in_sendShipsInfo,
				out_sendShotMap = in_sendShotMap
			};
			runProgram(callBacks);
		}

		#region dll methods
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void runProgram(CallBacks _); //uruchamia program
		#endregion

		#region callback
		//struktura przechowująca callbacki
		[StructLayout(LayoutKind.Sequential)]
		public struct CallBacks {
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_getCoords out_getCoords; //pobiera współrzędne strzału
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_sendShipsInfo out_sendShipsInfo; //wyświetla statki
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_sendShotMap out_sendShotMap; //wyświetla czy strzelono w pole
		}

		//deklaracje delegat
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate Point Dg_getCoords();
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate void Dg_sendShipsInfo([MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] IntPtr[] tab, int size);
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate void Dg_sendShotMap(IntPtr tab, int size);

		//definicje metod przekazywanych do biblioteki .dll
		//wyświetla statki
		private void in_sendShipsInfo(IntPtr[] tab, int size) {
			for (int i = 0; i < size; i++) {
				window.shipList.Add((DllInterface.ShipInfo)Marshal.PtrToStructure(tab[i], typeof(ShipInfo)));
			}
			window.RenderShips();
		}
		//wyświetla czy strzelono w pole
		private void in_sendShotMap(IntPtr tab, int size) {

			byte[] data = new byte[size];
			Marshal.Copy(tab, data, 0, size);
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					window.shotMap[i,j] = (ShotResult)data[i * 10 + j];
				}
			}
		}

		//inne techniczne
		[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
		private struct ShipInfo { //informacje o pojedyńczym statku
			public int size;
			public int x;
			public int y;
			public byte direction;
			public bool sunk;
			public static implicit operator GUI.ShipInfo(DllInterface.ShipInfo self) {
				return new GUI.ShipInfo {
					size = self.size,
					x = self.x + 1,
					y = self.y + 1,
					direction = (char)self.direction,
					sunk = self.sunk,
					drawObj = null
				};
			}
		}
		#endregion


	}
}
