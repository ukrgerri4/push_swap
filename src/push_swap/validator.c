#include "push_swap.h"

int     check_letter(char *str)
{
    int i;

    i = 0;
    if ((str[i] != '-' && !(str[i] >= '0' && str[i] <= '9')) ||
                (str[i] == '-' && !str[i + 1]))
        return (1);
    i++;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (1);
        i++;
    }
    return (0);
}

int     check_double(int *arr, int size)
{
    int i;

    i = 0;
    while (i < (size - 1))
    {
        if (arr[i] == arr[i + 1])
            return (1);
        i++;
    }
    return (0);
}

long long int llint_atoi(const char *str)
{
    long long int nb;
    long long int sign;

    sign = 1;
    nb = 0;
    while (*str && (*str == ' ' || *str == '\t' || *str == '\v' ||
                    *str == '\f' || *str == '\r' || *str == '\n'))
        str++;
    if (*str == '+' || *str == '-')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    while (*str && *str >= '0' && *str <= '9')
        nb = nb * 10 + (*(str++) - '0');
    return (nb * sign);
}

int     validation(int argc, char **argv)
{
    int     *arr;
    int     i;
    long long int nb;

    i = 0;
    arr = (int *)malloc(sizeof(int) * (argc - 1));
    while (i < (argc - 1))
    {
        if (check_letter(argv[i + 1]))
            return (1);
        nb = llint_atoi(argv[i + 1]);
        if (nb > 2147483647 || nb < -2147483648)
            return (1);
        arr[i] = atoi(argv[i + 1]);
        i++;
    }
    shells_sort(arr, (argc - 1), 0);
    if (check_double(arr, (argc - 1)))
        return (1);
    free(arr);
    return (0);
}
