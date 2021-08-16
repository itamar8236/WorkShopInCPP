//Name: Itamar Cohen ID: 318558236
//workshop at c++
//exercise 5 Question 2
//this program checking the functions "merge" and "makeSet" on link list. 
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
//this is operator "="
void List::operator =(const List&l2)
{//like copy ctr
	Link *src, *trg;
	if (l2.head == NULL)
		head = NULL;
	else
	{
		head = new Link((l2.head)->value, NULL);
		src = l2.head;
		trg = head;
		while (src->next != NULL)
		{
			trg->next = new Link((src->next)->value, NULL);
			src = src->next;
			trg = trg->next;
		}
	}
}
//this function prints all elements in the list
ostream& operator<<(ostream& os, List& l)
{
	List::Link *p = l.head;
	while (p != NULL)
	{
		os << p->value << ' ';
		p = p->next;
	}
	return os;
}
//this function reads elements into list in bigger order
istream& operator>>(istream& is, List& l)
{
	int val;
	is >> val;
	l.add(val);
	List::Link *p = l.head;
	is >> val;
	while (val > p->value)
	{
		p->next = new List::Link(val, NULL);
		p = p->next;
		is >> val;
	}
	return is;
}
//this function insert new elemnt to it's place in the list
void List::insert(int key)
{
	Link*p = head;
	if (p == NULL)
		head = new Link(key, NULL);
	else if (key < p->value)
		(*this).add(key);
	else
	{
		while (p->next != NULL && p->next->value < key)
			p = p->next;
		p->next = new Link(key, p->next);
	}
}
//this function remove element from the list
void List::remove(int key)
{
	Link *p = head;
	if (head == NULL)
		throw "value not found";
	if (key == p->value)
		(*this).removeFirst();
	else
	{
		while (p->next != NULL && p->next->value != key)
			p = p->next;
		if (p->next == NULL)
			throw "value not found";
		Link*temp = p->next;
		p->next = temp->next;
		temp->next = NULL;
		delete  temp;
	}
}
