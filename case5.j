class case5
{
    field static int k = 0
    method public static int isPrime(int)
    max_stack 31
    max_locals 31
    {
        iload 0
        ldc 1
        isub
        ifle C0
        iconst_0
        goto C1
C0:
        iconst_1
C1:
        ifeq FFalse0
        ldc 0
        ireturn
FFalse0:
        nop
        ldc 0
        istore 1
        ldc 2
        istore 1
ForBegin0:
        nop
        iload 1
        iload 1
        imul
        iload 0
        isub
        ifle C2
        iconst_0
        goto C3
C2:
        iconst_1
C3:
        ifeq ForEnd0
        iload 0
        iload 1
        irem
        ldc 0
        isub
        ifeq E0
        iconst_0
        goto E1
E0:
        iconst_1
E1:
        ifeq FFalse1
        ldc 0
        ireturn
FFalse1:
        nop
        iload 1
        ldc 1
        iadd
        istore 1
        goto ForBegin0
ForEnd0:
        nop
        ldc 1
        ireturn
    }

    method public static void main(java.lang.String[])
    max_stack 31
    max_locals 31
    {
        ldc 0
        istore 0
        ldc 0
        istore 1
        getstatic java.io.PrintStream java.lang.System.out
        ldc "Prime numbers up to "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        getstatic java.io.PrintStream java.lang.System.out
        ldc 30
        invokevirtual void java.io.PrintStream.println(int)
        ldc 2
        istore 0
ForBegin1:
        nop
        iload 1
        ldc 30
        isub
        iflt C4
        iconst_0
        goto C5
C4:
        iconst_1
C5:
        ifeq ForEnd1
        iload 0
        invokestatic int isPrime(int)
        ifeq FFalse2
        iload 0
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.print(int)
        getstatic java.io.PrintStream java.lang.System.out
        ldc " "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        iload 1
        ldc 1
        iadd
        istore 1
FFalse2:
        nop
        iload 0
        ldc 1
        iadd
        istore 0
        goto ForBegin1
ForEnd1:
        nop
        getstatic java.io.PrintStream java.lang.System.out
        ldc ""
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        getstatic int k
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.println(int)
       return
    }

}
