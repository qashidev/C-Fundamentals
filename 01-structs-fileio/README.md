### 01: Structs & File I/O

Small C program practicing structs, string input handling, and basic file I/O.

---

**What it does**
- Defines a `User` struct (`name`, `age`)
- Prompts for a name and age via `fgets` / `scanf`, storing them in the struct
- Writes the user's details to a file (filename entered by the user)
- Reads the file back and prints its contents to stdout (standard output)

---

**Concepts practiced**
- `struct` definitions and passing structs by pointer
- `fgets` for safe string input, stripping newline
- `strcpy` into a fixed-size buffer (you cannot copy a string over by simply assigning it to the destination)
- Clearing leftover input from stdin after `scanf` (see bug note below)
- Basic file I/O: `fopen`, `fprintf`, `fgets`, `fclose`
- `NULL` checks on file pointers

---

**Bug found & fixed**

Original code tried to declare and initialize a variable inside a `while` condition:

```c
while ((int grb=getchar())!='\n' && grb!=EOF)
```

This isn't valid C: variable declarations aren't allowed inside a `while` condition.
Fixed by declaring the variable beforehand and just assigning inside the condition:

```c
int grb;
while ((grb=getchar())!='\n' && grb!=EOF){}
```

This is a standard idiom for flushing the leftover `\n` that `scanf("%d", ...)` leaves in the input buffer,
which would otherwise get picked up by the next `fgets` call which is a big nono!

---

**Build & run**
```bash
gcc -Wall -Wextra -o out.bin main.c
./out.bin
```
