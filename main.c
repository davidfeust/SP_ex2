#include <stdio.h>
#include "myBank.h"

int main() {
    char c;
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
        scanf("%c", &c);
        int b;
        char t;
        switch (c) {
            case 'O':
                open();
                break;
            case 'B':
                printf("enter account number\n");

                scanf(" %d%c", &b, &t);
                balance(b);
                break;
            case 'D':
                printf("enter account number and amount:\n");
                int account_number;
                double amount;
                scanf("%d%c", &account_number, &t);
                scanf("%lf%c", &amount, &t);
                deposit(account_number, amount);
                break;
//            case 'W': withdrawal();
//                break;
//            case 'C': close();
//                break;
//            case 'I': interest();
//                break;
//            case 'P': print();
//                break;
            case 'E':
                break;
            default:
                printf("Enter valid char, not[%c]\n", c);
                break;

        }
    } while (c != 'E');


    return 0;
}
