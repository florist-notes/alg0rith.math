# Combinatorics

#### Binomial Coefficients

The Binomial Coefficient gives the number of ways we can choose a subset of k elements from a set of n elements

$$ \binom{n}{k} = \frac{n!}{k!(n-k)!} $$

For binomial coefficients,

$$ \binom{n}{k} = \frac{n}{(n-k)}, $$

The sum of binomial coefficients,

$$ \binom{n}{0} + \binom{n}{1} + \binom{n}{2} + ... + \binom{n}{n} = 2^n $$

#### Multinomial Coefficients


$$ \binom{n}{k_1, k_2, k_3,...,k_m} = \frac{n!}{k_1!k_2!..k_m!} $$

##### Boxes and Balls: "Boxes and balls" is a useful model, where we count the ways to plcae k balls in n boxes. Let us consider three scenarios:

+ Scenario 1 : Each box can contain atmost one ball. In this scenario, the number of combinations is directly the binomial coefficient 

$$ \binom{n}{k} $$

+ Scenario 2 : A box can contain multiple balls. The number of combinations is 

$$ \binom{k+n-1}{k} $$

+ Scenario 3 : Each box may contain at most one ball, and in addition, no two adjacent boxes may both contain a ball. The number of combinations is 

$$ \binom{n-k+1}{n-2k+1} $$

#### Catalan Numbers:

[ [The Most Important Sequence: The Catalan Numbers](https://youtu.be/TAuJV5eNKLM?si=cV6YX98gjLbEak0r), [Catalan Numbers Application](https://youtu.be/1ZAotQGnbi4?si=a_1FCGFAGt1sT6s-) ]

The Catalan number 

$$ C_n $$

gives the number of valid parenthesis expressions that consist of n left parentheses and n right parentheses. Another way to characterize valid parenthesis expressions is that if we choose any prefix of such an expression, it has to contain atleast as many left parentheses as right parentheses, and the complete expression has to contain an equal number of left and right parentheses.

Catalan numbers can be calculated using the formula,

$$ C_n = \sum_{i=0}^{n-1} C_i C_{n-i-1} $$

+ C_i : the number of ways to construct an empty parenthesis expression using zero pairs of parenthesses. 
+ C_{n-i-1} : the number of ways to construct a parenthesis expression using the parentheses of the second part.

The base case is C_0 = 1, because we can construct an empty parenthesis expression using zero pairs of parentheses.

Catalan numbers can also be calculated using the formula

$$ C_n = \frac{1}{n*1} \binom{2n}{n}$$