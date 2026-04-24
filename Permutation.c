#include <stdio.h>                        // Fix 1: Added missing header

void perm(int arr[], int start, int stop)
{
    int temp;
    if (start == stop - 1)               // Fix 2: 'If' → 'if'; stop-1 to print last permutation correctly
    {
        for (int i = 0; i < stop; i++)
            printf("\t%d", arr[i]);
        printf("\n");
    }
    else                                 // Fix 3: 'Else' → 'else' (case-sensitive)
    {
        for (int i = start; i < stop; i++)
        {
            // Swap arr[i] with arr[start]
            temp = arr[i];
            arr[i] = arr[start];
            arr[start] = temp;           // Fix 4: 'a[start]' → 'arr[start]' (wrong array name)

            perm(arr, start + 1, stop);  // Fix 5: semicolon → comma: 'start+1;stop' → 'start+1, stop'

            // Swap back (backtrack)
            temp = arr[i];
            arr[i] = arr[start];
            arr[start] = temp;           // Fix 6: 'a[start]' → 'arr[start]' (wrong array name)
        }
    }
}

int main()                               // Fix 7: 'void main()' → 'int main()'
{
    int n, i, a[10];                     // Fix 8: 'I' → 'i' (case-sensitive)
    printf("Enter total number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    perm(a, 0, n);
    return 0;                            // Fix 9: Added return 0
}