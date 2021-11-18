#include <stdio.h>
#include <stdlib.h> 
int i;

int changeopcode(int* arr)
{
    int opcode = 0;
    for(i = 0; i < 6; i++)
    {
        opcode *= 2; 
        opcode += arr[i];
    }
    return opcode;
}

int changefunc(int* arr)
{
    int func = 0;
    for(i = 0; i < 6; i++)
    {
        func *= 2; 
        func += arr[i+26];
    }
    return func;
}

void print_rdrsrt(int* arr)
{
    int rd = 0;
    int rs = 0;
    int rt = 0;
    for(i = 0; i < 5; i++)
    {
        rd *= 2; 
        rd += arr[i+16];
    }
    printf("$%d, ", rd);
    for(i = 0; i < 5; i++)
    {
        rs *= 2; 
        rs += arr[i+6];
    }
    printf("$%d, ", rs);
    for(i = 0; i < 5; i++)
    {
        rt *= 2; 
        rt += arr[i+11];
    }
    printf("$%d ", rt);
}

void print_rdrtrs(int* arr)
{
    int rd = 0;
    int rt = 0;
    int rs = 0;
    for(i = 0; i < 5; i++)
    {
        rd *= 2; 
        rd += arr[i+16];
    }
    printf("$%d, ", rd);
    for(i = 0; i < 5; i++)
    {
        rt *= 2; 
        rt += arr[i+11];
    }
    printf("$%d, ", rt);
    for(i = 0; i < 5; i++)
    {
        rs *= 2; 
        rs += arr[i+6];
    }
    printf("$%d ", rs);
}

void print_rdrtshamt(int*arr)
{
    int rd = 0;
    int rt = 0;
    int shamt = 0;
    for(i = 0; i < 5; i++)
    {
        rd *= 2; 
        rd += arr[i+16];
    }
    printf("$%d, ", rd);
    for(i = 0; i < 5; i++)
    {
        rt *= 2; 
        rt += arr[i+11];
    }
    printf("$%d, ", rt);
    for(i = 0; i < 5; i++)
    {
        shamt *= 2; 
        shamt += arr[i+21];
    }
    printf("%d ", shamt);
}

void print_rsrt(int*arr)
{
    int rs = 0;
    int rt = 0;
    for(i = 0; i < 5; i++)
    {
        rs *= 2; 
        rs += arr[i+6];
    }
    printf("$%d, ", rs);
    for(i = 0; i < 5; i++)
    {
        rt *= 2; 
        rt += arr[i+11];
    }
    printf("$%d ", rt);
}

void print_rs(int*arr)
{
    int rs = 0;
    for(i = 0; i < 5; i++)
    {
        rs *= 2; 
        rs += arr[i+6];
    }
    printf("$%d ", rs);
}

void print_rd(int* arr)
{
    int rd = 0;
    for(i = 0; i < 5; i++)
    {
        rd *= 2; 
        rd += arr[i+16];
    }
    printf("$%d ", rd);
}

void print_rdrs(int* arr)
{
    int rd = 0;
    int rs = 0;
    for(i = 0; i < 5; i++)
    {
        rd *= 2; 
        rd += arr[i+16];
    }
    printf("$%d, ", rd);
    for(i = 0; i < 5; i++)
    {
        rs *= 2; 
        rs += arr[i+6];
    }
    printf("$%d ", rs);
}

void print_rtrsimmed(int* arr)
{
    int rt = 0;
    int rs = 0;
    int immed = 0;
    for(i = 0; i < 5; i++)
    {
        rt *= 2; 
        rt += arr[i+11];
    }
    printf("$%d, ", rt);
    for(i = 0; i < 5; i++)
    {
        rs *= 2; 
        rs += arr[i+6];
    }
    printf("$%d, ", rs);
    if (arr[16] == 0)
    {
        for(i = 0; i < 15; i++)
        {
        immed *= 2; 
        immed += arr[i+17];
        }
        printf("%d ", immed);
    }
    else 
    {
        for(i = 0; i < 15; i++)
        {
        immed *= 2; 
        immed += arr[i+17];
        }
        immed = immed - 32768;
        printf("%d ", immed);
    }
}

void print_rtrsimmed2(int* arr)
{
    int rt = 0;
    int rs = 0;
    int immed = 0;
    for(i = 0; i < 5; i++)
    {
        rt *= 2; 
        rt += arr[i+11];
    }
    printf("$%d, ", rt);
    for(i = 0; i < 5; i++)
    {
        rs *= 2; 
        rs += arr[i+6];
    }
    if (arr[16] == 0)
    {
        for(i = 0; i < 15; i++)
        {
        immed *= 2; 
        immed += arr[i+17];
        }
        printf("%d($%d) ", immed, rs);
    }
    else 
    {
        for(i = 0; i < 15; i++)
        {
        immed *= 2; 
        immed += arr[i+17];
        }
        immed = immed - 32768;
        printf("%d($%d) ", immed, rs);
    }
}

void printaddress(int* arr)
{
    int address = 0;
    for(i = 0; i < 26; i++)
    {
        address *= 2; 
        address += arr[i+6];
    }
    printf("%d ", address);
}

void printrtimmed(int* arr)
{
    int rt = 0;
    int immed = 0;
    for(i = 0; i < 5; i++)
    {
        rt *= 2; 
        rt += arr[i+11];
    }
    printf("$%d, ", rt);
    if (arr[16] == 0)
    {
        for(i = 0; i < 15; i++)
        {
        immed *= 2; 
        immed += arr[i+17];
        }
        printf("%d ", immed);
    }
    else 
    {
        for(i = 0; i < 15; i++)
        {
        immed *= 2; 
        immed += arr[i+17];
        }
        immed = immed - 32768;
        printf("%d ", immed);
    }
}

