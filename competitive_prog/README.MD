# C++, CV and CMake 🌸

A short introduction to C++ for AI and Robotics:

```
        🌸

        
                🌸                                              🌸
                         🌸                     c + +
                                                                                        🌸
        🌸
                                        🌸
                                                        🌸                    
                                                        
                                                                          🌸
```

### NOTES : [ [Functions](./doc/fn.MD) , [Standard Template Library (STL)](./doc/stl.MD), [Utilities & Libraries](./doc/util.MD), [OpenCV](./doc/opencv.MD), [Math Libraries](./doc/mathcpp.MD) ]

I am comfortable with c++ build systems and c++ was my first programming language that I used extensively throughout high school. I have an overview note on problem solving with c++:


<table width="100%">
<tr>
<th>C++ Iterators:</th>
<th>C++ Enumeration:</th>
</tr>

<tr>
<td>

Iterators are objects that point to elements within a container. They provide a way to traverse through the elements of a container (like arrays, vectors, lists, etc.). Iterators can be incremented (to move to the next element) or decremented (to move to the previous element).

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Using an iterator to traverse the vector
    std::vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
</td>

<td>

Enumeration (enum) is a user-defined data type in C++ that consists of integral constants. Each enum variable is assigned an integer value by default.

```cpp
#include <iostream>

enum Color { RED, GREEN, BLUE };

int main() {
    Color c = RED;
    
    if (c == RED) {
        std::cout << "The color is red." << std::endl;
    }

    return 0;
}
```
</td>
</tr>

<tr>
<th>C++ Bitset:</th>
<th>C++ Map:</th>
</tr>

<tr>
<td>

The bitset class in C++ is used to store a fixed-size sequence of bits. Each bit can be accessed individually, and bitwise operations can be performed.

```cpp
#include <iostream>
#include <bitset>

int main() {
    std::bitset<8> bs1(std::string("1100"));
    std::bitset<8> bs2(std::string("1010"));

    // Bitwise AND
    std::bitset<8> bs_and = bs1 & bs2;
    std::cout << "AND: " << bs_and << std::endl;

    // Bitwise OR
    std::bitset<8> bs_or = bs1 | bs2;
    std::cout << "OR: " << bs_or << std::endl;

    // Bitwise XOR
    std::bitset<8> bs_xor = bs1 ^ bs2;
    std::cout << "XOR: " << bs_xor << std::endl;

    return 0;
}
```
</td>

<td>
A map is an associative container that stores key-value pairs. Each key is unique, and the values can be accessed using the keys.

```cpp
#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    // Inserting elements into the map
    myMap[1] = "One";
    myMap[2] = "Two";
    myMap[3] = "Three";

    // Accessing elements
    std::cout << "Key 1: " << myMap[1] << std::endl;

    // Iterating through the map
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
```
</td>
</tr>

<tr>
<th>C++ Multimap:</th>
<th>C++ Templates:</th>
</tr>

<tr>
<td>
A multimap is similar to a map, but it allows multiple elements to have the same key.

```cpp
#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> myMultimap;

    // Inserting elements into the multimap
    myMultimap.insert({1, "One"});
    myMultimap.insert({1, "Uno"});
    myMultimap.insert({2, "Two"});

    // Accessing elements
    auto range = myMultimap.equal_range(1);
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
```
</td>

<td>

Templates allow writing generic programs that can work with any data type. They are particularly useful for creating functions and classes that operate on different data types.

```cpp
#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << "Int: " << add<int>(2, 3) << std::endl;
    std::cout << "Double: " << add<double>(2.5, 3.5) << std::endl;

    return 0;
}
```
</td>
</tr>

<tr>
<th>C++ Files and Streams:</th>
<th>C++ Algorithms:</th>
</tr>

