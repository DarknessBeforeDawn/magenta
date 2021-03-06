#define _GNU_SOURCE
#include "libc.h"
#include "syscall.h"
#include <signal.h>
#include <unistd.h>

pid_t __vfork(void) {
/* vfork syscall cannot be made from C code */
#ifdef SYS_fork
    return syscall(SYS_fork);
#else
    return syscall(SYS_clone, SIGCHLD, 0);
#endif
}

weak_alias(__vfork, vfork);
