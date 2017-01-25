/*
 * Author: Vien Van
 * Name: Lab 2
 * Description: Testing functions for List.h/List.cpp (implicit)
 * Date: 01/22/2017
 */

#include <iostream>
#include "List.h"
using namespace std;

int main() {

    //instantiate two lists for testing purposes
    List<int> L1;
    List<char> L2;
    cout << "Should stop the program \n";
//    L1.getFirst();
//    L1.getIterator();
//    L1.getLast();
//    L1.removeFirst();
//    L1.removeLast();
//    L1.removeIterator();

    //Testing insertFirst() and printList()
    cout << "Should print out an empty line: \n";
    L1.printList(); //Should not print any message to the screen, just an empty line


    L1.insertFirst(0);
    cout << "Should print out 0 and then move to a new line: \n";
    L1.printList();

    L1.startIterator();
    cout << "First element of the node should be 0: " << L1.getIterator() << endl;

    L1.insertLast(1);
    cout << "Should print out 01 and then move to new line: \n";
    L1.printList();

    L1.advanceIterator();
    cout << "Next element of the node should be 1: " << L1.getIterator() << endl;
    cout << "Should print out true: " << L1.offEnd() << endl;

    L1.advanceIterator();
    cout << "Should print out false: " << L1.offEnd() << endl;

    for (int i = 1; i <= 10; i++) { //inserting the the values 1-10 into L1
        L1.insertFirst(i);
        L2.insertLast('A' + i);
    }

    cout << "Should print out 10 9 8 7 6 5 4 3 2 1 0 1 and then move to a new line: \n";
    L1.printList();

    List<int> L_copy(L1);

    cout << "Should print out 10 9 8 7 6 5 4 3 2 1 0 1: \n";
    L_copy.printList();
    cout << "Should print out 'Lists are deep copies' " << endl;
    if(L_copy == L1)
    	cout << "Lists are deep copies" << endl;
    else
    	cout << "Lists are not copied." << endl;

    cout << "Should print out characters: BCDEFGHIJK and then move to new line: \n";
    L2.printList();

    L2.startIterator();
    cout << "Should print out B: " << L2.getIterator() << endl;
    L2.advanceIterator();
    cout << "Should print out C: " << L2.getIterator() << endl;
    L2.insertIterator('c');
    cout << "Should print out BCcDEFGHIJK: " << endl;
    L2.printList();
    L2.advanceIterator();
    cout << "Should printout c: " << L2.getIterator() << endl;
    L2.removeIterator();
    cout << "Should printout BCDEFGHIJK: " << endl;
    L2.printList();
    L2.startIterator();
    cout << "Should print out B: " << L2.getIterator() << endl;
    cout << "Size of L2 should be 10: " << L2.getSize() << endl;
    L2.removeLast();
    cout << "The size of L2 should be 9: " << L2.getSize() << endl;

}


//Should stop the program
//Should print out an empty line:
//
//Should print out 0 and then move to a new line:
//0
//First element of the node should be 0: 0
//Should print out 01 and then move to new line:
//01
//Next element of the node should be 1: 1
//Should print out true: 0
//Should print out false: 1
//Should print out 10 9 8 7 6 5 4 3 2 1 0 1 and then move to a new line:
//1098765432101
//Should print out 10 9 8 7 6 5 4 3 2 1 0 1:
//1098765432101
//Should print out 'Lists are deep copies'
//Lists are deep copies
//Should print out characters: BCDEFGHIJK and then move to new line:
//BCDEFGHIJK
//Should print out B: B
//Should print out C: C
//Should print out BCcDEFGHIJK:
//BCcDEFGHIJK
//Should printout c: c
//Should printout BCDEFGHIJK:
//BCDEFGHIJK
//Should print out B: B
//Size of L2 should be 10: 10
//The size of L2 should be 9: 9
