// copyright 2021 nntu-cs
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
        Cage* copyfirst = first;
        Cage* newCage = new Cage;
        newCage->light = cond;
        newCage->next = first;
        newCage->prev = first->prev;
        first->prev->next = newCage;
        first->prev = newCage;
    }
}

int Train::getLength() {
    int Cages = 0;
    Cage* current = first;
    do {
        if (current->light) {
            Cages++;
            current->light = false;
            countOp += 2 * Cages;
        }
        current = current->next;
    } while (current != first);
    return Cages;
}

int Train::getOpCount() { 
    return countOp; 
}