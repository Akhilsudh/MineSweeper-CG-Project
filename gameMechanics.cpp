#include "gameMechanics.hpp"
#include "drawer.hpp"
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <thread>
#include <unistd.h>


int initial = 0;
Drawer d;
int retFlag = 0, anotherFlag = 0;
int X, Y;
int winFlag = 0;
void boom()
{
    system("play boom.wav 2> /dev/null");
}

void win()
{
	system("play ToToDo.wav 2> /dev/null");	
}

Game::Game()
{	gameOver = false;
	srand ( time(NULL) );
	for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x)
        {
            field_[x][y].state = CLOSED;
            field_[x][y].hasMine = false;
        }
    for (int i = 0; i < 30; ++i)
    {
        int x, y;
        //Randomly select a position x and y till a field with no mines has returned to place a mine there
        do
        {	
        	//Find x and y randomly wrt the HEIGHT and WIDTH defined
            x = rand() % WIDTH;
            y = rand() % HEIGHT;
        }
        while (field_[x][y].hasMine);
        
        field_[x][y].hasMine = true;
    }
}

bool Game::gridSweeper(int x, int y)
{
	if (!(field_[x][y].hasMine || (field_[x][y].state == FLAG) ))
	{	
		int neighbourMinesCount = 0;
	    //Check all around this field for mines and increase the neighbouring mines count
	    for (int yy = y - 1; yy <= y + 1; ++yy){
	    	for (int xx = x - 1; xx <= x + 1; ++xx)
	        {
	            if ((xx == x && yy == y) || xx < 0 || xx >= WIDTH || yy < 0 || yy >= HEIGHT)
	                continue;
	            if (field_[xx][yy].hasMine)
	                ++neighbourMinesCount;
	        }
	    }
	    field_[x][y].state = OPENED;
	    d.drawOpenedField(x, y, neighbourMinesCount);   
	    return true;
    }
    else return false;
}

bool Game::gameWin()
{
	int count = 0;
	for(int x = 0; x < WIDTH; x++)
	{
		for(int y = 0; y < HEIGHT; y++)
		{
			if(field_[x][y].hasMine && (field_[x][y].state == FLAG))
				count++;
		}
	}
	if(count == 30)
		return true;
	else
		return false;
}

void Game::draw()
{	int boomFlag = 0;
	if(gameWin())
	{
		if(!winFlag){
			std::thread t1(win);
			t1.join();
			winFlag = 1;
		}	
		gameWonFlag = true;
		gameOver = true;
	}

	if(!gameOver)
	{	for (int y = 0; y < HEIGHT; ++y)
	        for (int x = 0; x < WIDTH; ++x)
	        {
	            switch (field_[x][y].state)
	            {
		            case CLOSED:
		                d.drawClosedField(x, y); //Draw a closed field
		                break;
		            case OPENED:
		                if (!field_[x][y].hasMine)
		                {
		                    int neighbourMinesCount = 0;
		                    //Check all around this field for mines and increase the neighbouring mines count
		                    for (int yy = y - 1; yy <= y + 1; ++yy){
						    	for (int xx = x - 1; xx <= x + 1; ++xx)
						        {
						            if ((xx == x && yy == y) || xx < 0 || xx >= WIDTH || yy < 0 || yy >= HEIGHT)
						                continue;
						            if (field_[xx][yy].hasMine)
						                ++neighbourMinesCount;
						        }
						    }
						    d.drawOpenedField(x, y, neighbourMinesCount);   

		                	if(anotherFlag)
							{	
								//int depth = rand()%5;
								int depth = 2;
								for(int k = 1; k <= depth;k++){
		                			if(X > 0 && !gridSweeper(X-k, Y)) break;
		                			if(Y > 0 && !gridSweeper(X, Y-k)) break;
		                			if(X < WIDTH && !gridSweeper(X+k, Y)) break;
		                			if(Y < HEIGHT && !gridSweeper(X, Y+k)) break;
		                			if(X > 0 && Y > 0 && !gridSweeper(X-k, Y-k)) break;
		                			if(X < WIDTH && Y < HEIGHT &&!gridSweeper(X+k, Y+k)) break;
		                		}
		                		
								anotherFlag = 0;
							}
			                   	
		                    //d.drawOpenedField(x, y, neighbourMinesCount); //Draw the opened field
							
		                }
		                else
		                {   //Mines go KABOOM :P
		                	//Literally
		                	if(!boomFlag){
		                		std::thread t1(boom);
		                		t1.join();
		                		boomFlag = 1;
		                	}

		                	for (int j = 0; j < HEIGHT; ++j)
	        					for (int i = 0; i < WIDTH; ++i)
	        						if (field_[i][j].hasMine ){
	        							field_[i][j].state = OPENED;
	        							d.drawMine(i, j);	                	
	        						}
	        				gameOver = true;
	        				
		                }
		                break;
		            case FLAG:
		                d.drawFlag(x, y);
		                break;
	            }
	        }
        if (!initial)
	    {
	        initial = 1;
	        Drawer d;
			d.drawWelcomeScreen((int)HEIGHT, (int)WIDTH);
	        sleep(2);
	    }
	}
	else{
		for (int j = 0; j < HEIGHT; ++j)
			for (int i = 0; i < WIDTH; ++i)
			{	
				if (field_[i][j].hasMine && !gameWonFlag)
				{
			    	field_[i][j].state = OPENED;
			    	d.drawMine(i, j);	                	
			    }
			    else if (field_[i][j].hasMine && gameWonFlag)
			    {
			    	d.drawFlag(i, j);	
			    }
			    else
			    {
			    	d.drawClosedField(i, j);
			    }
			}    
		sleep(1);
		if(!gameWonFlag)
		{
			d.gameOver((int)HEIGHT, (int)WIDTH);
		}
		else
		{
			d.gameWon((int)HEIGHT, (int)WIDTH);
		}
	}
}

void Game::markFlag(int x, int y)
{
	switch (field_[x][y].state)
    {
	    case OPENED:
	        break;
	    case CLOSED:
	        field_[x][y].state = FLAG;
	        break;
	    case FLAG:
	        field_[x][y].state = CLOSED;
	        break;
    }
}

void Game::open(int x, int y)
{	
	//This is the place where we make sure that clicking the flagged cell
	//doesnt lead to opening it and when the cell is already opened. 
	if(!((field_[x][y].state == FLAG)||(field_[x][y].state == OPENED)))
	{
		field_[x][y].state = OPENED;
		anotherFlag = 1;
		X = x;
		Y = y;
	}
}
