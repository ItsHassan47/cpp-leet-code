#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Boggle
{
public:
	bool wordExist(vector<vector<char>> &board, string &word)	// check if the word exist on the board
	{
		if (word.empty())
			return false;
		if (board.empty() || board[0].empty())
			return false;

		rows = board.size();
		cols = board[0].size();
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {	// traverse the board to find the first character
				if (searchWords(board, word, 0, i, j))
					return true;
			}
		}
		return false;
	}

private:
	int rows;
	int cols;
	bool searchWords(vector<vector<char>> &board, string &word, int index, int i, int j)
	{
		if (i < 0 || i >= rows || j < 0 || j >= cols || word[index] != board[i][j])
			return false;
		if (index == word.length() - 1)
			return true;  // found the last character

		char visited = board[i][j];
		board[i][j] = '*';  // used

		bool found = searchWords(board, word, index + 1, i + 1, j)	// next row
			|| searchWords(board, word, index + 1, i - 1, j)		// previous row
			|| searchWords(board, word, index + 1, i, j - 1)		// previous col
			|| searchWords(board, word, index + 1, i, j + 1)		// next col
			|| searchWords(board, word, index + 1, i - 1, j - 1)	// previous row and previous col
			|| searchWords(board, word, index + 1, i + 1, j + 1)	// next row and next col
			|| searchWords(board, word, index + 1, i - 1, j + 1)	// previous row and next col
			|| searchWords(board, word, index + 1, i + 1, j - 1);	// next row and previous col

		board[i][j] = visited;  // reset
		return found;
	}
};

void showInstructions();	// display instructures
void constructBoard(vector<vector<char>> &board);	// constructs a board according to user input
void displayBoard(const vector<vector<char>> &board);	// print the board to the console
void readFromDictionary(vector<string> &words);	// read from the file dictionary.txt and stroe in the array
void getHumanWords(vector<string> &result, const vector<string> &valid_words);	// let user solve the puzzle
bool isWord(const vector<string> &result, const string &word);	// check if word enter by user exist on the board or not
void displayResults(const vector<string> &result);	// display the words
int calculateScore(const vector<string> &result);	// calculae the score


int main()
{
	Boggle b;
	vector<vector<char>> board {
		{'g', 'n', 'e', 's'},
		{'s', 'r', 'i', 'p'},
		{'e', 't', 'a', 'l'},
		{'t', 's', 'e', 'b'}
	};

	showInstructions();
	constructBoard(board);
	displayBoard(board);

	vector<string>dictionaryWords;	// stores the all the from the dictionary
	readFromDictionary(dictionaryWords);

	vector<string>valid_words;
	for (int i = 0; i < dictionaryWords.size(); i++) {
		if (b.wordExist(board, dictionaryWords[i]))
			valid_words.push_back(dictionaryWords[i]);
	}

	vector<string>human_words;
	getHumanWords(human_words, valid_words);
	cout << "\nHuman words count is: " << human_words.size();
	cout << "\nHuman Score is: " << calculateScore(human_words) << endl;
	displayResults(human_words);

	cout << "\nComputer's Turn" << endl;
	cout << "Computer words count is: " << valid_words.size() << endl;
	cout << "\Computer Score is: " << calculateScore(valid_words) << endl;
	displayResults(valid_words);

	return 0;
}

// display instructures
void showInstructions()
{
	string choice;
	cout << "Do you need instruction? ";
	cin >> choice;
	if (choice == "y" || choice == "Y" || choice == "yes")
	{
		cout << "The boggle board is a grid of letters on which you try to form words. You go first, entering all the words you can find that are formed by tracing adjoining letters. Two letters adjoin if they are next to each other horizontally, vertically. A letter can only be used once in each word. Words must be at least four letters long and can be counted only once." << endl << endl;
	}
}

// constructs a board according to user input
void constructBoard(vector<vector<char>> &board)
{
	string choice;
	cout << "Do you want to force the board configuration? ";
	cin >> choice;
	if (choice == "y" || choice == "Y" || choice == "yes") {
		cout << "Enter a 16-character string to identify which letters you want on the board. The first 4 characters form the top row, the next 4 characters form the second row, and so forth." << '\n' << "Enter the string: ";

		for (int i = 0; i < board.size(); ++i)
			for (int j = 0; j < board[0].size(); ++j)
				cin >> board[i][j];
	}
}

// print the board to the console
void displayBoard(const vector<vector<char>> &board)
{
	cout << " ________________" << endl;
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j) {
			cout << "| " << board[i][j] << ' ';
		}
		cout << '|' << endl;
	}
	cout << " ________________" << endl;
}

// read from the file dictionary.txt and stroe in the array
void readFromDictionary(vector<string> &dictionaryWords)
{
	ifstream dictionary {"dictionary.txt"};
	if (!dictionary) {
		cerr << "Error opening dictionary.txt" << endl;
		return;
	}
	string word;
	while (getline(dictionary, word)) {
		if (word.size() > 3)
			dictionaryWords.push_back(word);
	}
}

// let user solve the puzzle
void getHumanWords(vector<string> &human_words, const vector<string> &valid_words)
{
	string input;
	cout << "\nYour Turn started press 'q' to end Your turn" << endl;
	while (true) {
		cout << "\nWord: ";
		cin >> input;
		if (input == "q")
			break;
		if (input.size() < 4)
			cout << "Sorry, that isn't long enough to even be considered." << endl;
		else if (isWord(valid_words, input)) {
			cout << "word added." << endl;
			human_words.push_back(input);
		}
		else
			cout << "That word can't be constructed with this board." << endl;
	}
}

// check if word enter by user exist on the board or not
bool isWord(const vector<string> &result, const string &word)
{
	for (int i = 0; i < result.size(); ++i) {
		if (word == result[i])
			return true;
	}
	return false;
}

// display the words
void displayResults(const vector<string> &result)
{
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
}

// calculae the score
int calculateScore(const vector<string> &result)
{
	int score = 0;
	for (int i = 0; i < result.size(); ++i) {
		if (result[i].size() == 4)
			score += 1;
		else if (result[i].size() == 5)
			score += 2;
		else if (result[i].size() == 6)
			score += 3;
		else if (result[i].size() == 7)
			score += 5;
		else if (result[i].size() > 7)
			score += 11;
	}
	return score;
}