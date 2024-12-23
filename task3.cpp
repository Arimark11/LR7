#include <iostream>
#include <string>

bool isValidCharacter(char c, int base) {
    if (c >= '0' && c <= '9') {
        return c - '0' < base;
    }
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10 < base;
    }
    return false;
}

int charToValue(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return c - 'A' + 10;
}

char valueToChar(int value) {
    if (value < 10) {
        return '0' + value;
    }
    return 'A' + (value - 10);
}

std::string addNumbers(const std::string &num1, const std::string &num2, int base) {
    std::string result;
    int carry = 0;
    int maxLength = (num1.length() > num2.length()) ? num1.length() : num2.length();

    for (int i = 0; i < maxLength || carry; ++i) {
        int digit1 = (i < num1.length()) ? charToValue(num1[num1.length() - 1 - i]) : 0;
        int digit2 = (i < num2.length()) ? charToValue(num2[num2.length() - 1 - i]) : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / base;
        result += valueToChar(sum % base);
    }

    std::string reversedResult;
    for (int j = result.length() - 1; j >= 0; --j) {
        reversedResult += result[j];
    }

    return reversedResult;
}

std::string subtractNumbers(const std::string &num1, const std::string &num2, int base) {
    std::string result;
    int borrow = 0;

    for (int i = 0; i < num1.length(); ++i) {
        int digit1 = charToValue(num1[num1.length() - 1 - i]);
        int digit2 = (i < num2.length()) ? charToValue(num2[num2.length() - 1 - i]) : 0;

        digit1 -= borrow;
        if (digit1 < digit2) {
            digit1 += base;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result += valueToChar(digit1 - digit2);
    }

    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }

    std::string reversedResult;
    for (int j = result.length() - 1; j >= 0; --j) {
        reversedResult += result[j];
    }

    return reversedResult.empty() ? "0" : reversedResult;
}

int main() {
    int base;
    std::string num1, num2;
    char operation;

    std::cout << "Введите основание системы счисления (от 2 до 36): ";
    std::cin >> base;

    if (base < 2 || base > 36) {
        std::cout << "Некорректное основание" << std::endl;
        return 1;
    }

    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число: ";
    std::cin >> num2;

    for (char c : num1) {
        if (!isValidCharacter(c, base)) {
            std::cout << "Некорректный символ в первом числе" << std::endl;
            return 1;
        }
    }

    for (char c : num2) {
        if (!isValidCharacter(c, base)) {
            std::cout << "Некорректный символ во втором числе" << std::endl;
            return 1;
        }
    }

    std::cout << "Введите операцию (+ или -): ";
    std::cin >> operation;

    if (operation == '+') {
        std::string sum = addNumbers(num1, num2, base);
        std::cout << "Результат сложения: " << sum << std::endl;
    } else if (operation == '-') {
        std::string difference = subtractNumbers(num1, num2, base);
        std::cout << "Результат вычитания: " << difference << std::endl;
    } else {
        std::cout << "Некорректная операция" << std::endl;
    }

    return 0;
}