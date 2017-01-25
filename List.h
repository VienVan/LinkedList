/*
 * Author: Vien Van
 * Name: List.h
 * Description: Creating accessors, mutators, copy constructors, and iterators for doubly linked list.
 * Date: 01/22/2017
 */

#ifndef LIST_H_
#define LIST_H_

#include <cstddef> //for NULL

template <class listdata> //list stores generic listdata, not any specific C++ type

class List
{
    private:
             struct Node
             {
                listdata data;
                Node* next;
                Node* previous;

                Node(listdata data): data(data), next(NULL), previous(NULL){}
             };

             typedef struct Node* Nodeptr;

             Nodeptr first;
             Nodeptr last;
             Nodeptr iterator;
             int size;
    public:

        /**Constructors and Destructors*/

        List();
        //Default constructor; initializes and empty list
        //Postcondition: There should be an empty list.

        List(const List &list);
        //Copy Constructor
        //Postcondition: There should be a deep copy of the original list

        ~List();
        //Destructor. Frees memory allocated to the list
        //Postcondition: The list is cleared


        bool operator==(const List &list);
        /**Accessors*/


        listdata getFirst();
        //Returns the first element in the list
        //Precondition: There should be at least one element in the list


        listdata getLast();
        //Returns the last element in the list
        //Precondition: There should be at least one element in the list


        bool isEmpty();
        //Determines whether a list is empty.

        int getSize();
        //Returns the size of the list


        /**Manipulation Procedures*/

        void removeLast();
        //Removes the value of the last element in the list
        //Precondition: There should be one element in the list
        //Postcondition: There should be one less element in the list. The last element should be different than before.

        void removeFirst();
        //Removes the value of the first element in the list
        //Precondition: There should be at least one element in the list
        //Postcondition: There should be one less element in the list. The first element should be different than before.

        void insertLast(listdata data);
        //Inserts a new element at the end of the list
        //If the list is empty, the new element becomes both first and last
        //Postcondition: There should be one more element in the list. The last element should be different than before.

        void insertFirst(listdata data);
        //Inserts a new element at the start of the list
        //If the list is empty, the new element becomes both first and last
        //Postcondition: There should be one more element in the list. The first element should be different than before.

        /**Additional List Operations*/

        void printList();
        //Prints to the console the value of each element in the list sequentially
        //and separated by a blank space
        //Prints nothing if the list is empty

        void startIterator();
        //Make iterator point to the first node of the list
        //Precondition: size!=0

        listdata getIterator();
        //Return element at itertor's node
        //Precondition: size!=0 && iterator!=null

        void advanceIterator();
        //Move iteraror to the next node
        //Precondition: size!=0 && iterator!=null

        void removeIterator();
        //Remove element at the iterator
        //Precondition: size!=0 && iterator!= null

        void insertIterator(listdata data);
        //Insert node at the element after the iterator is pointing to
        //Precondition: !offEnd

        bool offEnd();
        //Returns true or false whether the iterator is null (end of the list)
};


#include <iostream>
#include "List.h"
#include <assert.h>
using namespace std;

/**********************************
 * Constructors + Destructors
 **********************************/
template <class listdata>
List<listdata>::List() : first(NULL), last(NULL), iterator(NULL), size(0) {}

template <class listdata>
List<listdata>::~List()
{
    Nodeptr cursor = first;
    Nodeptr temp;
    while(cursor != NULL)
    {
        temp = cursor->next;

        delete cursor;

        cursor = temp;

    }
}

template <class listdata>
List<listdata>::List(const List &list): size(list.size)
{
    if(list.first == NULL) //If the original list is empty, make an empty list for this list
    {
        first = last = iterator = NULL;
    }
    else
    {
        first = new Node(list.first->data); //calling Node constructor
        Nodeptr temp = list.first; //set a temporary node pointer to point at the first of the original list
        iterator = first; //set iterator to point to first node of the new list

        while(temp->next != NULL)
        {

            temp = temp->next; //advance up to the next node in the original list
            iterator->next = new Node(temp->data); //using node constructor to create a new node with copy of data
            iterator = iterator->next; //advance to this new node
        }

        last = iterator; //Why do I need this line of code?
        iterator = NULL;

    }
}


