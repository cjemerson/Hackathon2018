// TextParser.hpp

#ifndef FILE_TEXTPARSER_HPP_INCLUDED
#define FILE_TEXTPARSER_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include <vector>
#include <fstream>
#include <sstream>
#include <string>

class TextParser {
public:
	TextParser(const std::string & path);
	const std::vector<std::string> & getLine(int index) const;
	int size() const;

	static std::string getResourceName(std::string path);
	static int parseInt(const std::string & token);
	static float parseFloat(const std::string & token);
	static sf::Vector2f parseVector2f(const std::vector<std::string> & tokens);
	static sf::Vector2i parseVector2i(const std::vector<std::string> & tokens);

private:
	std::string _name;
	std::vector< std::vector<std::string> > _data;
};

#endif // #ifndef FILE_TEXTPARSER_HPP_INCLUDED