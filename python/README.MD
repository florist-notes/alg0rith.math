# Python ([web](https://www.python.org/)) 🌸

```python

>>> __name__
'__main__'

```
<img src="py.png" width=100%>

```python

    def main():
        list(map(lambda n: n * 2, [7, 8, 5, 6, 2, 1]))
        strs = ['skk', 'py', 'py-saikia', 'python']
        list(filter(lambda s: len(s) > 3, strs))

    if __name__ == "__main__":
        main()

    

```

I am comfortable in Python and have experience with Python for AI (pytorch/tensorflow2/opencv) / Data Science (numpy/pandas/matplotlib/geopandas) / Flask. I had healthy discussions with Guido Van Rossum (Father / Creator of Python) [image](https://twitter.com/florist_notes/status/1639723261528358916) at Stanford and python is my primary scripting language.

<table width=100%>
<tr>
<th>Python Class</th>
<th>Python Generators</th>
</tr>
<tr>
<td>

```python

#!/usr/bin/python

class Employee:
   'Common base class for all employees'
   empCount = 0

   def __init__(self, name, salary):
      self.name = name
      self.salary = salary
      Employee.empCount += 1
   
   def displayCount(self):
     print("Total Employee %d" % Employee.empCount)

   def displayEmployee(self):
      print("Name : ", self.name, ", Salary: ", self.salary)

print(" 🌸 Employee.__doc__:", Employee.__doc__)
print(" 🌸 Employee.__name__:", Employee.__name__)
print(" 🌸 Employee.__module__:", Employee.__module__)
print(" 🌸 Employee.__bases__:", Employee.__bases__)
print(" 🌸 Employee.__dict__:", Employee.__dict__)

```

</td>
<td>

```python


# A simple generator for Fibonacci Numbers
def fib(limit):
    # Initialize first two Fibonacci Numbers
    a, b = 0, 1
    # One by one yield next Fibonacci Number
    while a < limit:
        yield a
        a, b = b, a + b
# Create a generator object
x = fib(5)

print(next(x))
print(next(x))
print(next(x))
print(next(x))
print(next(x))
 
print("\nUsing for in loop")
for i in fib(5):
    print(i)

```

</td>
</tr>
</table>

Built-In Class Attributes : 
Every Python class keeps following built-in attributes and they can be accessed using dot operator like any other attribute:

 + `__dict__` − Dictionary containing the class's namespace.

 + `__doc__ `− Class documentation string or none, if undefined.

 + `__name__` − Class name.

 + ` __module__` − Module name in which the class is defined. This attribute is "`__main__`" in interactive mode.

 + `__bases__ `− A possibly empty tuple containing the base classes, in the order of their occurrence in the base class list.

I did lot of EDA in python with numpy/pandas/geopandas and matplotlib/plotly. I have a sample [py-notebook](./code/src/anom_graphfinale.ipynb) I wrote professionally to process and visualize time series anomaly data. I fetched data from API, stored it as mongodb geojson document and worked on processing as well as anomaly detection of data . I created plotly graph objects to visualize the pandas data frame objects interactively ([visualize.html](./code/src/MQ27.html)) :

<img src="./code/src/anom.gif" width=100%>

I did py geo data work and my notes are @github/[webappmap](https://github.com/florist-notes/linux_d/blob/main/proj/maps.MD). Some important documents and notes to keep handy: [py-chs](./doc/csh/python-cheatsheets.pdf) and [py-notebooks](./code/). I have been writing deep learning code in PyTorch and are @ [PyTorch](https://github.com/florist-notes/aicore_n/blob/main/notes/pyt.MD), [TensorFlow](https://github.com/florist-notes/aicore_n/blob/main/notes/tf.MD) and [dl-code](https://github.com/florist-notes/aicore_n/blob/main/notes/dlcode.MD).

resources : [py-notebooks](./code/), [py-cheatsheets](./doc/), [py-deepdive](https://github.com/fbaptiste/python-deepdive), [pep-8](https://peps.python.org/pep-0008/), [py-design-patterns](https://refactoring.guru/design-patterns/python), [python-patterns.guide](https://python-patterns.guide/), [python-patterns](https://github.com/faif/python-patterns) ; py-pm: [anaconda](https://www.anaconda.com/), [mamba](https://mamba.readthedocs.io/en/latest/), [pip](https://pypi.org/project/pip/), [jupyter](https://jupyter.org/); csheets : [py-libraries](./doc/csh/python-cheatsheets.pdf), [pandas](./doc/Pandas_Cheat_Sheet.pdf), [numpy](./code/Lecture-2-Numpy.ipynb), [matplotlib](./code/Lecture-4-Matplotlib.ipynb); [What does if __name__ == "__main__": do?](https://stackoverflow.com/questions/419163/what-does-if-name-main-do). Opensource python libraries @[[aitools-py](https://github.com/florist-notes/aicore_n/blob/main/notes/aitools.MD)], [[google code style guide - python](https://google.github.io/styleguide/pyguide.html)].




















