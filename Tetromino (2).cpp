//
//Jeffrey Warner
//912010188
//
//Tetromino.cpp
//

#include<iostream>
#include"Tetromino.h"
#include<cstdlib>
#include<fstream>

using namespace std;

//Class Tetromino
void Tetromino::print(void) const
{
   cout << name() << " at";
   for(int i = 0; i < 4; i++)
   {
      cout << " (" << x[i] << "," << y[i]<< ")";
   }
   cout << endl;
};

int Tetromino::getX(int i) const
{
   return x[i];
};

int Tetromino::getY(int i) const
{
   return y[i];
};

bool Tetromino::overlap(const Tetromino &t) const
{
   for(int i = 0; i < 4; i++)
   {
      for(int j = 0; j < 4; j++)
      {
         if(x[i] == t.x[j] && y[i] == t.y[j])
         {
            return true;
         }
      }
    }
    return false;
};

void Tetromino::draw(void) const
{
   for(int i = 0; i < 4; i++)
   {
      cout<<"<rect fill=\""<<color()<<"\" stroke=\"black\" x=\""<<x[i] * 50<<"\" y=\""<<y[i] * 50<<"\" width=\"50\" height=\"50\"/>"<<endl;
   }
};

Tetromino* Tetromino::makeTetromino(char ch, int posx, int posy, int orientation)
{
   Tetromino *t;
   if(orientation < 0 || orientation > 3)
   {
      throw invalid_argument("invalid orientation");
      exit(0);
   }
   
   if(ch == 'I')
   {
      t = new I(posx, posy, orientation);
      return t;
   }
   else if(ch == 'O')
   {
      t = new O(posx, posy, orientation);
      return t;
   }
   else if(ch == 'T')
   {
      t = new T(posx, posy, orientation);
      return t;
   }
   else if(ch == 'L')
   {
      t = new L(posx, posy, orientation);
      return t;
   }
   else if(ch == 'J')
   {
      t = new J(posx, posy, orientation);
      return t;
   }
   else if(ch == 'S')
   {
      t = new S(posx, posy, orientation);
      return t;
   }
   else if(ch == 'Z')
   {
      t = new Z(posx, posy, orientation);
      return t;
   }
   else
   {
      throw invalid_argument("invalid type");
      exit(0);
   }
   return 0;
};

void Tetromino::rotate(int nrot)
{
   for(int i = 0; i < nrot; i++)
   {
      for(int j = 1; j < 4; j++)
      {
         const int dx = x[j] - x[0];
         const int dy = y[j] - y[0];
         x[j] = x[0] - dy;
         y[j] = y[0] + dx;
      }
   }
};

//Class I
I::I(int posx, int posy, int orientation)
{
   x[0] = posx;//CELL ZERO
   y[0] = posy;
   x[1] = posx;//CELL ONE
   y[1] = posy + 1;
   x[2] = posx;//CELL TWO
   y[2] = posy + 2;
   x[3] = posx;//CELL THREE
   y[3] = posy + 3;
 
  if(orientation > 0)
   {
      rotate(orientation);
   }
};

char I::name(void) const
{
   return 'I';
};

const char* I::color(void) const
{
   const char* tetColor[] = {"cyan"};
   return *tetColor;
};

//Class O
O::O(int posx, int posy, int orientation)
{
   x[0] = posx;
   y[0] = posy;
   x[1] = posx + 1;
   y[1] = posy;
   x[2] = posx;
   y[2] = posy + 1;
   x[3] = posx + 1;
   y[3] = posy + 1;

   if(orientation > 0)
   {
      rotate(orientation);
   }   
};

char O::name(void) const
{
   return 'O';
};

const char* O::color(void) const
{
   const char* tetColor[] = {"yellow"};
   return *tetColor;
};

//Class T
T::T(int posx, int posy, int orientation)
{
   x[0] = posx;
   y[0] = posy;
   x[1] = posx - 1;
   y[1] = posy + 1;
   x[2] = posx;
   y[2] = posy + 1;
   x[3] = posx + 1;
   y[3] = posy + 1;

   if(orientation > 0)
   {
      rotate(orientation);
   }
};

char T::name(void) const
{
   return 'T';
};

const char* T::color(void) const
{
   const char* tetColor[] = {"purple"};
   return *tetColor;
};

//Class J
J::J(int posx, int posy, int orientation)
{
   x[0] = posx;
   y[0] = posy;
   x[1] = posx + 1;
   y[1] = posy;
   x[2] = posx + 1;
   y[2] = posy + 1;
   x[3] = posx + 1;
   y[3] = posy + 2;

   if(orientation > 0)
   {
      rotate(orientation);
   }
};

char J::name(void) const
{
   return 'J';
};

const char* J::color(void) const
{
   const char* tetColor[] = {"blue"};
   return *tetColor;
};

//Class L
L::L(int posx, int posy, int orientation)
{
   x[0] = posx;
   y[0] = posy;
   x[1] = posx + 1;
   y[1] = posy;
   x[2] = posx;
   y[2] = posy + 1;
   x[3] = posx;
   y[3] = posy + 2;

   if(orientation > 0)
   {
      rotate(orientation);
   }
};

char L::name(void) const
{
   return 'L';
};

const char* L::color(void) const
{
   const char* tetColor[] = {"orange"};
   return *tetColor;
};

//Class S
S::S(int posx, int posy, int orientation)
{
   x[0] = posx;
   y[0] = posy;
   x[1] = posx + 1;
   y[1] = posy;
   x[2] = posx + 1;
   y[2] = posy + 1;
   x[3] = posx + 2;
   y[3] = posy + 1;
   
   if(orientation > 0)
   {
      rotate(orientation);
   }
};

char S::name(void) const
{
   return 'S';
};

const char* S::color(void) const
{
   const char* tetColor[] = {"lime"};
   return *tetColor;
};

//Class Z
Z::Z(int posx, int posy, int orientation)
{
   x[0] = posx;
   y[0] = posy;
   x[1] = posx + 1;
   y[1] = posy;
   x[2] = posx - 1;
   y[2] = posy + 1;
   x[3] = posx;
   y[3] = posy + 1;

   if(orientation > 0)
   {
      rotate(orientation);
   }
};

char Z::name(void) const
{
   return 'Z';
};

const char* Z::color(void) const
{
   const char* tetColor[] = {"red"};
   return *tetColor;
};


