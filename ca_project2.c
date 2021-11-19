#include <stdio.h>
#include <stdlib.h> 
int i;

typedef struct Register{
    int arr[32];
} Register;

typedef struct memory{
    int arr[8];
} memory;


Register create_register(int num)
{
    Register a;
    for (i = 0; i < 32; i++)
    {
        a.arr[i] = 0;
    } 
    return a;
}

int changeregister(int* arr, int num)
{
    int reg_num = 0;
    for(i = 0; i < 5; i++)
    {
        reg_num *= 2; 
        reg_num += arr[i + 6 + 5*num];
    }
    return reg_num;
}

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
    if (arr[6] == 0)
    {
        for(i = 0; i < 25; i++)
        {
        address *= 2; 
        address += arr[i+7];
        }
        printf("%d ", address);
    }
    else 
    {
        for(i = 0; i < 25; i++)
        {
        address *= 2; 
        address += arr[i+7];
        }
        address = address - 33,554,432;
        printf("%d ", address);
    }
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

int unsigned_change(int* arr)
{
    int data = 0;
    for(i = 0; i < 32; i++)
    {
        data *= 2; 
        data += arr[i];
    }
    return data;
}

int signed_change(int* arr)
{
    int data = 0;
    if (arr[0] == 0)
    {
        for(i = 1; i < 32; i++)
        {
            data *= 2; 
            data += arr[i];
        }
        return data;
    }
    else
    {
        for(i = 1; i < 32; i++)
        {
            data *= 2; 
            data += arr[i];
        }
        return - 2^31 + data;
    }
}

int* decimal_to_binary(int num)
{
    int* arr = (int*)malloc(32 * sizeof(int));
    if (num < 0)
    {
        for ()
    }
    for ()
}

void add(int* arr, int* arr2, int* arr3)
{
    int arr4[32];
    for (i = 31; i > -1; i--)
    {
        arr4[i] = 0;
    }
    for (i = 31; i > -1; i--)
    {
        arr4[i] += arr[i] + arr2[i];
        if (arr4[i] >= 2)
        {
            arr4[i] %= 2;
            if (i != 0) 
            {
                arr4[i - 1] += 1;
            }
        }
    }
     arr3 = arr4;
}

void sub(int* arr, int* arr2, int* arr3)
{
    int arr3[32];
    for (i = 31; i > -1; i--)
    {
        arr3[i] = 0;
    }
    for (i = 31; i > -1; i--)
    {
        if (arr2[i] == 1) {arr3[i] == 0;}
        else {arr3[i] == 1;}
    }
    arr3[31] += 1; 
    for (i = 31; i > -1; i--)
    {
        arr3[i] += arr[i] + arr3[i];
        if (arr3[i] >= 2)
        {
            arr3[i] %= 2;
            if (i != 0) 
            {
                arr3[i - 1] += 1;
            }
        }
    }
}

void xor(int* arr, int* arr2, int* arr3)
{
    for (i = 31; i > -1; i--)
    {
        if (arr[i] != arr2[i]) {arr3[i] = 1;}
        if (arr[i] == arr2[i]) {arr3[i] = 0;}
    }
}

void or(int* arr, int* arr2, int* arr3)
{
    for (i = 31; i > -1; i--)
    {
        if (arr[i] + arr2[i] > 0) {arr3[i] = 1;}
        else { arr3[i] = 0;}
    }
}

void and(int* arr, int* arr2, int* arr3)
{
    for (i = 31; i > -1; i--)
    {
        if (arr[i] + arr2[i] > 1) {arr3[i] = 1;}
        else { arr3[i] = 0;}
    }
}

void nor(int* arr, int* arr2, int* arr3)
{
    for (i = 31; i > -1; i--)
    {
        if (arr[i] + arr2[i] > 0) {arr3[i] = 0;}
        else { arr3[i] = 1;}
    }
}

int* sign_extension(int* arr, int num, int num2)
{
    int* arr2 = (int*)malloc(32 * sizeof(int));
    for(i = num - 1; i > -1 ; i--)
    {
        arr2[i + num2 - num] = arr[i];
    }
    for (i = 0; i < num2 - num; i++)
    {
        arr2[i] = arr[0];
    }
    return arr2;
}

