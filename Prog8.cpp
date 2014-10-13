/*
Arlen D'Arcy

Write a C++ program that:
Reads a user-specified text file into a list of strings
Displays a menu of options to the user:
Searches for a user-specified word/phrase (string) in the document (list of strings)
if the word/phrase is found, the line (string) containing the word/phrase is displayed
otherwise, a message (e.g., "hello" not found)
Prints (displays) the document on the screen
Searches for a user-specified word/phrase (string) in the document (list of string)
if the word/phrase is found, replaces it with another user-specified word/phrase
otherwise, a message (e.g., "hello" not found)
Quits (exits) the program
Assignment Notes
You can implement the document (list of strings) as either a vector of strings or a partially-filled array of strings.
It is recommended that you write a function (or function template) for each of the menu items (except for the quit option).
To read a text file into the list of strings, use:
A while loop with the input stream good() member function.
In the while loop body, call the getline() standalone function with the file input stream (ifstream) object to read each line of the file as a string, and add the string to the list of strings.
After each input from the cin stream using the extraction (input; >>) operator (such as getting a word/phrase to search for), you should call the cin.clear() and cin.ignore() member function prior to calling the getline() function with the cin stream.
The string find member function returns the position of the string parameter as a value of the type size_t.  If the string parameter is not found in the string for which the find member function is called, the predefined value string::npos is returned.
To replace one substring with another in a string, you can use the string member function replace().

*/

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>

using namespace std;

//Function Declatations

void find(vector<string> file, string target, int& index, size_t& pos);

void replace(vector<string>& file, string target, int& index, size_t& pos);

void print(vector<string> file);

const int NOT_FOUND = -1;

int main()
{
	// String Variables
	string userFile,
		text,

		target;

	//Ints
	int line, index;

	//template
	size_t pos;



	//input stream var
	ifstream inStream;
	ofstream output;

	//Character Vars
	char user_choice;

	//vector declaration
	vector<string> file;

	cout << "Enter input file name: ";
	cin >> userFile;
	inStream.open(userFile.c_str());

	if(inStream.fail())
	{
		cout << "\nFailed to open the file restart the program and "
			<< "please enter the data file name\n";
		exit(1);
	}

	//Read file into vector
	if(inStream)
	{
		while(getline(inStream, text))
		{

			file.push_back(text);


		}//end while
		cout << "\n...Done Reading the file\n\n";

	}// end if


	do
	{
		cout << "Select an option:\n\n" << "\tf/F: search the document for a word/phrase\n" 
			<< "\tp/P: print the document on the screen\n"
			<< "\tq/Q: quit the program\n"
			<< "\tr/R: replace a word/phrase in the document\n\n"
			<<"enter your choice: ";

		cin >> user_choice;
		cout << endl;

		switch(user_choice)
		{
		case 'F':
		case 'f':
			cout << "\nSearch for ...? ";
			cin >> target;
			cout << "\nSearching for " << target << "...\n";
			find(file, target, index, pos);
			if(index == NOT_FOUND)
			{
				cout << "\nYour word was not found, try again\n";
				break;

			}
			else
			{
				cout << "\nFound: " << file[index] << endl << endl;
				break;
			}

			break;
		case 'p':
		case 'P':
			print(file);
			break;
		case 'r':
		case 'R':
			cout << "\nSearch for ...? ";
			cin >> target;
			cout << "\nSearching for " << target << "...\n";
			find(file, target, index, pos);
			if(index == NOT_FOUND)
			{
				cout << "\nYour word was not found, try again\n";
				break;

			}
			else
			{
				cout << "\nFound: " << file[index] << endl << endl;
				replace(file, target, index, pos);
			}

			break;
		case 'q':
		case 'Q':
			exit(1);
		default:
			cout << "Error...Please enter a option listed on the menu\n"; 
		}



	}while(user_choice != 'Q' || user_choice != 'q');

	return 0;
}//End Main

//function to print to the screen
void print(vector<string> file)
{
	for(unsigned int i = 0; i < file.size(); i++)
	{
		cout << file[i];
		cout << endl;
	}//end cout for loop




}// End Function to print file



//funtion to find a word
void find(vector<string> file, string target, int& index, size_t& pos)    ///, int& line, size_t& pos)
{
	for(index = 0; index < file.size(); index++)
	{
		pos = file[index].find(target);
		if (pos != string::npos)
		{
			break;
		}//end if 



	}//end for loop
	if(pos == string::npos)
	{
		index = NOT_FOUND;
	}//end if


}//end void find function


//funtion to replace a word
void replace(vector<string>& file, string target, int& index, size_t& pos)
{
	string newWord;
	cout << "\nReplace with ...? ";
	cin >> newWord;

	cout << file[index];

	file[index].replace(pos, target.size(), newWord);

	cout << "\n\nReplaced with " << file[index] << endl << endl;

}// end funtion to replace words