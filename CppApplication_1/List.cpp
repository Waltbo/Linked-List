/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "List.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
typedef string ElementType;

LinkedList::LinkedList() {
    first = NULL;
}

bool LinkedList::isEmpty() {
    bool emptyCheck = false;
    if (first == NULL) {
        emptyCheck = true;
    }
    return emptyCheck;
}

void LinkedList::InsertAtEnd(ElementType x) {
    Node *q = new Node;
    q->data = x; //sets nodes data to users input
    Node *p = new Node; //node to move through list
    q->next = NULL;
    p = first;
    if (isEmpty() == true) {
        first = q;
    } else {
        while (p->next != NULL) {//traverses through the list
            p = p->next;
        }
        p->next = q; //since p stopped at the last part in the list, puts the next to q
    }
}

void LinkedList::ReverseDisplay() {

    if (first != NULL) {
        RDisplay(first);
    }
}

void LinkedList::RDisplay(Node *q) {//puts everything onto a stack and pops it

    if (q->next != NULL) {
        RDisplay(q->next);
    }
    cout << q->data << endl;
}

void LinkedList::GetValueAt(int n) {
    Node *q = new Node;
    q = first;
    if (q->next != NULL) {
        for (int i = 0; i < n; i++) {//for loop to traverse the amount of times n
            q = q->next;
        }
    } else if (q->next == NULL) {
        cout << "There is nothing at this location" << endl;
    } else {
        cout << q->data << endl;
    }
}

void LinkedList::DeleteAll(ElementType x) {
    Node *q = new Node;
    Node *firstCheck = new Node;
    q = first;
    firstCheck = first;
    Node *temp = new Node;
    temp = first;
    if (first != NULL) {
        while (q->next != NULL) {
            if (firstCheck->data == x) {//handles if you delete the first value in the list
                first = first->next;
                delete firstCheck;
                q = first;
                firstCheck = first;
                temp = first;
            } else if (q->data == x) {//if first doesn't equal x and q equals x, delete it and set q back to first to go back up the list
                temp->next = q->next;
                delete q;
                q = temp->next;
            } else {
                temp = q;
                q = q->next;
            }
        }
    } else {
        cout << "List is empty" << endl;
    }
}

void LinkedList::Display(string type) {
    Node *q = new Node;
    q = first;
    if (isEmpty() == true) {
        cout << "List is empty" << endl;
    }
    if (type == "All") {//prints out all values
        while (q != NULL) {
            cout << q->data << endl;
            q = q->next;
        }
    } else if (type == "Odd") {
        while (q != NULL) {
            if (q->data.length() % 2 != 0) {//if the current value remainder isn't 0 then it's odd
                cout << q->data << endl;
            }
            q = q->next;
        }
    } else if (type == "Even") {
        while (q != NULL) {
            if (q->data.length() % 2 == 0) {//if current value remainder is 0 then it's even
                cout << q->data << endl;
            }
            q = q->next;
        }
    } else {
        cout << "Incorrect input" << endl;
    }
}

void LinkedList::Sort() {
    Node *q = new Node();
    q = first;
    string holdOne = q->data;
    string holdTwo = q->next->data;
    while (q->next != NULL) {
        if (holdOne.length() > holdTwo.length()) {//if length of string is longer than the next one, swap the two
            q->data = holdTwo;
            q->next->data = holdOne;
        }
        q = q->next;
        holdOne = q->data;
        if (q->next != NULL) {
            holdTwo = q->next->data;
        }
    }
    SortCheck(); //Checks and sees if first is 
}

void LinkedList::SortCheck() {//loops sort again incase first is still bigger than next

    if (first->data.length() > first->next->data.length()) {
        Sort();
    }
}

double LinkedList::Median() {
    Sort();
    double median = 0;
    int counter = 0;
    int i = 0;
    Node *q = new Node;
    q = first;
    while (q != NULL) {//gets entire size of list
        counter++;
        q = q->next;
    }
    q = first;
    if (counter % 2 != 0) {//if remainder isn't 0 then it's odd and therefor get the middle one
        while (i < (counter / 2)) {
            i++;
            q = q->next;

        }
        median = q->data.length();
    } else {
        while (i < counter / 2 - 1) {
            q = q->next;
            i++;
        }
        median += q->data.length(); //adds the lengths of both the middle lists values and divides them by two for the median
        q = q->next;
        median += q->data.length();
        median = median / 2;

    }
    return median;
}

void LinkedList::Shuffle() {
    Node *q = new Node();
    q = first;
    int counter = 0;
    while (q != NULL) {
        counter++;
        q = q->next;
    }
    q = first;
    Node *p = new Node();
    while (q != NULL) {
        int random = rand() % counter;
        p = first;
        for (int i = 0; i < random; i++) {
            p = p->next;
        }
        string hold = p->data;
        p->data = q->data;
        q->data = hold;
        q = q->next;

    }

}
