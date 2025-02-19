#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <vector>
using namespace std;

// should be a file with alternating string and int lines
class SingletonDatabase
{
    map<string, int> books;

    // Full path to bypass VSCode quirk (bad config?) of wrong cwd at runtime
    // string file = "G:\\Mon Drive\\Upskilling_2024\\Design_Patterns\\Singleton\\Singleton_Database\\books_stock.txt";
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

    int get_stock(string& name)
    {
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
            result += SingletonDatabase::get().get_stock(name);
        }
        return result;
    }
};
