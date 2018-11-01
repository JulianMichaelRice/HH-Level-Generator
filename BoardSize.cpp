#include "BoardSize.h"
#include "Random.h"

void BoardSize::generate(bool hard) {
    int product = 0;
    while (true) {
        if (hard) {
            m_row = randomInteger(4, 5);
            m_col = randomInteger(4, 5);
        }
        else {
            m_row = randomInteger(2, 5);
            m_col = randomInteger(2, 5);
        }
        product = m_row * m_col;
        if (product % 2 == 0 && product > 7)
            break;
    }
}

void BoardSize::clear() {
    m_row = 0;
    m_col = 0;
}
