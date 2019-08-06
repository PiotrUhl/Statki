using System;
using System.Runtime.InteropServices;

namespace CsharpCLI {
	static class DllImports {

		//uruchamia grę, przyjmuje strukturę callBacków
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void runProgram(InitData initData, CallBacks callBacks);

		//sprawdza możliwość położenia statku o rozmiarze "shipSize" w polu o współrzędnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern bool checkShipPlacement(int shipSize, int x, int y, char direction);

		//umieszcza statkek o rozmiarze "shipSize" w polu o współrzędnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern bool placeShip(int shipSize, int x, int y, char direction);

		//wypełnia planszę losowo używając algorytmu
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void fillRandom();

		//zwraca gracza obecnie wykonującego ruch (bądź 0 dla niewłaściwej części gry)
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern int getCurrentPlayer();

		//zwraca typ gracza 'playerId' bądź NONE w przypadku niewłaściwego gracza
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern PlayerType getPlayerType(int playerId);

		//zwraca id planszy w którą strzelono jako ostatnią (bądź 0 jeżeli nie strzelano)
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern int getLastShotBoard();

		//zwraca miejsce ostatniego strzału w planszę 'boardId'; dla 'boardId' = 0 zwraca miejsce ostatniego strzału
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern Point getLastShotPoint(int boardId);

		//zwraca wynik ostatniego strzału w planszę 'boardId'; dla 'boardId' = 0 zwraca wynik ostatniego strzału
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern ShotResult getLastShotResult(int boardId);

		//zapisuje obraz planszy 'boardId' do bufora 'outbuffer'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void getBoardImage(IntPtr outbuffer, int boardId);

		//zwraca obraz punktu 'point' na planszy 'boardId'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern byte getSquareImage(int boardId, Point point);

		//zapisuje mapę strzałów planszy 'boardId' do bufora 'outbuffer'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void getShotMap(IntPtr outbuffer, int boardId);

		//zwraca informację o strzale w pole 'point' na planszy 'boardId'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern ShotResult getSquareShot(int boardId, Point point);

		//zwraca informacje o statku leżącym na polu 'point' na planszy 'boardId'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern ShipInfo getSquareShip(int boardId, Point point);

		//zapisuje informacje o wszystkich statkach na planszy 'boardId' do bufora 'outbuffer'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern void getShipList(IntPtr outbuffer, int boardId);

		//zwraca liczbę statków na planszy 'boardId'
		[DllImport("core.dll", CallingConvention = CallingConvention.Cdecl)]
		public static extern int getShipCount(int boardId);
	}
}
