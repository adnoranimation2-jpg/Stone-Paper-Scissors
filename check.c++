#include <iostream>
#include <string>

using namespace std;

string ReadPassword() {
    string Password;
    cout << "Enter a 3-char Password (Upper, Lower, or Numbers): ";
    cin >> Password;
    return Password;
}

bool GuessPassword(string OriginalPassword) {
    // Character pool: A-Z, a-z, and 0-9
    string CharList = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    string word = "###"; 
    int Counter = 0;

    for (int i = 0; i < CharList.length(); i++) {
        for (int j = 0; j < CharList.length(); j++) {
            for (int k = 0; k < CharList.length(); k++) {
                
                Counter++;
                word[0] = CharList[i];
                word[1] = CharList[j];
                word[2] = CharList[k];

                // Optional: Comment out the line below to make it run faster
                // cout << "Trial [" << Counter << "] : " << word << endl;

                if (word == OriginalPassword) {
                    cout << "\nFound! Password is: " << word << "\n";
                    cout << "Total Trials: " << Counter << "\n";
                    return true;
                }
            }
        }
    }
    cout << "\nPassword not found within 3 characters.\n";
    return false;
}

int main() {
    GuessPassword(ReadPassword());
    return 0;
}