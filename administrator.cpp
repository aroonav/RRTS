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

#include "administrator.h"

int administrator::enterAvailableResources(std::string manpower, std::string machines)
{
	std::fstream fout;
	fout.open(RESOURCESPATH, std::ios::out);
	fout<<manpower<<std::endl;
	fout<<machines<<std::endl;
	fout.close();
	std::cout<<"Available resources updated successfully !!"<<std::endl;
	supervisor s;
	std::cout<<"Now scheduling road repairs..."<<std::endl;
	return s.repair_scheduler();
}
int administrator::showAvailableResources()
{
	std::string manpower, machines;
	std::fstream fin;
	fin.open(RESOURCESPATH, std::ios::in);
	fin>>manpower;
	fin>>machines;
	std::cout<<"Available manpower:"<<manpower<<std::endl;
	std::cout<<"Available machines:"<<machines<<std::endl;
	fin.close();
	return 0;
}
