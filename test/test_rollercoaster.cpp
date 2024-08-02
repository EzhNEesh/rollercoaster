#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <vector>
#include <fstream>
#include <iostream>

#include "../src/binaryreader.h"
#include "../src/binaryreader.cpp"
#include "../src/normaldistribution.h"
#include "../src/normaldistribution.cpp"
#include "../src/rollercoaster.h"
#include "../src/rollercoaster.cpp"

// struct RollerCoasterTest : testing::Test {

// };

TEST(RollerCoasterTest, FindRollerCoasters) {
    std::ifstream file("../test_findrollercoasters_data.txt");
    std::vector<std::pair<unsigned int, unsigned int>> resultsExc;
    std::string line;
    while (std::getline(file, line)) {
        unsigned int spacePos = line.find(' ');
        unsigned int leftBorder = std::stoi(line.substr(0, spacePos));
        unsigned int rightBorder = std::stoi(line.substr(spacePos));
        resultsExc.push_back(std::pair<unsigned int, unsigned int> (leftBorder, rightBorder));
    }
    const unsigned int minRange = 3;
    const unsigned int maxRange = 1000;
    const std::string filePath = "../detector_src_32f.bin";
    const size_t rollerCoastersCount = 6867;

    BinaryReader binReader;
    std::vector<float> nums = binReader.getNumsFromBinary(filePath);
    NormalDistribution nDistribution{nums};
    int noizeFloor = nDistribution.getBorders().second;
    RollerCoaster rollerCoaster{nums};
    std::vector<std::pair<unsigned int, unsigned int>> results = rollerCoaster.findRollerCoasters(minRange, maxRange, noizeFloor);

    ASSERT_EQ(results.size(), rollerCoastersCount);
    ASSERT_EQ(results, resultsExc);
}
