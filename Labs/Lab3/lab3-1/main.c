#include <stdio.h>
#include <stdlib.h>

int count_partitions(int n, int m);

int main(void)
{
    int number, part_number;
    printf("What number do you want to part?\n");
    scanf("%d", &number);
    printf("What part_number?\n");
    scanf("%d", &part_number);
    printf("There are %d methods to part\n", count_partitions(number, part_number));
    return EXIT_SUCCESS;
}

int count_partitions(int n, int m)
{
    /*your code here*/
}