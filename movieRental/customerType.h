#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>

class customerType
{
	std::ifstream iCustomerInfo;
	std::ofstream oCustomerInfo;

	std::string customerFile = "customerDatabase.txt";

	char cUserMenuInput;

	/*
	Variables for finding account in database.
	*/
	std::string sUserDatabaseFind;
	std::string sDatabaseFileInput;
	std::string sDatabaseFound = "false";
	char cAccountDatabaseCreation;
	char cUserDatabaseContinue;

	/*
	Variables for adding new account.
	*/
	std::string sImportAccountData;
	std::string sExistingAccountData;
	std::string sNewAccountFirst;
	std::string sNewAccountLast;
	std::string sNewAccountNum;
	std::string sNewAccount;
	char cAccountCreationContinue;

	/*
	Variables for renting a video.
	*/
	std::string sAccountInformation;
	std::string sAccountRetrieve;
	std::string sAccountDatabaseImport;
	std::string sAccountDatabase;
	std::string sMovieName;
	
	/*
	Variables for returning a video.
	*/
	std::string sCustomerInformation;
	std::string sCustomerAccRetrieve;
	std::string sCustomerAccRetrieved;
	std::string sExistingCustomersImport;
	std::string sExistingCustomers;
	std::string sCustomerWithoutMovie;
	std::string sMovieReturn;

	/*
	Variables for editing customer data.
	*/
	std::string sFindOldCustomerInfo;
	std::string sTempOldCustomerInfo;
	std::string sOldCustomerRetrieved;
	std::string sTempOldCustomerRetrieved;
	char cOldCustomerVerify;
	std::string sValueToChange;
	std::string sNewValue;
	std::string sEditDatabase;
	/*
	Variables for getCustomerData()
	*/
	std::string sDatabaseImport;
	std::string sDatabase;

	/*
	Variables for getAllCustomerData()
	*/
	std::string sFullDatabaseImport;
	std::string sFullDatabase;

	/*
	Variables for customerMovies()
	*/
	std::string sCustomerInfoMovies;
	std::string sCustomerInfoReturned;

public:
	void customerMenu();
	void getCustomerData();
	std::string getCustomerData(std::string);
	void addCustomerData();
	void editCustomerData();
	void rentOutVideo();
	void returnInVideo();
	void removeExtraLines();
	std::string getAllCustomerData();
	void customerMovies();
};

