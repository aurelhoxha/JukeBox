#include <iostream>
#include "Track.h"
using namespace std;

class Jukebox
{
		public:
						Jukebox();
						~Jukebox();

						bool isEmpty();
						void addTrack(const string trackTitle, const int releaseYear);
						void removeTrack(const string trackTitle);

						void addMusician(const string trackTitle, const string musicianFirstName, const string musicianLastName, const string musicianRole);
						void removeMusician(const string trackTitle, const string musicianFirstName,  const string musicianLastName);

						void showAllTracks();
						void showTrack(const string trackTitle);

						void showMusicianRoles(const string musicianFirstName, const string musicianLastName);
						string lower_case(const string tolower);

		private:
						Track* root;

};
