#ifndef SONG_H
#define SONG_H

#include <sstream>

class Song {
private:
	std::string name;
	int lengthSeconds;
public:
	Song() {}

	Song(std::string name, int lengthSeconds) : name(name), lengthSeconds(lengthSeconds) {}

	std::string getName() const {
		return this->name;
	}

	int getLengthSeconds() const {
		return this->lengthSeconds;
	}
};

bool operator < (const Song& first, const Song& second)
{
	return first.getLengthSeconds() < second.getLengthSeconds();
}

#endif // !SONG_H
