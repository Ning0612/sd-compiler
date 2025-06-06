class case1
{
    method public static void main(java.lang.String[])
    max_stack 31
    max_locals 31
    {
        ldc 0.000000f
        fstore 0
        ldc 0.000000f
        fstore 1
        ldc 0.000000f
        fstore 2
        ldc 1.500000f
        fstore 0
        ldc 2.500000f
        fstore 1
        fload 0
        fload 1
        fadd
        fstore 2
        getstatic java.io.PrintStream java.lang.System.out
        ldc "a = "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        fload 0
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.println(float)
        getstatic java.io.PrintStream java.lang.System.out
        ldc "b = "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        fload 1
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.println(float)
        getstatic java.io.PrintStream java.lang.System.out
        ldc "Sum of a and b = "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        fload 0
        fload 1
        fadd
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.print(float)
        getstatic java.io.PrintStream java.lang.System.out
        ldc "Difference of a and b = "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        fload 0
        fload 1
        fsub
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.println(float)
        getstatic java.io.PrintStream java.lang.System.out
        ldc "Product of a and b = "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        fload 0
        fload 1
        fmul
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.println(float)
        getstatic java.io.PrintStream java.lang.System.out
        ldc "Quotient of a and b = "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        fload 0
        fload 1
        fdiv
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.println(float)
        getstatic java.io.PrintStream java.lang.System.out
        ldc "a > b: "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        fload 0
        fload 1
        fcmpl
        ifgt C0
        iconst_0
        goto C1
C0:
        iconst_1
C1:
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.println(boolean)
        getstatic java.io.PrintStream java.lang.System.out
        ldc "a < b: "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        fload 0
        fload 1
        fcmpl
        iflt C2
        iconst_0
        goto C3
C2:
        iconst_1
C3:
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.println(boolean)
       return
    }

}
