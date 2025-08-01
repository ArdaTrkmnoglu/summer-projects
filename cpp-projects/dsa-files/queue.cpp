#include <iostream>
using namespace std;

// node of the queue
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// queue strucrure
typedef struct Queue {
    Node* head;
    Node* tail;
    int elementCount;
} Queue;

/* --- Functions --- */
void initQueue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
    q->elementCount = 0;
}

void enqueue(Queue* q, int newElement) {
    Node* newNode = new Node;

    newNode->data = newElement;
    newNode->next = NULL;

    if (q->head == NULL) {
        q->head = newNode;
    }

    if (q->tail != NULL) {
        q->tail->next = newNode;
    }
    q->tail = newNode;
    q->elementCount++;
}

void dequeue(Queue* q) {
    if (q->head != NULL) {
        Node* temp = q->head;
        q->head = q->head->next;
        if (q->head == NULL) {
            q->tail = NULL;
        }
        delete(temp);
        q->elementCount--;
    }
    else {
        cout << "Queue is empty." << endl;
        return;
    }
}

int front(Queue* q) {
    if (q->head == NULL) {
        cout << "Queue is empty." << endl;
        return -1;
    }
    return q->head->data;
}

/* --- Main Function --- */
int main() {

    Queue myQueue;
    initQueue(&myQueue);

    for (int i = 5; i > 0; i--) {
        enqueue(&myQueue, i);
    }
    dequeue(&myQueue);

    cout << front(&myQueue) << "\n";
}

