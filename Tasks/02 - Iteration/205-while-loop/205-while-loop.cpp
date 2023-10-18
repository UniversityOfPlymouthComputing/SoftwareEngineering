#include <stdio.h>

int main()

{
	int i = 0;

	puts("Start while loop");

	while (i < 7)

	{
		printf("i=%d\n", i);
		i++;             //same as i=i + 1 but more the point

	}

	printf("Exiting with i=%d\n", i);

}
