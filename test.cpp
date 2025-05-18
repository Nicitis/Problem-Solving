#include <iostream>

const int global_const = 123;
int global_var = 456;

int main() {
    const int local_const = 789;
    // std::cout << "&global_const: " << (void*)&global_const << "\n";
    std::cout << "&global_var: " << (void*)&global_var << "\n";
    std::cout << "&local_const: " << (void*)&local_const << "\n";
}