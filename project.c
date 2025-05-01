#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define MAX_ACCOUNTS 100 
 
typedef struct { 
    int accountNumber; 
    char name[50]; 
    int pin; 
    float balance; 
} Account; 
 
Account accounts[MAX_ACCOUNTS]; 
int accountCount = 0; 
 
// Function to check if an account number exists 
int accountExists(int accountNumber) { 
    for (int i = 0; i < accountCount; i++) { 
        if (accounts[i].accountNumber == accountNumber) { 
            return i;  // Return index of the account 
        } 
    } 
    return -1; 
} 
 
// Function to create a new account 
void createAccount() { 
    if (accountCount >= MAX_ACCOUNTS) { 
        printf("Cannot create more accounts. Limit reached.\n"); 
        return; 
    } 
 
    Account newAccount; 
    printf("Enter account number: "); 
    scanf("%d", &newAccount.accountNumber); 
 
    if (accountExists(newAccount.accountNumber) != -1) { 
        printf("Error: Account number already exists.\n"); 
        return; 
    } 
 
    printf("Enter account holder name: "); 
    scanf("%s", newAccount.name); 
 
    printf("Set a PIN for your account: "); 
    scanf("%d", &newAccount.pin); 
 
    printf("Enter initial deposit amount: "); 
    scanf("%f", &newAccount.balance); 
 
    if (newAccount.balance < 1000) { 
        printf("Error: Minimum deposit required is 1000.\n"); 
        return; 
    } 
 
    accounts[accountCount] = newAccount; 
    accountCount++; 
    printf("Account created successfully!\n"); 
} 
 
// Function to deposit money 
void depositMoney() { 
    int accountNumber, pin, index; 
    float amount; 
    printf("Enter account number: "); 
    scanf("%d", &accountNumber); 
    index = accountExists(accountNumber); 
 
    if (index == -1) { 
        printf("Error: Account not found.\n"); 
        return; 
    } 
 
    printf("Enter PIN: "); 
    scanf("%d", &pin); 
    
    if (accounts[index].pin != pin) { 
        printf("Error: Incorrect PIN.\n"); 
        return; 
    } 
 
    printf("Enter amount to deposit: "); 
    scanf("%f", &amount); 
    
    if (amount <= 0) { 
        printf("Error: Invalid amount.\n"); 
        return; 
    } 
 
    accounts[index].balance += amount; 
    printf("Deposit successful! New Balance: %.2f\n", accounts[index].balance); 
} 
 
// Function to withdraw money 
void withdrawMoney() { 
    int accountNumber, pin, index; 
    float amount; 
    printf("Enter account number: "); 
    scanf("%d", &accountNumber); 
    index = accountExists(accountNumber); 
 
    if (index == -1) { 
        printf("Error: Account not found.\n"); 
        return; 
    } 
 
    printf("Enter PIN: "); 
    scanf("%d", &pin); 
    
    if (accounts[index].pin != pin) { 
        printf("Error: Incorrect PIN.\n"); 
        return; 
    } 
 
    printf("Enter amount to withdraw: "); 
    scanf("%f", &amount); 
    
    if (amount <= 0 || amount > accounts[index].balance) { 
        printf("Error: Insufficient balance or invalid amount.\n"); 
        return; 
    } 
 
    accounts[index].balance -= amount; 
    printf("Withdrawal successful! New Balance: %.2f\n", accounts[index].balance); 
} 
 
// Function to transfer money 
void transferMoney() { 
    int senderAccount, receiverAccount, senderIndex, receiverIndex, pin; 
    float amount; 
    printf("Enter sender account number: "); 
    scanf("%d", &senderAccount); 
    senderIndex = accountExists(senderAccount); 
 
    if (senderIndex == -1) { 
        printf("Error: Sender account not found.\n"); 
        return; 
    } 
 
    printf("Enter sender PIN: "); 
    scanf("%d", &pin); 
    
    if (accounts[senderIndex].pin != pin) { 
        printf("Error: Incorrect PIN.\n"); 
        return; 
    } 
 
    printf("Enter receiver account number: "); 
    scanf("%d", &receiverAccount); 
    receiverIndex = accountExists(receiverAccount); 
 
    if (receiverIndex == -1) { 
        printf("Error: Receiver account not found.\n"); 
        return; 
    } 
 
    printf("Enter amount to transfer: "); 
    scanf("%f", &amount); 
 
    if (amount <= 0 || amount > accounts[senderIndex].balance) { 
        printf("Error: Insufficient balance or invalid amount.\n"); 
        return; 
    } 
 
    accounts[senderIndex].balance -= amount; 
    accounts[receiverIndex].balance += amount; 
    printf("Transfer successful! New Balance: %.2f\n", accounts[senderIndex].balance); 
} 
 
// Function to display all accounts 
void displayAccounts() { 
    printf("\nList of all accounts:\n"); 
    for (int i = 0; i < accountCount; i++) { 
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", 
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance); 
    } 
} 
 
int main() { 
    int choice; 
    while (1) { 
        printf("\nBanking System Menu:\n"); 
        printf("1. Create Account\n"); 
        printf("2. Deposit Money\n"); 
        printf("3. Withdraw Money\n"); 
        printf("4. Transfer Money\n"); 
        printf("5. Display Accounts\n"); 
        printf("6. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                createAccount(); 
                break; 
            case 2: 
                depositMoney(); 
                break; 
            case 3: 
                withdrawMoney(); 
                break; 
            case 4: 
                transferMoney(); 
                break; 
            case 5: 
                displayAccounts(); 
                break; 
            case 6: 
                printf("Exiting program. Goodbye!\n"); 
                exit(0); 
            default: 
                printf("Invalid choice. Please try again.\n"); 
        } 
    } 
    return 0; 
}



