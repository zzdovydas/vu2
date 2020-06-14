#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct WordCounter
{
    string word;
    vector<int> pos;
    int counter;

    WordCounter() : counter(0){}

};

int GetFileLineLength(string file)
{
    int numLines = 0;
    ifstream in(file.c_str());
    string unused;

    while (getline(in, unused))
       ++numLines;

    return numLines;
}

void ReadFileByLine(vector<string> &lines, string file)
{
    int numLines = 0;
    ifstream in(file.c_str());
    string text;

    while (getline(in, text))
    {
        lines.push_back(text);
        ++numLines;
    }
}

string CheckForIllegalCharacters(string word)
{

    if (word[word.length()-1] == ',' || word[word.length()-1] == '.' || word[word.length()-1] == '-' || word[word.length()-1] == ')' )
        word = word.replace(word.length()-1, 1, "");

    return word;
}

void ReadEachWord(vector<string> lines, vector<WordCounter> &wC)
{
    string word;
    for (int i = 0; i < lines.size(); i++)
    {
        istringstream iss(lines.at(i));
        string res;
        while(iss >> word)
        {

            bool doesExist = false;

            word = CheckForIllegalCharacters(word);

            for (int a = 0; a < wC.size(); a++)
            {
                if (wC.at(a).word == word)
                    doesExist = true;
            }

            if (doesExist)
            {
                for (int a = 0; a < wC.size(); a++)
                {
                    if (wC.at(a).word == word)
                    {
                        wC.at(a).counter++;
                        wC.at(a).pos.push_back(i);
                    }
                }
            }
            else if (!doesExist && word.length() > 1)
            {
                WordCounter wCO;
                wCO.word = word;
                wCO.pos.push_back(i);
                wCO.counter = 1;
                wC.push_back(wCO);
            }
        }
    }
}

void Print(vector<WordCounter> wC)
{
    ofstream output ("rezultatas.txt");

    for (int i = 0; i < wC.size(); i++)
    {
        if (wC.at(i).counter > 1)
            output << wC.at(i).word << "   " << wC.at(i).counter << endl;
    }

    output.close();

}

void PrintCrossReferenceTable(vector<WordCounter> wC, int lineLength)
{

    ofstream output ("CrossReference.txt");

    output << setw(20) << " ";

    for (int i = 0; i < lineLength; i++)
    {
        output << setw(3) << i;
    }

    output << endl;

    for (int i = 0; i < wC.size(); i++)
    {

        if (wC.at(i).counter > 1)
        {

            output << setw(20) << wC.at(i).word;

            for (int a = 0; a < lineLength; a++)
            {

                bool contains = false;

                for (int b = 0; b < wC.at(i).pos.size(); b++)
                {
                    if (a == wC.at(i).pos.at(b))
                        contains = true;
                }

                if (contains)
                    output << setw(3) << "X";
                else
                    output << setw(3) << " ";

            }

            output << endl;

        }

    }

    output.close();

}

int main()
{
    vector<WordCounter> wC;
    string file = "tekstas.txt";
    int lineLength = GetFileLineLength(file);
    vector<string> lines;
    ReadFileByLine(lines, file);
    ReadEachWord(lines, wC);
    cout << wC.size() << endl;
    Print(wC);
    PrintCrossReferenceTable(wC, lineLength);
    return 0;
}
