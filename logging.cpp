#include "logging.h"

	Logging::Logging()
	{
		_file = std::fstream("log.txt", std::ios::out | std::ios::app); //std::ios::in |

		if (!_file) {
			// Для создания файла используем параметр ios::trunc
			_file = std::fstream("log.txt", std::ios::in | std::ios::out | std::ios::trunc);
		}
	}

	Logging::~Logging() {
		_file.close();
	}

	void Logging::record(const std::string& sender, const std::string& recipient, const std::string& message) {

		if (_file) {
			_file << sender + " " + recipient + " " + message + "\n";
			_file.close();
		}
		else {
			std::cout << "eror logging\n";
		}

	}

	void Logging::reading() {
		_file = std::fstream("log.txt", std::ios::in); // | std::ios::app ; ate - переходите к концу потока сразу после открытия

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
