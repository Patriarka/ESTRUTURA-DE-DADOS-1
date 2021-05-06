MAIN=main

TADTESTE=tad_teste
TADVETOR=tad_vetor

all:
	@echo "compilando"
	gcc -c $(TADTESTE).c -o $(TADTESTE).o 
	gcc -c $(TADVETOR).c -o $(TADVETOR).o 
	gcc $(MAIN).c $(TADTESTE).o $(TADVETOR).o -o $(MAIN)

run:
	./$(MAIN)

clean:
	rm *.o
	rm $(MAIN)





