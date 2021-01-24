objects = getpwnam.o ../lib/libtlpi.a

getpwnam : $(objects)
	gcc -o getpwnam $(objects) 

getpwnam.o : check_password.c ../include/tlpi_hdr.h
	gcc -I ../include -c getpwnam.c

.PHONY : clean
clean : 
	-rm getpwnam getpwnam.o
