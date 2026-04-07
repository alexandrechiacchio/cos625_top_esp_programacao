#include <iostream>
#include <sstream>

class PilhaInt {
    int* stack;
    int size = 0;
    int capacity = 0;
public:
    PilhaInt(int _capacity = 10) : capacity(_capacity) {
        stack = (int*)malloc(capacity * sizeof(int));
        for (int pos = 0; pos < capacity; pos++) stack[pos] = 0;
    };

    PilhaInt(PilhaInt& other) : size(other.size), capacity(other.capacity) {
        stack = (int*)malloc(capacity * sizeof(int));
        for (int i = 0; i < capacity; i++) stack[i] = other.stack[i];
    }


    ~PilhaInt() {
        free(stack);
    };

    void empilha(int u) {
        if (size + 1 > capacity) {
            if (capacity) capacity <<= 1;
            else capacity++;
        }
        int* newArr = (int*)realloc(stack, sizeof(int) * (size + 1));
        if (newArr == nullptr) throw std::bad_alloc();
        stack = newArr;
        stack[size] = u;
        size++;
    }

    int desempilha() {
        return stack[--size];
    }

    int capacidade() {
        return capacity;
    }

    void redimensiona(int newSize) {
        void* reallocPtrRet = realloc(stack, newSize * sizeof(int));
        if (reallocPtrRet == nullptr) throw std::bad_alloc();
        stack = (int*)reallocPtrRet;
        capacity = newSize;
        if(newSize<size) size = newSize;
    }

    void print(std::ostream& o) {
        o << "[ ";
        for (int pos = 0; pos < size - 1; pos++) o << stack[pos] << ", ";
        o << stack[size - 1] << " ]";
    }

    PilhaInt& operator<<(int u) {
        empilha(u);
        return *this;
    }

    PilhaInt& operator=(PilhaInt u) {
        size = u.size;
        capacity = u.capacity;
        void* newArr = realloc(stack, capacity * sizeof(int));
        if (newArr) stack = (int*)newArr;
        for (int pos = 0; pos < capacity; pos++) stack[pos] = u.stack[pos];
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
