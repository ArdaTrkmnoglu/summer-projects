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

/* --- Main Function --- */
int main() {
    // memory allocation for nodes
    Node* node1 = (Node*)malloc(sizeof(Node));
    Node* node2 = (Node*)malloc(sizeof(Node));
    Node* node3 = (Node*)malloc(sizeof(Node));

    // initializing data inside of nodes
    node1->data = 1;
    node2->data = 3;
    node3->data = 5;

    // next elements of singly linked list
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    // initializing the linked list
    LinkedList mySinglyLinkedList;
    mySinglyLinkedList.head = node1;
    mySinglyLinkedList.elementCount = 3;

    Node* ptr = mySinglyLinkedList.head;
    while (ptr != NULL) {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
    
    free(node1);
    free(node2);
    free(node3);

    return 0;
} // end main