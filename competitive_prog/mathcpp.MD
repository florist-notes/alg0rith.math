# Mathematics Libraries in c++ (Eigen, Ceres-solver, GTSAM, g2o)

Eigen, Ceres Solver, GTSAM (Graphical Models Toolkit for Robotics and Sensor Fusion), and G2O are popular C++ libraries used in computer vision, robotics, and sensor fusion applications. Each of these libraries serves a specific purpose and provides tools for various tasks such as linear algebra, optimization, and factor graph-based estimation. 

Eigen is a high-performance C++ template library for linear algebra. It provides a wide range of functionalities for performing operations on matrices and vectors, making it an essential tool for numerical computing tasks in various fields, including computer vision, robotics, scientific computing, and machine learning. 

Key Features of Eigen:

+ <b>Intuitive Syntax:</b> Eigen's API is designed to closely resemble mathematical notation. This makes it easy for users to write code that mirrors the mathematical operations they want to perform.

+ <b>Efficient Computation:</b> Eigen is known for its efficiency. It leverages expression templates and optimized code paths for different hardware architectures to ensure that linear algebra operations are as fast as possible.

+ <b>Matrix and Vector Types:</b> Eigen provides a range of matrix and vector types, including dynamic-size matrices (MatrixXd), fixed-size matrices (Matrix3d), and various specialized types for specific tasks.

+ <b>Numerous Operations:</b> Eigen supports a wide range of operations, such as matrix multiplication, inversion, determinant calculation, eigenvalue decomposition, singular value decomposition (SVD), and more.

+ <b>Solvers:</b> Eigen includes solvers for common problems, such as linear least squares, linear systems of equations, and eigenvalue problems.

+ <b>Vectorization:</b> Eigen takes advantage of hardware vectorization to accelerate operations, making it suitable for high-performance computing.


<table width=100%>
<tr>
<th>Matrix and Vector Initialization</th>
<th>Matrix Multiplication</th>
</tr>

<tr>
<td>

```cpp

#include <iostream>
#include <Eigen/Dense>

int main() {
    // Define a 3x3 matrix
    Eigen::Matrix3d matrix;
    
    // Initialize the matrix
    matrix << 1, 2, 3,
              4, 5, 6,
              7, 8, 9;

    // Define a vector
    Eigen::Vector3d vector(1, 2, 3);

    // Access elements
    std::cout << "Matrix:\n" << matrix << "\n";
    std::cout << "Vector:\n" << vector << "\n";

    return 0;
}


```
</td>
<td>

```cpp

#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::Matrix3d A;
    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;

    Eigen::Vector3d b(2, 3, 4);

    Eigen::Vector3d result = A * b;

    std::cout << "Result:\n" << result << "\n";

    return 0;
}


```
</td>
</tr>

<tr>
<th>Eigenvalue Decomposition</th>
<th>Solving Linear Systems</th>
</tr>

<tr>
<td>

```cpp

#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::Matrix3d A;
    A << 1, 2, 3,
         4, 5, 6,
         7, 8, 9;

    Eigen::EigenSolver<Eigen::Matrix3d> eigenSolver(A);

    std::cout << "Eigenvalues:\n" << eigenSolver.eigenvalues() << "\n";
    std::cout << "Eigenvectors:\n" << eigenSolver.eigenvectors() << "\n";

    return 0;
}


```
</td>
<td>

```cpp

#include <iostream>
#include <Eigen/Dense>

int main() {
    Eigen::MatrixXd A(3, 3);
    A << 2, -1, 0,
         -1, 2, -1,
         0, -1, 2;

    Eigen::VectorXd b(3);
    b << 1, 2, 3;

    Eigen::VectorXd x = A.colPivHouseholderQr().solve(b);

    std::cout << "Solution x:\n" << x << "\n";

    return 0;
}


```

</td>
</tr>
</table>

## Ceres Solver :

Ceres Solver is an open-source C++ library developed by Google that provides robust, scalable, and efficient techniques for solving nonlinear optimization problems. It is particularly well-suited for solving problems involving parameter estimation, such as bundle adjustment in computer vision and sensor fusion in robotics.

Ceres Solver formulates optimization problems as the minimization of a cost function that depends on one or more parameters. The cost function is defined as the sum of squared residuals, which are the differences between observed and predicted values. The goal is to find the values of the parameters that minimize this cost function.

Here are some key concepts in Ceres Solver:

+ <b>Cost Function:</b> This is the function you want to minimize. It is defined as the sum of squared residuals.

+ <b>Residuals:</b> These are the differences between observed and predicted values. Residuals are computed using user-defined functions.

+ <b>Parameters:</b> These are the variables that you want to optimize. You need to define their initial values and bounds.

