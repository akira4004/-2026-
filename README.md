# Лабораторная работа: Процессы в Linux

## Программа 1 (p1.c)
Выводит идентификатор текущего и родительского процесса.
```
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("PID: %d\n", getpid());
    printf("PPID: %d\n", getppid());
    return 0;
}
```
## Программа 2 (p2.c)
Создаёт копию процесса через fork().
```
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
```
## Программа 3 (p3.c)
Создаёт процесс с новым кодом через exec().
```
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
```
Makefile
```
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

```
Как запускать
1. Скомпилировать все программы:
make
2. Запустить первую программу:
./p1
3. Запустить вторую программу:
./p2
4. Запустить третью программу:
./p3
5. Удалить скомпилированные файлы:
make clean
```
```
Пример вывода программы p2
```
Родительский процесс (до fork):
PID: 1234, PPID: 567
----------------
После fork:
PID: 1234, PPID: 567
----------------
После fork:
PID: 1235, PPID: 1234
----------------

```
Пример вывода программы p3
```
Программа p3 (PID: 1234)
Создаём дочерний процесс...
Дочерний процесс запускает p1
PID: 1235
PPID: 1234
Дочерний процесс завершён
