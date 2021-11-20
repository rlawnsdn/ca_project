#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int i, j;

typedef struct Register{
    int arr[32];
} Register;

Register create_register()
{
    Register a;
    for (i = 0; i < 32; i++)
    {
        a.arr[i] = 0;
    } 
    return a;
}

void printarr(int* arr)
{
    for(i = 0; i < 32; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int changeregister(int* arr, int num) // num = 0 -> rs, num = 1 -> rt, num = 2 -> rd, num = 3 -> shamt
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
            if (arr[i] == 0)
            {
                data += 1;
            }
        }
        data++;
        return -1 * data;
    }
}

int* decimal_to_binary(int num)
{
    int* arr = (int*)malloc(32 * sizeof(int));
    if (num >= 0)
    {
        arr[0] = 0;
        for (i = 31; i > 0; i--)
        {
            arr[i] = num % 2;
            num /= 2;
        }
    }
    else 
    {
        num = - num - 1;
        arr[0] = 1;
        for (i = 31; i > 0; i--)
        {
            arr[i] = !(num % 2);
            num /= 2;
        }
    }
    return arr;
}


int* sign_extension(int* arr, int num, int num2)
{
    int* arr2 = (int*)malloc(32 * sizeof(int));
    for(i = num - 1; i > -1 ; i--)
    {
        arr2[i + num2 - num] = arr[i + num2 - num];
    }
    for (i = 0; i < num2 - num; i++)
    {
        arr2[i] = arr[num];
    }
    return arr2;
}

int* unsign_extension(int* arr, int num, int num2)
{
    int* arr2 = (int*)malloc(32 * sizeof(int));
    for(i = num - 1; i > -1 ; i--)
    {
        arr2[i + num2 - num] = arr[i + num2 - num];
    }
    for (i = 0; i < num2 - num; i++)
    {
        arr2[i] = 0;
    }
    return arr2;
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
    for (i = 31; i > -1; i--)
    {
        arr3[i] = arr4[i];
    }
}

