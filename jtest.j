class jtest
{
    method public static void main(java.lang.String[])
    max_stack 15
    max_locals 15
    {
        ldc 0
        istore 0
        ldc 0
        istore 1
        ldc 3
        istore 0
        ldc 0
        istore 1
        iload 1
        ldc 0
        isub
        ifeq E0
        iconst_0
        goto E1
E0:
        iconst_1
E1:
        ifeq FFalse0
        getstatic java.io.PrintStream java.lang.System.out
        ldc "i is zero"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        iload 0
        ldc 0
        isub
        ifeq E2
        iconst_0
        goto E3
E2:
        iconst_1
E3:
        ifeq FFalse1
        getstatic java.io.PrintStream java.lang.System.out
        ldc "d is zero"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        goto FExit0
FFalse1:
        nop
        iload 0
        ldc 0
        isub
        iflt C0
        iconst_0
        goto C1
C0:
        iconst_1
C1:
        ifeq FFalse2
        getstatic java.io.PrintStream java.lang.System.out
        ldc "d is negative"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        goto FExit1
FFalse2:
        nop
        getstatic java.io.PrintStream java.lang.System.out
        ldc "d is positive"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
FExit1:
        nop
FExit0:
        nop
        goto FExit2
FFalse0:
        nop
        iload 1
        ldc 0
        isub
        iflt C2
        iconst_0
        goto C3
C2:
        iconst_1
C3:
        ifeq FFalse3
        getstatic java.io.PrintStream java.lang.System.out
        ldc "i is negative"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        goto FExit3
FFalse3:
        nop
        getstatic java.io.PrintStream java.lang.System.out
        ldc "i is positive"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
FExit3:
        nop
FExit2:
        nop
WBegin0:
        nop
        iload 1
        ldc 10
        isub
        iflt C4
        iconst_0
        goto C5
C4:
        iconst_1
C5:
        ifeq WEnd0
        iload 1
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
        goto WBegin0
WEnd0:
        nop
        ldc 0
        istore 1
DBegin1:
        nop
        getstatic java.io.PrintStream java.lang.System.out
        ldc "try"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        iload 1
        ldc 1
        iadd
        istore 1
        iload 1
        ldc 3
        isub
        iflt C6
        iconst_0
        goto C7
C6:
        iconst_1
C7:
        ifne DBegin1
DEnd1:
        nop
        getstatic java.io.PrintStream java.lang.System.out
        ldc ""
        invokevirtual void java.io.PrintStream.println(java.lang.String)
       return
    }

}
