#include "SolfegeNoteNaming.h"

NoteName SolfegeNoteNaming::operator()(const std::string& note) const
{
	char solfege;
	if (note == "Do")
	{
		solfege = 'C';
	}
	else if (note == "Re")
	{
		solfege = 'D';
	}
	else if (note == "Mi")
	{
		solfege = 'E';
	}
	else if (note == "Fa")
	{
		solfege = 'F';
	}
	else if (note == "Sol")
	{
		solfege = 'G';
	}
	else if (note == "La")
	{
		solfege = 'A';
	}
	else if (note == "Si")
	{
		solfege = 'B';
	}
	else
	{
		solfege = '?';
	}

    return NoteName(solfege);
}
