#include <iostream>
#include <fstream>
#pragma warning (disable:4996)

struct User
{
    char name[25]{};
};

 struct Message
{
    User from;
    char* text;

    ~Message()
    {
        delete[] text;
    }
};

 void initMes(Message& m,const char* from, const char*  text)
 {
     std::strcpy(m.from.name, from);
     m.text = new char[std::strlen(text)+1];
     std::strcpy(m.text, text);
 }

 void serializeMessage(const Message& m,std::ofstream& ofs)
 {
     ofs.write((const char*)&m.from, sizeof(User));
     size_t len = std::strlen(m.text);
     ofs.write((const char*)&len, sizeof(len));
     ofs.write(m.text, len);
 }

 void serializeChat(const Message* arr, size_t size, const char* filePath)
 {
     std::ofstream ofs(filePath, std::ios::out | std::ios::binary);

     if (!ofs.is_open())
         return;
     ofs.write((const char*)&size, sizeof(size));
     for (int i = 0;i < size;i++)
         serializeMessage(arr[i],ofs);
 }

 void deserialiseMessage(Message& m, std::ifstream& ifs)
 {
     ifs.read((char*)&m.from, sizeof(m.from));
     size_t len = 0;
     ifs.read((char*)&len, sizeof(len));
     m.text = new char[len];
     ifs.read(m.text, len);
     m.text[len] = '\0';
 }

 void deserializeChat(Message*& chat, size_t& size, std::ifstream& ifs)
 {
     ifs.read((char*)&size, sizeof(size));

     chat = new Message[size];

     for (int i = 0;i < size;i++)
     {
         deserialiseMessage(chat[i], ifs);
     }
 }

 void printMessage(const Message& m, int ind)
 {
     if (ind % 2) {
         std::cout << "\t\t\t\t\t\t\t\t\t\t" << m.from.name << std::endl;
         std::cout<< "\t\t\t\t\t\t\t\t\t\t" << m.text << std::endl;
     }

     else
     {
         std::cout <<m.from.name << std::endl;
         std::cout << m.text << std::endl;
     }
 }

 void printChat(const Message* chat, size_t size)
 {
     for (int i = 0;i < size;i++)
         printMessage(chat[i], i);
 }

 void fillFile()
 {
     Message* chat = new Message[4];
     size_t size = 4;

     initMes(chat[0], "Hrisi", "Are you going to eat?");
     initMes(chat[1], "Ivana", "Yes, musaka. Do you want some?");
     initMes(chat[2], "Hrisi", "Yes, I have salata");
     initMes(chat[3], "Ivana", "Great! Im coming in 10!");

     printChat(chat, size);
     serializeChat(chat, size, "chat.dat");
 }

