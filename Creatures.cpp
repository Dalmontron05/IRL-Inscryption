//* Contains all of the creatures you can have within a deck

// Imports
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Classes
class Creature
{
protected:
    // Attributes
    string name = "bruh";
    bool canBeGained; // Is a card that can be gained through card events
    bool costTypeIsBlood; // can either be blood or bones
    int cost; // blood range: 0-4. bones: 1-infinity (free cards are still considered blood type cards for this implementation)
    int attack;
    int health;
    // Can have the following tribes: Squirrel, Reptile, Insect, Avian, Canine, Hooved
    vector<string> tribe;
    // Can have the following sigils: {"None", "Airborne", "Amorphous", "Ant Spawner", "Bees Within", "Bellist", "Bifurcated Strike", "Bone King", "Burrower", "Corpse Eater", "Dam Builder", "Fecundity", "Fledling", "Frozen Away", "Guardian", "Hefty", "Hoarder", "Leader", "Loose Tail", "Many Lives", "Mighty Leap", "Omni Strike", "Rabbit Hole", "Repulsive", "Sharp Quills", "Sprinter", "Steel Trap", "Stinky", "Tidal Lock", "Touch of Death", "Trifurcated Strike", "Trinket Bearer", "Unkillable", "Waterborne", "Worthy Sacrifice"};
    vector<string> sigils;


public:
    // Constructor
    Creature(string name, bool canBeGained, bool costTypeIsBlood, int cost, int attack, int health, vector<string> tribe, vector<string> sigils)
        : name(name), costTypeIsBlood(costTypeIsBlood), cost(cost), attack(attack), health(health), tribe(tribe), sigils(sigils) {}


    // Functions
    void hiThere()
    {
        cout << "My name is : " << name << endl;
    }
};


// Side Deck
class Squirrel : public Creature
{
public:
    Squirrel()
    : Creature("Squirrel", false, true, 0, 0, 1, {"Squirrel"}, {"None"}) {}
};


// Main Deck
class Bullfrog : public Creature
{
    Bullfrog()
    : Creature("Bullfrog", true, true, 1, 1, 2, {"Reptile"}, {"Mighty Leap"}) {}
};


class Stoat : public Creature
{
public:
    Stoat()
    : Creature("Stoat", true, true, 1, 1, 3, {"None"}, {"None"}) {}
};

class Wolf : public Creature
{
    Wolf()
    : Creature("Wolf", true, true, 2, 3, 2, {"Canine"}, {"None"}) {}
};

