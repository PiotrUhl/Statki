
using System;
using System.Runtime.InteropServices;

namespace CsharpCLI {
	class DllInterface {
		public struct CallBacks {
			//wysyła do interfejsu wiadomość o treści 'msg' o typie 'type'; jeżeli 'critical' przerywa działanie programu
			[UnmanagedFunctionPointer(CallingConvention.StdCall)]
			public delegate void Dg_msg(IntPtr msg, MsgType type, byte critical);
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_msg call_msg;

			//pobiera współrzędne
			[UnmanagedFunctionPointer(CallingConvention.StdCall)]
			public delegate Point Dg_getCoords();
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_getCoords call_getCoords;

			//event - ruch gracza 'playerId'
			[UnmanagedFunctionPointer(CallingConvention.StdCall)]
			public delegate void Dg_event_int(int playerId);
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_event_int event_playerMoved;

			//event - ukończono tworzenie planszy 'boardId'
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_event_int event_boardCreated;


			//wyświetla statki
			[UnmanagedFunctionPointer(CallingConvention.StdCall)]
			public delegate void Dg_sendShipsInfo([MarshalAs(UnmanagedType.LPArray, SizeParamIndex = 1)] IntPtr[] tab, int size, int id);
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_sendShipsInfo call_sendShipsInfo;
			
			//wyświetla czy strzelono w pole
			[UnmanagedFunctionPointer(CallingConvention.StdCall)]
			public delegate void Dg_sendShotMap(IntPtr tab, int size, int id);
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_sendShotMap call_sendShotMap;

			//wypisuje na ekranie błąd
			[UnmanagedFunctionPointer(CallingConvention.StdCall)]
			public delegate void Dg_error(IntPtr error, byte critical);
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_error call_error;

			//przechodzi w tryb tworzenia planszy
			[UnmanagedFunctionPointer(CallingConvention.StdCall)]
			public delegate void Dg_plannerMode();
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_plannerMode call_plannerMode;

			//przechodzi w tryb tworzenia planszy
			[UnmanagedFunctionPointer(CallingConvention.StdCall)]
			public delegate void Dg_sendShotInfo(int id, Point point, ShotResult result);
			[MarshalAs(UnmanagedType.FunctionPtr)]
			public Dg_sendShotInfo call_sendShotInfo;
		}

		//uruchamia grę, przyjmuje strukturę callBacków
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern void runProgram(InitData initData, CallBacks callBacks);
		//sprawdza możliwość położenia statku o rozmiarze "shipSize" w polu o współrzędnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern bool checkShipPlacement(int shipSize, int x, int y, char direction);
		//umieszcza statkek o rozmiarze "shipSize" w polu o współrzędnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern bool placeShip(int shipSize, int x, int y, char direction);
		//wypełnia planszę losowo używając algorytmu
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern void fillRandom();

		//zwraca gracza obecnie wykonującego ruch (bądź 0 dla niewłaściwej części gry)
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern int getCurrentPlayer();
		//zwraca typ gracza 'playerId' bądź NONE w przypadku niewłaściwego gracza
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern PlayerType getPlayerType(int playerId);
		//zwraca id planszy w którą strzelono jako ostatnią (bądź 0 jeżeli nie strzelano)
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern int getLastShotBoard();
		//zwraca miejsce ostatniego strzału w planszę 'boardId'; dla 'boardId' = 0 zwraca miejsce ostatniego strzału
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern Point getLastShotPoint(int boardId);
		//zwraca wynik ostatniego strzału w planszę 'boardId'; dla 'boardId' = 0 zwraca wynik ostatniego strzału
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern ShotResult getLastShotResult(int boardId);
		//zapisuje obraz planszy 'boardId' do bufora 'outbuffer'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern void getBoardImage(IntPtr outbuffer, int boardId);
		//zwraca obraz punktu 'point' na planszy 'boardId'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern byte getSquareImage(int boardId, Point point);
		//zapisuje mapę strzałów planszy 'boardId' do bufora 'outbuffer'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern void getShotMap(IntPtr outbuffer, int boardId);
		//zwraca informację o strzale w pole 'point' na planszy 'boardId'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern ShotResult getSquareShot(int boardId, Point point);
		//zwraca informacje o statku leżącym na polu 'point' na planszy 'boardId'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern ShipInfo getSquareShip(int boardId, Point point);
		//zapisuje informacje o wszystkich statkach na planszy 'boardId' do bufora 'outbuffer'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern void getShipList(IntPtr outbuffer, int boardId);
		//zwraca liczbę statków na planszy 'boardId'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		private static extern int getShipCount(int boardId);
	}
}