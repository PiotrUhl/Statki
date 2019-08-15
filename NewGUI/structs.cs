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
	};

	[StructLayout(LayoutKind.Sequential)]
	public struct InitData {
		public PlayerType player1type;
		public PlayerType player2type;
	};

	[StructLayout(LayoutKind.Sequential)]
	public struct ShipInfo {
		public int size;
		public Point point;
		public Direction direction;
		public bool sunk;
	};
}
