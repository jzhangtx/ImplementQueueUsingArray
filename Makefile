ImplementQueueUsingArray: ImplementQueueUsingArray.o
	g++ -g -o ImplementQueueUsingArray.exe ImplementQueueUsingArray.o -pthread    

ImplementQueueUsingArray.o: ImplementQueueUsingArray/ImplementQueueUsingArray.cpp
	g++ -g  -c -pthread ImplementQueueUsingArray/ImplementQueueUsingArray.cpp
