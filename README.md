# Compiler Design Lab Programs

## JNTUH R18 CSE

### Running Lex Programs

To execute Lex programs, use the following commands:

- Compile the Lex file:

```bash

lex file-name.l
```

- Compile the generated C file:

```bash
gcc lex.yy.c
```

- Run the resulting executable:

```bash
./a.out

```

### Running YACC Programs with Lex

To execute YACC programs in conjunction with Lex, use the following commands:

- Compile the Lex file:

```bash

lex file-name.l
```

- Compile the YACC file:

```bash
yacc -d file-name.y

````

- Compile the generated C files:

```bash
gcc lex.yy.c y.tab.c -w
```

- Run the resulting executable:

```bash
./a.out
```
