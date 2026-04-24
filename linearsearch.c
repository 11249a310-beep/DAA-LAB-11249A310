#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void ls(int a1[], int begin, int stop, int search)
{
    if (begin == stop)
        printf("Element not found");
    else if (a1[begin] == search)          // Fix 1: a[begin] → a1[begin]
        printf("Element found @ position %d", begin + 1);
    else
        ls(a1, begin + 1, stop, search);
}

int main()                                  // Fix 2: void main() → int main()
{
    int a[10000], n = 10000, key, i;
    clock_t start, end;                     // Fix 3: Clock_t → clock_t (case-sensitive)

    for (i = 0; i < n; i++)
        a[i] = rand() % 1000;

    key = rand() % 1000;

    start = clock();
    ls(a, 0, n, key);
    end = clock();

    printf("\nTotal time taken for execution is %lf seconds",
           (double)(end - start) / CLOCKS_PER_SEC);   // Fix 4: start-end → end-start, divide by CLOCKS_PER_SEC

    return 0;                               // Fix 5: added return 0
}