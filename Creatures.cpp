//* Contains all of the creatures you can have within a deck

// Imports
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Classes
class Creature
{
public:
    // Attributes
    string name;
    bool costTypeIsBlood; // can either be blood or bones
    int cost; // blood range: 1-4. bones: 1-infinity
    int attack;
    int health;
    vector<string> tribe = {};
    // Can be the following sigils: {"None", "Airborne", "Amorphous", "Ant Spawner", "Bees Within", "Bellist", "Bifurcated Strike", "Bone King", "Burrower", "Corpse Eater", "Dam Builder", "Fecundity", "Fledling", "Frozen Away", "Guardian", "Hefty", "Hoarder", "Leader", "Loose Tail", "Many Lives", "Mighty Leap", "Omni Strike", "Rabbit Hole", "Repulsive", "Sharp Quills", "Sprinter", "Steel Trap", "Stinky", "Tidal Lock", "Touch of Death", "Trifurcated Strike", "Trinket Bearer", "Unkillable", "Waterborne", "Worthy Sacrifice"};
    vector<string> sigils = {};

    // Functions
    void hiThere()
    {
        cout << "My name is :" << name;
    }
};


class Squirrel : public Creature
{};


class Stoat : public Creature
{
    string name = "Stoat";
    bool costTypeIsBlood = true;
    int cost = 1;
    int attack = 1;
    int health = 3;
    vector<string> tribe = {"None"};
    vector<string> sigils = {"None"};

};


class DireWolf : public Creature
{
    string name = "Dire Wolf";
};

