#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void displayMainMenu() {
    cout << "\n*** Main Menu ***\n";
    cout << "[1] Load Starting Data\n";
    cout << "[2] Show User Records\n";
    cout << "[3] Edit Users\n";
    cout << "[4] Enter User View\n";
    cout << "[5] Show System Usage Summary\n";
    cout << "[6] Credits and Exit\n";
    cout << "*****************\n";
    cout << "Option (1 - 6): ";
}

void displayWelcomeMessage() {
    cout << "Welcome to the Program!\n";
}

void displayInvalidMessage() {
    cout << "Invalid option. Please choose a valid option.\n";
}

void CreditsAndExit() {

}

int main() {
    displayWelcomeMessage();
    int option;

12312
    do {
        displayMainMenu();
        cin >> option;

        switch (option) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6: CreditsAndExit();
        default: displayInvalidMessage();
        }
    } while (option != 6);
}
