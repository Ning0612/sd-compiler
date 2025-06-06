class case1
{
    method public static void main(java.lang.String[])
    max_stack 31
    max_locals 31
    {
        ldc 1
        istore 0
        iload 0
        ldc 1
        isub
        ifeq E0
        iconst_0
        goto E1
E0:
        iconst_1
E1:
        ifeq FFalse0
        goto FExit0
FFalse0:
        nop
        iload 0
        ldc 2
        isub
        ifeq E2
        iconst_0
        goto E3
E2:
        iconst_1
E3:
        ifeq FFalse1
        goto FExit1
FFalse1:
        nop
        iload 0
        ldc 3
        isub
        ifeq E4
        iconst_0
        goto E5
E4:
        iconst_1
E5:
        ifeq FFalse2
        goto FExit2
FFalse2:
        nop
        iload 0
        ldc 4
        isub
        ifeq E6
        iconst_0
        goto E7
E6:
        iconst_1
E7:
        ifeq FFalse3
        goto FExit3
FFalse3:
        nop
        iload 0
        ldc 5
        isub
        ifeq E8
        iconst_0
        goto E9
E8:
        iconst_1
E9:
        ifeq FFalse4
        ldc 7
        istore 1
        ldc 0
        istore 2
FFalse4:
        nop
FExit3:
        nop
FExit2:
        nop
FExit1:
        nop
FExit0:
        nop
       return
    }

}
