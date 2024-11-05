#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent user account information
struct user {
    char phone[50];
    char ac[50];
    char password[50];
    float balance;
    struct user *next;
};

// Global variable to store the head of the linked list
struct user *head = NULL;

// Function to display the user menu and get user's choice
int userMenu() {
    int ch;
    printf("\n\nUser Menu:");
    printf("\n1. Check Balance");
    printf("\n2. Deposit Cash");
    printf("\n3. Withdraw Cash");
    printf("\n4. Transfer Money");
    printf("\n5. Change Password");
    printf("\n6. Logout");

    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    return ch;


}

// Function to register a new account
// Function to register a new account
void registerAccount() {
    struct user *temp = (struct user *)malloc(sizeof(struct user));
    if (temp == NULL) {
        printf("Memory allocation failed.");
        return;
    }

    printf("Enter your account number: ");
    scanf("%s", temp->ac);

    // Check if the entered account number already exists
    struct user *current = head;
    while (current != NULL) {
        if (strcmp(temp->ac, current->ac) == 0) {
            printf("Account number already exists.\n");
            free(temp); // Free the allocated memory for the new user
            return;
        }
        current = current->next;
    }

    printf("Enter your phone number: ");
    scanf("%s", temp->phone);
    printf("Enter your new password: ");
    scanf("%s", temp->password);
    temp->balance = 0;
    temp->next = NULL;

    // Add the new user to the linked list
    if (head == NULL) {
        head = temp;
    } else {
        struct user *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = temp;
    }

    // Store the account details in a file
    FILE *fp = fopen("user_accounts.txt", "a");
    if (fp != NULL) {
        fprintf(fp, "%s %s %s %.2f\n", temp->ac, temp->phone, temp->password, temp->balance);
        fclose(fp);
        printf("\nAccount successfully registered and stored in file.\n");
    } else {
        printf("\nFailed to open file for storing account details.\n");
    }
}


// Function to load user account details from file into linked list
void loadAccountsFromFile() {
    FILE *fp = fopen("user_accounts.txt", "r");
    if (fp != NULL) {
        while (!feof(fp)) {
            struct user *temp = (struct user *)malloc(sizeof(struct user));
            if (fscanf(fp, "%s %s %s %f", temp->ac, temp->phone, temp->password, &temp->balance) == 4) {
                temp->next = NULL;
                if (head == NULL) {
                    head = temp;
                } else {
                    struct user *current = head;
                    while (current->next != NULL) {
                        current = current->next;
                    }
                    current->next = temp;
                }
            }
        }
        fclose(fp);
    } else {
        printf("\nFailed to open file for loading account details.\n");
    }
}

