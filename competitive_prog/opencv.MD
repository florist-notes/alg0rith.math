# OpenCV in GNU/Linux with C++


<img src="img/opencv.png" width=30%>

```cpp

#include <opencv2/opencv.hpp>

```
OpenCV has namespace : `cv::` | types in OpenCV : `CV_<bit_count>` `<itentifier>` `<num_of_channels>`, example:
+ RGB image is `CV_8UC3`: 8-bit unsigned char with 3 channels for RGB
+ Grayscale image is `CV_8UC1`: single 8-bit unsigned char for intensity

Better to use `DataType`, `DataType<uint>::type == CV_8UC1`

Basic Matrix Type : Every image is a `cv::Mat`, for “Matrix” : `Mat image(rows, cols, DataType, Value);`
 and `Mat_<T> image(rows, cols, Value);` . Initialize with `zeros`:

 ```cpp
cv:: Mat image = cv:: Mat :: zeros (10, 10, CV_8UC3);
using Matf = cv::Mat_ <float >;
Matf image_float = Matf :: zeros (10, 10);
 ```

 Get type identifier with `image.type();` and size with `image.rows`, `image.cols`.

 I/O:
   + Read image with `imread` | Write image with `imwrite` | Show image with `imshow` | Detects I/O method from extension

cv::Mat is sort of shared pointer: ` $ c++ -std=c++11 -o copy copy.cpp pkg -config --libs --cflags opencv `

```cpp
 #include <opencv2/opencv.hpp >
 #include <iostream >
 int main () {
 using Matf = cv::Mat_ <float >;
 Matf image = Matf :: zeros (10, 10);
 Matf image_no_copy = image; // Does not copy!
 image_no_copy .at <float >(5, 5) = 42.42f;
 std :: cout << image.at <float >(5, 5) << std :: endl;
 Matf image_copy = image.clone (); // Copies image.
 image_copy .at <float >(1, 1) = 42.42f;
 std :: cout << image.at <float >(1, 1) << std :: endl;
 }


```


<table style="width:100%" >
<tr>
<th>imread</th>
<th>imwrite</th>
</tr>
<tr>
<td>

+ Read image from file
+ Mat imread(const string& file, int mode=1)
+ Different modes:
  - unchanged: `cv::IMREAD_UNCHANGED < 0`
  - 1 channel: `cv::IMREAD_GREYSCALE == 0`
  - 3 channels: `cv::IMREAD_COLOR > 0`

```cpp
1 #include <opencv2/ imgcodecs .hpp >
2 #include <opencv2/opencv.hpp >
3 using namespace cv;
4 int main () {
5       Mat i1 = imread("logo_opencv.png",
6       cv:: IMREAD_GRAYSCALE );
7       Mat_ <uint8_t > i2 = imread("logo_opencv.png",
8       cv:: IMREAD_GRAYSCALE );
9       std :: cout << (i1.type () == i2.type ()) << std :: endl;
10      return 0;
11 }
```
</td>
<td>

+ Write the image to file
+ Format is guessed from extension
+ bool imwrite(const string& file,
const Mat& img);

```cpp
1 #include <opencv2/core.hpp >
2 #include <opencv2/highgui.hpp >
3 int main () {
4       cv:: Mat image = cv:: imread("logo_opencv.png",
5       cv:: IMREAD_GRAYSCALE );
6       cv:: imwrite("copy.jpg", image);
7       return 0;
8 }

```
Write float images to *.exr files. These files will store and read values as is without losing precision. Float images I/O example:

```cpp
 #include <iostream >
 #include <string >

 #include <opencv2/opencv.hpp >
 int main () {
       using Matf = cv::Mat_ <float >;
       Matf image = Matf :: zeros (10, 10);
       image.at <float >(5, 5) = 42.42f;
       std :: string f = "test.exr";
      cv:: imwrite(f, image);
      Matf copy = cv:: imread(f, cv:: IMREAD_UNCHANGED );
      std :: cout << copy.at <float >(5, 5) << std :: endl;
      return 0;
 }

```


</td>
</tr>
<tr>
<th>imshow</th>
<th>OpenCV vector type</th>
</tr>
<tr>
<td>

+ Display the image on screen
+ Needs a window to display the image
+ void imshow(const string& window_name, const Mat& mat)


```cpp
 // clang -format off
 #include <opencv2/opencv.hpp >
 int main () {
        cv:: Mat image = cv:: imread("logo_opencv.png",
        cv:: IMREAD_COLOR );
        std :: string window_name = "Window name";
        // Create a window.
        cv:: namedWindow (window_name , cv:: WINDOW_AUTOSIZE );
        cv:: imshow(window_name , image); // Show image.
        cv:: waitKey (); // Don't close window instantly.
        return 0;
 }


```
</td>
<td>

+ OpenCV vector type: `cv::Vec<Type, SIZE>`
+ Many typedefs available: `Vec3f`, `Vec3b`, etc
+ Used for pixels in multidimensional images: `mat.at<Vec3b>(row, col);`

```cpp
 #include <opencv2/opencv.hpp >
 #include <iostream >
 using namespace cv;
   int main () {
        Mat mat = Mat :: zeros (10, 10, CV_8UC3);
        std :: cout << mat.at <Vec3b >(5, 5) << std :: endl;
        Mat_ <Vec3f > matf3 = Mat_ <Vec3f >:: zeros (10, 10);
        std :: cout << matf3.at <Vec3f >(5, 5) << std :: endl;
 }
```
</td>
</tr>
</table>
