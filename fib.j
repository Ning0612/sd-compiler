class fib
{
    method public static int itFibonacci(int)
    max_stack 31
    max_locals 31
    {
        ldc 0
        istore 1
        ldc 0
        istore 2
        ldc 0
        istore 3
        ldc 1
        istore 1
        ldc 1
        istore 2
WBegin0:
        nop
        iload 0
        ldc 2
        isub
        ifgt C0
        iconst_0
        goto C1
C0:
        iconst_1
C1:
        ifeq WEnd0
        iload 1
        istore 3
        iload 1
        iload 2
        iadd
        istore 1
        iload 3
        istore 2
        iload 0
        ldc 1
        isub
        istore 0
        goto WBegin0
WEnd0:
        nop
        iload 1
        ireturn
    }

    method public static void main(java.lang.String[])
    max_stack 31
    max_locals 31
    {
        getstatic java.io.PrintStream java.lang.System.out
        ldc "N: "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        getstatic java.io.PrintStream java.lang.System.out
        ldc 2
        invokevirtual void java.io.PrintStream.println(int)
        getstatic java.io.PrintStream java.lang.System.out
        ldc "Result of iterative computation:"
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        ldc 2
        invokestatic int itFibonacci(int)
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.println(int)
       return
    }

}
