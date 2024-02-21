/*
Program: Word Search
Name: Aastha Sheth
Date: 02/14/2024
Class: CS 1337.012
Purpose: This program reads in a text file that has a word search grid in it and movie names to be found.

The program reads this file and outputs the movie names that were found(and the direction they were found in), 
and the also outputs the words that weren't found to the console.

Changelog:
02/14/2024-- created program, began listing required functions.
02/15/2024-- read file data into the function and made the matrix
02/17/2024-- created the functions to search the words in the matrix
02/18/2024-- 

*/

#include <iostream>
#include <iomanip> // maybe maybe
#include <fstream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

ifstream inputFile;
string **strptr = nullptr; // gonna be used maybe
int lineCount = 0;
vector<string> matrix;
vector<string> moviesFound;
vector<string> movieNotFound;
vector<string> directionAndCount;
char direction;
int matrixRow, matrixCol;
string *movieptr = nullptr;
int occurrences = 0;

void fileValidation(string &fileName) // good to go
{
    while(inputFile.fail())
    {
        cout << "Couldn't find the file named " << fileName << endl;
        cout << "Enter again or 'q' to quit: ";
        getline(cin, fileName);
        if(fileName == "q")
        {
            exit(0);
        }
        inputFile.open(fileName);
    }
}

void openFile() 
{
    string fileName;
    cout << "Enter the name of the file: ";
    getline(cin, fileName);
    inputFile.open(fileName);
    fileValidation(fileName);
}

void readFileIgnoringCommentsAndSpace() 
{
    string line = "";
    while (getline(inputFile, line))
    {
        if(line.empty() || line[0] == '#')
            continue;

        matrix.push_back(line);
        lineCount++;
    }
}

void getRowOrCol(int &index, string &sRowOrCol)
{
    while (index < matrix[1].length() && isdigit(matrix[0][index]) && !isspace(matrix[0][index]))
    {
        sRowOrCol.append(1, matrix[0][index]);
        index++; 
    }
}

void determineMatrixSize()
{
    string s_matrixRow = "", s_matrixCol = "";
    int i = 0;

    getRowOrCol(i, s_matrixRow);

    while (i < matrix[1].length() && isspace(matrix[0][i]))
    {
        i++;
    }

    getRowOrCol(i, s_matrixCol);

    matrixRow = stoi(s_matrixRow);
    matrixCol = stoi(s_matrixCol);
}

void displayMatrix()
{
    for (int i = 0; i < matrixRow; ++i)
    {
        for (int j = 0; j < matrixCol; ++j)
        {
            cout << strptr[i][j] << " ";
        }
        cout << endl;
    }
}

void getMatrixIntoArray()
{
    determineMatrixSize();
    strptr = new string*[matrixRow];
    for (int i = 0; i < matrixRow; ++i) 
    {
        strptr[i] = new string[matrixCol];
    }

    for (int i = 1; i <= matrixRow; ++i)
    {
        for (int j = 0; j < matrixCol; ++j)
        {
            strptr[i-1][j] = matrix[i][j];
        }
    }

    displayMatrix();
    
}

void getMovieNamesIntoArray()
{
    int index = 0;
    movieptr = new string[lineCount - (matrixRow + 1)];
    for (int i = matrixRow + 1; i < lineCount; i++)
    {
        movieptr[index] = matrix[i];
        index++;
    }
}

void checkHorizontally(string &target, int &len)
{
    for (int i = 1; i <= matrixRow; ++i)
    {
        for (int j = 0; j <= matrixCol - len; ++j)
        {
            string substring = matrix[i].substr(j, len);
            if (substring == target || substring == string(target.rbegin(), target.rend()))
            {
                moviesFound.push_back(target);
                directionAndCount.push_back(target + " Direction: E at (" + to_string(i) + "," + to_string(j+1) + ")");
                return;
            }
        }
    }
    for (int i = 1; i <= matrixRow; ++i)
    {
        for (int j = matrixCol - 1; j >= len - 1; --j)
        {
            string substring = "";
            for (int k = 0; k < len; ++k)
            {
                substring += matrix[i][j - k];
            }
            if (substring == target || substring == string(target.rbegin(), target.rend()))
            {
                moviesFound.push_back(target);
                directionAndCount.push_back(target + " Direction: W at (" + to_string(i) + "," + to_string(j+1) + ")");
                return;
            }
        }
    }
}

