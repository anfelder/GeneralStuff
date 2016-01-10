#include "ai.h"

AI::AI(){
    difficulty = 0;
    while(difficulty < 1 || difficulty > 3){
        cout << "Choose your difficulty:\nEasy: 1\nMedium: 2\nHard: 3" << endl;
        cin >> difficulty;
    }

    cpu_hits = PATROL_SIZE + BATTLESHIP_SIZE + DESTROYER_SIZE + SUBMARINE_SIZE + CARRIER_SIZE;
}

void AI::runAI(Board &board){
    if(difficulty == EASY) runEasy(board);
    else if(difficulty == MEDIUM) runMedium(board);
    else if(difficulty == HARD) runHard(board);
}

void AI::runEasy(Board &board){
    cout << endl;
    int x = generateRandCoord();
    int y = generateRandCoord();
    while(board.getBoardLoc(x, y) == ',' || board.getBoardLoc(x, y) == 'H' ){
        x = generateRandCoord();
        y = generateRandCoord();
    }
    cout << "The enemy shot at the location (" << char(y + 64) << ", " << x << ")" << endl;
    if(board.getBoardLoc(x, y) == '.'){
        board.updateBoard(x, y, ',');
        cout << "The enemy has missed your ships." << endl;
    }
    else generateHitMessage(x, y, board);
    cout << endl;

}
void AI::runMedium(Board &board){

}
void AI::runHard(Board &board){

}

void AI::runHitRoutine(){

}
void AI::generateHitMessage(int x, int y, Board &board){
    static int p_hits = 2;
    static int d_hits, s_hits = 3;
    static int b_hits = 4;
    static int c_hits = 5;
    if(board.getBoardLoc(x, y) == 'P'){
        cout << "The enemy has hit your Patrol Boat!" << endl;
        p_hits--;
        if(p_hits == 0) cout << "The enemy has sunk your Patrol Boat!" << endl;
        board.updateBoard(x, y, 'H');
    }
    else if(board.getBoardLoc(x, y) == 'D'){
        cout << "The enemy has hit your Destroyer!" << endl;
        d_hits--;
        if(d_hits == 0) cout << "The enemy has sunk your Destroyer!" << endl;
        board.updateBoard(x, y, 'H');
    }
    else if(board.getBoardLoc(x, y)== 'S'){
        cout << "The enemy has hit your Submarine!" << endl;
        s_hits--;
        if(s_hits == 0) cout << "The enemy has sunk your Submarine!" << endl;
        board.updateBoard(x, y, 'H');
    }
    else if(board.getBoardLoc(x, y) == 'B'){
        cout << "The enemy has hit your Battleship!" << endl;
        b_hits--;
        if(b_hits == 0) cout << "The enemy has sunk your Battleship!" << endl;
        board.updateBoard(x, y, 'H');
    }
    else if(board.getBoardLoc(x, y)== 'C'){
        cout << "The enemy has hit your Carrier Ship!" << endl;
        c_hits--;
        if(c_hits == 0) cout << "The enemy has sunk your Carrier Ship!" << endl;
        board.updateBoard(x, y, 'H');
    }
    decrementCPUHits();
}

int AI::generateRandCoord(){
    return ((rand() % 10) + 1);
}

void AI::decrementCPUHits(){
    cpu_hits--;
}

int AI::getCPUHits(){
    return cpu_hits;
}
