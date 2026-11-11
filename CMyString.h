#ifndef CMYSTRING_H
#define CMYSTRING_H

#include <string>

class CMyString
{
public:
    CMyString(const std::string& value)
        : m_value(value)
    {
    }

    // Returns the stored string.
    const std::string& GetString() const
    {
        return m_value;
    }

private:
    std::string m_value;
};

#endif