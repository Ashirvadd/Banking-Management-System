# Banking Management System

This project is a Banking Management System written in C, allowing both users and administrators to manage bank accounts with essential functionalities like checking balance, depositing, withdrawing, transferring money, and updating account details. The project uses a linked list to manage user accounts, and account details are persistently stored in a file, making it easy to reload and update information.

---

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Admin Login](#admin-login)
- [User Login](#user-login)
- [Code Explanation](#code-explanation)
- [Contributing](#contributing)
- [License](#license)

---

## Features

- **Admin Login** - Access admin functionalities with the default password `Admin@123`.
- **User Registration** - Create a new account with unique credentials and store details in a file.
- **Check Balance** - Allows users to view their current balance.
- **Deposit Money** - Add funds to a user account.
- **Withdraw Money** - Remove funds from a user account with sufficient balance.
- **Transfer Money** - Transfer funds between user accounts.
- **Change Password** - Allows users to update their password for security.
- **Logout** - Simple logout functionality for both users and admins.

---

## Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/yourusername/Banking-Management-System.git
   cd Banking-Management-System
2. **Compile the Code: Use GCC or any C compiler**:
   gcc banking_system.c -o banking_system
3. **Run the Program**:
   ./banking_system
Note: You must have user_accounts.txt in the same directory, or the program will create one when you register the first user account.

## Usage
## Admin Login
Select Admin Login in the main menu.
Enter the default password Admin@123.
Admin options include:
Viewing all user accounts.
Creating a new account.
Deleting an existing account.
Logging out.

## User Login
Select User Login in the main menu.
Enter your registered phone number and password.
User options include:
Check Balance - Displays current account balance.
Deposit Cash - Allows adding money to the account.
Withdraw Cash - Allows withdrawing money if balance permits.
Transfer Money - Transfer funds between accounts.
Change Password - Change the user account password.
Logout - Logout from the user account.

## Code Explanation
The project code comprises various functions to manage accounts and handle user/admin interactions. Here's a breakdown:

Data Structure: struct user - Manages account details like phone number, account number, password, and balance using a linked list structure.
Core Functionalities:
Register Account: Registers a new account after checking if the account number already exists.
Load Accounts: Loads existing account details from user_accounts.txt at the start of the program.
Admin Functions: Includes functions to view all accounts, create a new account, and delete accounts.
User Functions: Allows checking balance, depositing, withdrawing, transferring, and changing passwords.
Data Persistence:
Account details are stored in user_accounts.txt. Changes made during a session are saved when the program exits.
At program startup, it loads account details from the file, enabling seamless data persistence.
File Structure
banking_system.c - Main source code.
user_accounts.txt - Stores user details in the format: Account_Number Phone_Number Password Balance.


Sample Code Structure
Below is the sample structure and primary functions of the code:
C 
// Main struct for storing user details
struct user {
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
    struct user *next;
};

// Load accounts from file
void loadAccountsFromFile() {
    // Implementation to read from file and create linked list
}

// Register new account
void registerAccount() {
    // Account registration and file writing logic
}

// Admin login function with options
void adminLogin() {
    // Admin functionalities: view, create, delete accounts
}

// User login function with menu options
void userLogin() {
    // User functionalities: check balance, deposit, withdraw, transfer, change password
}

## Contributing
Feel free to contribute by opening issues or submitting pull requests. Whether you want to fix bugs, add new features, or improve documentation, contributions are welcome!

## License
This project is licensed under the MIT License.
