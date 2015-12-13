#Makefile de l'application Analog

Analog : Application.o PageInternet.o GrapheRequetes.o main.o
	g++ -std=c++11 -o Analog Application.o PageInternet.o GrapheRequetes.o main.o
	
Application.o : Application.h PageInternet.h GrapheRequetes.h
	g++ -c -std=c++11 Application.cpp
	
PageInternet.o : PageInternet.h
	g++ -c -std=c++11 PageInternet.cpp
	
main.o : Application.h PageInternet.h
	g++ -c -std=c++11 main.cpp
