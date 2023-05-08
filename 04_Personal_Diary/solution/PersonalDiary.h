#ifndef PERSONALDIARY_H
#define PERSONALDIARY_H

#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <sys/_types/_time_t.h>
#include <time.h>

class Diary{
	private:
	std::map<unsigned int, std::string> content;

	public:
	Diary(){
		time_t now = time(NULL);
	}
	inline std::string operator[](std::string);
};

#endif