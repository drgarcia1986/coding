# 30 Days of Code
[Hacker Rank](https://www.hackerrank.com) Practice challengers

## Day 0: Hello, World
To complete this challenge, you must save a line of input from stdin to a variable, print Hello, World. on a single line, and finally print the value of your variable on a second line.

**Sample Input**
```
Welcome to 30 Days of Code!
```
**Sample Output**
```
Hello, World. 
Welcome to 30 Days of Code!
```

- [C](C/day-0.c).

## Day 1: Data Types
The variables _i_, _d_, and _s_ are already declared and initialized for you. You must:

1. Declare  variables: one of type int, one of type double, and one of type String.
2. Read  lines of input from stdin (according to the sequence given in the Input Format section below) and initialize your variables.
3. Use the _+_ operator to perform the following operations: 
    1. Print the sum of  plus your int variable on a new line.
    2. Print the sum of  plus your double variable to a scale of one decimal place on a new line.
    3. Concatenate  with the string you read as input and print the result on a new line.

**Sample Input**
```
12
4.0
is the best place to learn and practice coding!
```
**Sample Output**
```
16
8.0
HackerRank is the best place to learn and practice coding!
```

- [C](C/day-1.c).

## Day 2: Operators
Given the meal price (base cost of a meal), tip percent (the percentage of the meal price being added as tip), and tax percent (the percentage of the meal price being added as tax) for a meal, find and print the meal's total cost.

**Note**: Be sure to use precise values for your calculations, or you may end up with an incorrectly rounded result!

**Sample Input**
```
12.00
20
8
```
**Sample Output**
```
The total meal cost is 15 dollars.
```

- [C](C/day-2.c).

## Day 3: Intro to Conditional Statements
Given an integer, _N_, perform the following conditional actions:

- If _N_ is odd, print Weird
- If _N_ is even and in the inclusive range of 2 to 5, print Not Weird
- If _N_ is even and in the inclusive range of 6 to 20, print Weird
- If _N_ is even and greater than 20, print Not Weird

- [C](C/day-3.c)

## Day 4: Class vs. Instance
Write a Person class with an instance variable, _age_, and a constructor that takes an integer, _initialAge_, as a parameter. The constructor must assign _initialAge_ to _age_  after confirming the argument passed as  is not negative; if a negative argument is passed as _intialAge_, the constructor should set _age_ to _0_ and print Age is not valid, setting age to 0.. In addition, you must write the following instance methods:

- yearPasses() should increase the  instance variable by .
- amIOld() should perform the following conditional actions:
- If age < 13, print You are young..
- If age >= 13 and age < 18, print You are a teenager..
- Otherwise, print You are old..

- [Go](Go/day4/main.go)

## Day 5: Loops
Given an integer, _n_, print its first _10_ multiples. Each multiple _n x i_ (where _1 < i < 10_) should be printed on a new line in the form: n x i = result.

**Sample Input**
```
2
```
**Sample Output**
```
2 x 1 = 2
2 x 2 = 4
2 x 3 = 6
2 x 4 = 8
2 x 5 = 10
2 x 6 = 12
2 x 7 = 14
2 x 8 = 16
2 x 9 = 18
2 x 10 = 20
```

- [C](C/day-5.c)

## Day 6: Let's Review
Given a string, _S_, of length _N_ that is indexed from _0_ to _N - 1_, print its even-indexed and odd-indexed characters as _2_ space-separated strings on a single line (see the Sample below for more detail).

**Note**: _0_ is considered to be an even index.

**Sample Input**
```
2
Hacker
Rank
```
**Sample Output**
```
Hce akr
Rn ak
```

- [C](C/day-6.c)

## Day 7: Arrays
Given an array, _A_, of _N_ integers, print _A_'s elements in reverse order as a single line of space-separated numbers.


**Sample Input**
```
4
1 4 3 2
```
**Sample Output**
```
2 3 4 1
```

- [C](C/day-7.c)
