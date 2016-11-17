#include <iostream>
#include <fstream>
#include <string>
#define DATAPATH "data.txt"

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
		ofstream fout;
		fout.open(DATAPATH, std::ios_base::app);
		if (fout.is_open())
		{	fout<<location<<","<<startPoint<<","<<endPoint<<","<<residentName<<","<<address<<","<<contact<<","<<IDNumber<<endl;
			fout.close();
			return 0;
		}
		else
		{	cout<<"Error opening file";
			return 1;
		}
	}
};

class clerk
{
public:
	clerk();
	~clerk();
	int request_raiser(string location, string startPoint, string endPoint, string residentName, string address, string contact, string IDNumber)
	{
		;
	}
};

class supervisor
{
private:
	void enter_priority(int priority);
	void enter_raw_materials();
	void enter_machines();
	void enter_personnels();
public:
	supervisor();
	~supervisor();
	int enter_information();
	int repair_scheduler();
};

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
	scanf("%*c");
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
	{	cout<<"Request Raised successfully !!"<<endl;
		return 0;
	}
	else
		return 1;
}

int mainInterface()
{
	cout<<"---------------------------"<<endl;
	cout<<"Road Repair Tracking System"<<endl;
	cout<<"---------------------------"<<endl;
	int option = -1;
	do
	{	cout<<"Please choose your identity:"<<endl;
		cout<<"1. Resident"<<endl;
		cout<<"6. Exit"<<endl;
		cin>>option;

		if(option<0 || option>6)
		{	cout<<"Please choose correctly.";
			continue;
		}
		else if(option==1)		// Resident
			return resident_driver();
	}while(option!=6);
	return 0;
}

int main()
{
	return mainInterface();
}
