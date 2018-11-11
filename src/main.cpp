
#include "../include/TextParser.hpp"
#include "../include/Node.hpp"

#include <iostream>
#include <map>
#include <limits>

std::string parseString(const std::vector<std::string> tokens, int offset) {
	std::string temp = "";
	for (int i = offset; i < int(tokens.size()); ++i) {
		if (tokens[i] == "\\n") {
			temp += '\n';
			continue;
		} else if (tokens[i] == "\\t") {
			temp += '\t';
		} else {
			temp += tokens[i];
		}

		if (i + 1 < int(tokens.size()))
			temp += " ";
	}
	return temp;
}

int main()
{
	std::map<std::string, Node> nodes;

	/***** LOAD FROM FILE *****/
	TextParser tp("../assets/example.txt");
	std::string currentNode = "";
	for (int i = 0; i < int(tp.size()); ++i) {
		auto tokens = tp.getLine(i);

		if (tokens.size() == 0) continue;

		if (tokens[0] == "node" && tokens.size() > 1) {
			if (!nodes.empty() && nodes[currentNode].needsDefault())
				nodes[currentNode].setDefaultNextNode(tokens[1]);
			currentNode = tokens[1];
			nodes[currentNode].setName(tokens[1]);
		}  else if (tokens[0] == "dialogue" && tokens.size() > 1) {
			std::string temp = parseString(tokens, 1);
			nodes[currentNode].setDialogue(temp);
		} else if (tokens[0] == "choice" && tokens.size() > 1) {
			std::string temp = parseString(tokens, 2);
			nodes[currentNode].addChoice(tokens[1], temp);
		} else if (tokens[0] == "default" && tokens.size() > 1) {
			nodes[currentNode].setDefaultNextNode(tokens[1]);
		}
	}

	if (nodes[currentNode].needsDefault()) {
		nodes[currentNode].setDefaultNextNode("end");
	}


	/**** INITIATE TEXT ADVENTURE *****/
	currentNode = "start";
	while (true) {
		if (currentNode == "end") break;

		Node node = nodes[currentNode];
		std::cout << node.getDialogue() << std::endl;

		switch(node.getNumChoices()) {
			case 0:
				if (node.isDefault()) {
					std::cout << "Press Enter to continue..." << std::endl;
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
					currentNode = node.getDefaultNextNode();
					continue;
				} else {
					// I don't know how you get here so exit
					currentNode = "end";
					continue;
				}
			case 1:
				std::cout << "\t" + node.getChoiceText(0) << std::endl;
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
				currentNode = node.getChoiceNextNode(0);
				continue;
			default:
				for (int i = 0; i < node.getNumChoices(); ++i) {
					std::cout << "\t(" << i << ") " << node.getChoiceText(i) << std::endl;
				}
		}


		std::cout << std::endl;
		int choiceNum = -1;
		do {
			std::cin >> choiceNum;
			if (!std::cin) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			}
		} while (choiceNum < 0 || choiceNum >= node.getNumChoices());
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

		currentNode = node.getChoiceNextNode(choiceNum);
	}

	return 0;
}