+ <b>Solver Options:</b> Ceres Solver provides various options to configure the optimization process, such as the optimization algorithm, convergence criteria, and verbosity level.

We'll create a simple C++ program that uses Ceres Solver to optimize a quadratic function:

```cpp

#include <iostream>
#include <ceres/ceres.h>

// Define the cost function class
struct QuadraticCostFunction {
  template <typename T>
  bool operator()(const T* const x, T* residual) const {
    // Define the quadratic function: f(x) = (x - 3)^2
    residual[0] = x[0] - T(3.0);
    return true;
  }
};

int main() {
  // Initialize the Ceres Solver problem
  ceres::Problem problem;

  // Add parameter to the problem
  double initial_x = 0.0; // Initial guess for x
  problem.AddResidualBlock(
      new ceres::AutoDiffCostFunction<QuadraticCostFunction, 1, 1>(
          new QuadraticCostFunction),
      nullptr,
      &initial_x);

  // Configure the solver options
  ceres::Solver::Options options;
  options.linear_solver_type = ceres::DENSE_QR;
  options.minimizer_progress_to_stdout = true;

  // Solve the problem
  ceres::Solver::Summary summary;
  ceres::Solve(options, &problem, &summary);

  // Print the results
  std::cout << "Optimization result:" << std::endl;
  std::cout << "Final x: " << initial_x << std::endl;
  std::cout << summary.BriefReport() << std::endl;

  return 0;
}


```

In this code:

+ We define a cost function class `QuadraticCostFunction` that represents the function to be minimized, which is `(x - 3)^2`.

+ We create a Ceres Solver problem, add a parameter (`initial_x`), and add a residual block that uses the `QuadraticCostFunction` to compute residuals.

+ We configure the solver options, specifying the linear solver type and whether to print progress to the console.

+ We solve the optimization problem using `ceres::Solve`.

+ Finally, we print the optimization results, including the final value of `x`.

## GTSAM (Graph-Toolbox for Samplers and Mappers) :

GTSAM (Graph-Toolbox for Samplers and Mappers) is an open-source C++ library developed by the Robotics Institute at Carnegie Mellon University. GTSAM is designed for solving inference and estimation problems in robotics and computer vision. It provides efficient implementations of various factor graph optimization techniques, including Gaussian Belief Propagation (BP), Variable Elimination (VE), and Sequential Monte Carlo (SMC).

GTSAM is centered around factor graphs. Factor graphs are a probabilistic graphical model used to represent complex relationships in estimation problems. The key components of GTSAM include:

+ <b>Factors:</b> Factors represent constraints or relationships between variables in your estimation problem. GTSAM provides a library of built-in factor types (e.g., Gaussian, BetweenFactor) and allows users to create custom factors.

+ <b>Variables:</b> Variables are the unknowns in your estimation problem. These can be continuous, discrete, or mixed variables.

+ <b>Values:</b> Values are the current estimates of the variables. GTSAM maintains a key-value map for efficient variable storage and retrieval.

+ <b>Factor Graph:</b> The factor graph is the central data structure in GTSAM that encodes the relationships between variables using factors.

+ <b>Optimization:</b> GTSAM provides optimization algorithms like the Levenberg-Marquardt optimizer for finding the best values of variables that satisfy the constraints imposed by the factors.

Here's a simple C++ example that demonstrates the use of GTSAM to solve a simple pose-graph SLAM problem. In this example, we'll create a factor graph representing the relationships between robot poses and landmarks, and then optimize for the most likely positions of the robot and landmarks.

```cpp

#include <gtsam/geometry/Pose2.h>
#include <gtsam/inference/Symbol.h>
#include <gtsam/slam/PriorFactor.h>
#include <gtsam/slam/BetweenFactor.h>
#include <gtsam/nonlinear/NonlinearFactorGraph.h>
#include <gtsam/nonlinear/GaussNewtonOptimizer.h>
#include <iostream>

using namespace std;
using namespace gtsam;

int main() {
    // Create a factor graph
    NonlinearFactorGraph graph;

    // Define initial estimates (initial pose of robot and landmark)
    Values initial;
    initial.insert(Symbol('x', 1), Pose2(0.0, 0.0, 0.0));
    initial.insert(Symbol('l', 2), Point2(2.0, 0.0));

    // Add a prior factor to the robot's pose
    graph.add(PriorFactor<Pose2>(Symbol('x', 1), Pose2(0.0, 0.0, 0.0), noiseModel::Unit::Create(3)));

    // Add a relative pose measurement between the robot's poses
    graph.add(BetweenFactor<Pose2>(Symbol('x', 1), Symbol('x', 2), Pose2(2.0, 0.0, 0.0), noiseModel::Unit::Create(3)));

    // Add a measurement between the robot's pose and the landmark
    graph.add(BetweenFactor<Pose2, Point2>(Symbol('x', 1), Symbol('l', 2), Pose2(1.0, 0.0, 0.0), noiseModel::Unit::Create(3), noiseModel::Unit::Create(2)));

    // Create an optimizer
    GaussNewtonOptimizer optimizer(graph, initial);
    
    // Optimize the factor graph
    Values result = optimizer.optimize();
    
    // Print the optimized values
    cout << "Optimized values:\n" << result << endl;

    return 0;
}


```


