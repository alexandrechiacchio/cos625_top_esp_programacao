#include "stream.cpp"
#include <iostream>
#include <vector>


int main() {

    std::vector<int> v1 = { 2, 9, 8, 8, 7, 4 };
    auto result = v1 | [](int x) { return x % 2 == 0; };
    for (auto x : result)
        std::cout << x << " ";

    return 0;
}