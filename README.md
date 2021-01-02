# Zackster-String
It is just the same as standart string in c++
main functions:

int compareABC(str& bufStr) // the same as strcmp()
int addSymb(char c) // adds symbol in the end of string
int size() // returns string's size with 0 char in the end
int reverse() //reverses string
char* line() // returns const char its used for output the string in console or anywhere else
you can create string in 3 ways:

1) str Example; //creates string with only one zero symbol
2) str Example = "Example"; //create string with char of symbols;
3) str a = "Example; 
   str Example = a; //create string with another string;
   
   
arithmetical operations:

str example;
str a = "Test2"
str b = "Test3"
example += "Example"; //adds const char to string;

example += a; //adds string from another string

example = a + b; //adds a string and b string into example string

example[i] // return i char from array

example[i] = 'c'; //changes i item in array
