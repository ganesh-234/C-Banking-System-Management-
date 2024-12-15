Banking System Management 

Project Overview
This comprehensive banking management system, developed in C++, showcases advanced object-oriented programming (OOP) principles. Designed for educational purposes at the University of Wisconsin, Green Bay, it features robust functionalities like account management, transaction processing, and user authentication.


Features
•	User Account Management: Dynamically create, modify, and delete banking accounts.
•	Transaction Handling: Support for deposits, withdrawals, and viewing transaction history.
•	Loan Management: Administer loans to users with real-time updates.
•	Authentication System: Secure login for regular users and administrators.
•	Data Persistence: Real-time data management with backup and restore capabilities using users.txt.


Technical Specifications
•	Language: C++
•	OOP Principles: Encapsulation, Inheritance, Polymorphism, Pointers, Array and basic fundamentals.
•	External Libraries: Standard C++ library only.
•	Platform: Developed and tested on Windows 10.


Core Classes

Account
•	Purpose: Base class for different types of bank accounts.
•	Key Methods: deposit(), withdraw(), printAccountSummary().

UserAccount : public Account
•	Purpose: Manages individual user accounts and handles transactions.
•	Key Methods: Specific implementations for deposit and withdrawal methods.

ManagerAccount : public Account
•	Purpose: Manages administrative functions such as account creation and deletion.
•	Key Methods: createAccount(), deleteAccount().

AccountManager
•	Purpose: Oversees a collection of accounts and facilitates system-wide operations.
•	Key Methods: loadAccounts(), saveAccounts(), displayAllAccounts().

Login
•	Purpose: Handles authentication for users and administrators.
•	Key Methods: userLogin(), managerLogin(), validateManager().

UIUtils
•	Purpose: Contains utility functions to manage user interface elements.
•	Key Methods: displayLoginMenu(), displayManagerMenu(), getConsoleSize(), printCentered().


Main Function
The main function serves as the entry point for the application, orchestrating user interactions and system operations based on input choices. It integrates user authentication, session management, and navigates between different user interfaces depending on the role and actions chosen.


Getting Started
Prerequisites
•	C++ compiler supporting C++11 (e.g., GCC, Clang, MSVC)



Usage
Follow the on-screen prompts to log in as a user or manager, manage accounts, and perform transactions.

