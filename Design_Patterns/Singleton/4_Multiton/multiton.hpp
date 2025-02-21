#include <iostream>
#include <memory>
#include <map>
using namespace std;

// Range of values allowed in multiton
// can be string, enum, integers, ...
enum class Priority
{
    High,
    Medium,
    Low
};

template <typename T, typename Key = std::string>
class Multiton
{
private:
    static map<Key, shared_ptr<T>> instances;

protected:
    Multiton() = default;
    virtual ~Multiton() = default;
    Multiton(const Multiton&) = delete;
    Multiton& operator=(const Multiton&) = delete;

public:
    static shared_ptr<T> get(const Key& key)
    {
        const auto it = instances.find(key);
        if(it != instances.end())
        {
            return it->second;
        }

        // Create instance if not found
        auto instance = make_shared<T>();
        instances[key] = instance;
        return instance;
    }
};

template <typename T, typename Key>
map<Key, shared_ptr<T>> Multiton<T, Key>::instances;
