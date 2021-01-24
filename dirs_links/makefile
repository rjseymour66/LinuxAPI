objects = t_unlink.o ../lib/libtlpi.a

t_unlink : $(objects)
	gcc -o t_unlink $(objects) 

t_unlink.o : t_unlink.c ../include/tlpi_hdr.h
	gcc -I ../include -c t_unlink.c

.PHONY : orm
orm :
	-rm *.o

.PHONY : clean
clean : 
	-rm t_unlink t_unlink.o
