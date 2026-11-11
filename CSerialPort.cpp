#include "CSerialPort.h"

#include "CMyString.h"
#include <iostream>
#include <algorithm>

// Start with the serial port closed.
CSerialPort::CSerialPort()
    : m_isOpen(false)
{
}

// Close the port automatically when the object is destroyed.
CSerialPort::~CSerialPort()
{
    Close();
}

// Open the simulated serial port.
int CSerialPort::Open(const CMyString* pStrPort, int baudrate)
{
    if (pStrPort == nullptr || baudrate <= 0)
        return -1;

    if (m_isOpen)
        return -1;

    std::cout << "Opening serial port: "
              << pStrPort->GetString()
              << " at " << baudrate << " baud."
              << std::endl;

    m_isOpen = true;
    m_buffer.clear();

    return 0;
}

// Store written data in the loopback buffer.
int CSerialPort::Write(char* data, size_t len)
{
    if (!m_isOpen)
        return -1;

    if (data == nullptr && len > 0)
        return -1;

    for (size_t i = 0; i < len; ++i)
    {
        m_buffer.push_back(data[i]);
    }

    return static_cast<int>(len);
}

// Read previously written data.
int CSerialPort::Read(char* data, size_t max_len)
{
    if (!m_isOpen)
        return -1;

    if (data == nullptr && max_len > 0)
        return -1;

    size_t bytesToRead = std::min(max_len, m_buffer.size());

    for (size_t i = 0; i < bytesToRead; ++i)
    {
        data[i] = m_buffer.front();
        m_buffer.pop_front();
    }

    return static_cast<int>(bytesToRead);
}

// Close the simulated serial port.
void CSerialPort::Close()
{
    if (m_isOpen)
    {
        std::cout << "Closing serial port." << std::endl;

        m_isOpen = false;
        m_buffer.clear();
    }
}