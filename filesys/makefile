objects = t_mount.o ../lib/libtlpi.a

t_mount : $(objects)
	gcc -o t_mount $(objects) 

t_mount.o : t_mount.c ../include/tlpi_hdr.h
	gcc -I ../include -c t_mount.c

.PHONY : orm
orm :
	-rm *.o

.PHONY : clean
clean : 
	-rm t_mount t_mount.o
