using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NewGUI {
	class Board {

		private readonly int boardId; //id planszy
		private View.BoardControl view; //powiązana kontrolka w widoku
		private List<ShipInfo> shipList; //lista statków na planszy

		//konstruktor
		public Board(int _boardId, View.BoardControl _view) {
			boardId = _boardId;
			view = _view;
		}

		//dodaje statek do planszy
		public void add(ShipInfo ship) {
			shipList.Add(ship);
			view.addShip(ship);
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

	}
}
