# The C Programming Language Notes

## Chapter 1: A Tutorial Introduction

- C stems from BCPL and B, which lacked types.
- The types are character, integer, and floating-point numbers.
- Then there are data types created with pointers, arrays, structures, and unions.
- There is no heap or garbage collection.
- The data types and control structures provided by C are supported directly by most computers.
- The full list of C types are `int`, `char`, `short`, `long`, and `double`
- `printf` is not part of the standard library
- In `printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));`, the `(5.0/9.0)*(fahr-32)` illustrates that anytime it is permissible to use a variable of some type, you can also use an expression that returns that type.

### On Division

In:

    int fahr, celsius;
	// [...]
	celsius = 5 * (fahr - 32) / 9;

Multiplying by 5 is performed before dividing by 9 (instead of multiplying by 5/9) is because in C integer division truncates. I.e., the fractional part is discarded. So 5/9 would be truncated to zero because both are integers.

### Parameters

Parameters in C are passed "by value". This means that a function is called with new variables with the values of its arguments rather than the original variables. This means in C the called function cannot alter a variable in the calling function. This is in contrast to functions in some other languages being called "by reference", in which case the original variables are passed to the function.

## Chapter 2

- `char` is a single byte that holds one character in the local character set.
- `int` is an integer that usually reflects the natural size of integers on the host machine.
- `float` is a single-precision floating point.
- There are some qualifiers that can be applied to these basic types, for example `short int sh` and `long int counter` (the word `int` can and should be omitted in those declarations).
- `short` is often 16 bits, and `long` 32 bits. Compilers can choose their own sizes based on the hardware, but `short` and `int` must be at least 16 bits and longs at least 32 bits. And `long` >= `int` >= `short`
- `double` is a double-precision floating point.
- If `char` is 8 bits, unsigned `char` variables have values between 0 and 255, while signed `char` have values between -128 and 127.
- The standard headers `<limit.h>` and `<float.h` contain the these sizes.
- `1234` is an `int`.
- The suffix `L` on a constant makes it `long`.
- The suffix `UL` makes it `unsigned long`.
- A leading `0` in an integer constant means octal.
- A leading `0x` means hexadecimal.
- The decimal `31` is `037` in octal and `0x1f` in hex.
- A character constant is an integer, written as one character in single quotes, like `'x'`.
- Since a character is just a small integer, they can be used in arithmetic expressions, to assist in character transformations. For example to convert from upper to lowercase: `c + 'a' - 'A'`

### Escape Sequences

- `\a`: alert (bell) character
- `\b`: backspace
- `\f`: formfeed
- `\n`: newline
- `\r`: carriage return
- `\t`: horizontal tab
- `\v`: vertical tab
- `\\`: backslash
- `\?`: question mark
- `\?`: single quote
- `\"`: double quote
- `\ooo`: octal number
- `\xhh`: hexadecimal number

- `'\0'` represents the character with the value zero, or the null character. Its numeric value is `0`.
- Expressions that only include constants are called "constant expressions" and are evaluated at compile time.
- A "string constant" or "string literal" has double quotes, e.g., `"I am a string"`
- Strings are concatenated at compile time, `"hello," " world"` is equivalent to `"hello, world"`.
- A string constant is an array of `char` with a null character (`\0`) at the end. A string can be any length, but a string must be scanned completely to determine its length.
- `strlen(s)` determines the length of a string (excluding the terminal `\0`), it's declared in `<string.h>`.
- `'x'` is not the same as `"x"`. The former is an integer, the latter a string.
- An "enumeration constant" is a list of constant integer values, e.g., `enum boolean { NO, YES };`. The first has the value `0`, the second `1`, etc..., unless explicit values are specified.
- Variable initialization is only done once, before the program starts, and the initializer must be a constant expression.
- The qualifier `const` can be applied to the declaration of any variable to specify that its value will not be changed. For an array, `const` means the elements will not be altered.
- `const` can also be used with array arguments to indicate the function does not change that array: `int strlen(const char[]);`.
- `i` is the unary negation operator, it converts a non-zero operand into `0`, and a zero operand into `1`, e.g., in `if (!valid)`.

### Bitwise Operators

- `&`: AND
- `|`: OR
- `^`: Exclusive OR
- `<<`: Left shift
- `>>`: Right shift
- `~`: One's complement (unary)

#### Masking

- `n = n & 0177` sets to zero all but the low-order `7` bits of `n` (low-order bits are the rightmost).
- `x = x | SET_ON` is used to turn bits on.
- `^` sets bits to `0` when they are both the same, and `1` if they are both different.
- Note that bitwise operators do not have the operator precedence of `||` and `&&`, e.g., if `x = 1` and `y = 2`, then `x & y` is `0` while `x && y` is `1`.

## Chapter 3

The comma operator (`,`) is most often used in `for` statements. Expressions separated by a comma are evaluated left to right, and the type and value are the result of the right operand. The comma operator can be used to include multiple indexes in a `for` loop:

	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
	    c = s[i];
	    s[i] = s[j];
	    s[j] = c;
	}

This `for` statement:

	for (expr1;  expr2;  expr3)
		statement

Is the same as this `while` loop:

	expr1;
	while (expr2)  {
		statement
		expr3;
	}

