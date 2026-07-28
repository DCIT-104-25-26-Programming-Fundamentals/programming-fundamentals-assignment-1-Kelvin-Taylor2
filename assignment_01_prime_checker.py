# =============================================================================
# PROGRAMMING FUNDAMENTALS — Assignment 1
# Topic: Conditional Logic, Loops, and Functions
# =============================================================================
#
# TASK: Prime Number Checker
#
# Write a Python program that checks whether a given number is prime.
#
# A prime number is a whole number greater than 1 that has no divisors
# other than 1 and itself (e.g., 2, 3, 5, 7, 11, 13 ...).
#
# -----------------------------------------------------------------------------
# EXPECTED INPUT / OUTPUT EXAMPLES
# -----------------------------------------------------------------------------
#
#   Enter a number: 7
#   7 is a prime number.
#
#   Enter a number: 10
#   10 is NOT a prime number.
#
#   Enter a number: 1
#   1 is NOT a prime number.
#
# -----------------------------------------------------------------------------
# REQUIREMENTS
# -----------------------------------------------------------------------------
# - You MUST implement the logic inside a function (see scaffold below).
# - Numbers less than 2 are NOT prime — handle this inside the function.
# - The main block must call the function and print the result.
#

# =============================================================================
# YOUR CODE BELOW — remove the # symbols from the scaffold and fill it in
# =============================================================================

def is_prime(n):
    """
    Checks whether a given number is prime.

    Parameters:
        n (int): The number to check.

    Returns:
        bool: True if n is prime, False otherwise.
    """
    # Numbers less than 2 are not prime
    if n < 2:
        return False

    # Check divisors from 2 to sqrt(n)
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False  # Divisible by a number other than 1 and itself
        i += 1

    return True  # No divisors found, it's prime


def main():
    """
    Main function that reads a number from the user and prints whether it is prime.
    """
    try:
        num = int(input("Enter a number: "))

        if is_prime(num):
            print(f"{num} is a prime number.")
        else:
            print(f"{num} is NOT a prime number.")

    except ValueError:
        print("Error: Please enter a valid integer.")


if __name__ == "__main__":
    main()

