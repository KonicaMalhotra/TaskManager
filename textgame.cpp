#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Character class
class Character {
protected:
    string name;
    int health;
    int attack;
    int defense;
public:
    Character(const string& n, int hp, int att, int def) : name(n), health(hp), attack(att), defense(def) {}
    void takeDamage(int damage) {
        int actualDamage = max(0, damage - defense);
        health -= actualDamage;
        cout << name << " takes " << actualDamage << " damage." << endl;
        if (health <= 0) {
            cout << name << " has been defeated!" << endl;
        }
    }
    int getHealth() const { return health; }
    int getAttack() const { return attack; }
    const string& getName() const { return name; }
    bool isAlive() const { return health > 0; }
    virtual void attackTarget(Character& target) = 0;
};

// Enemy class (inherits from Character)
class Enemy : public Character {
public:
    Enemy(const string& n, int hp, int att, int def) : Character(n, hp, att, def) {}
    void attackTarget(Character& target) override {
        int damage = rand() % attack + 1;
        cout << name << " attacks " << target.getName() << " for " << damage << " damage." << endl;
        target.takeDamage(damage);
    }
};

// Player class (inherits from Character)
class Player : public Character {
public:
    Player(const string& n, int hp, int att, int def) : Character(n, hp, att, def) {}
    void attackTarget(Character& target) override {
        int damage = rand() % attack + 1;
        cout << name << " attacks " << target.getName() << " for " << damage << " damage." << endl;
        target.takeDamage(damage);
    }
};

// Function to simulate battle between player and enemy
void battle(Player& player, Enemy& enemy) {
    while (player.isAlive() && enemy.isAlive()) {
        player.attackTarget(enemy);
        if (enemy.isAlive()) {
            enemy.attackTarget(player);
        }
    }
    if (player.isAlive()) {
        cout << "Player wins!" << endl;
    } else {
        cout << "Enemy wins!" << endl;
    }
}

int main() {
    srand(time(nullptr));

    // Create player and enemy
    Player player("Player", 100, 20, 10);
    Enemy enemy("Goblin", 50, 10, 5);

    // Simulate battle
    battle(player, enemy);

    return 0;
}
