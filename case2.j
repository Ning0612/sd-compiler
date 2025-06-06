class case2
{
    method public static int add(int, int)
    max_stack 31
    max_locals 31
    {
        iload 0
        iload 1
        iadd
        ireturn
    }

    method public static float multiply(float, float)
    max_stack 31
    max_locals 31
    {
        fload 0
        fload 1
        fmul
        freturn
    }

    method public static void main(java.lang.String[])
    max_stack 31
    max_locals 31
    {
        ldc 5
        istore 0
        ldc 10
        istore 1
        ldc 2.500000f
        fstore 2
        ldc 4.000000f
        fstore 3
        ldc 0
        istore 4
        ldc 0.000000f
        fstore 5
        iload 0
        iload 1
        invokestatic int add(int, int)
        istore 4
        ldc 0.000000f
        fstore 6
        fload 2
        fload 3
        invokestatic float multiply(float, float)
        fstore 6
        getstatic java.io.PrintStream java.lang.System.out
        ldc "Product: "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        fload 6
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.println(float)
       return
    }

}
