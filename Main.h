#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>  // For rand()
#include <ctime>    // For seeding rand()

#include "Creatures.cpp"
#include "Escape-Codes.cpp"

int main();
unique_ptr<Creature> moveRandomCreature(vector<unique_ptr<Creature>>& fromDeck, vector<unique_ptr<Creature>>& toDeck);
void fightSetup();
void test();
void printDeck(const vector<unique_ptr<Creature>>& deck, const string& deckName);

