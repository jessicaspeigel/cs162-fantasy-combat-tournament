/****************************************************
** Author: Jessica Speigel
** Assignment: CS162 cs162_lab_7
** Date: 02/25/2018
** Description: Declaration for Queue class.
****************************************************/

#ifndef CS162_LAB_7_CIRCULARLINKEDLIST
#define CS162_LAB_7_CIRCULARLINKEDLIST

#include "Character.hpp"
#include "QueueNode.hpp"

class Queue {

private:
    QueueNode* head;
    void setHead(QueueNode* n);

public:
    Queue();
    ~Queue();
    void addBack(Character* playerPtr);
    bool removeFront();
    void printItem(QueueNode* item);
    void printList();
    QueueNode* getHead();
    Character* getFront();
    void clearList();
    bool isEmpty();

};


#endif //CS162_LAB_7_CIRCULARLINKEDLIST
