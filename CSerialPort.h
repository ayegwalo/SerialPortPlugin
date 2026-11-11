#ifndef CSERIALPORT_H
#define CSERIALPORT_H

#include "CSerialPortInterface.h"

#include <deque>

class CSerialPort : public CSerialPortInterface
{
public:
    CSerialPort();
    ~CSerialPort() override;

    int Open(const CMyString* pStrPort, int baudrate) override;

    int Write(char* data, size_t len) override;

    int Read(char* data, size_t max_len) override;

    void Close() override;

private:
    bool m_isOpen;

    // Stores data for the simulated loopback.
    std::deque<char> m_buffer;
};

#endif