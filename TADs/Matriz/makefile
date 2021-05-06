MAIN=main

TADTESTE=tad_teste
TADMATRIZ=tad_matriz

all:
	@echo "compilando"
	gcc -c $(TADTESTE).c -o $(TADTESTE).o 
	gcc -c $(TADMATRIZ).c -o $(TADMATRIZ).o 
	gcc $(MAIN).c $(TADTESTE).o $(TADMATRIZ).o -o $(MAIN)

run:
	./$(MAIN)

clean:
	rm *.o
	rm $(MAIN)
