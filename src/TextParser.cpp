 // TextParser.cpp

#include "../include/TextParser.hpp"
// #include <iostream>

TextParser::TextParser(const std::string & path) {
	std::ifstream input(path);
	_name = getResourceName(path);

	if (!input.is_open()) {
		throw "Unable to open (" + _name + ").";
		// @TODO
		// std::cout << "Failed to open " << path << "." << std::endl;
	} else {
		std::string line;
		while (std::getline(input, line)) {
			std::vector<std::string> tokens;
			std::istringstream lineParser(line);
			std::string token;
			while (!lineParser.eof()) {
				lineParser >> token;
				if (lineParser.fail())
					break;
				if (token[0] == '#') {
					break;
				}
				tokens.push_back(token);
			}
			if (tokens.size() > 0) _data.push_back(tokens);
		}
	}
}

std::string TextParser::getResourceName(std::string path) {
	auto pos = path.rfind('/');
	if (pos == std::string::npos)
		return path;
	return path.substr(pos + 1);
}

const std::vector<std::string> & TextParser::getLine(int index) const {
	return _data[index];
}

int TextParser::size() const {
	return int(_data.size());
}

// May throw std::invalid_argument if the conversion cannot be performed
// May throw std::out_of_range if the conversion results in overflow (token is too big for int type)
int TextParser::parseInt(const std::string & token) {
	return std::stoi(token);
}

// May throw std::invalid_argument if the conversion cannot be performed
// May throw std::out_of_range if the conversion results in overflow (token is too big for int type)
float TextParser::parseFloat(const std::string & token) {
	return std::stof(token);
}

sf::Vector2f TextParser::parseVector2f(const std::vector<std::string> & tokens) {
	float x = (tokens.size() > 1)? parseFloat(tokens[1]): 0;
	float y = (tokens.size() > 2)? parseFloat(tokens[2]): 0;
	return sf::Vector2f(x, y);
}

sf::Vector2i TextParser::parseVector2i(const std::vector<std::string> & tokens) {
	int x = (tokens.size() > 1)? parseInt(tokens[1]): 0;
	int y = (tokens.size() > 2)? parseInt(tokens[2]): 0;
	return sf::Vector2i(x, y);
}