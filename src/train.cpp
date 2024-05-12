// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCage(bool cond) {
    Cage* newCage = new Cage;
    newCage->light = cond;

    if (!first) {
        newCage->next = newCage;
        newCage->prev = newCage;
        first = newCage;
    } else {
        newCage->next = first;
        newCage->prev = first->prev;
        first->prev->next = newCage;
        first->prev = newCage;
    }
}

int Train::getLength() {
    int length = 0;
    Cage* current = first;
    do {
        length++;
        current = current->next;
    } while (current != first);
        return length;
}

int Train::getOpCount() {
    return countOp;
}