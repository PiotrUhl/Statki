using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace GUI {
	[StructLayout(LayoutKind.Sequential)]
	public struct Point {
		public int x;
		public int y;
	}

	public class DllInterface {
		public MainWindow window;
		public DllInterface(MainWindow window) {
			this.window = window;
		}

		#region funkcje_dll
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void runProgram(CallBacks _);
		#endregion

		#region delegaty
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate Point Dg_getCoords();
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate void Dg_sendBoardInfo([MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] IntPtr[] tab, int size);
		#endregion

		#region callBacki
		[StructLayout(LayoutKind.Sequential)]
		public struct CallBacks {
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_getCoords out_getCoords;
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_sendBoardInfo out_sendBoardInfo;
		}
		#endregion

		#region metody_do_delegatów
		private void sendBoardInfo(IntPtr[] tab, int size) {
			//List<ShipInfo> tempList = new List<ShipInfo>();
			for (int i = 0; i < size; i++) {
				//tempList.Add((ShipInfo)Marshal.PtrToStructure(tab[i], typeof(ShipInfo)));
				window.shipList.Add(new GUI.ShipInfo((DllInterface.ShipInfo)Marshal.PtrToStructure(tab[i], typeof(ShipInfo))));
			}
			window.RenderShips();
		}
		#endregion

		[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
		public struct ShipInfo {
			public int size;
			public int x;
			public int y;
			public byte direction;
			public bool sunk;
		}

		public void initAndRun() {
			CallBacks callBacks = new CallBacks {
				out_sendBoardInfo = sendBoardInfo
			};
			runProgram(callBacks);
		}

	}
}
