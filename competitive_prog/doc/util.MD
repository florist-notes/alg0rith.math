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

### Reading and writing to files:

```cpp

 #include <fstream>
 using std :: string;
 using Mode = std :: ios_base :: openmode;

 // ifstream: stream for input from file
 std :: ifstream f_in(string& file_name , Mode mode);

 // ofstream: stream for output to file
 std :: ofstream f_out(string& file_name , Mode mode);

 // stream for input and output to file
 std :: fstream f_in_out(string& file_name , Mode mode);

```

`ios_base::app` append output, `ios_base::ate` seek to EOF when opened, `ios_base::binary` open file in binary mode, `ios_base::in` open file for reading, `ios_base::out` open file for writing, `ios_base::trunc` overwrite the existing file.

### Reading from ifstream: 


```cpp
 #include <fstream> // For the file streams.
 #include <iostream>
 #include <string>
 using namespace std; // Saving space.
 int main () {
 int i;
 double a, b;
 string s;
 // Create an input file stream.
 ifstream in("test_cols.txt", ios_base ::in);
 // Read data , until it is there.
 while (in >> i >> a >> s >> b) {
 cout << i << ", " << a << ", "
 << s << ", " << b << endl;
 }
 return (0);
 }

```

### Reading files one line at a time:

```cpp
 #include <fstream> // For the file streams.
 #include <iostream>
 using namespace std;
 int main () {
 string line , file_name ;
 ifstream input("test_bel.txt", ios_base ::in);
 // Read data line -wise.
 while (getline(input , line)) {
 cout << "Read: " << line << endl;
 // String has a find method.
 string :: size_type loc = line.find("filename", 0);
 if (loc != string :: npos) {
 file_name = line.substr(line.find("=", 0) + 1,
 string :: npos);
 }
 }
 cout << "Filename found: " << file_name << endl;
 return (0);
 }

```

### Writing into text files:


```cpp
 #include <iomanip> // For setprecision.
 #include <fstream>
 using namespace std;
 int main () {
 string filename = "out.txt";
 ofstream outfile( filename );
 if (! outfile.is_open ()) { return EXIT_FAILURE ; }
 double a = 1.123123123;
 outfile << "Just string" << endl;
 outfile << setprecision (20) << a << endl;
 return 0;
 }

```

<table width=100%>
<tr>
<th>Reading from binary files</th>
<th>Writing to binary files</th>
</tr>
<tr>
<td>

```cpp
 #include <fstream>
 #include <iostream>
 #include <vector>
 using namespace std;
 int main () {
 string file_name = "image.dat";
 int r = 0, c = 0;
 ifstream in(file_name ,
 ios_base ::in | ios_base :: binary);
 if (!in) { return EXIT_FAILURE ; }
 in.read(reinterpret_cast <char*>(&r), sizeof(r));
 in.read(reinterpret_cast <char*>(&c), sizeof(c));
 cout << "Dim: " << r << " x " << c << endl;
 vector <float > data(r * c, 0);
 in.read(reinterpret_cast <char*>(& data.front ()),
 data.size () * sizeof(data.front ()));
 for (float d : data) { cout << d << endl; }
 return 0;
 }

```
</td>
<td>

```cpp
 #include <fstream> // for the file streams
 #include <vector>
 using namespace std;

 int main() {
 string file_name = "image.dat";
 ofstream file(file_name , ios_base ::out | ios_base ::binary);
 int rows = 2;
 int cols = 3;
 vector <float > vec(rows * cols);
 file.write(reinterpret_cast <char*>(&rows), sizeof(rows));
 file.write(reinterpret_cast <char*>(&cols), sizeof(cols));
 file.write(reinterpret_cast <char*>(&vec.front()),
 vec.size() * sizeof(float));
 return 0;
 }

```
</td>
</tr>
</table>

## C++17 Filesystem library:


<table width=100%>
<tr>
<th>directory_iterator</th>
<th>filename</th>
</tr>
<tr>
<td>

```cpp
 #include <filesystem >
 namespace fs = std :: filesystem ;

 int main () {
 fs:: create_directories ("sandbox/a/b");
 std :: ofstream("sandbox/file1.txt");
 std :: ofstream("sandbox/file2.txt");
 for (auto& p : fs:: directory_iterator ("sandbox")) {
 std :: cout << p.path () << '\n';
 }
 fs:: remove_all ("sandbox");
 }


```
</td>
<td>

```cpp
 #include <filesystem >
 namespace fs = std :: filesystem ;

 int main () {
 cout << fs:: path("/foo/bar.txt").filename () << '\n'
 << fs:: path("/foo/.bar").filename () << '\n'
 << fs:: path("/foo/bar/").filename () << '\n'
 << fs:: path("/foo/.").filename () << '\n'
 << fs:: path("/foo/..").filename () << '\n';
 }

```
</td>
</tr>


<tr>
<th>stem</th>
<th>extension</th>
<th>exists</th>
</tr>
<tr>
<td>

```cpp
 #include <filesystem >
 namespace fs = std :: filesystem ;

 int main () {
 cout << fs:: path("/foo/bar.txt").stem () << endl
 << fs:: path("/foo/00000.png").stem () << endl
 << fs:: path("/foo/.bar").stem () << endl;
 }

```
</td>
<td>

```cpp
 #include <filesystem >
 namespace fs = std :: filesystem ;

 int main () {
 cout << fs:: path("/foo/bar.txt"). extension () << '\n'
 << fs:: path("/foo/bar."). extension () << '\n'
 << fs:: path("/foo/bar"). extension () << '\n'
 << fs:: path("/foo/bar.png"). extension () << '\n';
 }

```
</td>
<td>

```cpp
 void demo_exists (const fs:: path& p) {
 cout << p;
 if (fs:: exists(p)) cout << " exists\n";
 else cout << " does not exist\n";
 }

 int main () {
 fs:: create_directory ("sandbox");
 ofstream("sandbox/file"); // create regular file
 demo_exists ("sandbox/file");
 demo_exists ("sandbox/cacho");
 fs:: remove_all ("sandbox");
 }


```
</td>
</tr>
</table>

## C++ Classes:

```cpp

 // 2D entities
 class Image : public Geometry2D ;
 class RGBDImage : public Geometry2D ;

 // 3D entities
 class Image : public Geometry2D ;
 class OrientedBoundingBox : public Geometry3D ;
 class AxisAlignedBoundingBox : public Geometry3D ;
 class LineSet : public Geometry3D ;
 class MeshBase : public Geometry3D ;
 class Octree : public Geometry3D ;
 class PointCloud : public Geometry3D ;
 class VoxelGrid : public Geometry3D ;

 // 3D surfaces
 class TetraMesh : public MeshBase;
 class TriangleMesh : public MeshBase;


```

### Open3D::Geometry::Image:

```cpp

 #include <Open3D/Geometry/Image.h>

 using namespace Open3D :: Geometry;
 int main () {
 Image linux_pic (".data/linux.png");

 auto flipped_linux = linux_pic . FlipHorizontal ();

 auto sobel_filter = Image :: FilterType :: Sobel3Dx;
 auto filtered_linux = linux_pic .Filter( sobel_filter );

 if ( filtered_linux .IsEmpty ()) {
 std :: cerr << "Couldn't Filter Image!\n";
 }
 }


```