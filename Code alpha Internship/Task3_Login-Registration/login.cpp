#include <iostream>
#include <fstream>
#include <string>
#include <limits>  // for numeric_limits
using namespace std;

// Function to check if user exists
bool userExists(const string& username) {
    ifstream file("users.txt");
    string line;
    while (getline(file, line)) {
        if (line.find(username + ":") == 0) {
            return true;
        }
    }
    return false;
}

// Function to register user
void registerUser() {
    string username, password;
    cout << "Enter new username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "❌ Username already exists. Try a different one.\n";
        return;
    }

    cout << "Enter new password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    if (!file) {
        cout << "❌ Unable to open file for writing.\n";
        return;
    }

    file << username << ":" << password << endl;
    file.close();
    cout << "✅ Registration successful!\n";
}

// Function to login
void loginUser() {
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    if (!file) {
        cout << "❌ Unable to open file for reading.\n";
        return;
    }

    string line;
    bool success = false;

    while (getline(file, line)) {
        size_t pos = line.find(":");
        if (pos == string::npos) continue;

        string storedUser = line.substr(0, pos);
        string storedPass = line.substr(pos + 1);

        if (storedUser == username && storedPass == password) {
            success = true;
            break;
        }
    }

    file.close();

    if (success) {
        cout << "✅ Login successful!\n";
    } else {
        cout << "❌ Invalid username or password.\n";
    }
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n========== Login & Registration System ==========\n";
        cout << "1. Register\n2. Login\n3. Exit\nChoose an option: ";

        cin >> choice;

        // Handle non-integer input
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "❌ Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "👋 Exiting program. Goodbye!\n";
                break;
            default:
                cout << "❌ Invalid option. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
