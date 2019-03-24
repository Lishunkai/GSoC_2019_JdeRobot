/*
	Author: Shunkai Li
	Education: a senior student of Nankai University, China,
			   and an incoming student of Peking University, China.
*/

#include <iostream>
#include <fstream>

#include "Labyrinth.h"

using namespace std;

Labyrinth::Labyrinth(const vector<vector<int> > &board)
{
    mBoard = board;
    mMaxPath = 0;
}

Labyrinth::Labyrinth(ifstream &InputLabyrinth)
{
    string Line;
    
    // Search all lines.
    while (!InputLabyrinth.eof())
    {
        vector<int> CurrentLine;
        CurrentLine.reserve(Line.size());
        InputLabyrinth >> Line;

        // Search all the elements in the current line.
        for (int i = 0; i < Line.size(); ++i)
        {
            if(Line[i] == '#')
            {
                CurrentLine.push_back(IsWall);
            }
            else if(Line[i] == '.')
            {
                CurrentLine.push_back(IsFree);
            }
            else
            {
                cout<<Line[i]<<" is not a valid input."<<endl;
                throw 1;
            }
        }
        mBoard.push_back(CurrentLine);
    }
}

// Find the longest path.
Labyrinth Labyrinth::FindMaxPath() const
{
    Labyrinth max = *this;

    int Rows = mBoard.size();
    int Columns = mBoard[0].size();

    // First row.
    for (int j = 0; j < Columns; ++j)
    {
        max = std::max(max, MaxPathFromThisPoint(0, j));
    }
    // First and last column.
    for (int i = 1; i < Rows-1; ++i)
    {
        max = std::max(max, MaxPathFromThisPoint(i, 0));
        max = std::max(max, MaxPathFromThisPoint(i, Columns-1));
    }
    // Last row.
    for (int j = 0; j < Columns; ++j)
    {
        max = std::max(max, MaxPathFromThisPoint(Rows-1, j));
    }
    return max;
}

// Find the longest path starting from point (i,j)
Labyrinth Labyrinth::MaxPathFromThisPoint(const int i, const int j) const
{
    int Rows = mBoard.size();
    int Columns = mBoard[0].size();
    // If point (i,j) is out of Labyrinth.
    if (i < 0 || j < 0 || i >= Rows || j >= Columns)
        return *this;

    // Check if point (i,j) is free.
    if (mBoard[i][j] == IsFree)
    {
        Labyrinth NextStep = *this;
        NextStep.SetValue(i, j, NextStep.mMaxPath++);
        
        return std::max(
                        std::max(
                                    NextStep.MaxPathFromThisPoint(i-1, j), // direction 1
                                    NextStep.MaxPathFromThisPoint(i+1, j)  // direction 2
                                ),
                        std::max(
                                    NextStep.MaxPathFromThisPoint(i, j-1), // direction 3
                                    NextStep.MaxPathFromThisPoint(i, j+1)  // direction 4
                                )
                        );
    }
    else
    {
        // Return the same labyrinth.
        return *this;
    }

}

int Labyrinth::MaxPath() const
{
    return mMaxPath;
}

int Labyrinth::point(const int i, const int j) const
{
    return mBoard[i][j];
}

void Labyrinth::SetValue(const int i, const int j, const int value)
{
    mBoard[i][j] = value;
}

// See if l has a longer free path than this Labyrinth.
bool Labyrinth::operator<(const Labyrinth &l) const
{
    return mMaxPath < l.mMaxPath;
}

/*
    Description: Output the result.
    
    @param   output: Convert l to a string.
    @param   l:   Labyrinth
*/
ostream& operator<<(ostream &output, const Labyrinth &l)
{
    int Rows = l.mBoard.size();
    int Columns = l.mBoard[0].size();
    
    for (int i = 0; i < Rows; ++i)
    {
        for (int j = 0; j < Columns; ++j)
        {
            if(l.point(i, j) == IsWall)
            {
                output << '#';
            }
            else if(l.point(i, j) == IsFree)
            {
                output << '.';
            }
            else
            {
                output << l.point(i, j);
            }
        }
        output << endl;
    }
}