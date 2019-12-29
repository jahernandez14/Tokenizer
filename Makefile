
HEADERS = tokenizer.h history.h

all: UI

UI: UI.o tokenizer.o history.o
	gcc UI.o tokenizer.o history.o -o UI

UI.o: UI.c $(HEADER)
	gcc -c UI.c -o UI.o

tokenizer.o: tokenizer.c
	gcc -c tokenizer.c -o tokenizer.o

history.o: history.c
	gcc -c history.c -o history.o
clean:
	-rm *.o
	-rm *~
	-rm *.c#
	-rm UI