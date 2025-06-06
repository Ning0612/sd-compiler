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
        iload 1
        ldc 0
        isub
        ifeq E0
        iconst_0
        goto E1
E0:
        iconst_1
E1:
        ifeq I0
        getstatic java.io.PrintStream java.lang.System.out

        ldc "i is zero"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        goto I1
I0:
        iload 1
        ldc 0
        isub
        iflt C0
        iconst_0
        goto C1
C0:
        iconst_1
C1:
        ifeq I2
        getstatic java.io.PrintStream java.lang.System.out

        ldc "i is negative"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        goto I3
I2:
        getstatic java.io.PrintStream java.lang.System.out

        ldc "i is positive"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
I3:
I1:
        getstatic java.io.PrintStream java.lang.System.out

        ldc ""
        invokevirtual void java.io.PrintStream.println(java.lang.String)
       return
    }

}
