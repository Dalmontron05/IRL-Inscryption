//* Contains all of the creatures you can have within a deck

// Imports
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;


// Base Class
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
public:
    Creature(string name, bool canBeGained, bool costTypeIsBlood, int cost, int attack, int health, vector<string> tribe, vector<string> sigils)
        : name(name), canBeGained(canBeGained), costTypeIsBlood(costTypeIsBlood), cost(cost), attack(attack), health(health), tribe(tribe), sigils(sigils) {}

    // Virtual destructor for proper cleanup
    virtual ~Creature() {} 

    // Getters
    string getName() const {
        return name;
    }

    bool getCanBeGained() const {
        return canBeGained;
    }

    bool getCostTypeIsBlood() const {
        return costTypeIsBlood;
    }

    int getCost() const {
        return cost;
    }

    int getAttack() const {
        return attack;
    }

    int getHealth() const {
        return health;
    }

    vector<string> getTribe() const {
        return tribe;
    }

    vector<string> getSigils() const {
        return sigils;
    }

    // Setters
    void setName(const string& newName) {
        name = newName;
    }

    void setCanBeGained(bool newCanBeGained) {
        canBeGained = newCanBeGained;
    }

    void setCostTypeIsBlood(bool newCostTypeIsBlood) {
        costTypeIsBlood = newCostTypeIsBlood;
    }

    void setCost(int newCost) {
        cost = newCost;
    }

    void setAttack(int newAttack) {
        attack = newAttack;
    }

    void setHealth(int newHealth) {
        health = newHealth;
    }

    void setTribe(const vector<string>& newTribe) {
        tribe = newTribe;
    }

    void setSigils(const vector<string>& newSigils) {
        sigils = newSigils;
    }

    // Functions
    virtual void displayStats() const {
        cout << "Name: " << name << ", Attack: " << attack << ", Health: " << health << endl;
    }
};


// Derived Classes
class Squirrel : public Creature {
public:
    Squirrel()
        : Creature("Squirrel", false, true, 0, 0, 1, {"Squirrel"}, {"None"}) {}
};

class Bullfrog : public Creature {
public:
    Bullfrog()
        : Creature("Bullfrog", true, true, 1, 1, 2, {"Reptile"}, {"Mighty Leap"}) {}
};

class Stoat : public Creature {
public:
    Stoat()
        : Creature("Stoat", true, true, 1, 1, 3, {"None"}, {"None"}) {}
};

class Wolf : public Creature {
public:
    Wolf()
        : Creature("Wolf", true, true, 2, 3, 2, {"Canine"}, {"None"}) {}
};

