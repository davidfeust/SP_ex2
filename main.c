#include <stdio.h>
#include "myBank.h"

void getInput(int *account, double *am) {
    printf("Enter account number and amount:\n");
    while (scanf(" %d", account) != 1) {
        char c;
        scanf("%c", &c);
    }
    while (scanf(" %lf", am) != 1) {
        char c;
        scanf("%c", &c);
    }
}

void getAccountNum(int *an) {
    printf("Enter account number\n");
    while (scanf(" %d", an) != 1) {
        char c;
        scanf("%c", &c);
    }
}

int main() {
    char input;
    int account_number;
    double amount;
    double interest_rate;
    do {
        printf("\nEnter char operation:\n"
               "\tO: Open account\n"
               "\tB: Balance inquiry\n"
               "\tD: Deposit\n"
               "\tW: Withdrawal\n"
               "\tC: Close account\n"
               "\tI: Adding interest\n"
               "\tP: Print all open accounts\n"
               "\tE: Close all accounts and exit\n");
        scanf(" %c", &input);
        switch (input) {
            case 'O':
                open();
                break;
            case 'B':
                getAccountNum(&account_number);
                balance(account_number);
                break;
            case 'D':
                getInput(&account_number, &amount);
                deposit(account_number, amount);
                break;
            case 'W':
                getInput(&account_number, &amount);
                withdrawal(account_number, amount);
                break;
            case 'C':
                getAccountNum(&account_number);
                close(account_number);
                break;
            case 'I':
                printf("Enter interest rate [-99, 99]\n");
                while (scanf(" %lf", &interest_rate) != 1) {
                    char c;
                    scanf("%c", &c);
                }
                interest(interest_rate);
                break;
            case 'P':
                print();
                break;
            case 'E':
                closeAll();
                break;
            default:
                printf("Enter valid char, not '%c'\n", input);
                break;
        }
    } while (input != 'E');

    return 0;
}
