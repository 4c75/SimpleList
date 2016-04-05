// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>
#include <iostream>



struct Person{
	int Age;
	char Name[100];
	Person(char name[100], int age){
		Age = age;
		strncpy_s(Name, name, 100);
	}
	Person(){}
};

// Lets build Node as universal as we can;
// so we use template - it is like a class, but with no specified type.
template <typename T> 
class Node{
public:
	T content;
	Node * next;
};

template <typename T>
class List
{
private:
	Node<T> * Head;

public:
	List(){

	}
	~List(){
		while (Head != NULL){
			Node<T> * n = Head->next;
			delete Head;
			Head = n;
		}
	}
	void Add(T person){
		Node<T> * element = new Node<T>();
		element->content = person;
		element->next = Head;
		Head = element;
	}
	void IterateAndPrint(){
		Node<T> * iterator = Head;
		while (iterator != NULL){
			T person = iterator->content; //change T to Person or whatever you want
			iterator = iterator->next;
			//std::cout << person.Name <<" "<< person.Age << "\n"; //if T is a Person, can uncomment this
		}
		delete iterator;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Person Janis("John", 29);
	Person Peteris("Peter", 40);
	Person Zeks("Vladimirs", 31);
	Person Nil("Nils", 88);
	List<Person> * Persons = new List<Person>();
	Persons->Add(Janis);
	Persons->Add(Peteris);
	Persons->Add(Nil);
	Persons->Add(Zeks);
	Persons->IterateAndPrint();
	delete Persons;
	getchar();
	return 0;
}

