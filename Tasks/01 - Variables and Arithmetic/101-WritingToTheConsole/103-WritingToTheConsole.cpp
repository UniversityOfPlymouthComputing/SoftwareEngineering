#include <stdio.h>

int main()
{
    // ************************ Using puts ******************************** 
    puts("Hello World!\n");   //Write Hello World to the terminal

    printf("Hello World!\n");
        printf("Hello Everyone. We are using C\nHow are things?\n");
    printf("Hello Everyone. We are using C\nHow are things?\n");

    puts("Answer when n is removed there is an error and no new line\n");

    int age = 35;
    printf("my age is %d\n",age); 

    // TASK(b) - Use printf to displa the value of the variable area. Look at the lecture slides and find out how to limit this to 3 decimal places
    // 
    float raduis =10.0f;
    float area = 3.415926 * raduis * raduis;

    printf("The area = %6.3f/n", area);

    // You can output complex strings to the terminal
    int p = 3;
    int q = 4;
    printf("p=%d, q=%d\n", p, q);

    int t = 7;
    int u = 8;

    printf("t=%d, u=%d\n", t, u);


    // TASK(c) - using printf, display the radius and the area using a single printf statement
    printf("raduis = %.6f, area = %.6f", raduis, area);

   





}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

