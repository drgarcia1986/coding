# The Algorithm Design Manual

![skiena](https://m.media-amazon.com/images/I/41v28WnETpS._SL250_.jpg)

Some exercises from masterpiece book by Steven Skiena

1. **Introduction to Algorithm**:
    - [knapsack brute force](./cap1/1-5.py): The knapsack problem is as follows: given a set of integers S = {s1, s2, . . . , sn}, and a target number T , find a subset of S which adds up exactly to T . For example, there exists a subset within S = {1, 2, 5, 9, 10} that adds up to T = 22 but not T = 23.
Find counterexamples to each of the following algorithms for the knapsack problem.  That is, giving an S and T such that the subset is selected using the algorithm does not leave the knapsack completely full, even though such a solution exists.
        - (a) Put the elements of S in the knapsack in left to right order if they fit, i.e. the
        first-fit algorithm.

            `s = {22, 21, 2}; t = 23`

        - (b) Put the elements of S in the knapsack from smallest to largest, i.e. the best-fit
        algorithm.

            `s = {1, 2, 3, 5}; t = 5`

        - (c) Put the elements of S in the knapsack from largest to smallest.

            `s = {23, 21, 2}; t = 23`
