using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace CsharpCLI {

	using static Const;

	static class DllInterface {

		static DllExports dllExports;

		//konstruktor
		static DllInterface() { dllExports = new DllExports(); }

		#region callBacks
		static public void setCall_msg(DllExports.Dg_void_string_MsgType_bool dg) { dllExports.call_msg = dg; }
		static public void setCall_getCoords(DllExports.Dg_Point_void dg) { dllExports.call_getCoords = dg; }
		static public void setCall_enterPlannerMode(DllExports.Dg_void_void dg) { dllExports.call_enterPlannerMode = dg; }
		static public void setEvent_playerMoved(DllExports.Dg_void_int dg) { dllExports.event_playerMoved = dg; }
		static public void setEvent_boardCreated(DllExports.Dg_void_int dg) { dllExports.event_boardCreated = dg; }
		#endregion

		#region dllFunctions
		//uruchamia grę, przyjmuje strukturę callBacków i dane inicjalizacyjne
		static public void runProgram(InitData initData) {
			if (dllExports.call_msg == null || dllExports.call_getCoords == null || dllExports.call_enterPlannerMode == null)
				throw new InvalidOperationException("Necessary callback uninitialized");
			else
				DllImports.runProgram(initData, dllExports.callBacks);
		}

		//sprawdza możliwość położenia statku o rozmiarze 'shipSize' w polu 'point', w kierunku 'direction'
		static public bool checkShipPlacement(int shipSize, Point point, Direction direction) {
			return DllImports.checkShipPlacement(shipSize, point, direction);
		}

		//umieszcza statkek o rozmiarze 'shipSize' w polu 'point', w kierunku 'direction'; zwraca rezultat
		static public bool placeShip(int shipSize, Point point, Direction direction) {
			return DllImports.placeShip(shipSize, point, direction);
		}

		//wypełnia planszę losowo używając algorytmu
		static public void fillRandom() {
			DllImports.fillRandom();
		}

		//zwraca gracza obecnie wykonującego ruch (bądź 0 dla niewłaściwej części gry)
		static public int getCurrentPlayer() {
			return DllImports.getCurrentPlayer();
		}

		//zwraca typ gracza 'playerId' bądź NONE w przypadku niewłaściwego gracza
		static public PlayerType getPlayerType(int playerId) {
			return DllImports.getPlayerType(playerId);
		}

		//zwraca id planszy w którą strzelono jako ostatnią (bądź 0 jeżeli nie strzelano)
		static public int getLastShotBoard() {
			return DllImports.getLastShotBoard();
		}

		//zwraca miejsce ostatniego strzału w planszę 'boardId'; dla 'boardId' = 0 zwraca miejsce ostatniego strzału
		static public Point getLastShotPoint(int boardId = 0) {
			return DllImports.getLastShotPoint(boardId);
		}

		//zwraca wynik ostatniego strzału w planszę 'boardId'; dla 'boardId' = 0 zwraca wynik ostatniego strzału
		static public ShotResult getLastShotResult(int boardId = 0) {
			return DllImports.getLastShotResult(boardId);
		}

		//zwraca obraz planszy 'boardId'
		static public unsafe byte[,] getBoardImage(int boardId) {
			byte[,] tab = new byte[BOARDSIZE, BOARDSIZE];
			fixed (void* ptr = &tab[0, 0]) {
				DllImports.getBoardImage(new IntPtr(ptr), boardId);
			}
			return tab;
		}

		//zwraca obraz punktu 'point' na planszy 'boardId'
		static public byte getSquareImage(int boardId, Point point) {
			return DllImports.getSquareImage(boardId, point);
		}

		//zwraca mapę strzałów planszy 'boardId'
		static public unsafe ShotResult[,] getShotMap(int boardId) {
			ShotResult[,] tab = new ShotResult[BOARDSIZE, BOARDSIZE];
			fixed (void* ptr = &tab[0, 0]) {
				DllImports.getShotMap(new IntPtr(ptr), boardId);
			}
			return tab;
		}

		//zwraca informację o strzale w pole 'point' na planszy 'boardId'
		static public ShotResult getSquareShot(int boardId, Point point) {
			return DllImports.getSquareShot(boardId, point);
		}

		//zwraca informacje o statku leżącym na polu 'point' na planszy 'boardId'
		static public ShipInfo getSquareShip(int boardId, Point point) {
			ShipInfo ret = new ShipInfo();
			DllImports.getSquareShip(ref ret, boardId, point);
			return ret;
		}

		//zwraca listę informacji o wszystkich statkach na planszy 'boardId'
		static public unsafe List<ShipInfo> getShipList(int boardId) {
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
		static public int getShipCount(int boardId) {
			return DllImports.getShipCount(boardId);
		}
		#endregion

	}
}