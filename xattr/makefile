objects = xattr_view.o ../lib/libtlpi.a

xattr_view : $(objects)
	gcc -o xattr_view $(objects) ; rm *.o 

xattr_view.o : xattr_view.c ../include/tlpi_hdr.h
	gcc -I ../include -c xattr_view.c

.PHONY : orm
orm :
	-rm *.o

.PHONY : clean
clean : 
	-rm xattr_view xattr_view.o
