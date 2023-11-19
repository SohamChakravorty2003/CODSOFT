#include <iostream>
#include <vector>
#include <string>
#include <ctime>

class Book {
public:
    std::string title;
    std::string author;
    std::string ISBN;
    bool available;

    Book(const std::string& t, const std::string& a, const std::string& isbn) : title(t), author(a), ISBN(isbn), available(true) {}
};

class Borrower {
public:
    std::string name;
    int borrowerID;

    Borrower(const std::string& n, int id) : name(n), borrowerID(id) {}
};

class Transaction {
public:
    Book* book;
    Borrower* borrower;
    time_t checkoutDate;
    time_t returnDate;
    bool returned;
    double fine;

    Transaction(Book* b, Borrower* br) : book(b), borrower(br), checkoutDate(time(nullptr)), returnDate(0), returned(false), fine(0.0) {}
};

class Library {
private:
    std::vector<Book> books;
    std::vector<Borrower> borrowers;
    std::vector<Transaction> transactions;

public:
    void addBook() {
        std::string title, author, ISBN;
        std::cout << "Enter book title: ";
        std::getline(std::cin, title);
        std::cout << "Enter author name: ";
        std::getline(std::cin, author);
        std::cout << "Enter ISBN: ";
        std::getline(std::cin, ISBN);

        books.emplace_back(title, author, ISBN);
        std::cout << "Book added to the library: " << title << "\n";
    }

    void addBorrower() {
        std::string name;
        int borrowerID;

        std::cout << "Enter borrower name: ";
        std::getline(std::cin, name);
        std::cout << "Enter borrower ID: ";
        std::cin >> borrowerID;

        borrowers.emplace_back(name, borrowerID);
        std::cout << "Borrower added to the library: " << name << "\n";
    }

    Book* findBook(const std::string& searchCriteria) {
        for (auto& book : books) {
            if (book.title == searchCriteria || book.author == searchCriteria || book.ISBN == searchCriteria) {
                return &book;
            }
        }
        return nullptr;
    }

    Borrower* findBorrower(int borrowerID) {
        for (auto& borrower : borrowers) {
            if (borrower.borrowerID == borrowerID) {
                return &borrower;
            }
        }
        return nullptr;
    }

    void checkoutBook() {
        std::string searchCriteria;
        std::cout << "Enter book title, author, or ISBN to search: ";
        std::getline(std::cin, searchCriteria);

        Book* bookToCheckout = findBook(searchCriteria);
        if (bookToCheckout) {
            int borrowerID;
            std::cout << "Enter borrower ID: ";
            std::cin >> borrowerID;

            Borrower* borrower = findBorrower(borrowerID);
            if (borrower) {
                transactions.emplace_back(bookToCheckout, borrower);
                bookToCheckout->available = false;
                std::cout << "Book checked out successfully.\n";
            } else {
                std::cout << "Borrower not found.\n";
            }
        } else {
            std::cout << "Book not found.\n";
        }
    }

    void returnBook() {
        std::string searchCriteria;
        std::cout << "Enter book title, author, or ISBN to search: ";
        std::getline(std::cin, searchCriteria);

        Book* bookToReturn = findBook(searchCriteria);
        if (bookToReturn) {
            if (!bookToReturn->available) {
                for (auto& transaction : transactions) {
                    if (transaction.book == bookToReturn && !transaction.returned) {
                        transaction.returnDate = time(nullptr);
                        transaction.returned = true;

                        // Calculate fine for overdue books (for simplicity, assume 1 day overdue results in a $1 fine)
                        double daysOverdue = difftime(transaction.returnDate, transaction.checkoutDate) / (60 * 60 * 24);
                        transaction.fine = (daysOverdue > 0) ? daysOverdue : 0;

                        bookToReturn->available = true;
                        std::cout << "Book returned successfully.\n";
                        return;
                    }
                }
                std::cout << "Book not found in transactions.\n";
            } else {
                std::cout << "Book is already available.\n";
            }
        } else {
            std::cout << "Book not found.\n";
        }
    }
};

int main() {
    Library library;
    int choice;

    std::cout << "Welcome to the Library Management System!\n";

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add Book\n";
        std::cout << "2. Add Borrower\n";
        std::cout << "3. Checkout Book\n";
        std::cout << "4. Return Book\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Consume the newline character

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.addBorrower();
                break;
            case 3:
                library.checkoutBook();
                break;
            case 4:
                library.returnBook();
                break;
            case 0:
                std::cout << "Exiting the Library Management System. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}


