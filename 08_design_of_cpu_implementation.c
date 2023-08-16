/*
    C program to design CPU implementation.
*/

#include <stdio.h>

#define FETCH 1
#define DECODE 2
#define ADDITION 3
#define HALT 4

int main()
{
    int program[] = {FETCH, DECODE, ADDITION, HALT};
    int PC = 0, ir = 0, mar = 0, mdr = 0, accumulator = 0, operand = 5;
    int running = 1;
    
    while (running)
    {
        mar = PC;
        mdr = program[mar];
        ir = mdr;
        PC++;
        switch (ir)
        {
        case ADDITION:
            accumulator += operand;
            break;
        case HALT:
            running = 0;
            break;
        default:
            printf("Invalid Instruction\n");
            running = 0;
            break;
        }
    }

    printf("Result: %d\n", accumulator);
    
    return 0;
}