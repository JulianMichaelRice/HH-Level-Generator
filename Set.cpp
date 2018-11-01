#include "Set.h"

void Set::addLevel(Level level) {
    m_levels.push_back(level);
}

void Set::printSet(ofstream& file) {
    for (int i = 0; i < m_levels.size(); i++) {
        m_levels[i].printDetails();
        m_levels[i].pushDetails(file);
    }
}
