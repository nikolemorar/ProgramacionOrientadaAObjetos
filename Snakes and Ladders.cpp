#include <iostream>
#include <time.h>
using namespace std;

class MyGame {
protected:
  char board[30] = {
'N', 'L', 'S', 'N', 'N', 
'N', 'N', 'N', 'N', 'N', 
'L', 'N', 'N', 'N', 'S', 
'N', 'N', 'N', 'N', 'N', 
'N', 'N', 'N', 'L', 'N', 
'N', 'S', 'N', 'N', 'S'
};
  char tileclasification;

  int dice() {
    srand(time(0));
    int x = rand() % 6 + 1;
    return (x);
  };
  int player;
  int tilenumber;
  int tilefinal;
  int tileselection;
  int tile = 1;

  void turn() {
    cout << player << " " << tile << " " << dice() << " ";
    tilenumber = tile + dice();
    tileclasification = board[tilenumber];
    cout << tileclasification << " ";
    switch (tileclasification) {
    case 'N':
      tileselection = 0;
      break;
    case 'S':
      tileselection = -3;
      break;
    case 'L':
      tileselection = 3;
      break;
    }
    tilefinal = tilenumber + tileselection;
    cout << tilefinal << endl;
    tile = tilefinal;
  };

public:
  MyGame(int p) { player = p; };
  char userinput;
  bool gamend = false;

  void start() {
    switch (userinput) {
    case 'C':
    case 'c':
      turn();
      if (tile >= 30) {
        cout << "Player " << player << " has WON!!!!! " << endl;
        gamend = true;
      }
      break;
    case 'E':
    case 'e':
      cout << " Thanks fot playing!  " << endl;
      gamend = true;
      break;
    default:
      cout << "That is NOT a valid character. Please try again pressing C to continue or E to exit the game" << endl;
    }
  };
};

int main() {
  cout << "\nPress:\n C - continue next turn\n E - exit the game " << endl;
  int turn = 1;
  MyGame p1(1);
  MyGame p2(2);
  while (1) {
    if (p1.gamend == true || p2.gamend == true) {
      break;
    }
    cin >> p1.userinput;
    cout << turn << " ";
    p1.start();
    turn += 1;
    cin >> p2.userinput;
    cout << turn << " ";
    p2.start();
    turn += 1;
  }
  cout << "GAME OVER ";
}
