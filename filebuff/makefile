objects = t_tail.o ../lib/libtlpi.a

t_tail : $(objects)
	gcc -o t_tail $(objects) 

t_tail.o : t_tail.c ../include/tlpi_hdr.h
	gcc -I ../include -c t_tail.c

.PHONY : orm
orm :
	-rm *.o

.PHONY : clean
clean : 
	-rm t_tail t_tail.o
