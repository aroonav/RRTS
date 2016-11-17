#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>

#define TEMPDATAPATH "data/temp.txt"
#define DATAPATH "data/data.txt"
#define REQUESTIDPATH "data/requestID.txt"
#define RESOURCESPATH "data/resources.txt"
#define ACTIVEREQUESTSPATH "data/activeRequests.txt"

using namespace std;

class resident
{
public:
	string residentName;
	string address;
	string contact;
	string IDNumber;

	resident()
	{
		residentName = address = contact = IDNumber = "";
	}
	resident(string residentName, string address, string contact, string IDNumber)
	{
		this->residentName = residentName;
		this->address = address;
		this->contact = contact;
		this->IDNumber = IDNumber;
	}
	int request_raiser(string location, string startPoint, string endPoint)
	{
		ofstream fout;ifstream fin;
		int requestID = -1;
		int activeRequests = -1;
		int priority = -1;					// Default priority of repair request. Denotes that the priority hasn't been set yet.
		string rawMaterials;
		string machinesRequired;
		string personnelRequired;

		fin.open(REQUESTIDPATH, ios::in);
		fin>>requestID;						// Retrieves last request ID from file.
		fin.close();
		fout.open(REQUESTIDPATH, ios::out);
		fout<<requestID+1;					// Updates request ID by incrementing the old value.
		fout.close();

		fin.open(ACTIVEREQUESTSPATH, ios::in);
		fin>>activeRequests;						// Retrieves last request ID from file.
		fin.close();
		fout.open(ACTIVEREQUESTSPATH, ios::out);
		fout<<activeRequests+1;					// Updates request ID by incrementing the old value.
		fout.close();

		fout.open(DATAPATH, std::ios_base::app);
		if (fout.is_open())
		{	fout<<requestID+1<<","<<location<<","<<startPoint<<","<<endPoint<<","<<residentName<<","<<address<<","<<contact<<","<<IDNumber<<","<<priority<<","<<rawMaterials<<","<<machinesRequired<<","<<personnelRequired<<endl;
			fout.close();
			cout<<"Request ID:"<<requestID+1<<endl;
			return 0;
		}
		else
		{	cout<<"Error opening file while raising request by resident.";
			return 1;
		}
	}
};

class clerk
{
	resident* requester;
public:
	clerk()
	{	requester = NULL;
	}
	clerk(string requesterName, string requesterAddress, string requesterContact, string requesterIDNumber)
	{
		requester = new resident(requesterName, requesterAddress, requesterContact, requesterIDNumber);
	}
	int request_raiser(string location, string startPoint, string endPoint)
	{
		ofstream fout;ifstream fin;
		int requestID = -1;
		int activeRequests = -1;
		int priority = -1;					// Default priority of repair request. Denotes that the priority hasn't been set yet.
		string rawMaterials;
		string machinesRequired;
		string personnelRequired;

		fin.open(REQUESTIDPATH, ios::in);
		fin>>requestID;						// Retrieves last request ID from file.
		fin.close();
		fout.open(REQUESTIDPATH, ios::out);
		fout<<requestID+1;					// Updates request ID by incrementing the old value.
		fout.close();

		fin.open(ACTIVEREQUESTSPATH, ios::in);
		fin>>activeRequests;						// Retrieves last request ID from file.
		fin.close();
		fout.open(ACTIVEREQUESTSPATH, ios::out);
		fout<<activeRequests+1;					// Updates request ID by incrementing the old value.
		fout.close();

		fout.open(DATAPATH, std::ios_base::app);
		if (fout.is_open())
		{	fout<<requestID+1<<","<<location<<","<<startPoint<<","<<endPoint<<","<<requester->residentName<<","<<requester->address<<","<<requester->contact<<","<<requester->IDNumber<<","<<priority<<","<<rawMaterials<<","<<machinesRequired<<","<<personnelRequired<<endl;
			fout.close();
			cout<<"Request ID:"<<requestID+1<<endl;
			return 0;
		}
		else
		{	cout<<"Error opening file while raising request by resident.";
			return 1;
		}
	}
};

