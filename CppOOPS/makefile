main: AbstractCollection.o Stack.o Queue.o OrderedList.o UnorderedList.o Node.o
	g++ -w -o hw2.out main.cpp AbstractCollection.o Stack.o Queue.o OrderedList.o UnorderedList.o Node.o

Stack.o: Stack.h Stack.cpp AbstractCollection.o
	g++ -c Stack.cpp

Queue.o: Queue.h Queue.cpp AbstractCollection.o
	g++ -c Queue.cpp

OrderedList.o: OrderedList.h OrderedList.cpp AbstractCollection.o
	g++ -c OrderedList.cpp

UnorderedList.o: UnorderedList.h UnorderedList.cpp AbstractCollection.o
	g++ -c UnorderedList.cpp

AbstractCollection.o: AbstractCollection.cpp AbstractCollection.h Node.o
	g++ -c AbstractCollection.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm *o

