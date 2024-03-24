#include <iostream>
#include <fstream>
#pragma warning( disable : 4996)

namespace GlobalConstants
{
    constexpr size_t SONGNAME_MAX_SIZE = 64;
    constexpr size_t CONTENT_MAX_SIZE = 256;
    constexpr size_t MAX_COUNT_OF_SONGS = 30;
    constexpr unsigned SECONDS_IN_HOURS = 3600;
    constexpr unsigned SECONDS_IN_MINUTE = 60;
    constexpr size_t ARR_MAX_SIZE = 1024;
    constexpr size_t MAX_DIGITS_IN_INT = 10;
}

enum ErrorCodes {
    OK,
    NullPtrGiven = -1,
    OpeningError = -2,
    Other=-3,
};

enum class SimpleGenres {
    r,//rock
    p,//pop
    e,//electronic
    f,//folklore
    j,//jazz
    t,//techno
    h,//house
    c//classical
};

int min(int a, int b)
{
    if (a <= b)
        return a;
    else
        return b;
}

class Song
{
private:
    int8_t Genre = 0;
    int DurationInSec = 0;
    char Name[GlobalConstants::SONGNAME_MAX_SIZE]="Unidentified";
    char Content[GlobalConstants::CONTENT_MAX_SIZE] = "\0";

    ErrorCodes createGenreString(char*& dest, const char* source) const
    {
        if (!dest || !source)
            return ErrorCodes::NullPtrGiven;

        std::strcpy(dest, source);
        dest += std::strlen(source);
    }

    bool isValidGenre(const char* source) const 
    {
        if (!source)
            return 0;

        char availableGenres[9] = "rpefjthc";

        while (*source)
        {
           
        }

        return 1;
    }

public:
    Song()
    {
        setName("Unidentified");
        this->Content[0] = '\0';
        this->Genre = 0;
        this->DurationInSec = 0;
    }

    Song(const char* name, int hours, int minutes, int seconds, const char* genre, const char* filePath)
    {
        if (!name || !genre || !filePath)
            return;

        setName(name);
        setDuration(hours, minutes, seconds);
        setGenre(genre);
        setContent(filePath);  
    }

    ErrorCodes setName(const char* name)
    {
        if (!name)
            return ErrorCodes::NullPtrGiven;

        if (std::strlen(name) > 64)
        {
            std::cout << "Invalid string. Enter a valid command." << std::endl;
            return ErrorCodes::Other;
        }

        std::strcpy(this->Name, name);
        return ErrorCodes::OK;
    }

    ErrorCodes setGenre(const char* genre)
    {
        if (!genre)
            return ErrorCodes::NullPtrGiven;

        if (isValidGenre(genre))
        {
            this->Genre = 0;

            while (*genre)
            {
                SimpleGenres simpleGenre = (SimpleGenres)*genre;
                this->Genre += 1 << (int)simpleGenre;
                genre++;
            }

            return ErrorCodes::OK;
        }
        else
        {
            return ErrorCodes::Other;
        }
        
    }
        
    void setDuration(int hours, int minutes, int seconds)
    {
        this->DurationInSec = (GlobalConstants::SECONDS_IN_HOURS)*hours
                              + (GlobalConstants::SECONDS_IN_MINUTE)*minutes + seconds;
    }

    ErrorCodes setContent(const char* filePath)
    {
        std::ifstream songFile(filePath, std::ios::binary);
        if (!songFile.is_open())
            return ErrorCodes::OpeningError;

        songFile.read(this->Content, GlobalConstants::CONTENT_MAX_SIZE);

        return ErrorCodes::OK;
    }

    ErrorCodes setContentWithArr(const char* newContent)
    {
        if (!newContent)
            return ErrorCodes::NullPtrGiven;

        std::strcpy(this->Content, newContent);
        return ErrorCodes::OK;
    }

    const char* getName() const
    {
        return Name;
    }

    void getDuration(int& hours, int& minutes, int& seconds) const
    {
        hours = DurationInSec / GlobalConstants::SECONDS_IN_HOURS;
        minutes = (DurationInSec % GlobalConstants::SECONDS_IN_HOURS )/ GlobalConstants::SECONDS_IN_MINUTE;
        seconds = (DurationInSec % GlobalConstants::SECONDS_IN_HOURS) % GlobalConstants::SECONDS_IN_MINUTE;
    }

    int getDurationInSec()
    {
        return DurationInSec;
    }

    const char* getGenre() const
    {
        char songGenre[GlobalConstants::ARR_MAX_SIZE];
        char* songGenrePtr = songGenre;

        for (int i = 0; i <= (int)SimpleGenres::c; i++)
        {
            int mask = 1<<i;
            mask = mask & Genre;

            if (mask)
            {
                switch (i)
                {
                case (int)SimpleGenres::r:
                    createGenreString(songGenrePtr, "Rock&");
                        break;
                case (int)SimpleGenres::p:
                    createGenreString(songGenrePtr, "Pop&");
                    break;
                case (int)SimpleGenres::e:
                    createGenreString(songGenrePtr, "Electronic&");
                    break;
                case (int)SimpleGenres::f:
                    createGenreString(songGenrePtr, "Folkore&");
                    break;
                case (int)SimpleGenres::j:
                    createGenreString(songGenrePtr, "Jazz&");
                    break;
                case (int)SimpleGenres::t:
                    createGenreString(songGenrePtr, "Techno&");
                    break;
                case (int)SimpleGenres::h:
                    createGenreString(songGenrePtr, "House&");
                    break;
                case (int)SimpleGenres::c:
                    createGenreString(songGenrePtr, "Classical&");
                    break;
                }
            }
        } 

        songGenrePtr--;
        *songGenrePtr = '\0';

        return songGenre;
    }

