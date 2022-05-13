EXEC = trains
FILES = functii.c main.c graph.c
HEAD = functii.h


build: $(FILES) $(HEAD)
	gcc $(FILES) -o $(EXEC) -std=gnu99

run: build
	./$(EXEC)

clean:
	rm -f $(EXEC)