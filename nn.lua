require 'torch'
require 'nn'

-- Define a simple feedforward neural network
local inputSize = 2
local hiddenSize = 3
local outputSize = 1

local model = nn.Sequential()
model:add(nn.Linear(inputSize, hiddenSize))  -- Input layer to hidden layer
model:add(nn.Tanh())                        -- Activation function (Tanh)
model:add(nn.Linear(hiddenSize, outputSize)) -- Hidden layer to output layer
model:add(nn.Sigmoid())                     -- Activation function (Sigmoid)

-- Define the loss function (Binary Cross-Entropy for binary classification)
local criterion = nn.BCECriterion()

-- Generate some sample data for training
local input = torch.Tensor{
  {0, 0},
  {0, 1},
  {1, 0},
  {1, 1}
}
local target = torch.Tensor{
  {0},
  {1},
  {1},
  {0}
}

-- Define the optimization algorithm (Stochastic Gradient Descent)
local learningRate = 0.1
local optimizer = nn.SGD(model.parameters, learningRate)

-- Training loop
local epochs = 10000
for epoch = 1, epochs do
  -- Forward pass
  local output = model:forward(input)
  
  -- Compute the loss
  local loss = criterion:forward(output, target)
  
  -- Backpropagation
  model:zeroGradParameters()
  local gradOutput = criterion:backward(output, target)
  model:backward(input, gradOutput)
  
  -- Update the weights
  optimizer:update()
  
  -- Print the loss every 1000 epochs
  if epoch % 1000 == 0 then
    print('Epoch ' .. epoch .. ', Loss: ' .. loss)
  end
end

-- Test the trained model
local testInput = torch.Tensor{
  {0, 0},
  {0, 1},
  {1, 0},
  {1, 1}
}
local testOutput = model:forward(testInput)
print('Predicted Output:')
print(testOutput)