    int8_t getGenreAsInt() const
    {
        return Genre;
    }

    char* getContent()
    {
        return Content;
    }
};


 class Playlist {
 private:

     Song playlist[GlobalConstants::MAX_COUNT_OF_SONGS];
     int currentSongsCount = 0;
     
     void printName(int i) const
     {
         char songName[GlobalConstants::SONGNAME_MAX_SIZE];
         std::strcpy(songName, playlist[i].getName());
         std::cout << songName << " ";
     }

     void printDuration(int i) const
     {
         int hours = 0;
         int minutes = 0;
         int seconds = 0;

         playlist[i].getDuration(hours, minutes, seconds);

         std::cout << hours << ':' << minutes << ':' << seconds << " ";
     }

     void printGenre(int i) const
     {
         char songGenre[GlobalConstants::ARR_MAX_SIZE];
         std::strcpy(songGenre, playlist[i].getGenre());
         std::cout << songGenre << std::endl;
     }

     void printSong(int i) const
     {
         printName(i);
         printDuration(i);
         printGenre(i);
     }
 public:

     Playlist()
     {
        this-> currentSongsCount = 0;
     }

     Playlist(Song* songs, int songsCount)
     {
         if (!songs)
             return;

         if (songsCount > GlobalConstants::MAX_COUNT_OF_SONGS)
             return;

         for (int i = 0;i < songsCount;i++)
         {
             this->playlist[i] = songs[i];
         }

         this->currentSongsCount = songsCount;
        
     }

     ErrorCodes add(const char* newName, int hours, int minutes, int seconds, const char* genre, const char* filePath)
     {
         if (!newName || !genre || !filePath)
             return ErrorCodes::NullPtrGiven;

         if (currentSongsCount == GlobalConstants::MAX_COUNT_OF_SONGS)
         {
             std::cout << "You cannot add anymore songs." << std::endl;
             return ErrorCodes::Other;
         }

         Song newSong(newName, hours, minutes, seconds, genre, filePath);

         playlist[currentSongsCount] = newSong;
         currentSongsCount++;

         return ErrorCodes::OK;
     }

     void printPlaylist() const
     {
         for (int i = 0; i < currentSongsCount;i++)
         {
             printSong(i);
         }
     }

    const Song& findSongByName(const char* Name) const
     {
         if (!Name)
             return Song();

         for (int i = 0;currentSongsCount;i++)
         {
             char currentSongName[GlobalConstants::SONGNAME_MAX_SIZE];
             std::strcpy(currentSongName, playlist[i].getName());

             if (!std::strcmp(currentSongName, Name))
             {
                 return playlist[i];
                 break;
             }
         }

         return Song();
     }

     Playlist findSongsByGenres(char genre) const
     {
         Playlist sameGenre = Playlist();

         for (int i = 0;i < currentSongsCount;i++)
         {
             int8_t songGenre = playlist[i].getGenreAsInt();
             int8_t mask = 1 << (int)(SimpleGenres)genre;
             mask = mask & songGenre;

             if (mask)
             {
                 sameGenre.playlist[i] = playlist[i];
                 sameGenre.currentSongsCount = i+1;
             }
         }
     
         return sameGenre;
     }

     void sortByDuration()
     {
         for (int i = 0; i < currentSongsCount - 1; i++)
         {
             int minElementIndex = i;
             for (int j = i + 1; j < currentSongsCount; j++)
             {
                 if (playlist[j].getDurationInSec() < playlist[minElementIndex].getDurationInSec())
                     minElementIndex = j;
             }
             if (minElementIndex != i)
                 std::swap(playlist[i], playlist[minElementIndex]);
         }

         printPlaylist();
     }

     void sortByName()
     {
         for (int i = 0; i < currentSongsCount - 1; i++)
         {
             int minElementIndex = i;
             for (int j = i + 1; j < currentSongsCount; j++)
             {
                 if (std::strcmp(playlist[j].getName(), playlist[minElementIndex].getName())<0)
                     minElementIndex = j;
             }
             if (minElementIndex != i)
                 std::swap(playlist[i], playlist[minElementIndex]);
         }

         printPlaylist();
     }

     void mixSongs(const char* outcomeSong, const char* name2)
     {
         Song song1 = findSongByName(outcomeSong);
         Song song2 = findSongByName(name2);

         char content1[GlobalConstants::CONTENT_MAX_SIZE];
         std::strcpy(content1, song1.getContent());

         char content2[GlobalConstants::CONTENT_MAX_SIZE];
         std::strcpy(content2, song2.getContent());

         unsigned sizeOfShorterSong = 0;
         unsigned sizeOfSong1 = std::strlen(content1);
         unsigned sizeOfSong2 = std::strlen(content2);
         
         sizeOfShorterSong = min(sizeOfSong1, sizeOfSong2);

         for (int i = 0;i < sizeOfShorterSong;i++)
         {
             content1[i] ^= content2[i];
         }

         song1.setContentWithArr(content1);
     }
     
     ErrorCodes serialiseSong(const char* name, const char* filePath) const
     {
         std::ofstream file(filePath, std::ios::binary);
         if (!file.is_open())
             return ErrorCodes::OpeningError;

         Song toSave = findSongByName(name);

         file.write((const char*)&toSave, sizeof(toSave));
     }

};
 int main()
 {
  

 }


