#Mekafile de l'application Analog

Analog : Application.o PageInternet.o GrapheRequetes.o main.o
	g++ -o Analog Application.o PageInternet.o GrapheRequetes.o
	
Application.o : Application.h PageInternet.h GrapheRequetes.h
	g++ -c Application.cpp
	
PageInternet.o : PageInternet.h
	g++ -c PageInternet.cpp
	
main.o : Application.h PageInternet.h
	g++ -c main.cpp
