#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// I have heard of this befaore and heard it's answer and the maths behind it before multiple times,
// So I do know that not swapping gives you a 1/3 chance of winning, but swapping increases that chance
// to 2/3.

bool montyHall(bool doesChange) {//returns true if the contestant won, false if they loose.
    bool doors[3] = {false, false, false};//the three doors. false is a goat, true is $$
    int win = rand() % 3;//win decides which door has $$.
    doors[win] = true;//puts $$ behind a randomly chosen door.

    //cout << doors[0] << ", " << doors[1] << ", " << doors[2] << endl;//debug

    int chosenDoor = rand() % 3;//the chosen door, either door 0, 1, or 2.
    //cout << chosenDoor << endl;// << ", " << win << endl;//debug
    int temp;//temp keeps track of how many doors can be revealed.
    if (win == chosenDoor) {
        temp = 2;
    } else {
        temp = 1;
    }

    int possibleDoorReveals[temp];//which doors can be revealed
    int j = 0;
    for (int i = 0; i < 3; i++) {//populates the posibleDoorReveals list with the appropriate integers.
        if (i != win && i != chosenDoor) {
            possibleDoorReveals[j] = i;
            j++;
        }
    }

    int revealedDoor = possibleDoorReveals[rand() % temp];
    //cout << possibleDoorReveals[0] << ", " << possibleDoorReveals[1] << endl;//debug
    //cout << temp << ", " << revealedDoor << endl;//debug

    if (doesChange) {
        for (int i = 0; i < 3; i++) {
            if (i != revealedDoor && i != chosenDoor) {
                chosenDoor = i;
                break;
            }
        }
    }
    //cout << chosenDoor << endl;//debug
    return doors[chosenDoor];


}


int main() {

    srand(time(0));
    double fails = 0;
    double wins = 0;
    
    for (int i = 0; i < 100000; i++) {//when they do switch...
        if (montyHall(true)) {
            wins++;
        } else {
            fails++;
        }
    }
    cout << "When the player/contestant switched their choice, they won " << wins << " times and lost " << fails << " times." << endl;
    cout << "This gave them a " << ((wins * 100) / 100000) << "% win rate." << endl;

    wins = 0;
    fails = 0;
    for (int i = 0; i < 100000; i++) {//...and when they don't.
        if (montyHall(false)) {
            wins++;
        } else {
            fails++;
        }
    }
    cout << "When the player/contestant did not switch their choice, they won " << wins << " times and lost " << fails << " times." << endl;
    cout << "This gave them a " << ((wins * 100) / 100000) << "% win rate." << endl;



    return 0;
}
