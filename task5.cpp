#include <iostream>
#include <string>

std::string convertToBase(long long number, unsigned int base) {
    const char* DIGITS = "0123456789abcdefghijklmnopqrstuvwxyz";
    std::string result;

    do {
        result += DIGITS[number % base];
        number /= base;
    } while (number > 0);

    std::string reversedResult;
    for (int i = result.length() - 1; i >= 0; --i) {
        reversedResult += result[i];
    }

    return reversedResult;
}

void padWithZeros(std::string& numberStr) {
    while (numberStr.length() < 5) {
        numberStr.insert(0, "0");
    }
}

int getInput() {
    std::string input;
    int number;

    while (true) {
        std::cout << "Введите номер отравленной бочки (1-240): ";
        std::getline(std::cin, input); 
        
        bool isNumber = true;
        number = 0; 

        for (char c : input) {
            if (!isdigit(c)) {
                isNumber = false;
                break;
            }
        }
        
        if (isNumber) {
            for (char c : input) {
                number = number * 10 + (c - '0');
            }

            if (number > 0 && number <= 240) {
                return number; 
            }
        }

        std::cout << "Некорректный ввод, введите число от 1 до 240.\n";
    }
}

int main() {
    std::string result = "qqqqq";
    int poisonedBarrel, dead[5] = {0};

    poisonedBarrel = getInput();

    for (int i = 1; i < 241; i++) {
        std::string k = convertToBase(i, 3);
        padWithZeros(k);

        for (int j = 0; j < 5; j++) {
            if (k[j] == '1' && i == poisonedBarrel) {
                result[j] = '1';
                dead[j] = 1;
            } else if (k[j] == '2' && i == poisonedBarrel && dead[j] != 1) {
                result[j] = '2';
            }
        }
    }

    for (char& c : result) {
        if (c == 'q') c = '0';
    }

    std::cout << result << "\n";

    int decimalResult = (result[0] - '0') * 81 + (result[1] - '0') * 27 +
                        (result[2] - '0') * 9 + (result[3] - '0') * 3 + 
                        (result[4] - '0');

    std::cout << "Отравленная бочка: " << decimalResult << "\n";

    return 0;
}