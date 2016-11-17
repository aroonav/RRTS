## Meaning of data:

* requestID.txt contains the last request ID. This value is used in subsequent road repair requests by incrementing this value.

* Order of data in data.txt:

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
