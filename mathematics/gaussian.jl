using Random
using Plots

# Set a random seed for reproducibility
Random.seed!(123)

# Generate random data points from a Gaussian distribution
μ = 0.0    # Mean
σ = 1.0    # Standard deviation
num_samples = 1000

data = μ + σ * randn(num_samples)

# Create a histogram of the data
histogram(data, bins=30, normalize=true, label="Data Histogram", xlabel="Value", ylabel="Probability", alpha=0.7)

# Generate points for the probability density function (PDF)
x = range(-5, stop=5, length=1000)
pdf_y = pdf(Normal(μ, σ), x)

# Overlay the Gaussian PDF on the histogram
plot!(x, pdf_y, linewidth=2, color="red", label="Gaussian PDF")

# Show the plot
display(Plots.plot())