// Function to display all user accounts
void viewAllAccounts() {
    if (head == NULL) {
        printf("\nNo accounts registered yet.\n");
        return;
    }

    printf("\nAll User Accounts:");
    struct user *current = head;
    while (current != NULL) {
        printf("\nAccount Number: %s", current->ac);
        printf("\nPhone Number: %s", current->phone);
        printf("\nBalance: Rs. %.2f\n", current->balance);
        current = current->next;
    }
}
void deleteAccount() {
    char accountNumber[50];
    printf("\nEnter the account number to delete: ");
    scanf("%s", accountNumber);

    struct user *prev = NULL;
    struct user *current = head;

    // Find the account to delete
    while (current != NULL) {
        if (strcmp(accountNumber, current->ac) == 0) {
            if (prev == NULL) {
                // If the account to be deleted is the first node
                head = current->next;
            } else {
                // If the account to be deleted is not the first node
                prev->next = current->next;
            }
            free(current);
            printf("\nAccount deleted successfully.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("\nAccount not found.\n");
}

// Function to handle user login
void userLogin() {
    char phone[50], password[50];
    printf("\nPhone number: ");
    scanf("%s", phone);
    printf("Password: ");
    scanf("%s", password);

    struct user *current = head;
    while (current != NULL) {
        if (strcmp(phone, current->phone) == 0 && strcmp(password, current->password) == 0) {
            printf("\nWelcome %s", current->phone);

            int choice;
            do {
                choice = userMenu();
                switch (choice) {
                    case 1:
                        printf("\nYour current balance is Rs.%.2f", current->balance);
                        break;
                    case 2:
                        printf("\nEnter the amount to deposit: ");
                        float depositAmount;
                        scanf("%f", &depositAmount);
                        current->balance += depositAmount;
                        printf("\nDeposit successful. Your new balance is Rs.%.2f", current->balance);
                        break;
                    case 3:
                        printf("\nEnter the amount to withdraw: ");
                        float withdrawAmount;
                        scanf("%f", &withdrawAmount);
                        if (withdrawAmount > current->balance) {
                            printf("\nInsufficient balance.");
                        } else {
                            current->balance -= withdrawAmount;
                            printf("\nWithdrawal successful. Your new balance is Rs.%.2f", current->balance);
                        }
                        break;
                    case 4:
                        // Add transfer money logic
                        transferMoney();
                        break;
                    case 5:
                        printf("\nEnter new password: ");
                        scanf("%s", current->password);
                        printf("\nPassword changed successfully.");
                        break;
                    case 6:
                        printf("\nLogging out...");
                        break;
                    default:
                        printf("\nInvalid choice.");
                }
            } while (choice != 6);

            return;
        }
        current = current->next;
    }
    printf("\nInvalid phone number or password\n");
}

// Function to handle admin login
void adminLogin() {
    char adminPassword[50];
    printf("\nEnter admin password: ");
    scanf("%s", adminPassword);

    // You can set your admin password here
    char *correctAdminPassword = "Admin@123";

    if (strcmp(adminPassword, correctAdminPassword) == 0) {
        printf("\nWelcome Admin");

        int choice;
        do {
            printf("\n\nAdmin Menu:");
            printf("\n1. View All Accounts");
            printf("\n2. Create New Account");
            printf("\n3. Delete Account");
            printf("\n4. Logout");

            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    viewAllAccounts();
                    break;
                case 2:
                    registerAccount();
                    break;
                case 3:
                    // Add delete account logic
                    deleteAccount();
                    break;
                case 4:
                    printf("\nLogging out...");
                    break;
                default:
                    printf("\nInvalid choice.");
            }
        } while (choice != 4);

    } else {
        printf("\nIncorrect admin password\n");
    }
}
 void transferMoney() {
    char sourceAccount[50], targetAccount[50];
    printf("\nEnter source account number: ");
    scanf("%s", sourceAccount);
    printf("Enter target account number: ");
    scanf("%s", targetAccount);

    struct user *source = NULL, *target = NULL;
    struct user *current = head;

    // Find the source and target accounts in the linked list
    while (current != NULL) {
        if (strcmp(sourceAccount, current->ac) == 0) {
            source = current;
        }
        if (strcmp(targetAccount, current->ac) == 0) {
            target = current;
        }
        current = current->next;
    }

    // Check if both source and target accounts exist
    if (source == NULL || target == NULL) {
        printf("\nInvalid source or target account number.\n");
        return;
    }

    float transferAmount;
    printf("Enter the amount to transfer: ");
    scanf("%f", &transferAmount);

    // Check if the source account has sufficient balance
    if (transferAmount > source->balance) {
        printf("\nInsufficient balance in the source account.\n");
        return;
    }

    // Deduct the transfer amount from the source account and add it to the target account
    source->balance -= transferAmount;
    target->balance += transferAmount;

    printf("\nTransfer successful.\n");
}

int main() {
    // Load existing accounts from file into linked list
    loadAccountsFromFile();

    int userChoice;

    do {
        printf("\n\n1. Admin Login");
        printf("\n2. User Login");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &userChoice);

        switch (userChoice) {
            case 1:
                adminLogin();
                break;
            case 2:
                userLogin();
                break;
            case 3:
                printf("\nThank You... Visit Again...\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    } while (userChoice != 3);

    // Store updated account details from linked list back to file
    FILE *fp = fopen("user_accounts.txt", "w");
    if (fp != NULL) {
        struct user *current = head;
        while (current != NULL) {
            fprintf(fp, "%s %s %s %.2f\n", current->ac, current->phone, current->password, current->balance);
            current = current->next;
        }
        fclose(fp);
    } else {
        printf("\nFailed to open file for storing account details.\n");
    }

    // Free the allocated memory for the linked list before exiting
    struct user *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}





