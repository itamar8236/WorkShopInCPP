//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 8 Question 2
//this program checks QueueStack class. 
#include "List.h"
#include <iostream>
using namespace std;
//copied:

//class link:
List::Link::Link(int val, Link* nxt) :value(val), next(nxt) {}
List::Link::Link(const Link& source) : value(source.value), next(source.next) {}

//class list:
List::List(const List &l)
{
	Link *src, *trg;
	if (l.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l.head)->value, NULL);
		src = l.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
}
void List::clear()
{
	Link* next;	for (Link * p = head; p != NULL; p = next)
	{
		next = p->next;
		p->next = NULL;
		delete p;
	}
	head = NULL;
}
bool List::isEmpty() const { return head == NULL; }
void List::add(int val)
{
	head = new Link(val, head);
	if (head == NULL)
		throw "failed in memory allocation";
}
int List::firstElement() const
{
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}
bool List::search(const int &val) const
{
	for (Link* p = head; p != NULL; p = p->next)
		if (val == p->value)
			return true;
	return false;
}
void List::removeFirst()
{
	if (isEmpty())		throw "the List is empty, no Elements to remove";	Link*p = head;	head = p->next;	p->next = NULL;	delete p;
}
List::List() : head(NULL) {}
List::~List()
{
	clear();
}
