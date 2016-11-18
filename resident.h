#ifndef RESIDENT_H_FILE
#define RESIDENT_H_FILE

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include "constants.h"

class resident
{
public:
	std::string residentName;
	std::string address;
	std::string contact;
	std::string IDNumber;
	resident();
	resident(std::string residentName, std::string address, std::string contact, std::string IDNumber);
	int request_raiser(std::string location, std::string startPoint, std::string endPoint);
};

#endif
