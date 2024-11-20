//* Contains all of the creatures you can have within a deck

// Imports
#include <iostream>
#include <string>
#include <vector>

using namespace std;


// Classes
class Creature
{
private:
    // Attributes
    string name;
    bool costTypeIsBlood; // can either be blood or bones
    int cost; // blood range: 1-4. bones: 1-infinity
    int attack;
    int health;
    vector<string> tribe;
    // Can be the following sigils: {"None", "Airborne", "Amorphous", "Ant Spawner", "Bees Within", "Bellist", "Bifurcated Strike", "Bone King", "Burrower", "Corpse Eater", "Dam Builder", "Fecundity", "Fledling", "Frozen Away", "Guardian", "Hefty", "Hoarder", "Leader", "Loose Tail", "Many Lives", "Mighty Leap", "Omni Strike", "Rabbit Hole", "Repulsive", "Sharp Quills", "Sprinter", "Steel Trap", "Stinky", "Tidal Lock", "Touch of Death", "Trifurcated Strike", "Trinket Bearer", "Unkillable", "Waterborne", "Worthy Sacrifice"};
    vector<string> sigils;


public:
    // Constructor
    Creature(){}

    Creature(string name, bool costTypeIsBlood, int cost, int attack, int health, vector<string> tribe, vector<string> sigils)
    {
        this -> name = name;
        this -> costTypeIsBlood = costTypeIsBlood;
        this -> cost = cost;
        this -> attack = attack;
        this -> health = health;
        this -> tribe = tribe;
        this -> sigils = sigils;
    }


    // getters and setters
    string getName()
    {
        return name;
    }


    // Functions
    void hiThere()
    {
        cout << "My name is : " << name;
    }
};


// class Squirrel : public Creature
// {};


class Stoat : public Creature
{
public:
    // using Creature::Creature;
    // Stoat(string name, bool costTypeIsBlood, int cost, int attack, int health, vector<string> tribe, vector<string> sigils) : Creature("Stoat", true, 1, 1, 3, "None", "None") {}

    Stoat()
    {
        string name = "Stoat";
        bool costTypeIsBlood = true;
        int cost = 1;
        int attack = 1;
        int health = 3;
        vector<string> tribe = {"None"};
        vector<string> sigils = {"None"};
    }
};


// class DireWolf : public Creature
// {
//     string name = "Dire Wolf";
// };

