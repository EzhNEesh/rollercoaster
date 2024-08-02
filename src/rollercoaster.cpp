#include <iostream>
#include <string>

#include "rollercoaster.h"

RollerCoaster::RollerCoaster(const std::vector<float> &_nums) {
    nums = _nums;
}

std::vector<std::pair<unsigned int, unsigned int>> RollerCoaster::findRollerCoasters(
    const unsigned int &minRange,
    const unsigned int &maxRange,
    const int &noizeFloor)
{
    if (minRange > nums.size()) {
        throw std::logic_error("Minimal range("
                               + std::to_string(minRange)
                               + ") cannot be greater than nums size("
                               + std::to_string(nums.size()) + ')');
    }

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
