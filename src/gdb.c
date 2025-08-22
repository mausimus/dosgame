#ifndef _WIN32

#define GDB_IMPLEMENTATION
#include "gdbstub.h"

void gdb() {
	gdb_start();
}
#else
void gdb() {}
#endif