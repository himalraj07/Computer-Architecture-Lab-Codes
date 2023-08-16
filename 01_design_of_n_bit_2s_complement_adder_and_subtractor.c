/*
    C program to design of N-Bit 2's complement adder/subtractor.
*/

#include <stdio.h>
// Function to perform 2's complement addition
void twosComplementAdder(int a[], int b[], int n, int sum[]);

// Function to perform 2's complement subtraction
void twosComplementSubtractor(int a[], int b[], int n, int diff[]);

// Function to display binary number
void displayBinaryNumber(int arr[], int n);

int main()
{
    int n;
    int i;

    printf("Enter the number of bits: ");
    scanf("%d", &n);

    int a[n], b[n], sum[n], diff[n];
    printf("Enter the first binary number: ");

    for (i = 0; i < n; i++)
    {
        scanf("%1d", &a[i]);
    }

    printf("Enter the second binary number: ");
    for (i = 0; i < n; i++)
    {
        scanf("%1d", &b[i]);
    }

    printf("\nPerforming 2's complement addition:\n");
    twosComplementAdder(a, b, n, sum);
    displayBinaryNumber(sum, n);

    printf("\nPerforming 2's complement subtraction:\n");
    twosComplementSubtractor(a, b, n, diff);
    displayBinaryNumber(diff, n);
    return 0;
}

void twosComplementAdder(int a[], int b[], int n, int sum[])
{
    int carry = 0, i;
    for (i = n - 1; i >= 0; i--)
    {
        int temp = a[i] + b[i] + carry;
        sum[i] = temp % 2;
        carry = temp / 2;
    }
}

void twosComplementSubtractor(int a[], int b[], int n, int diff[])
{
    int carry = 1, i;
    for (i = n - 1; i >= 0; i--)
    {
        int temp = a[i] + (1 - b[i]) + carry;
        diff[i] = temp % 2;
        carry = temp / 2 - 1;
    }
}

void displayBinaryNumber(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}