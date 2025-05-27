#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
bool confirm_further_operation()
{
    char selection;
    printf("Do you want to perform another transaction y/n?");
    scanf("%s", &selection);
    return tolower(selection) == 'y';
}