<tr>
<td>
C++ provides classes to perform file input and output. The `ifstream` class is used for reading from files, and the `ofstream` class is used for writing to files.

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream outFile("example.txt");
    outFile << "Hello, World!" << std::endl;
    outFile.close();

    std::ifstream inFile("example.txt");
    std::string content;
    std::getline(inFile, content);
    std::cout << "File content: " << content << std::endl;
    inFile.close();

    return 0;
}
```
</td>

<td>

The C++ Standard Library provides a collection of algorithms that can be used to perform various operations on containers.

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> vec = {1, 3, 2, 5, 4};

    // Sorting the vector
    std::sort(vec.begin(), vec.end());

    // Displaying the sorted vector
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Finding an element
    auto it = std::find(vec.begin(), vec.end(), 3);
    if (it != vec.end()) {
        std::cout << "Element found: " << *it << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
```
</td>
</tr>

<tr>
<th>C++ Namespaces:</th>
<th>C++ Math Functions:</th>
</tr>

<tr>
<td>

Namespaces are used to organize code into logical groups and to prevent name collisions. The `std` namespace is the most commonly used namespace in C++.

```cpp
#include <iostream>

namespace myNamespace {
    void myFunction() {
        std::cout << "Hello from myNamespace" << std::endl;
    }
}

int main() {
    myNamespace::myFunction();
    return 0;
}
```
</td>

<td>

The C++ Standard Library provides a set of functions to perform mathematical operations, such as `sqrt`, `pow`, `sin`, `cos`, etc.

```cpp
#include <iostream>
#include <cmath>

int main() {
    double x = 9.0;

    std::cout << "Square root of " << x << " is " << sqrt(x) << std::endl;
    std::cout << x << " raised to the power 3 is " << pow(x, 3) << std::endl;
    std::cout << "Sine of 45 degrees is " << sin(45 * M_PI / 180) << std::endl;

    return 0;
}
```
</td>
</tr>

</table>

