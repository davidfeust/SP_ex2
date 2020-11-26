#include <stdio.h>

double bank[2][50] = {0}; //bank[0] = open if not 0; bank[1] = account

void open() {
    int i;
    for (i = 0; i < 50; i++) {
        if (bank[0][i] == 0) {
            bank[0][i] = 901.0 + i;
            printf("The account number is: %d\n", 901 + i);
            printf("Enter initial deposit: ");
            double money;
            while (scanf(" %lf", &money) != 1) {
                char c;
                scanf(" %c", &c);
            }
            bank[1][i] = money;
            return;
        }
    }
    printf("There no room for anther account :(\n");
}

void balance(int account_number) {
    if (account_number < 901 || account_number > 950 || bank[0][account_number - 901] == 0) {
        printf("There is no such account\n");
    } else
        printf("The balance is %.2f $\n", bank[1][account_number - 901]);
}

void deposit(int account_number, double amount) {
    if (account_number < 901 || account_number > 950 || bank[0][account_number - 901] == 0) {
        printf("There is no such account\n");
    } else
        bank[1][account_number - 901] += amount;

}

void withdrawal(int account_number, double amount) {
    if (account_number < 901 || account_number > 950 || bank[0][account_number - 901] == 0) {
        printf("There is no such account\n");
    } else if (bank[1][account_number - 901] - amount < 0) {
        printf("There is no enough money\n");
    } else {
        bank[1][account_number - 901] -= amount;
        printf("You have %.2f$ left\n", bank[1][account_number - 901]);
    }
}

void close(int account_number) {
    if (account_number < 901 || account_number > 950 || bank[0][account_number - 901] == 0) {
        printf("There is no such account\n");
    } else {
        bank[0][account_number - 901] = 0;
        bank[0][account_number - 901] = 0;
        printf("Account number %d closed\n", account_number);
    }
}

void interest(double d) {
    if (d > 99 || d < -99) {
        printf("Not legal rate");
    }
    for (int i = 0; i < 50; ++i) {
        if (bank[0][i] != 0) {
            bank[1][i] += bank[1][i] * d / 100;
        }
    }
}

void print() {
    for (int i = 0; i < 50; ++i) {
        if (bank[0][i] != 0) {
            printf("Account number %d: %.2lf$\n", (i + 901), bank[1][i]);
        }
    }
}

void closeAll() {
    for (int i = 0; i < 50; ++i) {
        bank[0][i] = 0;
    }
}
