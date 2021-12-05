#include <iostream>
#include <vector>
#include <array>

using namespace std;

vector<int> split2int(string s, char delimiter);
vector<int> find_win(vector<int> numbers, vector<int> board);
vector<int> slice(vector<int> arr, int begin, int end);
int get_sum_of_rest(vector<int> test, vector<int> board);
bool test_line(vector<int> test, vector<int> line);
bool includes(vector<int> arr, int key);
int calculate_sum_of_rest(vector<int> line_win, vector<int> board);

int main()
{
    string line;
    getline(cin, line);
    string numbers_str = line;
    vector<int> numbers = split2int(numbers_str, ',');

    vector<int> results;
    int max_index = 0;
    int score = 0;
    string board_str;
    while (cin)
    {
        getline(cin, line);
        if ((line == "" || cin.eof()) && board_str != "")
        {
            board_str += line;
            vector<int> board = split2int(board_str, ' ');
            results = find_win(numbers, board);
            if (results.size() > 0)
            {
                int index = results[0];
                if (index > max_index)
                {
                    max_index = index;
                    score = results[1];
                }
            }
            board_str = "";
            if (cin.eof())
                break;
        }
        else
        {
            board_str = board_str + line + " ";
        }
    }

    cout << score << endl;
    return 0;
}

vector<int> split2int(string s, char delimiter)
{
    string value;
    vector<int> arr;
    for (int i = 0; i < s.length(); i++)
    {
        char l = s[i];
        if (l == delimiter && value != "")
        {
            arr.push_back(stoi(value));
            value = "";
        }
        else
        {
            value += l;
        }
    }
    if (value != "")
    {
        arr.push_back(stoi(value));
    }
    return arr;
}

vector<int> find_win(vector<int> numbers, vector<int> board)
{
    vector<int> arr;
    for (int i = 5; i <= numbers.size(); i++)
    {
        vector<int> test = slice(numbers, 0, i);
        int sum = get_sum_of_rest(test, board);
        if (sum > 0)
        {
            arr.push_back(i);
            arr.push_back(sum * test[i - 1]);
            return arr;
        }
    }
    return arr;
}

vector<int> slice(vector<int> arr, int begin, int end)
{
    vector<int> arr_slice;
    for (int i = begin; i < end; i++)
    {
        arr_slice.push_back(arr[i]);
    }
    return arr_slice;
}

int get_sum_of_rest(vector<int> test, vector<int> board)
{
    int board_side = 5;
    for (int i = 0; i < board_side; i++)
    {
        vector<int> row = slice(board, i * board_side, (i + 1) * board_side);
        bool is_win = test_line(test, row);
        if (is_win)
        {
            return calculate_sum_of_rest(test, board);
        }
    }
    for (int i = 0; i < board_side; i++)
    {
        vector<int> col;
        for (int j = i; j < board.size(); j = j + board_side)
        {
            col.push_back(board[j]);
        }
        bool is_win = test_line(test, col);
        if (is_win)
        {
            return calculate_sum_of_rest(test, board);
        }
    }
    return 0;
}

bool test_line(vector<int> test, vector<int> line)
{
    int count = 0;
    for (int i = 0; i < line.size(); i++)
    {
        if (includes(test, line[i]))
        {
            count++;
        }
    }
    return count == line.size();
}

bool includes(vector<int> arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
            return true;
    }
    return false;
}

int calculate_sum_of_rest(vector<int> line_win, vector<int> board)
{
    int sum = 0;
    for (int i = 0; i < board.size(); i++)
    {
        if (!includes(line_win, board[i]))
        {
            sum += board[i];
        }
    }
    return sum;
}