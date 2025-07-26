#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAX_TRIES = 6;

int letterFill(char, string, string&);

int main() {
    string name;
    char letter;
    int num_of_wrong_guesses = 0;
    string word;

    string words[] = {
        "India",
        "Pakistan",
        "Bhutan",
        "Germany",
        "Finland",
        "Nepal",
        "Malaysia",
        "Philippines",
        "Australia",
        "Iran",
        "Ethiopia",
        "Oman",
        "Indonesia",
        "America",
        "New Zealand"
    };

    srand(time(NULL));
    int n = rand() % 10;
    word = words[n];

    string unknown(word.length(), '*');

    cout << "\n\nWelcome to hangman...Guess a country Name";
    cout << "\n\nEach letter is represented by a star.";
    cout << "\n\nYou have to type only one letter in one try";
    cout << "\n\nYou have " << MAX_TRIES << " tries to guess the word.";
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";

    while (num_of_wrong_guesses < MAX_TRIES) {
        cout << "\n\n" << unknown;
        cout << "\n\nGuess a letter: ";
        cin >> letter;

        if (letterFill(letter, word, unknown) == 0) {
            cout << endl << "Whoops! That letter isn't in there!" << endl;
            num_of_wrong_guesses++;
            switch(num_of_wrong_guesses) {
    case 1:
        cout << "\n  O" << endl;
        break;
    case 2:
        cout << "\n  O\n  |" << endl;
        break;
    case 3:
        cout << "\n  O\n /|" << endl;
        break;
    case 4:
        cout << "\n  O\n /|\\ " << endl;
        break;
    case 5:
        cout << "\n  O\n /|\\\n / \\" << endl;
        break;
}
        } else {
            cout << endl << "You found a letter! Nice one!" << endl;
        }

        cout << "You have " << MAX_TRIES - num_of_wrong_guesses << " guesses left." << endl;

        if (word == unknown) {
            cout << "\n" << word << endl;
            cout << "Yeah! You got it!";
            break;
        }
    }

    if (num_of_wrong_guesses == MAX_TRIES) {
        cout << "\nSorry, you lose... you've been hanged.";
        cout << "\nThe word was: " << word << endl;
    }

    cin.ignore();
    cin.get();
    return 0;
}

// Fill in the guessed letters in the word
int letterFill(char guess, string secretword, string &guessword) {
    int matches = 0;
    for (int i = 0; i < secretword.length(); i++) {
        // Already guessed
        if (guess == guessword[i]) {
            return 0;
        }

        // Match found
        if (guess == secretword[i]) {
            guessword[i] = guess;
            matches++;
        }
    }
    return matches;
}
