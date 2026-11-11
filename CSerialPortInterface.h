#ifndef CSERIALPORTINTERFACE_H
#define CSERIALPORTINTERFACE_H

#include "CAbstractPlugin.h"
#include <cstddef>

// Forward declaration of CMyString.
// This tells the compiler that CMyString is a class.
class CMyString;

// Interface for serial port plugins.
class CSerialPortInterface : public CAbstractPlugin
{
public:

    virtual ~CSerialPortInterface() = default;

    // Opens the serial port.
    virtual int Open(const CMyString* pStrPort, int baudrate) = 0;

    // Writes data to the serial port.
    virtual int Write(char* data, size_t len) = 0;

    // Reads data from the serial port.
    virtual int Read(char* data, size_t max_len) = 0;

    // Closes the serial port.
    virtual void Close() = 0;
};

#endif // CSERIALPORTINTERFACE_H