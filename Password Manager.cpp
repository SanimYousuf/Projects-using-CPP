#include <bits/stdc++.h>
using namespace std;

void createAccount() {
    string username, password, cPass, email;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter E-mail: ";
    cin >> email;

    cout << "Enter password: ";
    cin >> password;

    cout << "Enter password again: ";
    cin >> cPass;

    if(cPass != password) {
        cout << "Password doesn't match. Try again!" << endl;
        return; // Exit the function if passwords don't match
    }

    ofstream file("accounts.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
        cout << "Account created successfully\n";
    } else {
        cout << "Error: Unable to open file\n";
    }
}

bool login() {
    string username, password, storedUsername, storedPassword;

    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream file("accounts.txt");
    if (file.is_open()) {
        while (file >> storedUsername >> storedPassword) {
            if (storedUsername == username && storedPassword == password) {
                file.close();
                return true;
            }
        }
        file.close();
    } else {
        cout << "Error: Unable to open file\n";
    }

    return false;
}

int main() {
    int choice;

    cout << "Welcome to the Capstone Password Manager\n";

    while (true) {
        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                if (login()) {
                    cout << "Login successful\n";
                } else {
                    cout << "Login failed\n";
                }
                break;
            case 3:
                cout << "Exiting...\n";
                exit(0);
            default:
                cout << "Invalid choice\n";
        }
    }

    return 0;
}


