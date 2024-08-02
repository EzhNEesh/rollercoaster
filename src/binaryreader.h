#ifndef BINARYREADER_H
#define BINARYREADER_H

#include <vector>

class BinaryReader
{
public:
    BinaryReader();
    std::vector<float> getNumsFromBinary(const std::string &);
};

#endif // BINARYREADER_H
