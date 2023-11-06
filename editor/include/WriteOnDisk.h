#pragma once

#include <utility>
#include <string>
#include <fstream>

class WriteOnDisk {
private:
    std::string m_FileName;
    std::string m_Message;
public:
    WriteOnDisk(std::string  fileName, std::string  message);
    void write();
    ~WriteOnDisk() = default;
    WriteOnDisk(const WriteOnDisk&) = delete;
    WriteOnDisk(WriteOnDisk&& other) = delete;
};