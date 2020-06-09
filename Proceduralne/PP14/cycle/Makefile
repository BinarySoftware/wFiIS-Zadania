#
# Created by Maciej Mikołajek on 02/06/2020.
#

main.o: cycle_main.o cycle.o
	gcc -o main.o cycle.o cycle_main.o -Wall
cycle.o: cycle.c cycle.h
	gcc -c cycle.c -Wall
cycle_main.o: cycle_main.c cycle.h
	gcc -c cycle_main.c -Wall