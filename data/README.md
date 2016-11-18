## Meaning of data:

*	requestID.txt contains the last request ID. This value is used in subsequent road repair requests by incrementing this value.

*	data.txt contains all the road repair requests
	Order of data in data.txt:

	int requestID = -1;
	string location;
	string startPoint;
	string endPoint;
	string residentName;
	string address;
	string contact;
	string IDNumber;
	int priority = -1;					// Default priority of repair request. Denotes that the priority hasn't been set yet.
	string rawMaterials;
	string machinesRequired;
	string personnelRequired;

*	activeRequests.txt stores the total number of active requests that have been made as of at that moment when it is run.

*	resources.txt contains the currently available manpower and machines available with the administrator as of that moment.

*	statistics.txt contains the statistics of all road repair that is inserted into the system for the review of the mayor.
