#include <stdio.h>

void toh(int, char, char, char);          // Fix 1: Added missing includes

void toh(int n, char x, char y, char z)  // Fix 2: Added function name 'toh'
{
    if (n == 1)                           // Fix 3: 'If' → 'if' (case-sensitive)
    {
        printf("\nDisk %d -> %c to %c", n, x, y);
    }
    else
    {
        toh(n - 1, x, z, y);
        printf("\nDisk %d -> %c to %c", n, x, y);  // Fix 4: comma → arrow for clarity
        toh(n - 1, z, y, x);
    }
}                                         // Fix 5: Added missing closing brace for toh()

int main()                                // Fix 6: 'void main()' → 'int main()'
{
    int n;                                // Fix 7: 'Int' → 'int' (case-sensitive)
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    toh(n, 'A', 'C', 'B');              // Fix 8: Completed the toh() call with proper arguments
    return 0;                             // Fix 9: Added return 0
}