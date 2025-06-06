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
        ldc 0
        istore 1
        ldc 0
        istore 1
        goto F0
F1:
        iload 1
        ldc 10
        isub
        iflt C0
        iconst_0
        goto C1
C0:
        iconst_1
C1:
F0:
        ifeq F2
        iload 1
        ldc 1
        iadd
        istore 1
        iload 1
        getstatic java.io.PrintStream java.lang.System.out

        swap
        invokevirtual void java.io.PrintStream.print(int)
        getstatic java.io.PrintStream java.lang.System.out

        ldc " "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        goto F1
F2:
        getstatic java.io.PrintStream java.lang.System.out

        ldc ""
        invokevirtual void java.io.PrintStream.println(java.lang.String)
       return
    }

}
