#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed for the random number generator
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    int secretNumber = std::rand() % 100 + 1;

    int userGuess;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "Can you guess the number between 1 and 100?\n";

    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        // Check if the guess is too high, too low, or correct
        if (userGuess > secretNumber) {
            std::cout << "Too high! Try again.\n";
        } else if (userGuess < secretNumber) {
            std::cout << "Too low! Try again.\n";
        }

        attempts++;

    } while (userGuess != secretNumber);

    std::cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts.\n";

    return 0;
}