void slti(int* arr, int* arr2, int* arr3)
{
    for (i = 31; i > -1; i--)
    {
        arr3[i] = 0;
    }
    if (arr[0] > arr2[0])
    {
        arr3[-1] = 1;
    }
    else if (arr[0] < arr2[0]);
    else if (arr[0] == 1)
    {
        for(i = 0; i < 32; i++)
        {
            if (arr[i] < arr2[i])
            {
                arr3[-1] = 1;
                break;
            }
            else if (arr[i] > arr2[i])
            {
                break;
            }
        }
    }
    else
    {
        for(i = 0; i < 32; i++)
        {
            if (arr[i] < arr2[i])
            {
                arr3[-1] = 1;
                break;
            }
            else if (arr[i] > arr2[i])
            {
                break;
            }
        }
    }
}

void sltiu(int* arr, int* arr2, int* arr3)
{
    for (i = 31; i > -1; i--)
    {
        arr3[i] = 0;
    }
    for(i = 0; i < 32; i++)
    {
        if (arr[i] < arr2[i])
        {
            arr3[-1] = 1;
            break;
        }
        else if (arr[i] > arr2[i])
        {
            break;
        }
    }
}

void sll(int* arr, int* arr2, int num)
{
    for (i = 0; i < 32 - num; i++)
    {
        arr2[i] = arr[i + num];
    }
    for (i = 32 - num; i < 32; i++)
    {
        arr2[i] = 0;
    }
}

void srl(int* arr, int* arr2, int num)
{
    for (i = 31; i > -1; i--)
    {
        arr2[i - num] = arr[i];
    }
    for (i = num - 1; i > -1; i--)
    {
        arr2[i] = arr[0];
    }
}

void lui(int* arr, int* arr2)
{
    for(i = 0; i < 16; i++)
    {
        arr2[i] = arr[i + 16];
    }
}

void bne(int* arr, int* arr2, int* pc, int* immd)
{
    int cnt = 0;
    int arr3[32];
    for(i = 0; i < 32; i++)
    {
        arr3[i] = 0;
        if (arr[i] == arr2[i]){cnt++;}
    }
    arr3[31] = 1;
    if (cnt != 32)
    {
        for(i = 0; i < 32; i++)
        {
            add(immd, arr3, immd);
            sll(immd, immd, 2);
            add(immd, pc, pc);
        }
    }
}

void beq(int* arr, int* arr2, int* pc, int* immd)
{
    int cnt = 0;
    int arr3[32];
    for(i = 0; i < 32; i++)
    {
        arr3[i] = 0;
        if (arr[i] == arr2[i]){cnt++;}
    }
    arr3[31] = 1;
    if (cnt == 32)
    {
        for(i = 0; i < 32; i++)
        {
            add(immd, arr3, immd);
            sll(immd, immd, 2);
            add(immd, pc, pc);
        }
    }
}

void jump(int* immd, int* pc)
{
    sll(immd, immd, 2);
    for(i = 4; i < 32; i++)
    {
        pc[i] = immd[i];
    }
}

void jal (int* immd, int* pc, int* ra)
{
    int arr[32];
    for(i = 0; i < 32; i++)
    {
        arr[i] = 0;
    }
    arr[29] = 1;
    add(arr, pc, arr);
    for(i = 0; i < 32; i++)
    {
        ra[i] = arr[i];
    }
    sll(immd, immd, 2);
    for(i = 4; i < 32; i++)
    {
        pc[i] = immd[i];
    }
}

void jr (int* arr, int* pc)
{
    for(i = 0; i < 32; i++)
    {
        pc[i] = arr[i];
    }
}

//void lw (int* )
int issame(int* arr, int num)
{
    int a = signed_change(arr);
    if (a == num) {return 1;}
    else {return 0;}
}

void syscall(int* v0, int* a0)
{
    if(issame(v0, 1))
    {
        printf("%d", signed_change(a0));
    }
    else if(issame(v0, 4))
    {
        
    }
    else if(issame(v0, 5))
    {
        int value;
        scanf("%d", &value);
        int* arr = decimal_to_binary(value);
        for ()
        
    }
}


