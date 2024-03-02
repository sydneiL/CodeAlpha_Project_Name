//Created by Sydnei Lang on 3/2/24.
//C++ Task Project for CodeAlpha
//Mystery Quest//
//Plyaers must guess numbers


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "Welcome to Treasure Hunt: Guess the Number!" << endl;
    cout << "Embark on an adventure to uncover hidden treasures!" << endl;
    cout << "I've hidden a number between 1 and 100. Can you guess it and claim the treasure?" << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Your search takes you too high! Try a lower number." << endl;
        } else if (guess < secretNumber) {
            cout << "Your search takes you too low! Aim higher." << endl;
        } else {
            cout << "Congratulations, brave treasure hunter! You've uncovered the hidden treasure - the number " << secretNumber << "!" << endl;
            cout << "As a reward for your efforts, you've won a valuable gemstone!" << endl;
            // You can add more rewards or gifts here
            cout << "Thank you for playing Treasure Hunt: Guess the Number!" << endl;
        }
    } while (guess != secretNumber);

    return 0;
}
