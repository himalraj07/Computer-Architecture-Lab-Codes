/*
    C program for binary multiplication.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *binaryMultiplication(const char *binary1, const char *binary2)
{
    int length1 = strlen(binary1);
    int length2 = strlen(binary2);
    int result_length = length1 + length2;
    char *result = (char *)malloc((result_length + 1) * sizeof(char));
    result[result_length] = '\0';

    int i, j;
    for (i = 0; i < result_length; i++)
    {
        result[i] = '0';
    }

    for (i = length1 - 1; i >= 0; i--)
    {
        for (j = length2 - 1; j >= 0; j--)
        {
            int bit1 = binary1[i] - '0';
            int bit2 = binary2[j] - '0';
            int product = bit1 * bit2;
            int position = i + j + 1;
            int carry = 0;

            int sum = (result[position] - '0') + product + carry;
            carry = sum / 2;
            result[position] = (sum % 2) + '0';

            while (carry != 0)
            {
                position--;
                sum = (result[position] - '0') + carry;
                result[position] = (sum % 2) + '0';
                carry = sum / 2;
            }
        }
    }

    return result;
}

int main()
{
    const char *binary1 = "1101";
    const char *binary2 = "101";

    char *multiplicationResult = binaryMultiplication(binary1, binary2);

    printf("Multiplication Result: %s\n", multiplicationResult);
    
    free(multiplicationResult);

    return 0;
}