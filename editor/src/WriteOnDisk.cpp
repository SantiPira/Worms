
#include "../include/WriteOnDisk.h"

WriteOnDisk::WriteOnDisk(std::string fileName, std::string message) : m_FileName(std::move(fileName)),
                                                                                   m_Message(std::move(message)) {}

void WriteOnDisk::write() {
    std::ofstream file;
    file.open(m_FileName, std::ios::app);
    file << m_Message;
    file.close();
}
