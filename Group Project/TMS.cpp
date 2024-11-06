#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

struct User {
    string userID;       
    char type{};
    int tokenBalance{};
    char autoTopUp{};
};


vector<User> users;      
bool isDataLoaded = false; 


void displayMainMenu();
void displayWelcomeMessage();
void displayInvalidMessage();
void loadStartingData();
void showUserRecords();
void editUsers();
void enterUserView();
void showSystemUsageSummary();
void CreditsAndExit();


int main() {
    displayWelcomeMessage();
    int option;

    do {
        displayMainMenu();
        cin >> option;

        switch (option) {
        case 1: loadStartingData(); break;
        case 2: showUserRecords(); break;
        case 3: editUsers(); break;
        case 4: enterUserView(); break;
        case 5: showSystemUsageSummary(); break;
        case 6: CreditsAndExit(); return 0;
        default: displayInvalidMessage();
        }
    } while (option != 6);
}

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
void EditProfile(string a) {
    int fail = 0, max = 3;
    char choice;
    string newAccountType;
    char newAutoTopUp;
    string userID;
    userID = a;
    auto it = find_if(users.begin(), users.end(), [&](User& u) { return u.userID == userID; });
 if (it == users.end()) {
        cout << "User not found.\n";
        return;
    }
 while (fail < max) {
        cout << "Choose field to update (1 for Account Type, 2 for Auto Top-up): ";
        cin >> choice;
if (choice == '1') {
            cout << "Enter new Account Type: ";
            cin >> newAccountType;
            it->type = newAccountType[0]; // Assuming the type is a single character
            cout << "Account Type updated successfully.\n";
            return;
        }
        else if (choice == '2') {
            cout << "Enter new Auto Top-up setting (Y for Yes, N for No): ";
            cin >> newAutoTopUp;
            if (newAutoTopUp == 'Y' || newAutoTopUp == 'N') {
                it->autoTopUp = newAutoTopUp;
                cout << "Auto Top-up updated successfully.\n";
                return;
            }
            else {
                cout << "Invalid input. Please enter 'Y' or 'N'.\n";
                fail++;
            }
        }
        else {
            cout << "Invalid choice. Please try again.\n";
            fail++;
        }
    }
 if (fail == max) {
        cout << "Too many invalid attempts. Returning to User View Menu.\n";
    }
}
// R1
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
    isDataLoaded = true; 
    cout << "Starting data loaded successfully.\n";
}
// R2
void showUserRecords() {
    if (!isDataLoaded) {
        cout << "Error: Please Load the data first!\n"; 
        return;
    }
    sort(users.begin(), users.end(), [](User a, User b) { return a.userID < b.userID; }); 
    cout << "User Records:\n";

    cout << setw(15) << "ID"
         << setw(20) << "Type"
         << setw(25) << "Token Balance"
         << setw(20) << "Auto Top-Up\n";
    cout << string(85, '-') << "\n"; 
    for (const auto& user : users) {
        cout << setw(18) << user.userID
            << setw(15) << user.type
            << setw(22) << user.tokenBalance
            << setw(20) << user.autoTopUp << "\n";
    }
}
// R3
void editUsers() {
    if (!isDataLoaded) {
        cout << "Error: Please Load the data first!\n"; 
        return;
    }
    string userID;
    cout << "Enter User ID to edit: ";
    cin >> userID;
    auto it = find_if(users.begin(), users.end(), [&](User& u) { return u.userID == userID; });
    if (it == users.end()) {

        cout << "User not found. Adding new user.\n";
        User newUser;
        newUser.userID = userID;


        cout << "Enter Type (T/F/S): ";
        cin >> newUser.type;
        while (newUser.type != 'T' && newUser.type != 'F' && newUser.type != 'S') {
            cout << "Invalid type. Enter Type (T/F/S): ";
            cin >> newUser.type;
        }

        cout << "Enter Token Balance: ";
        cin >> newUser.tokenBalance;
        while (newUser.tokenBalance < 0) {
            cout << "Invalid balance. Enter Token Balance: ";
            cin >> newUser.tokenBalance;
        }

        cout << "Enter Auto Top-Up (Y/N): ";
        cin >> newUser.autoTopUp;
        while (newUser.autoTopUp != 'Y' && newUser.autoTopUp != 'N') {
            cout << "Invalid input. Enter Auto Top-Up (Y/N): ";
            cin >> newUser.autoTopUp;
        }

        users.push_back(newUser); 
        cout << "User added successfully.\n";
    }
    else {
        cout << "User found. Deleting user.\n";
        users.erase(it); 
        cout << "User deleted successfully.\n";
    }

}
// R4
void enterUserView(){

}
// R5
void showSystemUsageSummary(){

}
// R6
void CreditsAndExit(){

}
