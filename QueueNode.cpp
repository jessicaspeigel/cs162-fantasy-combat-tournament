/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_tournament
** Date: 02/28/2018
** Description: 
****************************************************/
#include "QueueNode.hpp"

QueueNode::QueueNode(Character* player, QueueNode *next, QueueNode *prev) {
    setPlayer(player);
    setNext(next);
    setPrev(prev);
}

QueueNode::QueueNode(Character* player) {
    setPlayer(player);
    setNext(nullptr);
    setPrev(nullptr);
}

Character* QueueNode::getPlayer() {
    return player;
}

void QueueNode::setPlayer(Character* player) {
    this->player = player;
}

QueueNode* QueueNode::getNext() {
    return this->next;
}

void QueueNode::setNext(QueueNode *next) {
    this->next = next;
}

QueueNode* QueueNode::getPrev() {
    return this->prev;
}

void QueueNode::setPrev(QueueNode *prev) {
    this->prev = prev;
}