class supervisor
{
public:
	int enter_information(int requestID, int newPriority, string newRawMaterials, string newMachinesRequired, string newPersonnelRequired);
	int repair_scheduler();
};

int supervisor::enter_information(int requestID, int newPriority, string newRawMaterials, string newMachinesRequired, string newPersonnelRequired)
{
	string str;

	fstream fin, fout;
	fin.open(DATAPATH, ios::in);
	fout.open(TEMPDATAPATH, ios::out);

	if(fout.is_open())
	{
		while(getline(fin, str))
		{
			istringstream in(str);
			char tempStr[128];
			string temp[12];
			for (int i = 0; i < 12; i++)
			{
				in.getline(tempStr, 128, ',');
				temp[i] = tempStr;		// temp[] contains the 12 pieces of information that was stored in the CSV file
			}

			if(requestID == stoi(temp[0]))
			{
				for (int i = 0; i <= 7; i++)
					fout<<temp[i]<<",";
				fout<<newPriority<<","<<newRawMaterials<<","<<newMachinesRequired<<","<<newPersonnelRequired;
			}
			else
			{
				for (int i = 0; i < 12; i++)
					fout<<temp[i]<<",";
			}
			fout<<endl;
		}
		// Rename temp.txt to data.txt now.
		rename(TEMPDATAPATH, DATAPATH);
		remove(TEMPDATAPATH);
		cout<<"Values updated successfully !!"<<endl;
	}
	else
	{	cout<<"Error opening file while updating information by supervisor."<<endl;
		return 1;
	}
	fin.close();
	fout.close();
	return 0;
}

int supervisor::repair_scheduler()
{
	int i=0, activeRequests=-1, j=0, k=0, swap;
	fstream fin, fout;
	fin.open(ACTIVEREQUESTSPATH, ios::in);
	fin>>activeRequests;						// Retrieves last request ID from file.
	fin.close();

	string str[activeRequests+1], swap_str;		// str stores each road repair request.
	int priorities[activeRequests+1];			// priorities stores the priority of each road repair request.

	fin.open(DATAPATH, ios::in);

	if(fin.is_open())
	{
		while(getline(fin, str[i]))
		{
			istringstream in(str[i]);
			char tempStr[128];
			for (int i = 0; i < 9; i++)
				in.getline(tempStr, 128, ',');
			priorities[i] = stoi(tempStr);
			if(priorities[i]==-1)
				priorities[i]=1000;
			i++;
		}
	}
	else
	{	cout<<"Error opening file while updating information by supervisor."<<endl;
		return 1;
	}

	// TODO: Use a divide and conquer approach sorting algorithm.
	// Bubble sort according to the road repair priority and alongside also sort the array str.
	for(j=0; j<(activeRequests-1); j++)
	{
		for(k=0; k<(activeRequests-j-1); k++)
		{
			if(priorities[k] > priorities[k+1])
			{
				swap			= priorities[k];
				priorities[k]   = priorities[k+1];
				priorities[k+1] = swap;

				swap_str = str[k];
				str[k] = str[k+1];
				str[k+1] = swap_str;
			}
		}
	}
	fin.close();

	fout.open(DATAPATH, ios::out);
	cout<<"Data format: <Request ID> <Location> <Start Point> <End Point> <Name> <Address> <Contact> <ID Numbe> <Priority> <Required Raw Materials> <Required Machines> <Required Personnels>";
	for(j=0; j<activeRequests; j++)
	{
		// Write sorted repair requests to file
		fout<<str[j]<<endl;

		// Now print the sorted repair requests to console. This is to generate the "report".
		istringstream in(str[j]);
		char tempStr[128];
		for (int i = 0; i < 12; i++)
		{
			in.getline(tempStr, 128, ',');
			cout<<tempStr<<" ";
		}
		cout<<endl;
	}
	fout.close();
	return 0;
}

