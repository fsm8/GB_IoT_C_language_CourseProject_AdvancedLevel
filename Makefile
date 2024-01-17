# Аргументы программы
ARGS1=-help
ARGS2=-eps1
ARGS3=0,00001
ARGS4=-sqr

all: 	prog.exe

prog.exe: main.o functions.o
	gcc -o prog.exe main.o functions.o

main.o : Course_project_C_advanced.c functions.h
	gcc -c Course_project_C_advanced.c -o main.o

functions.o : functions.c functions.h
	gcc -c functions.c -o functions.o 

# Цель запуска программы с аргументами командной строки
run: prog.exe
	prog.exe $(ARGS1) $(ARGS2) $(ARGS3) $(ARGS4)
	
clean:
	del /Q *.o *.exe

# стандартные опции команды "del" в Windows, "/Q" для удаления файлов без подтверждения удаления и "/S" для удаления каталогов и их содержимого рекурсивно.
#del -rf *.o *.exe
#Чтобы запустить программу с аргументами командной строки, вы можете выполнить следующую команду в терминале: make run