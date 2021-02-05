objects = nested_struct.o 

nested_struct : $(objects)
	gcc -o nested_struct $(objects) -Wall -g -Wextra -std=c99


nested_struct.o : nested_struct.c 
	gcc -c nested_struct.c -Wall -g -Wextra -std=c99

.PHONY : orm
orm :
	-rm *.o

.PHONY : clean
clean : 
	-rm nested_struct nested_struct.o