/**********************************
 * Accessors
 **********************************/
template <class listdata>
void List<listdata>::printList()
{
    Nodeptr temp = first; //create a temporary iterator
    while (temp != NULL) {

        //Add two lines of code here

        //Hint: One statement should contain a cout
    	cout << temp->data;
    	temp = temp->next;

    }
    cout << endl; //What does this do?
}


template <class listdata>
bool List<listdata>::isEmpty()
{
    return (size==0);
}

template <class listdata>
int List<listdata>::getSize() { return size;}


template <class listdata>
listdata List<listdata>::getFirst() {
	assert(size!=0);
	return first -> data;
}

template <class listdata>
listdata List<listdata>::getLast() {
	assert(size!=0);
	return last -> data;
}

template <class listdata>
listdata List<listdata>::getIterator()
{
	assert (size != 0);
	assert (iterator != NULL);
	return iterator -> data;
}

template <class listdata>
void List<listdata>::advanceIterator()
{
	assert (size != 0);
	assert (iterator != NULL);
	iterator = iterator -> next;
}

template <class listdata>
bool List<listdata>::offEnd()
{
	return iterator == NULL;
}

/********************************************
 * Mutators
 ********************************************/

template <class listdata>
void List<listdata>::insertFirst(listdata data)
{
    if (size==0) //Why is this necessary?
    {
        first = new Node(data);
        last = first; //notice the order here. Assignment is right to left

    }
    else
    {
        Nodeptr N = new Node(data);//create the new node by calling the node constructor
        N->next = first;//set the new node's next field to point to the first node
        first->previous = N; //Need to update the previous pointer of first to point back at the new node
        first = N;//point the first pointer to the new node
    }

    size++;

}

template <class listdata>
void List<listdata>::insertLast(listdata data)
{
    if (size==0) //Why is this necessary?
    {
        first = new Node(data);
        last = first; //notice the order here. Assignment is right to left
    }
    else
    {
        Nodeptr N = new Node(data);//create the new node by calling the node constructor
        last->next = N;
        last  = N;
    }

    size++;

}

template <class listdata>
void List<listdata>::removeFirst()
{
    assert (size != 0);
	if (size == 1) {

        delete first;

        first = last = NULL;

        size = 0;

    } else {

        Nodeptr temp = first; //store pointer to first so we don't lose access to it

        first = first->next; //advance the pointer

        delete temp; //free the memory for the original first node

        size--;
    }

}

template <class listdata>
void List<listdata>::removeLast()
{
    assert (size != 0);
	if ( size == 1) {

    	delete first;

    	first = last = NULL;

    	size = 0;

    } else {

        Nodeptr temp = first;

        while (temp->next != last) {

            temp = temp->next; //advance the pointer

        }

        delete last; //free the memory for the original last node

        last = temp;

        last->next = NULL; //so last->next is not pointing at freed memory

        size--;
    }

}

template <class listdata>
void List<listdata>::startIterator()
{
	assert(size != 0);
	iterator = first;
}

template <class listdata>
void List<listdata>::insertIterator(listdata data)
{
	assert(iterator != NULL);

	if(iterator == last)
	{
		insertLast(data);
	}
	else
	{
		Nodeptr N = new Node(data);
		N->next = iterator->next;
		N->previous = iterator;
		iterator->next->previous = N;
		iterator->next = N;
		size++;
	}
}
template <class listdata>
void List<listdata>::removeIterator()
{
	assert(size != 0);
	assert(iterator != NULL);
	if(size == 1)
	{
		delete first;
		first = last = iterator = NULL;
		size = 0;
	}
	else if(iterator == last)
	{
		removeLast();
	}
	else
	{
		iterator->previous->next = iterator->next;
		iterator->next->previous = iterator->previous;
		delete iterator;
		iterator = NULL;
		size--;
	}
}

template <class listdata>
bool List<listdata>::operator==(const List& list)
{
    if(size != list.size)
        return false;
    Nodeptr temp1 = first;
    Nodeptr temp2 = list.first;
    while(temp1 != NULL)
    {
        if(temp1->data != temp2->data)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}


#endif /* LIST_H_ */
