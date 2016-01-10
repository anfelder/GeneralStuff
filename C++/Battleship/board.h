#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <QCoreApplication>
#include <QProcess>
#define BOARD_SIZE 11

#define PATROL_SIZE 2
#define DESTROYER_SIZE 3
#define CARRIER_SIZE 5
#define SUBMARINE_SIZE 3
#define BATTLESHIP_SIZE 4

using namespace std;

class Board
{
public:
    Board();
    void print();
    void updateBoard(int x, int y, char c);
    void updateHMBoard();

    void setCPUShips();
    void setCPUDestroyer();
    void setCPUPatrol();
    void setCPUCarrier();
    void setCPUSubmarine();
    void setCPUBattleship();
    bool validUp(int x, int y,int ship_size);
    bool validDown(int x, int y, int ship_size);
    bool validLeft(int x, int y, int ship_size);
    bool validRight(int x, int y, int ship_size);


    void setShips();
    void setDestroyer();
    void setPatrol();
    void setCarrier();
    void setSubmarine();
    void setBattleship();
    bool validSpace(int ship_size, char direction, int x, int y);
    bool validStart(int x, int y);

    void decrementPHits();
    int getPHits();
    int getCPUHits();
    char getBoardLoc(int x, int y);

    void chooseHitSpot();

private:
    //player's board, includes 1-10 column markers
    char board[BOARD_SIZE][BOARD_SIZE];
    //cpu's board, hidden to player
    char cpu_board[BOARD_SIZE-1][BOARD_SIZE];
    //board that player sees that shows hits/misses
    char placeholder_board[BOARD_SIZE-1][BOARD_SIZE];
    int player_hits;

};

#endif // BOARD_H
