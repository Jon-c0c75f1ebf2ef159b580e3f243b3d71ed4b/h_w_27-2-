#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Logger
{
public:
	Logger();

	~Logger();

	void record(const std::string& sender, const std::string& recipient, const std::string& message);

	void reading();

private:
	std::fstream _file;
};
