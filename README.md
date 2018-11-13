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

### Valid Instructions
- "*node &lt;nodeName&gt;*"			-	create a new node
- "*dialogue &lt;displayedText&gt;*"			-	add dialogue (multiple calls adds newlines)
- "*choice &lt;nodeName&gt; &lt;displayedText&gt;*"	-	offer a choice and jump to that node if chosen
- "*default &lt;nodeName&gt;*"		-	the default jump (unnecessary if sequential). Note only works on zero-choice nodes

### Notes
- "start" is the name of the initial node
- "end" is the name of the final node which calls exit (no dialogue display)
- In &lt;displayedText&gt; the strings "\n" or "\t" fulfill their character equivalents (when separated on either side by spaces)
