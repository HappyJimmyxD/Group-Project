#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<User> users;
bool isDataLoaded = false;

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

// R1
void loadStartingData(vector<User>& users) {
    users = {
        {"SkyWalker", 'T', 20, 'N'},
        {"Ocean123", 'T', 35, 'N'},
        {"Forest99", 'T', 6, 'Y'},
        {"Valley777", 'F', 10, 'Y'},
        {"Desert2022", 'F', 25, 'N'},
        {"River456", 'F', 20, 'Y'},
        {"Blaze2023", 'F', 100, 'N'},
        {"Meadow888", 'S', 40, 'Y'},
        {"Galaxy", 'S', 15, 'N'},
        {"Storm2024", 'S', 30, 'N'}
    };
    cout << "Starting data loaded successfully.\n";
}
// R2
void showUserRecords() {
    if(!isDataLoaded) {
        cout << " Error! Please load the data first!\n";
        return;
    }
    sort(users.begin(), users.end(), [](User a, User b) { return a.userID < b.userID; });
    cout << "User Records: \n";
    
    cout << "ID: " << user.userID << ", Type: " << user.type 
    << ", Token Balance: " << user.tokenBalance 
    << ", Auto Top-Up: " << user.autoTopUp << "\n";
}
// R3
void editUser() {

}
// R4
void enterUserView() {
    
}
// R5
void showSystemUsageSummary() {

}
// R6
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
        case 2: showUserRecords();
        case 3: editUser();
        case 4: enterUserView();
        case 5: showSystemUsageSummary();
        case 6: CreditsAndExit();
        default: displayInvalidMessage();
        }
    } while (option != 6);
}
