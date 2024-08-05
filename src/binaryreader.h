#ifndef BINARYREADER_H
#define BINARYREADER_H

#include <vector>

class BinaryReader
{
public:
    BinaryReader();
    static std::vector<float> getNumsFromBinary(const std::string &filePath);
};

#endif // BINARYREADER_H
