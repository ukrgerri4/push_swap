#include "push_swap.h"

static void shells_sort(int *arr, int n, int tmp)
{
    int k;
    int i;
    int j;

    k = n/2;
    while (k > 0)
    {
        i = k;
        while (i < n)
        {
            tmp = arr[i];
            j = i;
            while (j >= k)
            {
                if (tmp < arr[j - k])
                    arr[j] = arr[j - k];
                else
                    break;
                j -= k;
            }
            arr[j] = tmp;
            i++;
        }
        k /= 2;
    }
}

int     find_median(t_dlist *list, int len)
{
    t_node  *tmp;
    int     median;
    int     *arr;
    int     i;
    int     cnt;

    i = 0;
    cnt = 0;
    tmp = list->head;
    if (!(arr = (int*)malloc(sizeof(int) * len)))
        return (0);
    while (i < len)
    {
        arr[i++] = tmp->nb;
        tmp = tmp->next;
    }
    shells_sort(arr, len, cnt);
    median = arr[(len / 2)];
    return (median);
}
