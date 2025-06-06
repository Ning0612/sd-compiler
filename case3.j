class case3
{
    method public static void main(java.lang.String[])
    max_stack 31
    max_locals 31
    {
        ldc 3
        istore 0
        iload 0
        ldc 5
        isub
        ifgt C0
        iconst_0
        goto C1
C0:
        iconst_1
C1:
        ifeq FFalse0
        getstatic java.io.PrintStream java.lang.System.out
        ldc "a is greater than 5"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        goto FExit0
FFalse0:
        nop
        iload 0
        ldc 5
        isub
        ifeq E0
        iconst_0
        goto E1
E0:
        iconst_1
E1:
        ifeq FFalse1
        getstatic java.io.PrintStream java.lang.System.out
        ldc "a is equal to 5"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        goto FExit1
FFalse1:
        nop
        getstatic java.io.PrintStream java.lang.System.out
        ldc "a is less than 5"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
FExit1:
        nop
FExit0:
        nop
       return
    }

}
