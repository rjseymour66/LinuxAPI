objects = t_realpath.o ../lib/libtlpi.a

t_realpath : $(objects)
	gcc -o t_realpath $(objects) -Wall -g -Wextra -std=c99

t_realpath.o : t_realpath.c ../include/tlpi_hdr.h
	gcc -I ../include -c t_realpath.c -Wall -g -Wextra -std=c99

.PHONY : orm
orm :
	-rm *.o

.PHONY : clean
clean : 
	-rm t_realpath t_realpath.o
