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

#include "mayor.h"

int mayor::query_repair_statistics()
{
	std::string repairOverTime;
	std::string repairOutstanding;
	std::string repairUtilization;
	std::fstream fin;
	fin.open(STATISTICSPATH, std::ios::in);
	fin>>repairOverTime;
	fin>>repairOutstanding;
	fin>>repairUtilization;
	std::cout<<"Repair work over time:"<<repairOverTime<<std::endl;
	std::cout<<"Repair work outstanding:"<<repairOutstanding<<std::endl;
	std::cout<<"Repair utilization:"<<repairUtilization<<std::endl;
	fin.close();
	return 0;
}
