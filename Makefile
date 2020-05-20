all: main

main:main.cpp header.h
	g++ -g main.cpp -o final

clear:
	rm *.o final
