# libft – C Utility Library

![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)
![Language: C](https://img.shields.io/badge/language-C-blue.svg)
![Made at 42/Hive](https://img.shields.io/badge/made%20at-42%20Hive-blueviolet)
[![GitHub Repo](https://img.shields.io/badge/GitHub-libft-black?logo=github)](https://github.com/nicolas-lovis/libft)

> A modular C library built from scratch during 42/Hive School.

[🔗 View on GitHub](https://github.com/to0nsa/libft)
**[📚 View full documentation](https://to0nsa.github.io/libft/)**

This C library was developed during my training at **42/Hive School** and has grown over time into a practical, reusable toolkit. It includes a wide range of utilities for **string, array, 2Darray** manipulation, **memory management**, **data structures**, **math**, and **custom I/O** — all written from scratch in C.

By reimplementing core functions like `printf` and `qsort`, I deepened my understanding of **low-level programming**, **pointer logic**, and **performance optimization**. Each function was added to solve real challenges I encountered, helping me develop a strong foundation in writing **robust**, **readable**, **reusable** and **maintainable** code.

Special care was given to **error handling**, **code clarity**, **project structure** and **building documentation**. The library is organized, well-documented, and designed for **portability** across UNIX-like systems.

In addition to replicating standard behaviors, Libft introduces **custom tools** not found in the C standard library — giving **greater flexibility** and **control** in real-world use cases. It promotes **code reusability** and can be easily integrated into new or existing C projects.

---

## Libft Features

<details>
<summary><strong>see features</strong></summary>

Libft is a foundational C library that offers a comprehensive toolkit for low-level programming. It emphasizes **performance**, **reliability**, and **clarity**, making it a solid base for building larger software systems.

**🔐 Memory-Safe Operations**
All functions are implemented with a strong focus on memory safety. This includes careful handling of buffer boundaries, null-terminated strings, and dynamic memory allocation to prevent common pitfalls like buffer overflows or memory leaks.

**⚠️ Consistent Error Handling**
Functions gracefully handle edge cases and failure scenarios, such as null inputs or allocation errors. Return values are designed to be predictable and easily checkable, reducing the risk of undefined behavior.

**🛡️ Defensive Design**
Every function is built to fail safely. This defensive approach ensures that developers can integrate Libft into their codebases without introducing instability or hidden bugs.

**📘 Solid Documentation**
Each module is thoroughly documented using Doxygen, with clear descriptions, usage guidelines, and grouping by functionality. This makes the library easy to navigate, understand, and maintain—even as it grows in complexity.

**🧪 Tested and Modular**
Each component of the library is modular, making it easy to maintain, extend, or integrate into larger projects. The code follows clear conventions to support readability and maintainability.

**📚 Educational and Practical**
Originally designed as an educational exercise, Libft serves both as a learning tool and a practical foundation for writing robust C programs without relying on the standard library in constrained environments.

<details>
<summary><strong>📚 String</strong></summary>


- **Memory Safety**: Functions like `ft_strcpy`, `ft_strdup`, and `ft_strcat` ensure safe copying, avoiding buffer overflows or unintentional memory corruption.
- **Error Handling**: Most functions, especially those dealing with dynamic memory allocation (e.g., `ft_strdup`), gracefully handle errors such as memory allocation failures, returning `NULL` when necessary.
- **String Manipulation**:
  - Functions like `ft_strjoin` allow concatenation of strings while managing memory efficiently.
  - `ft_strtrim` helps remove unwanted characters from both ends of a string, useful for sanitizing input.
  - `ft_split` splits a string by a delimiter (usually a character) and returns an array of substrings. It's ideal for parsing inputs like CSV or space-separated values.
  - `ft_split_charset` splits a string based on any set of characters from a given charset, providing a more flexible solution for splitting strings with multiple delimiters or special characters.
- **Comparison**: String comparison functions like `ft_strcmp` and `ft_strncmp` provide reliable ways to compare strings, supporting various use cases such as lexicographical sorting or equality checks.
- **Copying and Duplication**: Functions like `ft_strncpy` and `ft_strdup` allow for secure string copying and duplication, handling edge cases like null-terminated strings or fixed-size buffers.
- **Error-proof Design**: Each utility function is designed to return consistent results while minimizing the risk of **undefined behavior** (null pointer dereferencing, buffer overflow...).
</details>

<details>
<summary><strong>📚 String & Number Conversion</strong></summary>

Libft provides a set of functions for **string-to-number** and **number-to-string** conversions, allowing seamless manipulation and transformation between different data types.

- **Integer to String**:
  - `ft_itoa`: Converts an integer to a string representation.
  - `ft_itoa_base`: Converts an integer to a string representation in any given base (binary, hexadecimal).

- **String to Integer**:
  - `ft_atoi`: Converts a string to an integer, handling edge cases like leading whitespaces and signs.
  - `ft_atoll`: Similar to `ft_atoi` but returns a `long long` value for larger integers.

- **Unsigned Integer Conversion**:
  - `ft_utoa`: Converts an unsigned integer to a string.

These functions allow reliable conversion between different data types efficiently and are often used for **parsing**, **formatting** in many applications.
</details>

<details>
<summary><strong>📚 Array</strong></summary>

Libft provides a set of functions for efficiently working with arrays, including handling their sizes, copying, freeing, and printing.

- **Array Size**:
  - `ft_arraysize`: Returns the number of elements in an array, useful for dynamic arrays where size is not explicitly tracked.
- **Array Copying**:
  - `ft_copy_strarray`: Creates a duplicate of an array of strings, making it easy to clone or manipulate arrays without modifying the original.
- **Array Memory Management**:
  - `ft_free_array`: Frees the memory occupied by an array, preventing memory leaks when dynamically allocated arrays are no longer needed.
- **Array Output**:
  - `ft_putintarray`: Prints an array of integers, useful for debugging or displaying arrays in a readable format.

These functions streamline common array operations while ensuring memory safety and efficiency.
</details>

<details>
<summary><strong>📚 Custom `ft_printf`</strong></summary>

This is a custom implementation of the standard `printf` function, created as part of my **Hive School** curriculum. The goal of this project was to replicate the behavior of the `printf` function while gaining a deeper understanding of how it works.

- Supports basic format specifiers (e.g., `%s`, `%d`, `%x`, `%c`, etc.)
- Handles custom formatting (width, precision, and flags)
- Manages memory efficiently with error handling and safe string manipulation
- Fully implemented from scratch, without using the standard `printf` library

This project helped me strengthen my skills in **variadic functions**, **formatting** string output, and **dynamic memory allocation** in C.
</details>

<details>
<summary><strong>📚 2Darray</strong></summary>

Libft provides essential functions for managing 2D arrays (matrices), enabling efficient creation, manipulation, and printing of matrix-like structures.

- **Matrix Creation**:
  - `ft_create_matrix`: Allocates memory for a 2D array (matrix) of integers, allowing for easy manipulation of grid-like data structures.
- **Matrix Copying**:
  - `ft_copy_matrix`: Creates a copy of an existing matrix, useful for preserving original data when performing operations on copies.
- **Matrix Memory Management**:
  - `ft_free_matrix`: Frees the memory allocated for a matrix, ensuring that there are no memory leaks.
- **Matrix Output**:
  - `ft_print_matrix`: Prints the contents of a matrix in a human-readable format, making it easier to debug or visualize the data.
- **String to Matrix Conversion**:
  - `ft_strarr_to_matrix`: Converts an array of strings into a matrix of integers, useful for parsing string-based data into a structured matrix format.

These functions simplify the management of matrix-based data, enhancing both the readability and performance of matrix operations.
</details>

<details>
<summary><strong>📚 Memory</strong></summary>

Libft provides a suite of **memory management** functions that offer essential tools for safe and efficient manipulation of memory. These utilities are designed to handle tasks such as memory allocation, copying, setting, and comparing, ensuring that the program handles memory safely and without errors.

- Functions for allocating memory (`ft_calloc`, `ft_realloc`).
- Efficient memory manipulation with utilities like `ft_memcpy`, `ft_memmove`, and `ft_memset`.
- Memory comparison and search with `ft_memcmp` and `ft_memchr`.

These functions are crucial for handling raw memory operations and are often used in lower-level system programming, embedded systems, and scenarios where performance and memory safety are key.
</details>

<details>
<summary><strong>🔗 Linked List Operations</strong></summary>

Libft provides a collection of **Linked List** functions that allow for easy management of dynamic data structures. These functions enable efficient manipulation of linked lists for various use cases, such as quick prototyping or managing non-contiguous memory.

- **Creation and Deletion**:
  - `ft_lstnew`: Creates a new node with the given content.
  - `ft_lstdelone`: Deletes a node and frees its memory.
  - `ft_lstclear`: Removes all nodes in a list, freeing the entire structure.

- **Insertion and Removal**:
  - `ft_lstadd_front`: Inserts a node at the beginning of the list.
  - `ft_lstadd_back`: Inserts a node at the end of the list.
  - `ft_lstdelete`: Deletes a specific node from the list.
- **Iteration and Mapping**:
  - `ft_lstiter`: Iterates over each node and applies a function to its content.
  - `ft_lstmap`: Creates a new list by applying a function to each node’s content.
- **Size and Last Node**:
  - `ft_lstsize`: Returns the total number of elements in the list.
  - `ft_lstlast`: Retrieves the last node of the list.

These functions offer a flexible approach to working with linked lists and can be easily adapted for complex tasks requiring dynamic data handling.
</details>

<details>
<summary><strong>📝 I/O Helpers</strong></summary>

Libft provides a set of **I/O helper functions** designed to simplify reading and writing operations with file descriptors, while ensuring **safe and efficient** data handling.

- **File Input**:
  - `get_next_line`: Reads a line from a file descriptor, returning it as a string. This is useful for reading files line by line without loading the entire file into memory.

- **File Output**:
  - `ft_putstr_fd`: Safely writes a string to a specified file descriptor, ensuring proper handling of different output streams.
  - `ft_putnbr_fd`: Writes an integer to a file descriptor, converting it to a string for output.

These functions streamline file input and output operations while ensuring **safe memory usage** and **error handling**, making them ideal for tasks that involve reading from or writing to files or standard output.
</details>

<details>
<summary><strong>⚡ Generic Quick Sort (`ft_qsort`)</strong></summary>

A fully generic, optimized quicksort implementation for sorting any array type.

- Works with **any data type** (int, double, structs…) via a user-provided comparator.
- Uses **median-of-three pivot selection** to avoid worst-case scenarios.
- Falls back to **insertion sort** for small partitions for better performance.
- Includes **tail recursion optimization** to reduce call stack usage.
- Custom **`ft_swap`** handles generic byte-wise swapping.
</details>

<details>
<summary><strong>📐 Math & Vector</strong></summary>

Libft provides a set of **mathematical** and **vector-related** functions that are essential for performing geometric and mathematical operations, particularly in **2D/3D vector calculations**.

- **Angle Conversion**:
  - `deg_to_rad`: Converts degrees to radians.
  - `rad_to_deg`: Converts radians to degrees.
  - `wrap_angle`: Normalizes an angle to the range `[0, 2π)`.
- **Distance Calculations**:
  - `ft_manhattan_dist_point`: Computes the **Manhattan distance** between two `t_point` structs (integer points).
  - `ft_manhattan_dist_dpoint`: Computes the **Manhattan distance** between two `t_dpoint` structs (floating-point points).
  - `ft_euclidean_dist_point`: Computes the **Euclidean distance** between two `t_point` structs (integer points).
  - `ft_euclidean_dist_dpoint`: Computes the **Euclidean distance** between two `t_dpoint` structs (floating-point points).
- **Mathematical Operations**:
  - `clamp`: Clamps a value between a specified minimum and maximum.
  - `get_fractional_part`: Returns the fractional part of a floating-point number.
  - `wrap_in_range`: Wraps a value within a specified range.
- **Vector Operations**:
  - `get_vector_length`: Calculates the **magnitude** (length) of a vector.
  - `divide_vector_by_scalar`: Divides a vector by a scalar.
  - `get_normalized_vector`: Returns the **unit vector** (normalized vector) from a given vector.
  - `get_vector_angle`: Returns the angle of a vector relative to the x-axis.
  - `get_vector_angle_between`: Calculates the angle between two vectors.
  - `get_direction_vector`: Returns the direction vector from one point to another.
  - `get_unit_direction_vector`: Returns the unit direction vector from one point to another.
  - `get_dot_product`: Computes the **dot product** of two vectors.

These functions provide the foundation for performing efficient **vector mathematics**, **distance calculations**, and **angle conversions**, crucial for projects involving graphics, physics simulations, or geometry-related tasks.
</details>

<details>
<summary><strong>🎲 Random Number Generator (`ft_rand`)</strong></summary>

`ft_rand` is a custom implementation of a random number generator (RNG) designed to provide efficient and **deterministic random numbers**. It uses the **Xorshift32** algorithm for generating pseudo-random integers, based on the current system time.

- **Efficient RNG**: Uses the **Xorshift32** method, which is fast and has a low computational overhead.
- **Range Control**: Allows specifying a **range** (`min` and `max`) for generating random numbers within a given interval.
- **System Time Seed**: Seeds the RNG using the system's current time to ensure non-repetitive sequences.

This function is useful for simulations, games, or any applications where you need **randomized behavior** without relying on external libraries or functions.
</details>

</details>

---
## 🚀 Usage
<details>
<summary><strong> See usage guide  </strong></summary>

🛠️ To build the **static library**, in the `libft folder` run:
```bash
make
```

🧪 **Example**
```c
#include "libft.h" // Include the header

int	main(void)
{
    ft_putstr_fd("Hello from libft!\n", 1);
    return (0);
}
```
🖥️ **Compile** your program with the library, `main.c` being in the same directory as `libft folder`:
```bash
gcc main.c -I libft/include -L libft/lib -lft -o my_program
```
ℹ️ This links your code against libft.a, using libft.h for declarations.
</details>

---
## 📝 License

This project is licensed under the [MIT License](LICENSE).

You are free to use, modify, and distribute this code for academic, personal, or professional purposes. Attribution is appreciated but not required.

---

## 🗂️ Project Structure

<details>
<summary><strong> See project structure  </strong></summary>

```plaintext
libft/
├── docs/
├── include/
│   ├── ft_2darray.h
│   ├── ft_array.h
│   ├── ft_check.h
│   ├── ft_convert.h
│   ├── ft_file.h
│   ├── ft_list.h
│   ├── ft_math.h
│   ├── ft_memory.h
│   ├── ft_output.h
│   ├── ft_printf.h
│   ├── ft_sorting.h
│   ├── ft_string.h
│   ├── ft_utils.h
│   └── libft.h
├── srcs/
│   ├── 2Darray/
│   ├── array/
│   ├── check/
│   ├── convert/
│   ├── file_utils/
│   ├── ft_printf/
│   ├── list/
│   ├── math/
│   ├── mem/
│   ├── output/
│   ├── sort/
│   ├── str/
│   └── utilities/
├── .clang-format
├── .gitignore
├── Doxyfile
├── DOXYGEN_STYLE_GUIDE.md
├── format_all.sh
├── LICENSE
├── Makefile
└── README.md
```

</details>

---

## 📬 Contact

If you have any questions, suggestions, or feedback, feel free to reach out:

- **📧 Email:** nicolas.lovis@hotmail.fr
- **💻 GitHub:** [github.com/to0nsa](https://github.com/to0nsa)

You're also welcome to open an issue or leave a comment on the repository.
