# Probability

1. Working with Events:
   
Events in probability are outcomes or sets of outcomes of a random experiment. Probability is assigned to events, and operations such as union, intersection, and complement can be performed on them.

```cpp
#include <iostream>
#include <cmath>

int main() {
    // Probability of events A and B
    double P_A = 0.4;
    double P_B = 0.3;

    // Probability of the union of events A and B: P(A U B) = P(A) + P(B) - P(A ∩ B)
    double P_A_union_B = P_A + P_B - (P_A * P_B);

    std::cout << "Probability of A union B: " << P_A_union_B << std::endl;

    return 0;
}


```

2. Random Variables:
   
A random variable is a variable whose possible values are outcomes of a random experiment. It can be discrete or continuous, and its probability distribution describes the likelihood of different values.

```cpp

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed for random number generation
    std::srand(std::time(0));

    // Generate a random integer between 1 and 6 (simulate a six-sided die)
    int outcome = std::rand() % 6 + 1;

    std::cout << "Random outcome: " << outcome << std::endl;

    return 0;
}


```

3. Markov Chains:

A Markov chain is a stochastic model that describes a sequence of events in which the probability of each event depends only on the state attained in the previous event. It has states, transition probabilities, and an initial state.

```cpp
#include <iostream>
#include <vector>

int main() {
    // Define a simple 2-state Markov chain transition matrix
    std::vector<std::vector<double>> transition_matrix = {{0.7, 0.3}, {0.4, 0.6}};

    // Initial state
    int current_state = 0;

    // Simulate several transitions
    for (int i = 0; i < 5; ++i) {
        std::cout << "Step " << i + 1 << ": State " << current_state + 1 << std::endl;

        // Transition to a new state based on probabilities
        double random_number = (rand() % 100) / 100.0; // Generate a random number between 0 and 1
        if (random_number < transition_matrix[current_state][0]) {
            current_state = 0;
        } else {
            current_state = 1;
        }
    }

    return 0;
}


```

4. Randomized Algorithms:
   
Randomized algorithms use random numbers to make decisions or introduce randomness to achieve desired properties. They are often used in situations where deterministic algorithms may be impractical or too slow.

```cpp

#include <iostream>
#include <cstdlib>

// Randomized algorithm to determine if a number is prime (Miller-Rabin primality test)
bool isPrime(int n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    // Find d such that n-1 = 2^r * d
    int d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }

    // Repeat k times
    for (int i = 0; i < k; ++i) {
        // Pick a random number 'a' in the range [2, n-2]
        int a = 2 + rand() % (n - 4);

        // Compute a^d % n
        int x = std::pow(a, d) % n;

        // If x is 1 or n-1, continue to the next iteration
        if (x == 1 || x == n - 1) {
            continue;
        }

        // Repeat r-1 times
        for (int j = 0; j < d - 1; ++j) {
            // Compute x = x^2 % n
            x = (x * x) % n;

            // If x is n-1, break the loop
            if (x == n - 1) {
                break;
            }
        }

        // If x is neither 1 nor n-1, return false
        if (x != 1 && x != n - 1) {
            return false;
        }
    }

    // Probably prime
    return true;
}

int main() {
    int number = 23;
    int iterations = 5;

    if (isPrime(number, iterations)) {
        std::cout << number << " is probably prime." << std::endl;
    } else {
        std::cout << number << " is composite." << std::endl;
    }

    return 0;
}


```

In this example, the Miller-Rabin primality test is used as a randomized algorithm to determine if a number is probably prime. The accuracy of the test depends on the number of iterations (parameter k). Higher values of k increase the accuracy but also the computational cost.





