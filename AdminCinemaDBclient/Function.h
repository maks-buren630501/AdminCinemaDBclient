#include<iostream>
#include<list>
#include<string>

using std::cout;
using std::endl;
using std::string;
using std::list;





int checkUser(const char* nickname, list<string> listOfUsers);

list<int> getFreePlacesList(list<int> listOfBusyPlaces, int sizeOfHall);

string getStringOfFreePlaces(list<int> freePlaces);

string getNameFromRequest(string request);

string getFirstParametrFromRequest(string request);

string getSecondParametrFromRequest(string request);

string getParameterByNumber(string request, int number);

list<Film> getListOfFilmFromAnswer(string answer);


