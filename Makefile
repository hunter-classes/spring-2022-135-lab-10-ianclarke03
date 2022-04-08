main: main.o funcs.o
	g++ -o main main.o funcs.o

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o

main.o: main.cpp funcs.h time.h
	g++ -c main.cpp

tests.o: tests.cpp doctest.h funcs.h time.h
	g++ -c tests.cpp

funcs.o: funcs.cpp funcs.h time.h
	g++ -c funcs.cpp

clean:
	rm -f main tests main.o tests.o funcs.o