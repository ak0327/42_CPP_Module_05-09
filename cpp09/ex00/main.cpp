#include <iostream>

#include "BitcoinExchange.hpp"

const char *get_input_file_path(int argc, char **argv) {
	const std::size_t INPUT_FILE_IDX = 1;
	std::string error_msg;

	if (argc == 2) {
		return argv[INPUT_FILE_IDX];
	}
	error_msg = "Invalid argument. How to execute: \"./btc <input_file>\"";
	throw std::invalid_argument(error_msg);
}

int main(int argc, char **argv) {
	const char *input_file_path;
	std::string error_msg;

	try {
		input_file_path = get_input_file_path(argc, argv);

		BitcoinExchange btc;
		btc.exchange(input_file_path);

		// BitcoinExchange btc2 = btc;
		// btc2.exchange(input_file_path);

		// BitcoinExchange btc3 = BitcoinExchange(btc);
		// btc3.exchange(input_file_path);

	} catch (const std::exception &e) {
		std::cout << "[Error]: " << e.what() << std::endl;
	}
	return 0;
}
