objects = t_fpathconf.o ../lib/libtlpi.a

t_fpathconf : $(objects)
	gcc -o t_fpathconf $(objects) 

t_fpathconf.o : t_fpathconf.c ../include/tlpi_hdr.h
	gcc -I ../include -c t_fpathconf.c

.PHONY : clean
clean : 
	-rm t_fpathconf t_fpathconf.o
