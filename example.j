class example
{
    field static int a = 10
    method public static int add(int, int)
    max_stack 31
    max_locals 31
    {
        iload 0
        iload 1
        iadd
        ireturn
    }

    method public static void main(java.lang.String[])
    max_stack 31
    max_locals 31
    {
        ldc 0
        istore 0
        ldc 5
        putstatic int example.a
        getstatic int example.a
        ldc 10
        invokestatic int example.add(int, int)
        istore 0
        iload 0
        ldc 10
        isub
        ifgt C0
        iconst_0
        goto C1
C0:
        iconst_1
C1:
        ifeq FFalse0
        iload 0
        ineg
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.print(int)
        goto FExit0
FFalse0:
        nop
        iload 0
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.print(int)
FExit0:
        nop
        getstatic java.io.PrintStream java.lang.System.out
        ldc "Hello World"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
       return
    }

}
