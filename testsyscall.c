#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sched.h>
#include <signal.h>
#include <syscall.h>
int main(void)
{
    int *a = malloc(1024);
    if (!a) {
        printf("couldn't allocate the memory");
        return 1;
    }
    long pid = syscall(SYS_clone,  CLONE_PARENT | SIGCHLD, a);
    if (pid == -1) {
        printf("failure %d: %s\n", errno, strerror(errno));
    } else {
        printf("success: %d\n", pid);
    }
    free(a);
    return 0;
}
