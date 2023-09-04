# Python notes ;)

Avoid Nested Python Loops Using product() Function :

<table width=100%>
<tr>
<td>

```python
list_a = [1, 2020, 70]
list_b = [2, 4, 7, 2000]
list_c = [3, 70, 7]

for a in list_a:
    for b in list_b:
        for c in list_c:
            if a + b + c == 2077:
                print(a, b, c)

```

</td>
<td>

```python
from itertools import product

list_a = [1, 2020, 70]
list_b = [2, 4, 7, 2000]
list_c = [3, 70, 7]

for a, b, c in product(list_a, list_b, list_c):
    if a + b + c == 2077:
        print(a, b, c)

```
</td>
</tr>
</table>

Make use of the walrus operator `print(author:="Saikia")` and ternary operator for if-else condition in one line : `min = a if a < b else b`

```python

cities_de = {'Hamburg': 'Germany', 'Bremen': 'Germany'} #dict1
cities_ind = {'Guwahati': 'India', 'Mumbai': 'India'} #dict2

cities = cities_de|cities_ind #union operator
cities_de |= cities_ind  #inplace

```


#### F-Strings: The Pythonic String Formatting Technique

```python

pi = 3.1415926
print(f'Pi is approximately equal to {pi:.2f}')
# Pi is approximately equal to 3.14

id = 1  # need to print a 3-digit number
print(f"The id is {id:03d}")
# The id is 001

N = 1000000000  # need to add separator
print(f'His networth is ${N:,d}')
# His networth is $1,000,000,000

```

####  Asterisks for Unpacking Iterables :

```python

A = [1, 2, 3]
B = (4, 5, 6)
C = {7, 8, 9}
L = [*A, *B, *C]
print(L)
# [1, 2, 3, 4, 5, 6, 8, 9, 7]

```

Lists vs tuples :  Tuples, are immutable, tuples are more memory efficient since Python can allocate the right memory block required for the data. In contrast, in a list, extra memory has to be allocated just in case we extend it - this is called dynamic memory allocation. 

In Python, rounded brackets with list comprehension logic create what is known as a generator object. Generators are a special kind of iterable. Unlike lists, they do not store their items. Instead, they store instructions to generate each element in order and the current state of iterations.

List comprehension : `a = [x * 2 for x in range(10)]` becomes generator: `b = (x * 2 for x in range(10))`.

Each element is only generated upon request using a technique called lazy evaluation. The main benefit of this Python tip using a generator is that it uses less memory since the entire sequence is not built at once. 

Easiest way to check if our data structure is empty by using the not operator. 

```python

a = []
print(not a)

"""
True
"""
```

The Print Functions ‘`end`’ Parameter : 

```python

a = ["english", "french", "hindi", "german", "assamese"]
for language in a:
    print(language, end=" ")

"""
english french hindi german assamese
"""

```

Append to Tuple : The first two elements of our tuple are integers - they are immutable. The last element of our tuple is a list, a mutable object in Python.

```python

a = (1, 2, [1, 2, 3])
a[2].append(4)
print(a)

"""
(1, 2, [1, 2, 3, 4])
"""

```

+ Use `set()` to remove duplicates.
+ Underscore (`_`) is a legal identifier in Python, thus, it's possible to use it to reference an object. But underscore also has another responsibility: to store the result of the last evaluation. example : `print(_)`

```python
for _ in range(100):
    print("The index doesn't matter")

"""
The index doesn't matter
The index doesn't matter
...
"""

```

Trailing Underscores : PEP 8 mentions that a trailing underscore (_) should be "used by convention to avoid conflicts with Python keywords." `list_ = [0, 1, 2, 3, 4]`
and `global_ = "Hamburg is beautiful"`.

Leading Underscores : The underscore prefixed to an identifier or method has a hidden meaning: this variable or method is only meant for internal usage. Essentially, it is a disclaimer to other programmers that have been defined in PEP 8. 

```python

class Example:
    def __init__(self):
        self._internal = 2
        self.external = 20

```

Another way we could use the underscore is as a visual separator for digit grouping in integral, floating-point, and complex number literals – this was introduced in Python 3.6. 

```python

number = 1_500_000
print(number)

"""
15000000
"""
```

