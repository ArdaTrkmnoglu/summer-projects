#include <iostream>
using namespace std;

// node of the linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// singly linked list structure
typedef struct LinkedList {
    Node* head;
    int elementCount;
} LinkedList;

/* --- Functions --- */

void initList(LinkedList* list) {
    list->head = NULL;
    list->elementCount = 0;
}

void addFront(LinkedList* list, int newElement) {
    Node* newNode = new Node;
    newNode->data = newElement;
    newNode->next = list->head;
    list->head = newNode;
    list->elementCount++;
}

void add(LinkedList* list, int newElement, int position) {
    if (position == 0) {
        addFront(list, newElement);
        return;
    }
    else if (position >= list->elementCount) {
        return;
    }
    Node* prevNode = NULL;
    Node* positionPtr = list->head;
    for (int i = 0; i < position; i++) {
        prevNode = positionPtr;
        positionPtr = positionPtr->next;
    }
    Node* newNode = new Node;
    newNode->data = newElement;
    prevNode->next = newNode;
    newNode->next = positionPtr;
    list->elementCount++;
}

void removeFront(LinkedList* list) {
    if (list->head != NULL) {
        Node* deletedNode = list->head;
        list->head = list->head->next;
        delete deletedNode;
        list->elementCount--;
    }
}

void removeAtPosition(LinkedList* list, int position) {
    if (position == 0) {
        removeFront(list);
        return;
    }
    else if (position >= list->elementCount) {
        return;
    }
    Node* prevNode = NULL;
    Node* positionPtr = list->head;
    for (int i = 0; i < position; i++) {
        prevNode = positionPtr;
        positionPtr = positionPtr->next;
    }
    Node* deletedNode = positionPtr;
    prevNode->next = positionPtr->next;
    delete deletedNode;
    list->elementCount--;
}

void printList(LinkedList list) {
    Node* ptr = list.head;
    while (ptr != NULL) {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}

/* --- Main Function --- */
int main() {
    // initializing the linked list
    LinkedList mySinglyLinkedList;
    initList(&mySinglyLinkedList);

    addFront(&mySinglyLinkedList, 7);
    addFront(&mySinglyLinkedList, 5);
    addFront(&mySinglyLinkedList, 3);
    addFront(&mySinglyLinkedList, 1);

    add(&mySinglyLinkedList, 31, 2);

    removeAtPosition(&mySinglyLinkedList, 1);
    removeFront(&mySinglyLinkedList);

    printList(mySinglyLinkedList);

    return 0;
} // end main