objects = new_free_and_sbrk.o ../lib/libtlpi.a

new_free_and_sbrk : $(objects)
	gcc -o new_free_and_sbrk $(objects)

new_free_and_sbrk.o : new_free_and_sbrk.c ../include/tlpi_hdr.h
	gcc -I ../include -c new_free_and_sbrk.c

.PHONY : clean
clean : 
	-rm new_free_and_sbrk new_free_and_sbrk.o
