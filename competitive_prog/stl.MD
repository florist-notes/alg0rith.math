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

 #include <array >
 #include <iostream >
 using std :: cout;
 using std :: endl;

 int main () {
 std ::array <float , 3> data {10.0F, 100.0F, 1000.0F};

 for (const auto& elem : data) {
 cout << elem << endl;
 }

 cout << std :: boolalpha ;
 cout << "Array empty: " << data.empty () << endl;
 cout << "Array size : " << data.size () << endl;
 }

```

</td>
<td>

Vector is implemented as a dynamic table. Remove all elements: `vec.clear()`. Add a new item in one of two ways:
`vec.emplace_back(value)` [preferred, c++11]. reserve(n) ensures that the vector has enough memory to store n items (useful optimization).


```cpp
#include <iostream >
#include <string >
#include <vector >
using std :: cout;
using std :: endl;

int main () {
std :: vector <int> numbers = {1, 2, 3};
std :: vector <std :: string > names = {"Nacho", "Cyrill"};

 names. emplace_back ("Roberto");

 cout << "First name : " << names.front () << endl;
 cout << "Last number: " << numbers.back () << endl;
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
 vec. emplace_back (i);
 }
 // vec ends with size 100, capacity 100

 vector <int> vec2; // size 0, capacity 0
 for (int i = 0; i < N; ++i) {
 vec2. emplace_back (i);
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
<td></td>
<td></td>
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
