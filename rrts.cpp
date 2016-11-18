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

#include "rrts.h"

int resident_driver()
{
	std::string location, startPoint, endPoint, residentName, address, contact, IDNumber;
	std::cout<<"\nRaise request for road repair by resident."<<std::endl;
	std::cout<<"Enter Location:";			getline(std::cin, location);
	std::cout<<"Enter start point of road:";	getline(std::cin, startPoint);
	std::cout<<"Enter end point of road:";	getline(std::cin, endPoint);
	std::cout<<"Enter your name:";			getline(std::cin, residentName);
	std::cout<<"Enter your address:";		getline(std::cin, address);
	std::cout<<"Enter your contact number:";	getline(std::cin, contact);
	std::cout<<"Enter your IDNumber:";		getline(std::cin, IDNumber);

	resident r(residentName, address, contact, IDNumber);
	if( r.request_raiser(location, startPoint, endPoint) == 0)
	{	std::cout<<"Request Raised successfully by resident !!"<<std::endl;
		return 0;
	}
	else
		return 1;
}
int clerk_driver()
{
	std::string location, startPoint, endPoint, requesterName, requesterAddress, requesterContact, requesterIDNumber;
	std::cout<<"\nRaise request for road repair by clerk."<<std::endl;
	std::cout<<"Enter Location:";					getline(std::cin, location);
	std::cout<<"Enter start point of road:";			getline(std::cin, startPoint);
	std::cout<<"Enter end point of road:";			getline(std::cin, endPoint);
	std::cout<<"Enter resident's name:";				getline(std::cin, requesterName);
	std::cout<<"Enter resident's address:";			getline(std::cin, requesterAddress);
	std::cout<<"Enter resident's contact number:";	getline(std::cin, requesterContact);
	std::cout<<"Enter resident's IDNumber:";			getline(std::cin, requesterIDNumber);

	clerk r(requesterName, requesterAddress, requesterContact, requesterIDNumber);
	if( r.request_raiser(location, startPoint, endPoint) == 0)
	{	std::cout<<"Request Raised successfully by clerk !!"<<std::endl;
		return 0;
	}
	else
		return 1;
}
int supervisor_driver()
{
	int requestID;
	int newPriority;
	int option = -1;
	std::string newRawMaterials;
	std::string newMachinesRequired;
	std::string newPersonnelRequired;
	supervisor s;

	std::cout<<"\nSupervisor"<<std::endl;
	std::cout<<"----------"<<std::endl;
	std::cout<<"1. Enter information about a road repair request.\n2. Schedule road repair work\n3. Enter Statistics\n";
	std::cin>>option;
	if(option==1)
	{
		//TODO: Check that these values don't contain commas.
		std::cout<<"\nNow entering information about road repair request..."<<std::endl;
		std::cout<<"Enter request ID whose values have to be updated:";
		scanf("%d%*c", &requestID);
		std::cout<<"Enter new priority(1-100):";
		scanf("%d%*c", &newPriority);
		std::cout<<"Enter new raw materials:";
		getline(std::cin, newRawMaterials);
		std::cout<<"Enter new machines required:";
		getline(std::cin, newMachinesRequired);
		std::cout<<"Enter new personnel required:";
		getline(std::cin, newPersonnelRequired);
		return s.enter_information(requestID, newPriority, newRawMaterials, newMachinesRequired, newPersonnelRequired);
	}
	else if(option==2)
	{
		std::cout<<"Now scheduling road repairs..."<<std::endl;
		return s.repair_scheduler();
	}
	else if(option==3)
	{
		return s.enter_statistics();
	}
}
int administrator_driver()
{
	std::string manpower, machines;
	std::cout<<"\nAdministrator"<<std::endl;
	std::cout<<"-------------"<<std::endl;
	std::cout<<"Enter information about the available resources:"<<std::endl;
	administrator a;
	std::cout<<"Enter available manpower with the system."<<std::endl;
	getline(std::cin, manpower);
	std::cout<<"Enter available machines with the system."<<std::endl;
	getline(std::cin, machines);
	return a.enterAvailableResources(manpower, machines);
}
int mayor_driver()
{
	mayor m;
	std::cout<<"Mayor"<<std::endl;
	std::cout<<"-----"<<std::endl;
	std::cout<<"Query Repair Statistics."<<std::endl;
	m.query_repair_statistics();
}


int mainInterface()
{
	std::cout<<"---------------------------"<<std::endl;
	std::cout<<"---------------------------"<<std::endl;
	std::cout<<"Road Repair Tracking System"<<std::endl;
	std::cout<<"---------------------------"<<std::endl;
	std::cout<<"---------------------------"<<std::endl;
	int option = -1;
	do
	{	std::cout<<"Please choose your identity:"<<std::endl;
		std::cout<<"1. Resident"<<std::endl;
		std::cout<<"2. Clerk"<<std::endl;
		std::cout<<"3. Supervisor"<<std::endl;
		std::cout<<"4. Administrator"<<std::endl;
		std::cout<<"5. Mayor"<<std::endl;
		std::cout<<"6. Exit"<<std::endl;
		std::cin>>option;scanf("%*c");

		if(option<0 || option>6)
		{	std::cout<<"Please choose correctly.";
			continue;
		}
		else if(option==1)		return resident_driver();		// Resident
		else if(option==2)		return clerk_driver();			// Clerk
		else if(option==3)		return supervisor_driver();		// Supervisor
		else if(option==4)		return administrator_driver();	// Administrator
		else if(option==5)		return mayor_driver();			// Mayor
	} while(option!=6);

	return 0;
}

int main()
{
	std::cout<<"    Road Repair Tracking System  Copyright (C) 2016  Aroonav Mishra.\nThis program comes with ABSOLUTELY NO WARRANTY; for details see LICENSE.txt.\nThis is free software, and you are welcome to redistribute it under certain conditions.\n";
	return mainInterface();
}
