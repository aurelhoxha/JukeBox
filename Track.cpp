
#include "Track.h"
#include <iostream>
using namespace std;


// Constructor of the Track where the Track title and release year are updated

Track::Track ( const string trackTitle, const int releaseYear)
{
	this->trackTitle = trackTitle;
	this->releaseYear = releaseYear;
	next = NULL;
	root = NULL;
}

//Destructor for the Track
Track::~Track()
{

	while ( root != NULL )
	{

		Musician* temp = root;
		root = root -> next;
		delete temp;
	}

}

//Add a musicain in th Track containing his firstName, lastName and Role
void Track::addMusician( const string musicianFirstName, const string musicianLastName, const string musicianRole)
{

	Musician* temp = new Musician;

	temp->musicianFirstName = musicianFirstName;
	temp->musicianLastName = musicianLastName;
	temp->musicianRole = musicianRole;
	temp->next = NULL;

  if(root == NULL)
	{
        root = temp;
        return;
  }

  Musician* cur = root;
  Musician* prev = root;


  for( ; cur != NULL ; prev = cur, cur = cur->next)
	{
        if(cur->musicianFirstName == musicianFirstName && cur->musicianLastName == musicianLastName && cur->musicianRole == musicianRole)
				{
            cout << "This musician is already in the Track.\n\n";
            return;
        }

  }

  prev->next = temp;

}

//Check if there is a musician in the track
bool Track::hasMusician( string musicianFirstName, string musicianLastName)
{
		for(Musician *cur = root; cur != NULL; cur = cur -> next)
		{
			if( cur->musicianFirstName == musicianFirstName && cur->musicianLastName == musicianLastName)
			{
				cout << cur->musicianRole << ", ";
				return true;
			}
		}

		return false;
}

//Remove the musician from the track
void Track::removeMusician( string musicianFirstName, string musicianLastName)
{

	Musician *prev = NULL, *cur = root;
	for( ; cur != NULL ; prev = cur, cur = cur->next )
	{
		if( cur->musicianFirstName == musicianFirstName && cur->musicianLastName == musicianLastName)
		{
			Musician* temp = cur;
			if(prev != NULL)
				prev -> next = cur->next;
			else
				root = cur -> next;;
			delete temp;
		}

	}

}
// Show info for the track such as the title, year and musicians
void Track::showInfo()
{
	cout<<"Information about the required Track!\n";
	cout << "Title: " << trackTitle << " | Release Year: " << releaseYear << endl;

	Musician* cur = root;

	for( ; cur != NULL ; cur = cur->next ) {

		cout << cur->musicianLastName << ", " << cur->musicianFirstName << " (" << cur->musicianRole << ")\n";

	}

}
