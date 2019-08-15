using System;
using System.Runtime.InteropServices;

namespace NewGUI {

	[StructLayout(LayoutKind.Sequential)]
	struct CallBacks {
		//wysyła do interfejsu wiadomość o treści 'msg' o typie 'type'; jeżeli 'critical' przerywa działanie programu
		[MarshalAs(UnmanagedType.FunctionPtr)]
		public DllExports.Dg_void_IntPtr_MsgType_byte dll_call_msg;

		//pobiera współrzędne
		[MarshalAs(UnmanagedType.FunctionPtr)]
		public DllExports.Dg_Point_void dll_call_getCoords;

		//przechodzi w tryb tworzenia planszy
		[MarshalAs(UnmanagedType.FunctionPtr)]
		public DllExports.Dg_void_void dll_call_enterPlannerMode;

		//event - ruch gracza 'playerId'
		[MarshalAs(UnmanagedType.FunctionPtr)]
		public DllExports.Dg_void_int dll_event_playerMoved;

		//event - ukończono tworzenie planszy 'boardId'
		[MarshalAs(UnmanagedType.FunctionPtr)]
		public DllExports.Dg_void_int dll_event_boardCreated;
	}

}
