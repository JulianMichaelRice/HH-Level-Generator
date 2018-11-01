#ifndef BoardSize_hpp
#define BoardSize_hpp

#include <iostream>

using namespace std;

class BoardSize {
public:
    void generate(bool hard);
    void clear();
    int getRow() { return m_row; }
    int getCol() { return m_col; }
private:
    int m_row;
    int m_col;
};

#endif
