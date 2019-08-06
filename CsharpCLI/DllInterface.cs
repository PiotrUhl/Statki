using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace CsharpCLI {

	using static Const;

	class DllInterface {

		//uruchamia grę, przyjmuje strukturę callBacków i dane inicjalizacyjne
		public void runProgram(InitData initData, CallBacks callBacks) {
			DllImports.runProgram(initData, callBacks);
		}

		//sprawdza możliwość położenia statku o rozmiarze "shipSize" w polu o współrzędnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo)
		public bool checkShipPlacement(int shipSize, int x, int y, char direction) {
			return DllImports.checkShipPlacement(shipSize, x, y, direction);
		}

		//umieszcza statkek o rozmiarze "shipSize" w polu o współrzędnych ("x", "y"), w kierunku direction ('H' - poziomo, 'V' - pionowo); zwraca rezultat
		public bool placeShip(int shipSize, int x, int y, char direction) {
			return DllImports.placeShip(shipSize, x, y, direction);
		}

		//wypełnia planszę losowo używając algorytmu
		public void fillRandom() {
			DllImports.fillRandom();
		}

		//zwraca gracza obecnie wykonującego ruch (bądź 0 dla niewłaściwej części gry)
		public int getCurrentPlayer() {
			return DllImports.getCurrentPlayer();
		}

		//zwraca typ gracza 'playerId' bądź NONE w przypadku niewłaściwego gracza
		public PlayerType getPlayerType(int playerId) {
			return DllImports.getPlayerType(playerId);
		}

		//zwraca id planszy w którą strzelono jako ostatnią (bądź 0 jeżeli nie strzelano)
		public int getLastShotBoard() {
			return DllImports.getLastShotBoard();
		}

		//zwraca miejsce ostatniego strzału w planszę 'boardId'; dla 'boardId' = 0 zwraca miejsce ostatniego strzału
		public Point getLastShotPoint(int boardId) {
			return DllImports.getLastShotPoint(boardId);
		}

		//zwraca wynik ostatniego strzału w planszę 'boardId'; dla 'boardId' = 0 zwraca wynik ostatniego strzału
		public ShotResult getLastShotResult(int boardId) {
			return DllImports.getLastShotResult(boardId);
		}

		//zwraca obraz planszy 'boardId'
		public unsafe byte[ , ] getBoardImage(int boardId) {
			byte[,] tab = new byte[BOARDSIZE, BOARDSIZE];
			fixed (void* ptr = &tab[0,0]) {
				DllImports.getBoardImage(new IntPtr(ptr), boardId);
			}
			return tab;
		}

		//zwraca obraz punktu 'point' na planszy 'boardId'
		public byte getSquareImage(int boardId, Point point) {
			return DllImports.getSquareImage(boardId, point);
		}

		//zwraca mapę strzałów planszy 'boardId'
		public unsafe ShotResult[ , ] getShotMap(int boardId) {
			ShotResult[,] tab = new ShotResult[BOARDSIZE, BOARDSIZE];
			fixed (void* ptr = &tab[0, 0]) {
				DllImports.getShotMap(new IntPtr(ptr), boardId);
			}
			return tab;
		}

		//zwraca informację o strzale w pole 'point' na planszy 'boardId'
		public ShotResult getSquareShot(int boardId, Point point) {
			return DllImports.getSquareShot(boardId, point);
		}

		//zwraca informacje o statku leżącym na polu 'point' na planszy 'boardId'
		public ShipInfo getSquareShip(int boardId, Point point) {
			return DllImports.getSquareShip(boardId, point);
		}

		//zwraca listę informacji o wszystkich statkach na planszy 'boardId'
		public unsafe List<ShipInfo> getShipList(int boardId) {
			int shipCount = DllImports.getShipCount(boardId);
			ShipInfo[] tab = new ShipInfo[shipCount];
			fixed (void* ptr = &tab[0]) {
				DllImports.getShipList(new IntPtr(ptr), boardId);
			}
			List<ShipInfo> list = new List<ShipInfo>(shipCount);
			foreach (ShipInfo k in tab) {
				list.Add(k);
			}
			return list;
		}

		//zwraca liczbę statków na planszy 'boardId'
		public int getShipCount(int boardId) {
			return DllImports.getShipCount(boardId);
		}
	}
}