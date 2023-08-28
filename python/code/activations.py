import numpy as np

# Sigmoid activation function and its derivative
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

# Hyperbolic Tangent (tanh) activation function and its derivative
def tanh(x):
    return np.tanh(x)

def tanh_derivative(x):
    return 1 - x**2

# Rectified Linear Unit (ReLU) activation function and its derivative
def relu(x):
    return np.maximum(0, x)

def relu_derivative(x):
    return 1 * (x > 0)

# Leaky Rectified Linear Unit (Leaky ReLU) activation function and its derivative
def leaky_relu(x, alpha=0.01):
    return np.where(x > 0, x, alpha * x)

def leaky_relu_derivative(x, alpha=0.01):
    return np.where(x > 0, 1, alpha)

# Softmax activation function
def softmax(x):
    e_x = np.exp(x - np.max(x))
    return e_x / e_x.sum(axis=0)

# Testing the activation functions
if __name__ == "__main__":
    x = np.array([-2, -1, 0, 1, 2])

    print("Sigmoid:")
    print("Input:", x)
    print("Output:", sigmoid(x))
    print("Derivative:", sigmoid_derivative(sigmoid(x)))
    print()

    print("Tanh:")
    print("Input:", x)
    print("Output:", tanh(x))
    print("Derivative:", tanh_derivative(tanh(x)))
    print()

    print("ReLU:")
    print("Input:", x)
    print("Output:", relu(x))
    print("Derivative:", relu_derivative(x))
    print()

    print("Leaky ReLU:")
    print("Input:", x)
    print("Output:", leaky_relu(x))
    print("Derivative:", leaky_relu_derivative(x))
    print()

    x = np.array([1.0, 2.0, 3.0])
    print("Softmax:")
    print("Input:", x)
    print("Output:", softmax(x))
