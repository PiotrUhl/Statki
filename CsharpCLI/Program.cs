using System;

namespace CsharpCLI {

	static class Const { public const int BOARDSIZE = 10; }; //rozmiar planszy - stała globalna - C# jest upośledzony

	class Program {
		static void Main(string[] args) {
			Console.WriteLine("Hello World!");
			Console.ReadKey();
			DllInterface.setCall_msg(fun_msg);
			DllInterface.setCall_enterPlannerMode(fun_enterPlannerMode);
			DllInterface.setCall_getCoords(fun_getCoords);
			DllInterface.setEvent_boardCreated(fun_boardCreated);
			DllInterface.setEvent_playerMoved(fun_playerMoved);
			InitData initData = new InitData {
				player1type = PlayerType.HUMAN,
				player2type = PlayerType.AI
			};
			DllInterface.runProgram(initData);
		}

		static void fun_msg(string msg, MsgType type, bool critical) {
			Console.WriteLine(msg);
			if (critical)
				Environment.Exit(1);
		}

		static void fun_enterPlannerMode() {
			Console.WriteLine("Entered into Planner Mode");
			DllInterface.fillRandom();
			Console.WriteLine("Filled Randomly");
		}

		static Point fun_getCoords() {
			Console.Write("(x, y): ");
			string[] input = Console.ReadLine().TrimStart().Split(' ');
			Point ret = new Point();
			ret.x = Convert.ToInt32(input[0]);
			ret.y = Convert.ToInt32(input[1]);
			return ret;
		}

		static void fun_boardCreated(int boardId) {
			Console.WriteLine("Board {0} created", boardId);
		}

		static void fun_playerMoved(int playerId) {
			Point point = DllInterface.getLastShotPoint();
			ShotResult result = DllInterface.getLastShotResult();
			Console.WriteLine("Player " + playerId + " shooted field (" + point.x + ", " + point.y + ") with result: " + result + ".");
		}
	}

}