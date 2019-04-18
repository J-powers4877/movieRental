#include "customerType.h"
#include "videoType.h"

videoType movieType;

void customerType::customerMenu()
{
	system("cls");
	std::cout << "- Please enter the letter of what you would like to do -" << std::endl;
	std::cout << "- A: Look up a account's information based on name of the customer or account number -" << std::endl;
	std::cout << "- B: Add a account to the system -" << std::endl;
	std::cout << "- C: Rent out a video to a customer -" << std::endl;
	std::cout << "- D: Return in a video from the customer -" << std::endl;
	std::cout << "- E: Edit customer account information -" << std::endl;
	std::cout << "- F: Print the list of movies a customer has out" << std::endl;
	std::cout << "- G: Return to the main menu - " << std::endl;

	std::cin >> cUserMenuInput;
	std::cin.ignore(1, '\n');

	switch (cUserMenuInput)
	{
	case 'A':
	case 'a':
		system("cls");
		getCustomerData();
		break;
	case 'B':
	case 'b':
		system("cls");
		addCustomerData();
		removeExtraLines();
		break;
	case 'C':
	case 'c':
		system("cls");
		rentOutVideo();
		removeExtraLines();
		break;
	case 'D':
	case 'd':
		system("cls");
		returnInVideo();
		removeExtraLines();
		break;
	case 'E':
	case 'e':
		system("cls");
		editCustomerData();
		removeExtraLines();
		break;
	case 'F':
	case 'f':
		system("cls");
		customerMovies();
		removeExtraLines();
		break;
	case 'G':
	case 'g':
		system("cls");
		break;
	}
}

void customerType::getCustomerData()
{
	while (true)
	{
		system("cls");
		iCustomerInfo.open(customerFile);

		std::cout << "Please enter the name or account number of the account you would like to find: ";
		getline(std::cin, sUserDatabaseFind);
	
		while (iCustomerInfo.good())
		{
			getline(iCustomerInfo, sDatabaseFileInput);
			if (sDatabaseFileInput.find(sUserDatabaseFind) != sDatabaseFileInput.npos)
			{
				sDatabaseFound = "true";
				std::cout << sDatabaseFileInput << std::endl;
			}
			else if (sDatabaseFileInput.find(sUserDatabaseFind) < 0)
			{
				getline(iCustomerInfo, sDatabaseFileInput);
			}
		}
		if (sDatabaseFound == "false")
		{
			std::cout << "The account entered was not found." << std::endl;
			std::cout << "Would you like to create a new account for the customer? Y for yes, N for No: " << std::endl;
			std::cin >> cAccountDatabaseCreation;
			if (cAccountDatabaseCreation == 'Y' || cAccountDatabaseCreation == 'y')
			{
				iCustomerInfo.close();
				addCustomerData();
			}
		}
		
		std::cout << std::endl;
		std::cout << "Would you like to find another account? Y for yes, N for no: ";
		std::cin >> cUserDatabaseContinue;
		std::cin.ignore(1, '\n');
		if (cUserDatabaseContinue == 'Y' || cUserDatabaseContinue == 'y')
		{
			iCustomerInfo.close();
			sUserDatabaseFind.clear();
			sDatabaseFound = "false";
			system("cls");
			continue;
		}
		else
		{
			system("cls");
			iCustomerInfo.close();
			customerMenu();
			break;
		}
	}
}

std::string customerType::getCustomerData(std::string sDatabaseInput)
{
	while (true)
	{
		system("cls");
		iCustomerInfo.open(customerFile);

		while (iCustomerInfo.good())
		{
			getline(iCustomerInfo, sDatabaseFileInput);
			if (sDatabaseFileInput.find(sDatabaseInput) != sDatabaseFileInput.npos)
			{
				sDatabaseFound = "true";
				iCustomerInfo.close();
				return sDatabaseFileInput;
			}
			else if (sDatabaseFileInput.find(sDatabaseInput) < 0)
			{
				getline(iCustomerInfo, sDatabaseFileInput);
			}
		}
		if (sDatabaseFound == "false")
		{
			std::cout << "The account entered was not found." << std::endl;
			system("pause");
		}
		else 
		{
			break;
		}
	}
}

