#include "gameMechanics.hpp"
#include "drawer.hpp"
#include <cstdlib>

Game::Game()
{
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
    }
}

void Game::draw()
{
	Drawer d;
	for (int y = 0; y < HEIGHT; ++y)
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
	                    p.drawOpenedField(x, y, neighbourMinesCount); //Draw the opened field
	                }
	                else
	                {    
	                	p.drawMine(x, y);
	                	///////////////////////////////////////////////////////////////////
	                	//Write a procedure here to show the player that the game is over//
	                	///////////////////////////////////////////////////////////////////
	                }
	                break;
	            case FLAG:
	                p.drawFlag(x, y);
	                break;
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
	field_[x][y].state = OPENED;
}