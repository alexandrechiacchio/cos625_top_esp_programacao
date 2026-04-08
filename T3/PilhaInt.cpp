#include <iostream>
#include <sstream>
#include <vector>

class PilhaInt {
    std::vector<int> stack;
public:
    PilhaInt() {};

    PilhaInt(size_t size) {
        stack.reserve(size);
    };

    PilhaInt(PilhaInt& other) {
        stack = other.stack;
    }


    ~PilhaInt() {};

    void empilha(int u) {
        stack.push_back(u);
    }

    int desempilha() {
        int ret = stack.back();
        stack.pop_back();
        return ret;
    }

    int capacidade() {
        return stack.capacity();
    }

    void redimensiona(size_t newSize) {
        if (newSize < stack.capacity()){
            if(newSize < stack.size()) stack.resize(newSize);
            std::vector<int>(stack).swap(stack);
        }
        stack.reserve(newSize);
    }

    void print(std::ostream& o) {
        o << "[ ";
        for (auto it = stack.begin(); it != stack.end(); it++) {
            if (it != stack.end() - 1) o << *it << ", ";
            else o << *it;
        }
        o << " ]";
    }

    PilhaInt& operator<<(int u) {
        empilha(u);
        return *this;
    }

    PilhaInt& operator=(const PilhaInt& u) {
        stack = std::vector<int>(u.stack);
        stack.reserve(u.stack.capacity());
        return *this;
    }
};
using namespace std;

PilhaInt embaralha(PilhaInt q) {
    int aux = q.desempilha();
    q << 32 << 9 << aux;

    return q;
}

int main() {

    PilhaInt a{ 7 }, b{ 5000 }, c{ 5 };
    a << 8 << 3 << 1 << 4 << 5;
    for (int i = 0; i < 5000; i++)
        b << i;
    c = a;
    a = b;
    b = c;
    cout << a.capacidade() << ", " << b.capacidade() << ", " << c.capacidade() << endl;

    return 0;
}
