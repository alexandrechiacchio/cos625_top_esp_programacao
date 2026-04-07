#include <iostream>
#include <sstream>
#include <vector>

class PilhaInt {
    std::vector<int> stack;
public:
    PilhaInt(size_t size) {
        stack.resize(size);
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

    void redimensiona(int newSize) {
        stack.resize(newSize);
    }

    void print(std::ostream& o) {
        o << "[ ";
        for (auto it : stack)
            if(&it != &stack.back()) o << it << ", ";
            else o << it;
        o << " ]";
    }

    PilhaInt& operator<<(int u) {
        empilha(u);
        return *this;
    }

    PilhaInt& operator=(PilhaInt u) {
        stack = u.stack;
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

    PilhaInt a{ 81 };
    a << 5 << 6 << 3 << 2 << 9 << 13;
    a.redimensiona(81); cout << a.capacidade() << endl;
    a.redimensiona(11); cout << a.capacidade() << endl;
    a.redimensiona(6); cout << a.capacidade() << endl;
    a.print(cout); cout << endl;
    a.redimensiona(3); cout << a.capacidade() << endl;
    a.print(cout); cout << endl;

    return 0;
}
