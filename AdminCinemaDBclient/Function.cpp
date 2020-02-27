#include"Function.h"
#include"Film.h"




int checkUser(const char* nickname, list<string> listOfUsers)
{

	std::list<string>::iterator iterator = std::find(listOfUsers.begin(), listOfUsers.end(), string(nickname));
	if (iterator == listOfUsers.end())
	{
		return -1;
	}
	else
	{
		return 1;
	}
}

list<int> getFreePlacesList(list<int> listOfBusyPlaces, int sizeOfHall)
{
	list<int> allPlacesList;
	int flag = 0;
	for (int i = 1; i < sizeOfHall + 1; i++)
	{
		if (std::find(listOfBusyPlaces.begin(), listOfBusyPlaces.end(), i) != listOfBusyPlaces.end())
		{
			continue;
		}
		else
		{
			allPlacesList.push_back(i);
		}
	}
	return allPlacesList;

}

string getStringOfFreePlaces(list<int> freePlaces)
{
	string freePlaceString;
	for (int i : freePlaces)
	{
		freePlaceString += std::to_string(i) + "|";
	}
	freePlaceString += "\n";
	return freePlaceString;
}

string getNameFromRequest(string request)
{
	string Name;
	int beginOfName = request.find("|") + 1;
	Name = request.substr(beginOfName, request.size() - beginOfName - 1);
	return Name;
}

string getFirstParametrFromRequest(string request)
{
	string FirstParametr;
	int beginOfFirstParametr = request.find("|") + 1;
	string parametrs = request.substr(beginOfFirstParametr, request.size() - beginOfFirstParametr);
	int endOfFirstParametr = parametrs.find("|");
	FirstParametr = parametrs.substr(0, endOfFirstParametr);
	return FirstParametr;
}

string getSecondParametrFromRequest(string request)
{
	string secondParametr;
	int beginOfFirstParametr = request.find("|") + 1;
	string parametrs = request.substr(beginOfFirstParametr, request.size() - beginOfFirstParametr);
	int beginOfLastParametr = parametrs.find("|") + 1;
	secondParametr = parametrs.substr(beginOfLastParametr, parametrs.size() - beginOfLastParametr - 1);
	return secondParametr;
}

string getParameterByNumber(string request, int number)
{
	while (true)
	{
		number--;
		int endOfFirstParam = request.find("|");
		if (number == 0)
		{
			return request.substr(0, endOfFirstParam);
		}
		else
		{
			return getParameterByNumber(request.substr(endOfFirstParam + 1, request.size() - endOfFirstParam), number);
		}
	}
}

//need to add
list<Film> getListOfFilmFromAnswer(string answer)
{
	string temp;
	list<Film> listOfFilm;
	for (int i = 0; i < answer.size(); i++)
	{
		if (answer[i] == '|')
		{
			
		}
	}
	return listOfFilm;
}