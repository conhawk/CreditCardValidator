#include <iostream>
#include <string>
#include <algorithm>

bool validateCreditCard(const std::string& cardNumber) {
    // Remove any spaces from the card number
    std::string number = cardNumber;
    number.erase(std::remove(number.begin(), number.end(), ' '), number.end());

    // Check if the card number has a valid length
    if (number.length() < 13 || number.length() > 16) {
        return false;
    }

    // Check if the card number contains only digits
    if (number.find_first_not_of("0123456789") != std::string::npos) {
        return false;
    }

    // Use Luhn algorithm to validate the card number
    int sum = 0;
    bool alternate = false;
    for (int i = number.length() - 1; i >= 0; i--) {
        int digit = number[i] - '0';

        if (alternate) {
            digit *= 2;
            if (digit > 9) {
                digit = (digit % 10) + 1;
            }
        }

        sum += digit;
        alternate = !alternate;
    }

    return (sum % 10) == 0;
}

int main() {
    std::string cardNumber;
    std::cout << "Enter the credit card number: ";
    std::getline(std::cin, cardNumber);

    if (validateCreditCard(cardNumber)) {
        std::cout << "Valid credit card number." << std::endl;
    }
    else {
        std::cout << "Invalid credit card number." << std::endl;4
    }

    return 0;
}
