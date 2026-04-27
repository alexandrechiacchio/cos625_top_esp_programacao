#include <vector>
#include <initializer_list>

template<int n, typename T>
class Vetor;

template<int n, typename T>
class ProdutoVetorIntermediario {
public:
    std::vector<T> arr;
    ProdutoVetorIntermediario(const Vetor<n, T>& v);  // declared, not defined
};

template<int n, typename T>
class Vetor {
public:
    std::vector<T> arr;
    Vetor() {
        arr.resize(n);
    }

    Vetor(const std::initializer_list<T> list) : arr(list) {
    }

    Vetor(const Vetor& v) : arr(v.arr) {
    }

    Vetor(const Vetor&& v) : arr(std::move(v.arr)) {
    }

    const Vetor& operator= (const Vetor& v) {
        arr = v.arr;
        return *this;
    }

    const Vetor& operator= (Vetor&& v) {
        arr = v.arr;
        v.arr.clear();
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const Vetor& v) {
        out << '{';
        for (auto it = v.arr.begin(); it != v.arr.end(); it++) {
            out << *it;
            if (it != v.arr.end() - 1) out << ", ";
        }
        out << '}';
        return out;
    }

    Vetor operator+(const Vetor& v) {
        Vetor<n, T> r;
        for (int i = 0; i < n; i++) {
            r.arr[i] = arr[i] + v.arr[i];
        }
        return r;
    }

    T operator*(const Vetor& v) {
        T r = 0.0;
        for (int i = 0; i < n; i++) {
            r += arr[i] * v.arr[i];
        }
        return r;
    }

    Vetor operator*(T m) {
        Vetor<n, T> r(*this);
        for (int i = 0; i < n; i++) {
            r.arr[i] *= m;
        }
        return r;
    }

    friend Vetor operator*(const T m, const Vetor& v) {
        Vetor<n, T> r(v);
        for (int i = 0; i < n; i++) {
            r.arr[i] *= m;
        }
        return r;
    }

    ProdutoVetorIntermediario<n, T> operator* () {
        return ProdutoVetorIntermediario<n, T>(*this);
    }

    Vetor operator*(const ProdutoVetorIntermediario<n, T> p) {
        Vetor<3, T> r;
        r.arr[0] = arr[1] * p.arr[2] - arr[2] * p.arr[1];
        r.arr[1] = arr[2] * p.arr[0] - arr[0] * p.arr[2];
        r.arr[2] = arr[0] * p.arr[1] - arr[1] * p.arr[0];

        return r;
    }

    // const Vetor& operator* (const Vetor& v){

    // }
};


template<int n, typename T>
ProdutoVetorIntermediario<n, T>::ProdutoVetorIntermediario(const Vetor<n, T>& v) : arr(v.arr) {}