The Print Function ‘sep’ Parameter:

```python

day = "04"
month = "10"
year = "2022"

print(day, month, year)
print(day, month, year, sep = "")
print(day, month, year, sep = ".")




"""
04 10 2022
04/10/2022
04.10.2022
"""

```

### Exception Handling:

```python

def get_ration(x:int, y:int) -> int:
    try:
        ratio = x/y
    except: ZeroDivisionError:
        y = y + 1
        ratio = x/y
    return ratio

print(get_ratio(x=400, y=0))

"""
400.0
"""

```

### Lists :

```python

list_1 = [1, 3, 5, 7, 8]
list_2 = [1, 2, 3, 4, 5, 6, 7, 8, 9]

solution_1 = list(set(list_2) - set(list_1))
solution_2 = list(set(list_1) ^ set(list_2))
solution_3 = list(set(list_1).symmetric_difference(set(list_2)))

```

### Args & Kwargs:

We use *args and **kwargs as parameters to a function when we are unaware of the number of variables our function should expect. 

The *args parameter permits us to pass a variable number of parameters to a function when it’s non-keyworded (i.e., the parameters we pass do not require an associated name). On the other hand, the **kwargs parameter enables us to pass an arbitrary number of keyworded parameters to a function.

```python

def some_function(*args, **kwargs):
    print(f"Args: {args}")
    print(f"Kwargs: {kwargs}")

some_function(1, 2, 3,  a=4, b=5, c=6)

"""
Args: (1, 2, 3)
Kwargs: {'a': 4, 'b': 5, 'c': 6}
"""

```

### The Ellipsis :

The Ellipsis is a Python object that can be called by providing a sequence of three dots (...) or calling the object itself (Ellipsis).

```python

import numpy as np

arr = np.array([[2,3], [1,2], [9,8]])

print(arr[...,0])
"""
[2 1 9]
"""
print(arr[...])

"""
[[2 3]
[1 2]
[9 8]]
"""

```

Use `xrange()` instead of `range()`, where `xrange()` is a generator function. 

Permutations with itertools:

```python

import itertools
iter = itertools.permutations(["Alice", "Bob", "Carol"])
list(iter)

'''

[('Alice', 'Bob', 'Carol'),
 ('Alice', 'Carol', 'Bob'),
 ('Bob', 'Alice', 'Carol'),
 ('Bob', 'Carol', 'Alice'),
 ('Carol', 'Alice', 'Bob'),
 ('Carol', 'Bob', 'Alice')]

 '''

```

Decorator Caching : Memoization is a specific type of caching that optimizes software running speeds. Basically, a cache stores the results of an operation for later use. The results could be rendered web pages or the results of complex calculations.

```python

import functools

@functools.lru_cache(maxsize=128)
def fibonacci(n):
  if n == 0:
    return 0
  elif n == 1:
    return 1
  return fibonacci(n - 1) + fibonacci(n-2)

```

Use keys for sorts: 

```python

import operator
my_list = [("Josh", "Grobin", "Singer"), ("Marco", "Polo", "General"), ("Ada", "Lovelace", "Scientist")]
my_list.sort(key=operator.itemgetter(0))


'''
This will sort the list by the first keys:

[('Ada', 'Lovelace', 'Scientist'),
 ('Josh', 'Grobin', 'Singer'),
 ('Marco', 'Polo', 'General')]

'''

```

<b>Use the “enumerate” Function </b>: The enumerate function allows you to iterate over a collection while also keeping track of the index of each element. This can be useful for creating dictionaries, or for printing out messages that include the position of each item in a list.

```python

# Iterate over a list using a for loop and index variable
my_list = ["apple", "banana", "cherry"]
for index in range(len(my_list)):
    print(index, my_list[index])

# Iterate over a list using "enumerate" function
my_list = ["apple", "banana", "cherry"]
for index, item in enumerate(my_list):
    print(index, item)

```



resources : @github/[all algorithms implemented in python](https://github.com/TheAlgorithms/Python), @github/[py-ds](https://github.com/Py-Contributors/AlgorithmsAndDataStructure/tree/master/Python/DataStructure), @github/[py-ds2](https://github.com/prabhupant/python-ds).