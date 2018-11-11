# Hackathon2018
### A collaboration between a Biologist, a Physicist, and a Computer Engineer

## Steps to compile (Note that this method requires cmake 2.6 or later to be installed)
1. Create a new folder in the project folder called 'build'.
2. navigate into /build
3. 'cmake ..'
4. 'make'
5. Run the Hackathon game


## Text Adventure File Format
Note all whitespace is ignored (spaces, tabs, newlines, etc.). Anything after a '#' is ignored so use this for comments.

### Valid Commands
- "*node nodeName*"			-	create a new node
- "*dialogue msg*"			-	add dialogue (multiple calls adds newlines)
- "*choice nodeName msg*"	-	offer a choice and jump to that node if chosen
- "*default nodeName*"		-	the default jump (unnecessary if sequential). Note only works on zero-choice nodes

### Notes
node start 					- the initial node
node end 					- the final node, calls exit (no dialogue display)
In choice or dialogue (in <str>) you can have "\n" or "\t" (separated by spaces)