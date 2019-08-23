using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using static NewGUI.Const;

namespace NewGUI {
	class Board {

		private readonly int boardId; //id planszy
		private View.BoardControl view; //powiązana kontrolka w widoku
		private List<ShipInfo> shipList; //lista statków na planszy
		private ShotResult[ , ] shotMap;
		private bool visibility; //wyświetlanie statków na planszy

		//konstruktor
		public Board(int _boardId, bool _visibility, View.BoardControl _view) {
			shipList = new List<ShipInfo>();
			boardId = _boardId;
			view = _view;
			shotMap = new ShotResult[BOARDSIZE, BOARDSIZE];
			visibility = _visibility;
		}

		//dodaje statek do planszy
		public void add(ShipInfo ship) {
			shipList.Add(ship);
			if (visibility == true) {
				view.Dispatcher.Invoke(() => view.addShip(ship));
			}
		}

		//usuwa statek z planszy
		public void remove(ShipInfo ship) {
			shipList.Remove(ship);
			view.removeShip(ship);
		}

		//usuwa wszystkie statki z planszy
		public void clear() {
			shipList.Clear();
			view.clearShips();
		}

		//wyświetla wszystkie statki na planszy (jeżeli visibility == true nie robi nic)
		public void showAllShips() {
			if (visibility == false) {
				foreach (var k in shipList) {
					view.Dispatcher.Invoke(() => view.addShip(k));
				}
			}
		}

		//ustawia stan pola 'point' na 'state'
		public void setState(Point point, ShotResult state) {
			if (state == ShotResult.SUNK) {
				ShipInfo ship = DllInterface.getSquareShip(boardId, point);
				if (ship.direction == Direction.HORIZONTAL) {
					for (int i = 0; i < ship.size; i++) {
						shotMap[ship.point.y, ship.point.x + i] = state;
						view.Dispatcher.Invoke(() => view.setState(ship.point.x + i, ship.point.y, state));
					}
				}
				else if (ship.direction == Direction.VERTICAL) {
					for (int i = 0; i < ship.size; i++) {
						shotMap[ship.point.y + i, ship.point.x] = state;
						view.Dispatcher.Invoke(() => view.setState(ship.point.x, ship.point.y + i, state));
					}
				}
				else {
					throw new InvalidEnumArgumentException("Invalid ShotResult state");
				}
				if (visibility == false) {
					view.Dispatcher.Invoke(() => view.addShip(ship));
				}
				view.Dispatcher.Invoke(() => view.sinkShip(ship));
			}
			else {
				shotMap[point.y, point.x] = state;
				view.Dispatcher.Invoke(() => view.setState(point, state));
			}
		}

		//pobiera i zwraca współrzędne strzału w planszę od użytkownika
		public Point getCoords() {
			//return view.Dispatcher.Invoke(() => { return view.getCoords(); });
			return view.getCoords();
		}
	}
}
