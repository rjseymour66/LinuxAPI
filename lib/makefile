objects = error_functions.o get_num.o curr_time.o ugid_functions.o file_perms.o

libtlpi.a : $(objects)
	ar crs libtlpi.a $(objects) 

error_functions.o : error_functions.c ../include/tlpi_hdr.h
	gcc -I ../include/ -c error_functions.c

get_num.o : get_num.c ../include/tlpi_hdr.h
	gcc -I ../include/ -c get_num.c

curr_time.o : curr_time.c ../include/tlpi_hdr.h
	gcc -I ../include/ -c curr_time.c

ugid_functions.o : ugid_functions.c ../include/tlpi_hdr.h
	gcc -I ../include/ -c ugid_functions.c

file_perms.o : file_perms.c ../include/tlpi_hdr.h
	gcc -I ../include/ -c file_perms.c

.PHONY : orm
orm : 
	-rm *.o

.PHONY : clean
clean : 
	-rm libtlpi.a
