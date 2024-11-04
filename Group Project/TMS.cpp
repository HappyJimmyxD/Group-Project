#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

vector<User> users;
bool isdataLoaded = false;

struct User {
    int userID;
    char type;
    int tokenBalance;
    char tokenBalanceStatus;
};

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
void loadStartingData() {
users = {
        {"SkyWalker", 'T', 20, 'N'},
        {"Ocean123", 'T', 35, 'N'},
        {"Forest99", 'T', 6, 'Y'},
        {"Valley777", 'F', 10, 'Y'},
        {"Desert2022", 'F', 25, 'N'},
        {"River456", 'F', 20, 'Y'},
        {"Blaze2003", 'F', 100, 'N'},
        {"Meadow888", 'S', 40, 'Y'},
        {"Galaxy", 'S', 15, 'Y'},
        {"Storm2024", 'S', 30, 'N'}
    };
    isdataLoaded = true; 
    cout << "Starting data loaded successfully!\n";
}
void CreditsAndExit() {

}

int main() {
    displayWelcomeMessage();
    int option;

    do {
        displayMainMenu();
        cin >> option;

        switch (option) {
        case 1: loadStartingData();
        case 2:
        case 3:
        case 4:
        case 5:
        case 6: CreditsAndExit();
        default: displayInvalidMessage();
        }
    } while (option != 6);
}
