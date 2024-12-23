#include <iostream>
#include <string>

std::string toBinary(int number, int bits) {
    if (number < 0) {
        number = (1 << bits) + number; 
    }

    std::string binary;
    while (number > 0) {
        binary = (number % 2 ? '1' : '0') + binary;
        number /= 2;
    }

    while (binary.size() < bits) {
        binary = '0' + binary;
    }

    return binary.empty() ? "0" : binary;
}

std::string addBinary(const std::string &a, const std::string &b) {
    std::string result;
    int carry = 0;
    int maxLength = a.size() > b.size() ? a.size() : b.size();

    for (int i = 0; i < maxLength; ++i) {
        int bitA = (i < a.size()) ? (a[a.size() - 1 - i] - '0') : 0;
        int bitB = (i < b.size()) ? (b[b.size() - 1 - i] - '0') : 0;

        int sum = bitA + bitB + carry;
        result = (sum % 2 ? '1' : '0') + result;
        carry = sum / 2;
    }

    if (carry) {
        result = '1' + result;
    }

    if (result.size() > maxLength) {
        result = result.substr(1);
    }

    return result;
}

int main() {
    int num1, num2;

    std::cout << "Введите первое число в десятичной форме: ";
    std::cin >> num1;
    std::cout << "Введите второе число в десятичной форме: ";
    std::cin >> num2;

    int bits = 8; 

    std::string binary1 = toBinary(num1, bits);
    std::string binary2 = toBinary(num2, bits);

    std::string sum = addBinary(binary1, binary2);

    std::cout << "Результат в дополнительном коде: " << sum << std::endl;

    return 0;
}