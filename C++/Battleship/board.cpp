#include "board.h"

Board::Board(){
    for(int r = 0;r<BOARD_SIZE;r++){
        for(int c = 0;c<BOARD_SIZE;c++){
            if(r == 0 && c == 0){
                board[r][c] = ' ';
                cpu_board[r][c] = 'A';
                placeholder_board[r][c] = 'A';
            }
            else if(r == 0 && c == BOARD_SIZE - 1){
                board[r][c] = '0';
                cpu_board[r][c] = '.';
                placeholder_board[r][c] = '.';
            }
            else if(r == 0){
                board[r][c] = (c + '0');
                cpu_board[r][c] = '.';
                placeholder_board[r][c] = '.';
            }
            else if(c == 0){
                board[r][c] = (char)(64 + r);
                cpu_board[r][c] = (char)(65 + r);
                placeholder_board[r][c] = (char)(65 + r);
            }
            else{
                board[r][c] = '.';
                if(r != BOARD_SIZE-1){
                    cpu_board[r][c] = '.';
                    placeholder_board[r][c] = '.';
                }
            }
        }
    }
    placeholder_board[0][0] = 'A';
    player_hits = PATROL_SIZE + BATTLESHIP_SIZE + DESTROYER_SIZE + SUBMARINE_SIZE + CARRIER_SIZE;
}
void Board::print(){
    for(int r = 0;r<BOARD_SIZE - 1;r++){
        for(int c = 0;c<BOARD_SIZE;c++){
            cout << placeholder_board[r][c] << " ";
        }
        cout << endl;
    }
    for(int r = 0;r<BOARD_SIZE;r++){
        for(int c = 0;c<BOARD_SIZE;c++){
            cout << board[r][c] << " ";
        }
        cout << endl;
    }
}

