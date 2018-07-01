# Hacker Rank C exercicies
Random [Hacker Rank](https://www.hackerrank.com) exercicies in C.

## "Hello, World!" in C
This challenge requires you to print _Hello, World!_ on a single line, and then print the already provided input string to stdout.

[source](./hello-world.c)

## Playing With Characters
You have to print the character, _ch_, in the first line. Then print _s_ in next line. In the last line print the sentence, _sen_.

**Input Format**

- First, take a character, _ch_ as input.
- Then take the string, _s_ as input.
- Lastly, take the sentence _sen_ as input.

**Output Format**

- Print three lines of output. The first line prints the character, _ch_.
- The second line prints the string, _s_.
- The third line prints the sentence, _sen_.

[source](./playing-with-characters.c)

## Sum and Difference of Two Numbers
Your task is to take two numbers of int data type, two numbers of float data type as input and output their sum:

1. Declare 4 variables: two of type int and two of type float.
2. Read 2 lines of input from stdin (according to the sequence given in the 'Input Format' section below) and initialize your 4 variables.
3. Use the  and  operator to perform the following operations:
    - Print the sum and difference of two int variable on a new line.
    - Print the sum and difference of two float variable rounded to one decimal place on a new line.

**Sample Input**
```
10 4
4.0 2.0
```
**Sample Output**
```
14 6
6.0 2.0
```

[souce](./sum-and-difference-of-two-numbers.c)

## Functions in C
You have to write a function int max\_of\_four(int a, int b, int c, int d) which reads four arguments and returns the greatest of them.

**Sample Input**
```
3
4
6
5
```
**Sample Output**
```
6
```

[source](./max_of_four.c)

## Pointers in C
You have to complete the function void update(int \*a,int \*b), which reads two integers as argument, and sets _a_ with the sum of them, and _b_  with the absolute difference of them.

**Sample Input**
```
4
5
```

**Sample Output**
```
9
1
```

[source](./pointers-in-c.c)

## Conditional Statements in C
Given a positive integer denoting _n_, do the following:
If 1 <= _n_ <= 9, then print the lowercase English word corresponding to the number (e.g., one for 1, two for 2, etc.).
If _n_ > 9, print Greater than 9.

[source](./nine_numbers.c)

## For Loop in C
For each integer _n_ in the interval _[a, b]_ (given as input):

- If 1 <= _n_ <= 9, then print the English representation of it in lowercase. That is "one" for 1, "two" for 2, and so on.
- Else if _n_ > 9 and it is an even number, then print "even".
- Else if _n_ > 9 and it is an odd number, then print "odd".

**Sample Input**
```
8
11
```
**Sample Output**
```
eight
nine
even
odd
```

[source](./for-loop.c)
