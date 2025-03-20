#include <vector>
#include <iostream>
#include <memory>

#include <vector>
#include <iostream>

class Mediator;

class IParticipant {
public:

    IParticipant() {}

    virtual void say(int value) = 0;
    virtual void receive(int value) = 0;
    virtual ~IParticipant() = default;
};

class Mediator {
public:
    std::vector<IParticipant*> participants;

    void add_participant(IParticipant* participant){
        participants.push_back(participant);
    }

    void broadcast(IParticipant* sender, int val) {
        for (auto participant : participants) {
            if (participant != sender) {
                participant->receive(val);
            }
        }
    }
};

struct Participant : IParticipant
{
    int value{0};
    Mediator& mediator;
    
    Participant(Mediator &mediator) : mediator(mediator)
    {
      mediator.add_participant(this);
    }

    void say(int value) override
    {
        mediator.broadcast(this, value);
    }
    
    void receive(int val) override
    {
        this->value += val;
    }
};

int main() {
    Mediator mediator;
    Participant participant1(mediator);
    Participant participant2(mediator);
    Participant participant3(mediator);

    participant1.say(10);
    participant2.say(20);
    participant3.say(5);

    return 0;
}
