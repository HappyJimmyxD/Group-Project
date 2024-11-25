#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

class Transaction {
public:
    string type; 
    string details; 
    int tokens;
    double amount;

    Transaction(string t, string d, int tok, double amt)
        : type(t), details(d), tokens(tok), amount(amt) {}
};

struct User {
    string userID;
    char type{};
    int tokenBalance{};
    char autoTopUp{};
    double totalAmountPaid;
    vector<Transaction> transactions; 
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
void PurchaseTokens(User& user);
void EditProfile();
void ShowTransactionHistory(User& user);
void ReturntoMainMenu();
void display();
void enterUserView();
void SelectAIService(string userID) {
    int ser, cost = 0, size, balance = 0;
    auto cs = find_if(users.begin(), users.end(), [&](User& u) { return u.userID == userID; });
    User& user = *cs;
    balance = (user.tokenBalance);

    cout << "(1)Image Recognition" << endl;
    cout << "(2)Speech-to-text transcription\n";
    cout << "(3)Predictive Analysis" << endl;
    cout << "(4)Natural Language Processing (NLP) \n";
    cout << "Choose a service (1-4): " << endl;
    cin >> ser;
    while (ser == 1) {
        cout << "What is the size of the picture: \n";
        cin >> size;
        if (size <= 3)
        {
            cost = (user.type == 'T') ? 5 : (user.type == 'F') ? 5 : 4;
        }
        else if (user.type == 'T')
        {
            cout << "Error, please upgrade your account or no more than 3MB" << endl;
            break;
        }
        else if (size > 3)
            cost = (user.type == 'F') ? 8 : 7;
        if (balance >= cost) {
            cout << balance - cost << "Successfully completed!\n";
        }
        else if (balance < cost && user.autoTopUp == 'Y' || user.autoTopUp == 'y')
        {
            while (balance - cost < 0) {
                balance += 20;
                user.transactions.emplace_back("Auto Top-up", "Purchased extra tokens", 20, 40);
                user.totalAmountPaid += 20;
            }
            cout << balance - cost << "Successfully completed!\n";
            user.tokenBalance = balance - cost;
            user.transactions.emplace_back("Service", "Used AI Service", cost, 0);
        }
        else
        {
            cout << "Balance not enought\n";
            user.tokenBalance = balance;
            break;
        }
        user.tokenBalance -= cost;
        user.transactions.emplace_back("Service", "Used AI Service", cost, 0);
        break;
    }

    while (ser == 2) {
        cout << "What is the length of Audio: \n";
        cin >> size;
        if (size <= 3) {
            cost = size * 2;
        }
        else {
            cost = (size - 3) * 3;
            cost += 6;
        }
        if (balance >= cost) {
            cout << balance - cost << "Successfully completed!\n";
        }
        else if (balance < cost && user.autoTopUp == 'Y' || user.autoTopUp == 'y')
        {
            while (balance - cost < 0) { 
                balance += 20; 
                user.transactions.emplace_back("Auto Top-up", "Purchased extra tokens", 20, 40);
                user.totalAmountPaid += 20;
            }
            cout << balance - cost << "Successfully completed!\n";
            user.tokenBalance = balance - cost;
            user.transactions.emplace_back("Service", "Used AI Service", cost, 0);
        }
        else
        {
            cout << "Balance not enought\n";
            user.tokenBalance = balance; break;
        }
        user.tokenBalance -= cost;
        user.transactions.emplace_back("Service", "Used AI Service", cost, 0);
        break;
    }
    while (ser == 3) {
        cout << "How many tasks do you need to analyze: \n";
        cin >> size;
        cost = size * 10;
        if (balance >= cost) {
            cout << balance - cost << "Successfully completed!\n";
        }
        else if (balance < cost && user.autoTopUp == 'Y' || user.autoTopUp == 'y')
        {
            while (balance - cost < 0) {
                balance += 20;
                user.transactions.emplace_back("Auto Top-up", "Purchased extra tokens", 20, 40);
                user.totalAmountPaid += 20;
            }
            cout << balance - cost << "Successfully completed!\n";
            user.tokenBalance = balance - cost;
            user.transactions.emplace_back("Service", "Used AI Service", cost, 0);
        }
        else
        {
            cout << "Balance not enought\n";
            user.tokenBalance = balance; break;
        }
        user.tokenBalance -= cost;
        user.transactions.emplace_back("Service", "Used AI Service", cost, 0);
        break;
    }
    while (ser == 4) {
        int num;
        cout << "What is the length of text for NLP: \n";
        cin >> size;
        if (size > 2500 && user.type == 'T')
            cout << "Please upgrade your user type\n";
        else if (size % 500 != 0)
            num = size / 500 + 1;
        else
            num = size / 500;
        cost = 1 * num;
        if (balance >= cost) {
            cout << balance - cost << "Successfully completed!\n";
        }
        else if (balance < cost && user.autoTopUp == 'Y' || user.autoTopUp == 'y')
        {
            while (balance - cost < 0) {
                balance += 20;
                user.transactions.emplace_back("Auto Top-up", "Purchased extra tokens", 20, 40);
                user.totalAmountPaid += 20;
            }
            cout << balance - cost << "Successfully completed!\n";
            user.tokenBalance = balance - cost;
            user.transactions.emplace_back("Service", "Used AI Service", cost, 0);
        }
        else
        {
            cout << "Balance not enought\n";
            user.tokenBalance = balance; break;
        }
        user.tokenBalance -= cost;
        user.transactions.emplace_back("Service", "Used AI Service", cost, 0);
        break;
    }
}


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
    auto cs = find_if(users.begin(), users.end(), [&](User& u) { return u.userID == userID; });
    if (cs == users.end()) {

        cout << "User not found. Adding new user.\n";
        User newUser;
        newUser.userID = userID;

        int attempts = 0;
        const int maxAttempts = 3;


        do {
            cout << "Enter Type (T/F/S): ";
            cin >> newUser.type;
            if (newUser.type == 'T' || newUser.type == 'F' || newUser.type == 'S') {
                break;
            }
            cout << "Invalid type. ";
            attempts++;
        } while (attempts < maxAttempts);

        if (attempts >= maxAttempts) {
            cout << "Too many invalid attempts. Returning to Main Menu.\n";
            return;
        }

        attempts = 0;


        do {
            cout << "Enter Token Balance: ";
            cin >> newUser.tokenBalance;
            if (cin.fail()) {
                cout << "Invalid balance. ";
                cin.clear();
                cin.ignore();

                attempts++;
            }
            else if (newUser.tokenBalance >= 0) {
                break;
            }
            else {
                cout << "Invalid balance. ";
                attempts++;
            }
        } while (attempts < maxAttempts);

        if (attempts >= maxAttempts) {
            cout << "Too many invalid attempts. Returning to Main Menu.\n";
            return;
        }

        attempts = 0;

        do {
            cout << "Enter Auto Top-Up (Y/N): ";
            cin >> newUser.autoTopUp;
            if (newUser.autoTopUp == 'Y' || newUser.autoTopUp == 'N') {
                break;
            }
            cout << "Invalid input. ";
            attempts++;
        } while (attempts < maxAttempts);

        if (attempts >= maxAttempts) {
            cout << "Too many invalid attempts. Returning to Main Menu.\n";
            return;
        }

        users.push_back(newUser);
        cout << "User added successfully.\n";
    }
    else {

        cout << "User found:\n";
        cout << "UserID: " << cs->userID << "\n";
        cout << "Type: " << cs->type << "\n";
        cout << "Token Balance: " << cs->tokenBalance << "\n";
        cout << "Auto Top-Up: " << cs->autoTopUp << "\n";

        char confirmation;

        cout << "Do you want to delete this user? (Y/N): ";
        cin >> confirmation;
        if (confirmation == 'Y' || confirmation == 'y') {
            users.erase(cs);
            cout << "User deleted successfully.\n";
        }
        else {
            cout << "User deletion cancelled.\n";
        }
    }

}
// R4
void enterUserView() {
    string userID;

    int count = 1;
    if (!isDataLoaded) {
        cout << "Error: Please Load the data first!\n";
        return;
    }
    cout << "Action for User ID: \n";
    cin >> userID;
    cout << endl;
    auto cs = find_if(users.begin(), users.end(), [&](User& u) { return u.userID == userID; });
    User& user = *cs;
    if (cs != users.end()) {
        while (count <= 3) {
            display();
            int option;
            cin >> option;
            switch (option) {
            case 1: SelectAIService(userID); break;
            case 2: PurchaseTokens(user); break;
            case 3: EditProfile(); break;
            case 4: ShowTransactionHistory(user); break;
            case 5: return;
            default: displayInvalidMessage();
            }
        }
    }
    else cout << "Not Found userID please enter again\n";
}
void display() {
    cout << "***** User View Menu ***** \n";
    cout << "[1] Select AI Service\n";
    cout << "[2] Purchase Tokens\n";
    cout << "[3] Edit Profile\n";
    cout << "[4] Show Transaction History\n";
    cout << "[5] Return to Main Menu\n";
    cout << "**************************" << endl << " Option(1 - 5) :";

}
void PurchaseTokens(User& user) {
    int amount;
    cout << "Enter amount to purchase tokens: ";
    cin >> amount;
    if (amount % 2 != 0) {
        cout << "Invalid amount. Must be an even number.\n";
        return;
    }
    int tokens = amount / 2;
    user.tokenBalance += tokens;
    user.totalAmountPaid += amount;
    user.transactions.emplace_back("Purchase", "Purchased tokens", tokens, amount);
    cout << "Purchased " << tokens << " tokens for $" << amount << ". New balance: " << user.tokenBalance << "\n";
    cout << endl;
}
void EditProfile() {}
void ShowTransactionHistory(User& user) {
    if (user.transactions.empty()) {
        cout << "No transactions made so far.\n";
        return;
    }
    cout << "Transaction History for " << user.userID << ":\n";
    for (const auto& transaction : user.transactions) {
        cout << "Type: " << transaction.type
            << ", Details: " << transaction.details
            << ", Tokens: " << transaction.tokens
            << ", Amount: $" << transaction.amount << "\n";
    }
    cout << "Total Amount Paid: $" << user.totalAmountPaid << endl;
}
void ReturntoMainMenu() {}

