class case4
{
    method public static void main(java.lang.String[])
    max_stack 31
    max_locals 31
    {
        ldc 0
        istore 0
        ldc 0
        istore 1
        ldc 0
        istore 2
        ldc 9
        istore 0
        iload 0
        istore 3
        ldc 0
        istore 1
        iload 1
        iload 3
        isub
        iflt ForEachDelta0
        ldc -1
        goto ForEachDelta1
ForEachDelta0:
        ldc 1
ForEachDelta1:
        nop
        istore 4
ForEachBegin0:
        nop
        iload 4
        ifgt ForEachCheckDesc0
        iload 1
        iload 3
        isub
        iflt ForEachEnd0
        goto ForEachStatement0
ForEachCheckDesc0:
        iload 1
        iload 3
        isub
        ifgt ForEachEnd0
ForEachStatement0:
        nop
        iload 1
        istore 5
        ldc 0
        istore 2
        iload 2
        iload 5
        isub
        iflt ForEachDelta2
        ldc -1
        goto ForEachDelta3
ForEachDelta2:
        ldc 1
ForEachDelta3:
        nop
        istore 6
ForEachBegin1:
        nop
        iload 6
        ifgt ForEachCheckDesc2
        iload 2
        iload 5
        isub
        iflt ForEachEnd1
        goto ForEachStatement1
ForEachCheckDesc2:
        iload 2
        iload 5
        isub
        ifgt ForEachEnd1
ForEachStatement1:
        nop
        iload 1
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.print(int)
        getstatic java.io.PrintStream java.lang.System.out
        ldc " "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        iload 2
        iload 6
        iadd
        istore 2
        goto ForEachBegin1
ForEachEnd1:
        nop
        getstatic java.io.PrintStream java.lang.System.out
        ldc ""
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        iload 1
        iload 4
        iadd
        istore 1
        goto ForEachBegin0
ForEachEnd0:
        nop
       return
    }

}
