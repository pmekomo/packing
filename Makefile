SHELL =/bin/bash
CC = gcc
RM = rm -f
CFLAGS = -ggdb -W -Wall -pedantic -ansi
EXECS1 = main
EXECS2 = genere
OBJS1 = main.o Lecture.o remplir_conteneur.o structure.o sac_a_dos.o
OBJS2= genere.o

.c.o :
	$(CC) $(CFLAGS) -g -c $*.c

#$(OBJS):
#	$(CC) $(CFLAGS) -c main.c

all:: $(EXECS1) $(EXECS2)



$(EXECS1) : $(OBJS1)
	$(CC) -o $@ $^

$(EXECS2) : $(OBJS2)
	$(CC) -o $@ $^

clean ::
	$(RM) *.o $(EXECS)
