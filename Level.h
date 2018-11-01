#ifndef Level_h
#define Level_h

#include <string>
#include <fstream>
#include "BoardSize.h"

using namespace std;

class Level {
public:
    int create(int level);
    void blank();
    void printDetails();
    void pushDetails(ofstream& file);
private:
    int m_level;
    string m_type;
    int m_tiles;
    BoardSize m_board;
    int m_maxTurns;
    int m_winCond;
    int m_initTime;
    string m_iconPack;
};

#endif
