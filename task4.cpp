#include <iostream>

bool isDivisible(int number, int prime) { 
    int remainder = number;
    while (remainder >= prime) {
        remainder += (~prime + 1);
    }
    return remainder == 0;
}

int main() {
    int number;
    std::cout << "Введите число: ";
    std::cin >> number;

    int primes[] = {5, 29, 223};

    for (int prime : primes) {
        if (isDivisible(number, prime)) {
            std::cout << "Число " << number << " делится на " << prime << '\n';
        } else {
            std::cout << "Число " << number << " не делится на " << prime << '\n';
        }
    }

    return 0;
}