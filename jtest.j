class jtest
{
    field static int d = 432
    field static int dw = 0
    field static int global_B = 10
    field static int global_A = 5
    method public static int add(int, int)
    max_stack 15
    max_locals 15
    {
        ldc 40
        ireturn
    }

    method public static void pp(int)
    max_stack 15
    max_locals 15
    {
        getstatic java.io.PrintStream java.lang.System.out

        ldc "rwerw"
        invokevirtual void java.io.PrintStream.print(java.lang.String)
       return
    }

    method public static void main(java.lang.String[])
    max_stack 15
    max_locals 15
    {
        ldc 10
        istore 0
        ldc 20
        istore 1
        ldc 30
        istore 2
        ldc 0
        istore 3
        iload 0
        ldc 1
        iadd
        istore 0
        iload 0
        iload 0
        ldc 1
        iadd
        istore 0
        iload 0
        iload 1
        iadd
        istore 3
        iload 0
        getstatic java.io.PrintStream java.lang.System.out

        swap
        invokevirtual void java.io.PrintStream.println(int)
        iload 3
        getstatic java.io.PrintStream java.lang.System.out

        swap
        invokevirtual void java.io.PrintStream.println(int)
        ldc 0
        istore 4
       return
    }

}
