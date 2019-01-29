"""
>>> a = [1, 2, 3, 4, 5]
>>> merge_sort(a)
[1, 2, 3, 4, 5]
>>> a = [4, 2, 5, 1, 3]
>>> merge_sort(a)
[1, 2, 3, 4, 5]
"""


def merge_sort(a):
    if len(a) == 1:
        return a
    middle = int(len(a) / 2)
    sorted_1 = merge_sort(a[:middle])
    sorted_2 = merge_sort(a[middle:])
    return merge(sorted_1, sorted_2)


def merge(a1, a2):
   i, j = 0, 0
   result = []
   while i < len(a1) and j < len(a2):
       if a1[i] < a2[j]:
           result.append(a1[i])
           i += 1
       else:
           result.append(a2[j])
           j += 1
   while i < len(a1):
       result.append(a1[i])
       i += 1
   while j < len(a2):
       result.append(a2[j])
       j += 1
   return result


if __name__ == "__main__":
    import doctest
    doctest.testmod()
