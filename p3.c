#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    
    printf("Основная программа (p3):\n");
    printf("  PID: %d\n", getpid());
    printf("  PPID: %d\n", getppid());
    printf("----------------------------------------\n");
    
    pid = fork();
    
    if (pid == -1) {
        perror("Ошибка при вызове fork");
        return 1;
    }
    
    if (pid == 0) {
        printf("Дочерний процесс (до exec):\n");
        printf("  PID: %d\n", getpid());
        printf("  PPID: %d\n", getppid());
        printf("----------------------------------------\n");
        printf("Запускаем программу p1 через execlp...\n\n");
        
        execlp("./p1", "p1", NULL);
        
        perror("Ошибка при вызове execlp");
        return 1;
    } else {
        wait(NULL);
        printf("\nДочерний процесс завершён\n");
    }
    
    return 0;
}
