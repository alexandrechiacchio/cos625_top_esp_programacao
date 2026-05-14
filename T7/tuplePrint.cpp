#include <initializer_list>
#include <iostream>
#include <memory>
#include <string>

class AbstractPair {
    
    public:
    AbstractPair() {}
    virtual ~AbstractPair() = default;
    virtual void print(std::ostream& o) const = 0;
};

template<typename A, typename B>
class PairTemplate : public AbstractPair {
    A a;
    B b;
    public:
    PairTemplate(A _a, B _b) : a(_a), b(_b) {}
    
    void print(std::ostream& o) const {
        o << a << " = " << b << std::endl;
    }
};

class Pair {
    std::shared_ptr<AbstractPair> p;
public:
    template <typename A, typename B>
    Pair(A a, B b) : p(std::make_shared<PairTemplate<A, B>>(a, b)) {}

    Pair(Pair const &pair) {

    }

    const Pair& operator=(const Pair u){
        this->p->a = u->p->a;
        return *this;
    }



    void print(std::ostream& o) const {
        p->print(o);
    }


};

void print(std::ostream& o, std::initializer_list<Pair> arr) {
    for (auto it = arr.begin(); it != arr.end(); it++) {
        it->print(o);
    }
    
}

int main() {
    
    Pair p("1", 2);
    
    print( std::cout, { { "jan", 1 }, { 2, "fev" }, { std::string( "pi" ), 3.14 } } );

    return 0;
}