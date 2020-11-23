#include <stdio.h>

double bank[2][50] = {0}; //bank[0] = open if not 0; bank[1] = account

void open() {
    int i;
    for (i = 0; i < 50; i++) {
        if (bank[0][i] == 0) {
            bank[0][i] = 901.0 + i;
            printf("the account number is: %d\n", 901 + i);
            printf("Enter initial deposit: ");
            double money;
            char t;
            scanf("%lf%c", &money, &t);
            bank[1][i] = money;
//            printf("%lf", money);
            return;
        }
    }
    printf("There no room for anther account :(\n");
    return;
}

void balance(int account_number) {
    if (bank[0][account_number - 901] != 0) {
        printf("%.2f\n", bank[1][account_number - 901]);
        return;
    }
    printf("There is no such account\n");
}

void deposit(int account_number, double amount) {
    if (bank[0][account_number -901] != 0) {
        bank[1][account_number - 901] += amount;
    }
    printf("There is no such account\n");
}