class mayor
{
public:
	mayor();
	~mayor();	
};

class administrator
{
public:
	administrator();
	~administrator();
};


int resident_driver()
{
	string location, startPoint, endPoint, residentName, address, contact, IDNumber;
	cout<<"\nRaise request for road repair by resident."<<endl;
	cout<<"Enter Location:";			getline(cin, location);
	cout<<"Enter start point of road:";	getline(cin, startPoint);
	cout<<"Enter end point of road:";	getline(cin, endPoint);
	cout<<"Enter your name:";			getline(cin, residentName);
	cout<<"Enter your address:";		getline(cin, address);
	cout<<"Enter your contact number:";	getline(cin, contact);
	cout<<"Enter your IDNumber:";		getline(cin, IDNumber);

	resident r(residentName, address, contact, IDNumber);
	if( r.request_raiser(location, startPoint, endPoint) == 0)
	{	cout<<"Request Raised successfully by resident !!"<<endl;
		return 0;
	}
	else
		return 1;
}
int clerk_driver()
{
	string location, startPoint, endPoint, requesterName, requesterAddress, requesterContact, requesterIDNumber;
	cout<<"\nRaise request for road repair by clerk."<<endl;
	cout<<"Enter Location:";					getline(cin, location);
	cout<<"Enter start point of road:";			getline(cin, startPoint);
	cout<<"Enter end point of road:";			getline(cin, endPoint);
	cout<<"Enter resident's name:";				getline(cin, requesterName);
	cout<<"Enter resident's address:";			getline(cin, requesterAddress);
	cout<<"Enter resident's contact number:";	getline(cin, requesterContact);
	cout<<"Enter resident's IDNumber:";			getline(cin, requesterIDNumber);

	clerk r(requesterName, requesterAddress, requesterContact, requesterIDNumber);
	if( r.request_raiser(location, startPoint, endPoint) == 0)
	{	cout<<"Request Raised successfully by clerk !!"<<endl;
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
	string newRawMaterials;
	string newMachinesRequired;
	string newPersonnelRequired;
	supervisor s;

	cout<<"\nSupervisor"<<endl;
	cout<<"----------"<<endl;
	cout<<"1. Enter information about a road repair request.\n2. Schedule road repair work\n";
	cin>>option;
	if(option==1)
	{
		//TODO: Check that these values don't contain commas.
		cout<<"\nNow entering information about road repair request..."<<endl;
		cout<<"Enter request ID whose values have to be updated:";
		scanf("%d%*c", &requestID);
		cout<<"Enter new priority(1-100):";
		scanf("%d%*c", &newPriority);
		cout<<"Enter new raw materials:";
		getline(cin, newRawMaterials);
		cout<<"Enter new machines required:";
		getline(cin, newMachinesRequired);
		cout<<"Enter new personnel required:";
		getline(cin, newPersonnelRequired);
		return s.enter_information(requestID, newPriority, newRawMaterials, newMachinesRequired, newPersonnelRequired);
	}
	else
	{
		cout<<"Now scheduling road repairs..."<<endl;
		return s.repair_scheduler();
	}
}
int administrator_driver()
{
	;
}
int mayor_driver()
{
	;
}


int mainInterface()
{
	cout<<"---------------------------"<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"Road Repair Tracking System"<<endl;
	cout<<"---------------------------"<<endl;
	cout<<"---------------------------"<<endl;
	int option = -1;
	do
	{	cout<<"Please choose your identity:"<<endl;
		cout<<"1. Resident"<<endl;
		cout<<"2. Clerk"<<endl;
		cout<<"3. Supervisor"<<endl;
		cout<<"6. Exit"<<endl;
		cin>>option;scanf("%*c");

		if(option<0 || option>6)
		{	cout<<"Please choose correctly.";
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
	return mainInterface();
}