// R5
void showSystemUsageSummary() {
if (!isDataLoaded) {
    cout << "Error: Please Load the data first!\n";
    return;
}
    int sum =0;
    
    cout<<"The number of tokens spent on Image Recognition :\n";
    cout<<"The number of tokens spent on Speech-to-text transcription :\n";
    cout<<"The number of tokens spent on Predictive Analysis :\n";
    cout<<"The number of tokens spent on Natural Language Processing (NLP) : \n";
    cout<<"The total number of tokens spent on all AI services by all users : \n"<<sum<<"\n";
    cout<<"the total amount of money paid for buying tokens by all users : \n";
    
}
// R6
void CreditsAndExit() {
    char confirm;
    string StudentName[] = { "CHAN Kai Hei", "CHAN Man Pan", "LAM Ho", "LAW Ka Wai", "LEUNG Kam Ho", "TSE Wai Lok" };
    string StudentID[] = { "23158242A", "23176628A", "23175195A", "23179993A", "23162347A" };

    while (true) {
        cout << "Are you sure you want to enter CreditsAndExit? (y/n): ";
        cin >> confirm;
        if (confirm == 'y' || confirm == 'Y') {
            cout << left << setw(20) << "Student Name" << setw(40) << "Student ID" << endl;
            for (int i = 0; i < 6; ++i) {
                cout << left << setw(20) << StudentName[i] << setw(40) << StudentID[i] << endl;
            }
        }
        else if (confirm == 'n' || confirm == 'N') {
            return;
        }
        else {
            cout << "Invalid input. Please enter 'y' or 'n'." << endl;
        }
    }
}
