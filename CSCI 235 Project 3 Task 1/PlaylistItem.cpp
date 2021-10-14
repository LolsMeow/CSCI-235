#include "PlaylistItem.hpp"
/*
    Parameterized Construtor
    Parameters: title, length, genre
    Goal: Update member variables with given parameters
*/

PlaylistItem::PlaylistItem(std::string title, double length, std::string genre) : 
                        title_(title), length_(length), genre_(genre)
{
}

/************************ Getter Functions ************************/

/*
    Goal: Return the value of title_
*/

std::string PlaylistItem::getTitle() const{
    return title_;
}

/*
    Goal: Return the value of length_
*/

double PlaylistItem::getLength() const{
    return length_;
}

/*
    Goal: Return the value of genre_
*/

std::string PlaylistItem::getGenre() const{
    return genre_;
}

/************************ Setter Functions ************************/

/*
    Goal: Update the value of title_ with the given parameter
*/

void PlaylistItem::setTitle(std::string title){
    title_ = title;
}

/*
    Goal: Update the value of length_ with the given parameter
*/

void PlaylistItem::setLength(double length){
    length_ = length;
}

/*
    Goal: Update the value of genre_ with the given parameter
*/

void PlaylistItem::setGenre(std::string genre){
    genre_ = genre;
}

/************************ Other Functions ************************/

/*
    A virtual function to be implemented by the children classes
*/
