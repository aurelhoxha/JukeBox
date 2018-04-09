#include <iostream>
#include <string>
#include <algorithm>
#include "Jukebox.h"
#include "Track.h"

Jukebox::Jukebox()
{
    root = NULL;
}

Jukebox::~Jukebox()
{
    while(!isEmpty())
    {
        Track* tmp = root;
        root = root->next;
        delete tmp;
    }
}

bool Jukebox::isEmpty()
{
    return (root == NULL);
}

void Jukebox::addTrack( const string title, const int releaseYear)
{

    Track *cur = root, *prev;

    for( ; cur != NULL ; prev = cur, cur = cur->next )
    {
        if( lower_case(cur->trackTitle) == lower_case(title) )
        {
            std::cout << "You cannot add " << "\"" << title << "\" since it already is if the list.\n\n";
            return;
        }

    }

    Track* submittedTrack = new Track(title, releaseYear);
    std::cout<<"Track " << "\"" << title << "\" added successfully!\n";
    if(Jukebox::isEmpty())
    {
        root = submittedTrack;
        return;
    }
    prev->next = submittedTrack;

}

void Jukebox::removeTrack( string title )
{
    if (Jukebox::isEmpty())
    {
        std::cout << "There are no songs in the jukebox" << '\n';
        return;
    }

    Track* cur = root;

    std::cout <<"Track " << "\"" << title << "\" was deleted successfully.\n";
    if(cur != NULL && (lower_case(cur->trackTitle) == lower_case(title)))
    {
        Track* temp = root->next;
        delete root;
        root = temp;
        return;
    }

    for( ; cur->next != NULL ; cur = cur->next )
    {
        if( lower_case(title) == lower_case(cur->next->trackTitle))
        {
            Track* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
            return;
        }
    }

}

void Jukebox::addMusician(const string trackTitle, const string musicianFirstName, const string musicianLastName, const string musicianRole)
{
    Track* cur = root;
    for(  ; cur != NULL ; cur = cur->next )
    {
        if( lower_case(cur->trackTitle) == lower_case(trackTitle) )
        {
            cur->addMusician(musicianFirstName, musicianLastName, musicianRole);
            cout<<"Musician " << musicianFirstName << " "<< musicianLastName << " added successfuly in " << trackTitle << " track as "<< musicianRole <<".\n";
            return;
        }
    }

    cout << "There is no track with that name :(\n\n";
}

void Jukebox::removeMusician(const string trackTitle, const string musicianFirstName,  const string musicianLastName)
{

    for( Track* cur = root ; cur != NULL ; cur = cur->next )
    {
        cout<<"Musician " << musicianFirstName << " " << musicianLastName << " in " << " \" " << trackTitle << " \" " << " deleted successfully!\n";
        if( lower_case(cur->trackTitle) == lower_case(trackTitle) )
        {
            cur->removeMusician(musicianFirstName, musicianLastName);
            return;
        }

    }

    cout << "There is no such musician :(\n\n";

}

void Jukebox::showAllTracks()
{
  cout<<"List of Tracks\n";
	if ( root == NULL )
  {
		cout << "---No tracks (yet)---" << "\n";
        return;
	}


	Track* cur = root;


	for (;cur != NULL; cur = cur->next)
		cout <<"Title: "<< cur -> trackTitle << " | Release Year: " << cur -> releaseYear << "\n";

}


void Jukebox::showTrack(const string trackTitle)
{
	Track* cur = root;
	for( ; cur != NULL ; cur = cur->next)
  {
        if(lower_case(cur->trackTitle) == lower_case(trackTitle))
        {
            cur->showInfo();
            return;
        }

	}

    cout << "No track with that name :( ";
}


void Jukebox::showMusicianRoles(const string musicianFirstName, const string musicianLastName) {

    Track* cur = root;

    cout << musicianFirstName << " " << musicianLastName << endl;


	for( ; cur != NULL ; cur = cur->next) {

        if( cur->hasMusician(musicianFirstName, musicianLastName) )
            cout << cur -> trackTitle << ", " << cur->releaseYear << endl;

    }

}


string Jukebox::lower_case(string a) {
	string b = a;
	for ( int i = 0; i < a.length(); i++) {
		b [i] = tolower ( a [i]);
	}
	return b;
}

int main() {

    Jukebox j;

    j.addTrack("Hey yee", 1990);
    j.addTrack("Hey ye", 1990);
    j.addMusician("Hey yee", "Aqif", "Kapertoni", "Mut");
    j.removeMusician("Hey yee","Aqif", "Kapertoni" );

    j.showTrack("Hey yee");


  //  j.showMusicianRoles("Aqif", "Kapertoni");
    // j.showTrack("Hey yee");

}
