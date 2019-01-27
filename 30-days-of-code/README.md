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

### Solutions
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

### Solutions
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

### Solutions
- [C](C/day-2.c).

## Day 3: Intro to Conditional Statements
Given an integer, _N_, perform the following conditional actions:

- If _N_ is odd, print Weird
- If _N_ is even and in the inclusive range of 2 to 5, print Not Weird
- If _N_ is even and in the inclusive range of 6 to 20, print Weird
- If _N_ is even and greater than 20, print Not Weird

### Solutions
- [C](C/day-3.c)

## Day 4: Class vs. Instance
Write a Person class with an instance variable, _age_, and a constructor that takes an integer, _initialAge_, as a parameter. The constructor must assign _initialAge_ to _age_  after confirming the argument passed as  is not negative; if a negative argument is passed as _intialAge_, the constructor should set _age_ to _0_ and print Age is not valid, setting age to 0.. In addition, you must write the following instance methods:

- yearPasses() should increase the  instance variable by .
- amIOld() should perform the following conditional actions:
- If age < 13, print You are young..
- If age >= 13 and age < 18, print You are a teenager..
- Otherwise, print You are old..

### Solutions
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

### Solutions
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

### Solutions
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

### Solutions
- [C](C/day-7.c)

## Day 8: Dictionaries and Maps
Given _n_ names and phone numbers, assemble a phone book that maps friends' names to their respective phone numbers. You will then be given an unknown number of names to query your phone book for. For each _name_  queried, print the associated entry from your phone book on a new line in the form name=phoneNumber; if an entry for _name_ is not found, print _Not found_ instead.

**Note**: Your phone book should be a Dictionary/Map/HashMap data structure.

**Sample Input**
```
3
sam 99912222
tom 11122222
harry 12299933
sam
edward
harry
```
**Sample Output**
```
sam=99912222
Not found
harry=12299933
```

### Solutions
- [Python](Python/day-8.py)

## Day 9: Recursion 3
Write a factorial function that takes a positive integer, _n_ as a parameter and prints the result of _n!_ (_n_ factorial).

**Sample Input**
```
3
```
**Sample Output**
```
6
```

### Solutions
- [C](C/day-9.c)

## Day 10: Binary Numbers
Given a base-10 integer, _n_, convert it to binary (base-2). Then find and print the base-10 integer denoting the maximum number of consecutive 1's in n's binary representation.

**Sample Input**
```
13
```
**Sample Output**
```
2
```

#### Solutions
- [C](C/day-10.c)

## Day 11: 2D Arrays
Calculate the hourglass sum for every hourglass in _A_, then print the maximum hourglass sum.

**Context**
Given a _6_ X _6_  2D Array, _A_:

```
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
```

We define an hourglass in _A_ to be a subset of values with indices falling in this pattern in _A_'s graphical representation:

```
a b c
  d
e f g
```

**Sample Input**
```
1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 2 4 4 0
0 0 0 2 0 0
0 0 1 2 4 0
```

**Sample Output**
```
19
```

#### Solutions
- [C](C/day-11.c)
- [Python](Python/day-11.py)
