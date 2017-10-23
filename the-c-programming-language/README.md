# The C Programming Language

![c](https://upload.wikimedia.org/wikipedia/en/thumb/5/5e/The_C_Programming_Language_cover.svg/792px-The_C_Programming_Language_cover.svg.png)

Solved exercicies of the amazing K&R's book.

1. **Chapter 1: A Tutorial Introduction**
    - [1-1](./cap1/1-1.c): Run the `hello, world` program on your system. Experiment with leaving out parts of the program, to see what error messages you get.
    - [1-2](./cap1/1-2.c): Experiment to find out waht happens when `prints`'s argument string contains `\c`, where `c` is some character not listed above.
    - [1-3](./cap1/1-3.c): Modify the temperature conversion program to print a heading aboute the table.
    - [1-4](./cap1/1-4.c): Write a program to print the corresponding Celsius to Fahrenheit table.
    - [1-5](./cap1/1-5.c): Modify the temperature conversion program to print the table in reverse order, that is from 300 degrees to 0.
    - [1-6](./cap1/1-6.c): Verify that the expression `getchar() != EOF` is `0` or `1`.
    - [1-7](./cap1/1-7.c): Write a program to print the value of `EOF`.
    - [1-8](./cap1/1-8.c): Write a program to count blanks, tabs and newlines.
    - [1-9](./cap1/1-9.c): Write a program to copy its input to its output, replacing each string of one or more blanks by single blank.
    - [1-10](./cap1/1-10.c): Write a program to copy its input to its output, replacing each tab by `\t`, each backspace by `\b`, and each backslash by `\\`. This makes tabs and backspaces visible in an unambiguous way.
    - [1-11](./cap1/1-11.c): How would you test the word count program? What kinds of input are most likely to incover bugs if there are any?
    - [1-12](./cap1/1-12.c): Write a program that prints its input one word per line.
    - [1-13](./cap1/1-13.c): Write a program to print a histogram of the lenghts of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
    - [1-14](./cap1/1-14.c): Write a program to print a histogram of the frequencies of different characters in its input.
    - [1-15](./cap1/1-15.c): Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
    - [1-16](./cap1/1-16.c): Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines, and as much as possible of the text.
    - [1-17](./cap1/1-17.c): Write a program to print all input lines that are longer than 80 characters.
    - [1-18](./cap1/1-18.c): Write a program to remove all trailing blanks and tabs from each line of input, and to delete entirely blank lines.
    - [1-19](./cap1/1-19.c): Write a function `reverse(s)` that reverses the character string s. Use it to write a program that reverses its input a line at a time.
    - [1-20](./cap1/1-20.c): Write a program `detab` that replaces tabs in the input with the proper number of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every `n` columns. Should n be a variable or a symbolic parameter?
    - [1-21](./cap1/1-21.c): Write a program `entab` that replaces strings of blanks with the minimum number of tabs and blanks to achieve the same spacing. Use the same stops as for `detab`. When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
    - [1-22](./cap1/1-22.c): Write a program to "fold" long input lines into two or more shorter lines after the last non-blank character that occurs before the `n`-th column of input. Make sure your program does something intelligent with very long lines, and if there are no blanks or tabs before the specified column.
    - [1-23](./cap1/1-23.c): Write a program to remove all comments from a C program. Don't forget to handle quoted strings and character constants properly. C comments do not nest.
    - [1-24](./cap1/1-24.c): Write a program to check a C program for rudimentary syntax errors like unbalanced parentheses, brackets and braces. Don't forget about quotes, both single and double, escape sequences, and comments. (This program is hard if you do it in full generality.)