void customerType::addCustomerData()
{
	while (true)
	{
		system("cls");
		iCustomerInfo.open(customerFile);

		std::cout << "Please enter the first name of the new customer: ";
		std::cin >> sNewAccountFirst;
		sNewAccount.append(sNewAccountFirst);

		std::cout << "Please enter the last name of the new customer: ";
		std::cin >> sNewAccountLast;
		sNewAccount.append(" " + sNewAccountLast);

		std::cout << "Please enter the account number of the new customer: ";
		std::cin >> sNewAccountNum;
		sNewAccount.append(" | " + sNewAccountNum + " [");

		while (iCustomerInfo.good())
		{
			getline(iCustomerInfo, sImportAccountData);
			sExistingAccountData.append(sImportAccountData + '\n');
		}
		//Add Name check.
		
		iCustomerInfo.close();
		oCustomerInfo.open(customerFile);
		oCustomerInfo << sExistingAccountData << sNewAccount;
		oCustomerInfo.close();

		std::cout << "Would you like to add another account? Y for yes, N for No: ";
		std::cin >> cAccountCreationContinue;
		if (cAccountCreationContinue == 'Y' || cAccountCreationContinue == 'y')
		{
			system("cls");
			sNewAccount.clear();
			sExistingAccountData.clear();
			continue;
		}
		else 
		{
			system("cls");
			sNewAccount.clear();
			sExistingAccountData.clear();
			customerMenu();
			break;
		}
	}
	
	

	
}

void customerType::editCustomerData()
{
	while (true)
	{
		std::cout << "Please enter the customer's data you would like to change: ";
		getline(std::cin, sFindOldCustomerInfo);

		sTempOldCustomerInfo = sFindOldCustomerInfo;

		sOldCustomerRetrieved = getCustomerData(sFindOldCustomerInfo);

		sTempOldCustomerRetrieved = sOldCustomerRetrieved;

		if (sOldCustomerRetrieved.empty() == 'true')
		{
			continue;
		}

		std::cout << "You would like to change " << sOldCustomerRetrieved << " information, correct? Y for yes, N for no.";
		std::cin >> cOldCustomerVerify;

		if (cOldCustomerVerify == 'Y' || cOldCustomerVerify || 'y')
		{

		}
		else if(cOldCustomerVerify == 'N' || cOldCustomerVerify || 'n')
		{
			continue;
		}

		std::cout << "Please enter the value you would like to change: ";
		std::cin >> sValueToChange;

		size_t valueChangePos = sOldCustomerRetrieved.find(sValueToChange);

		std::cout << "What would you like to replace " << sValueToChange << " with?" << std::endl;
		std::cin >> sNewValue;

		sOldCustomerRetrieved.replace(valueChangePos, std::string(sValueToChange).length(), sNewValue);

		sEditDatabase = getAllCustomerData();

		size_t oldValueChangePos = sEditDatabase.find(sTempOldCustomerRetrieved);

		sEditDatabase.replace(oldValueChangePos, std::string(sTempOldCustomerRetrieved).length(), sOldCustomerRetrieved);

		oCustomerInfo.open(customerFile);

		oCustomerInfo << sEditDatabase;

		oCustomerInfo.close();

		sOldCustomerRetrieved.clear();
		sEditDatabase.clear();
		sOldCustomerRetrieved.clear();

		break;
	}
}