void print_rsrtimmed(int* arr)
{
    int rs = 0;
    int rt = 0;
    int immed = 0;
    for(i = 0; i < 5; i++)
    {
        rs *= 2; 
        rs += arr[i+6];
    }
    printf("$%d, ", rs);
    for(i = 0; i < 5; i++)
    {
        rt *= 2; 
        rt += arr[i+11];
    }
    printf("$%d, ", rt);
    if (arr[16] == 0)
    {
        for(i = 0; i < 15; i++)
        {
        immed *= 2; 
        immed += arr[i+17];
        }
        printf("%d ", immed);
    }
    else 
    {
        for(i = 0; i < 15; i++)
        {
        immed *= 2; 
        immed += arr[i+17];
        }
        immed = immed - 32768;
        printf("%d ", immed);
    }
}

void classify(int* arr, int opcode, int func)
{
    if (opcode == 0)
    {
        if (func == 32){printf("add "); print_rdrsrt(arr);}
        else if (func == 33){printf("addu "); print_rdrsrt(arr);}
        else if (func == 36){printf("and "); print_rdrsrt(arr);}
        else if (func == 26){printf("div "); print_rsrt(arr);}
        else if (func == 27){printf("divu "); print_rsrt(arr);}
        else if (func == 9){printf("jalr "); print_rdrs(arr);}
        else if (func == 8){printf("jr "); print_rs(arr);}
        else if (func == 16){printf("mfhi "); print_rd(arr);}
        else if (func == 18){printf("mflo "); print_rd(arr);}
        else if (func == 17){printf("mthi "); print_rs(arr);}
        else if (func == 19){printf("mtlo "); print_rs(arr);}
        else if (func == 24){printf("mult "); print_rsrt(arr);}
        else if (func == 25){printf("multu "); print_rsrt(arr);}
        else if (func == 39){printf("nor "); print_rdrsrt(arr);}
        else if (func == 37){printf("or "); print_rdrsrt(arr);}
        else if (func == 0){printf("sll "); print_rdrtshamt(arr);}
        else if (func == 4){printf("sllv "); print_rdrtrs(arr);}
        else if (func == 42){printf("slt "); print_rdrsrt(arr);}
        else if (func == 43){printf("sltu "); print_rdrsrt(arr);}
        else if (func == 3){printf("sra "); print_rdrtshamt(arr);}
        else if (func == 7){printf("srav "); print_rdrtrs(arr);}
        else if (func == 2){printf("srl "); print_rdrtshamt(arr);}
        else if (func == 6){printf("srlv "); print_rdrtrs(arr);}
        else if (func == 34){printf("sub "); print_rdrsrt(arr);}
        else if (func == 35){printf("subu "); print_rdrsrt(arr);}
        else if (func == 12){printf("syscall ");}
        else if (func == 26){printf("xor "); print_rdrsrt(arr);}
        else {printf("unknown instruction ");}
    }
    else if (opcode == 8){printf("addi "); print_rtrsimmed(arr);}
    else if (opcode == 9){printf("addiu "); print_rtrsimmed(arr);}
    else if (opcode == 12){printf("andi "); print_rtrsimmed(arr);}
    else if (opcode == 4){printf("beq "); print_rsrtimmed(arr);}
    else if (opcode == 5){printf("bne "); print_rsrtimmed(arr);} 
    else if (opcode == 32){printf("lb "); print_rtrsimmed2(arr);}
    else if (opcode == 36){printf("lbu "); print_rtrsimmed2(arr);}
    else if (opcode == 33){printf("lh "); print_rtrsimmed2(arr);}
    else if (opcode == 37){printf("lhu "); print_rtrsimmed2(arr);}
    else if (opcode == 15){printf("lui "); printrtimmed(arr);}
    else if (opcode == 35){printf("lw "); print_rtrsimmed2(arr);}
    else if (opcode == 13){printf("ori "); print_rtrsimmed(arr);}
    else if (opcode == 40){printf("sb "); print_rtrsimmed2(arr);}
    else if (opcode == 10){printf("slti "); print_rtrsimmed(arr);}
    else if (opcode == 11){printf("sltiu "); print_rtrsimmed(arr);}
    else if (opcode == 41){printf("sh "); print_rtrsimmed2(arr);}
    else if (opcode == 43){printf("sw "); print_rtrsimmed2(arr);}
    else if (opcode == 14){printf("xori "); print_rtrsimmed(arr);}
    else if (opcode == 2){printf("j "); printaddress(arr);}
    else if (opcode == 3){printf("jal "); printaddress(arr);}
    else {printf("unknown instruction ");}
}

int main()
{
    FILE *input;
    int hex, j;
    if ((input = fopen("/home/swe3005/2021f/proj1/test3.bin", "rb")) == NULL)
    {
        fputs("Error : file doesn't open", stderr);
        exit(1);
    }
    i = 0;
    int arr[32];
    int temp[4];
    int line_num = 0;
    while ((hex = fgetc(input)) != EOF)
    {
        temp[i] = hex;
        for(j = 7; j >= 0; j--)
        {
            arr[8*i + j] = hex % 2;
            hex /= 2;
        }
        i++;
        if (i == 4)
        {
            printf("inst %d: ", line_num);
            for(i = 0; i < 4; i++)
            {
                printf("%02x", temp[i]);
            }
            printf(" ");
            int opcode = changeopcode(arr);
            int func = changefunc(arr);
            classify(arr, opcode, func);
            printf("\n");
            i = 0;
            line_num++;
        }
    }
    fclose(input);
    return 0;
}
