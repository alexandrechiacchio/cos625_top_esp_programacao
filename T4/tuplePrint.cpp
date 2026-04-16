#include <initializer_list>
#include <iostream>

class AbstractPair {
    
    public:
    AbstractPair() {}
    virtual ~AbstractPair() = default;
    virtual void print(std::ostream& o) = 0;
};

template<typename A, typename B>
class PairTemplate : public AbstractPair {
    A a;
    B b;
    public:
    PairTemplate(A _a, B _b) : a(_a), b(_b) {}
    
    void print(std::ostream& o) {
        o << a << " = " << b << std::endl;
    }
};

class Pair {
public:
    template <typename A, typename B>
    Pair(A a, B b) {
        p = new PairTemplate<A, B>(a, b);
    }
    AbstractPair* p;
};

void print(std::ostream& o, std::initializer_list<Pair> arr) {
    for (auto it = arr.begin(); it != arr.end(); it++) {
        it->p->print(o);
    }
    
}

int main() {
    
    Pair p("1", 2);
    
    print(std::cout, { { "jan", 1 }, { 2, "fev" }, { std::string("pi"), 3.14 } });

    return 0;
}