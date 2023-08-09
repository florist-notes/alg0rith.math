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

