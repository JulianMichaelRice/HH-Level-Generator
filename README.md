# HH-Level-Generator
Level generator for Harvey's Hundreds (iOS)
[ Julian Rice 2018 | October 2018 ]

### Summary
[Harvey's Hundreds (iOS)](https://itunes.apple.com/us/app/harveys-hundreds/id1352632321?mt=8&ign-mpt=uo%3D2) is a fun iOS application places the player in Steve's gameshow, Harvey's Hundreds. The player needs to match tiles while fulfilling time and/or move limits, which makes for frantic mayhem!

I have worked on the game's levels for a number of weeks now, and decided that making a level generator would be (1) a good way to practice my programming skills and (2) a nice idea for more efficiently creating difficult (but fair) levels and something that might become useful as the number of levels skyrockets in the near future. As of the end of October 2018, there are around 224 levels completed, but minor changes to this generator could increase the output of good levels being created by A LOT! If you have any questions or requests, shoot me an email at rice.m.julian@gmail.com.

---
### Contents
##### main.cpp
This file asks for the number of levels (x) to generate and the starting level (y). It will then run a loop and generate x levels starting from level y. This will all be saved to a to-be generated file *hh-levels.json*. 

##### BoardSize.h & BoardSize.cpp
This is the BoardSize class, which consists of the number of rows and the number of columns for a board. These values can range from 2 to 5, but the product (or total number of tiles) needs to be 6 or greater *and* even. The generate() function will repeatedly generate new combinations of rows and columns until the previous two conditions are satisfied.
```
void generate(): Generate random row / column values
void clear(): Clear all row / column values
int getRow() { return m_row; } - Return row count
int getCol() { return m_col; } - Return column count
```

##### Level.h & Level.cpp
This is the Level class, which consists of the main function, create(), that generates values for each level. The Level class contains all of the specific elements of a level as private variables (level, type, tile count, etc.), and has four functions.
```int create(int level): This creates a new level
void blank(): This cleans up all private members
void printDetails(): This outputs a level
void pushDetails(ofstream& file): This outputs what is found in printDetails() into a json file.
```
##### Set.h & Set.cpp
This is the Set class, which consists of a vector that contains the total number of levels (x) requested to be generated. It contains two functions.
```
void addLevel(Level level): Add level to vector
void printSet(ofstream &file): Print & push all levels
```

##### Random.h & Random.cpp
This is just a file (with a short header) that contains a random number generator function. There is not much more to say about this!
