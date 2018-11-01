#ifndef Set_hpp
#define Set_hpp

#include <iostream>
#include <vector>
#include "Level.h"

using namespace std;

class Set {
public:
    void addLevel(Level level);
    void printSet(ofstream& file);
private:
    vector<Level> m_levels;
};

#endif
