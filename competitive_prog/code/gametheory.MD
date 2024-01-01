# Game Theory | Grundy Numbers & Sprague Grundy Theorem

The Sprague-Grundy theorem is a mathematical concept used in combinatorial game theory. It provides a way to analyze and solve certain types of impartial games, where two players take turns making moves, and the game ends when no legal moves are possible. The theorem assigns a Grundy number to each game position, which represents its "nim-value." The nim-value is a non-negative integer that determines the outcome of the game in terms of a nim-sum.

$$ s = X_1 \oplus X_2 \oplus X_3 ... \oplus X_n  $$ 

The nim-sum of a set of numbers is the XOR (exclusive OR) of those numbers. If the nim-sum is zero, the first player has a winning strategy; otherwise, the second player has a winning strategy.

#### [Grundy Numbers - Combinatorial Game Theory - I](https://youtu.be/MboYbpE76js?si=QKhCpu5zX9nb9WLm), [Sprague Grundy Theorem - Combinatorial Game Theory - II](https://youtu.be/AbJqhMm8htw?si=ihmlMHrgETNBpVw_), [Game Theory L-2 | Grundy Numbers & Sprague Grundy Theorem](https://www.youtube.com/live/AaaEl55iK40?si=XBOoXQYwF2HDpfPb), [Nimbers And Sprague Grundy Theorem](https://www.youtube.com/live/h2ZsdmUkfMI?si=7Lq1IH9ofwQTQBiT)

Here's a simple explanation of the Sprague-Grundy theorem with code in Python:

```python

def calculate_grundy_number(position):
    if position == 0:
        return 0  # Grundy number of an empty position is 0

    visited_positions = set()

    for move in generate_possible_moves(position):
        next_position = position - move

        # Calculate Grundy number recursively for the next position
        grundy_number = calculate_grundy_number(next_position)

        visited_positions.add(grundy_number)

    # Find the smallest non-negative integer not in the set of Grundy numbers
    current_grundy_number = 0
    while current_grundy_number in visited_positions:
        current_grundy_number += 1

    return current_grundy_number

def generate_possible_moves(position):
    # Implement the logic to generate possible moves for the game
    # Return a list of valid moves for the given position
    pass

# Example usage
initial_position = 7
grundy_number = calculate_grundy_number(initial_position)

if grundy_number == 0:
    print("First player wins!")
else:
    print("Second player wins!")


```

In this code:

+ `calculate_grundy_number` is a recursive function that calculates the Grundy number for a given game position.
+ `generate_possible_moves` is a placeholder function where we need to implement the logic to generate valid moves for the game.


The Grundy number is calculated by recursively finding the Grundy numbers of possible next positions and then determining the smallest non-negative integer not in the set of Grundy numbers. This ensures that the Grundy number represents the nim-value of the current position. The example usage section demonstrates how to determine the winner based on the Grundy number.