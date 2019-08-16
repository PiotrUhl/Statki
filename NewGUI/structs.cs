using System.Runtime.InteropServices;

namespace NewGUI {

	public enum PlayerType : byte { NONE = 0, HUMAN, AI, REMOTE };

	public enum ShotResult : byte { NONE = 0, MISS, HIT, SUNK };

	public enum Direction : byte { NONE = 0, HORIZONTAL = (byte)'H', VERTICAL = (byte)'V' };

	public enum MsgType : byte { NONE = 0, INFO, WARNING, ERROR }; //typ wiadomości dla metody IUserInterface::msg()

	[StructLayout(LayoutKind.Sequential)]
	public struct Point {
		public int x;
		public int y;
		public Point(int _x, int _y) {
			x = _x;
			y = _y;
		}
		public static bool operator ==(Point left, Point right) {
			return left.x == right.x && left.y == right.y;
		}
		public static bool operator !=(Point left, Point right) {
			return left.x != right.x && left.y != right.y;
		}
	};

	[StructLayout(LayoutKind.Sequential)]
	public struct ShipInfo {
		public int size;
		public Point point;
		public Direction direction;
		public bool sunk;
		public ShipInfo(int _size, Point _point, Direction _direction, bool _sunk = false) {
			size = _size;
			point = _point;
			direction = _direction;
			sunk = _sunk;
		}
		public ShipInfo(int _size, int x, int y, Direction _direction, bool _sunk = false) {
			size = _size;
			point = new Point(x, y);
			direction = _direction;
			sunk = _sunk;
		}
		public static bool operator ==(ShipInfo left, ShipInfo right) {
			return left.size == right.size && left.point == right.point && left.direction == right.direction && left.sunk == right.sunk;
		}
		public static bool operator !=(ShipInfo left, ShipInfo right) {
			return left.size != right.size && left.point != right.point && left.direction != right.direction && left.sunk != right.sunk;
		}
	};

	[StructLayout(LayoutKind.Sequential)]
	public struct InitData {
		public PlayerType player1type;
		public PlayerType player2type;
	};
}
