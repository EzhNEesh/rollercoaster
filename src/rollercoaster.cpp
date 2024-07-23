#include "rollercoaster.h"

RollerCoaster::RollerCoaster(const std::vector<float> &_nums) {
    this->nums = _nums;
}

std::vector<std::pair<unsigned int, unsigned int>> RollerCoaster::findRollerCoasters(
    const unsigned int &minRange,
    const unsigned int &maxRange,
    const int &noizeFloor)
{
    std::vector<std::pair<unsigned int, unsigned int>> results;

    unsigned int curPos = 0;
    unsigned int curWidth = 0;
    while (curPos < nums.size() - minRange) {
        if (nums[curPos] > noizeFloor) {
            curWidth++;
        } else if (curWidth != 0) {
            if (curWidth >= minRange && curWidth <= maxRange) {
                results.push_back(std::pair<unsigned int, unsigned int> (curPos - curWidth, curPos - 1));
            }
            curWidth = 0;
        }
        curPos++;
    }
    if (curWidth != 0) {
        if (curWidth >= minRange && curWidth <= maxRange) {
            results.push_back(std::pair<unsigned int, unsigned int> (curPos - curWidth, curPos - 1));
        }
    }

    return results;
}
