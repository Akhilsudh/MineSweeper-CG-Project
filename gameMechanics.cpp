#include "gameMechanics.hpp"
#include "drawer.hpp"
#include <cstdlib>
#include <stdio.h>
#include <ctime>
#include <unistd.h>

Game::Game()
{	gameOver = false;
	srand ( time(NULL) );
	for (int y = 0; y < HEIGHT; ++y)
        for (int x = 0; x < WIDTH; ++x)
        {
            field_[x][y].state = CLOSED;
            field_[x][y].hasMine = false;
        }
    for (int i = 0; i < 10; ++i)
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
        printf("%d %d\n", x, y);
    }
}

void Game::draw()
{
	Drawer d;
	if(!gameOver)
		{for (int y = 0; y < HEIGHT; ++y)
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
		                    for (int yy = y - 1; yy <= y + 1; ++yy)
		                        for (int xx = x - 1; xx <= x + 1; ++xx)
		                        {
		                            if ((xx == x && yy == y) || xx < 0 || xx >= WIDTH || yy < 0 || yy >= HEIGHT)
		                                continue;
		                            if (field_[xx][yy].hasMine)
		                                ++neighbourMinesCount;
		                        }
		                    d.drawOpenedField(x, y, neighbourMinesCount); //Draw the opened field
		                }
		                else
		                {   
		                	///////////////////////////////////////////////////////////////////
		                	//Write a procedure here to show the player that the game is over//
		                	/////////////////////////////////////////////////////////////////// 
		                	for (int j = 0; j < HEIGHT; ++j)
	        					for (int i = 0; i < WIDTH; ++i)
	        						if (field_[i][j].hasMine){
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
	}
	else{
		for (int j = 0; j < HEIGHT; ++j)
			for (int i = 0; i < WIDTH; ++i)
				d.drawClosedField(i, j);
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
	field_[x][y].state = OPENED;
}