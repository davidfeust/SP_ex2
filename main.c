#include <stdio.h>
#include "myBank.h"

void getInput(int *account, double *am) {
    printf("Enter account number and amount:\n");
    scanf(" %d", account);
    scanf(" %lf", am);
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
                printf("Enter account number\n");
                scanf(" %d", &account_number);
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
                printf("Enter account number\n");
                scanf(" %d", &account_number);
                close(account_number);
                break;
            case 'I':
                printf("Enter interest rate [-99, 99]\n");
                scanf(" %lf", &interest_rate);
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
