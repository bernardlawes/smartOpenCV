
#include "stdafx.h"
#include <iostream>

#include <fstream>

#ifdef _WIN32
#include <io.h> 
#define access    _access_s
#else
#include <unistd.h>
#endif

using namespace std;

// #########################################################
bool FileExists(const std::string &Filename)
{
	return access(Filename.c_str(), 0) == 0;
}
// #########################################################
bool fexists(const char *filename) {
	std::ifstream ifile(filename);
	return (bool)ifile;
}
// #########################################################
void exitFileNotFound(std::string filename) {
	if (!FileExists(filename)) {
		std::cout << "File Not Found" << std::endl;
		int key = 0, ext = 0;

		while (key != 13)
		{
			key = getchar();
			// Return key pressed
			if (key == 10)             
			{
				//printf(" \"%c\" has ascii value %i\n", key, key);
				exit(-1);
			}
		}
	}
}
// #########################################################