objects = user_processes.o ../lib/libtlpi.a

user_processes : $(objects)
	gcc -o user_processes $(objects) 

user_processes.o : user_processes.c ../include/tlpi_hdr.h
	gcc -I ../include -c user_processes.c

.PHONY : objrm
objrm :
	-rm *.o

.PHONY : clean
clean : 
	-rm user_processes user_processes.o
