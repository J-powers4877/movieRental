#include "videoType.h"

void videoType::movieMenu()
{
	system("cls");
	std::cout << "- Please enter the letter of what you would like to do " << std::endl;
	std::cout << "- A: Add a movie to the store -" << std::endl;
	std::cout << "- B: Check if a movie is in the store -" << std::endl;
	std::cout << "- C: Check the number of copies of a movie in stock -" << std::endl;
	std::cout << "- D: Return to main menu -" << std::endl;

	std::cin >> cMovieMenuInput;
	std::cin.ignore(1, '\n');

	switch (cMovieMenuInput)
	{
	case 'A':
	case 'a':
		system("cls");
		addAMovie();
		removingExtraLines();
		break;
	case 'B':
	case 'b':
		system("cls");
		videoCheck();
		removingExtraLines();
		break;
	case 'C':
	case 'c':
		system("cls");
		numberOfCopies();
		removingExtraLines();
		break;
	case 'D':
	case 'd':
		system("cls");
		break;
	}
}

void videoType::addAMovie()
{
	std::cout << "Please enter the title of the movie: ";
	getline(std::cin, sAddMovieName);
	sAddMovie.append("Title: " + sAddMovieName);

	std::cout << "Please enter the number of stars: ";
	std::cin >> iAddNumberOfStars;
	std::cin.ignore(1, '\n');

	sAddMovie.append(" | Stars: ");
	for (int i = 1; i <= iAddNumberOfStars; i++)
	{
		std::cout << "Please enter star #" << i << " : ";
		getline(std::cin, sAddMovieStars);
		sAddMovieStarsTotal.append(sAddMovieStars + ", ");
	}

	sAddMovie.append(sAddMovieStarsTotal);

	std::cout << "Please enter the producer of the movie: ";
	getline(std::cin, sAddMovieProducer);
	sAddMovie.append("| Producer: " + sAddMovieProducer);

	std::cout << "Please enter the director of the movie: ";
	getline(std::cin, sAddMovieDirector);
	sAddMovie.append(" | Director: " + sAddMovieDirector);

	std::cout << "Please enter the production company: ";
	getline(std::cin, sAddMovieProductionCompany);
	sAddMovie.append(" | Production Company: " + sAddMovieProductionCompany);

	std::cout << "Please enter the number of copies of " << sAddMovieName << " in the store: ";
	std::cin >> iAddNumberOfCopies;
	while (iAddNumberOfCopies < 1 || iAddNumberOfCopies > 10)
	{
		std::cout << "Please enter a value of 1 through 9: ";
		std::cin >> iAddNumberOfCopies;
	}
	sAddNumberOfCopies = std::to_string(iAddNumberOfCopies);
	sAddMovie.append(" | Number of copies: " + sAddNumberOfCopies + '/' + sAddNumberOfCopies + '\n');

	sExistingMovies = getAllMovies();

	oMovieInfo.open(movieFile);

	oMovieInfo << sExistingMovies << sAddMovie;

	oMovieInfo.close();

	sAddMovie.clear();
}

void videoType::videoCheck()
{
	while (true)
	{
		iMovieInfo.open(movieFile);

		std::cout << "Please enter the name of the movie you want to find: ";
		getline(std::cin, sVideoFind);

		while (iMovieInfo.good())
		{
			getline(iMovieInfo, sVideoFileInput);
			if (sVideoFileInput.find(sVideoFind) != sVideoFileInput.npos)
			{
				sVideoFound = "true";
				std::cout << "The video " << sVideoFind << " was found. Would you like to see the video's details? Y for yes, N for no: ";
				std::cin >> cVideoDetails;

				if (cVideoDetails == 'Y' || cVideoDetails == 'y')
				{
					std::cout << sVideoFileInput << std::endl;
				}
				else
				{
					break;
				}
			}
			else if (sVideoFileInput.find(sVideoFind) < 0)
			{
				getline(iMovieInfo, sVideoFileInput);
			}
		}
		if (sVideoFound == "false")
		{
			std::cout << "The movie was not found." << std::endl;
		}

		std::cout << std::endl;
		std::cout << "Would you like to find another movie? Y for yes, N for no: ";
		std::cin >> cVideoSearchContinue;
		std::cin.ignore(1, '\n');
		if (cVideoSearchContinue == 'Y' || cVideoSearchContinue == 'y')
		{
			iMovieInfo.close();
			sVideoFind.clear();
			sVideoFound = "false";
			system("cls");
			continue;
		}
		else
		{
			system("cls");
			iMovieInfo.close();
			movieMenu();
			break;
		}
	}
}

void videoType::numberOfCopies()
{
	while (true)
	{
		std::cout << "Please enter the name of the movie you would like to check the stock for: ";
		std::cin >> sMovieToFind;

		sMovieData = getVideoDetails(sMovieToFind);

		iCopyPosition = sMovieData.find_last_of('/');

		std::cout << "There are " << sMovieData.substr(iCopyPosition - 1, iCopyPosition + 1) << " copies of " << sMovieToFind << " in stock." << std::endl;
		system("pause");

		std::cout << "Would you like to search for another movie? Y for yes, N for no: ";
		std::cin >> cCopiesContinue;

		if (cCopiesContinue == 'Y' || cCopiesContinue == 'y')
		{
			continue;
		}
		else
		{
			break;
		}
	}
}

