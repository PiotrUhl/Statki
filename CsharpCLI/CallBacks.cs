using System;
using System.Runtime.InteropServices;

namespace CsharpCLI {
	struct CallBacks {
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

		//przechodzi w tryb tworzenia planszy
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate void Dg_enterPlannerMode();
		[MarshalAs(UnmanagedType.FunctionPtr)]
		public Dg_enterPlannerMode call_enterPlannerMode;

		//event - ruch gracza 'playerId'
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate void Dg_event_int(int playerId);
		[MarshalAs(UnmanagedType.FunctionPtr)]
		public Dg_event_int event_playerMoved;

		//event - ukończono tworzenie planszy 'boardId'
		[MarshalAs(UnmanagedType.FunctionPtr)]
		public Dg_event_int event_boardCreated;
	}
}
