
#include <iostream>
#include <cstring>
#include <string>

#include "CMyString.h"
#include "CSerialPort.h"

void TestResult(const std::string& testName, bool passed)
{
    std::cout << (passed ? "[PASS] " : "[FAIL] ")
    << testName << std::endl;
}

int main()
{
    CSerialPort serialPort;
    CSerialPortInterface* port = &serialPort;

    CMyString portName("COM1");

    std::cout << "\n===== SERIAL PORT PLUGIN TESTS =====\n"
              << std::endl;

    // TEST 1: Write while port is closed
    char testData[] = "Test";
    TestResult("Write while closed",
               port->Write(testData, 4) == -1);

    // TEST 2: Read while port is closed
    char buffer[100] = {};
    TestResult("Read while closed",
               port->Read(buffer, sizeof(buffer)) == -1);

    // TEST 3: Open the port
    TestResult("Open serial port",
               port->Open(&portName, 9600) == 0);

    // TEST 4: Write data
    char message[] = "Hello Serial Port!";
    int bytesWritten = port->Write(
        message, strlen(message));

    TestResult("Write data",
               bytesWritten == 18);

    // TEST 5: Read first 5 bytes
    char firstPart[6] = {};
    int firstRead = port->Read(firstPart, 5);

    TestResult("Partial read (5 bytes)",
               firstRead == 5 &&
                   std::string(firstPart, firstRead) == "Hello");

    // TEST 6: Read remaining bytes
    char secondPart[100] = {};
    int secondRead = port->Read(
        secondPart, sizeof(secondPart));

    TestResult("Read remaining data",
               secondRead == 13 &&
                   std::string(secondPart, secondRead)
                       == " Serial Port!");

    // TEST 7: Read from empty buffer
    int emptyRead = port->Read(buffer, sizeof(buffer));

    TestResult("Read from empty buffer",
               emptyRead == 0);

    // TEST 8: Close the port
    port->Close();

    TestResult("Close serial port", true);

    // TEST 9: Write after closing
    TestResult("Write after closing",
               port->Write(testData, 4) == -1);

    // TEST 10: Read after closing
    TestResult("Read after closing",
               port->Read(buffer, sizeof(buffer)) == -1);

    std::cout << "\n===== TESTS COMPLETED ====="
              << std::endl;

    return 0;
}
