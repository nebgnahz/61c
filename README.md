Intro to RISC-V
---

----

### Tools

In Lab 3, you are introduced to Venus: http://www.kvakil.me/venus/. Venus is
easy to use but somewhat limited (it is meant for education anyway).

In addition to Venus, you can setup your own RISC-V toolchain to explore the
compiler.

https://github.com/riscv/riscv-tools

---

If compiling code from source is hard for you, you can use this compiler explorer:
https://cx.rv8.io/

![Compiler Explorer](./images/compiler_explorer.png)

---
### Optimization Levels

Level 0: `-O0`

```c
void x() {
}
```

```assembly
x():
  addi sp,sp,-16
  sw s0,12(sp)
  addi s0,sp,16
  nop
  lw s0,12(sp)
  addi sp,sp,16
  jr ra
```

Level 1/2/3: `-O1`, `-O2`, `-O3`.

```c
void x() {
}
```

```assembly
x():
  ret
```

### Simple Functions

```c
int double_(int x) {
    return x + x;
}
```

```assembly
double_(int):
  slli a0,a0,1
  ret
```


```c
int condition(int x) {
    if (x) {
        return 3;
    } else {
        return 5;
    }
}
```

```assembly
condition(int):
  bnez a0,.L3
  li a0,5
  ret
.L3:
  li a0,3
  ret
```

```c
int condition(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += i;
    }
    return sum;
}
```

```assembly
condition(int):
  blez a0,.L4
  li a5,0
  li a4,0
.L3:
  add a4,a4,a5
  addi a5,a5,1
  bne a0,a5,.L3
.L1:
  mv a0,a4
  ret
.L4:
  li a4,0
  j .L1
```

#### More

```
int ultimate_question(int a0, int a1, int a2, int a3,
                      int a4, int a5, int a6, int a7,
                      int a8, int a9) {
    int x = a0 + a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9;
    return x;
}

int main() {
    return ultimate_question(0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
}
```

#### Section Materials

Write assembly friendly C.

```c
int power(int x, int n) {
    int ret = 1;
    for (int i = 0; i < n; i++) {
        ret = ret * n;
    }
    return ret;
}
```

```c
int power(int a0 /* x */, int a1 /* n */) {
    int t0 = 0;
    int t1 = a0;
    int a0 = 1;
    while (!(t0 >= a1)) {
        a0 = a0 * t1;
        t0++;
    }
    return a0;
}
```

```assembly
power: li   t0, 0       # t0 = 0
       addi t1, a0, 0   # t1 = a0
       addi a0, x0, 1   # a0 = 1
loop:  bge  t0, a1, end # end the loop if t0 >= a1 (n)
       mul  a0, a0, t1  # a0 = a0 * t1
       addi t0, t0, 1   # t0 = t0 + 1
       jal  x0, loop    # Jump back to the while condition
end:   jr ra            # Return to caller
```

#### Assembler / Linker / Loader / Go

Use examples in [multifiles](multifiles).

```
.
├── Makefile
├── add.c
├── add.h
├── main.c
├── mul.c
├── mul.h
├── sub.c
└── sub.h
```

```make
# CC=gcc -O0
# AR=ar
CC=/opt/riscv/toolchain/bin/riscv64-unknown-elf-gcc
AR=/opt/riscv/toolchain/bin/riscv64-unknown-elf-ar
```

```c
// add.h
int add(int a, int b);

// add.c
int add(int a, int b) {
    return a + b;
}
```

```c
// main.c
#include <stdio.h>

#include "add.h"
#include "sub.h"
#include "mul.h"

int main() {
    printf("1 + 1 = %d\n", add(1, 1));
    printf("2 - 1 = %d\n", sub(2, 1));
    printf("2 * 1 = %d\n", mul(2, 1));
    return 0;
}
```


```
$ rv-bin dump -a add.o
$ rv-sim main
```

--------------

- [C](c.md)
- [RISC-V](riscv.md)
