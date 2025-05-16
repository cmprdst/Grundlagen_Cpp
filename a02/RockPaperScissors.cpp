#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*
 * Determines if choice1 beats choice2.
 *
 * Valid values for both parameters are:
 * 1: Rock
 * 2: Paper
 * 3: Scissors
 *
 * Rock beats Scissors, Paper beats Rock, Scissors beat Paper.
 *
 * Returns true if choice1 beats choice2
 */
bool beats(int choice1, int choice2) {
    if ((choice1 == 1 && choice2 == 3) || (choice1 == 2 && choice2 == 1) || (choice1 == 3 && choice2 == 2)) return true;
    return false;
}


/*
 * Performs a game of Rock-Paper-Scissors.
 *
 * Prompts the player for a choice of Rock, Paper or Scissors (1, 2 or 3)
 * and chooses a second choice to play against.
 *
 * Displays the choice of the player and computer.
 *
 * Returns true if the player wins, false if the player loses.
 * Repeats the game in case of a draw.
 */
bool play() {
    cout << "Please pick either 1 (Rock), 2 (Paper) or 3 (Scissors): " << endl;
    int input = 0;
    cin >> input;
    if (input < 1 || input > 3) return play();

    const string choices[] = {"Placeholder", "Rock", "Paper", "Scissors"};
    int opp = rand() % 3 + 1; // srand(time(nullptr)) in main() versichert neue Zufallszahl bei jedem Programmstart
    cout << "You chose " << choices[input] << ", your opponent " << choices[opp] << "." << endl;
    if (input == opp) {
        cout << "The game ended in a draw. Try again!" << endl;
        return play();
    }
    return beats(input, opp);
}

bool win(int games) {
    int wins = 0;
    int replays = 0;
    int winsNeeded = games / 2 + 1;
    while (replays < games && wins < winsNeeded) {
        if (play()) wins++;
        replays++;
    }
    return wins >= winsNeeded;
}

/*
 * Performs three games of Rock-Paper-Scissors and returns true if the player
 * wins at least two of them.
 */
bool bestOf3() { return win(3); }


/*
 * Performs five games of Rock-Paper-Scissors and returns true if the player
 * wins at least three of them.
 */
bool bestOf5() { return win(5); }

/******************************************************************************/
// Template code starts here. Please do not edit beyond this point.
/******************************************************************************/

/*
 * Converts a game mode choice into the game mode's name for display purposes.
 *
 * Note: we can only return a raw pointer here because string literals have
 * static storage duration i.e. they survive for the whole run time of the
 * program. Returning a pointer to something that is not a string literal
 * would be dangerous!
 */
const char *gameModeToString(int mode) {
    switch (mode) {
        case 1:
            return "Single";
        case 2:
            return "Best of Three";
        case 3:
            return "Best of Five";
        default:
            return "invalid";
    }
}


int main() {
    // Initialize random seed
    srand(time(nullptr));

    int mode = 0;
    while (true) {
        cout << "Choose a game mode: \n"
                << "1: " << gameModeToString(1) << "\n"
                << "2: " << gameModeToString(2) << "\n"
                << "3: " << gameModeToString(3) << "\n"
                << "0: exit\n";
        cout << "Your choice: ";
        cin >> mode;
        if (mode == 0) return 0;
        if (mode < 1 || mode > 3) {
            cout << "Invalid choice\n";
            continue;
        }
        break;
    }

    bool won = false;
    switch (mode) {
        case 1:
            won = play();
            break;
        case 2:
            won = bestOf3();
            break;
        case 3:
            won = bestOf5();
            break;
        default:
            // unreachable code
            return -1;
    }

    if (won) {
        cout << "Congratulations! You win the game!\n";
    } else {
        cout << "Unfortunate! You lose the game.\n";
    }

    return 0;
}