#include "Logger.h"

Logger::Logger()
{
	_file = std::fstream("log.txt", std::ios::out | std::ios::app);

	if (!_file) {
		// ios::trunc
		_file = std::fstream("log.txt", std::ios::in | std::ios::out | std::ios::trunc);
	}
}

Logger::~Logger() {
	_file.close();
}

void Logger::record(const std::string& sender, const std::string& recipient, const std::string& message) {

	if (_file) {
		_file << sender + " " + recipient + " " + message + "\n";
		_file.close();
	}
	else {
		std::cout << "eror logging\n";
	}

}

void Logger::reading() {
	_file = std::fstream("log.txt", std::ios::in);

	if (!_file) {
		std::cout << "error reading log\n";
		return;
	}
	_file.seekg(std::ios_base::beg);
	if (_file.eof()) {
		return;
	}
	char ch = 'a';
	int exit = 10000; //freeze protection
	while (exit) {
		_file.get(ch);
		if (ch == '\n' || _file.eof()) {
			std::cout << '\n';
			return;
		}
		std::cout << ch;
		--exit;
	}
}
