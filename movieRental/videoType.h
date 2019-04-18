#pragma once

#include <iostream>
#include <string>
#include <fstream>

class videoType
{
	std::ifstream iMovieInfo;
	std::ofstream oMovieInfo;

	char cMovieMenuInput;

	std::string movieFile = "movieDatabase.txt";

	std::string sFullMoviesImport;
	std::string sFullMovies;

	/*
	Variables for addAMovie()
	*/
	std::string sAddMovieName;
	std::string sAddMovieStars;
	std::string sAddMovieStarsTotal;
	int iAddNumberOfStars;
	std::string sAddMovieProducer;
	std::string sAddMovieDirector;
	std::string sAddMovieProductionCompany;
	std::string sAddMovie;
	int iAddNumberOfCopies;
	std::string sAddNumberOfCopies;
	std::string sExistingMovies;

	/*
	Variables for videoCheck()
	*/
	std::string sVideoFind;
	std::string sVideoFileInput;
	std::string sVideoFound = "false";
	char cVideoSearchContinue;
	char cVideoDetails;

	/*
	Variables for getVideoDetails()
	*/
	std::string sInputVideo;

	/*
	Variables for numberOfCopies()
	*/
	std::string sMovieToFind;
	std::string sMovieData;
	int iCopyPosition;
	char cCopiesContinue;

	/*
	Variables for returnCopy()
	*/
	std::string sReturnMovieInfo;
	std::string sReturnMovieInfoTemp;
	std::string sReturnMovieDatabaseImport;
	std::string sReturnMovieDatabase;
	int iPositionOfCopies;
	int iNumberOfOldCopies;
	int iNumberOfNewCopies;

	/*
	Variables for rentCopy()
	*/
	std::string sRentMovieInfo;
	std::string sRentMovieInfoTemp;
	std::string sRentMovieDatabaseImport;
	std::string sRentMovieDatabase;
	int iPositionOfRented;
	int iNumberOfRented;
	int iNewNumberOfRented;

	/*
	Variables for removingExtraLines()
	*/
	std::string sMovieDatabaseImport;
	std::string sMovieDatabase;


public:
	std::string sRented;

	std::string sMovieFound = "false";

	void movieMenu();
	void addAMovie();
	void numberOfCopies();
	void returnCopy(std::string);
	void rentCopy(std::string);
	void removingExtraLines();
	std::string getVideoDetails(std::string);
	std::string getAllMovies();
	void videoCheck();
};

