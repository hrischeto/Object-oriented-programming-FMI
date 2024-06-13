#include <iostream>
#include <fstream>

struct User
{
    char name[25]{};
};

struct Message
{
    User from;
    char* text;
};


void printChat(const char* filePath)
{
    std::ifstream discussion(filePath, std::ios::binary);
    if (!discussion.is_open())
    {
        std::cout << "Error while reading." << std::endl;
        return;
    }

    Message mes;
    char* textSize[sizeof(size_t)];
    
    while (true)
    {
        discussion.read(mes.from.name, 25);

        if (!discussion.eof())
            break;

        discussion.read(text)

    }
}
