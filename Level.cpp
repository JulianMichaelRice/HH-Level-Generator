#include "Level.h"
#include "Random.h"

void Level::blank() {
    m_level = 0;
    m_type = "";
    m_tiles = 0;
    m_board.clear();
    m_maxTurns = 0;
    m_winCond = 0;
    m_initTime = 0;
    m_iconPack = "";
}

int Level::create(int level) {
    //Set the level appropriately
    m_level = level;
    bool hardLevel = (level % 10) == 0;
    
    //Set type and boardsize
    int area;
    while (true) {
        int randomVariable = randomInteger(1, 4);
        if (randomVariable > 1) {
            m_type = "random";
            while (true) {
                if (hardLevel)
                    m_tiles = randomInteger(16, 24);
                else
                    m_tiles = randomInteger(6, 24);
                if (m_tiles % 2 == 0)
                    break;
            }
        }
        else
            m_type = "static";
        m_board.generate(hardLevel);
        area = m_board.getCol() * m_board.getRow();
        if (area >= m_tiles)
            break;
        m_board.clear();
        //cout << "area: " << area << endl;
        //cout << "tiles: " << m_tiles << endl;
    }
    
    //Set max turns
    int maxActivated = randomInteger(1, 12);
    if (maxActivated >= 1 && maxActivated <= 3) {
        m_maxTurns = 0;
    }
    else {
        m_maxTurns = m_tiles + (randomInteger(1, m_tiles/2) / 2);
    }
    //Set win condition
    if (m_type == "random")
        m_winCond = m_tiles / 2;
    else
        m_winCond = area / 2;
    
    //Set initial time
    int timeActivated = randomInteger(1, 6);
    if (timeActivated >= 1 && timeActivated <= 2) {
        if (m_maxTurns != 0) {
            if (m_type == "random")
                m_initTime = randomInteger(m_tiles, m_tiles*2);
            else
                m_initTime = randomInteger(area, area*2);
        }
        else {
            if (m_type == "random") {
                m_initTime = m_tiles + randomInteger(0, m_tiles/2) + randomInteger(0, m_tiles/3);
                if (m_tiles <= 14) {
                    m_initTime -= randomInteger(0, 3);
                }
            }
            else {
                m_initTime = area + randomInteger(0, area/2);
                if (area <= 14) {
                    m_initTime -= randomInteger(0, 3);
                }
            }
        }
    }
    else if (timeActivated >= 3 && timeActivated <= 6) {
        if (m_type == "random") {
            m_initTime = m_tiles + randomInteger(0, m_tiles/2) + randomInteger(0, m_tiles/3);
            if (m_tiles <= 14) {
                m_initTime -= randomInteger(0, 3);
            }
        }
        else {
            m_initTime = area + randomInteger(0, area/2);
            if (area <= 14) {
                m_initTime -= randomInteger(0, 3);
            }
        }
    }
    
    //Set icon pack
    string icons[5] = {"birds", "planets", "cars", "butterflies", "balloons"};
    if (m_level % 10 == 0) {
        int iconChoice = randomInteger(0, 4);
        m_iconPack = icons[iconChoice];
    }
    return 0;
}

void Level::printDetails() {
    cout << "{" << endl;
    cout << "   \"level\": " << m_level << "," <<  endl;
    cout << "   \"type\": \"" << m_type << "\"," << endl;
    if (m_type == "random")
        cout << "   \"tiles\": " << m_tiles << "," << endl;
    cout << "   \"boardSize\": {" << endl;
    cout << "       \"row\": " << m_board.getRow() << "," << endl;
    cout << "       \"column\": " << m_board.getCol() << endl;
    cout << "   }," << endl;
    if (m_maxTurns == 0)
        cout << "   \"maxTurns\": null," << endl;
    else
        cout << "   \"maxTurns\": " << m_maxTurns << "," << endl;
    cout << "   \"winCondition\": " << m_winCond << "," << endl;
    if (m_initTime == 0)
        cout << "   \"initialTime\": null";
    else
        cout << "   \"initialTime\": " << m_initTime;
    if (m_level % 10 == 0) {
        cout << "," << endl;
        cout << "   \"iconPack\": \"" << m_iconPack << "\"" << endl;
    }
    else
        cout << endl;
    cout << "}," << endl;
}

void Level::pushDetails(ofstream& file) {
    file << "{\n";
    file << "   \"level\": " << m_level << ",\n";
    file << "   \"type\": \"" << m_type << "\",\n";
    if (m_type == "random")
        file << "   \"tiles\": " << m_tiles << ",\n";
    file << "   \"boardSize\": {" << endl;
    file << "       \"row\": " << m_board.getRow() << ",\n";
    file << "       \"column\": " << m_board.getCol() << "\n";
    file << "   }," << endl;
    if (m_maxTurns == 0)
        file << "   \"maxTurns\": null,\n";
    else
        file << "   \"maxTurns\": " << m_maxTurns << ",\n";
    file << "   \"winCondition\": " << m_winCond << ",\n";
    if (m_initTime == 0)
        file << "   \"initialTime\": null";
    else
        file << "   \"initialTime\": " << m_initTime;
    if (m_level % 10 == 0) {
        file << ",\n";
        file << "   \"iconPack\": \"" << m_iconPack << "\"\n";
    }
    else
        file << "\n";
    file << "},\n";
}
