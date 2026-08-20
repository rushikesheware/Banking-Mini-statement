#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("\nAccount limit reached!\n");
        return;
    }

    Account *acc = &accounts[accountCount];

    acc->accountNumber = 1001 + accountCount;

    printf("\nEnter account holder name: ");
    scanf(" %[^\n]", acc->name);

    printf("Enter initial deposit: ₹");
    scanf("%lf", &acc->balance);

    accountCount++;

    printf("\n✓ Account created successfully!");
    printf("\nAccount Number: %d\n", acc->accountNumber);
}

Account* findAccount(int number) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == number)
            return &accounts[i];
    }
    return NULL;
}

void deposit() {
    int number;
    double amount;

    printf("\nEnter account number: ");
    scanf("%d", &number);

    Account *acc = findAccount(number);

    if (!acc) {
        printf("\nAccount not found!\n");
        return;
    }

    printf("Enter deposit amount: ₹");
    scanf("%lf", &amount);

    if (amount <= 0) {
        printf("\nInvalid amount!\n");
        return;
    }

    acc->balance += amount;

    printf("\n✓ Deposit successful!");
    printf("\nNew Balance: ₹%.2f\n", acc->balance);
}

void withdraw() {
    int number;
    double amount;

    printf("\nEnter account number: ");
    scanf("%d", &number);



    Account *acc = findAccount(number);

    if (!acc) {
        printf("\nAccount not found!\n");
        return;
    }

    printf("Enter withdrawal amount: ₹");
    scanf("%lf", &amount);

    if (amount <= 0 || amount > acc->balance) {
        printf("\nInvalid amount or insufficient balance!\n");
        return;
    }

    acc->balance -= amount;

    printf("\n✓ Withdrawal successful!");
    printf("\nRemaining Balance: ₹%.2f\n", acc->balance);
}

void checkBalance() {
    int number;

    printf("\nEnter account number: ");
    scanf("%d", &number);

    Account *acc = findAccount(number);

    if (!acc) {
        printf("\nAccount not found!\n");
        return;
    }

    printf("\n-----------------------------");
    printf("\nAccount Holder : %s", acc->name);
    printf("\nAccount Number : %d", acc->accountNumber);
    printf("\nBalance        : ₹%.2f", acc->balance);
    printf("\n-----------------------------\n");
}

int main() {
    int choice;

    while (1) {
        clearScreen();

        printf("====================================\n");
        printf("        SMART BANKING SYSTEM        \n");
        printf("====================================\n");
        printf("  1. Create Account\n");
        printf("  2. Deposit Money\n");
        printf("  3. Withdraw Money\n");
        printf("  4. Check Balance\n");
        printf("  5. Exit\n");
        printf("====================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                deposit();
                break;

            case 3:
                withdraw();
                break;

            case 4:
                checkBalance();
                break;

            case 5:
                printf("\nThank you for using Smart Banking System!\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
    }

    return 0;
}
