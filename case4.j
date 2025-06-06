class case4
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

    method public static void main(java.lang.String[])
    max_stack 31
    max_locals 31
    {
        ldc 0
        istore 0
        ldc 10
        istore 1
        ldc 1
        istore 0
        iload 0
        iload 1
        isub
        iflt ForEachDelta0
        ldc -1
        goto ForEachDelta1
ForEachDelta0:
        ldc 1
ForEachDelta1:
        nop
        istore 2
ForEachBegin0:
        nop
        iload 2
        ifgt ForEachCheckDesc0
        iload 0
        iload 1
        isub
        iflt ForEachEnd0
        goto ForEachStatement0
ForEachCheckDesc0:
        iload 0
        iload 1
        isub
        ifgt ForEachEnd0
ForEachStatement0:
        nop
        iload 0
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.print(int)
        getstatic java.io.PrintStream java.lang.System.out
        ldc " "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        iload 0
        iload 2
        iadd
        istore 0
        goto ForEachBegin0
ForEachEnd0:
        nop
        getstatic java.io.PrintStream java.lang.System.out
        ldc ""
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        ldc 0
        istore 3
        iload 0
        ldc 1
        iadd
        istore 0
        iload 0
        ldc 1
        iadd
        istore 0
        iload 0
        istore 3
        ldc 3
        ldc 5
        invokestatic int add(int, int)
        istore 3
       return
    }

}
