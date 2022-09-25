
tokenizer: tokenizer.o uimain.o history.o 
	cc -o tokenizer tokenizer.o uimain.o history.o

clean: 
	rm -f *.o tokenizer
tokenizer.o: tokenizer.h tokenizer.o 

uimain.o: uimain.c tokenizer.h histor.h 

history.o: history.h history.c tokenizer.h