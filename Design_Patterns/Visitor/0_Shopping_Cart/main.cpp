#include <iostream>
#include <vector>

class DiscountVisitor;
class TaxVisitor;
class ReceiptPrinterVisitor;

// Base Element class (Product)
class Item {
public:
    double price;   // without tax and discounts
    double final_price;  // after applying discount and tax

    Item(double p) : price(p), final_price(p) {}

    // Accept method (Element interface), allows a visitor to visit the element
    virtual void accept(DiscountVisitor& visitor) = 0;
    virtual void accept(TaxVisitor& visitor) = 0;
    virtual void accept(ReceiptPrinterVisitor& visitor) = 0;

    virtual ~Item() = default;
};

class Book : public Item {
public:
    Book(double p) : Item(p) {}
    void accept(DiscountVisitor& visitor) override;
    void accept(TaxVisitor& visitor) override;
    void accept(ReceiptPrinterVisitor& visitor) override;
};

class Clothing : public Item {
public:
    Clothing(double p) : Item(p) {}
    void accept(DiscountVisitor& visitor) override;
    void accept(TaxVisitor& visitor) override;
    void accept(ReceiptPrinterVisitor& visitor) override;
};

class Electronic : public Item {
public:
    Electronic(double p) : Item(p) {}
    void accept(DiscountVisitor& visitor) override;
    void accept(TaxVisitor& visitor) override;
    void accept(ReceiptPrinterVisitor& visitor) override;
};

// Visitor interface (Base visitor)
class Visitor {
public:
    virtual ~Visitor() = default;
    virtual void visit(Book& book) = 0;
    virtual void visit(Clothing& clothing) = 0;
    virtual void visit(Electronic& electronic) = 0;
};

// Concrete Visitor classes (Operations: Discount, Tax, Receipt)
class DiscountVisitor : public Visitor {
public:
    void visit(Book& book) override {
        book.final_price = book.price * 0.85;
        std::cout << "Discounted price for Book: " << book.final_price << std::endl;
    }
    void visit(Clothing& clothing) override {
        clothing.final_price = clothing.price * 0.8;
        std::cout << "Discounted price for Clothing: " << clothing.final_price << std::endl;
    }
    void visit(Electronic& electronic) override {
        electronic.final_price = electronic.price * 0.88;
        std::cout << "Discounted price for Electronic: " << electronic.final_price << std::endl;
    }
};

class TaxVisitor : public Visitor {
public:
    void visit(Book& book) override {
        book.final_price += book.price * 0.1;
        std::cout << "Tax for Book: " << book.price * 0.1 << std::endl;
    }
    void visit(Clothing& clothing) override {
        clothing.final_price += clothing.price * 0.08;
        std::cout << "Tax for Clothing: " << clothing.price * 0.08 << std::endl;
    }
    void visit(Electronic& electronic) override {
        electronic.final_price += electronic.price * 0.15;
        std::cout << "Tax for Electronic: " << electronic.price * 0.15 << std::endl;
    }
};

class ReceiptPrinterVisitor : public Visitor {
public:
    void visit(Book& book) override {
        std::cout << "Item: Book" << std::endl;
        std::cout << "Original Price: " << book.price << std::endl;
        std::cout << "Final price: " << book.final_price << std::endl;
    }
    void visit(Clothing& clothing) override {
        std::cout << "Item: Clothing" << std::endl;
        std::cout << "Original Price: " << clothing.price << std::endl;
        std::cout << "Final price: " << clothing.final_price << std::endl;
    }
    void visit(Electronic& electronic) override {
        std::cout << "Item: Electronic" << std::endl;
        std::cout << "Original Price: " << electronic.price << std::endl;
        std::cout << "Final price: " << electronic.final_price << std::endl;
    }
};

// Implementing accept methods (Double Dispatch)
void Book::accept(DiscountVisitor& visitor) { visitor.visit(*this); }
void Book::accept(TaxVisitor& visitor) { visitor.visit(*this); }
void Book::accept(ReceiptPrinterVisitor& visitor) { visitor.visit(*this); }

void Clothing::accept(DiscountVisitor& visitor) { visitor.visit(*this); }
void Clothing::accept(TaxVisitor& visitor) { visitor.visit(*this); }
void Clothing::accept(ReceiptPrinterVisitor& visitor) { visitor.visit(*this); }

void Electronic::accept(DiscountVisitor& visitor) { visitor.visit(*this); }
void Electronic::accept(TaxVisitor& visitor) { visitor.visit(*this); }
void Electronic::accept(ReceiptPrinterVisitor& visitor) { visitor.visit(*this); }

void process_order(Item& item, DiscountVisitor& discountVisitor, TaxVisitor& taxVisitor, ReceiptPrinterVisitor& receiptVisitor){
    item.accept(discountVisitor);  // Apply discount
    item.accept(taxVisitor);       // Calculate tax
    item.accept(receiptVisitor);   // Print receipt
}

int main() {
    // Creating some items in the cart
    std::vector<std::shared_ptr<Item>> cart;
    cart.push_back(std::make_shared<Book>(50.0));
    cart.push_back(std::make_shared<Clothing>(30.0));
    cart.push_back(std::make_shared<Electronic>(200.0));

    // Create the visitors
    DiscountVisitor discountVisitor;
    TaxVisitor taxVisitor;
    ReceiptPrinterVisitor receiptVisitor;

    // Accept the visitors to perform the operations
    for (auto& item : cart) {
        process_order(*item, discountVisitor, taxVisitor, receiptVisitor);
    }

    return 0;
}
