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
class Creature
{
public:
    string name;
    bool costTypeIsBlood; // can either be blood or bones
    int cost; // blood range: 1-4 bones: 1-infinity
    int attack;
    int health;
    vector<string> tribe = {};
    vector<string> sigils = {};
};

// example class to show all possible options
class Example : public Creature
{
    vector<string> sigils = {"Airborne", "Amorphous", "Ant Spawner", "Bees Within", "Bellist", "Bifurcated Strike", "Bone King", "Burrower", "Corpse Eater", "Dam Builder", "Fecundity", "Fledling", "Frozen Away", "Guardian", "Hefty", "Hoarder", "Leader", "Loose Tail", "Many Lives", "Mighty Leap", "Omni Strike", "Rabbit Hole", "Repulsive", "Sharp Quills", "Sprinter", "Steel Trap", "Stinky", "Tidal Lock", "Touch of Death", "Trifurcated Strike", "Trinket Bearer", "Unkillable", "Waterborne", "Worthy Sacrifice"};
};


class Squirrel : public Creature
{};


class Stoat : public Creature
{
    string name = "Stoat";
    bool costTypeIsBlood = true; // can either be blood or bones
    int cost = 1; // blood range: 1-4 bones: 1-infinity
    int attack = 1;
    int health = 3;
};


class DireWolf : public Creature
{
    string name = "Dire Wolf"
};


// Functions
int main()
{
    cout << colors.GREEN_BACKGROUND << "Hello World!";
}

