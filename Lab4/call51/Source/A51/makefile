OBJ= a51.o emitter.o lexer.o parser.o pathtools.o run.o symbol.o

a51: $(OBJ) efm8p.o
	gcc -o a51 $(OBJ)
	gcc -o efm8p efm8p.c

parser.c parser.h: parser.y
	bison -d -o parser.c parser.y

a51.o: a51.c a51.h
	gcc -c a51.c 

emitter.o: emitter.c a51.h
	gcc -c emitter.c

lexer.o: lexer.c a51.h
	gcc -c lexer.c

parser.o: parser.y a51.h
	bison -d -v -o parser.c parser.y
	gcc -c parser.c

pathtools.o: pathtools.c a51.h
	gcc -c pathtools.c

run.o: run.c a51.h
	gcc -c run.c

symbol.o: symbol.c a51.h
	gcc -c symbol.c

