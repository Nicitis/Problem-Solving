#include <iostream>
#include <cmath>

int main()
{
    int a, b, v;
    
    std::cin >> a >> b >> v;
    
    int n = (int)ceil((double)(v-b)/(double)(a - b));
    
    std::cout << n;

    return 0;
}