void checkVertical(string target, int &len)
{
    for (int i = 1; i <= matrixRow - len; ++i)
    {
        for (int j = 0; j <= matrixCol; ++j)
        {
            string substring = "";
            for (int k = 0; k < len; ++k)
            {
                substring += matrix[i + k][j];
            }
            if (substring == target || substring == string(target.rbegin(), target.rend()))
            {

                moviesFound.push_back(target);
                directionAndCount.push_back(target + " Direction: S at (" + to_string(i) + "," + to_string(j+1) + ")");
                return;
            }
        }
    }
    for (int i = matrixRow; i >= len - 1; --i)
    {
        for (int j = 0; j < matrixCol; ++j)
        {
            string substring = "";
            for (int k = 0; k < len; ++k)
            {
                substring += matrix[i - k][j];
            }
            if (substring == target || substring == string(target.rbegin(), target.rend()))
            {
                moviesFound.push_back(target);
                directionAndCount.push_back(target + " Direction: N at (" + to_string(i) + "," + to_string(j+1) + ")");
                return;
            }
        }
    }
}

void checkDiagonalTopToBottom(string target, int &len)
{
    for (int i = 1; i <= matrixRow - len; ++i)
    {
        for (int j = 0; j < matrixCol; ++j)
        {
            string substring = "";
            for (int k = 0; k < len; ++k)
            {
                substring += matrix[i + k][j + k];
                //cout << substring<< endl;
            }
            if (substring == target || substring == string(target.rbegin(), target.rend()))
            {
                //cout << substring<< endl;
                moviesFound.push_back(target);
                directionAndCount.push_back(target + " Direction: SE at (" + to_string(i) + "," + to_string(j+1) + ")");
                return;
            }
        }
    }
}

void checkDiagonalBottomToTop(string target, int &len)
{
    for (int i = len-1; i <= matrixRow; ++i)
    {
        for (int j = 0; j < matrixCol - len; ++j)
        {
            string substring = "";
            for (int k = 0; k < len; ++k)
            {
                substring += matrix[i - k][j + k];
            }
            if (substring == target || substring == string(target.rbegin(), target.rend()))
            {
                //cout << substring << " Direction: NE at (" << to_string(i) << "," << to_string(j+1) << ")" << endl;
                moviesFound.push_back(target);
                directionAndCount.push_back(target + " Direction: NE at (" + to_string(i) + "," + to_string(j+1) + ")");
                return;
            }
        }
    }
}

void checkWord(string target)
{
    int len = target.length();
    int index = 0;
    checkHorizontally(target, len);
    checkVertical(target, len);
    checkDiagonalTopToBottom(target, len);
    checkDiagonalBottomToTop(target, len);

}

void skipSpaces(string target, string &sub)
{
    for (int i = 0; i < target.length(); i++)
        {
            if (target[i] == ' ')
            {
                continue;
            }
            else
            {
                sub += target[i];
            }
        }
}

void searchMovieInMatrix()
{
    int movieIndex = lineCount - (matrixRow + 1);
    getMatrixIntoArray();
    getMovieNamesIntoArray();
    for (int i = 0; i < movieIndex; i++)
    {
        string movie = movieptr[i];
        string substring;

        skipSpaces(movie, substring);
        movie = substring;

        //vector<string> directionAndCount;
        checkWord(movie);
        cout << directionAndCount[i] << endl;
        // Output found movies and directions
        if (find(moviesFound.begin(), moviesFound.end(), movie) == moviesFound.end())
        {
            movieNotFound.push_back(movie);
        }

        movie = movieptr[i];
    }

    cout << "Movies Found: " << endl;
    for(string movie : moviesFound)
        cout << movie << endl;

    cout << "Movies not found: " << endl;
    for (string movie : movieNotFound)
    {
        cout << movie << endl;
    }
    
}


int main()
{
    openFile();
    readFileIgnoringCommentsAndSpace();
    searchMovieInMatrix();

    delete [] strptr;
    delete [] movieptr;
    strptr = nullptr;
    movieptr = nullptr;
    return 0;
    
}