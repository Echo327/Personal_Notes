// Remote Procedure Call Example

// typically used in distributed systems where an object exists in a
// different address space (like on a remote server), and the proxy
// serves as a local representation of that remote object.
// The proxy handles communication between the client and the
// remote object, abstracting the details of network communication.

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// Simulation of a remote service
class RealService {
public:
    void fetchDataFromRemoteServer() {
        std::cout << "Fetching data from the remote server...\n";
        std::this_thread::sleep_for(std::chrono::seconds(5)); // Exaggerated network delay
        std::cout << "Data fetched from remote server\n";
    }
};

// Proxy for the remote object
class RemoteProxy {
private:
    RealService* realService; // Pointer to the real service (remote object)

public:
    RemoteProxy() : realService(nullptr) {}

    ~RemoteProxy() {
        if (realService) {
            delete realService;
        }
    }

    void fetchData() {
        // If the real object isn't created yet, create it
        if (!realService) {
            realService = new RealService();
        }
        std::cout << "Sending request to remote server...\n";
        realService->fetchDataFromRemoteServer();
    }
};

int main() {
    // Client code goes via the proxy to interrogate remote server
    RemoteProxy proxy;
    std::cout << "Client: Requesting data...\n";
    proxy.fetchData();  // Proxy forwards the request to the real service

    return 0;
}
