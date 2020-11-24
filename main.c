#include <stdio.h>
#include "myBank.h"

void getInput(int *i, double *d) {
    char t;
    printf("enter account number and amount:\n");
    scanf("%d%c", i, &t);
    scanf("%lf%c", d, &t);
}

int main() {
    char c;
    int account_number;
    double amount;
    double interest_rate;
    do {
        printf("Enter char operation:\n"
               "\tO: Open account\n"
               "\tB: Balance inquiry\n"
               "\tD: Deposit\n"
               "\tW: Withdrawal\n"
               "\tC: Close account\n"
               "\tI: Adding interest\n"
               "\tP: Print all open accounts\n"
               "\tE: Close all accounts and exit\n");
        scanf(" %c", &c);
        char t;
        switch (c) {
            case 'O':
                open();
                break;
            case 'B':
                printf("enter account number\n");
                scanf(" %d%c", &account_number, &t);
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
                printf("enter account number\n");
                scanf(" %d%c", &account_number, &t);
                close(account_number);
                break;
            case 'I':
                printf("enter interest rate [-99, 99]\n");
                scanf(" %lf%c", &interest_rate, &t);
                interest(interest_rate);
                break;
            case 'P':
                print();
                break;
            case 'E':
                closeAll();
                break;
            default:
                printf("Enter valid char, not[%c]\n", c);
                break;

        }
    } while (c != 'E');


    return 0;
}
