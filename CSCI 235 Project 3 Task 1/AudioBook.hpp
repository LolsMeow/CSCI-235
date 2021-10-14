#ifndef AUDIO_BOOK_
#define AUDIO_BOOK_

#include <iostream>
#include "PlaylistItem.hpp"

class AudioBook : public PlaylistItem
{

public:

    AudioBook(std::string title, double length, std::string genre, 
                             std::string author, std::string speaker);

    std::string getAuthor() const;
    std::string getSpeaker() const;

    void setAuthor(std::string author);
    void setSpeaker(std::string speaker);

/*
    Goal: Displays the member variables to the console. 
          Format is based on the given example in audioBookExample.txt.
*/
    void display() const;

private:

    std::string author_;
    std::string speaker_;
};

#endif
