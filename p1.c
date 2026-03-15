#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = getpid();
    pid_t ppid = getppid();
    
    printf("Текущий процесс:\n");
    printf("  PID: %d\n", pid);
    printf("  PPID: %d\n", ppid);
    printf("----------------------------------------\n");
    
    return 0;
}
