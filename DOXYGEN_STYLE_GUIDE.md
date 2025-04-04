# Doxygen Style Guide for `libft`

This guide defines how to write consistent, clean, and useful Doxygen documentation for all `.h` and `.c` files in the `libft` project.

Following this guide helps:
- Keep documentation readable and structured
- Generate clean HTML / PDF output with Doxygen
- Improve code discoverability and collaboration

---

## File Header Format (`@file`)

Each `.h` and `.c` file should start with a Doxygen `@file` block, **before** the ASCII comment block.

```c
/**
 * @file ft_array.h
 * @author Toonsa
 * @date 2025/04/04
 * @brief Brief description of this file's purpose.
 *
 * @details
 * Optional longer description of what the file does,
 * what it implements, and any special notes.
 *
 * @ingroup group_name
 */
```

### Group template (@defgroup)
Each module should declare a Doxygen group in its header file:

```c
/**
 * @defgroup array_utils Array Utilities
 * @brief Functions for working with pointer and integer arrays.
 * @{
 */

/** @} */ // end of array_utils group
```

Then use `@ingroup` array_utils in each function doc in the c file.

## Function Documentation Template

Place this above **every function** in the header file (.h)
Add extra internal logic notes in the .c file.

```c
/**
 * @brief One-liner summary of what this function does.
 *
 * @details
 * Longer explanation (optional). Include:
 * - Expected behavior
 * - Special edge cases
 * - Internal logic if helpful
 *
 * @param [name] Description of the parameter.
 * @return Description of the return value.
 *
 * @note Any caveats, NULL-safety, or usage context.
 * @see Related functions
 * @ingroup group_name
 */
```

### Doxygen Tags Cheat Sheet

| Tag                    | Description                                             | Use In                |
|------------------------|---------------------------------------------------------|------------------------|
| `@file`               | Describes the file                                       | Top of `.c` / `.h`    |
| `@brief`              | Short function or file summary                           | Functions / files     |
| `@details`            | Infos about the function, must be detailed if technical  | Functions/ files
| `@param`              | Describes each function parameter                        | Function declarations |
| `@return`             | Describes the return value                               | Function declarations |
| `@note`               | Extra notes (e.g., "Safe to call with NULL.")           | Optional              |
| `@see`                | References to related functions                          | Optional              |
| `@ingroup`            | Assigns function to a documentation group                | Required              |
| `@addtogroup` / `@{`...`@}` | Groups related functions together in `.c` files      | Recommended           |

### Group template (@defgroup)
Each module should declare a Doxygen group in its header file:

```c
/**
 * @defgroup array_utils Array Utilities
 * @brief Functions for working with pointer and integer arrays.
 * @{
 */

/** @} */ // end of array_utils group
```

Then use `@ingroup` array_utils in each function doc in the c file.

✨ Style Rules
All @param entries are aligned and ordered as in the function signature.

One empty line between @brief and full description (if any).

Use full sentences with punctuation.

Prefer present tense:

✅ "Returns the number of elements."

❌ "This function will return..."

Don't document implementation details in .h unless relevant to the user.

Don't repeat @ingroup in .c if you use @addtogroup ... @{ ... @} block.