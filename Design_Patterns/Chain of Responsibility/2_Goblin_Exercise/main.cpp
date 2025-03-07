// Example:
// Suppose you have 3 ordinary goblins in play. Each one is a 1/3 (1/1 + 0/2 defense bonus).
// A goblin king comes into play.
// Now every ordinary goblin is a 2/4 (1/1 + 0/3 defense bonus from each other + 1/0 from goblin king)
// Meanwhile, the goblin king itself is 3/6 (3/3 + 0/3 defense bonus from other goblins)

#include <iostream>
#include <vector>
#include <string>

struct Creature;

struct Game {
    std::vector<Creature*> creatures;
};

struct StatQuery {
    enum Statistic { attack, defense } statistic;
    int result;
};

struct Creature {
protected:
    Game& game;
    int base_attack, base_defense;

public:
    Creature(Game &game, int base_attack, int base_defense) : game(game), base_attack(base_attack),
                                                              base_defense(base_defense) {}
    virtual int get_attack() = 0;
    virtual int get_defense() = 0;
    virtual std::string get_name() = 0; // Method to get the name of the creature
    virtual ~Creature() {}
};

class Goblin : public Creature {
public:
    Goblin(Game &game, int base_attack, int base_defense) : Creature(game, base_attack, base_defense) {}

    Goblin(Game &game) : Creature(game, 1, 1) {}

    int get_attack() override {
        int attack_bonus = 0;
        for (Creature* creature : game.creatures) {
            if (creature->get_name() == "Goblin King" && creature != this)
            {
                attack_bonus++;
            }
        }
        return base_attack + attack_bonus;
    }

    int get_defense() override {
        int defense_bonus = 0;
        for (Creature* creature : game.creatures) {
            if ((creature->get_name() == "Goblin King" || creature->get_name() == "Goblin") && creature != this)
            {
                defense_bonus++;
            }
        }
        return base_defense + defense_bonus;
    }

    std::string get_name() override {
        return "Goblin";
    }
};

class GoblinKing : public Goblin {
public:
    GoblinKing(Game &game) : Goblin(game, 3, 3) {}

    int get_attack() override {
        int attack_bonus = 0;
        for (Creature* creature : game.creatures) {
            if (creature->get_name() == "Goblin King" && creature != this)
            {
                attack_bonus++;
            }
        }
        return base_attack + attack_bonus;
    }

    int get_defense() override {
        int defense_bonus = 0;
        for (Creature* creature : game.creatures) {
            if ((creature->get_name() == "Goblin King" || (creature->get_name() == "Goblin")) && creature != this)
            {
                defense_bonus++;
            }
        }
        return base_defense + defense_bonus;
    }

    std::string get_name() override {
        return "Goblin King";
    }
};

int main() {
    Game game;

    Goblin goblin(game);
    Goblin goblin2(game);
    Goblin goblin3(game);
    GoblinKing goblinKing(game);

    // Adding creatures to the game
    game.creatures.push_back(&goblin);
    game.creatures.push_back(&goblin2);
    game.creatures.push_back(&goblin3);
    game.creatures.push_back(&goblinKing);
    
    // Printing details of each creature
    for (Creature* creature : game.creatures) {
        std::cout << "Creature Name: " << creature->get_name() << "\n";
        std::cout << "Creature Attack: " << creature->get_attack() << "\n";
        std::cout << "Creature Defense: " << creature->get_defense() << "\n";
    }

    return 0;
}
