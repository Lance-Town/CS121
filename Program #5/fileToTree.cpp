/* fileToTree.cpp
 *
 * Holds the function definitions to unpacking the data from the input file and 
 * putting that data into the binary search tree
 * 
 *---------------------------------------------------------------------
 */

// System Includes
#include <fstream>
#include <iostream>

// User-Defined Includes
#include "fileToTree.h"
#include "binaryTree.h"

using namespace std;

// Returns which string comes first in the alphabet
int alphabeticalCompare(string a, string b) {
    // return values to signify the three different cases
    const int VALUES_EQUAL = 2;
    const int VALUE_A_GREATER = 1;
    const int VALUE_B_GREATER = 0;

    // remove blank spaces from the strings
    a = removeBlankSpace(a);
    b = removeBlankSpace(b);

    // compare the two values using std::string::compare
    int ret = a.compare(b);

    if (ret == 0) {
        return VALUES_EQUAL;
    } else if (ret < 0) {
        return VALUE_B_GREATER;
    } else {
        return VALUE_A_GREATER;
    }
}

// remove the blank space from a string, and return the 
// non-blank space result
string removeBlankSpace(string s) {
    string newString = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ')
            newString += s[i];
    }

    return newString;
}

// removes all blank spaces from a string after the last char
string removeEndBlankSpace(string s) {
    while (s.back() == ' ') {
        s.pop_back();
    }

    return s;
}

// get the substring from a string, based on the input results
void getSubString(string originalString, int first, int last, string& result) {
    for (int i = first; i < first+last; i++) {
        result += originalString[i];
    }
}

// get the index position of a char in a given string
int indexOf(string s, char c) {
    // initialize the index of string
    int i = 0;
    int lastChar = 0;
    
    // loop until the character is found
    for (i = 0 ; i < s.length(); i++) {
        if (s[i] == c){
            return i;
        }
    }

    // character not found, so return end of string
    return i;
}

// gets the title of the TV show
void getTitle(string& line, string& title) {
    int yearStart;

    yearStart = indexOf(line, '(');

    getSubString(line, 0, yearStart-1, title);

    // cout << "SERIES_NAME::title: |" << title << "|\n";
}

// get the years that a TV show aired from
void getYearsAired(string line, string& yearStart, string& yearEnd) {

    string tempString = "";
    string yearString = "";
    int tempYearStart = 0;
    int tempYearEnd = 0;

    tempYearStart = indexOf(line, '(');
    tempYearEnd = indexOf(line, ')');

    getSubString(line, tempYearStart+1, tempYearEnd-(tempYearStart+1), yearString);

    getSubString(yearString, 0, 4, tempString);
    yearStart = tempString;

    tempString = "";

    getSubString(yearString, 5, 4, tempString);
    yearEnd = tempString;

    return;
}

// read the input file and parse the data, storing each TVShow in the binary tree databsae
void parseFile(BinaryTree& tree) {
    ifstream inFile("TVShow.txt");

    if (!inFile.is_open()) {
        cout << "File unable to open\n"
             << "Terminating Program.\n";

        // the file isn't open, return with an erorr
        return;
    }

    // Get the max size of the actor array; declared in binaryTree.h
    extern const int MAX_ACTOR_COUNT;

    // initialize all of the input variables each TV show has
    string line = "";
    string title = "";
    string genre = "";
    string url = "";
    string actorName = "";
    string yearStart = "", yearEnd = "";

    int index;             // index of actors array

    while (getline(inFile, line)) {
        // error handling more than one space in the input file
        if (line == "")
            continue;

        // array to store all actors in the TV Show
        string actors[MAX_ACTOR_COUNT];

        // set the actor iterator to 0
        index = 0;

        // set the series name to be blank
        title = "";

        // get the series name
        getTitle(line, title);

        title = removeEndBlankSpace(title);

        // get the years the series aired from
        getYearsAired(line, yearStart, yearEnd);

        // get the series catagory and the series URL into their own strings
        getline(inFile, genre);
        getline(inFile, url);

        // Get the first actor
        getline(inFile, line);

        // add all actors to the actor array
        while (line != "") {
            // get next actor in show
            actorName = line;
            // cout << "Actor Name:\t|" << actorName << "|\n";

            // add them to actor array
            actors[index++] = actorName;
            getline(inFile, line);
        }

        // cout << "Inserting: " << title << '\n';
        tree.insertData(title, actors, index, yearStart, yearEnd, genre, url);

        // cout << "\n\n\n";
    }

    inFile.close();

    return;
}

// returns true if an actor is in the array of actors or not
bool actorInShow(string actors[], string actor) {
    for (int i = 0; i < MAX_ACTOR_COUNT; i++) {
        if (actors[i] == "")
            break;
        else if (actors[i] == actor)
            return true;
    }
    return false;
}