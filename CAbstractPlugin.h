#ifndef CABSTRACTPLUGIN_H
#define CABSTRACTPLUGIN_H

// Base class for all plugins.
class CAbstractPlugin
{
public:

    // Virtual destructor allows safe deletion through a base pointer.
    virtual ~CAbstractPlugin() = default;
};

#endif // CABSTRACTPLUGIN_H