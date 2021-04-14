program: funkcijos.o
	g++ -o program main.cpp funkcijos.o -O2

funkcijos:
	g++ -c funkcijos.cpp -O2

clean:
	rm *.o
