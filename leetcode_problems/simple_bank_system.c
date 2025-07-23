#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    long long* balance;
    int count;
} Bank;

Bank* bankCreate(long long* balance, int balanceSize) {
    Bank* obj = (Bank*)malloc(sizeof(Bank));
    obj->balance = (long long*)malloc(sizeof(long long) * balanceSize);
    for (int i = 0; i < balanceSize; i++) {
        obj->balance[i] = balance[i];
    }
    obj->count = balanceSize;
    return obj;
}

bool bankTransfer(Bank* obj, int account1, int account2, long long money) {
    if (account1 > obj->count || account2 > obj->count || obj->balance[account1 - 1] < money) {
        return false;
    }
    obj->balance[account1 - 1] -= money;
    obj->balance[account2 - 1] += money;
    return true;
}

bool bankDeposit(Bank* obj, int account, long long money) {
    if (account > obj->count) {
        return false;
    }
    obj->balance[account - 1] += money;
    return true;
}

bool bankWithdraw(Bank* obj, int account, long long money) {
    if (account > obj->count || obj->balance[account - 1] < money) {
        return false;
    }
    obj->balance[account - 1] -= money;
    return true;
}

void bankFree(Bank* obj) {
    free(obj->balance);
    free(obj);
}

int main() {
    long long balance[] = {10, 100, 20, 50, 30};
    int balanceSize = sizeof(balance) / sizeof(balance[0]);
    Bank* obj = bankCreate(balance, balanceSize);
    printf("Transfer: %s\n", bankTransfer(obj, 1, 2, 5) ? "true" : "false");
    printf("Deposit: %s\n", bankDeposit(obj, 3, 20) ? "true" : "false");
    printf("Withdraw: %s\n", bankWithdraw(obj, 4, 10) ? "true" : "false");
    bankFree(obj);
    return 0;
}
