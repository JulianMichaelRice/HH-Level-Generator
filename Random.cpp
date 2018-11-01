#include "Random.h"

int randomInteger(int min, int max) {
    //This function computes a random integer between min and max
    if (max < min)
        swap(max, min);
    static random_device rd;
    static mt19937 generator(rd());
    uniform_int_distribution<> distro(min, max);
    return distro(generator);
}
