#pragma once
#include <iostream>
using namespace std;

class Score
{
public:
	Score(int X, int Y);	//Score Constructor, 0 by default
	void setXscore(int X);	//setting up PlayerX's Score
	void setYscore(int Y);	//setting up PlayerY's Score
	int getXscore();		//return PlayerX's Score
	int getYscore();		//return PlayerY's Score

protected:
	int PlayerXscore;		//PlayerX's Score variable
	int PlayerYscore;		//PlayerY's Score variable
};

inline Score::Score(int X, int Y)
{
	PlayerXscore = X;
	PlayerYscore = Y;
}

inline void Score::setXscore(int X)
{
	PlayerXscore += X;		//add X number to current PlayerXscore;
}

inline void Score::setYscore(int Y)
{
	PlayerYscore += Y;		//add Y number to current PlayerXscore;
}

inline int Score::getXscore()
{
	return PlayerXscore;
}

inline int Score::getYscore()
{
	return PlayerYscore;
}
