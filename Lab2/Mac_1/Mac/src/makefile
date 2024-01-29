OBJ= a51.o emitter.o lexer.o parser.o pathtools.o run.o symbol.o

a51: $(OBJ)
	gcc -o a51 $(OBJ)
	gcc ISPN76E003.c -o ISPN76E003

parser.c parser.h: parser.y
	bison -d -o parser.c parser.y

a51.o: a51.c a51.h parser.h
	gcc -c a51.c 

emitter.o: emitter.c a51.h  parser.h
	gcc -c emitter.c

lexer.o: lexer.c a51.h parser.h
	gcc -c lexer.c

parser.o: parser.c a51.h parser.h
	gcc -c parser.c

pathtools.o: pathtools.c a51.h parser.h
	gcc -c pathtools.c

run.o: run.c a51.h parser.h
	gcc -c run.c

symbol.o: symbol.c a51.h parser.h
	gcc -c symbol.c

clean:
	rm *.o
	rm parser.c
	rm parser.h
