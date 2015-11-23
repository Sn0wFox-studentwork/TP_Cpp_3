#pragma once
#include <string>

class PageInternet
{
public:
	PageInternet();
	~PageInternet();
	std::string GetRacine() const;
	std::string GetExtension() const;
	std::string GetType() const;
};

