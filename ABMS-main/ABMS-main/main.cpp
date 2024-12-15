#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <unordered_map>
#include <string>
#include "Login/Login.h"
#include "UI/UIUtils.h"

void saveUserInfo(const std::string& username, const std::string& password, const std::string& accountID, double balance) {
    std::ofstream outFile("users.txt", std::ios::app);
    if (outFile) {
        outFile << username << " " << password << " " << accountID << " " << balance << std::endl;
        outFile.close();
    }
    else {
        std::cerr << "Error: Unable to open users.txt for writing." << std::endl;
    }
}

void createNewAccount(Login& login) {
    std::string username, password, accountID;
    double balance;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Enter account ID: ";
    std::cin >> accountID;
    std::cout << "Enter initial balance: ";
    std::cin >> balance;

    saveUserInfo(username, password, accountID, balance);
    login.addUser(username, password, balance);

    std::cout << "Account successfully created for " << username << "!" << std::endl;
    Sleep(2000);
}

int main() {
    Login login;
    login.loadUsers();
    bool loggedIn = false;

    while (!loggedIn) {
        system("cls");
        displayLoginMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            loggedIn = login.userLogin();
            break;
        case 2:
            createNewAccount(login);
            break;
        case 3:
            loggedIn = login.managerLogin();
            break;
        case 4:
            login.displayUsers();
            system("pause");
            break;
        case 5:
            std::cout << "Goodbye!" << std::endl;
            Sleep(1500);
            return 0;
        
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    if (login.currentUser) {
        bool running = true;
        while (running) {
            system("cls");
            displayBalanceMenu(login.currentUser);
            int action;
            std::cin >> action;

            switch (action) {
            case 1:
                double depositAmount;
                std::cout << "Enter amount to deposit: ";
                std::cin >> depositAmount;
                login.currentUser->deposit(depositAmount);
                break;
            case 2:
                double withdrawAmount;
                std::cout << "Enter amount to withdraw: ";
                std::cin >> withdrawAmount;
                login.currentUser->withdraw(withdrawAmount);
                break;
            case 3:
                login.currentUser->printAccountSummary();
                system("pause");
                break;
            case 5:
                running = false;
                break;
            
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }

    delete login.currentUser;
    return 0;
}
