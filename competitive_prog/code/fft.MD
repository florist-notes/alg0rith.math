# Fast Fourier Transform

The ideaa of the algorithm is to convert the polynomials into a special point-value form where it is easier to calculate the product. The Fast Fourier Transform (FFT) can be understood in terms of polynomial multiplication. The idea is that the coefficients of the product of two polynomials are related to the values of the convolution of their sequences of coefficients. FFT exploits this relationship to efficiently compute polynomial products by transforming the coefficients into a different domain, performing pointwise multiplication, and then transforming back.

Let's consider the polynomial multiplication of two polynomials 
A(x) and B(x):

$$ C(x)=A(x)⋅B(x) $$

In the context of FFT, we can represent the coefficients of these polynomials as sequences. The FFT algorithm helps us efficiently compute the coefficients of C(x) by transforming the sequences, performing pointwise multiplication, and then transforming back.

Here's an example of FFT-based polynomial multiplication in Python:

```python

import numpy as np

def fft_multiply(A, B):
    # Ensure the lengths are powers of 2 for simplicity
    n = 2**int(np.ceil(np.log2(max(len(A), len(B)))))
    
    # Pad the sequences with zeros
    A_pad = np.pad(A, (0, n - len(A)))
    B_pad = np.pad(B, (0, n - len(B)))

    # FFT of A and B
    fft_A = np.fft.fft(A_pad)
    fft_B = np.fft.fft(B_pad)

    # Pointwise multiplication
    fft_C = fft_A * fft_B

    # Inverse FFT to get the coefficients of C
    C = np.fft.ifft(fft_C)

    # Round the real parts to account for numerical errors
    return np.rint(C.real).astype(int)

# Example usage:
A = [1, 2, 3]  # Coefficients of A(x) = 1 + 2x + 3x^2
B = [4, 5, 6]  # Coefficients of B(x) = 4 + 5x + 6x^2

C = fft_multiply(A, B)
print("Result of polynomial multiplication:", C)


```

In this example:

+ The `fft_multiply` function takes two lists of coefficients `A` and `B` representing polynomials and returns the coefficients of their product `C`.
+ The sequences are padded with zeros to ensure their lengths are powers of 2, which simplifies the FFT computations.
+ The FFT and inverse FFT are performed using NumPy's `np.fft.fft` and `np.fft.ifft` functions, respectively.
+ The resulting coefficients are rounded to integers to account for numerical errors.
  
This example demonstrates the use of FFT for polynomial multiplication, and it can be extended to handle more complex scenarios.

## FFT Algorithm

Given a vector 

$$ a = [c_0, c_1, c_2,... c_{n-1}] $$ 

that represents the polynomial

$$ f(x) = c_0 + c_1x + ... + c_{n-1}x^{n-1} $$

the Fourier transform of a is a vector 

$$ t = [f(\omega_n^0), f(\omega_n^1),,,,f(\omega_n^{n-1})] $$

where

$$ \omega_n = e^{\frac{2\pi i}{n}} = cos(\frac{2\pi}{n}) + sin(\frac{2\pi}{n})i $$

The vector t corresponds to a point value representation of the polynomial f(x), evaluated at points 

$$ \omega_n^0, \omega_n^1, ..., \omega_n^{n-1}  $$

The value ω_n is a complex number called a principal root of unity that satisfies  ω_n^n = 1.

```cpp

vector<cd> fft(vector<cd> a, int d=1) {
    int n = a.size();
    vector<cd> r(n);
    for(int k = 0; k<n; k++){
        int b = 0;
        for(int z=1; z<n; z*=2){
            b*=2;
            if (k&z) b++;
        }
        r[b] = a[k];
    }
    for(int m=2; m<=n; m*=2){
        cd wm = exp(cd{0, d*2*pi/m});
        for(int k=0; k<n; k+=m){
            cd w = 1;
            for(int j=0; j< m/2; j++) {
                cd u = r[k+j];
                cd t = r*w[k+j+m/2];
                r[k+j] = u+t;
                r[k+j+m/2] = u - t;
                w = w*wm;
            }

        }

    }
    if (d == -1) {
        for (int i=0; i<n; i++) r[i] /= n;
    }
    return r;
}

```

For two polynomials, f(x) = 2x + 3 and g(x) = 5x + 1,

```cpp

int n = 4;
vector<cd> f = {3,2,0,0};
vector<cd> g = {1,5,0,0};

auto tf = fft(f);
auto tg = fft(g);

vector<cd> tp(n);
for (int i=0, i<n, i++) tp[i] = tf[i]*tg[i];
auto p = fft(tp, -1); // [3, 17, 10, 0]

```