In this code:

+ We create a factor graph (`graph`) and initialize initial estimates (`initial`) for the robot's pose and the landmark.

+ We add factors to the graph representing a prior on the robot's pose, a relative pose measurement between robot poses, and a measurement between the robot's pose and the landmark.

+ We create a Gauss-Newton optimizer and optimize the factor graph.

+ Finally, we print the optimized values.

## g2o :

g2o is an open-source C++ library for optimizing graph-based nonlinear optimization problems. It is particularly well-suited for solving problems in computer vision, robotics, and simultaneous localization and mapping (SLAM). 

g2o is designed for solving nonlinear optimization problems that can be represented as a factor graph. The key components of g2o include:

+ <b>Vertices:</b> Vertices represent the variables you want to optimize. These variables can be of any type (e.g., 2D/3D poses, landmarks, calibration parameters).

+ <b>Edges:</b> Edges represent the constraints or measurements between variables. Each edge encodes information about how variables are related. Edges can have associated measurement models and uncertainties.

+ <b>Factor Graph:</b> The factor graph is the central data structure in g2o. It represents the optimization problem as a graph, where vertices and edges are nodes connected by edges.

+ <b>Optimization Algorithms:</b> g2o provides a variety of optimization algorithms, including Gauss-Newton, Levenberg-Marquardt, and others, to solve the optimization problem defined by the factor graph.


Here's a simple C++ example that demonstrates the use of g2o to solve a 2D pose graph optimization problem. In this example, we'll create a factor graph representing the relationships between 2D poses and optimize for the most likely positions of these poses.

```cpp

#include <iostream>
#include <g2o/core/sparse_optimizer.h>
#include <g2o/core/block_solver.h>
#include <g2o/core/optimization_algorithm_levenberg.h>
#include <g2o/types/slam2d/vertex_se2.h>
#include <g2o/types/slam2d/edge_se2.h>

using namespace std;
using namespace g2o;

int main() {
    // Create a sparse optimizer
    SparseOptimizer optimizer;

    // Set the linear solver and optimization algorithm
    BlockSolver_2_1::LinearSolverType* linearSolver = new LinearSolverDense<BlockSolver_2_1::PoseMatrixType>();
    BlockSolver_2_1* solver_ptr = new BlockSolver_2_1(linearSolver);
    OptimizationAlgorithmLevenberg* solver = new OptimizationAlgorithmLevenberg(solver_ptr);

    optimizer.setAlgorithm(solver);

    // Add vertices (2D poses)
    VertexSE2* v1 = new VertexSE2();
    v1->setId(0);
    v1->setEstimate(SE2(0.0, 0.0, 0.0));
    optimizer.addVertex(v1);

    VertexSE2* v2 = new VertexSE2();
    v2->setId(1);
    v2->setEstimate(SE2(1.0, 0.0, 0.0));
    optimizer.addVertex(v2);

    // Add edges (constraints)
    EdgeSE2* e = new EdgeSE2();
    e->vertices()[0] = optimizer.vertex(0);
    e->vertices()[1] = optimizer.vertex(1);
    e->setMeasurement(SE2(1.0, 0.0, 0.0)); // Relative pose measurement
    e->setInformation(Matrix3d::Identity()); // Measurement uncertainty
    optimizer.addEdge(e);

    // Optimize the graph
    optimizer.initializeOptimization();
    optimizer.optimize(10);

    // Print optimized poses
    cout << "Optimized poses:" << endl;
    cout << "Vertex 0: " << dynamic_cast<VertexSE2*>(optimizer.vertex(0))->estimate().toVector().transpose() << endl;
    cout << "Vertex 1: " << dynamic_cast<VertexSE2*>(optimizer.vertex(1))->estimate().toVector().transpose() << endl;

    return 0;
}

```

In this code:

+ We create a sparse optimizer (`SparseOptimizer`) and set up the linear solver and optimization algorithm.

+ We add two 2D pose vertices (`VertexSE2`) representing the robot's positions.

+ We add an edge (`EdgeSE2`) representing the relative pose measurement between the two poses.

+ We specify the initial estimates, measurements, and measurement uncertainties.

+ We optimize the graph using the Levenberg-Marquardt algorithm.

+ Finally, we print the optimized poses.
