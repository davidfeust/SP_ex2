#include <stdio.h>
#include "myBank.h"

int accountInput(int *n) {
    if (scanf(" %d", n) != 1) {
        printf("Failed to read the account number\n");
        return 0;
    }
    return 1;
}

int main() {
    char input;
    int account_number;
    double amount, interest_rate;
    do {
        printf("\nPlease choose a transaction type:\n"
               "O-Open Account\n"
               "B-Balance Inquiry\n"
               "D-Deposit\n"
               "W-Withdrawal\n"
               "C-Close Account\n"
               "I-Interest\n"
               "P-Print\n"
               "E-Exit\n");
        scanf(" %c", &input);
        switch (input) {
            case 'O':
                open();
                break;

            case 'B':
                printf("Please enter account number: ");
                if (accountInput(&account_number) == 1)
                    balance(account_number);
                break;

            case 'D':
                printf("Please enter account number: ");
                if (accountInput(&account_number) == 1) {
                    printf("Please enter the amount to deposit: ");
                    if (scanf(" %lf", &amount) == 1) {
                        deposit(account_number, amount);
                    }
                }
                break;

            case 'W':
                printf("Please enter account number: ");
                if (accountInput(&account_number) == 1) {
                    printf("Please enter the amount to withdraw: ");
                    if (scanf(" %lf", &amount) == 1) {
                        withdrawal(account_number, amount);
                    }
                }
                break;

            case 'C':
                if (accountInput(&account_number) == 1)
                    close(account_number);
                break;

            case 'I':
                printf("Please enter interest rate: ");
                if (scanf(" %lf", &interest_rate) == 1) {
                    interest(interest_rate);
                } else {
                    printf("Failed to read the interest rate\n");
                }
                break;

            case 'P':
                print();
                break;

            case 'E':
                closeAll();
                break;

            default:
                printf("Invalid transaction type\n");
                break;
        }
    } while (input != 'E');
    return 0;
}
