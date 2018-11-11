#include "../include/Node.hpp"

Node::Node()
:	_name(""), _dialogue(""), _choices(0) { }

Node::Node(const std::string & name)
:	_name(name), _dialogue(""),	_choices(0) { }

void Node::setName (const std::string & name) {
	_name = name;
}

void Node::setDialogue(const std::string & dialogue) {
	if (_dialogue == "") {
		_dialogue = dialogue;		
	} else {
		_dialogue += "\n" + dialogue;
	}
}

void Node::addChoice(const std::string & next_node, const std::string & choice_text) {
	_choices.push_back(std::make_pair(next_node, choice_text));
}

void Node::setDefaultNextNode(const std::string & defaultNextNode) {
	_defaultNextNode = defaultNextNode;
}

const std::string & Node::getName() const{
	return _name;
}

const std::string & Node::getDialogue() const {
	return _dialogue;
}

int Node::getNumChoices() const {
	return int(_choices.size());
}

const std::string & Node::getChoiceText(int i) const {
	return _choices[i].second;
}

const std::string & Node::getChoiceNextNode(int i) const {
	return _choices[i].first;
}

const std::string & Node::getDefaultNextNode() const {
	return _defaultNextNode;
}

bool Node::needsDefault() const {
	return _defaultNextNode == "" && getNumChoices() == 0;
}

bool Node::isDefault() const {
	return _defaultNextNode != "";
}