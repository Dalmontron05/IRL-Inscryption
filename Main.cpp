//* Main C++ file

// Imports
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>  // For rand()
#include <ctime>    // For seeding rand()

// #include "main.h"
// #include "Color-Codes.cpp"
#include "Creatures.cpp"

using namespace std;

// Variables
vector<unique_ptr<Creature>> mainDeck;
// we have a temporary main deck to keep track of which cards have been drawn in a fight.
vector<unique_ptr<Creature>> tempMainDeck;
vector<unique_ptr<Creature>> currentHand;


// Randomly draws one free/one blood cost card from tempMainDeck to current hand, then removes that creature from tempMainDeck.
void fairHandMechanic(vector<unique_ptr<Creature>>& mainDeck) {
    // Copy mainDeck to tempMainDeck
    for (const auto& creature : mainDeck) {
        tempMainDeck.push_back(make_unique<Creature>(*creature)); // Create a deep copy
    }

    // Collect indices of all creatures matching the criteria
    vector<size_t> matchingIndices;
    for (size_t i = 0; i < tempMainDeck.size(); ++i) {
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

    // Output results
    cout << "Current Hand:" << endl;
    for (const auto& creature : currentHand) {
        creature->displayStats();
    }

    cout << "Remaining Temp Main Deck:" << endl;
    for (const auto& creature : tempMainDeck) {
        creature->displayStats();
    }
}


int main() {
    // Decks of creatures

    // Adding creatures to the deck
    mainDeck.push_back(make_unique<Bullfrog>());
    mainDeck.push_back(make_unique<Stoat>());
    mainDeck.push_back(make_unique<Wolf>());
    mainDeck.push_back(make_unique<Wolf>());

    // // Display stats of all creatures in the deck
    // for (const auto& creature : mainDeck) {
    //     creature->displayStats();
    // }

    // int index = 2; // Example: Access the third creature (index 2)
    // if (index >= 0 && index < mainDeck.size()) {
    //     cout << "Displaying stats for creature at index " << index << ":" << endl;
    //     mainDeck[index]->displayStats();
    // } else {
    //     cout << "Invalid index!" << endl;
    // }

    fairHandMechanic(mainDeck);
    fairHandMechanic(mainDeck);

    return 0;
}

