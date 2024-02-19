# Samson Shi
# Initialize word lists for Easy, Medium, and Hard levels.
# Define global variables for the current word and guess.
# Define main functions:
#    - update_scores_file: Append score and name to 'scores.txt'.
#    - print_scoreboard: Display top 3 scores from 'scores.txt'.
#    - selectWord: Choose a word based on selected difficulty.
#    - playing: Main game logic for guessing letters and checking win/lose.
#    - Menu: Show game menu and handle user choices.
#    - getLetter: Input and validate a single letter guess.
# Start the game with the Menu function, letting the user choose to play, view scores, or exit.
# In gameplay, select a word and allow the player to guess letters or the entire word.
# Track guesses, reveal correct letters, and manage game end conditions.
# Update and show scores upon successful guesses or game end.
# Loop back to the main menu for new game sessions or exiting.

# Import necessary libraries for system operations, random selection, and date/time handling
import os, random, datetime

# Clear the console for a clean game start
os.system('clear')

# Word Lists Section
# Define word lists for different difficulty levels
HardWords = ["craziest", "Phenomenon", "Worcestershire", "Sixth", "Mischievous", "Draconian", "Homogeneous", "Laconic", "Corroborate", "Pragmatic"]
MediumWords = ["aggressive", "futuristic", "imagine", "religion", "produce", "fraudulent", "Japanese", "diverse", "entrepreneur", "acknowledgement"]
EasyWords = ["bananas", "grapes", "pharmacy", 'post office', 'apples', "cafeteria", "papaya", 'oranges', 'towers', 'mangos', 'kiwis', 'house']

# Variables for game state
word = ""  # To store the current word to guess
guess = ""  # To store the player's current guess

# Function to update scores file
# Saves player score and name to "scores.txt" with current date
def update_scores_file(score, name):
    with open("scores.txt", "a") as f:
        f.write(f"{score} {name} {datetime.datetime.now().strftime('%m/%d/%Y')}\n")

# Function to print top scores from "scores.txt"
# Reads scores, sorts them, and displays the top 3
def print_scoreboard():
    scores = []
    with open("scores.txt", "r") as f:
        for line in f.readlines():
            parts = line.split()
            scores.append((int(parts[0]), parts[1], datetime.datetime.strptime(parts[2], '%m/%d/%Y')))
    sorted_scores = sorted(scores, reverse=True)
    print("Top 3 Scores:")
    for i in range(min(3, len(sorted_scores))):
        score, name, date = sorted_scores[i]
        print(f"{score}\t{name}\t{date.strftime('%m/%d/%Y')}")

# Function to select a word based on player's choice of difficulty
# Chooses a word from the appropriate list and sets it to lowercase
def selectWord(choice):
    global word
    if '2' in choice:
        word = random.choice(EasyWords)
    elif '3' in choice:
        word = random.choice(MediumWords)
    elif '4' in choice:
        word = random.choice(HardWords)
    word = word.lower()

# Main gameplay function
# Manages guessing turns, displays letters, and checks for game end conditions
def playing():
    turns = len(word) + 2  # Number of allowed guesses
    check = True  # Game state check
    guesses = ''  # Store letters guessed by the player

    while turns > 0 and check:
        for letter in word:
            if letter in guesses:
                print(letter, end=" ")
            else:
                print("_", end=" ")
        getLetter()  # Get a letter guess from the player

        # Check if guessed letter is in the word
        if guess in word:
            if guess not in guesses:
                guesses += guess
                print("Good guess")
            else:
                print("You have used that letter before")
        else:
            turns -= 1
            print("Sorry, guess again")

        # Check for win condition
        if len(guesses) >= len(set(word)) - 1:
            check = False

    # End of game actions
    if not check:
        score = len(word) * 5 * turns
        print("You guessed correctly, your score was", score)
        name = input("Enter your name: ")
        update_scores_file(score, name)
    else:
        print("Sorry you did not guess correctly...")

    input("Press enter to continue")
    Menu()  # Return to the main menu

# Main Menu Function
# Displays game options and handles player input
def Menu():
    os.system('clear')  # Clear the screen for menu display
    print("### Word Game Menu ###")
    print("# 1. Instructions")
    print("# 2. Easy Words")
    print("# 3. Medium Words")
    print("# 4. Hard Words")
    print("# 5. ScoreBoard")
    print("# 6. Exit")
    choice = input("Enter your choice: ")

    # Handle menu choices
    if '1' in choice:
        # Display instructions (simplified for this pseudocode)
        print("1.Select Difficulty: Choose from Easy (2), Medium (3), or Hard (4) levels. 2.Guessing: You can guess one letter at a time or the entire word. 3.Revealing Letters: Correctly guessed letters are revealed in their positions. 4.Chances: You get the word's length plus two extra guesses. 5.Incorrect Guesses: Each wrong guess reduces your remaining chances. 6.Winning: Guess all letters or the whole word correctly to win. 7.Scoring: Your score is based on the difficulty, word length, and remaining guesses. Enter your name to record your score. 8.Scoreboard: View the top scores via the main menu.")
        input("Press return to go back to main menu")
    elif choice in ['2', '3', '4']:
        selectWord(choice)
        playing()
    elif '5' in choice:
        print_scoreboard()
        input("Press return to continue")
    elif '6' in choice:
        print("Goodbye")
        exit()
    else:
        print("Please enter a valid option")
    Menu()

# Function to get a letter guess from the player
# Validates input as a single alphabetic character
def getLetter():
    global guess
    guess = input("\nEnter a letter to guess the word: ").lower()
    while not (guess.isalpha() and len(guess) == 1):
        print("Only one letter please")
        guess = input("Enter a letter to guess the word: ").lower()

# Start the game by calling the main menu
Menu()
