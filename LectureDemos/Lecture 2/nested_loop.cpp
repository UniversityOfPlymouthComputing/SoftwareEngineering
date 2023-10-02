#include <stdio.h>

int main()
{
    printf("Let's Go\n");

    // C99 (onwards) method
    for (int n=0; n < 5; n++) {
        for (int m=0; m<4; m++) {
            int product = n * m;
            printf("%d\t", product);
        }
        printf("\n");
    }
}