void videoType::returnCopy(std::string sReturnMovieTitle)
{
	while (true)
	{
		sReturnMovieInfo = getVideoDetails(sReturnMovieTitle);

		if (sReturnMovieInfo == "false")
		{
			std::cout << "Movie could not be returned" << std::endl;
			system("pause");
			break;
		}

		sReturnMovieInfoTemp = sReturnMovieInfo;

		iPositionOfCopies = sReturnMovieInfo.find_last_of('/') - 1;

		iNumberOfOldCopies = std::stoi(sReturnMovieInfo.substr(iPositionOfCopies));

		iNumberOfNewCopies = iNumberOfOldCopies + 1;

		sReturnMovieInfo.replace(iPositionOfCopies, 1, std::to_string(iNumberOfNewCopies));

		iMovieInfo.open(movieFile);

		while (iMovieInfo.good())
		{
			getline(iMovieInfo, sReturnMovieDatabaseImport);
			sReturnMovieDatabase.append(sReturnMovieDatabaseImport + '\n');
		}

		iMovieInfo.close();

		size_t moviePosition = sReturnMovieDatabase.find(sReturnMovieInfoTemp);

		sReturnMovieDatabase.replace(moviePosition, std::string(sReturnMovieInfoTemp).length(), sReturnMovieInfo);

		oMovieInfo.open(movieFile);

		oMovieInfo << sReturnMovieDatabase << std::endl;

		oMovieInfo.close();

		sReturnMovieDatabase.clear();

		break;
	}
}

void videoType::rentCopy(std::string sRentMovieTitle)
{
	while (true)
	{
		sRentMovieInfo = getVideoDetails(sRentMovieTitle);

		if (sRentMovieInfo == "false")
		{
			std::cout << "Movie could not be rented." << std::endl;
			system("pause");
			break;
		}

		sRentMovieInfoTemp = sRentMovieInfo;

		iPositionOfRented = sRentMovieInfo.find_last_of('/') - 1;

		iNumberOfRented = std::stoi(sRentMovieInfo.substr(iPositionOfRented));

		if (iNumberOfRented == 0)
		{
			std::cout << "The max number of copies has been rented out." << std::endl;
			system("pause");
			break;
		}

		iNewNumberOfRented = iNumberOfRented - 1;

		sRentMovieInfo.replace(iPositionOfRented, 1, std::to_string(iNewNumberOfRented));

		iMovieInfo.open(movieFile);

		while (iMovieInfo.good())
		{
			getline(iMovieInfo, sRentMovieDatabaseImport);
			sRentMovieDatabase.append(sRentMovieDatabaseImport + '\n');
		}

		iMovieInfo.close();

		size_t moviePosition = sRentMovieDatabase.find(sRentMovieInfoTemp);

		sRentMovieDatabase.replace(moviePosition, std::string(sRentMovieInfoTemp).length(), sRentMovieInfo);

		oMovieInfo.open(movieFile);

		oMovieInfo << sRentMovieDatabase << std::endl;

		oMovieInfo.close();

		sRentMovieDatabase.clear();

		sRented = "true";

		break;
	}
}

void videoType::removingExtraLines()
{
	iMovieInfo.open(movieFile);

	while (iMovieInfo.good())
	{
		getline(iMovieInfo, sMovieDatabaseImport);
		sMovieDatabase.append(sMovieDatabaseImport + '\n');
	}

	iMovieInfo.close();

	size_t emptyLinePosition;
	while ((emptyLinePosition = sMovieDatabase.find("\n\n", 0)) != std::string::npos)
	{
		sMovieDatabase.erase(emptyLinePosition, 1);
	}

	oMovieInfo.open(movieFile);

	oMovieInfo << sMovieDatabase;

	oMovieInfo.close();

	sMovieDatabase.clear();
}

std::string videoType::getVideoDetails(std::string sMovieGet)
{
	while (true)
	{
		system("cls");
		iMovieInfo.open(movieFile);
		while (iMovieInfo.good())
		{
			getline(iMovieInfo, sInputVideo);
			if (sInputVideo.find(sMovieGet) != sInputVideo.npos)
			{
				sMovieFound = "true";
				iMovieInfo.close();
				return sInputVideo;
			}
			else if (sInputVideo.find(sMovieGet) < 0)
			{
				getline(iMovieInfo, sInputVideo);
			}
		}
		if (sMovieFound == "false")
		{
			std::cout << "The movie was not found.";
			iMovieInfo.close();
			system("pause");
			return "false";
		}
		else
		{
			break;
		}
	}
}

std::string videoType::getAllMovies()
{
	sFullMovies.clear();
	iMovieInfo.open(movieFile);
	while (iMovieInfo.good())
	{
		getline(iMovieInfo, sFullMoviesImport);
		sFullMovies.append(sFullMoviesImport + '\n');
	}

	iMovieInfo.close();

	return sFullMovies;
}


