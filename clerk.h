/**
 *	Road Repair Tracking System
 *  Copyright (C) 2016 by Aroonav Mishra <aroonav11@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef CLERK_H_HEADER
#define CLERK_H_HEADER

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include "resident.h"
#include "constants.h"

class clerk
{
	resident* requester;
public:
	clerk();
	clerk(std::string requesterName, std::string requesterAddress, std::string requesterContact, std::string requesterIDNumber);
	int request_raiser(std::string location, std::string startPoint, std::string endPoint);
};

#endif
