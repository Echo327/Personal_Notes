#include <iostream>
#include <vector>

class GreenState;
class YellowState;
class RedState;

class State {
public:
    State * _nextState;
    State() {_nextState = nullptr;}
    State * next() {return _nextState;};
    virtual void display() const = 0;
};


class RedState : public State {
    public:
        RedState() : State() {}
        void setNextState(GreenState * nextState) {
            _nextState = (State *) nextState;
        }
    
        void display() const override {
            std::cout << "The traffic light is Red. Cars must stop.\n";
        }
    };    

class YellowState : public State {
    public:
        void setNextState(RedState * nextState) {
            _nextState = (State *) nextState;
        }
    
        void display() const override {
            std::cout << "The traffic light is Yellow. Prepare to stop.\n";
        }
    };

class GreenState : public State {
public:
    void setNextState(YellowState * nextState) {
        _nextState = (State *) nextState;
    }
    void display() const override {
        std::cout << "The traffic light is Green. Vehicles can go.\n";
    }
};

class TrafficLight {
    private:
        State* currentState;

        // std::vector<State*> states;
    
    public:
        TrafficLight() {
         
            RedState * red = new RedState();
            GreenState * green = new GreenState();
            YellowState * yellow = new YellowState();
            red->setNextState(green);
            green->setNextState(yellow);
            yellow->setNextState(red);
            // states.push_back(red);
            // states.push_back(yellow);
            // states.push_back(green);
            
            currentState = red;
        }
    
        void next() {
            currentState = currentState->next();
        }
    
        void display() const {
            currentState->display();
        }
    };
    
int main() {
    // Set initial state to Green
    TrafficLight trafficLight;
    
    // Should go Green -> Yellow -> Red -> Green
    for (int i = 0; i < 10; ++i) {
        trafficLight.display();
        trafficLight.next();
    }

    return 0;
}
