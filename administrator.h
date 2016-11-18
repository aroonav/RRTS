#ifndef ADMINISTRATOR_H_HEADER
#define ADMINISTRATOR_H_HEADER

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include "constants.h"
#include "supervisor.h"

class administrator
{
public:
	int enterAvailableResources(std::string manpower, std::string machines);
	int showAvailableResources();
};

#endif
