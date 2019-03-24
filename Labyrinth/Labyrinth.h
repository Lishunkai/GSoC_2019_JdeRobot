/*
	Author: Shunkai Li
	Education: a senior student of Nankai University, China,
			   and an incoming student of Peking University, China.
*/

#ifndef LABYRINTH_LABYRINTH_HPP
#define LABYRINTH_LABYRINTH_HPP

#include <vector>
#include <fstream>

// Wall and free path of the labyrinth.
#define IsFree        -1
#define IsWall        -2

using namespace std;

class Labyrinth
{

public:

    Labyrinth() {}
    Labyrinth(const vector<vector<int> > &board);
    Labyrinth(ifstream &inputFile);

    int point(const int i, const int j) const;

    // Find the longest free path.
    Labyrinth FindMaxPath() const;
    Labyrinth MaxPathFromThisPoint(const int i, const int j) const;
    int MaxPath() const;
    void SetValue(const int i, const int j, const int value);
    bool operator<(const Labyrinth &l) const;

    // output
    friend ostream& operator<<(ostream &output, const Labyrinth &l);

private:
    int mMaxPath = 0;

    // Labyrinth board
    vector<vector<int> > mBoard;
};

#endif // LABYRINTH_H