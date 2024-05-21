# Number Theory:

### Primes and Factors

-  Basic Algorithm:


```cpp
bool prime(int n){
    if (n<2) return false;
    for (int x=2; x*x <=n; x++){
        if (n%x == 0) return false;
    }
    return true;
}
```

```cpp
vector<int> factors(int n) {
    vector<int> f;
    for(int x=2; x*x <=n; x++) {
        while(n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}

```

### Sieve of Eratosthenes

The Sieve of Eratosthenes is an ancient algorithm used to find all prime numbers up to a specified integer value. It works by iteratively marking the multiples of each prime number starting from 2 as composite (i.e., not prime). Here's how the algorithm works:

+ Create a list of consecutive integers from 2 through the specified upper limit.
+ Start with the first prime number, which is 2. Mark all of its multiples greater than 2 as composite.
+ Find the next prime number (the smallest number greater than the current prime that is not marked as composite). + This next prime will be the next unmarked number in the list.
+ Repeat step 3 until the square of the current prime is greater than the specified upper limit. At this point, all non-marked numbers that remain in the list are prime.

The algorithm is efficient because it doesn't waste time checking multiples of numbers that have already been identified as composite. By the end of the process, all prime numbers up to the specified upper limit are identified, while composite numbers are marked as such. This algorithm is named after the ancient Greek mathematician Eratosthenes, who is credited with its invention.

