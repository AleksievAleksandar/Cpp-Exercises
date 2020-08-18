#ifndef SOLFEGE_H
#define SOLFEGE_H

#include <sstream>
#include <vector>
#include "NoteName.h"

class SolfegeNoteNaming
{
public:
	SolfegeNoteNaming() = default;
	NoteName operator () (const std::string& note) const;
};

#endif // !SOLFEGE_H

