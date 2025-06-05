class jtest
{
    field static int d = 432
    field static int dw = 0
    field static int ga = 34
    method public static int add(int, int)
    max_stack 15
    max_locals 15
    {
        sipush 40
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
        sipush 3445
        istore 0
        sipush 24
        istore 1
        sipush 0
        istore 2
        getstatic java.io.PrintStream java.lang.System.out

        ldc "Hello World !"
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        ldc 0.000000f
        fstore 3
        iload 0
        sipush 1
        iadd
        istore 0
        getstatic int ga
        sipush 1
        iadd
        putstatic int ga
        getstatic java.io.PrintStream java.lang.System.out

        ldc 37.400002f
        invokevirtual void java.io.PrintStream.println(float)
        getstatic int ga
        getstatic java.io.PrintStream java.lang.System.out

        swap
        invokevirtual void java.io.PrintStream.println(int)
        sipush 34
        istore 4
       return
    }

}