void customerType::rentOutVideo() 
{
	while (true)
	{
		sFullDatabase.clear();
		std::cout << "Please enter the customer's name or account number: ";
		getline(std::cin, sAccountInformation);
		sAccountRetrieve = getCustomerData(sAccountInformation);
		if (sAccountRetrieve.empty() == 'true')
		{
			continue;
		}

		std::cout << "Please enter the movie title: ";
		getline(std::cin, sMovieName);

		movieType.rentCopy(sMovieName);

		if (movieType.sMovieFound == "false")
		{
			break;
		}

		if (movieType.sRented == "false")
		{
			break;
		}

		sAccountDatabase = getAllCustomerData();

		size_t stringPosition = sAccountDatabase.find(sAccountRetrieve);

		sAccountDatabase.replace(stringPosition, std::string(sAccountRetrieve).length(), sAccountRetrieve + " " + sMovieName);

		oCustomerInfo.open(customerFile);

		oCustomerInfo << sAccountDatabase << std::endl;
		oCustomerInfo.close();

		sAccountDatabase.clear();
		sAccountInformation.clear();
		sAccountRetrieve.clear();

		break;
	}
 }

void customerType::returnInVideo()
{
	while (true)
	{
		std::cout << "Please enter the customer's name or account number: ";
		getline(std::cin, sCustomerInformation);
		sCustomerAccRetrieve = getCustomerData(sCustomerInformation);

		sCustomerAccRetrieved = sCustomerAccRetrieve;

		if (sCustomerAccRetrieve.empty() == 'true')
		{
			continue;
		}

		std::cout << "Please enter the movie title to return: ";
		getline(std::cin, sMovieReturn);

		movieType.returnCopy(sMovieReturn);

		sMovieReturn = " " + sMovieReturn;

		iCustomerInfo.open(customerFile);
		while (iCustomerInfo.good())
		{
			getline(iCustomerInfo, sExistingCustomersImport);
			sExistingCustomers.append(sExistingCustomersImport + '\n');
		}

		size_t customerPosition = sExistingCustomers.find(sCustomerAccRetrieve);

		size_t moviePosition = sCustomerAccRetrieve.find(sMovieReturn);

		if (moviePosition > 500)
		{
			std::cout << "The movie " << sMovieReturn << " could not be found for " << sCustomerAccRetrieved << std::endl;
			iCustomerInfo.close();
			system("pause");
			break;
		}

		sCustomerWithoutMovie = sCustomerAccRetrieve.replace(moviePosition, std::string(sMovieReturn).length(), "");

		sExistingCustomers.replace(customerPosition, std::string(sCustomerAccRetrieved).length(), sCustomerWithoutMovie);

		iCustomerInfo.close();
		oCustomerInfo.open(customerFile);

		oCustomerInfo << sExistingCustomers << std::endl;

		oCustomerInfo.close();

		sExistingCustomers.clear();
		sCustomerWithoutMovie.clear();


		break;
	}
}

void customerType::removeExtraLines()
{
	iCustomerInfo.open(customerFile);

	while (iCustomerInfo.good())
	{
		getline(iCustomerInfo, sDatabaseImport);
		sDatabase.append(sDatabaseImport + '\n');
	}
	
	iCustomerInfo.close();

	size_t emptyLinePosition;
	while ((emptyLinePosition = sDatabase.find("\n\n", 0)) != std::string::npos)
	{
		sDatabase.erase(emptyLinePosition, 1);
	}

	oCustomerInfo.open(customerFile);

	oCustomerInfo << sDatabase;

	oCustomerInfo.close();

	sDatabase.clear();
}

std::string customerType::getAllCustomerData()
{
	iCustomerInfo.open(customerFile);
	while (iCustomerInfo.good())
	{
		getline(iCustomerInfo, sFullDatabaseImport);
		sFullDatabase.append(sFullDatabaseImport + '\n');
	}

	iCustomerInfo.close();

	return sFullDatabase;
}

void customerType::customerMovies()
{
		std::cout << "Please enter the name or account number of the customer you would like to find: ";
		getline(std::cin, sCustomerInfoMovies);

		sCustomerInfoReturned = getCustomerData(sCustomerInfoMovies);

		size_t moviePosition = sCustomerInfoReturned.find('[');

		std::cout << sCustomerInfoMovies << " has" << sCustomerInfoReturned.substr(moviePosition + 1,sCustomerInfoReturned.length()) << " checked out." << std::endl;
		system("pause");
}