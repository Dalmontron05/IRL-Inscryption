//* Main C++ file

// * Imports
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>  // For rand()
#include <ctime>    // For seeding rand()

#include "main.h"
// #include "Color-Codes.cpp"
#include "Creatures.cpp"

using namespace std;

// TODO: eventually make it to where a deck isn't simplified to just "creatures," and that they are unique subclasses (since bell tentale and dire wolf are going to need their own implimentations for the attack and 1 turn grow up sigils respectively)

// * Variables
vector<unique_ptr<Creature>> mainDeck;
vector<unique_ptr<Creature>> sideDeck;
// we have temporary decks to keep track of which cards have been drawn in a fight.
vector<unique_ptr<Creature>> tempMainDeck;
vector<unique_ptr<Creature>> tempsideDeck;
vector<unique_ptr<Creature>> currentHand;


// * Functions
int main() {
    // Decks of creatures

    // Adding creatures to the deck (vanilla starting deck)
    mainDeck.push_back(make_unique<Bullfrog>());
    mainDeck.push_back(make_unique<Stoat>());
    mainDeck.push_back(make_unique<Wolf>());
    mainDeck.push_back(make_unique<Wolf>());

    // Add 10 Squirrels to the side deck
    for (int i = 0; i < 10; i++)
    {
        sideDeck.push_back(make_unique<Squirrel>());
        tempsideDeck.push_back(make_unique<Squirrel>());
    }

    fightSetup();

    // TEST: Display stats of all creatures in the deck
    cout << "main deck";
    for (const auto& creature : mainDeck) {
        creature->displayStats();
    }

    cout << endl;
    cout << endl;

    // Display stats of all creatures in the temp deck
    cout << "temp main deck";
    for (const auto& creature : tempMainDeck) {
        creature->displayStats();
    }

    cout << endl;
    cout << endl;

    // current hand
    cout << "current hand";
    for (const auto& creature : currentHand) {
    creature->displayStats();
    }
    
    return 0;
}


// Sets up initial prerequisites needed before a fight happens
void fightSetup()
{
    // initalize temp decks as regular decks
    // tempMainDeck = mainDeck;
    // tempsideDeck = sideDeck;

    for (const auto& creature : mainDeck) {
        tempMainDeck.push_back(make_unique<Creature>(*creature));
    }

    for (const auto& creature : sideDeck) {
        tempsideDeck.push_back(make_unique<Creature>(*creature));
    }
    
    // * Fair Hand Mechanic: Randomly draws one free/one blood cost card from tempMainDeck to current hand, then removes that creature from tempMainDeck.
    // Collect indices of all creatures matching the criteria
    vector<size_t> matchingIndices;
    
    for (size_t i = 0; i < tempMainDeck.size(); i++) {
        Creature* creature = tempMainDeck[i].get();
        if (creature->isCostTypeBlood() && creature->getCost() < 2) {
            matchingIndices.push_back(i);
        }
    }

    // Randomly pick one creature from matchingIndices
    if (!matchingIndices.empty()) {
        srand(static_cast<unsigned>(time(0))); // Seed random number generator
        size_t randomIndex = matchingIndices[rand() % matchingIndices.size()];

        // Move the chosen creature to currentHand
        currentHand.push_back(move(tempMainDeck[randomIndex]));

        // Remove it from tempMainDeck
        tempMainDeck.erase(tempMainDeck.begin() + randomIndex);
    }
}

