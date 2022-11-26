#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        unordered_set<string> unique_words(words.begin(), words.end());
        vector<string> ans;
        for (const string &word : unique_words)
            if (exist(board, word))
                ans.push_back(word);
        return ans;
    }
private:
    int w;
    int h;
    bool exist(vector<vector<char>> &board, string word)
    {
        if (board.size() == 0) return false;
        h = board.size();
        w = board[0].size();
        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++)
                if (search(board, word, 0, i, j)) return true;
        return false;
    }

    bool search(vector<vector<char>> &board,
        const string &word, int d, int x, int y)
    {
        if (x < 0 || x == w || y < 0 || y == h || word[d] != board[y][x])
            return false;

        // Found the last char of the word
        if (d == word.length() - 1)
            return true;

        char cur = board[y][x];
        board[y][x] = '#';
        bool found = search(board, word, d + 1, x + 1, y)
            || search(board, word, d + 1, x - 1, y)
            || search(board, word, d + 1, x, y + 1)
            || search(board, word, d + 1, x, y - 1);
        board[y][x] = cur;
        return found;
    }
};
int main()
{
    Solution s; 
    
    vector<vector<char>> board {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };


    vector<string> words {"oath", "pea", "eat", "rain"};

    for (const auto &v : s.findWords(board, words))
    {
        cout<<v<<' ';
    }

	return 0;
}