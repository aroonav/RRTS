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

#ifndef SUPERVISOR_H_HEADER
#define SUPERVISOR_H_HEADER

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include "constants.h"

class supervisor
{
public:
	int enter_information(int requestID, int newPriority, std::string newRawMaterials, std::string newMachinesRequired, std::string newPersonnelRequired);
	int repair_scheduler();
	int enter_statistics();
};

#endif