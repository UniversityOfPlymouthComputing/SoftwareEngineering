#include <stdio.h>


int main ()
{

    puts("Press a letter or number, then press return");
    puts("Press q then return to quit");

    char userenteredcharacter;
    char returnkey;
do
{
    userenteredcharacter = getchar();
    returnkey = getchar();
    printf("you type %c\n", userentercharacter);
    printf("you also pressed returnkey (userenteredcharacter %d)\n", returnkey);
}
while ((userentercharacter != 'q') && (userentercharacter != 'Q'));

     puts("Finished");
}
