#include "multiton.hpp"

class Threads
{
private:
    static int instanceCount;
public:
    Threads()
    {
        //Note: Avoid incrementing in prints
        cout << "Total number of instances created : "
        << ++instanceCount
        << endl;
    }
};

int Threads::instanceCount = 0;

int main()
{
    typedef Multiton<Threads, Priority> mt;

    auto HP = mt::get(Priority::High);
    auto MP = mt::get(Priority::Medium);
    auto MP2 = mt::get(Priority::Medium);

    // Note: MP and MP2 address are the same here
    cout << "High Priority at " << HP << endl;
    cout << "Medium Priority at " << MP << endl;
    cout << "Medium Priority 2 at " << MP2 << endl;
    
    return 0;
}