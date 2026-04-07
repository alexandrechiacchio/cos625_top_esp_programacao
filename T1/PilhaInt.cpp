#include <iostream>
#include <sstream>

class PilhaInt {
  int *stack = new int[0];
  size_t size = 0;
  size_t capacity = 0;
public:
    PilhaInt(){};
    ~PilhaInt(){};

    void empilha(int u) {
        if(size + 1 > capacity){
          if(capacity) capacity <<= 1;
          else capacity++;
        }
        int* newArr = new int[capacity];
        for(size_t pos = 0; pos<size; pos++){
          newArr[pos] = stack[pos];
        }
        delete[] stack; stack = newArr;
        stack[size] = u;
        size++;
    }

    int desempilha() {
        return stack[--size];
    }

    void print(std::ostream& o) {
      o << "[ ";
        for(size_t pos = 0; pos < size-1; pos++) o << stack[pos] << ", ";
      o << stack[size-1] << " ]";
    }

    PilhaInt& operator<<(int u) {
        empilha(u);
        return *this;
    }

    PilhaInt& operator=(PilhaInt u){
      this->size = u.size;
      this->capacity = u.capacity;
      delete[] this->stack;
      stack = new int[capacity];
      for (size_t pos = 0; pos<capacity; pos++) stack[pos] = u.stack[pos];
      return *this;
    }
};
using namespace std;

int main() {

PilhaInt p, q;
q << 2;
p << 19 << 18 << 17 << 30;
q = p;
p.desempilha();
q << 7;
stringstream ssp, ssq;
p.print( ssp );
q.print( ssq );

cout << "q = " << ssq.str() << "\n" << "p = " << ssp.str() << endl;

// Essa linha é apenas para gerar um erro se o "operator=" não for definido. Ignore-a!
auto l = &PilhaInt::operator=; (p.*l)(q);

    return 0;
}
