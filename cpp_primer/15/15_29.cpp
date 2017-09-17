#include<iostream>
#include<string>
#include<vector>
#include<memory>

using std::cin; using std::cout; using std::endl;
using std::string;

class Quote {
    friend bool operator!=(const Quote &lhs, const Quote &rhs) {
        return lhs.bookNo != rhs.bookNo && lhs.price != rhs.price;
    }
public:
    Quote() { 
        //cout << "Quote: default constructing" << endl; 
    }
    Quote(const string &book, double sales_price) :
        bookNo(book), price(sales_price) {
            //cout << "Quote: constructor taking 2 parameters" << endl;
        }
    // copy constructor
    Quote(const Quote &q) : bookNo(q.bookNo), price(q.price) {
        //cout << "Quote: copy constructing" << endl;
    }
    // move constructor
    Quote(Quote &&q) noexcept : bookNo(std::move(q.bookNo)), price(std::move(q.price)) {
        //cout << "Quote: move constructing" << endl;
    }
    // copy =
    Quote& operator=(const Quote &rhs) {
        if (*this != rhs) {
            bookNo = rhs.bookNo;
            price = rhs.price;
        }
        //cout << "Quote: copy =()" << endl;
        return *this;
    }
    // move =
    Quote& operator=(Quote &&rhs) noexcept {
        if (*this != rhs) {
            bookNo = std::move(rhs.bookNo);
            price = std::move(rhs.price);
        }
        //cout << "Quote: move =()" << endl;
        return *this;
    }
    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() {
        //cout << "Quote: destructing" << endl;
    }   
protected:
    double price = 0.0;
private:
    string bookNo;
};

class Bulk_quote : public Quote {
    // ?
    friend bool operator!=(const Bulk_quote &lhs, const Bulk_quote &rhs) {
        return lhs.min_qty != rhs.min_qty && lhs.discount != rhs.discount;
    }
public:
    Bulk_quote() {
        //cout << "Bulk_quote: default constucting" << endl;
    }
    Bulk_quote(const string &book, double sales_price, size_t qty, double disc) :
        Quote(book, sales_price), min_qty(qty), discount(disc) {
            //cout << "Bulk_quote: constructor taking 4 parameters" << endl;
        }
    // copy constructor
    Bulk_quote(const Bulk_quote &bq) : Quote(bq), min_qty(bq.min_qty), discount(bq.discount) {
        //cout << "Bulk_quote: copy constructing" << endl;
    }
    // move constructor
    Bulk_quote(Bulk_quote &&bq) noexcept : Quote(bq), min_qty(std::move(bq.min_qty)), discount(std::move(bq.discount)) {
        //cout << "Bulk_quote: move constructing" << endl;
    }
    // copy =
    Bulk_quote& operator=(const Bulk_quote &rhs) {
        if (*this != rhs) {
            Quote::operator=(rhs);
            min_qty = rhs.min_qty;
            discount = rhs.discount;
        }
        //cout << "Bulk_quote: copy =()" << endl;
        return *this;
    }
    // move =
    Bulk_quote& operator=(Bulk_quote &&rhs) noexcept {
        if (*this != rhs) {
            Quote::operator=(rhs);
            min_qty = std::move(rhs.min_qty);
            discount = std::move(rhs.discount);
        }
        //cout << "Bulk_quote: move =()" << endl;
        return *this;
    }
    double net_price(size_t) const override;
    ~Bulk_quote() override {
        //cout << "Bulk_quote: destructing" << endl;
    }
private:
    size_t min_qty = 0;
    double discount = 0.0;
};

double Bulk_quote::net_price(size_t cnt) const {
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else
        return cnt * price;
}

int main() {
    std::vector<Quote> v;
    for (unsigned i = 1; i != 10; i++)
        v.push_back(Bulk_quote("abc", i * 10.0, 10, 0.3));
    double total = 0;
    for (const auto &i : v)
        total += i.net_price(20);
    cout << total << endl;
    std::vector<std::shared_ptr<Quote>> pv;
    for (unsigned i = 1; i != 10; i++)
        pv.push_back(std::make_shared<Bulk_quote>(Bulk_quote("abc", i * 10.0, 10, 0.3)));
    double p_total = 0;
    for (auto p : pv)
        p_total += p->net_price(20);
    cout << p_total << endl;
    return 0;
}