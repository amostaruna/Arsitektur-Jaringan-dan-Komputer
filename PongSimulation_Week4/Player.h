#pragma once
#include<iostream>
using namespace std;

class Player
{
private:
	enum class PlayerEnum
	{
		PlayerX=0,
		PlayerY=1
	};

	PlayerEnum CurrentEnumField; //Object's variable that store enum data
	float Hits;	//Hits variable
public:

	//setting up playerX
	void setPlayerX()
	{
		CurrentEnumField = PlayerEnum::PlayerX;
	}
	//setting up PlayerY
	void setPlayerY()
	{
		CurrentEnumField = PlayerEnum::PlayerY;
	}
	//return CurrentEnumField data
	PlayerEnum getPlayer()
	{
		return CurrentEnumField;
	}
	//setting up Hits data
	void setHits(float f)
	{
		Hits = f;
	}
	//return Hits data
	float getHits()
	{
		return Hits;
	}

};