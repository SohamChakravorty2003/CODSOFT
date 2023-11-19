#include <iostream>

int main() {
    double num1, num2, result;
    char operation;

    std::cout << "Welcome to the Basic Calculator!\n";

    // Input the first number
    std::cout << "Enter the first number: ";
    std::cin >> num1;

    // Input the second number
    std::cout << "Enter the second number: ";
    std::cin >> num2;

    // Choose the operation
    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;

    // Perform the chosen operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            std::cout << "Result: " << num1 << " + " << num2 << " = " << result << "\n";
            break;
        case '-':
            result = num1 - num2;
            std::cout << "Result: " << num1 << " - " << num2 << " = " << result << "\n";
            break;
        case '*':
            result = num1 * num2;
            std::cout << "Result: " << num1 << " * " << num2 << " = " << result << "\n";
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                std::cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n";
            } else {
                std::cout << "Error! Division by zero is not allowed.\n";
            }
            break;
        default:
            std::cout << "Invalid operation. Please choose +, -, *, or /.\n";
            break;
    }

    return 0;
}

