#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Structure to store user data
struct User {
    string username;
    string password;
};

// Function to read user data from file
vector<User> readUserData() {
    vector<User> users;
    ifstream file("users.txt");
    string username, password;
    while (file >> username >> password) {
        users.push_back({username, password});
    }
    file.close();
    return users;
}

// Function to write user data to file
void writeUserData(const vector<User>& users) {
    ofstream file("users.txt");
    for (const User& user : users) {
        file << user.username << " " << user.password << endl;
    }
    file.close();
}

// Function for user registration
void registerUser(vector<User>& users, const string& username, const string& password) {
    users.push_back({username, password});
    writeUserData(users);
    cout << "Registration successful!" << endl;
}

// Function for user login
bool loginUser(const vector<User>& users, const string& username, const string& password) {
    for (const User& user : users) {
        if (user.username == username && user.password == password) {
            return true;
        }
    }
    return false;
}

int main() {
    vector<User> users = readUserData();

    while (true) {
        cout << "Welcome to the Login and Register form" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string username, password;
            cout << "Enter a username: ";
            cin >> username;
            cout << "Enter a password: ";
            cin >> password;
            registerUser(users, username, password);
        } else if (choice == 2) {
            string username, password;
            cout << "Enter your username: ";
            cin >> username;
            cout << "Enter your password: ";
            cin >> password;
            if (loginUser(users, username, password)) {
                cout << "Login successful!" << endl;
                // Here you can implement the task management functionality
                // for the logged-in user.
            } else {
                cout << "Login failed. Invalid credentials." << endl;
            }
        } else if (choice == 3) {
            cout << "Exiting the program." << endl;
            break;
        } else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}