program: funkcijos.o struktura.o
	g++ -o program main.cpp funkcijos.o struktura.o -O2

funkcijos:
	g++ -c funkcijos.cpp -O2

struktura:
	g++ -c struktura.cpp -O2
	
clean:
	rm *.o
