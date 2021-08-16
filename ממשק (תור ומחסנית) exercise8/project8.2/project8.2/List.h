//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 8 Question 2
//this program checks QueueStack class. 
#pragma once
#include <iostream>
using namespace std;
class List
{
protected:
	//--------------------------------------------
   // inner class link
   // a single element for the linked List
   //--------------------------------------------
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link * nextPtr);
		Link(const Link &);
		// data areas
		int value;
		Link * next;
	}; //end of class Link

public:
	// constructors
	List();
	List(const List&);
	~List();
	// operations
	void add(int value);
	int firstElement() const;
	bool search(const int &value) const;
	bool isEmpty() const;
	void removeFirst();
	void clear();
protected:
	// data field
	Link* head;
};

