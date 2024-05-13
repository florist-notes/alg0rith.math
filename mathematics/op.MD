# Mathematical Optimizations

Mathematical optimization plays a central role in machine learning, where the goal is to find the optimal parameters of a model that minimize a cost function, thereby improving its performance on unseen data. 

## Continuous Optimization:

Continuous optimization means finding the minimum or maximum value of a function of one or many real variables, subject to constraints. The constraints usually take the form of equations or inequalities. 

Continuous optimization problems can be categorized into two main types:

- <b>Unconstrained Optimization</b>: In these problems, the objective function is optimized without any constraints on the decision variables. The goal is to find the global or local minimum or maximum of the function.

- <b>Constrained Optimization</b>: These problems involve optimization subject to constraints. Constraints can be equality constraints (e.g., linear equations) or inequality constraints (e.g., bounds on variables). The goal is to find the best solution that satisfies all constraints.

SciPy provides several functions for both unconstrained and constrained optimization. The primary optimization functions in SciPy are part of the `scipy.optimize` module. Some commonly used functions include:

- `minimize`: General-purpose optimization function that supports various optimization methods.
- `minimize_scalar`: Optimization for scalar (single-variable) functions.
- `linprog`: Linear programming optimization.
- `root`: Solving nonlinear equations and systems of equations.
- `fsolve`: Specifically for finding solutions to systems of nonlinear equations.
- `leastsq`: Least-squares minimization for curve fitting.

SciPy offers various optimization algorithms to solve different types of problems. Some commonly used algorithms include:

- Local Optimization:
    + Nelder-Mead (simplex) algorithm (`'nelder-mead'`)
    + Powell's conjugate direction method (`'powell'`)
    + Broyden-Fletcher-Goldfarb-Shanno (BFGS) algorithm (`'BFGS'`)
    + Limited-memory BFGS (L-BFGS) algorithm (`'L-BFGS-B'`)

- Global Optimization:
    + Basin-hopping algorithm (`'basin-hopping'`)
- Linear Programming:
    + Simplex method (`'highs'`)
- Nonlinear Equations:
    + Newton-Raphson (`'newton-cg', 'newton-2'`)
    + Trust Region Reflective (`'trf'`)
    + Levenberg-Marquardt (`'lm'`)

The choice of algorithm depends on the problem's characteristics, such as convexity, dimensionality, and the presence of constraints.

<table width=100%>
<tr>
<th>Linear Programming</th>
<th>Nonlinear Optimization</th>
</tr>
<tr>
<td>

```python

from scipy.optimize import linprog

# Objective coefficients
c = [-1, -2]

# Coefficients for inequality constraints
A = [[1, 1], [1, -1]]
b = [4, 1]

# Variable bounds
x_bounds = [(0, None), (0, None)]

# Solve the linear programming problem
result = linprog(c, A_ub=A, b_ub=b, bounds=x_bounds, method='highs')

print("Optimal Solution:", result.x)
print("Optimal Value:", -result.fun)  # Minimization problem, so negate the result


```
</td>
<td>

```python

from scipy.optimize import minimize

# Define the objective function
def objective(x):
    return x[0]**2 + x[1]**2

# Initial guess
x0 = [1.0, 1.0]

# Minimize the objective function with bounds
result = minimize(objective, x0, method='SLSQP', bounds=[(-1, 1), (-1, 1)])

print("Optimal Solution:", result.x)
print("Optimal Value:", result.fun)


```
</td>
</tr>
</table>

Optimization (scipy.optimize) [[scipy/optimize](https://docs.scipy.org/doc/scipy/tutorial/optimize.html), [c++ eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)] 


### Constrained Optimization and Lagrange Multipliers

A constrained optimization problem is a problem of the form
maximize (or minimize) the function F(x, y) subject to the
condition g(x, y) = 0.


## Convex Optimization

Convex optimization is a specialized field within optimization theory, focusing on problems where both the objective function and the feasible region (constraints) are convex.

Convex optimization is the problem of minimizing a convex function over convex constraints. It is a class of problems for which there are fast and robust optimization algorithms, both in theory and in practice. Following the pattern for linear optimization, ever-wider classes of problems are being identified to be in this class in a wide variety of domains, such as statistics, finance, signal processing, geometry and many more. 

[cvxpy](https://github.com/cvxpy/cvxpy) is a Python library designed for convex optimization. It provides a high-level interface for defining and solving convex optimization problems.

#### Quadratic Programming: 

Quadratic programming (QP) is another common convex optimization problem. Here's an example of formulating and solving a QP problem:

```python

import cvxpy as cp

# Define decision variables
x = cp.Variable(2)

# Define objective function (minimize)
objective = cp.Minimize(cp.quad_form(x, cp.diag([1, 2])) - cp.sum(x))

# Define constraints
constraints = [x[0] >= 0, x[1] >= 0, x[0] + x[1] == 1]

# Create the optimization problem
qp_problem = cp.Problem(objective, constraints)

# Solve the problem
qp_problem.solve()

# Print the results
print("Optimal Value:", qp_problem.value)
print("Optimal Solution:", x.value)


```



Notes and code on linear and nonlinear optimization of pose graphs for vSLAMs are @/[slam-backend-i](https://github.com/florist-notes/aicore_n/blob/main/notes/code/slam/optimization.MD) and @github/[slam-backend-ii](https://github.com/florist-notes/aicore_n/blob/main/notes/code/slam/optimization2.MD). All my notes on visual SLAM can be found @github/[vSLAM](https://github.com/florist-notes/aicore_n/blob/main/notes/code/slam/README.MD). 

Some good resources on Convex Optimization: [convex_optimization.pdf](./notes/convexopt.pdf), [introduction video](https://youtu.be/oLowhs83aHk?si=wb0bQ1pB7bpv4MaL) and class : { [Stanford University: Convex Optimization](https://www.edx.org/learn/engineering/stanford-university-convex-optimization) }, [Optimization in Deep Learning](https://youtu.be/M2xkmc2oHUc?si=aNzpW22Xf5Yxz5aM), [Optimization for Deep Learning (Momentum, RMSprop, AdaGrad, Adam)](https://youtu.be/NE88eqLngkg?si=sYYHEkvpIJjhe96u).