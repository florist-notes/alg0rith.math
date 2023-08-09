# Standard Template Library (STL)

Some of the key components of the STL include:
- Containers: The STL provides a range of containers, such as vector, list, map, set, and stack, which can be used to store and manipulate data.
- Algorithms: The STL provides a range of algorithms, such as sort, find, and binary_search, which can be used to manipulate data stored in containers.
- Iterators: Iterators are objects that provide a way to traverse the elements of a container. The STL provides a range of iterators, such as forward_iterator, bidirectional_iterator, and random_access_iterator, that can be used with different types of containers.
- Function Objects: Function objects, also known as functors, are objects that can be used as function arguments to algorithms. They provide a way to pass a function to an algorithm, allowing you to customize its behavior.
- Adapters: Adapters are components that modify the behavior of other components in the STL. For example, the reverse_iterator adapter can be used to reverse the order of elements in a container.


```cpp

#include <iostream>
#include <vector>
using namespace std;
 
int main() {

   // create a vector to store int
   vector<int> vec; 
   int i;

   // display the original size of vec
   cout << "vector size = " << vec.size() << endl;

   // push 5 values into the vector
   for(i = 0; i < 5; i++) {
      vec.push_back(i);
   }

   // display extended size of vec
   cout << "extended vector size = " << vec.size() << endl;

   // access 5 values from the vector
   for(i = 0; i < 5; i++) {
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
   }

   // use iterator to access the values
   vector<int>::iterator v = vec.begin();
   while( v != vec.end()) {
      cout << "value of v = " << *v << endl;
      v++;
   }

   return 0;
}

```

<table width=100%>

<tr>
<th>std::array</th>
<th>std::vector</th>
</tr>
<tr>
<td>

First item: `arr.front() == arr[0]` and Last item: `arr.back() == arr[arr.size() - 1`.

```cpp

 #include <array>
 #include <iostream>
 using std :: cout;
 using std :: endl;

 int main () {
 std ::array <float , 3> data {10.0F, 100.0F, 1000.0F};

 for (const auto& elem : data) {
 cout << elem << endl;
 }

 cout << std :: boolalpha ;
 cout << "Array empty: " << data.empty() << endl;
 cout << "Array size : " << data.size() << endl;
 }

```

</td>
<td>

Vector is implemented as a dynamic table. Remove all elements: `vec.clear()`. Add a new item in one of two ways:
`vec.emplace_back(value)` [preferred, c++11]. reserve(n) ensures that the vector has enough memory to store n items (useful optimization).


```cpp
#include <iostream>
#include <string>
#include <vector>
using std :: cout;
using std :: endl;

int main () {
std :: vector <int> numbers = {1, 2, 3};
std :: vector <std :: string > names = {"Nacho", "Cyrill"};

 names.emplace_back ("Roberto");

 cout << "First name : " << names.front()<< endl;
 cout << "Last number: " << numbers.back()<< endl;
 return 0;
 }

```
Optimize vector resizing:

```cpp

 int main () {
 const int N = 100;

 vector <int> vec; // size 0, capacity 0
 vec.reserve(N); // size 0, capacity 100
 for (int i = 0; i < N; ++i) {
 vec.emplace_back (i);
 }
 // vec ends with size 100, capacity 100

 vector <int> vec2; // size 0, capacity 0
 for (int i = 0; i < N; ++i) {
 vec2.emplace_back (i);
 }
 // vec2 ends with size 100, capacity 128
 }

```
</td>
</tr>


<tr>
<th>Containers in CV (Open3D::PointCloud)</th>
<th>std::map</th>
</tr>
<tr>
<td>

```cpp

std::vector <Eigen :: Vector3d> points_;
std::vector <Eigen :: Vector3d> normals_;
std::vector <Eigen :: Vector3d> colors_;
```

sizeof():

```cpp

 int data [17];
 size_t data_size = sizeof(data) / sizeof(data [0]);
 printf("Size of array: %zu\n", data_size );

```
size():

```cpp

 std ::array <int, 17> data_ {};
 cout << "Size of array: " << data_.size () << endl;

```
Empty Container : No standard way of checking if empty

```cpp

 int empty_arr [10];
 printf("Array empty: %d\n", empty_arr [0] == NULL);

 int full_arr [5] = {1, 2, 3, 4, 5};
 printf("Array empty: %d\n", full_arr [0] == NULL);

```

empty():


```cpp

 std :: vector <int> empty_vec_ {};
 cout << "Array empty: " << empty_vec_ .empty () << endl;

 std :: vector <int> full_vec_ {1, 2, 3, 4, 5};
 cout << "Array empty: " << full_vec_ .empty () << endl;


```
Access last element : No robust way of doing it

```cpp
 float f_arr[N] = {1.5 , 2.3};
 // is it 3, 2 or 900?
 printf("Last element: %f\n", f_arr [3]);
```
back():
```cpp
 std ::array <float , 2> f_arr_ {1.5 , 2.3};
 cout << "Last Element: " << f_arr_.back () << endl;
```
Clear elements : External function call, doesn’t always
work with floating points
```cpp
 char letters [5] = {'n', 'a', 'c', 'h', 'o'};
 memset(letters , 0, sizeof(letters));

```
clear():
```cpp
 std :: vector <char > letters_ = {'n', 'a', 'c', 'h', 'o'};
 letters_.clear ();

```
Remember std::string:
```cpp
std :: string letters_right_ {"nacho"};
letters_right_ .clear ();


```




</td>
<td>

Sorted associative container and Contains key-value pairs (dictionaries dict in Python).

```c++

 #include <iostream >
 #include <map >
 using namespace std;

 int main () {
 using StudentList = std ::map <int, string >;
 StudentList cpp_students ;

 // Inserting data in the students dictionary
 cpp_students .emplace (1509 , "Nacho"); // [1]
 cpp_students .emplace (1040 , "Pepe"); // [0]
 cpp_students .emplace (8820 , "Marcelo"); // [2]

 for (const auto& [id , name] : cpp_students ) {
 cout << "id: " << id << ", " << name << endl;
 }

 return 0;
 }


```
Create from data: ` std ::map <KeyT , ValueT > m{{key1 , value1}, {..}};`

Check size: `m.size();`

Add item to map: `m.emplace(key, value);`

Modify or add item: `m[key] = value;`

Get (const) ref to an item: `m.at(key);`

Check if key present: `m.count(key) > 0;`

Check if key present: `m.contains(key)` [bool]


</td>
</tr>

<tr>
<th>std::unordered_map</th>
<th>Open3D::VoxelGrid</th>
</tr>
<tr>
<td></td>
<td></td>
</tr>

</table>



resources: [The C++ Standard Template Library (STL)](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/), [cplusplus/stl](https://cplusplus.com/reference/stl/)