[Sieve Algorithm: How to find Prime Numbers Optimally ?](https://youtu.be/T8PaMnb0GPo?si=oPtcq-XG8rkw_exE), [15.1 Sieve of Eratosthenes](https://youtu.be/nDPo9hsDNvU?si=E8zoCGQyWiDmElSx), [cp-algorithms.com](https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html)

```cpp

for (int x=2; x <=n; x++) {
    if (sieve[x]) continue;
    for (int u= 2*x; u <=n; u+=x) {
        sieve[u] = 1;
    }
}

```

### Euclid's Algorithm

[ [Euclid's Algorithm](https://crypto.stanford.edu/pbc/notes/numbertheory/euclid.html), [GCD - Euclidean Algorithm (Method 1)](https://youtu.be/yHwneN6zJmU?si=ahZDeuooSZbxmAej), [Euclidean Algorithm - An example ← Number Theory](https://youtu.be/fwuj4yzoX1o?si=PgRKZ8LLlKX5tv7X), [GCD and LCM using Euclid's Algorithm With Applications](https://youtu.be/utZcJ0leZ_g?si=rqjLE4NQVsUAm7Km) ]

```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
```

- Extended Euclid's Algorithm:

[[Extended Euclid Algorithm - Number Theory Advanced](https://youtu.be/0oP6XLTI2tY?si=4iCdrtH9gJLej3z1), [Euclidean algorithms (Basic and Extended)](https://www.geeksforgeeks.org/euclidean-algorithms-basic-and-extended/)], [Extended Euclidean Algorithm (Solved Example 1)](https://youtu.be/lq285DDdmtw?si=JqMFN0O8zI7LQJq3)

```cpp
tuple<int, int, int> gcd(int a, int b) {
    if (b==0) {
        return {1,0,a};
    } else {
        int x, y, g;
        tie(x,y,g) = gcd(b, a%b);
        return {y, x-(a/b)*y, g};
    }
}

```


### Modular Exponentiation

There is often need to efficiently calculate the value of x^nmod m. This can be done in O(logn) time using the following recursive formula:


$$
x^n = \left\{
\begin{array}{ll}
1 & \text{if } n = 0 \\
x^{\frac{n}{2}}x^{\frac{n}{2}} & \text{if } n \text{ is even} \\
x^{n-1}x & \text{if } n \text{ is odd}
\end{array}
\right.
$$


```cpp

int modpow (int x, int n, int m) {
    if (n==0) return 1%m;
    long long u = modpow(x, n/2, m);
    u = (u*u) % m;
    if (n%2 == 1) u = (u*x)%m;
    return u;
}

```

### Euler's Theorem

Two integers a and b are called coprime if gcd (a, b) = 1. Euler's totient function  Φ(n) gives the number of integers between 1 ... n that are coprime to n. 
Any value of Φ(n) can be calculated from the prime factorization of n using the formula:

$$ \Phi(n) = \prod_{i=1}^{k} p_{i}^{\alpha_i - 1} (p_i - 1)$$

Euler's theorem states that,

$$ x^{\Phi(m)} mod m = 1 $$

If m is prime, Φ(m) = m - 1, so the formula becomes

$$ x^{m-1} mod m = 1 $$

which is known as Fermat's little theorem. This also implies that,

$$ x^n mod m = x^{n mod(m-1)} mod m $$

which can be used to calculate values of x^n if n is very large.

Modular Multiplicative Inverse : [Modular Multiplicative Inverse ](https://youtu.be/Gd9w8m-klho?si=AgEc7cmteFqhLQYP), [Multiplicative Inverse](https://youtu.be/YwaQ4m1eHQo?si=eEp-vcEl4hPkPG5l), [Modular multiplicative inverse](https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/)

### Solving Equations

A Diophantine equation can be solved exactly when c is divisible by gcd(a ,b).

   
   $$ ax + by = gcd(a, b). $$


A solution to the Diophantine equation is not unique, because we can  form an infinite number of solutions if we know one solution. If a pair (x, y) is a solution, then also all pairs

$$ ( x + \frac{kb}{gcd(a,b)}, y - \frac{ka}{gcd(a,b)} )  $$


- Chinese Remainder Theorem : [[brilliant.org/chinese-remainder-theorem/](https://brilliant.org/wiki/chinese-remainder-theorem/)] | [cmu.pdf](https://www.math.cmu.edu/~mradclif/teaching/127S19/Notes/ChineseRemainderTheorem.pdf), [stanford.pdf](https://crypto.stanford.edu/pbc/notes/numbertheory/crt.html), [The Chinese Remainder Theorem (Solved Example 1)](https://youtu.be/e8DtzQkjOMQ?si=Hur6BhIziN4Pu-uP), [(Solved Example 2)](https://youtu.be/zd1_iY0FSEo?si=L5A4eP0Z97_OS6ht)


class : [Introduction to number theory (Berkeley Math 115)](https://www.youtube.com/playlist?list=PL8yHsr3EFj53L8sMbzIhhXSAOpuZ1Fov8)

resources: [Number Theory (Interesting Facts and Algorithms)](https://www.geeksforgeeks.org/number-theory-interesting-facts-and-algorithms/), [How to learn number theory ?](https://codeforces.com/blog/entry/108622), [Top math and number theory questions](https://www.codingninjas.com/studio/problem-lists/top-maths-and-number-theory-questions), [Number Theory - 1](https://www.hackerearth.com/practice/notes/number-theory-1/), [Basic Number Theory Every Programmer Should Know...](https://www.codechef.com/wiki/tutorial-number-theory), [Number Theory for DSA & Competitive Programming](https://www.geeksforgeeks.org/number-theory-competitive-programming/), [Algorithms for Competitive Programming](https://cp-algorithms.com/index.html), [Number theory Tutorials | Competitive Programming](https://www.youtube.com/playlist?list=PLauivoElc3giVROwL-6g9hO-LlSen_NaV), [Michael Penn - Number Theory](https://www.youtube.com/playlist?list=PL22w63XsKjqwAgBzVFVqZNMcVKpOOAA7c) - [NT v2](https://www.youtube.com/playlist?list=PL22w63XsKjqwn2V9CiP7cuSGv9plj71vv), [Number Theory : CodeNCode](https://www.youtube.com/playlist?list=PL5DyztRVgtRWblnyEHtajWijQffrfwLz6), [Complete Number Theory Practice - Noob to Expert](https://www.youtube.com/live/Q5knm-DArA0?si=C2GGpLXZ5VcEf69u), [NT L3](https://www.youtube.com/playlist?list=PL-Jc9J83PIiF0L_qYN4HG_MJpi1I8gvpy).