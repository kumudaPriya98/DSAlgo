#include <iostream>

using namespace std;

double power(double base, int exp) {
    if(exp == 0) return 1;
    else if(exp < 0) return 1/base * power(1/base, -(exp + 1));

    double result = power(base, exp/2);
    return (exp%2) ? result * result * base : result * result;
}

double powerIterative(double base, int exp) {
    if(exp == 0) return 1;
    else if(exp < 0) return 1/base * power(1/base, -(exp + 1));

    double remainder = 1;
    while(exp > 1) {
        remainder = exp % 2 ? base * remainder : remainder; 
        base = base * base;
        exp /= 2;
    }

    return base * remainder;
}