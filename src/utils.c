#include "utils.h"
#include <stdlib.h>
#include <stdio.h>

void error_exit(const char *message)
{
    write(2, message, strlen(message));
    exit(EXIT_FAILURE);
}

int ft_atoi(const char *str)
{
    int num = 0;
    int sign = 1;

    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
        str++;
    if (*str == '-' || *str == '+')
        sign = (*str++ == '-') ? -1 : 1;
    while (*str >= '0' && *str <= '9')
        num = num * 10 + (*str++ - '0');
    return (num * sign);
}
