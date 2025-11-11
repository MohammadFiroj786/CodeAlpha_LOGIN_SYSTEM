#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

const string FILE_PATH = "C:\\codealpha_c++\\New folder\\CodeAlpha_Login_System\\users.txt";

// Check if username exists
bool usernameExists(const string &username) {
    ifstream file(FILE_PATH);
    string u, p;
    while (file >> u >> p) {
        if (u == username) return true;
    }
    return false;
}

// Register new user
void registerUser() {
    string username, password;
    cout << "\n-------- User Registration --------\n";

    do {
        cout << "Enter username: ";
        cin >> username;
        if (usernameExists(username)) {
            cout << "Username already exists! Try a different one.\n";
        } else break;
    } while (true);

    cout << "Enter password: ";
    cin >> password;

    ofstream file(FILE_PATH, ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration successful! You can now login.\n";
}

// Login with max 3 attempts
void loginUser() {
    string username, password;
    bool success = false;
    int attempts = 3;

    cout << "\n----------- User Login -----------\n";

    while (attempts > 0) {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        ifstream file(FILE_PATH);
        string u, p;
        success = false;
        while (file >> u >> p) {
            if (u == username && p == password) {
                success = true;
                break;
            }
        }
        file.close();

        if (success) {
            cout << "Login successful! Welcome, " << username << "!\n";
            return;
        } else {
            attempts--;
            cout << "Invalid username or password. Attempts left: " << attempts << "\n";
        }
    }
    cout << "Maximum login attempts reached. Try again later.\n";
}

// Display all users (admin feature)
void displayUsers() {
    cout << "\n-------- Registered Users --------\n";
    ifstream file(FILE_PATH);
    string u, p;
    while (file >> u >> p) {
        cout << "- " << u << endl;
    }
    file.close();
}

// Update user password
void updatePassword() {
    string username, oldPass, newPass;
    cout << "\n------ Update Password ------\n";
    cout << "Enter username: ";
    cin >> username;

    if (!usernameExists(username)) {
        cout << "Username not found.\n";
        return;
    }

    cout << "Enter current password: ";
    cin >> oldPass;

    ifstream file(FILE_PATH);
    string u, p;
    string tempFile = "temp.txt";
    ofstream temp(tempFile);
    bool updated = false;

    while (file >> u >> p) {
        if (u == username && p == oldPass) {
            cout << "Enter new password: ";
            cin >> newPass;
            temp << u << " " << newPass << endl;
            updated = true;
        } else {
            temp << u << " " << p << endl;
        }
    }
    file.close();
    temp.close();

    remove(FILE_PATH.c_str());
    rename(tempFile.c_str(), FILE_PATH.c_str());

    if (updated) cout << "Password updated successfully!\n";
    else cout << "Incorrect current password.\n";
}

// Main menu
int main() {
    int choice;
    cout << "=================================\n";
    cout << "   CodeAlpha Internship Project\n";
    cout << "   Login & Registration System\n";
    cout << "       By: Mohammad Firoj\n";
    cout << "=================================\n";

    do {
        cout << "\nMenu:\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Update Password\n";
        cout << "4. Display Users (Admin)\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: updatePassword(); break;
            case 4: displayUsers(); break;
            case 5: cout << "Exiting program. Thank you!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
