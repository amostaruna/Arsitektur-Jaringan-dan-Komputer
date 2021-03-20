// PongSimulation_Week4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 
//library List
#include<iostream>
#include<thread>
#include<mutex>
#include <time.h>
#include <stdlib.h>
#include"Score.h"
#include "Player.h"

using namespace std;
Score score(0, 0);
mutex m;

//Player Turn Function
void PlayerTurn(Player p)
{
    m.lock();
    int* temp = new int;
    srand((int)temp);
    delete temp;

    //to check if the player is PlayerX
    if (static_cast<int>(p.getPlayer()) == 0)
    {
        cout << "\nPlayerX Turn" << endl;
        //Random hits generator 
        float random = rand() % 100;
        cout << "Random Hits X = " << random << endl << endl;
        p.setHits(random);
        //Hit Checker
        if (p.getHits() <= 50)//if hits>=150, player Y will get 1 score
        {
            score.setYscore(1);
            cout << "X score= " << score.getXscore() << "  Y score= " << score.getYscore() << endl;
        }
        else if (p.getHits() > 50)//if hits<50, the ball hit the oppenent and turn change.
        {
            cout << "Ball got hit" << endl;
        }

    }
    //to check if the player is PlayerY
    else if (static_cast<int>(p.getPlayer()) == 1)
    {
        cout << "\nPlayerY Turn" << endl;
        //Random hits generator 
        float random = rand() % 100;
        cout << "Random Hits Y = " << random << endl << endl;
        p.setHits(random);
        //Hit Checker
        if (p.getHits() <= 50)//if hits>=150, player X will get 1 score
        {
            score.setXscore(1);
            cout << "X score= " << score.getXscore() << "  Y score= " << score.getYscore() << endl;
        }
        else if (p.getHits() > 50)
        {
            cout << "Ball got hit" << endl; //if hits<50, the ball hit the oppenent and turn change.
        }
    }
    m.unlock();
    }

int main()
{
    //set Player X
    Player playerX;
    playerX.setPlayerX();
    cout << "Player x enum= " << static_cast<int>(playerX.getPlayer()) << endl;

    //set Player Y
    Player playerY;
    playerY = playerX;
    //playerY.setPlayerY(); //proper Player Y creation
    cout << "Player y enum= " << static_cast<int>(playerY.getPlayer()) << endl<<endl;

    //random first turn generator
    int* temp = new int;
    srand((int)temp);
    delete temp;
    int r = rand()%2;

    //player X first Turn
    if (r == 0)
    {
        cout << "Player X move first." << endl<<endl;
        //run thread until a player get 10 score
        while (score.getXscore()<10 && score.getYscore()<10)
        {

            thread tPX(PlayerTurn, playerX);
            tPX.join();
            thread tPY(PlayerTurn, playerY);
            tPY.join();
        }
    }
    //Player Y First Turn
    else if (r == 1)
    {
        cout << "Player Y move first." << endl << endl;
        //run thread until a player get 10 score
        while (score.getXscore() < 10 && score.getYscore() < 10)
        {
            thread tPY(PlayerTurn, playerY);
            tPY.join();
            thread tPX(PlayerTurn, playerX);
            tPX.join();
        }
    }
    //Win Checker
    if (score.getXscore() == 10)
    {
        cout << "\nPlayer X Win!" << endl;
    }
    else if (score.getYscore() == 10)
    {
        cout << "\nPlayer Y Win!" << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
