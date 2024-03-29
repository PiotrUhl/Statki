﻿using System;
using System.Runtime.InteropServices;

namespace CsharpCLI {

	class DllExports {

		public readonly CallBacks callBacks;

		//konstruktor
		public DllExports() {
			callBacks.dll_call_msg = ov_call_msg;
			callBacks.dll_call_enterPlannerMode = ov_call_enterPlannerMode;
			callBacks.dll_call_getCoords = ov_call_getCoords;
			callBacks.dll_event_playerMoved = ov_event_playerMoved;
			callBacks.dll_event_boardCreated = ov_event_boardCreated;
		}

		#region delegates
		//wysyła do interfejsu wiadomość o treści 'msg' o typie 'type'; jeżeli 'critical' przerywa działanie programu
		public DllExports.Dg_void_string_MsgType_bool call_msg;
		//pobiera współrzędne
		public DllExports.Dg_Point_void call_getCoords;
		//przechodzi w tryb tworzenia planszy
		public DllExports.Dg_void_void call_enterPlannerMode;
		//event - ruch gracza 'playerId'
		public DllExports.Dg_void_int event_playerMoved;
		//event - ukończono tworzenie planszy 'boardId'
		public DllExports.Dg_void_int event_boardCreated;
		#endregion

		#region overwriters
		public void ov_call_msg(IntPtr msg, MsgType type, byte critical) {
			bool criticalBool = critical == 0 ? false : true;
			string msgString = Marshal.PtrToStringAnsi(msg);
			call_msg(msgString, type, criticalBool);
		}
		public Point ov_call_getCoords() {
			return call_getCoords();
		}
		public void ov_call_enterPlannerMode() {
			call_enterPlannerMode();
		}
		public void ov_event_playerMoved(int playerId) {
			event_playerMoved(playerId);
		}
		public void ov_event_boardCreated(int boardId) {
			event_boardCreated(boardId);
		}
		#endregion

		#region typedefs
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate void Dg_void_IntPtr_MsgType_byte(IntPtr msg, MsgType type, byte critical);
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate Point Dg_Point_void();
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate void Dg_void_void();
		[UnmanagedFunctionPointer(CallingConvention.StdCall)]
		public delegate void Dg_void_int(int v1);

		public delegate void Dg_void_string_MsgType_bool(string msg, MsgType type, bool critical);
		#endregion

	}

}