resources : [ /[cpp competitive ref](./cp/) | [[cpp doc](./doc/)] [CMake tutorial](https://www.youtube.com/watch?v=nlKcXPUJGwA&list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4) [[How to Properly Setup C++ Projects](https://youtu.be/5glH8dGoeCA?si=nkwRWgvsitERl3L9)] [[Making and Working with Libraries in C++](https://youtu.be/Wt4dxDNmDA8?si=eBW6m8PqW0slulwi)] [[C++](https://www.youtube.com/watch?v=18c3MTX0PK0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)]

<img src="img/stdio.png" width=48%> <img src="img/stdio2.png" width=48%>

```cpp

1       #include <iostream>
2
3       int main () {
4       // cpp 🌸
5       std :: cout << "Hello World!" << std :: endl;
6       return 0;
7       }

```

`$ c++ file.cpp` > `$ ./a.out` > `$ ./a.out l> stdout.txt`.  Use `clang_format` to format your code


`main()` is a function that returns an error code
+ Error code 0 means OK
+ Error code can be any number in [1, 255]

```cpp

1       int main () {
2       return 0; // Program finished without errors.
3       }


1       int main () {
2       return 1; // Program finished with error code 1.
3       }


```

`#include <file>` — system include files ; `#include "file"` — local include files

+ std::cin — maps to stdin ; std::cout — maps to stdout ; std::cerr — maps to stderr
+ cpp keywords : [list](https://en.cppreference.com/w/cpp/keyword), cpp types [list](https://en.cppreference.com/w/cpp/language/types) & cpp expressions : [list](https://en.cppreference.com/w/cpp/language/expressions). Avoid `==` for floating point types.
+ Use `&` to state that a variable is a reference:
   - `float& ref = original_variable;`
   - `std::string& hello_ref = hello;`
  
Whatever happens to a reference happens to the variable and vice versa. Yields performance gain as references avoid copying data.
 
```cpp
 const , auto , friend , false , ... ///< C++ Keywords
 // comment type 1
 /* comment type 2 */
 /* comment type 3
 BLOCK COMMENT
 */
 "Hello C++ \n"; ///< "\n" is an escape character

 3.5f; // value entity
 std :: string str1; // object entity
 namespace std; // namespace entity
 void MyFunc (); // function entity
 const int& a = b; // reference entity
 enum MyEnum {}; // enum enityty
 #define UGLY_MACRO (X) // NOT a C++ entity

 float a; // float is the fundamental type of a
 bool b; // bool is fundamental

 MyType c; // MyType is user defined , incomplete
 MyType c{}; // MyType is user defined , complete

 std :: vector; // Also , user -defind type
 std :: string; // Also , user -defind type

```

Compilation is translation from text to machine code. Two compilers : { Clang, gcc }

```bash

        $ c++ -std=c++11 -o hello_world hello_world .cpp
        $ ./ hello_world

```

<img src="img/cpp_code.png" width=100%> 

+ Preprocess : `$ clang++ -E main.cpp > main.i`
+ Compilation : `$ clang++ -S main.i`
+ Assembly : `$ clang++ -c main.s`
+ Linking : `$ clang++ main.o -o main`

Compilation flags : `-std=c++17,`, `-Wall`, `-Wextra`, `-Werror` | Optimization options:
`-O0` — no optimizations [default]
`-O3` or `-Ofast` — full optimizations. Keep debugging symbols: `-g`.



Tools: [GNU/Linux]() { filesystem, terminal, standard input/output } ; [Text Editor]() { configuring, terminal, compile, debug } ; [Build Systems]() { headers/sources, libraries, compilation flags, cmake, 3rd paty libraries } ; [Git]() ; [gdb]() ; [Web-based tools]() { Quick Bench, Compiler  Explorer, cpp insights, cppreference.com } ; [Clang-tools](https://apt.llvm.org/) {Clang-format, Clang-tidy, Clangd, Cppcheck} ; [Google test](), [OpenCV](). Install llvm-toolchain from [here](https://apt.llvm.org/).


Install - git : `$ sudo apt install git`, build tools : ` $ sudo apt install build-essential`, cmake : ` $ sudo apt install cmake`, cppcheck : ` $ sudo apt install cppcheck`, clang-tools ` $ sudo apt install clang-format clang-tidy clangd`.

```bash
        $ sudo apt update
        $ sudo apt install git build-essential cmake cppcheck clang-format clang-tidy clangd
```

In VS Code for c++ extensions : CTRL + P , then execute `ext install ms-vscode.cpptools` and `ext install llvm-vs-code-extensions.vscode-clangd`; for CMake extensions : `ext install twxs.cmake`, `ext install ms-vscode.cmake-tools` and `ext install cheshirekow.cmake-format`; for markdown extensions `ext install yzhang.markdown-all-in-one` and `ext install DavidAnson.vscode-markdownlint`.

MY CODE:

<table width=100%>
<tr>
<th>Python</th>
<th>C++ 17</th>
</tr>

<tr>
<td>

```python
 my_dict = {'a': 27, 'b': 3}
 for key , value in my_dict.items ():
        print(key , "has value", value)

 ```
</td>
<td>

```cpp
 std ::map <char , int> my_dict {{'a', 27}, {'b', 3}};
 for (const auto& [key , value] : my_dict) {
        cout << key << " has value " << value << endl;
 }
 ```
</td>
</tr>
</table>
Spoiler alert : The C++ is ≈15 times faster than Python!

Core c++ : [control structures (if, for , while) ](https://cplusplus.com/doc/oldtutorial/control/), [switch](./code/switch.cpp), [I/O streams](https://en.cppreference.com/w/cpp/io), [stringstream](./code/stringstream.cpp), [Functions](https://www.w3schools.com/cpp/cpp_functions.asp), [c++ strings](https://cplusplus.com/reference/string/string/), [Pass by value / Pass by reference](https://www.tutorialspoint.com/differences-between-pass-by-value-and-pass-by-reference-in-cplusplus), [Namespaces](https://en.cppreference.com/w/cpp/language/namespace), [Containers](https://en.cppreference.com/w/cpp/container), [std::tuple](https://en.cppreference.com/w/cpp/utility/tuple), [Iterators](https://en.cppreference.com/w/cpp/iterator/iterator), [try/ catch](https://en.cppreference.com/w/cpp/language/try_catch), [enum classes](https://www.geeksforgeeks.org/enum-classes-in-c-and-their-advantage-over-enum-datatype/), [STL library](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/), [STL algorithms](https://en.cppreference.com/w/cpp/algorithm), [Function Overloading](https://www.geeksforgeeks.org/function-overloading-c/), [Operator Overloading](https://en.cppreference.com/w/cpp/language/operators), [String streams](https://cplusplus.com/reference/sstream/stringstream/stringstream/), [filesystem](https://en.cppreference.com/w/cpp/filesystem)

Program input parameters : `int main(int argc, char const *argv[]);
` , where `argc` defines number of input parameters and `argv` is an array of string parameters. By default:  `argc == 1` &  `argv == "<binary_path>"`.



Modern c++ :  [Classes](https://www.geeksforgeeks.org/c-classes-and-objects/), [Const Correctness](https://www.cprogramming.com/tutorial/const_correctness.html), [typedef / using](https://www.geeksforgeeks.org/typedef-in-cpp/), [static variables / methods](https://www.tutorialspoint.com/cplusplus/cpp_static_members.htm), [Move semantics](https://www.cprogramming.com/c++11/rvalue-references-and-move-semantics-in-c++11.html), [Special functions](https://en.cppreference.com/w/cpp/numeric/special_functions), [Singleton pattern](https://www.geeksforgeeks.org/implementation-of-singleton-class-in-cpp/), [Inheritence](https://www.geeksforgeeks.org/inheritance-in-c/), [Function Overriding](https://www.geeksforgeeks.org/function-overriding-in-cpp/), [Abstract classes](https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/), [Interfaces](https://www.tutorialspoint.com/cplusplus/cpp_interfaces.htm), [Strategy Pattern](https://refactoring.guru/design-patterns/strategy/cpp/example), [Polymorphism](https://www.geeksforgeeks.org/cpp-polymorphism/), [Typecasting](https://www.javatpoint.com/type-casting-in-cpp), [Memory Management](https://www.programiz.com/cpp-programming/memory-management), [Stack vs Heap](https://www.geeksforgeeks.org/stack-vs-heap-memory-allocation/), [Pointers](https://www.geeksforgeeks.org/cpp-pointers/), [new / delete](https://www.geeksforgeeks.org/new-and-delete-operators-in-cpp-for-dynamic-memory/), [this pointer](https://www.geeksforgeeks.org/this-pointer-in-c/), [Memory issues](https://www.geeksforgeeks.org/memory-leak-in-c-and-how-to-avoid-it/), [RAII](https://en.cppreference.com/w/cpp/language/raii), [Smart pointers](https://en.cppreference.com/book/intro/smart_pointers), [Generic programming](https://www.javatpoint.com/generic-programming-in-cpp), [Template functions](https://en.cppreference.com/w/cpp/language/function_template), [Template classes](https://en.cppreference.com/w/cpp/language/class_template), [Static code generation](#), [lambdas](https://en.cppreference.com/w/cpp/language/lambda).

## C++ Build System: CMake

Library: multiple object files that are logically connected. Types of libraries:
- Static: faster, take a lot of space, become part
of the end binary, named: `lib*.a`
- Dynamic: slower, can be copied, referenced by a
program, named `lib*.so` .

Create a static library with
` $ ar rcs libname.a module.o module.o …`.  Static libraries are just archives just like `zip/tar/…`.

Header / Source Separation :
Move all declarations to header files (`*.hpp`) and Implementation goes to `*.cpp` or `*.cc`.

```cpp
1       // some_file.hpp
2       Type SomeFunc (... args ...);
3
4       // some_file.cpp
5       #include "some_file.hpp"
6       Type SomeFunc (... args ...) {} // implementation
7
8       // program.cpp
9       #include "some_file.hpp"
10      int main () {
11      SomeFunc(/* args */);
12      return 0;
13      }
```

To use a library we need:
1. A header file `library_api.h`
2. The compiled library object `libmylibrary.a`
   
         folder/
         --- tools.hpp
         --- tools.cpp
         --- main.cpp


<table style="width:100%" >
<tr>
<th>tools.hpp</th>
<th>tools.cpp</th>
<th>main.cpp</th>
</tr>

<tr>
<td>

```cpp

#pragma once // Ensure file is included only once
void MakeItSunny ();
void MakeItRain ();

```
</td>
<td>

```cpp

#include "tools.hpp"
#include <iostream >
void MakeItRain () {
// important weather manipulation code
std :: cout << "Here! Now it rains! Happy?\n";
}
void MakeItSunny () { std :: cerr << "Not available\n"; }
```

</td>
<td>

```cpp

#include "tools.hpp"
int main () {
MakeItRain ();
MakeItSunny ();
return 0;
}
```
</td>
</tr>
</table>

Compile modules: ` $ c++ -std=c++17 -c tools.cpp -o tools.o`

Organize modules into libraries: ` $ ar rcs libtools.a tools.o`

Link libraries when building code: ` $ c++ -std=c++17 main.cpp -L . -ltools -o main`

Run the code: ` $ ./main`

### CMake : Does not build the code, generates files to feed into a build system

Build process : ` $ cd <project_folder>` > ` $ . mkdir build ` > ` $ cd build ` > ` $ cmake .. ` > ` $ make `.

The build process is completely defined in `CMakeLists.txt` and childrens `src/CMakeLists.txt`, etc. 

<b>CMakeLists.txt</b>:

```cmake
        cmake_minimum_required(VERSION 3.1) # Mandatory.
        project( first_project ) # Mandatory.
        set( CMAKE_CXX_STANDARD 17) # Use c++17.

        # tell cmake where to look for *.hpp, *.h files
        include_directories(include /)

        # create library "libtools"
        add_library(tools src/tools.cpp) # creates libtools.a

        # add executable main
        add_executable(main src/tools_main.cpp) # main.o

        # tell the linker to bind these objects together
        target_link_libraries(main tools) # ./main

```

Automatically detects changes and after doing changes: ` $ . cd <project_folder>/build` and ` $ make`.


<table style="width:100%" >
<tr>
<th>project structure:</th>
<th>CMake compilation options</th>
</tr>

<tr>
<td>


```cmake

 |-- project_name /
 | |-- CMakeLists .txt
 | |-- build/ # All generated build files
 | |-- results/ # Executable artifacts
 | | |-- bin/
 | | |-- tools_demo
 | | |-- lib/
 | | |-- libtools.a
 | |-- include/ # API of the project
 | | |-- project_name
 | | |-- library_api .hpp
 | |-- src/
 | | |-- CMakeLists .txt
 | | |-- project_name
 | | |-- CMakeLists .txt
 | | |-- tools.hpp
 | | |-- tools.cpp
 | | |-- tools_demo .cpp
 | |-- tests/ # Tests for your code
 | | |-- test_tools .cpp
 | | |-- CMakeLists .txt
 | |-- README.md # How to use your code

```

</td>
<td>

```cmake

 set( CMAKE_CXX_STANDARD 17)

 # Set build type if not set.
 if(NOT CMAKE_BUILD_TYPE )
 set( CMAKE_BUILD_TYPE Debug)
 endif ()
 # Set additional flags.
 set( CMAKE_CXX_FLAGS "-Wall -Wextra ")
 set( CMAKE_CXX_FLAGS_DEBUG "-g -O0")


```

`-Wall` `-Wextra`: show all warnings; `-g`: keep debug information in binary; `-O<num>`: optimization level in {0, 1, 2, 3} where 0: no optimization and 3: full optimization.

Useful commands in CMake: Set variables with `set(VAR VALUE)`, Get value of a variable with `${VAR}`, Show a message `message(STATUS "message")`, Also possible `WARNING`, `FATAL_ERROR`.

In ` $ make -j2` # pass your number of cores here and ` $ make clean` to remove generated binaries`.

</td>
</tr>

</table>

Use pre-compiled library:  `find_package` calls multiple `find_path` and `find_library` functions. To use `find_package(<pkg>)` CMake must
have a file `Find<pkg>.cmake` in `CMAKE_MODULE_PATH` folders. `Find<pkg>.cmake` defines which libraries and headers belong to package `<pkg>`.



<table style="width:100%" >
<tr>
<th>CMakeLists.txt</th>
<th>cmake_modules/Findsome_pkg.cmake</th>
</tr>

<tr>
<td>


```cmake

 cmake_minimum_required(VERSION 3.1)
 project( first_project )

 # CMake will search here for Find <pkg >.cmake files
 SET( CMAKE_MODULE_PATH
 ${PROJECT_SOURCE_DIR}/ cmake_modules )

 # Search for Findsome_pkg.cmake file and load it
 find_package(some_pkg )

 # Add the include folders from some_pkg
 include_directories(${some_pkg_INCLUDE_DIRS})

 # Add the executable "main"
 add_executable(main small_main .cpp)
 # Tell the linker to bind these binary objects
 target_link_libraries(main ${some_pkg_LIBRARIES})


```

</td>
<td>

```cmake

# Find the headers that we will need
find_path( some_pkg_INCLUDE_DIRS include/some_lib.hpp < FOLDER_WHERE_TO_SEARCH >)
message(STATUS "headers: ${some_pkg_INCLUDE_DIRS}")

# Find the corresponding libraries
find_library( some_pkg_LIBRARIES
NAMES some_lib_name
PATHS <FOLDER_WHERE_TO_SEARCH >)
message(STATUS "libs: ${some_pkg_LIBRARIES}")
```
</td>
</tr>

</table>




resources: [mathematical optimizations with google or-tool](https://developers.google.com/optimization/introduction/cpp), [SNOPT](https://ccom.ucsd.edu/~optimizers/solvers/snopt/), [IPOPT](https://github.com/coin-or/Ipopt), [Conic Bundle](https://www-user.tu-chemnitz.de/~helmberg/ConicBundle/Manual/index.html), [Computer Vision and OpenCV in c++](https://www.youtube.com/watch?v=uJrwLq_BKPY&list=PLkmvobsnE0GHMmTF7GTzJnCISue1L9fJn), [Computer Vision Projects - C++](https://www.youtube.com/watch?v=9iEPzbG-xLE&list=PLMoSUbG1Q_r8jFS04rot-3NzidnV54Z2q), [Modern c++](https://www.youtube.com/watch?v=sZK6ouwREXA&list=PLgnQpQtFTOGRM59sr3nSL8BmeMZR9GCIA), [google code styling guide - c++](https://google.github.io/styleguide/cppguide.html), [The C++ Programming Language (4th Edition)](https://www.stroustrup.com/4th.html), [cppreference](https://en.cppreference.com/w/cpp), [ " Give me 15 minutes & I'll change your view of GDB"](https://youtu.be/PorfLSr3DDI), [cpp tutorial](https://cplusplus.com/doc/tutorial/), [cpp core guidelines](https://github.com/isocpp/CppCoreGuidelines), [Learn Robotics with C++ in 1 Hour ](https://youtu.be/xVtoWTvXQrs?si=di0sS6cOw0sd4HFp), [Advice for getting a PhD in robotics | Boris Sofman and Lex Fridman](https://youtu.be/YHnpagQnqZ0?si=SY-RPydd3vWTKWrN), [Programming a Wireless Robotic Arm](https://youtu.be/ekdQ-aAB36Y?si=fDohV5XhdoV1rFnb), [Practical Polymorphism C++](https://youtu.be/kxKKHKSMGIg?si=KJiH2CXQNxzwPjJG), [Path Planning #2 Wave Propagation, Potential Fields & Modern(ish) C++](https://youtu.be/0ihciMKlcP8?si=eWliibIkTtRSnkgZ).