MAIN=main
TAD=tad_teste

all:
	@echo "compilando"
	gcc -c $(TAD).c -o $(TAD).o
	gcc $(MAIN).c $(TAD).o -o $(MAIN)

run:
	./$(MAIN)

clean:
	rm *.o
	rm $(MAIN)