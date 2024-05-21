# Geometric Techniques

+ `Complex Numbers`: Complex numbers can be used in geometry to represent points and perform geometric transformations. The C++ STL provides a std::complex class template to work with complex numbers.

```cpp
#include <iostream>
#include <complex>

int main() {
    std::complex<double> a(3.0, 4.0);  // Complex number 3 + 4i
    std::complex<double> b(1.0, 2.0);  // Complex number 1 + 2i

    std::complex<double> sum = a + b;
    std::complex<double> product = a * b;

    std::cout << "Sum: " << sum << "\n";          // Output: (4,6)
    std::cout << "Product: " << product << "\n";  // Output: (-5,10)
    std::cout << "Magnitude of a: " << std::abs(a) << "\n";  // Output: 5
    std::cout << "Angle of a: " << std::arg(a) << "\n";      // Output: 0.927295
    return 0;
}
```

+ `Points and Lines` : Points and lines are fundamental concepts in computational geometry. Points can be represented using pairs or `std::complex`, and lines can be represented using two points or a point and a direction vector.

```cpp
#include <iostream>
#include <complex>

using Point = std::complex<double>;

struct Line {
    Point p1, p2;
    
    Line(Point a, Point b) : p1(a), p2(b) {}
};

// Function to check if point c is on the line segment [a, b]
bool onSegment(Point a, Point b, Point c) {
    double crossProduct = std::imag((b - a) * std::conj(c - a));
    if (std::abs(crossProduct) > 1e-10) return false;
    double dotProduct = std::real((c - a) * std::conj(b - a));
    if (dotProduct < 0) return false;
    double squaredLengthBA = std::norm(b - a);
    if (dotProduct > squaredLengthBA) return false;
    return true;
}

int main() {
    Point a(0, 0), b(4, 4), c(2, 2);
    
    if (onSegment(a, b, c)) {
        std::cout << "Point c is on the line segment [a, b]\n";
    } else {
        std::cout << "Point c is not on the line segment [a, b]\n";
    }

    return 0;
}
```

+ `Polygon Area` : The area of a simple polygon can be calculated using the Shoelace formula, also known as Gauss's area formula.

```cpp
#include <iostream>
#include <vector>
#include <complex>

using Point = std::complex<double>;

double polygonArea(const std::vector<Point>& vertices) {
    int n = vertices.size();
    double area = 0;
    for (int i = 0; i < n; ++i) {
        area += std::real(vertices[i]) * std::imag(vertices[(i + 1) % n]);
        area -= std::imag(vertices[i]) * std::real(vertices[(i + 1) % n]);
    }
    return std::abs(area) / 2.0;
}

int main() {
    std::vector<Point> polygon = {
        {0, 0}, {4, 0}, {4, 3}, {0, 3}
    };
    
    std::cout << "Area of the polygon: " << polygonArea(polygon) << "\n";  // Output: 12
    return 0;
}
```

+ `Distance Functions` : Distance functions are useful for calculating distances between points, between a point and a line, etc.

```cpp
#include <iostream>
#include <complex>

using Point = std::complex<double>;

double distance(Point a, Point b) {
    return std::abs(a - b);
}

double distancePointLine(Point a, Point b, Point p) {
    double area = std::abs((b - a).imag() * (p - a).real() - (b - a).real() * (p - a).imag());
    double base = std::abs(b - a);
    return area / base;
}

int main() {
    Point a(0, 0), b(3, 4), p(1, 2);
    
    std::cout << "Distance between a and b: " << distance(a, b) << "\n";  // Output: 5
    std::cout << "Distance from p to line [a, b]: " << distancePointLine(a, b, p) << "\n";  // Output: 0.6

    return 0;
}
```
