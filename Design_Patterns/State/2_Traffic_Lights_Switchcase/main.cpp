#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

enum TrafficLightState {
    RED,
    YELLOW,
    GREEN
};

void runTrafficLight() {
    TrafficLightState state = GREEN;

    while (true) {
        switch (state) {
            case RED:
                cout << "Red Light - Stop!" << endl;
                this_thread::sleep_for(chrono::seconds(3));
                state = GREEN;
                break;

            case YELLOW:
                cout << "Yellow Light - Slow Down" << endl;
                this_thread::sleep_for(chrono::seconds(3));
                state = RED;
                break;

            case GREEN:
                cout << "Green Light - Go" << endl;
                this_thread::sleep_for(chrono::seconds(3));
                state = YELLOW;
                break;

            default:
                cout << "Invalid state!" << endl;
                break;
        }
    }
}

int main() {
    runTrafficLight();
    
    return 0;
}
