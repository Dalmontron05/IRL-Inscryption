//* Main C++ file

// Imports
#include <iostream>
#include <string>
#include <vector>

// #include "main.h"
#include "Color-Codes.cpp"

using namespace std;


// Global Variables


// Classes
class Sigils
{
public:
    vector<string> name = {"Airborne", "Amorphous", "Ant Spawner", "Bees Within", "Bellist", "Bifurcated Strike", "Bone King", "Burrower", "Corpse Eater", "Dam Builder", "Fecundity", "Fledling", "Frozen Away", "Guardian", "Hefty", "Hoarder", "Leader", "Loose Tail", "Many Lives", "Mighty Leap", "Omni Strike", "Rabbit Hole", "Repulsive", "Sharp Quills", "Sprinter", "Steel Trap", "Stinky", "Tidal Lock", "Touch of Death", "Trifurcated Strike", "Trinket Bearer", "Unkillable", "Waterborne", "Worthy Sacrifice"};

    vector<string> description = {};
};

class Card
{
public:
    vector<string> name = {"Stoat"};
    vector<bool> costTypeIsBlood = {true}; // can either be blood or bones
    vector<int> costAmount = {1}; // blood range: 1-4 bones: 1-infinity
    vector<int> attackAmount = {1};
    vector<int> healthAmount = {3};
};

class Stoat



// Functions
int main()
{
    cout << colors.GREEN_BACKGROUND << "Hello World!";
}

