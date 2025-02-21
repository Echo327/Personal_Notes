#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <vector>
using namespace std;

// Note: To Make Dummy Database
class Database
{
public:
    virtual int get_stock(const string& name) = 0;
};


// should be a file with alternating string and int lines
class SingletonDatabase : public Database
{
    map<string, int> books;

    string file = "books_stock.txt";

    SingletonDatabase(){
        cout << "Initializing Database" << endl;
        ifstream ifs(file);

        if (!ifs) {  // Check if the file opened successfully
            throw std::runtime_error("Failed to open file: " + file);
        }

        string tmp, tmp2;
        while(getline(ifs, tmp)){
            getline(ifs, tmp2);
            books[tmp] = std::stoi(tmp2);
        }
    }

public:
    // Ensures no one can replicate the database
    SingletonDatabase(SingletonDatabase const&) = delete;
    void operator=(SingletonDatabase const&) = delete;

    void print_database(){
        cout << "This is the whole library:" << endl;
        for (auto iter = books.begin(); iter != books.end(); iter++){
            cout << iter->first << ": " << iter->second << endl;
        }
    }

    static SingletonDatabase& get()
    {
        static SingletonDatabase db;
        return db;
    }

    int get_stock(const string& name) override
    {
        return books[name];
    }
};

class DummyDatabase : public Database
{
    map<string, int> books;
public:
    // Full control of dummy data for unit tests
    DummyDatabase(){
        books["astro"] = 1;
        books["bully"] = 2;
        books["coin"] = 3;
    }

    int get_stock(const string& name) override {
        return books[name];
    }
};

struct SingletonRecordFinder
{
    int total_stock(vector<string> names)
    {
        int result{0};
        for (auto& name : names)
        {
            // Dependecy Injection here (instead of SingletonDatabase::get())
            // Point of insertion for dependency instead of actual object
            result += SingletonDatabase::get().get_stock(name);
        }
        return result;
    }
};

struct ConfigurableRecordFinder
{
    Database& db;

    ConfigurableRecordFinder(Database& db) : db(db){}
    
    int total_stock(vector<string> names)
    {
        int result{0};
        for (auto& name : names)
        {
            // Dependecy Injection here (instead of SingletonDatabase::get())
            result += db.get_stock(name);
        }
        return result;
    }
};
