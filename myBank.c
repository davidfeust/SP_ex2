#include <stdio.h>

double bank[2][50] = {0}; //bank[0] = open if not 0; bank[1] = account

void open() {
    int i;
    for (i = 0; i < 50; i++) {
        if (bank[0][i] == 0) {
            printf("Please enter amount for deposit: ");
            double money;
            if (scanf(" %lf", &money) != 1) {
                printf("Failed to read the amount\n");
                return;
            }
            bank[0][i] = 901.0 + i;
            printf("New account number is: %d\n", 901 + i);
            bank[1][i] = money;
            return;
        }
    }
    printf("There no room for anther account :(\n");
}

void balance(int account_number) {
    if (account_number < 901 || account_number > 950 || bank[0][account_number - 901] == 0) {
        printf("This account is closed\n");
    } else
        printf("The balance of account number %d is: %.2f\n", account_number, bank[1][account_number - 901]);
}

void deposit(int account_number, double amount) {
    if (account_number < 901 || account_number > 950 || bank[0][account_number - 901] == 0) {
        printf("This account is closed\n");
    } else {
        bank[1][account_number - 901] += amount;
        printf("The new balance is: %.2f\n", bank[1][account_number - 901]);
    }
}

void withdrawal(int account_number, double amount) {
    if (account_number < 901 || account_number > 950 || bank[0][account_number - 901] == 0) {
        printf("This account is closed\n");
    } else if (bank[1][account_number - 901] - amount < 0) {
        printf("Cannot withdraw more than the balance\n");
    } else {
        bank[1][account_number - 901] -= amount;
        printf("The new balance is: %.2f\n", bank[1][account_number - 901]);
    }
}

void close(int account_number) {
    if (account_number < 901 || account_number > 950 || bank[0][account_number - 901] == 0) {
        printf("This account is closed\n");
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
            printf("The balance of account number %d is: %.2lf\n", (i + 901), bank[1][i]);
        }
    }
}

void closeAll() {
    for (int i = 0; i < 50; ++i) {
        bank[0][i] = 0;
    }
}
