#pragma once
namespace Call {
	int _cdecl func_1(int x, int y, int z);
	int _stdcall func_2(int& x, int y, int z);
	int _fastcall func_3(int x, int y, int z, int t);
}