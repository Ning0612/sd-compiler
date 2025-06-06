class case3
{
    method public static void main(java.lang.String[])
    max_stack 31
    max_locals 31
    {
        ldc 0
        istore 0
        ldc 0
        istore 1
DBegin0:
        nop
        iload 0
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.print(int)
        getstatic java.io.PrintStream java.lang.System.out
        ldc " "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        iload 0
        ldc 1
        iadd
        istore 0
        iload 0
        ldc 9
        isub
        iflt C0
        iconst_0
        goto C1
C0:
        iconst_1
C1:
        ifne DBegin0
DEnd0:
        nop
        ldc 0
        istore 0
ForBegin0:
        nop
        iload 0
        ldc 9
        isub
        iflt C2
        iconst_0
        goto C3
C2:
        iconst_1
C3:
        ifeq ForEnd0
        iload 0
        ldc 1
        iadd
        istore 0
        ldc 0
        istore 1
ForBegin1:
        nop
        iload 1
        ldc 9
        isub
        iflt C4
        iconst_0
        goto C5
C4:
        iconst_1
C5:
        ifeq ForEnd1
        iload 0
        iload 1
        iadd
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.print(int)
        getstatic java.io.PrintStream java.lang.System.out
        ldc " "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        iload 1
        ldc 1
        iadd
        istore 1
        goto ForBegin1
ForEnd1:
        nop
        getstatic java.io.PrintStream java.lang.System.out
        ldc ""
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        goto ForBegin0
ForEnd0:
        nop
        ldc 0
        istore 0
        ldc 0
        istore 1
ForBegin2:
        nop
        iload 0
        ldc 9
        isub
        iflt C6
        iconst_0
        goto C7
C6:
        iconst_1
C7:
        ifeq ForEnd2
        iload 0
        iload 1
        iadd
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.print(int)
        getstatic java.io.PrintStream java.lang.System.out
        ldc " "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        iload 0
        ldc 1
        iadd
        istore 0
        iload 1
        ldc 1
        iadd
        istore 1
        goto ForBegin2
ForEnd2:
        nop
        getstatic java.io.PrintStream java.lang.System.out
        ldc ""
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        ldc 9
        istore 2
        ldc 0
        istore 0
        iload 0
        iload 2
        isub
        iflt ForEachDelta0
        ldc -1
        goto ForEachDelta1
ForEachDelta0:
        ldc 1
ForEachDelta1:
        nop
        istore 3
ForEachBegin3:
        nop
        iload 3
        ifgt ForEachCheckDesc0
        iload 0
        iload 2
        isub
        iflt ForEachEnd3
        goto ForEachStatement3
ForEachCheckDesc0:
        iload 0
        iload 2
        isub
        ifgt ForEachEnd3
ForEachStatement3:
        nop
        iload 0
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.print(int)
        getstatic java.io.PrintStream java.lang.System.out
        ldc " "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        iload 0
        iload 3
        iadd
        istore 0
        goto ForEachBegin3
ForEachEnd3:
        nop
        getstatic java.io.PrintStream java.lang.System.out
        ldc ""
        invokevirtual void java.io.PrintStream.println(java.lang.String)
        ldc 60
        istore 2
        ldc -90
        istore 0
        iload 0
        iload 2
        isub
        iflt ForEachDelta2
        ldc -1
        goto ForEachDelta3
ForEachDelta2:
        ldc 1
ForEachDelta3:
        nop
        istore 3
ForEachBegin4:
        nop
        iload 3
        ifgt ForEachCheckDesc2
        iload 0
        iload 2
        isub
        iflt ForEachEnd4
        goto ForEachStatement4
ForEachCheckDesc2:
        iload 0
        iload 2
        isub
        ifgt ForEachEnd4
ForEachStatement4:
        nop
        iload 0
        getstatic java.io.PrintStream java.lang.System.out
        swap
        invokevirtual void java.io.PrintStream.print(int)
        getstatic java.io.PrintStream java.lang.System.out
        ldc " "
        invokevirtual void java.io.PrintStream.print(java.lang.String)
        iload 0
        iload 3
        iadd
        istore 0
        goto ForEachBegin4
ForEachEnd4:
        nop
        getstatic java.io.PrintStream java.lang.System.out
        ldc ""
        invokevirtual void java.io.PrintStream.println(java.lang.String)
       return
    }

}
