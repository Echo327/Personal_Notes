#include "singleton.hpp"

int main()
{
    string book = "Great White";
    int stock = SingletonDatabase::get().get_stock(book);
    cout << "We have " << stock << " " << book << endl;

    SingletonDatabase::get().print_database();

    vector<string> search_terms{"Optiplex","Packard"};
    auto print_vector = [search_terms]{for(auto iter = search_terms.begin(); iter < search_terms.end(); iter++){
        cout << *iter << " ";
        if (iter != (search_terms.end()-1))
            cout << "+ ";
    }};

    auto print_total_stock = [search_terms, print_vector]{
        SingletonRecordFinder rf;
        cout << "Total stock for ";
        print_vector();
        cout << "= " << rf.total_stock(search_terms) << endl;
    };

    print_total_stock();

    return 0;
}
