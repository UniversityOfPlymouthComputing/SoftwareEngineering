#include <iostream>

int main()
{
    int startInt = 0, creditInt = 10, debitInt = 0, balanceInt = 0;
    float startFloat = 0.0, creditFloat = 20.0, debitFloat = 0.0, balanceFloat = 0;

    // Use the + operator to add startInt to creditInt and assign the result to balanceInt
    balanceInt = startInt + creditInt;
    printf("Started at %d balance now at %d\n", startInt, balanceInt);

    // use the - operator to subtract debitInt from balanceInt and assign the result to balanceInt
    printf("Debit 5\n");
    debitInt = 5;
    balanceInt = balanceInt - debitInt;
    printf("Balance now at %d\n\n", balanceInt);

    // Use the increment operator to increase the Balance by 1
    //balanceInt++;
    //printf("Balance now at %d\n", balanceInt);
}