int main(int argc, char *argv[])
{
    FILE *input;
    int hex, j;
    if ((input = fopen("test1.bin", "rb")) == NULL)
    {
        fputs("Error : file doesn't open", stderr);
        exit(1);
    }
    i = 0;
    int arr[32];
    int pc[32];
    int four[32];
    int temp[4];
    int line_num = 0;
    Register reglist[32];
    memory instlist[65536];
    memory datalist[65536];
    for (i = 0; i < 32; i++)
    {
        Register reg = create_register(i);
        reglist[i] = reg;
        four[i] = 0;
    }
    four[29] = 1;

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

            if (opcode == 0)
            {
                if (func == 32)
                {
                    //printf("add "); print_rdrsrt(arr);
                    int rd = changeregister(arr, 1);
                    int rs = changeregister(arr, 2);
                    int rt = changeregister(arr, 3);
                    add(reglist[rs].arr, reglist[rt].arr, reglist[rd].arr);
                }
                else if (func == 33)
                {
                    //printf("addu "); print_rdrsrt(arr);
                    int rd = changeregister(arr, 1);
                    int rs = changeregister(arr, 2);
                    int rt = changeregister(arr, 3);
                    add(reglist[rs].arr, reglist[rt].arr, reglist[rd].arr);
                }
                else if (func == 36)
                {
                    //printf("and "); print_rdrsrt(arr);
                    int rd = changeregister(arr, 1);
                    int rs = changeregister(arr, 2);
                    int rt = changeregister(arr, 3);
                    and(reglist[rs].arr, reglist[rt].arr, reglist[rd].arr);
                }
                //else if (func == 26){printf("div "); print_rsrt(arr);}
                //else if (func == 27){printf("divu "); print_rsrt(arr);}
                else if (func == 9)
                {printf("jalr "); print_rdrs(arr);}
                else if (func == 8)
                {printf("jr "); print_rs(arr);}
                //else if (func == 16){printf("mfhi "); print_rd(arr);}
                //else if (func == 18){printf("mflo "); print_rd(arr);}
                //else if (func == 17){printf("mthi "); print_rs(arr);}
                //else if (func == 19){printf("mtlo "); print_rs(arr);}
                //else if (func == 24){printf("mult "); print_rsrt(arr);}
                //else if (func == 25){printf("multu "); print_rsrt(arr);}
                else if (func == 39)
                {
                    //printf("nor "); print_rdrsrt(arr);
                }
                else if (func == 37){printf("or "); print_rdrsrt(arr);}
                else if (func == 0){printf("sll "); print_rdrtshamt(arr);}
                //else if (func == 4){printf("sllv "); print_rdrtrs(arr);}
                else if (func == 42){printf("slt "); print_rdrsrt(arr);}
                else if (func == 43){printf("sltu "); print_rdrsrt(arr);}
                //else if (func == 3){printf("sra "); print_rdrtshamt(arr);}
                //else if (func == 7){printf("srav "); print_rdrtrs(arr);}
                else if (func == 2){printf("srl "); print_rdrtshamt(arr);}
                //else if (func == 6){printf("srlv "); print_rdrtrs(arr);}
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
            //else if (opcode == 32){printf("lb "); print_rtrsimmed2(arr);}
            //else if (opcode == 36){printf("lbu "); print_rtrsimmed2(arr);}
            //else if (opcode == 33){printf("lh "); print_rtrsimmed2(arr);}
            //else if (opcode == 37){printf("lhu "); print_rtrsimmed2(arr);}
            else if (opcode == 15){printf("lui "); printrtimmed(arr);}
            else if (opcode == 35){printf("lw "); print_rtrsimmed2(arr);}
            else if (opcode == 13){printf("ori "); print_rtrsimmed(arr);}
            //else if (opcode == 40){printf("sb "); print_rtrsimmed2(arr);}
            else if (opcode == 10){printf("slti "); print_rtrsimmed(arr);}
            else if (opcode == 11){printf("sltiu "); print_rtrsimmed(arr);}
            //else if (opcode == 41){printf("sh "); print_rtrsimmed2(arr);}
            else if (opcode == 43){printf("sw "); print_rtrsimmed2(arr);}
            else if (opcode == 14){printf("xori "); print_rtrsimmed(arr);}
            else if (opcode == 2){printf("j "); printaddress(arr);}
            else if (opcode == 3){printf("jal "); printaddress(arr);}
            else {printf("unknown instruction ");}



            i = 0;
            add(pc, four, pc);
            
        }
    }
    fclose(input);
    return 0;
}