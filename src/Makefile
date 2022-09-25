tokenizer: tokenizer.o main.o history.o 
	cc -o tokenizer tokenizer.o main.o history.o

clean: 
	rm -f *.o tokenizer
tokenizer.o: tokenizer.h tokenizer.o 

main.o: main.c tokenizer.h histor.h 

history.o: history.h history.c tokenizer.h
