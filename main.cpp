#include "BoardSize.h"
#include "Level.h"
#include "Set.h"
#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    int levelCount, currentLevel;
    Set s1;
    ofstream outputFile;
    outputFile.open("hh-levels.json", fstream::out);
    
    cout << "[Input] Number of levels to generate: ";
    cin >> levelCount;
    cout << "[Input] Start from what level? ";
    cin >> currentLevel;
    Level levels[levelCount];
    for (int i = 0; i < levelCount; i++) {
        levels[i].blank();
        levels[i].create(currentLevel+i);
        s1.addLevel(levels[i]);
    }
    s1.printSet(outputFile);
    outputFile.close();
    return 0;
}
