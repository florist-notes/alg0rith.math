# Mathematical Optimizations

## Continuous Optimization:

Continuous optimization means finding the minimum or maximum value of a function of one or many real variables, subject to constraints. The constraints usually take the form of equations or inequalities. 

Optimization (scipy.optimize) [[scipy/optimiza](https://docs.scipy.org/doc/scipy/tutorial/optimize.html), [c++ eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)] 

### Optimization Using Gradient Descent

### Constrained Optimization and Lagrange Multipliers

A constrained optimization problem is a problem of the form
maximize (or minimize) the function F(x, y) subject to the
condition g(x, y) = 0.


### Convex Optimization

Convex optimization is the problem of minimizing a convex function over convex constraints. It is a class of problems for which there are fast and robust optimization algorithms, both in theory and in practice. Following the pattern for linear optimization, ever-wider classes of problems are being identified to be in this class in a wide variety of domains, such as statistics, finance, signal processing, geometry and many more. 

Notes and code on linear and nonlinear optimization of pose graphs for vSLAMs are @/[slam-backend-i](https://github.com/florist-notes/aicore_n/blob/main/notes/code/slam/optimization.MD) and @github/[slam-backend-ii](https://github.com/florist-notes/aicore_n/blob/main/notes/code/slam/optimization2.MD). All my notes on visual SLAM can be found @github/[vSLAM](https://github.com/florist-notes/aicore_n/blob/main/notes/code/slam/README.MD). A good open document on Convex Optimization is [here](./notes/convexopt.pdf) with this [introduction](https://youtu.be/oLowhs83aHk?si=wb0bQ1pB7bpv4MaL).