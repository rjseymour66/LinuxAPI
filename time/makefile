objects = process_time.o ../lib/libtlpi.a

process_time : $(objects)
	gcc -o process_time $(objects) 

process_time.o : process_time.c ../include/tlpi_hdr.h
	gcc -I ../include -c process_time.c

.PHONY : clean
clean : 
	-rm process_time process_time.o
