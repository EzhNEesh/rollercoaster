#include <iostream>
#include <fstream>

#include "binaryreader.h"

BinaryReader::BinaryReader() {}

std::vector<float> BinaryReader::readBinary(const std::string &filepath) {
    std::ifstream file(filepath, std::ios::binary);
    std::vector<float> nums;
    if (file.is_open()) {
        float num;
        while (file.read((char*)&num, sizeof(float))){
            nums.push_back(num);
        }
    }
    return nums;
}
