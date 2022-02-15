#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


string PATH_TO_FILE = "D:\\Homework\\OOP\\lab_01\\timetable.csv";
bool ORDER_BY_CLASSROOM = true;

string strip(string str) {
    if (!str.empty() && str[str.length()-1] == '\r') {
        str.erase(str.length()-2);
    }
    return str;
}

vector<string> split(const string& str, char delim)
{
    vector<string> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            end = str.find(delim, start);
            tokens.push_back(str.substr(start, end - start));
            start = end + 1;
        } while (end != string::npos);
    }

    return tokens;
}

int main()
{
    string classroom;
    if (ORDER_BY_CLASSROOM) {
        cin >> classroom;
    }
    fstream file;
    file.open(PATH_TO_FILE, ios::binary | ios::in);
    for (string line; getline(file, line);)
    {
        string result_string;
        string id;
        vector<string> row = split(line, ';');
        id = row[0];
        row.erase(row.begin());
        for (const auto &s : row)
            result_string += strip(s) + " - ";
        if (ORDER_BY_CLASSROOM) {
            if (result_string.find(classroom) != string::npos) {
                result_string = id + " - " + result_string;
                cout << result_string.substr(0, result_string.length() - 3) << '\n';
            }
        }
        else {
            result_string = id + " - " + result_string;
            cout << result_string.substr(0, result_string.length() - 3) << '\n';
        }
    }
    file.close();

    return 0;
}
