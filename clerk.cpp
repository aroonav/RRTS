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

#include "clerk.h"

clerk::clerk()
{	requester = NULL;
}
clerk::clerk(std::string requesterName, std::string requesterAddress, std::string requesterContact, std::string requesterIDNumber)
{
	requester = new resident(requesterName, requesterAddress, requesterContact, requesterIDNumber);
}
int clerk::request_raiser(std::string location, std::string startPoint, std::string endPoint)
{
	std::ofstream fout;std::ifstream fin;
	int requestID = -1;
	int activeRequests = -1;
	int priority = -1;					// Default priority of repair request. Denotes that the priority hasn't been set yet.
	std::string rawMaterials;
	std::string machinesRequired;
	std::string personnelRequired;

	fin.open(REQUESTIDPATH, std::ios::in);
	fin>>requestID;						// Retrieves last request ID from file.
	fin.close();
	fout.open(REQUESTIDPATH, std::ios::out);
	fout<<requestID+1;					// Updates request ID by incrementing the old value.
	fout.close();

	fin.open(ACTIVEREQUESTSPATH, std::ios::in);
	fin>>activeRequests;						// Retrieves last request ID from file.
	fin.close();
	fout.open(ACTIVEREQUESTSPATH, std::ios::out);
	fout<<activeRequests+1;					// Updates request ID by incrementing the old value.
	fout.close();

	fout.open(DATAPATH, std::ios_base::app);
	if (fout.is_open())
	{	fout<<requestID+1<<","<<location<<","<<startPoint<<","<<endPoint<<","<<requester->residentName<<","<<requester->address<<","<<requester->contact<<","<<requester->IDNumber<<","<<priority<<","<<rawMaterials<<","<<machinesRequired<<","<<personnelRequired<<std::endl;
		fout.close();
		std::cout<<"Request ID:"<<requestID+1<<std::endl;
		return 0;
	}
	else
	{	std::cout<<"Error opening file while raising request by resident.";
		return 1;
	}
}
