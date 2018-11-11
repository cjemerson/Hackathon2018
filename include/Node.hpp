
#ifndef FILE_NODE_HPP_INCLUDED
#define FILE_NODE_HPP_INCLUDED

#include <string>
// For std::string
#include <utility>
// For std::pair and std::make_pair
#include <vector>
// For std::vector

class Node {
public:
	Node();

	Node(const std::string & name);
	void setName (const std::string & name);

	void setDialogue(const std::string & dialogue);

	void addChoice(const std::string & next_node, const std::string & choice_text);

	void setDefaultNextNode(const std::string & defaultNextNode);

	const std::string & getName() const;

	const std::string & getDialogue() const;

	int getNumChoices() const;

	const std::string & getChoiceText(int i) const;

	const std::string & getChoiceNextNode(int i) const;

	const std::string & getDefaultNextNode() const;

	bool needsDefault() const;

	bool isDefault() const;

private:
	std::string _name, _dialogue, _defaultNextNode;
	std::vector<std::pair<std::string, std::string> > _choices;
};

#endif // #ifndef FILE_NODE_HPP_INCLUDED