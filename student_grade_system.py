# =============================================================================
# PROGRAMMING FUNDAMENTALS — Assignment 2
# Topic: Conditional Logic (if / elif / else) and Functions
# =============================================================================
#
# TASK: Student Grade System
#
# Write a Python program that reads a student's score and outputs the
# corresponding letter grade based on the scale below.
#
# Grading Scale:
#   Score 80 – 100  →  Grade A
#   Score 70 – 79   →  Grade B
#   Score 60 – 69   →  Grade C
#   Score 50 – 59   →  Grade D
#   Score below 50  →  Grade F
#
# =============================================================================


def get_grade(score):
    """
    Determines the letter grade based on the score.

    Parameters:
        score (int/float): The student's score.

    Returns:
        str or None: The letter grade ('A', 'B', 'C', 'D', 'F')
                     or None if the score is outside 0–100.
    """
    if score < 0 or score > 100:
        return None

    if score >= 80:
        return 'A'
    elif score >= 70:
        return 'B'
    elif score >= 60:
        return 'C'
    elif score >= 50:
        return 'D'
    else:
        return 'F'


def main():
    """
    Main function that reads a student's score and prints the grade.
    """
    try:
        score = float(input("Enter student score (0-100): "))

        grade = get_grade(score)

        if grade is None:
            print("Error: Score must be between 0 and 100.")
        else:
            print(f"Grade: {grade}")

    except ValueError:
        print("Error: Please enter a valid numeric score.")


if __name__ == "__main__":
    main()

