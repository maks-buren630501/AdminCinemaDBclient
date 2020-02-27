#pragma once

class Film
{
private:
	string title;
	string country;
	string date;
public:
	Film(const char* title, const char* country, const char* date)
	{
		this->title = title;
		this->country = country;
		this->date = date;
	}

	string getTitle()
	{
		return title;
	}

	string getCountry()
	{
		return country;
	}

	string getDate()
	{
		return date;
	}
};
