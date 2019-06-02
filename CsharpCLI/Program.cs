using System;
using System.Runtime.InteropServices;
using System.Threading;

namespace CsharpCLI {
	static class CoreDll {
		[StructLayout(LayoutKind.Sequential)]
		public struct Point {
			public int x;
			public int y;
		}
		#region DllImport
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern bool getOutFlag();
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern int getOutBuffer();
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void resetOutFlag();
		[DllImport(@"C:\Users\Piotr\source\repos\Statki\Debug\core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void runProgram();
		#endregion

		private static Thread gameThread; //wątek wykonujący główny proces gry
		//uruchamia główny proces gry na wątku gameThread
		public static void runCore() {
			gameThread = new Thread(runProgram);
			gameThread.Start();
		}
		//czeka aż w buforze wyjściowym będą dane i zwraca je
		public static int readOut() {
			while (gameThread.IsAlive && getOutFlag() == false);
			if (gameThread.IsAlive == false)
				throw new InvalidOperationException("gameThread is dead");
			int data = getOutBuffer();
			resetOutFlag();
			return data;
		}
		//zwraca wartość flagi bufora wyjściowego
		public static bool tryOut() {
			if (!gameThread.IsAlive)
				throw new InvalidOperationException("gameThread is dead");
			else
				return getOutFlag();
		}
		//zwraca informacje czy wątek gameThread jest aktywny
		public static bool IsAlive() {
			return gameThread.IsAlive;
		}
	}
	class Program {
		static void Main(string[] args) {
				
		}
	}
}
