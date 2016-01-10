/*
 *
 * Andrew Felder
 * Battleship with basic AI
 *
 */
#include "ai.h"

int main(int argc, char *argv[])
{
    srand(time(NULL));
    cout << "Welcome to Battleship!\nYou will be placing your ships on the bottom half while the\ntop half keeps "
         << "up with your hits and misses" << endl << endl;
    Board board;
    AI ai;
    //setup game
    board.print();
    board.setShips();
    board.setCPUShips();
    cout << endl;
    //play game
    QProcess::execute("clear");

    while(board.getPHits() > 0 && ai.getCPUHits() > 0){
        board.print();
        board.chooseHitSpot();
        ai.runAI(board);
    }

    return 0;
}
