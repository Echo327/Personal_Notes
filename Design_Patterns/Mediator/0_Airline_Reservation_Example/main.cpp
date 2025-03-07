#include <iostream>
#include <vector>
#include <string>

// Forward declarations for mediator pattern
class ReservationSystem;
class Customer;
class Flight;

enum Action {
    BOOK,
    CANCEL,
    INVALID
};

Action stringToAction(const std::string& action) {
    if (action == "book") return BOOK;
    if (action == "cancel") return CANCEL;
    return INVALID;
}

// Abstract Mediator class
class Mediator {
public:
    virtual void notify(Flight* flight, Customer* customer, const std::string& action) = 0;
};

// Customer class
class Customer {
private:
    std::string name;
    Mediator* mediator;

public:
    Customer(const std::string& name, Mediator* mediator)
        : name(name), mediator(mediator) {}

    void bookFlight(Flight* flight) {
        std::cout << name << " is booking a flight." << std::endl;
        mediator->notify(flight, this, "book");
    }

    void cancelFlight(Flight* flight) {
        std::cout << name << " is canceling a flight." << std::endl;
        mediator->notify(flight, this, "cancel");
    }

    std::string getName() const {
        return name;
    }

    void setMediator(Mediator* mediator) {
        this->mediator = mediator;
    }
};

// Flight class
class Flight {
private:
    std::string flightNumber;
    int availableSeats;
    Mediator* mediator;
    std::vector<std::string> passengers;

public:
    Flight(const std::string& flightNumber, int seats, Mediator* mediator)
        : flightNumber(flightNumber), availableSeats(seats), mediator(mediator) {}

    void reserveSeat(Customer* customer) {
        if (availableSeats > 0) {
            availableSeats--;
            passengers.push_back(customer->getName());
            std::cout << "Seat reserved on flight " << flightNumber << " for " << customer->getName() << ". Remaining seats: " << availableSeats << std::endl;
        } else {
            std::cout << "No seats available on flight " << flightNumber << std::endl;
        }
    }

    void cancelReservation(Customer* customer) {
        for (auto it = passengers.begin(); it != passengers.end(); ++it) {
            if (*it == customer->getName()) {
                passengers.erase(it);
                availableSeats++;
                std::cout << "Reservation cancelled on flight " << flightNumber << " for " << customer->getName() 
                          << ". Available seats: " << availableSeats << std::endl;
                break;
            }
        }
    }

    void setMediator(Mediator* mediator) {
        this->mediator = mediator;
    }

    int getAvailableSeats() const {
        return availableSeats;
    }

    std::string getFlightNumber() const {
        return flightNumber;
    }

    std::vector<std::string> getPassengers() const {
        return passengers;
    }

    friend std::ostream& operator<<(std::ostream& os, const Flight& flight) {
        os << "Flight " << flight.flightNumber << " has " << flight.availableSeats << " seats remaining.\n";
        os << "Passengers: ";
        if (flight.passengers.empty()) {
            os << "No passengers.";
        } else {
            for (const auto& passenger : flight.passengers) {
                os << passenger << " ";
            }
        }
        return os;
    }
};

// ReservationSystem class (Mediator)
class ReservationSystem : public Mediator {
private:
    std::vector<Flight*> flights;
    std::vector<Customer*> customers;

public:
    void addFlight(Flight* flight) {
        flights.push_back(flight);
    }

    void addCustomer(Customer* customer) {
        customers.push_back(customer);
    }

    void notify(Flight* flight, Customer* customer, const std::string& action) override {
        Action actionType = stringToAction(action);

        switch (actionType) {
            case BOOK:
                flight->reserveSeat(customer);  // Pass the customer when reserving a seat
                break;
    
            case CANCEL:
                flight->cancelReservation(customer);  // Pass the customer when canceling
                break;
    
            default:
                std::cout << "Invalid action" << std::endl;
                break;
        }
    }
};

int main() {
    // Create the mediator
    ReservationSystem reservationSystem;

    // Create flights
    Flight flightA("A123", 10, &reservationSystem);
    Flight flightB("B456", 5, &reservationSystem);

    // Create customers
    Customer customer1("John Doe", &reservationSystem);
    Customer customer2("Jane Smith", &reservationSystem);

    // Add flights and customers to the system
    reservationSystem.addFlight(&flightA);
    reservationSystem.addFlight(&flightB);
    reservationSystem.addCustomer(&customer1);
    reservationSystem.addCustomer(&customer2);

    // Book flights
    customer1.bookFlight(&flightA);
    customer2.bookFlight(&flightA);
    customer1.bookFlight(&flightB);

    // Cancel a flight reservation
    customer1.cancelFlight(&flightA);

    // Double-booking allowed
    // Hey someone should check passport numbers at some point
    customer2.bookFlight(&flightA);

    // Should print
    // Flight A Jane and Jane the dirty double booker
    // Flight B John
    std::cout << flightA << std::endl;
    std::cout << flightB << std::endl;

    return 0;
}
