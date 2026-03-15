#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    printf("Родительский процесс (до fork):\n");
    printf("  PID: %d\n", getpid());
    printf("  PPID: %d\n", getppid());
    printf("----------------------------------------\n");
    
    pid = fork();
    
    if (pid == -1) {
        perror("Ошибка при вызове fork");
        return 1;
    }
    
    if (pid == 0) {
        printf("Дочерний процесс:\n");
        printf("  PID: %d\n", getpid());
        printf("  PPID: %d\n", getppid());
        printf("  Возврат fork(): %d (0 в дочернем процессе)\n", pid);
        printf("----------------------------------------\n");
    } else {
        printf("Родительский процесс (после fork):\n");
        printf("  PID: %d\n", getpid());
        printf("  PPID: %d\n", getppid());
        printf("  Возврат fork(): %d (PID дочернего процесса)\n", pid);
        printf("----------------------------------------\n");
        
        wait(NULL);
    }
    
    return 0;
}
