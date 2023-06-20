<h1 align="center">Monty</h1>

<p align="center">
  A simple interpreter for a subset of the Monty language.
</p>

<p align="center">
  <a href="#installation">Installation</a> •
  <a href="#usage">Usage</a> •
  <a href="#language-specification">Language Specification</a> •
  <a href="#contributing">Contributing</a> •
</p>

---

## Introduction

Monty is an interpreter for a subset of the Monty language. It reads Monty bytecode files and executes the commands within them.

## Installation

To install and run Monty, follow these steps:

1. Clone the repository:

   ```bash
   git clone https://github.com/zrdouane/monty.git
   ```

2. Change to the project directory:

   ```bash
   cd monty
   ```

3. Compile the source code:

   ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
   ```

4. Run Monty with a Monty bytecode file:

   ```bash
   ./monty bytecodes/06.m 
   ```

   Note: The provided `Makefile` can also be used to compile the source code.

## Usage

Monty accepts Monty bytecode files as input. These files contain Monty commands, one per line. Here's an example of a Monty bytecode file:

```
push 1
push 2
add
pall
```

This file pushes two values onto the stack, adds them together, and then prints the contents of the stack.

To run Monty, use the following command:

```bash
./monty <filename>
```

Replace `<filename>` with the path to the Monty bytecode file you want to execute.

## Language Specification

Monty supports a subset of the Monty language commands. Refer to the [Monty Language Specification](docs/language-specification.md) for details on the supported commands and their usage.

## Contributing

Contributions to Monty are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request on the GitHub repository.

---

<p align="center">
  Made with ❤️ by zrdouane
</p>
