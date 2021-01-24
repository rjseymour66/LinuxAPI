objects = t_access.o ../lib/libtlpi.a

t_access : $(objects)
	gcc -o t_access $(objects) 

t_access.o : t_access.c ../include/tlpi_hdr.h
	gcc -I ../include -c t_access.c

.PHONY : orm
orm :
	-rm *.o

.PHONY : clean
clean : 
	-rm t_access t_access.o
