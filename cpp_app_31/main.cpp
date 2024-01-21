#include "Traffic.h"
#include <iostream>

int main() {
    Traffic database;

    database.addReceipt(55, "Speeding");
    database.addReceipt(33, "Running a red light");
    database.addReceipt(71, "Illegal parking");
    database.addReceipt(64, "Driving without a seatbelt");
    database.addReceipt(91, "Speeding");
    database.addReceipt(47, "Illegal parking");

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Full database printing\n";
        std::cout << "2. Data on a given number\n";
        std::cout << "3. Data by range of numbers\n";
        std::cout << "4. Add penalty\n";
        std::cout << "5. Delete a receipt\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "\nFull database printing:\n";
            database.printFullDatabase();
            break;
        }
        case 2: {
            int searchNumber;
            std::cout << "Enter the number to search: ";
            std::cin >> searchNumber;
            std::cout << "Data on given number:\n";
            database.printDataForNumber(searchNumber);
            break;
        }
        case 3: {
            int startRange, endRange;
            std::cout << "Enter the start range: ";
            std::cin >> startRange;
            std::cout << "Enter the end range: ";
            std::cin >> endRange;
            std::cout << "Data by range of numbers:\n";
            database.printDataInRange(startRange, endRange);
            break;
        }
        case 4: {
            int receiptNumber;
            std::cout << "Enter the receipt number to add a penalty or create a new receipt: ";
            std::cin >> receiptNumber;
            std::string newPenalty;
            std::cout << "Enter the new penalty: ";
            std::cin.ignore();
            std::getline(std::cin, newPenalty);
            database.addPenalty(receiptNumber, newPenalty);
            break;
        }
        case 5: {
            int deleteNumber;
            std::cout << "Enter the receipt number to delete: ";
            std::cin >> deleteNumber;
            database.deleteReceipt(deleteNumber);
            break;
        }
        case 0: {
            std::cout << "Exiting the program.\n";
            break;
        }
        default: {
            std::cout << "Invalid choice. Please enter a valid option\n";
            break;
        }
        }
    } while (choice != 0);

	return 0;
}
