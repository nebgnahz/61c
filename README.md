Intro to C
---

C is a general-purpose, imperative, static typed computer programming language,
supporting structured programming, lexical variable scope, recursion.

C is considered a high-level language in comparison to assembly (at its time,
~1970). Nowadays, it's very low level in comparison to Python/Java/Go.

You would also hear people referring C as a system programming language.

---
### Section Materials

- Section Materials: https://goo.gl/6pz7Xb
- C visualization: https://goo.gl/12juwA

---
### What we talk about when we talk about "C"

|      Year | Version | Standard               | Publication Date |
|      :--: | :--:    | :--:                   |             :--: |
| 1972-1989 | K&R     | n/a                    |       1978-02-22 |
| 1989-1990 | C89     | ANSI X3.159-1989       |       1989-12-14 |
| 1990-1995 | C90     | ISO/IEC 9899:1990      |       1990-12-20 |
| 1995-1999 | C95     | ISO/IEC 9899/AMD1:1995 |       1995-03-30 |
| 1999-2011 | C99     | ISO/IEC 9899:1999      |       1999-12-16 |
|  2011-now | C11     | ISO/IEC 9899:2011      |       2011-12-15 |

But only newer version compilers support C11. And on Hive, do `type gcc`.

```bash
$ type gcc
gcc is aliased to `gcc -Wall -ggdb3 -std=c99'
```

---
### Basic C "Hello World"

```c
#include <stdio.h>

int main() {
  printf("Hello World\n");
  return 0;
}
```

---
### Basic C Overview

- Types, Operators, Expressions (`int`, `char`, `int *`, ...)
- Control Flow (`if`, `else`, `switch`, `for`, `while`, `break`, `continue`, `goto`)
- Functions
- Pointers/Arrays
- User defined types: `Struct`, `Enum`, `typedef`
- I/O
- syscall
- CPP (preprocessor), `#define`, `#if`, `#ifndef`

---
### In-depth Topics

- Functions and Stack Frames
- Pointers/Arrays
- Heap

---
### Pointers


```c
int x = 3;
int *p = &x;
*p = 4;
```

---
### Function

Stack frames.

```c
void a() {}
void b() { a(); }
void c() { b(); }

int main() { c(); return 0; }
```

---
### Function Pointer

https://cdecl.org/

```
int (*fp) (void *, void *);
(*fp)(x, y);
```

declare fp as pointer to function (pointer to void, pointer to
void) returning int


----------------------------------------------------------------------------

## Better C

A set of actionable items to improve your C skills.

---
### Compilers (with warnings) are your friends

Add proper flags to the compilation process to detect potential bugs, e.g.
treating all warnings as errors. Check out [gcc
doc](https://gcc.gnu.org/onlinedocs/gcc/).

- `-Wall`, `-Wextra`, `-Wpedantic`
- `-Werror`

- `-g`, `-ggdb`

You can make more friends! `clang-tidy` and `clang-format`.

```
$ clang-tidy 1.pointer/pointer.c -- -I/usr/local/include
/intro-c/1.pointer/pointer.c:36:14: warning: cast to 'int *' from smaller integer type 'int'
    int* p = (int *) x;
             ^
/intro-c/1.pointer/pointer.c:30:45: warning: Pointer arithmetic done on non-array variables means reliance on memory layout, which is dangerous
    printf(" p: %p, (p + 1): %p\n", p, (p + 1));
                                            ^
/intro-c/1.pointer/pointer.c:30:45: note: Pointer arithmetic done on non-array variables means reliance on memory layout, which is dangerous
    printf(" p: %p, (p + 1): %p\n", p, (p + 1));
                                            ^
```

----------------------------------------------------------------------------
## "Esoteric" C

---
#### C Can be deep/dark

C is a simple language if you are experienced. Want a proof? See [Deep
C](https://www.slideshare.net/olvemaudal/deep-c).

```
int main() {
  int a = 42;
  printf("%d\n", a);
}
```

1. `include <stdio.h>` for `printf`
2. although it would work for gcc (with a warning)
3. Undefined return value
4. Being explicit? `main(void)`
5. C program ends with a newline


---
#### Multi-line String

```c
char *my_string = "Line 1 "
                  "Line 2";
```

---
#### Trigraphs

```c
  // Will the next line be executed????????????????/
  a++;
```

---
#### Good Practices writing better/modern C

- Use `stdint.h`
- Use `stdbool.h`
- Use `inttypes.h`
- Use `const`

---
#### Const

```
const char* const foo = "hello";
```

---
#### Macros & Preprocessor

```
cpp file.c
```

Good practice to `#undef` to facilitate reuse later on

---
## Resources and References

- [C gibberish <-> English](https://cdecl.org/)
- [How to C in 2016](https://matt.sh/howto-c), [HN](https://news.ycombinator.com/item?id=10864176)


<!-- links -->
