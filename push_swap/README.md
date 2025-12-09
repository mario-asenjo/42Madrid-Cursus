# push_swap

## Description

`push_swap` is a 42 project to sort a stack of integers using **two stacks** (`a` and `b`) and a limited set of instructions.  

The program:
- Receives a list of integers as arguments.
- Validates and stores them in stack **a**.
- Outputs to **stdout** a sequence of operations that will sort stack **a**.

The project includes:
- **Mandatory part**: `push_swap` — generates the sequence of stack operations.
- **Bonus part**: `checker` — reads operations from **stdin**, reads unordered numbers from **args**, applies them, and checks if the result is correctly sorted.

---

## Instructions

### Requirements

- C compiler (e.g. `cc` / `gcc`)
- `make`
- The included `libft`, `ft_printf` and `get_next_line` libraries

### Compilation

**Mandatory program:**

```bash
make
```

Builds the `push_swap` binary.

**Bonus checker:**

```bash
make bonus
```

Builds the `checker` bonus binary.

Clean targets:

```bash
make clean    # remove object files
make fclean   # remove objects and binaries/libraries
make re       # full rebuild
```

### Execution

**push_swap**

```bash
./push_swap <numbers...>
```

Examples:

```bash
./push_swap 2 1 3
./push_swap "3 2 1 4 5"
```

The program prints one operation per line (`sa`, `pb`, `ra`, etc.).

**checker** (bonus)

```bash
./checker <numbers...>
```

Then type operations on stdin (one per line) and send EOF (`Ctrl+D`), or pipe from another program:

```bash
ARG="3 2 1 6 5 4"
./push_swap $ARG | ./checker $ARG
```

The checker prints `OK` if stack **a** is sorted and stack **b** is empty, or `KO` otherwise.

---

## Resources

Some useful references related to the project:

- 42 subject PDF for `push_swap`.
- Libraries developed by myself during the process of 42Common-Core in C language.
- Basic data structures and algorithms research.

### Use of AI

AI was used as a support tool to:

- Refine the chosen sorting strategy for large inputs.
- Help review edge cases, errors, and documentation wording.

All code was written, integrated, and debugged by myself, with AI used only as guidance and for concept clarification.
