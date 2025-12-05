OBJ = main.o pyramid.o
APPNAME = pyramid.out
TARGET = pyramid.txt

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ)

%.o : %.c
	gcc -c -o $@ $<

clean :
	rm $(OBJ) $(APPNAME)

print: $(APPNAME)
	./$(APPNAME) > ${TARGET}