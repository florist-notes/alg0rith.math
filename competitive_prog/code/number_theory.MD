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



-  Properties of Primes:

### Sieve of Eratosthenes

```cpp

for (int x=2; x <=n; x++) {
    if (sieve[x]) continue;
    for (int u= 2*x; u <=n; u+=x) {
        sieve[u] = 1;
    }
}

```

### Euclid's Algorithm



```cpp
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}
```

- Extended Euclid's Algorithm:

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

### Solving Equations

- Chinese Remainder Theorem


class : [Introduction to number theory (Berkeley Math 115)](https://www.youtube.com/playlist?list=PL8yHsr3EFj53L8sMbzIhhXSAOpuZ1Fov8)

resources: [Number Theory (Interesting Facts and Algorithms)](https://www.geeksforgeeks.org/number-theory-interesting-facts-and-algorithms/), [How to learn number theory ?](https://codeforces.com/blog/entry/108622), [Top math and number theory questions](https://www.codingninjas.com/studio/problem-lists/top-maths-and-number-theory-questions), [Number Theory - 1](https://www.hackerearth.com/practice/notes/number-theory-1/), [Basic Number Theory Every Programmer Should Know...](https://www.codechef.com/wiki/tutorial-number-theory), [Number Theory for DSA & Competitive Programming](https://www.geeksforgeeks.org/number-theory-competitive-programming/), [Algorithms for Competitive Programming](https://cp-algorithms.com/index.html), [Number theory Tutorials | Competitive Programming](https://www.youtube.com/playlist?list=PLauivoElc3giVROwL-6g9hO-LlSen_NaV), [Michael Penn - Number Theory](https://www.youtube.com/playlist?list=PL22w63XsKjqwAgBzVFVqZNMcVKpOOAA7c) - [NT v2](https://www.youtube.com/playlist?list=PL22w63XsKjqwn2V9CiP7cuSGv9plj71vv), [Number Theory : CodeNCode](https://www.youtube.com/playlist?list=PL5DyztRVgtRWblnyEHtajWijQffrfwLz6), [Complete Number Theory Practice - Noob to Expert](https://www.youtube.com/live/Q5knm-DArA0?si=C2GGpLXZ5VcEf69u), [NT L3](https://www.youtube.com/playlist?list=PL-Jc9J83PIiF0L_qYN4HG_MJpi1I8gvpy).