objects = idshow.o ../lib/libtlpi.a

idshow : $(objects)
	gcc -o idshow $(objects) 

idshow.o : idshow.c ../include/tlpi_hdr.h
	gcc -I ../include -c idshow.c

.PHONY : clean
clean : 
	-rm idshow idshow.o
