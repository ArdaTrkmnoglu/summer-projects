#include <iostream>
using namespace std;

// node of the linked list
typedef struct Node {
    int data;
    struct Node* previous;
    struct Node* next;
} Node;

// doubly linked list structure
typedef struct LinkedList {
    Node* head;
    Node* tail;
    int elementCount;
} LinkedList;

/* --- Functions --- */

void initList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->elementCount = 0;
}

void addFront(LinkedList* list, int newElement) {
    Node* newNode = new Node;
    newNode->data = newElement;
    newNode->previous = NULL;
    newNode->next = list->head;
    if (list->head != NULL) {
        list->head->previous = newNode;
    }
    else {
        list->tail = newNode;
    }
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
    newNode->previous = prevNode;
    newNode->next = positionPtr;

    if (positionPtr != NULL) {
        positionPtr->previous = newNode;
    }
    if (position == list->elementCount) {
        list->tail = newNode;
    }
    list->elementCount++;
}

void removeFront(LinkedList* list) {
    if (list->head != NULL) {
        Node* deletedNode = list->head;
        list->head = list->head->next;
        if (list->head != NULL) {
            list->head->previous = NULL;
        }
        else {
            list->tail = NULL;
        }
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
    if (positionPtr->next != NULL) {
        positionPtr->next->previous = prevNode;
    }
    if (position == list->elementCount-1) {
        list->tail = prevNode;
    }

    delete deletedNode;
    list->elementCount--;
}

void printList(LinkedList* list) {
    for (Node* ptr = list->head; ptr != NULL; ptr = ptr->next) {
        cout << ptr->data << endl;
    }
}

void reversePrintList(LinkedList* list) {
    for (Node* ptr = list->tail; ptr != NULL; ptr = ptr->previous) {
        cout << ptr->data << endl;
    }
}

/* --- Main Function --- */
int main() {
    // initializing the linked list
    LinkedList myDoublyLinkedList;
    initList(&myDoublyLinkedList);

    addFront(&myDoublyLinkedList, 7);
    addFront(&myDoublyLinkedList, 5);
    addFront(&myDoublyLinkedList, 3);
    addFront(&myDoublyLinkedList, 1);

    add(&myDoublyLinkedList, 31, 2);

    removeAtPosition(&myDoublyLinkedList, 1);
    removeFront(&myDoublyLinkedList);

    cout << "HeadToTail:" << endl;
    printList(&myDoublyLinkedList);
    cout << "TailToHead:" << endl;
    reversePrintList(&myDoublyLinkedList);

    return 0;
} // end main