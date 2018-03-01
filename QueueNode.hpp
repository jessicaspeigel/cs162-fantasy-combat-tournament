/****************************************************
** Author: Jessica Speigel
** Assignment: cs162_fantasy_combat_tournament
** Date: 02/28/2018
** Description: QueueNode header
****************************************************/
#ifndef CS162_FANTASY_COMBAT_TOURNAMENT_QUEUENODE_HPP
#define CS162_FANTASY_COMBAT_TOURNAMENT_QUEUENODE_HPP

#include "Character.hpp"

class QueueNode {

private:
    Character* player;
    QueueNode* next;
    QueueNode* prev;

public:
    QueueNode(Character* player, QueueNode* next, QueueNode* prev);
    QueueNode(Character* player);
    Character* getPlayer();
    void setPlayer(Character* player);
    QueueNode* getNext();
    void setNext(QueueNode *next);
    QueueNode* getPrev();
    void setPrev(QueueNode *prev);


};


#endif //CS162_FANTASY_COMBAT_TOURNAMENT_QUEUENODE_HPP
