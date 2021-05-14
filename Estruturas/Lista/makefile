MAIN=main

TAD1=tad_lista_dupla

all:
	@echo "Compilando Lista..."
	gcc -c $(TAD1).c -o $(TAD1).o
	gcc $(MAIN).c $(TAD1).o -o $(MAIN)
	./$(MAIN)	
	rm *.o
	rm $(MAIN)