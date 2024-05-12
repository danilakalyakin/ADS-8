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
    if (!first)
        return 0;

    first->light = true;
    Cage* copyfirst = first;
    int cages = 1;

    while (copyfirst->next != first) {
        if (copyfirst->light) {
            cages++;
            copyfirst = copyfirst->next;
        } else {
            Cage* temp = copyfirst;
            copyfirst->prev->next = copyfirst->next;
            copyfirst->next->prev = copyfirst->prev;
            copyfirst = copyfirst->next;
            delete temp;
        }
    }

    countOp += 2 * cages;
    return cages;
}

int Train::getOpCount() { return countOp; } 