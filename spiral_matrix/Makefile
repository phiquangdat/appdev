OBJ = main.o spiral_matrix.o
APPNAME = spiral_matrix.out
TARGET = spiral_matrix.txt

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ)

%.o : %.c
	gcc -c -o $@ $<

clean :
	rm $(OBJ) $(APPNAME)

print: $(APPNAME)
	./$(APPNAME) > ${TARGET}