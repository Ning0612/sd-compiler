# sD Compiler

Complete compiler coursework project for **sD**, a C-like teaching language. The compiler covers lexical analysis, parsing, semantic analysis, and Java Assembly code generation.

> Course project, cleaned public version. This repository is presented as an academic-scale compiler implementation, not a production compiler or optimizing compiler.

## Pipeline

```
sD source (.sd)
  -> scanner (flex)
  -> parser (yacc/bison)
  -> semantic analysis
  -> Java Assembly (.j)
  -> JVM class file via javaa-compatible assembler
```

## Project Structure

```
.
├── Makefile
├── src/                  # scanner, parser, semantic analyzer, code generator
├── input/                # small self-contained sample programs
└── javaaPortable/        # Java Assembly tooling; third-party historical bundle with preserved notices
```

Generated files such as `y.output`, object files, and submission archives should not be committed in the public version.

## Build

```bash
make
```

Run the compiler on a sample program:

```bash
./bin/sd input/case1.sd
```

This produces a Java Assembly file such as `case1.j`. Assemble and run it with the Java Assembly tool:

```bash
./javaaPortable/javaa case1.j
java case1
```

or use the provided shortcut:

```bash
make test-java TEST=case1
```

## Language Snapshot

### Basic Types

- `int`, `float`
- `bool`
- string constants for `print` / `println`

### Statements

- variable and constant declarations
- assignment
- `if`, `if-else`
- `while`, `do-while`, `for`, `foreach`
- `print`, `println`
- `return`

### Expressions

- arithmetic: `+`, `-`, `*`, `/`, `%`
- logic: `!`, `&&`, `||`
- comparisons: `<`, `>`, `<=`, `>=`, `==`, `!=`
- constant folding for compile-time expressions

### Functions

- typed parameters
- return type checks
- function call validation
- integer and `void` returns

## Grammar Summary

This is a compact overview of the implemented language shape, not a replacement for the yacc grammar in `src/p3_parser.y`.

```bnf
program        ::= { declaration | function }
declaration    ::= ("var" | "const") type identifier [ "=" expression ] ";"
function       ::= type identifier "(" [ parameters ] ")" block
parameters     ::= parameter { "," parameter }
parameter      ::= type identifier
block          ::= "{" { declaration | statement } "}"
statement      ::= assignment ";"
                 | if_statement
                 | while_statement
                 | do_while_statement
                 | for_statement
                 | foreach_statement
                 | print_statement ";"
                 | return_statement ";"
assignment     ::= identifier "=" expression
expression     ::= literal
                 | identifier
                 | function_call
                 | unary_operator expression
                 | expression binary_operator expression
```

## Example

sD source:

```c
var int x = 5;

int main() {
    println(x + 1);
    return 0;
}
```

Representative Java Assembly shape:

```asm
field static int x
method public static int main()
    getstatic int example.x
    sipush 1
    iadd
    invokevirtual void java/io/PrintStream/println(int)
    sipush 0
    ireturn
```

Exact generated labels and class names depend on the input file and code-generation path.

## Sample Inputs

The `input/` directory contains small programs for exercising semantic analysis and code generation:

| File | Focus |
|---|---|
| `case1.sd` | integer arithmetic, comparison, constant folding |
| `case2.sd` | string constants and `print` / `println` |
| `case3.sd` | nested `if` / `else if` / `else` control flow |
| `case4.sd` | `foreach` syntax and variable scope |
| `case5.sd` | prime-number loop with boolean logic |
| `case6.sd` | `do-while` code generation |
| `case7.sd` | function calls and recursion |
| `case8.sd` | mixed declarations, control flow, and functions |

## Limitations

- Teaching-language implementation; not an optimizing compiler.
- No production-grade runtime, diagnostics framework, or incremental compilation.
- String support is limited to constants used in output statements.
- Array and `read` support are not part of the current code-generation path.

## License Boundary

This repository uses the MIT License for the original `sd-compiler` coursework
source code written for this project.

`javaaPortable/` is preserved only as historical third-party tooling needed to
assemble generated Java Assembly output. It retains its own upstream copyright
notices, and its redistribution license has not been fully verified. Do not
assume the repository-level MIT License covers `javaaPortable/`.

For any redistribution beyond viewing or reproducing the coursework locally,
the conservative option is to remove `javaaPortable/` and document an external
download or local build step instead. See [THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

## Attribution

Developed as compiler coursework in the Department of Computer Science and Information Engineering, National Taiwan University of Science and Technology, Spring 2025.

Author: Ning (Cheng-Ning Wang)
