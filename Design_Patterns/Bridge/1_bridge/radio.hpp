// Disclaimer: This file is entirely
// Generated by OpenAI's ChatGPT-4, February 2025
// for prompting practice

// Radio.hpp
#ifndef RADIO_HPP
#define RADIO_HPP

#include "Device.hpp"
#include <iostream>

class Radio : public Device {
public:
    void turnOn() override {
        std::cout << "Radio is now ON." << std::endl;
    }

    void turnOff() override {
        std::cout << "Radio is now OFF." << std::endl;
    }
};

#endif // RADIO_HPP
