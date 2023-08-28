import numpy as np

# Define the sigmoid activation function and its derivative
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

# Define the neural network architecture
class NeuralNetwork:
    def __init__(self, input_size, hidden_size, output_size):
        # Initialize the weights and biases with random values
        self.weights_input_hidden = np.random.rand(input_size, hidden_size)
        self.bias_hidden = np.random.rand(1, hidden_size)
        self.weights_hidden_output = np.random.rand(hidden_size, output_size)
        self.bias_output = np.random.rand(1, output_size)

    def forward(self, inputs):
        # Compute the input to hidden layer
        self.hidden_input = np.dot(inputs, self.weights_input_hidden) + self.bias_hidden
        # Apply the activation function
        self.hidden_output = sigmoid(self.hidden_input)

        # Compute the input to output layer
        self.output_input = np.dot(self.hidden_output, self.weights_hidden_output) + self.bias_output
        # Apply the activation function
        self.output = sigmoid(self.output_input)

        return self.output

    def backward(self, inputs, targets, learning_rate):
        # Compute the error in the output layer
        error_output = targets - self.output
        delta_output = error_output * sigmoid_derivative(self.output)

        # Compute the error in the hidden layer
        error_hidden = delta_output.dot(self.weights_hidden_output.T)
        delta_hidden = error_hidden * sigmoid_derivative(self.hidden_output)

        # Update the weights and biases
        self.weights_hidden_output += self.hidden_output.T.dot(delta_output) * learning_rate
        self.bias_output += np.sum(delta_output, axis=0, keepdims=True) * learning_rate
        self.weights_input_hidden += inputs.T.dot(delta_hidden) * learning_rate
        self.bias_hidden += np.sum(delta_hidden, axis=0, keepdims=True) * learning_rate

    def train(self, inputs, targets, learning_rate, epochs):
        for epoch in range(epochs):
            output = self.forward(inputs)
            self.backward(inputs, targets, learning_rate)
            loss = np.mean(np.square(targets - output))
            if epoch % 1000 == 0:
                print(f"Epoch {epoch}, Loss: {loss:.4f}")

# Define the training data (XOR problem)
X = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
Y = np.array([[0], [1], [1], [0]])

# Create a neural network with 2 input neurons, 2 hidden neurons, and 1 output neuron
nn = NeuralNetwork(input_size=2, hidden_size=2, output_size=1)

# Train the neural network
nn.train(X, Y, learning_rate=0.1, epochs=10000)

# Test the trained neural network
test_data = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
predicted_output = nn.forward(test_data)
print("Predicted Output:")
print(predicted_output)
