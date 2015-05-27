#include <iostream> 
#include <fstream>
#include <string>
#include <array>

int menu()
{
	int choice = 0;

	std::cout << "-- Please enter a number -- \n";
	std::cout << "-- 1: Create entry --\n";
	std::cout << "-- 2: List entries --\n";
	std::cout << "-- 3: Clear address book --\n";

	std::cin >> choice;

	return choice;
}

//Function creates an entry in the text file
void createEntry()
{
	std::ofstream addEntry("addressbook.got", std::ofstream::out | std::ofstream::app);
	std::string name, address1, address2, postode, email, mobileNum, homeNum;

	std::cout << "Name: ";
	std::cin >> name;
	std::cout << " \nAddress 1: ";
	std::cin >> address1;
	std::cout << "\nAddress 2: ";
	std::cin >> address2;
	std::cout << "\nEnter postode: ";
	std::cin >> postode;
	std::cout << "\nEnter email address: ";
	std::cin >> email;
	std::cout << "\nEnter home phone number: ";
	std::cin >> homeNum;
	std::cout << "\nEnter mobile number: ";
	std::cin >> mobileNum;

	addEntry << name << std::endl;
	addEntry << address1 << std::endl;
	addEntry << address2 << std::endl;
	addEntry << postode << std::endl;
	addEntry << email << std::endl;
	addEntry << homeNum << std::endl;
	addEntry << mobileNum << std::endl;
	addEntry << "---" << std::endl;

	addEntry.close();


}

int listEntries()
{
	std::array<std::string, 10> name = {};
	std::array<std::string, 10> address1 = {};
	std::array<std::string, 10> address2 = {};
	std::array<std::string, 10> postcode = {};
	std::array<std::string, 10> email = {};
	std::array<std::string, 10> homeNum = {};
	std::array<std::string, 10> mobileNum = {};
	std::array<std::string, 10> divider = {};
	
	std::ifstream readFile; 

	readFile.open("addressbook.got");

	while (!readFile.eof())
	{	
		for (int x = 0; x < 10; x++)
		{
			std::getline(readFile, name[x]);
			std::getline(readFile, address1[x]);
			std::getline(readFile, address2[x]);
			std::getline(readFile, postcode[x]);
			std::getline(readFile, email[x]);
			std::getline(readFile, homeNum[x]);
			std::getline(readFile, mobileNum[x]);
			std::getline(readFile, divider[x]);
		}
	}

	

	for (int i = 0; i < 10; i++)
	{
		if (name[i] != "")
		{
			std::cout << "\nName: " << name[i];
			std::cout << "\nAddress 1: " << address1[i];
			std::cout << "\nAddress 2: " << address2[i];
			std::cout << "\nPostcode: " << postcode[i];
			std::cout << "\nEmail: " << email[i];
			std::cout << "\nHome Number: " << homeNum[i];
			std::cout << "\nMobile number :" << mobileNum[i];
			std::cout << "\n" << divider[i];
			std::cin.get();
		}	
	}


	return 1;

}

void clearEntries()
{
	std::ofstream clear ("addressbook.got", std::ofstream::trunc);
	clear.close();
}

int main()
{
	switch (menu())
	{
		case 1: 
			createEntry();
			break;
			
		case 2: 
			listEntries();
			break;

		case 3: 
			clearEntries();
			break;
		
		default:
			break;
	}

	return 0;
}

