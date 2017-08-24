//
//Jeffrey Warner
//912010188
//
//Board.cpp

#include<iostream>
#include"Board.h"
#include<vector>
#include<exception>
#include<cstdlib>
#include<fstream>

using namespace std;

void Board::addTetromino(char type, int x, int y, int orientation)
{
   Tetromino *t;
   t = t->makeTetromino(type, x, y, orientation);
  
   if(fits_on_board(*t))
   {
      for(unsigned int i = 0; i < tList.size(); i++)
      {
         if (tList[i]->overlap(*t))
         {
            throw invalid_argument("overlap");
            exit(0);
         }
      }
      tList.push_back(t);
   }
   
   else
   {
      throw invalid_argument("does not fit on board");
      exit(0);
   } 
};

bool Board::fits_on_board(const Tetromino &t) const
{
   for(int i = 0; i < 4; i++)
   {
      if(t.getX(i) >= size_x || t.getY(i) >= size_y)
      {  
         return false;
      }
   }
   return true;
};

void Board::draw(void) const
{
   cout<<"<?xml version=\"1.0\" encoding=\"utf-8\" standalone=\"no\"?>"<<endl
       <<"<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\""<<endl
       <<"\"http://www.w3.org/Graphics/SVG/1.1/DTDsvg11.dtd\">"<<endl
       <<"<svg width=\"570\" height=\"570\" viewBox=\"0 0 550 550\""<<endl
       <<"xmlns=\"http://www.w3.org/2000/svg\""<<endl
       <<"xmlns:xlink=\"http://www.w3.org/1999/xlink\">"<<endl
       <<"<g transform=\"matrix(1,0,0,-1,50,550)\">"<<endl

       <<"<rect fill=\"white\" stroke=\"black\" x=\"0\" y=\"0\" width=\""<<size_x * 50<<"\" height=\""<<size_y * 50<<"\"/>"<<endl;
   for(unsigned int i = 0; i < tList.size(); i++)
   {
      tList[i]->draw();
   }
   cout<<"</g>"<<endl
       <<"</svg>"<<endl;
};
