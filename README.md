# Лабораторная работа: Процессы в Linux

## Программа 1 (p1.c)
Выводит идентификатор текущего и родительского процесса.

```c
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());
    return 0;
}
Программа 2 (p2.c)
Создаёт копию процесса через fork().

c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Родительский процесс (до fork):\n");
    printf("PID: %d, PPID: %d\n", getpid(), getppid());
    printf("----------------\n");
    
    fork();
    
    printf("После fork:\n");
    printf("PID: %d, PPID: %d\n", getpid(), getppid());
    printf("----------------\n");
    
    wait(NULL);
    return 0;
}
Программа 3 (p3.c)
Создаёт процесс с новым кодом через exec().

c
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Программа p3 (PID: %d)\n", getpid());
    printf("Создаём дочерний процесс...\n");
    
    if (fork() == 0) {
        printf("Дочерний процесс запускает p1\n");
        execlp("./p1", "p1", NULL);
    } else {
        wait(NULL);
        printf("Дочерний процесс завершён\n");
    }
    
    return 0;
}
Makefile
Для компиляции всех программ.

makefile
CC = gcc
CFLAGS = -Wall

all: p1 p2 p3

p1: p1.c
	$(CC) $(CFLAGS) -o p1 p1.c

p2: p2.c
	$(CC) $(CFLAGS) -o p2 p2.c

p3: p3.c
	$(CC) $(CFLAGS) -o p3 p3.c

clean:
	rm -f p1 p2 p3

.PHONY: all clean
Как запускать
Скомпилировать все программы:

bash
make
Запустить первую программу:

bash
./p1
Запустить вторую программу:

bash
./p2
Запустить третью программу:

bash
./p3
Удалить скомпилированные файлы:

bash
make clean
Пример вывода программы p2
text
Родительский процесс (до fork):
PID: 1234, PPID: 567
----------------
После fork:
PID: 1234, PPID: 567
----------------
После fork:
PID: 1235, PPID: 1234
----------------
Пример вывода программы p3
text
Программа p3 (PID: 1234)
Создаём дочерний процесс...
Дочерний процесс запускает p1
PID: 1235
PPID: 1234
Дочерний процесс завершён
