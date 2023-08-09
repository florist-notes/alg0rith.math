# C++ Functions :

 `void` , also called subroutine. Automatic return type deduction C++14):

 ```cpp

 std ::map <char , int> GetDictionary () {
    return std ::map <char , int >{{'a', 27}, {'b', 3}};
 }
 
 ```

 Can be expressed as:

```cpp
auto GetDictionary () {
  return std ::map <char , int >{{'a', 27}, {'b', 3}};
}

 ```

Sadly you can use only one type for return
values, so, no Python like:

```python
 #!/usr/bin/env python3
 def foo ():
 return "Super Variable", 5


 name , value = foo ()
 print(name + " has value: " + str(value))

```

With the introduction of structured binding in
C++17 you can now:

```cpp
 #include <iostream>
 #include <tuple>
 using namespace std;

 auto Foo () {
    return make_tuple ("Super Variable", 5);
 }

 int main () {
    auto [name , value] = Foo ();
    cout << name << " has value :" << value << endl;
    return 0;
 }

```

### Strings

+ `#include <string>` to use `std::string`
+ Check if `str` is empty with `str.empty()`

```cpp

 #include <iostream>
 #include <string>

 int main () {
 const std :: string source{"Copy this!"};
 std :: string dest = source; // copy string

 std :: cout << source << '\n';
 std :: cout << dest << '\n';
 return 0;
}

```

## Return Value Optimization ([RVO](https://en.wikipedia.org/wiki/Copy_elision#Return_value_optimization)): 


```c++
 Type DoSomething () {
 Type huge_variable ;

 // ... do something

 // don't worry , the compiler will optimize it
 return huge_variable ;
 }
 // ...

Type out = DoSomething (); // does not copy
```

Unless declared static, each local variable invocation has
its own copy. Q : [What’s the “static initialization order ‘fiasco’ (problem)”?](https://isocpp.org/wiki/faq/ctors#static-init-order)

Default arguments: 

```c++
 #include <iostream >
 using namespace std;

 string SayHello(const string& to_whom = "world") {
 return "Hello " + to_whom + "!";
 }

 int main () {
 // Will call SayHello using the default argument
 cout << SayHello () << endl;

 // This will override the default argument
 cout << SayHello("students") << endl;
 return 0;
 }

```

Passing big objects : Pass by reference to avoid copy:

```c++
 void DoSmth(std :: string huge_string ); // Slow.
 void DoSmth(std :: string& huge_string ); // Faster.


```
use const references : `void DoSmth(const std :: string& huge_string ); `
function calls are expensive - use `inline` ; 

```cpp

 inline int fac(int n) {
    if (n < 2) {
      return 2;
   }
   return n * fac(n - 1);
 }

 int main () {
   int fac0 = fac (0);
   int fac1 = fac (1);
   int fac2 = fac (2);
   int fac3 = fac (3);
   int fac4 = fac (4);
   int fac5 = fac (5);
   return fac0 + fac1 + fac2 + fac3 + fac4 + fac5;
 }

```

### C++ style overloading:

<table width=100%>
<tr>
<th>cosine</th>
<th>arctan</th>
</tr>

<tr>
<td>

```cpp
 #include <cmath>

 // ONE cos function to rule them all
 double cos(double x);
 float cos(float x);
 long double cos(long double x);
```

</td>
<td>

```cpp
 #include <cmath>

 double atan(double x);
 float atan(float x);
 long double atan(long double x);
```

</td>
</tr>

<tr>
<td>

```cpp

 #include <cmath>
 #include <iostream>
 using namespace std;

 int main () {
 double x_double = 0.0;
 float x_float = 0.0;
 long double x_long_double = 0.0;

 cout << "cos(0)=" << std :: cos(x_double) << '\n';
 cout << "cos(0)=" << std :: cos(x_float) << '\n';
 cout << "cos(0)=" << std :: cos( x_long_double ) << '\n';

 return 0;
 }

```

</td>
</tr>


</table>

Function overloading : Compiler infers a function from arguments

```cpp

 #include <iostream>
 #include <string>
 using namespace std;
 string TypeOf(int) { return "int"; }
 string TypeOf(const string &) { return "string";}
 int main () {
 cout << TypeOf (1) << endl;
 cout << TypeOf("hello") << endl;
 return 0;
}

```

Good Function Example:


```cpp
 #include <vector>
 using namespace std;

 vector <int> CreateVectorOfZeros (int size) {
 vector <int> null_vector (size);
 for (int i = 0; i < size; ++i) {
 null_vector [i] = 0;
 }
 return null_vector ;
 }

 int main () {
 vector <int> zeros = CreateVectorOfZeros (10);
 return 0;
}

```

## Namespaces:

```cpp

 #include <iostream>

 namespace fun {
 int GetMeaningOfLife (void) { return 42; }
 } // namespace fun

 namespace boring {
 int GetMeaningOfLife (void) { return 0; }
 } // namespace boring

 int main () {
 std :: cout << boring :: GetMeaningOfLife () << std :: endl
 << fun :: GetMeaningOfLife () << std :: endl;
 return 0;
 }

```

Namespaces (Only use what you need): 
```cpp
 #include <cmath>
 #include <iostream>
 using std :: cout; // Explicitly use cout. (avoid using namespace std;)
 using std :: endl; // Explicitly use endl.

 // Self -defined function power shadows std::pow
 double pow(double x, int exp) {
 double res = 1.0;
 for (int i = 0; i < exp; i++) {
 res *= x;
 }
 return res;
 }

 int main () {
 cout << "2.0^2 = " << pow (2.0 , 2) << endl;
 return 0;
 }


```

Nameless namespaces : If you find yourself relying on some constants in a file and these constants should not be seen in any other file, put them into a nameless namespace on the top of this file.

```cpp
 namespace {
 const int kLocalImportantInt = 13;
 const float kLocalImportantFloat = 13.0f;
 } 

```
