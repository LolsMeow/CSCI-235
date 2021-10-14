#ifndef SONG_HPP
#define SONG_HPP 

#include <iostream> 
#include "PlaylistItem.hpp"

class Song : public PlaylistItem
{

public:

Song(std::string title, double length, std::string genre, std::string artist);

/************************ Getter Functions ************************/

/*
    Goal: Return the value of artist_
*/
std::string getArtist() const;

/************************ Setter Functions ************************/

/*
    Goal: Update the value of artist_ with the given parameter
*/
void setArtist(std::string artist);

/************************ Other Functions ************************/

/*
    Goal: Displays the member variables to the console. 
          Format is based on the given example in songExample.txt.
*/
void display() const;

private:

std::string artist_;
};

#endif