void sub(int* arr, int* arr2, int* arr3)
{
    int arr4[32];
    for (i = 31; i > -1; i--)
    {
        arr4[i] = 0;
    }
    for (i = 31; i > -1; i--)
    {
        if (arr2[i] == 1) {arr4[i] == 0;}
        else {arr4[i] == 1;}
    }
    arr4[31] += 1; 
    for (i = 31; i > -1; i--)
    {
        arr4[i] += arr[i] + arr4[i];
        if (arr4[i] >= 2)
        {
            arr4[i] %= 2;
            if (i != 0) 
            {
                arr4[i - 1] += 1;
            }
        }
    }
    for (i = 31; i > -1; i--)
    {
        arr3[i] = arr4[i];
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

void slt(int* arr, int* arr2, int* arr3)
{
    int arr4[32];
    for (i = 31; i > -1; i--)
    {
        arr4[i] = 0;
    }
    if (arr[0] > arr2[0])
    {
        arr4[31] = 1;
    }
    else if (arr[0] < arr2[0]);
    else if (arr[0] == 1)
    {
        for(i = 0; i < 32; i++)
        {
            if (arr[i] < arr2[i])
            {
                arr4[31] = 1;
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
                arr4[31] = 1;
                break;
            }
            else if (arr[i] > arr2[i])
            {
                break;
            }
        }
    }
    for (i = 31; i > -1; i--)
    {
        arr3[i] = arr4[i];
    }
}

void sltu(int* arr, int* arr2, int* arr3)
{
    int arr4[32];
    for (i = 31; i > -1; i--)
    {
        arr4[i] = 0;
    }
    for(i = 0; i < 32; i++)
    {
        if (arr[i] < arr2[i])
        {
            arr4[-1] = 1;
            break;
        }
        else if (arr[i] > arr2[i])
        {
            break;
        }
    }
    for (i = 31; i > -1; i--)
    {
        arr3[i] = arr4[i];
    }
}

void sll(int* arr, int* arr2, int num)
{
    if (num != 0)
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
}

void srl(int* arr, int* arr2, int num)
{
    if (num != 0)
    {
        for (i = 0; i < 32 - num; i++)
        {
            arr2[i + num] = arr[i];
        }
        for (i = 0; i < num; i++)
        {
            arr2[i] = 0;
        }
    }
}

void lui(int* arr, int* arr2)
{
    for(i = 0; i < 16; i++)
    {
        arr2[i] = arr[i + 16];
    }
    for(i = 16; i < 32; i++)
    {
        arr2[i] = 0;
    }
}

void bne(int* arr, int* arr2, int* pc, int* immd)
{
    int cnt = 0;
    for(i = 0; i < 32; i++)
    {
        if (arr[i] == arr2[i]){cnt++;}
    }
    if (cnt != 32)
    {
        sll(immd, immd, 2);
        add(immd, pc, pc);
    }
}

void beq(int* arr, int* arr2, int* pc, int* immd)
{
    int cnt = 0;
    for(i = 0; i < 32; i++)
    {
        if (arr[i] == arr2[i]){cnt++;}
    }
    if (cnt == 32)
    {
        sll(immd, immd, 2);
        add(immd, pc, pc);
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

void jal(int* immd, int* pc, int* ra)
{
    for(i = 0; i < 32; i++)
    {
        ra[i] = pc[i];
    }
    sll(immd, immd, 2);
    for(i = 4; i < 32; i++)
    {
        pc[i] = immd[i];
    }
}

void jr(int* arr, int* pc)
{
    for(i = 0; i < 32; i++)
    {
        pc[i] = arr[i];
    }
}

void lw(int* arr, int* arr2, int* immd, int* datalist)
{
    int* arr3 = (int*)malloc(32 * sizeof(int));
    add(immd, arr, arr3);
    //int value2 = signed_change(arr3);/////////////////////////
    add(arr3, decimal_to_binary(-268435456), arr3);
    int value = signed_change(arr3);
    //printf("주소 %08x 에 ", value2);////////////////////////////////////
    int data;
    for (i = 0; i < 4; i++)
    {
        data = datalist[value + i];
        //printf("%02x", data);////////////////////////////////
        for(j = 7; j >= 0; j--)
        {
            arr2[8*i + j] = data % 2;
            data /= 2;
        }
    }
    //printf(" 를 로드했습니다.\n");/////////////////////////////////////
}

void sw(int* arr, int* arr2, int* immd, int* datalist)
{
    int* arr3 = (int*)malloc(32 * sizeof(int));
    add(immd, arr, arr3);
    //int value2 = signed_change(arr3);//////////////////////////
    add(arr3, decimal_to_binary(-268435456), arr3);
    int value = signed_change(arr3);
    //printf("주소 %08x 에 ", value2);/////////////////////////////////
    for (i = 0; i < 4; i++)
    {
        int data = 0;
        for(j = 0; j < 8; j++)
        {
            data *= 2; 
            data += arr2[8*i + j];
        }
        datalist[value + i] = data;
        //printf("%02x", data);//////////////////////////////////
    }
    //printf(" 를 저장했습니다.");//////////////////////////////////
}

int issame(int* arr, int num)
{
    int a = signed_change(arr);
    if (a == num) {return 1;}
    else {return 0;}
}

void syscall(int* v0, int* a0, int* datalist)
{
    if(issame(v0, 1))
    {
        printf("%d", signed_change(a0));
    }
    else if(issame(v0, 4))
    {
        int* arr = (int*)malloc(32 * sizeof(int));
        add(a0, decimal_to_binary(-268435456), arr);
        int value = signed_change(arr);
        while((datalist[value] != -1) && (datalist[value] != 0))
        {
            printf("%c", datalist[value]);
            value++;
        }
    }
    else if(issame(v0, 5))
    {
        int value;
        scanf("%d", &value);
        int* arr = decimal_to_binary(value);
        for (i = 0; i < 32; i++)
        {
            v0[i] = arr[i];
        }
    }
}

int main(int argc, char *argv[])
{
    FILE* input;
    if ((input = fopen(argv[2], "rb")) == NULL)
    {
        fputs("Error : inst file doesn't open", stderr);
        exit(1);
    }

    int pc[32];
    int* four = decimal_to_binary(4);
    int hex;
    Register reglist[32];
    for (i = 0; i < 32; i++)
    {
        Register reg = create_register();
        reglist[i] = reg;
        pc[i] = 0;
    }

    int instlist[65537];
    int datalist[65537];
    memset(instlist, 0xFF, sizeof(instlist));
    memset(datalist, 0xFF, sizeof(datalist));
    i = 0;
    while ((hex = fgetc(input)) != EOF)
    {
        instlist[i] = hex;
        i++;
    }
    if (argc == 4)
    {
        FILE* input2;
        if ((input2 = fopen(argv[3], "rb")) == NULL)
        {
            fputs("Error : data file doesn't open", stderr);
            exit(1);
        }
        i = 0;
        while ((hex = fgetc(input2)) != EOF)
        {
            datalist[i] = hex;
            i++;
        }
        fclose(input2);
    }


    int cycle = 0;
    int pc_value = 0;
    int arr[32];
    while (cycle != atoi(argv[1]))
    {   
        int inst = instlist[pc_value];
        for(j = 7; j >= 0; j--)
        {
            arr[8*(pc_value % 4) + j] = inst % 2;
            inst /= 2;
        }
        pc_value++;
        if (pc_value % 4 == 0)
        {
            add(pc, four, pc);
            //printf("-----------------------------------------------------------");
            //printf("현재 pc value : %d\n", pc_value/4 - 1);
            int opcode = changeopcode(arr);
            int func = changefunc(arr);
            if (opcode == 0)
            {
                if (func == 32)
                {
                    //printf("add "); //print_rdrsrt(arr);
                    int rs = changeregister(arr, 0);
                    int rt = changeregister(arr, 1);
                    int rd = changeregister(arr, 2);
                    add(reglist[rs].arr, reglist[rt].arr, reglist[rd].arr);
                }
                else if (func == 33)
                {
                    //printf("addu "); //print_rdrsrt(arr);
                    int rs = changeregister(arr, 0);
                    int rt = changeregister(arr, 1);
                    int rd = changeregister(arr, 2);
                    add(reglist[rs].arr, reglist[rt].arr, reglist[rd].arr);
                }
                else if (func == 36)
                {
                    //printf("and "); //print_rdrsrt(arr);
                    int rs = changeregister(arr, 0);
                    int rt = changeregister(arr, 1);
                    int rd = changeregister(arr, 2);
                    and(reglist[rs].arr, reglist[rt].arr, reglist[rd].arr);
                }
                else if (func == 8)
                {
                    //printf("jr "); //print_rs(arr);
                    int rs = changeregister(arr, 0);
                    jr(reglist[rs].arr, pc);
                }
                else if (func == 39)
                {
                    //printf("nor "); //print_rdrsrt(arr);
                    int rs = changeregister(arr, 0);
                    int rt = changeregister(arr, 1);
                    int rd = changeregister(arr, 2);
                    nor(reglist[rs].arr, reglist[rt].arr, reglist[rd].arr);
                }
                else if (func == 37)
                {
                    //printf("or "); //print_rdrsrt(arr);
                    int rs = changeregister(arr, 0);
                    int rt = changeregister(arr, 1);
                    int rd = changeregister(arr, 2);
                    or(reglist[rs].arr, reglist[rt].arr, reglist[rd].arr);
                }
                else if (func == 0)
                {
                    //printf("sll "); //print_rdrtshamt(arr);
                    int rt = changeregister(arr, 1);
                    int rd = changeregister(arr, 2);
                    int shamt = changeregister(arr, 3);
                    sll(reglist[rt].arr, reglist[rd].arr, shamt);

                }
                else if (func == 42)
                {
                    //printf("slt "); //print_rdrsrt(arr);
                    int rs = changeregister(arr, 0);
                    int rt = changeregister(arr, 1);
                    int rd = changeregister(arr, 2);
                    slt(reglist[rs].arr, reglist[rt].arr, reglist[rd].arr);
                }
                else if (func == 43)
                {
                    //printf("sltu "); //print_rdrsrt(arr);
                    int rs = changeregister(arr, 0);
                    int rt = changeregister(arr, 1);
                    int rd = changeregister(arr, 2);
                    sltu(reglist[rs].arr, reglist[rt].arr, reglist[rd].arr);
                }
                else if (func == 2)
                {
                    //printf("srl "); //print_rdrtshamt(arr);
                    int rt = changeregister(arr, 1);
                    int rd = changeregister(arr, 2);
                    int shamt = changeregister(arr, 3);
                    srl(reglist[rt].arr, reglist[rd].arr, shamt);
                }
                else if (func == 34)
                {
                    //printf("sub "); //print_rdrsrt(arr);
                    int rs = changeregister(arr, 0);
                    int rt = changeregister(arr, 1);
                    int rd = changeregister(arr, 2);
                    sub(reglist[rs].arr, reglist[rt].arr, reglist[rd].arr);
                }
                else if (func == 35)
                {
                    //printf("subu "); //print_rdrsrt(arr);
                    int rs = changeregister(arr, 0);
                    int rt = changeregister(arr, 1);
                    int rd = changeregister(arr, 2);
                    sub(reglist[rs].arr, reglist[rt].arr, reglist[rd].arr);
                }
                else if (func == 12)
                {
                    //printf("syscall ");
                    syscall(reglist[2].arr, reglist[4].arr, datalist);
                }
                else if (func == 26)
                {
                    //printf("xor "); //print_rdrsrt(arr);
                    int rs = changeregister(arr, 0);
                    int rt = changeregister(arr, 1);
                    int rd = changeregister(arr, 2);
                    xor(reglist[rs].arr, reglist[rt].arr, reglist[rd].arr);
                }
                else 
                {
                    printf("unknown instruction\n");
                    break;
                }
            }
            else if (opcode == 8)
            {
                //printf("addi "); //print_rtrsimmed(arr);
                int rs = changeregister(arr, 0);
                int rt = changeregister(arr, 1);
                int* immd = sign_extension(arr, 16, 32);
                add(reglist[rs].arr, immd, reglist[rt].arr);
            }
            else if (opcode == 9)
            {
                //printf("addiu "); //print_rtrsimmed(arr);
                int rs = changeregister(arr, 0);
                int rt = changeregister(arr, 1);
                int* immd = sign_extension(arr, 16, 32);
                add(reglist[rs].arr, immd, reglist[rt].arr);
            }
            else if (opcode == 12)
            {
                //printf("andi "); //print_rtrsimmed(arr);
                int rs = changeregister(arr, 0);
                int rt = changeregister(arr, 1);
                int* immd = unsign_extension(arr, 16, 32);
                and(reglist[rs].arr, immd, reglist[rt].arr);
            }
            else if (opcode == 4)
            {
                //printf("beq "); //print_rsrtimmed(arr);
                int rs = changeregister(arr, 0);
                int rt = changeregister(arr, 1);
                int* immd = sign_extension(arr, 16, 32);
                beq(reglist[rs].arr, reglist[rt].arr, pc, immd);
            }
            else if (opcode == 5)
            {
                //printf("bne "); //print_rsrtimmed(arr);
                int rs = changeregister(arr, 0);
                int rt = changeregister(arr, 1);
                int* immd = sign_extension(arr, 16, 32);
                bne(reglist[rs].arr, reglist[rt].arr, pc, immd);
            } 
            else if (opcode == 15)
            {
                //printf("lui "); //printrtimmed(arr);
                int rt = changeregister(arr, 1);
                int* immd = sign_extension(arr, 16, 32);
                lui(immd, reglist[rt].arr);
            }
            else if (opcode == 35)
            {
                //printf("lw "); //print_rtrsimmed2(arr);
                int rs = changeregister(arr, 0);
                int rt = changeregister(arr, 1);
                int* immd = sign_extension(arr, 16, 32);
                lw(reglist[rs].arr, reglist[rt].arr, immd, datalist);
            }
            else if (opcode == 13)
            {
                //printf("ori "); //print_rtrsimmed(arr);
                int rs = changeregister(arr, 0);
                int rt = changeregister(arr, 1);
                int* immd = unsign_extension(arr, 16, 32);
                or(reglist[rs].arr, immd, reglist[rt].arr);
            }
            else if (opcode == 10)
            {
                //printf("slti "); //print_rtrsimmed(arr);
                int rs = changeregister(arr, 0);
                int rt = changeregister(arr, 1);
                int* immd = sign_extension(arr, 16, 32);
                slt(reglist[rs].arr, immd, reglist[rt].arr);
            }
            else if (opcode == 11)
            {
                //printf("sltiu "); //print_rtrsimmed(arr);
                int rs = changeregister(arr, 0);
                int rt = changeregister(arr, 1);
                int* immd = sign_extension(arr, 16, 32);
                sltu(reglist[rs].arr, immd, reglist[rt].arr);
            }
            else if (opcode == 43)
            {
                //printf("sw "); //print_rtrsimmed2(arr);
                int rs = changeregister(arr, 0);
                int rt = changeregister(arr, 1);
                int* immd = sign_extension(arr, 16, 32);
                sw(reglist[rs].arr, reglist[rt].arr, immd, datalist);
            }
            else if (opcode == 14)
            {
                //printf("xori "); //print_rtrsimmed(arr);
                int rs = changeregister(arr, 0);
                int rt = changeregister(arr, 1);
                int* immd = unsign_extension(arr, 16, 32);
                xor(reglist[rs].arr, immd, reglist[rt].arr);
            }
            else if (opcode == 2)
            {
                //printf("j "); //printaddress(arr);
                int* immd = sign_extension(arr, 28, 32);
                jump(immd, pc);
            }
            else if (opcode == 3)
            {
                //printf("jal "); //printaddress(arr);
                int rs = changeregister(arr, 0);
                int rt = changeregister(arr, 1);
                int* immd = sign_extension(arr, 28, 32);
                jal(immd, pc, reglist[31].arr);
            }
            else 
            {
                printf("unknown instruction\n");
                break;
            }
            //printf("\n");
            int reg_value;
            for (int i = 0; i < 32; i++)
            {
                reg_value = unsigned_change(reglist[i].arr);
                if (reg_value != 0)
                {
                    //printf("$%d: %08x\n", i, reg_value);
                }
            }

            cycle++;
            pc_value = unsigned_change(pc);
            //printf("\n");
        }
    }
    int reg_value;
    for (int i = 0; i < 32; i++)
    {
        reg_value = unsigned_change(reglist[i].arr);
        printf("$%d: 0x%08x\n", i, reg_value);
    }
    printf("PC : 0x%08x\n", pc_value);

    fclose(input);
    return 0;
}