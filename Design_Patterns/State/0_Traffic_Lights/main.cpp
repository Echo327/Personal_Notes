// Does not compile (see Note: below)

#include <iostream>
#include <memory>

class TrafficLight;

class State {
    public:
        virtual void next(TrafficLight& trafficLight) = 0;
        virtual void display() const = 0;
        virtual ~State() = default;
};

class GreenState;

// Context
class TrafficLight {
private:
    std::unique_ptr<State> currentState;

public:
    void setState(std::unique_ptr<State> state) {
        currentState = std::move(state);
    }

    void next() {
        currentState->next(*this);
    }

    void display() const {
        currentState->display();
    }
};

class RedState : public State {
    public:
        void next(TrafficLight& trafficLight) override {
            std::cout << "Red -> Green\n";
            // Note: unique_ptr doesn't work with forward declaration only
            // so the following line in not possible (due to cyclic transition of nodes)
            trafficLight.setState(std::make_unique<GreenState>());
        }
    
        void display() const override {
            std::cout << "The traffic light is Red. Cars must stop.\n";
        }
    };    

class YellowState : public State {
    public:
        void next(TrafficLight& trafficLight) override {
            std::cout << "Yellow -> Red\n";
            // Cast to State pointer explicitly
            trafficLight.setState(std::make_unique<RedState>());
        }
    
        void display() const override {
            std::cout << "The traffic light is Yellow. Prepare to stop.\n";
        }
    };    

class GreenState : public State {
public:
    void next(TrafficLight& trafficLight) override {
        std::cout << "Green -> Yellow\n";
        trafficLight.setState(std::make_unique<YellowState>());
    }

    void display() const override {
        std::cout << "The traffic light is Green. Vehicles can go.\n";
    }
};

int main() {
    // Set initial state to Green
    TrafficLight trafficLight;
    trafficLight.setState(std::make_unique<GreenState>());
    
    // Should go Green -> Yellow -> Red -> Green
    for (int i = 0; i < 10; ++i) {
        trafficLight.display();
        trafficLight.next();
    }

    return 0;
}
