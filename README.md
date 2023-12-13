# Monty - Interpreter for Monty ByteCode Files

Monty is a scripting language interpreter designed for Monty ByteCode files, similar to Python bytecodes. It features a unique stack with specific instructions to manipulate it. This project aims to create an interpreter for Monty ByteCode files using C language.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Files](#files)
- [How to Contribute](#how-to-contribute)
- [License](#license)

## Introduction

Monty 0.98 is a scripting language compiled into Monty byte codes and relies on a unique stack with specific instructions to manipulate it. The project implements various opcodes to perform stack operations like push, pop, swap, add, pint, and nop.

## Installation

To get started with the Monty interpreter, follow these steps:

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/monty.git
    ```

2. Compile the source code using GCC:
    ```bash
    gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
    ```

## Usage

The Monty program operates as follows:

```bash
$ ./monty file
