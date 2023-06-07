vet:	main.o Control.o View.o Time.o Date.o Animal.o Appt.o Schedule.o
	g++ -o vet main.o Control.o View.o Time.o Date.o Animal.o Appt.o Schedule.o

main.o:	main.cc defs.h CompareBehaviour.h
	g++ -c main.cc
	
Control.o:	Control.cc Control.h
	g++ -c Control.cc
	
View.o:	View.cc View.h
	g++ -c View.cc
	
Time.o: Time.cc Time.h
	g++ -c Time.cc
	
Date.o:	Date.cc Date.h
	g++ -c Date.cc

Animal.o:	Animal.cc Animal.h
	g++ -c Animal.cc

Appt.o:	Appt.cc Appt.h
	g++ -c Appt.cc
	
Schedule.o:	Schedule.cc Schedule.h
	g++ -c Schedule.cc

clean:
	rm -f *.o vet
