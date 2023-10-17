#include <stdio.h>

int main()
{


    float grade;
    puts("Enter your grade");
    scanf("%f", &grade);

    if (grade < 39.5) 
    {
        puts("Sadly - failed");
    } 
    else if (grade < 50.0)
    {
        puts("3rd Class");
    }
    else if (grade < 60.0) 
    {
        puts("2:2");
    } 
    else if (grade < 70.0)
    {
        puts("2:1");
    }
    else {
        char someString[] = "May the force be with you always";
        puts("1st");
    }

    char hackyString[] = {'H','e','l','l','o'};
    puts(hackyString);
}