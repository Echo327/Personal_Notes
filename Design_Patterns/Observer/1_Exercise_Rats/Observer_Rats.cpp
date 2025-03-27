#include <iostream>
#include <vector>
using namespace std;

struct IRat
{
    virtual void updateAttack(int a) = 0;
};

struct Game
{
    vector<IRat*> rats = {};
    
    void join(IRat& rat){
        rats.push_back(&rat);
        updateRatAttacks();
    }
    
    void leave(IRat& rat){
        rats.erase(
            remove(rats.begin(), rats.end(),&rat),
            rats.end());
        updateRatAttacks();
    }
    
    void updateRatAttacks()
    {
        for (IRat* rat : rats)
        {
            rat->updateAttack(rats.size());
        }
    }
};

struct Rat : IRat
{
    Game& game;
    int attack{1};

    Rat(Game &game) : game(game)
    {
      game.join(*this);
      cout << "number of rats " << game.rats.size() << endl;
      attack = game.rats.size();
      cout << "attack A " << attack << endl;
    }

    ~Rat() 
    {
      game.leave(*this);
      cout << "number of rats " << game.rats.size() << endl;
      attack = game.rats.size();
      cout << "attack B " << attack << endl;
    }
    
    void updateAttack(int a) override
    {
        attack = a;
    }
};

int main() 
{
    Game game;

    // Create rats and observe the behavior
    Rat rat1(game);
    Rat rat2(game);
    Rat rat3(game);
    
    // Remove a rat and observe the changes
    {
        Rat rat4(game);
        Rat rat5(game);
    }

    // Final state
    cout << "Final number of rats: " << game.rats.size() << endl;

    return 0;
}
