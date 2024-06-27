#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Logging
{
public:
	Logging();

	~Logging();

	void record(const std::string& sender, const std::string& recipient, const std::string& message);

	void reading();

private:
	std::fstream _file;
};
