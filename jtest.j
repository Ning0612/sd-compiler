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
        ldc -3
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
        ifeq LFalse0
        getstatic java.io.PrintStream java.lang.System.out

        ldc "i is zero"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        goto LExit0
LFalse0:
        nop
        iload 1
        ldc 0
        isub
        iflt C0
        iconst_0
        goto C1
C0:
        iconst_1
C1:
        ifeq LFalse1
        getstatic java.io.PrintStream java.lang.System.out

        ldc "i is negative"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        goto LExit1
LFalse1:
        nop
        getstatic java.io.PrintStream java.lang.System.out

        ldc "i is positive"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
LExit1:
        nop
LExit0:
        nop
        getstatic java.io.PrintStream java.lang.System.out

        ldc ""
        invokevirtual void java.io.PrintStream.println(java.lang.String)
       return
    }

}
