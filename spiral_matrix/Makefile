OBJ = main.o spiral_matrix.o
APPNAME = spiral_matrix.out

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ)

%.o : %.c
	gcc -c -o $@ $<

clean :
	rm $(OBJ) $(APPNAME)
