/*
    C program to Design of Overflow detector in binary signed number addition.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addBinary(char *a, char *b)
{
    int lenA = strlen(a);
    int lenB = strlen(b);
    int maxLen = (lenA > lenB) ? lenA : lenB;
    char *result = (char *)malloc((maxLen + 1) * sizeof(char));

    int carry = 0;
    int i = lenA - 1;
    int j = lenB - 1;
    int k = maxLen;

    while (i >= 0 || j >= 0)
    {
        int digitA = (i >= 0) ? (a[i--] - '0') : 0;
        int digitB = (j >= 0) ? (b[j--] - '0') : 0;
        int sum = digitA + digitB + carry;

        result[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    if (carry)
        result[k--] = carry + '0';

    if (carry)
    {
        printf("Overflow\n");
    }
    else
    {
        printf("No overflow\n");
    }

    printf("Binary sum: %s\n", &result[k + 1]);
    free(result); // Free dynamically allocated memory.
}

int main()
{
    char binary1[100], binary2[100];
    printf("Enter the first binary number: ");
    scanf("%s", binary1);
    printf("Enter the second binary number: ");
    scanf("%s", binary2);
    addBinary(binary1, binary2);

    return 0;
}