// train.cpp
#include "train.h"

Train::Train() {
first = nullptr;
countOp = 0;
}

void Train::addCage(bool cond) {
    if (!first) {
        Cage* newCage = new Cage;
        newCage->light = cond;
        newCage->next = newCage;
        newCage->prev = newCage;
        first = newCage;
    } else {
        Cage* newCage = new Cage;
        newCage->light = cond;
        newCage->next = first;
        newCage->prev = first->prev;
        first->prev->next = newCage;
        first->prev = newCage;
    }
}

int Train::getLength() {
if (!first)
    return 0;

Cage* current = first;
int length = 0;
do {
    length++;
    current = current->next;
} while (current != first);
    return length;
}

int Train::getOpCount() { return countOp; }