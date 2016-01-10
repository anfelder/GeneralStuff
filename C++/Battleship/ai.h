#ifndef AI_H
#define AI_H
#include "board.h"
class AI
{
public:
    AI();

    void runAI(Board &board);



    int generateRandCoord();
    void runHitRoutine();
    void generateHitMessage(int x, int y, Board &board);
    void decrementCPUHits();
    int getCPUHits();

private:
    int cpu_hits;
    enum {EASY = 1, MEDIUM, HARD};
    int difficulty;

    void runEasy(Board &board);
    void runMedium(Board &board);
    void runHard(Board &board);
};

#endif // AI_H
