//* Main C++ file

// * Imports
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>  // For rand()
#include <ctime>    // For seeding rand()

#include "main.h"
// #include "Escape-Codes.cpp"
// #include "Creatures.cpp"

using namespace std;

// TODO: eventually make it to where a deck isn't simplified to just "creatures," and that they are unique subclasses (since bell tentale and dire wolf are going to need their own implimentations for the attack and 1 turn grow up sigils respectively)

// * Variables
bool willReplay = true;
vector<unique_ptr<Creature>> mainDeck;
vector<unique_ptr<Creature>> sideDeck;
// we have temporary decks to keep track of which cards have been drawn in a fight.
vector<unique_ptr<Creature>> tempMainDeck;
vector<unique_ptr<Creature>> tempSideDeck;
// for now, current hand creatures are also considered on the board
vector<unique_ptr<Creature>> currentHand;


// * Functions
int main() {
    // Clears previous input
    cout << ANSI.CLEAR;
    
    // Adding creatures to the deck (vanilla starting deck)
    mainDeck.push_back(make_unique<Bullfrog>());
    mainDeck.push_back(make_unique<Stoat>());
    mainDeck.push_back(make_unique<Wolf>());
    mainDeck.push_back(make_unique<Wolf>());

    // Add 10 Squirrels to the side deck
    for (int i = 0; i < 10; i++)
    {
        sideDeck.push_back(make_unique<Squirrel>());
        // tempSideDeck.push_back(make_unique<Squirrel>());
    }

    // while (willReplay == true)
    // {
        // Gives user the list of options available in the application
        cout << "What will you do (Enter integer)?" << endl << endl;
        cout << "1) Draw First Card 2) Draw From Main Deck 3) Draw From Side Deck" << endl;
        cout << "\t\t4) Discard Card 5) Reset 6) Exit" << endl;

        // Asks user for choice input
        int userChoice;
        cin >> userChoice;
        cin.ignore(1000, '\n');

        cout << ANSI.CLEAR;

        // logic for choice
        switch (userChoice)
        {
            case 1:
                cout << "Starting fight sequence, drawing first 5 cards..." << endl;
                fightSetup();
                break;
            case 2:
                cout << "Drawing card from main deck..." << endl;
                break;
            case 3:
                cout << "Drawing card from side deck..." << endl;
                break;
            case 4:
                cout << "Which card should be discarded?" << endl;
                break;
            case 5:
                cout << "Stopping fight sequence" << endl;
                break;
            case 6:
                cout << "Exiting..." << endl;
                willReplay = false;
                break;
            default:
                cerr << "Invalid input detected. Exiting..." << endl;
                willReplay = false;
        }

        printDeck(mainDeck, "Main Deck");
        cout << endl;
        printDeck(sideDeck, "Side Deck");
        cout << endl;
        printDeck(tempMainDeck, "Temp Main Deck");
        cout << endl;
        printDeck(tempSideDeck, "Temp Side Deck");
        cout << endl;
        printDeck(currentHand, "Current Hand");
    // }
    
    return 0;
}


// Function to randomly move a creature between two decks
unique_ptr<Creature> moveRandomCreature(vector<unique_ptr<Creature>>& fromDeck, vector<unique_ptr<Creature>>& toDeck) {
    // Ensure the `fromDeck` is not empty
    if (fromDeck.empty()) {
        cout << "No creatures available in the source deck!" << endl;
        return nullptr; // Return null if no creatures are available to move
    }

    // Seed the random number generator
    srand(static_cast<unsigned>(time(0)));

    // Randomly select an index from the `fromDeck`
    size_t randomIndex = rand() % fromDeck.size();
    if (!fromDeck[randomIndex]) {
        cerr << "Error: Null creature at random index in fromDeck!" << endl;
        return nullptr;
    }

    // Move the selected creature to `toDeck`
    unique_ptr<Creature> movedCreature = move(fromDeck[randomIndex]);
    if (!movedCreature) {
        cerr << "Error: Moved creature is null!" << endl;
        return nullptr;
    }
    toDeck.push_back(move(movedCreature));

    // Remove the creature from `fromDeck`
    fromDeck.erase(fromDeck.begin() + randomIndex);

    // Return the moved creature
    return move(toDeck.back());
}


// Sets up initial prerequisites needed before a fight happens
void fightSetup()
{
    // Clear temp decks to ensure they're empty
    tempMainDeck.clear();
    tempSideDeck.clear();

    // Duplicate mainDeck into tempMainDeck
    for (const auto& creature : mainDeck) {
        if (!creature) {
            cerr << "Error: Null creature in mainDeck!" << endl;
            continue;
        }
        tempMainDeck.push_back(creature -> clone());  // Use clone for deep copy
    }

    // Duplicate sideDeck into tempSideDeck
    for (const auto& creature : sideDeck) {
        if (!creature) {
            cerr << "Error: Null creature in sideDeck!" << endl;
            continue;
        }
        tempSideDeck.push_back(creature -> clone());
    }

    // draw a squirel from side deck
    auto movedSquirrel = moveRandomCreature(tempSideDeck, currentHand);
    if (!movedSquirrel) {
        cerr << "Error: Failed to move squirrel to currentHand!" << endl;
    }
    
    // * Fair Hand Mechanic: Randomly draws one free/one blood cost card from tempMainDeck to current hand, then removes that creature from tempMainDeck.
    // Collect indices of all creatures matching the criteria
    vector<size_t> matchingIndices;
    
    for (size_t i = 0; i < tempMainDeck.size(); i++) {
        Creature* creature = tempMainDeck[i].get();
        if (!creature) {
            cerr << "Error: Null creature in tempMainDeck!" << endl;
            continue;
        }
        if (creature -> getCostTypeIsBlood() && creature -> getCost() < 2) {
            matchingIndices.push_back(i);
        }
    }

    // Randomly pick one creature from matchingIndices
    if (!matchingIndices.empty()) {
        srand(static_cast<unsigned>(time(0))); // Seed random number generator
        size_t randomIndex = matchingIndices[rand() % matchingIndices.size()];

        // Move the chosen creature to currentHand
        unique_ptr<Creature> chosenCreature = move(tempMainDeck[randomIndex]);
        if (!chosenCreature) {
            cerr << "Error: Chosen creature is null!" << endl;
        } else {
            currentHand.push_back(move(chosenCreature));
        }

        // Remove it from tempMainDeck
        tempMainDeck.erase(tempMainDeck.begin() + randomIndex);
    } else {
        cerr << "Error: No creatures match the criteria!" << endl;
    }
}

void test()
{
    // TEST: Display stats of all creatures in the deck
    // cout << "main deck" << endl;
    // for (const auto& creature : mainDeck) {
    //     creature -> displayStats();
    // }

    // cout << endl;
    // cout << endl;

    // Display stats of all creatures in the temp deck
    cout << "temp main deck" << endl;
    for (const auto& creature : tempMainDeck) {
        creature -> displayStats();
    }

    cout << endl;
    cout << endl;

    // Display stats of all creatures in current hand
    cout << "current hand" << endl;
    for (const auto& creature : currentHand) {
        creature -> displayStats();
    }
}

void printDeck(const vector<unique_ptr<Creature>>& deck, const string& deckName) {
    cout << "Deck: " << deckName << " (Size: " << deck.size() << ")" << endl;
    for (size_t i = 0; i < deck.size(); i++) {
        if (deck[i]) {
            cout << "[" << i << "] ";
            deck[i]->displayStats();
        } else {
            cout << "[" << i << "] Null Creature!" << endl;
        }
    }
    cout << endl;
}

