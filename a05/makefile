MAIN=main

TAD1=tad_timer1
TAD2=tad_timer2

timer1:
	@echo "compilando tad_timer1"
	gcc -c $(TAD1).c -o $(TAD1).o
	gcc $(MAIN).c $(TAD1).o -o $(MAIN)

timer2:
	@echo "compilando tad_timer2"
	gcc -c $(TAD2).c -o $(TAD2).o
	gcc $(MAIN).c $(TAD2).o -o $(MAIN)

run:
	./$(MAIN)

clean:
	rm *.o
	rm $(MAIN)