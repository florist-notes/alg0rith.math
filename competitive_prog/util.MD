# C++ Utilities and Libraries

C++ includes a variety of utility libraries that
provide functionality ranging from
bit-counting to partial function application.
These libraries can be broadly divided into
two groups:
+ language support libraries.
+ general-purpose libraries.

Language support :  Provide classes and functions that interact
closely with language features and support
common language idioms. Type support(`std::size_t`), Dynamic memory, management(`std::shared_ptr`), Error handling(`std::exception`, `assert`), Initializer list(`std::vector{1, 2}`), Much more...

General-purpose Utilities : Program utilities(`std::abort`), Date and Time(`std::chrono::duration`), Optional, variant and any(`std::variant`), Pairs and tuples(`std::tuple`), Swap, forward and move(`std::move`), Hash support(`std::hash`).

<table width=100%>
<tr>
<th>std::swap</th>
<th>std::variant</th>
</tr>
<tr>
<td>

```cpp
 int main () { 
    int a = 3; 
    int b = 5;
    // before  
    std :: cout << a << ' ' << b << '\n';
    std :: swap(a, b); 
    // after
    std :: cout << a << ' ' << b << '\n';
}


```

</td>
<td>

```cpp

 int main () {
 std :: variant <int, float > v1;
 v1 = 12; // v contains int
 cout << std ::get <int >(v1) << endl;
 std :: variant <int, float > v2 {3.14F};
 cout << std ::get <1>(v2) << endl;

 v2 = std ::get <int >(v1); // assigns v1 to v2
 v2 = std ::get <0>(v1); // same as previous line
 v2 = v1; // same as previous line
 cout << std ::get <int >(v2) << endl;
 }

```

</td>
</tr>

<tr>
<th>std::any</th>
<th>std::optional</th>
</tr>
<tr>
<td>

```cpp

 int main () {
 std :: any a; // any type

 a = 1; // int
 cout << any_cast <int >(a) << endl;

 a = 3.14; // double
 cout << any_cast <double >(a) << endl;

 a = true; // bool
 cout << std :: boolalpha << any_cast <bool >(a) << endl;
 }

```

</td>
<td>

```cpp

 std :: optional <std :: string > StringFactory (bool create) {
 if (create) {
 return "Modern C++ is Awesome";
 }
 return {};
 }

 int main () {
cout << StringFactory (true).value () << '\n';
 cout << StringFactory (false).value_or (":(") << '\n';
}

```

</td>
</tr>

<tr>
<th>std::tuple</th>
<th>std::chrono</th>
</tr>
<tr>
<td>

```cpp

 int main () {
 std ::tuple <double , char , string > student1;
 using Student = std ::tuple <double , char , string >;
 Student student2 {1.4 , 'A', "Jose"};
 PrintStudent (student2);
 cout << std ::get <string >( student2) << endl;
 cout << std ::get <2>( student2) << endl;

 // C++17 structured binding:
 auto [gpa , grade , name] = make_tuple (4.4 , 'B', "");
}


```

</td>
<td>

```cpp

 #include <chrono>

 int main () {
 auto start = std :: chrono :: steady_clock :: now ();
 cout << "f(42) = " << fibonacci (42) << '\n';
 auto end = chrono :: steady_clock :: now ();

 chrono :: duration <double > sec = end - start;
 cout << "elapsed time: " << sec.count () << "s\n";
}

```

</td>
</tr>
</table>

Error handling with exceptions : To use exceptions: `#include <stdexcept>`, Base class: `std::exception`.