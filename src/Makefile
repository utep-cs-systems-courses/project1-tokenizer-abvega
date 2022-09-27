OBJS = tokenizer.o history.o
OBJS_MAIN = $(OBJS) main.o
OBJS_TEST = $(OBJS) tester.o 
CFLAGS = -g -O3
all: tokenizer
tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

$(OBJS): history.h tokenizer.h

clean:
	rm -f *.o tokenizer

run: tokenizer
	./tokenizer