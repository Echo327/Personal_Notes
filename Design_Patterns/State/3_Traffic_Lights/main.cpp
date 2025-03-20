// unique_ptr and minor changes added by OpenAI's ChatGPT-4, March 2025
// after initial creation

#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct LightData {
    string colour;
    string message;
};

class State {
public:
    virtual void display() const = 0;
    virtual ~State() {}
};

class TrafficLightState : public State {
protected:
    LightData data;

public:
    TrafficLightState(LightData lightData) : data(lightData) {}

    void display() const override {
        cout << data.colour << " Light: " << data.message << endl;
    }
};

class GreenLight : public TrafficLightState {
public:
    GreenLight() : TrafficLightState({"Green", "Go!"}) {}
};

class YellowLight : public TrafficLightState {
public:
    YellowLight() : TrafficLightState({"Yellow", "Slow down..."}) {}
};

class RedLight : public TrafficLightState {
public:
    RedLight() : TrafficLightState({"Red", "Stop!!!"}) {}
};

class Node {
public:
    unique_ptr<State> state;
    unique_ptr<Node> next;

    Node(State* s) : state(s), next(nullptr) {}
};

class TrafficLight {
private:
    unique_ptr<Node> head;
    Node* currentState;

public:
    TrafficLight() : head(nullptr), currentState(nullptr) {}

    TrafficLight& add(State* s) {
        auto newNode = make_unique<Node>(s);
        if (!head) {
            head = move(newNode);
            currentState = head.get();
        } else {
            Node* last = head.get();
            while (last->next) {
                last = last->next.get();
            }
            last->next = move(newNode);
        }
        return *this;
    }

    void next() {
        if (currentState) {
            currentState->state->display();

            if (currentState->next) {
                currentState = currentState->next.get();
            } else {
                currentState = head.get();
            }
        }
    }
};

int main() {
    TrafficLight tl;
    tl.add(new GreenLight())
      .add(new YellowLight())
      .add(new RedLight());

    for (int i = 0; i < 7; ++i) {
        tl.next();
    }

    return 0;
}
