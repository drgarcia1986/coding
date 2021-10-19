"""
>>> knapsack({1, 2, 5, 9, 10}, 22)
{1, 2, 9, 10}
>>> knapsack({1, 2, 3}, 5)
{2, 3}
>>> knapsack({4, 3, 2}, 5)
{2, 3}
>>> knapsack({3, 2, 4}, 5)
{2, 3}
>>> knapsack({1, 2, 5, 9, 10}, 11)
{9, 2}
"""
from typing import Dict, Set


def knapsack(s: Set[int], t: int) -> Set[int]:
    subset: Set[int] = set()
    current_sum: int = 0
    for n in s:
        if n == t:
            return {i}
        if (current_sum + n) <= t:
            current_sum += n
            subset.add(n)
        else:
            for n_in_subset in subset:
                if (n_in_subset + n) == t:
                    return {n_in_subset, n}
                if ((current_sum + n) - n_in_subset) != t:
                    continue
                subset.remove(n_in_subset)
                subset.add(n)
                return subset
        if current_sum == t:
            return subset
    raise ValueError('There is no subset that adds up to T')


if __name__ == '__main__':
    import doctest
    doctest.testmod()
