#include <iostream>
#include <string>
#include <windows.h>
#include <cstdlib> 
#include <ctime>   

using namespace std;

enum enChoise_User { User_Stone = 1, User_Paper = 2, User_Scissors = 3 };
enum enChoise_Computer { Stone = 1, Paper = 2, Scissors = 3 };

// Function to convert the number to a Word for display
string ChoiceToText(int choice) {
    if (choice == 1) return "Stone";
    if (choice == 2) return "Paper";
    if (choice == 3) return "Scissors";
    return "Unknown";
}

// Function to convert user's word input into the Enum
enChoise_User ReadInput() {
    string choice;
    bool isValid = false;

    while (!isValid) {
        cout << "Enter Choice (Stone, Paper, Scissors): ";
        cin >> choice;

        if (choice == "Stone" || choice == "stone") {
            return User_Stone;
        } 
        else if (choice == "Paper" || choice == "paper") {
            return User_Paper;
        } 
        else if (choice == "Scissors" || choice == "scissors") {
            return User_Scissors;
        } 
        else {
            cout << "Invalid Input! Please type Stone, Paper, or Scissors." << endl;
            isValid = false; 
        }
    }
    return User_Stone;
}

int computerChoise() {
    return (rand() % 3) + 1;
}

void CheckWinner(enChoise_Computer computerCh, enChoise_User playerCh) {
    // --- YOUR ORIGINAL LOGIC KEPT EXACTLY THE SAME ---
    if (computerCh == Scissors && playerCh == User_Scissors) {
        cout << "\a"; 
        cout << "It is Draw" << endl;
        system("Color 6F"); 
    } else if (computerCh == Stone && playerCh == User_Stone) {
        cout << "\a"; 
        cout << "It is Draw" << endl;
        system("Color 6F"); 
    } else if (computerCh == Paper && playerCh == User_Paper) {
        cout << "\a"; 
        cout << "It is Draw" << endl;
        system("Color 6F"); 
    } else if (computerCh == Stone && playerCh == User_Scissors) {
        cout << "\a"; 
        cout << "It is Lose" << endl;
        system("Color 4F"); 
    } else if (computerCh == Paper && playerCh == User_Stone) {
        cout << "\a"; 
        cout << "It is Lose" << endl;
        system("Color 4F"); 
    } else if (computerCh == Scissors && playerCh == User_Paper) {
        cout << "\a"; 
        cout << "It is Lose" << endl;
        system("Color 4F"); 
    } else if (computerCh == Paper && playerCh == User_Scissors) {
        cout << "\a"; 
        cout << "It is Win" << endl;
        system("Color 2F"); 
    } else if (computerCh == Scissors && playerCh == User_Stone) {
        cout << "\a"; 
        cout << "It is Win" << endl;
        system("Color 2F"); 
    } else {
        cout << "\a"; 
        cout << "It is Win" << endl;
        system("Color 2F"); 
    }
}

int main() {
    srand((unsigned)time(NULL));
    string playAgain;

    do {
        system("cls");
        system("Color 0F");

        int rounds;
        cout << "How many rounds do you want to play? ";
        cin >> rounds;

        for (int i = 1; i <= rounds; i++) {
            cout << "\n--- Round " << i << " ---" << endl;
            
            enChoise_User playerChoice = ReadInput();
            enChoise_Computer compChoice = (enChoise_Computer)computerChoise();

            // Displaying words instead of numbers
            cout << "\nYour Choice: " << ChoiceToText(playerChoice) << endl;
            cout << "Computer Choice: " << ChoiceToText(compChoice) << endl;
            cout << "-----------------------" << endl;

            CheckWinner(compChoice, playerChoice);
        }

        cout << "\n================================" << endl;
        cout << "GAME OVER. Print Game Results here." << endl;
        cout << "================================" << endl;

        cout << "\nDo you want to play again? (yes/no): ";
        cin >> playAgain;

    } while (playAgain == "yes" || playAgain == "Yes" || playAgain == "y");

    system("cls");
    system("Color 0F");
    return 0;
}