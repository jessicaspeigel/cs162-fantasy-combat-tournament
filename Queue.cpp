/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_lab_7
** Date: 02/25/2018
** Description: Implementation for Queue class.
****************************************************/
#include "Queue.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

/****************************************************
** Constructors / Destructor
****************************************************/

Queue::Queue() {
    head = nullptr;
}

Queue::~Queue() {
    clearList();
}

/****************************************************
** Description: Deletes all items in the list.
****************************************************/

void Queue::clearList() {
    // Only delete shit if there's shit to delete
    if (!isEmpty()) {
        QueueNode* n = getHead();
        do {
            //Pointer to node to be deleted
            QueueNode* garbage = n;
            // Move on to the next
            n = n->next;
            // Delete the garbage node
            delete garbage;
        } while(n != nullptr && n != getHead());
    }
}

/****************************************************
** Description: Adds a new node to the back of the
** queue.
****************************************************/

void Queue::addBack(Character* playerPtr) {
    // This constructor instantiates with next and prev set to nullptr
    QueueNode* n = new QueueNode(playerPtr);
    // Set the head if none exists
    if (isEmpty()) {
        setHead(n);
    } else {
        // Otherwise, add the new node to the back of the list
        QueueNode* h = getHead();
        // Set the node's next to the current head
        n->next = h;
        // Define a pointer the current back of the queue
        QueueNode *oldBack = h->prev;
        // Set the node's prev to the current back
        n->prev = oldBack;
        // Set the old back's next to the new node
        oldBack->next = n;
        // Update the head node's prev
        h->prev = n;
    }
}

/****************************************************
** Description: Deletes the first item in the list.
** Returns true if the item was deleted. This really
** only returns false if the list is empty.
****************************************************/

bool Queue::removeFront() {
    bool deleteResult = false;
    if (!isEmpty()) {
        QueueNode* h = getHead();
        QueueNode* newHead = nullptr;
        newHead = h->next;
        if (newHead != h) {
            // If this isn't the last item in the list
            newHead->prev = h->prev;
            // Set the last item's next to the new head (if there's more than one item in the queue)
            QueueNode* l = head->prev;
            l->next = newHead;
            // We don't call setHead here, we set the head directly
            head = newHead;
        } else {
            setHead(nullptr);
        }
        // Delete the head
        delete h;
        // Set the delete result to true
        deleteResult = true;
    }
    return deleteResult;
}

/****************************************************
** Description: Prints a single item from the list.
** Takes a pointer to the item to print.
****************************************************/

void Queue::printItem(QueueNode *item) {
    if (item != nullptr) {
        cout << item->player->getName() << endl;
    }
}

/****************************************************
** Description: Prints the list from head to tail.
****************************************************/

void Queue::printList() {
    // Print a message if the list is empty
    if (isEmpty()) {
        cout << "This queue is empty." << endl;
    } else {
        QueueNode* n = getHead();
        do {
            // Print the value
            printItem(n);
            // Move on to the next
            n = n->next;
        } while(n != getHead());
        cout << endl;
    }
}

/****************************************************
** Description: Returns the first item in the list.
****************************************************/

QueueNode *Queue::getHead() {
    return head;
}

/****************************************************
** Description: Private function to set the first
** item in the list. Takes a pointer to the new
** head.
****************************************************/

void Queue::setHead(QueueNode *n) {
    // Only set the prevs and nexts if n isn't null
    if (n != nullptr) {
        if (isEmpty()) {
            // If the list is previously empty, point everything to the head
            n->prev = n;
            n->next = n;
        } else {
            // Set next of the new head to the old head if one exists
            n->next = head;
            n->prev = head->prev;
            // Set prev of the old head to n
            head->prev = n;
        }
    }
    // Set the new head
    head = n;
}

/****************************************************
** Description: Returns true if the queue is empty,
** false if not empty
****************************************************/

bool Queue::isEmpty() {
    return getHead() == nullptr;
}

/****************************************************
** Description: Returns the value in the first node
** in the queue. Note the calling function needs to
** ensure the list isn't empty otherwise it will
** return nullptr.
****************************************************/

Character* Queue::getFront() {
    Character* result = nullptr;
    if (!isEmpty()) {
        result = getHead()->player;
    }
    return result;
}