void Board::setShips(){
    setBattleship();
    system("clear");
    print();
    setCarrier();
    system("clear");
    print();
    setDestroyer();
    system("clear");
    print();
    setPatrol();
    system("clear");
    print();
    setSubmarine();
    system("clear");
    print();
}
void Board::setBattleship(){
    char start_y = 'z';
    char ship_letter = 'B';
    int s_y;
    int start_x = -1;
    char direction = 'z';
    bool direction_invalid = true;
    int ship_size = 4;

    //choose starting spot
    while(!validStart(start_x, start_y)){
        start_x = -1;
        start_y = 'z';
        cout << "Enter a valid location of first point of your Battleship:" << endl;
        while((int)start_y > 74 || (int)start_y < 65 ){
            cout << "Enter Valid Letter Location (A-J): ";
            cin >> start_y;
            start_y = toupper(start_y);
        }
        //cin >> junk;
        while(start_x < 1 || start_x > 10){
            cout << "Enter number location (1-10): ";
            cin >> start_x;
        }
    }
    //choose their direction
    cout << "Would you like your ship to be above, below, left of, or right of your starting point? (U/D/L/R) ";
    while(direction_invalid){
        cin >> direction;
        direction = toupper(direction);
        if(direction == 'U' && (int)start_y < 68)
            cout << "Your ship is placed too high to make it go up from the start point." << endl;
        else if(direction == 'D' && (int)start_y > 71)
            cout << "Your ship is placed too low to make it go down from the start point." << endl;
        else if(direction == 'L' && start_x < 4)
            cout << "Your ship is placed too far left to make it go left from the start point." << endl;
        else if(direction == 'R' && start_x > 7)
            cout << "Your ship is placed too far right to make it go right from the start point." << endl;
        else if(direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R')
            cout << "Please enter \'U\', \'D\', \'L\', \'R\' ";
        else if(!validSpace(ship_size, direction, start_x, start_y))
            cout << "There is already a ship in that space ";
        else if(direction == 'U' || direction == 'D' || direction == 'L' || direction == 'R') direction_invalid = false;
    }

    s_y = (int)start_y - 64;
    for(int i = 0;i < ship_size; i++){
        if(direction == 'U')            board[s_y - i][start_x] = ship_letter;
        else if(direction == 'D')       board[s_y + i][start_x] = ship_letter;
        else if(direction == 'L')       board[s_y][start_x - i] = ship_letter;
        else if(direction == 'R')       board[s_y][start_x + i] = ship_letter;
    }
}
void Board::setCarrier(){
    char start_y = 'z';
    char ship_letter = 'C';
    int s_y;
    int start_x = -1;
    char direction = 'z';
    bool direction_invalid = true;
    int ship_size = 5;

    //choose starting spot
    while(!validStart(start_x, start_y)){
        start_x = -1;
        start_y = 'z';
        cout << "Enter a valid location of first point of your Carrier:" << endl;
        while((int)start_y > 74 || (int)start_y < 65 ){
            cout << "Enter Valid Letter Location (A-J): ";
            cin >> start_y;
            start_y = toupper(start_y);
        }
        //cin >> junk;
        while(start_x < 1 || start_x > 10){
            cout << "Enter number location (1-10): ";
            cin >> start_x;
        }
    }

    //choose their direction
    cout << "Would you like your ship to be above, below, left of, or right of your starting point? (U/D/L/R) ";
    while(direction_invalid){
        cin >> direction;
        direction = toupper(direction);
        if(direction == 'U' && (int)start_y < (64 + ship_size))
            cout << "Your ship is placed too high to make it go up from the start point." << endl;
        else if(direction == 'D' && (int)start_y > (75 - ship_size))
            cout << "Your ship is placed too low to make it go down from the start point." << endl;
        else if(direction == 'L' && start_x < ship_size)
            cout << "Your ship is placed too far left to make it go left from the start point." << endl;
        else if(direction == 'R' && start_x > (11 - ship_size))
            cout << "Your ship is placed too far right to make it go right from the start point." << endl;
        else if(direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R')
            cout << "Please enter \'U\', \'D\', \'L\', \'R\' ";
        else if(!validSpace(ship_size, direction, start_x, start_y))
            cout << "There is already a ship in that space ";
        else if(direction == 'U' || direction == 'D' || direction == 'L' || direction == 'R') direction_invalid = false;
    }

    s_y = (int)start_y - 64;
    for(int i = 0;i < ship_size; i++){
        if(direction == 'U')            board[s_y - i][start_x] = ship_letter;
        else if(direction == 'D')       board[s_y + i][start_x] = ship_letter;
        else if(direction == 'L')       board[s_y][start_x - i] = ship_letter;
        else if(direction == 'R')       board[s_y][start_x + i] = ship_letter;
    }
}
void Board::setDestroyer(){
    char start_y = 'z';
    char ship_letter = 'D';
    int s_y;
    int start_x = -1;
    char direction = 'z';
    bool direction_invalid = true;
    int ship_size = 3;

    //choose starting spot
    while(!validStart(start_x, start_y)){
        start_x = -1;
        start_y = 'z';
        cout << "Enter a valid location of first point of your Destroyer:" << endl;
        while((int)start_y > 74 || (int)start_y < 65 ){
            cout << "Enter Valid Letter Location (A-J): ";
            cin >> start_y;
            start_y = toupper(start_y);
        }
        //cin >> junk;
        while(start_x < 1 || start_x > 10){
            cout << "Enter number location(1-10): ";
            cin >> start_x;
        }
    }
    //choose their direction
    cout << "Would you like your ship to be above, below, left of, or right of your starting point? (U/D/L/R) ";
    while(direction_invalid){
        cin >> direction;
        direction = toupper(direction);
        if(direction == 'U' && (int)start_y < (64 + ship_size))
            cout << "Your ship is placed too high to make it go up from the start point." << endl;
        else if(direction == 'D' && (int)start_y > (75 - ship_size))
            cout << "Your ship is placed too low to make it go down from the start point." << endl;
        else if(direction == 'L' && start_x < ship_size)
            cout << "Your ship is placed too far left to make it go left from the start point." << endl;
        else if(direction == 'R' && start_x > (11 - ship_size))
            cout << "Your ship is placed too far right to make it go right from the start point." << endl;
        else if(direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R')
            cout << "Please enter \'U\', \'D\', \'L\', \'R\' ";
        else if(!validSpace(ship_size, direction, start_x, start_y))
            cout << "There is already a ship in that space ";
        else if(direction == 'U' || direction == 'D' || direction == 'L' || direction == 'R') direction_invalid = false;
    }

    s_y = (int)start_y - 64;
    for(int i = 0;i < ship_size; i++){
        if(direction == 'U')            board[s_y - i][start_x] = ship_letter;
        else if(direction == 'D')       board[s_y + i][start_x] = ship_letter;
        else if(direction == 'L')       board[s_y][start_x - i] = ship_letter;
        else if(direction == 'R')       board[s_y][start_x + i] = ship_letter;
    }
}
void Board::setPatrol(){
    char start_y = 'z';
    char ship_letter = 'P';
    int s_y;
    int start_x = -1;
    char direction = 'z';
    bool direction_invalid = true;
    int ship_size = 2;

    //choose starting spot
    while(!validStart(start_x, start_y)){
        start_x = -1;
        start_y = 'z';
        cout << "Enter a valid location of first point of your Patrol Boat:" << endl;
        while((int)start_y > 74 || (int)start_y < 65 ){
            cout << "Enter Valid Letter Location (A-J): ";
            cin >> start_y;
            start_y = toupper(start_y);
        }
        //cin >> junk;
        while(start_x < 1 || start_x > 10){
            cout << "Enter number location (1-10): ";
            cin >> start_x;
        }
    }
    //choose their direction
    cout << "Would you like your ship to be above, below, left of, or right of your starting point? (U/D/L/R) ";
    while(direction_invalid){
        cin >> direction;
        direction = toupper(direction);
        if(direction == 'U' && (int)start_y < (64 + ship_size))
            cout << "Your ship is placed too high to make it go up from the start point." << endl;
        else if(direction == 'D' && (int)start_y > (75 - ship_size))
            cout << "Your ship is placed too low to make it go down from the start point." << endl;
        else if(direction == 'L' && start_x < ship_size)
            cout << "Your ship is placed too far left to make it go left from the start point." << endl;
        else if(direction == 'R' && start_x > (11 - ship_size))
            cout << "Your ship is placed too far right to make it go right from the start point." << endl;
        else if(direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R')
            cout << "Please enter \'U\', \'D\', \'L\', \'R\' ";
        else if(!validSpace(ship_size, direction, start_x, start_y))
            cout << "There is already a ship in that space ";
        else if(direction == 'U' || direction == 'D' || direction == 'L' || direction == 'R') direction_invalid = false;
    }

    s_y = (int)start_y - 64;
    for(int i = 0;i < ship_size; i++){
        if(direction == 'U')            board[s_y - i][start_x] = ship_letter;
        else if(direction == 'D')       board[s_y + i][start_x] = ship_letter;
        else if(direction == 'L')       board[s_y][start_x - i] = ship_letter;
        else if(direction == 'R')       board[s_y][start_x + i] = ship_letter;
    }
}
void Board::setSubmarine(){
    char start_y = 'z';
    char ship_letter = 'S';
    int s_y;
    int start_x = -1;
    char direction = 'z';
    bool direction_invalid = true;
    int ship_size = 3;

    //choose starting spot
    while(!validStart(start_x, start_y)){
        start_x = -1;
        start_y = 'z';
        cout << "Enter a valid location of first point of your Submarine:" << endl;
        while((int)start_y > 74 || (int)start_y < 65 ){
            cout << "Enter Valid Letter Location (A-J): ";
            cin >> start_y;
            start_y = toupper(start_y);
        }
        //cin >> junk;
        while(start_x < 1 || start_x > 10){
            cout << "Enter number location with (1-10): ";
            cin >> start_x;
        }
    }
    //choose their direction
    cout << "Would you like your ship to be above, below, left of, or right of your starting point? (U/D/L/R) ";
    while(direction_invalid){
        cin >> direction;
        direction = toupper(direction);
        if(direction == 'U' && (int)start_y < (64 + ship_size))
            cout << "Your ship is placed too high to make it go up from the start point." << endl;
        else if(direction == 'D' && (int)start_y > (75 - ship_size))
            cout << "Your ship is placed too low to make it go down from the start point." << endl;
        else if(direction == 'L' && start_x < ship_size)
            cout << "Your ship is placed too far left to make it go left from the start point." << endl;
        else if(direction == 'R' && start_x > (11 - ship_size))
            cout << "Your ship is placed too far right to make it go right from the start point." << endl;
        else if(direction != 'U' && direction != 'D' && direction != 'L' && direction != 'R')
            cout << "Please enter \'U\', \'D\', \'L\', \'R\' ";
        else if(!validSpace(ship_size, direction, start_x, start_y))
            cout << "There is already a ship in that space ";
        else if(direction == 'U' || direction == 'D' || direction == 'L' || direction == 'R') direction_invalid = false;
    }

    s_y = (int)start_y - 64;
    for(int i = 0;i < ship_size; i++){
        if(direction == 'U')            board[s_y - i][start_x] = ship_letter;
        else if(direction == 'D')       board[s_y + i][start_x] = ship_letter;
        else if(direction == 'L')       board[s_y][start_x - i] = ship_letter;
        else if(direction == 'R')       board[s_y][start_x + i] = ship_letter;
    }
}
bool Board::validSpace(int ship_size, char direction, int x, int y){
    int y_loc = y - 64;
    int x_loc = x;

    for(int i = 0;i < ship_size;i++){
        if(direction == 'U'){
            if(board[y_loc-i][x_loc] != '.') return false;
        }
        else if(direction == 'D'){
            if(board[y_loc+i][x_loc] != '.') return false;
        }
        else if(direction == 'R'){
            if(board[y_loc][x_loc+i] != '.') return false;
        }
        else if(direction == 'L'){
            if(board[y_loc][x_loc-i] != '.') return false;
        }
    }
    return true;
}
bool Board::validStart(int x, int y){
    int nx = x;
    if(nx == 0) nx = 10;
    int ny = y - 64;
    if(board[ny][nx] != '.') return false;
    else return true;
}

void Board::setCPUBattleship(){
    int ship_size = 4;
    int start_x = (rand() % 10) + 1; //1-10 because Letters take up first column
    int start_y = rand() % 10;  //0-9 because all 10 rows are pegs since this board doesn't have it's own number row
    while(!validUp(start_x, start_y, ship_size) && !validDown(start_x, start_y, ship_size) &&
          !validLeft(start_x, start_y, ship_size) && !validRight(start_x, start_y, ship_size)){
        start_x = (rand() % 10) + 1;
        start_y = rand() % 10;
    }
    bool direction[4] = {validUp(start_x, start_y, ship_size),validDown(start_x, start_y, ship_size),
                         validLeft(start_x, start_y, ship_size), validRight(start_x, start_y, ship_size)};
    int dir = rand() % 4;
    while(!direction[dir]) dir = rand() % 4;
    for(int i = 0;i<ship_size;i++){
        if(dir == 0)            cpu_board[start_y-i][start_x] = 'B';
        else if(dir == 1)       cpu_board[start_y+i][start_x] = 'B';
        else if(dir == 2)       cpu_board[start_y][start_x-i] = 'B';
        else if(dir == 3)       cpu_board[start_y][start_x+i] = 'B';
    }

}
void Board::setCPUCarrier(){
    int ship_size = 5;
    int start_x = (rand() % 10) + 1; //1-10 because Letters take up first column
    int start_y = rand() % 10;  //0-9 because all 10 rows are pegs since this board doesn't have it's own number row
    while(!validUp(start_x, start_y, ship_size) && !validDown(start_x, start_y, ship_size) &&
          !validLeft(start_x, start_y, ship_size) && !validRight(start_x, start_y, ship_size)){
        start_x = (rand() % 10) + 1;
        start_y = rand() % 10;
    }
    bool direction[4] = {validUp(start_x, start_y, ship_size),validDown(start_x, start_y, ship_size),
                         validLeft(start_x, start_y, ship_size), validRight(start_x, start_y, ship_size)};
    int dir = rand() % 4;
    while(!direction[dir]) dir = rand() % 4;
    for(int i = 0;i<ship_size;i++){
        if(dir == 0)            cpu_board[start_y-i][start_x] = 'C';
        else if(dir == 1)       cpu_board[start_y+i][start_x] = 'C';
        else if(dir == 2)       cpu_board[start_y][start_x-i] = 'C';
        else if(dir == 3)       cpu_board[start_y][start_x+i] = 'C';
    }
}
void Board::setCPUDestroyer(){
    int ship_size = 3;
    int start_x = (rand() % 10) + 1; //1-10 because Letters take up first column
    int start_y = rand() % 10;  //0-9 because all 10 rows are pegs since this board doesn't have it's own number row
    while(!validUp(start_x, start_y, ship_size) && !validDown(start_x, start_y, ship_size) &&
          !validLeft(start_x, start_y, ship_size) && !validRight(start_x, start_y, ship_size)){
        start_x = (rand() % 10) + 1;
        start_y = rand() % 10;
    }
    bool direction[4] = {validUp(start_x, start_y, ship_size),validDown(start_x, start_y, ship_size),
                         validLeft(start_x, start_y, ship_size), validRight(start_x, start_y, ship_size)};
    int dir = rand() % 4;
    while(!direction[dir]) dir = rand() % 4;
    for(int i = 0;i<ship_size;i++){
        if(dir == 0)            cpu_board[start_y-i][start_x] = 'D';
        else if(dir == 1)       cpu_board[start_y+i][start_x] = 'D';
        else if(dir == 2)       cpu_board[start_y][start_x-i] = 'D';
        else if(dir == 3)       cpu_board[start_y][start_x+i] = 'D';
    }
}
void Board::setCPUPatrol(){
    int ship_size = 2;
    int start_x = (rand() % 10) + 1; //1-10 because Letters take up first column
    int start_y = rand() % 10;  //0-9 because all 10 rows are pegs since this board doesn't have it's own number row
    while(!validUp(start_x, start_y, ship_size) && !validDown(start_x, start_y, ship_size) &&
          !validLeft(start_x, start_y, ship_size) && !validRight(start_x, start_y, ship_size)){
        start_x = (rand() % 10) + 1;
        start_y = rand() % 10;
    }
    bool direction[4] = {validUp(start_x, start_y, ship_size),validDown(start_x, start_y, ship_size),
                         validLeft(start_x, start_y, ship_size), validRight(start_x, start_y, ship_size)};
    int dir = rand() % 4;
    while(!direction[dir]) dir = rand() % 4;
    for(int i = 0;i<ship_size;i++){
        if(dir == 0)            cpu_board[start_y-i][start_x] = 'P';
        else if(dir == 1)       cpu_board[start_y+i][start_x] = 'P';
        else if(dir == 2)       cpu_board[start_y][start_x-i] = 'P';
        else if(dir == 3)       cpu_board[start_y][start_x+i] = 'P';
    }
}
void Board::setCPUSubmarine(){
    int ship_size = 3;
    int start_x = (rand() % 10) + 1; //1-10 because Letters take up first column
    int start_y = rand() % 10;  //0-9 because all 10 rows are pegs since this board doesn't have it's own number row
    while(!validUp(start_x, start_y, ship_size) && !validDown(start_x, start_y, ship_size) &&
          !validLeft(start_x, start_y, ship_size) && !validRight(start_x, start_y, ship_size)){
        start_x = (rand() % 10) + 1;
        start_y = rand() % 10;
    }
    bool direction[4] = {validUp(start_x, start_y, ship_size),validDown(start_x, start_y, ship_size),
                         validLeft(start_x, start_y, ship_size), validRight(start_x, start_y, ship_size)};
    int dir = rand() % 4;
    while(!direction[dir]) dir = rand() % 4;
    for(int i = 0;i<ship_size;i++){
        if(dir == 0)            cpu_board[start_y-i][start_x] = 'S';
        else if(dir == 1)       cpu_board[start_y+i][start_x] = 'S';
        else if(dir == 2)       cpu_board[start_y][start_x-i] = 'S';
        else if(dir == 3)       cpu_board[start_y][start_x+i] = 'S';
    }
}
bool Board::validUp(int x, int y, int ship_size){
    if((y - ship_size + 1) >= 0){
        for(int i = 0;i<ship_size;i++){
            if(cpu_board[y-i][x] != '.') return false;
        }
        return true;
    }
    else return false;
}
bool Board::validDown(int x, int y, int ship_size){
    if((y + ship_size - 1) <= 9){
        for(int i = 0;i<ship_size;i++){
            if(cpu_board[y+i][x] != '.') return false;
        }
        return true;
    }
    else return false;
}
bool Board::validLeft(int x, int y, int ship_size){
    if((x - ship_size + 1) >= 1){
        for(int i = 0;i<ship_size;i++){
            if(cpu_board[y][x-i] != '.') return false;
        }
        return true;
    }
    else return false;
}
bool Board::validRight(int x, int y, int ship_size){
    if((x + ship_size - 1) <= 10){
        for(int i = 0;i<ship_size;i++){
            if(cpu_board[y][x+i] != '.') return false;
        }
        return true;
    }
    else return false;
}
void Board::setCPUShips(){
    setCPUBattleship();
    setCPUCarrier();
    setCPUDestroyer();
    setCPUPatrol();
    setCPUSubmarine();
}


void Board::decrementPHits(){
    player_hits--;
}

int Board::getPHits(){
    return player_hits;
}
//works only with player board
char Board::getBoardLoc(int x, int y){
    return board[y][x];
}

void Board::chooseHitSpot(){
    char y_loc = 'z';
    int x_li, y_li = 50;
    bool validMove = false;
    static int patrol_hits = PATROL_SIZE;
    static int destroyer_hits = DESTROYER_SIZE;
    static int submarine_hits = SUBMARINE_SIZE;
    static int battleship_hits = BATTLESHIP_SIZE;
    static int carrier_hits = CARRIER_SIZE;


    while(!validMove){
        y_loc = 'z';
        x_li = 50;
        while((int)y_loc < 65 || (int)y_loc > 74){
            cout << "Enter the letter coordinate of your shot (A-J): ";
            cin >> y_loc;
            y_loc = toupper(y_loc);
        }
        y_li = (int)y_loc - 65;
        while(x_li < 1 || x_li > 10){
            cout << "Enter the number coordinate of your shot (1-10): ";
            cin >> x_li;
            cout << "x: " << x_li << endl;
        }
        if(placeholder_board[y_li][x_li] != '.'){
            cout << "You've already attempted a shot at that location." << endl;
        }
        else validMove = true;
    }
    cout << endl;
    QProcess::execute("clear");

    if(cpu_board[y_li][x_li] == '.') placeholder_board[y_li][x_li] = 'M';
    else{
        cout << "You've hit an enemy ship!" << endl;
        if(cpu_board[y_li][x_li] == 'P'){
            //cout << "You've hit the enemy Patrol Boat!" << endl;
            patrol_hits--;
            if(patrol_hits == 0) cout << "You've sunk the enemy Patrol Boat!" << endl;
        }
        else if(cpu_board[y_li][x_li] == 'B'){
            //cout << "You've hit the enemy Battleship!" << endl;
            battleship_hits--;
            if(battleship_hits == 0) cout << "You've sunk the enemy Battleship!" << endl;
        }
        else if(cpu_board[y_li][x_li] == 'D'){
            //cout << "You've hit the enemy Destroyer!" << endl;
            destroyer_hits--;
            if(destroyer_hits == 0) cout << "You've sunk the enemy Destroyer!" << endl;
        }
        else if(cpu_board[y_li][x_li] == 'S'){
            //cout << "You've hit the enemy Submarine!" << endl;
            submarine_hits--;
            if(submarine_hits == 0) cout << "You've sunk the enemy Submarine!" << endl;
        }
        else if(cpu_board[y_li][x_li] == 'C'){
            //cout << "You've hit the enemy Carrier Ship!" << endl;
            carrier_hits--;
            if(carrier_hits == 0) cout << "You've sunk the enemy Carrier Ship!" << endl;
        }
        placeholder_board[y_li][x_li] = 'H';
        decrementPHits();
        cout << endl;
    }
}
//works only with player board
void Board::updateBoard(int x, int y, char c){
    board[y][x] = c;
}
