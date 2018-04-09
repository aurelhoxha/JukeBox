

#ifndef TRACK_H_
#define TRACK_H_

#include <iostream>
using namespace std;

class Track
{
  public:
          string trackTitle;
          int releaseYear;

	        struct Musician
          {
		          string musicianFirstName, musicianLastName, musicianRole;
		          Musician* next;
	        };

          Track(string trackTitle, int releaseYear);
	        ~Track();

	        void addMusician( string musicianFirstName, string musicianLastName, string musicianRole );
          bool hasMusician( string musicianFirstName, string musicianLastName );
          void removeMusician( string musicianFirstName, string musicianLastName);

          void showInfo();
	        Track* next;
	        Musician* root;
};

#endif /* TRACK_H_ */
