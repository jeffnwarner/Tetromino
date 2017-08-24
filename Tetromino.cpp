//Jeffrey Warner
//912010188
//
//Tetromino.cpp
//

#include<iostream>
#include<stdexcept>
#include<math.h>
#include"Tetromino.h"
using namespace std;

void Tetromino::print(void) const
{
   cout<<name()<<" at ";
   cout<<"("<<x[0]<<","<<y[0]<<") ";
   cout<<"("<<x[1]<<","<<y[1]<<") ";
   cout<<"("<<x[2]<<","<<y[2]<<") ";
   cout<<"("<<x[3]<<","<<y[3]<<")"<<endl;
};
bool Tetromino::overlap(const Tetromino &t) const
{
   bool ovlp = false;
   for (int i = 0; i < 4; i++)
   {
      for (int j = 0; j < 4; j++)
      {
         if (t.x[i] == x[j] && t.y[i] == y[j])
         {
            ovlp = true;
         }
      }
   }
   if (ovlp == true)
   {
      return true;
   }
   else
   {
      return false;
   }
};

Tetromino* Tetromino::makeTetromino(char ch, int posx, int posy, int orientation)
{  
   Tetromino *t;
   if (orientation > 3 || orientation < 0)
   {
      throw std::invalid_argument("invalid orientation");
   }
   else
   {
      if (ch == 'I')
      {
         t = new I(posx, posy, orientation);
         return t;
      }  
         
      else if (ch == 'O')
      {
         t = new O(posx, posy, orientation);
         return t;
      }
      else if (ch == 'T')
      {
         t = new T(posx, posy, orientation);
         return t;
      }
      else if (ch == 'J')
      {
         t = new J(posx, posy, orientation);
         return t;
      }
      else if (ch == 'L')
      {
         t = new L(posx, posy, orientation);
         return t;
      }
      else if (ch == 'S')
      {
         t = new S(posx, posy, orientation);
         return t;
      }
      else if (ch == 'Z')
      {
         t = new Z(posx, posy, orientation);
         return t;
      }
      else
      { 
         throw std::invalid_argument("invalid type");
      }
    }
};

void Tetromino::rotate(int nrot)
{  
  // int posx = x[0];
  // int posy = y[0];
  cout<<x[0]<<" "<<y[0]<<endl;
  for (int i = 0; i < nrot; i++)
  {
     for (int j = 1; j < (sizeof(x)/sizeof(*x)); j++)
     {  
        int posx = x[j];
        int posy = y[j];
        cout<<x[j]<<" "<<y[j]<<endl;
        x[j] = -posy + (2 * x[0]);
        y[j] = posx;
        cout<<x[j]<<" "<<y[j]<<" "<<j<<endl;
     }
  }
  /* switch(name())
   {
      case 'I' :
         if (nrot == 1)
         {
            x[1] = posx - 1;
            y[1] = posy;
            x[2] = posx - 2;
            y[2] = posy;
            x[3] = posx - 3;
            y[3] = posy;
         }
         else if (nrot == 2)
         {
            x[1] = posx;
            y[1] = posy - 1;
            x[2] = posx;
            y[2] = posy - 2;
            x[3] = posx;
            y[3] = posy - 3;
         }
         else if (nrot == 3)
         {
            x[1] = posx + 1;
            y[1] = posy;
            x[2] = posx + 2;
            y[2] = posy;
            x[3] = posx + 3;
            y[3] = posy;
         }
         break;
      
      case 'O' :
         if (nrot == 1)
         {
            x[1] = posx;
            y[1] = posy + 1;
            x[2] = posx - 1;
            y[2] = posy;
            x[3] = posx - 1;
            y[3] = posy + 1;
         }
         else if (nrot == 2)
         {
            x[1] = posx - 1;
            y[1] = posy;
            x[2] = posx;
            y[2] = posy - 1;
            x[3] = posx - 1; 
            y[3] = posy - 1;
         }
         else if (nrot == 3)
         {
            x[1] = posx;
            y[1] = posy - 1;
            x[2] = posx + 1;
            y[2] = posy;
            x[3] = posx + 1;
            y[3] = posy - 1;
         }
         break;
      
      case 'T' :
         if (nrot == 1)
         {
            x[1] = posx - 1;
            y[1] = posy - 1;
            x[2] = posx - 1;
            y[2] = posy;
            x[3] = posx - 1;
            y[3] = posy + 1;
         }
         else if (nrot == 2)
         {
            x[1] = posx + 1;
            y[1] = posy - 1;
            x[2] = posx;
            y[2] = posy - 1;
            x[3] = posx - 1;
            y[3] = posy - 1;
         }
         else if (nrot == 3)
         {
            x[1] = posx + 1;
            y[1] = posy + 1;
            x[2] = posx + 1;
            y[2] = posy;
            x[3] = posx + 1;
            y[3] = posy - 1;
         }
         break;
      
      case 'J' :
         if (nrot == 1)
         {
            x[1] = posx;
            y[1] = posy + 1;
            x[2] = posx - 1;
            y[2] = posy + 1;
            x[3] = posx - 2;
            y[3] = posy + 1;
         }
         else if (nrot == 2)
         {
            x[1] = posx - 1;
            y[1] = posy;
            x[2] = posx - 1;
            y[2] = posy - 1;
            x[3] = posx - 1;
            y[3] = posy - 2;
         }
         else if (nrot == 3)
         {
            x[1] = posx;
            y[1] = posy - 1;
            x[2] = posx + 1;
            y[2] = posy - 1;
            x[3] = posx + 2;
            y[3] = posy - 1;
         }
         break;
 
      case 'L' :
         if (nrot == 1)
         {
            x[1] = posx;
            y[1] = posy + 1;
            x[2] = posx - 1;
            y[2] = posy;
            x[3] = posx - 2;
            y[3] = posy;
         }
         else if (nrot == 2)
         {
            x[1] = posx - 1;
            y[1] = posy;
            x[2] = posx;
            y[2] = posy - 1;
            x[3] = posx;
            y[3] = posy - 2;
         }
         else if (nrot == 3)
         {
            x[1] = posx;
            y[1] = posy - 1;
            x[2] = posx + 1;
            y[2] = posy;
            x[3] = posx + 2;
            y[3] = posy;
         }
         break;

      case 'S' :
         if (nrot == 1)
         {
            x[1] = posx;
            y[1] = posy + 1;
            x[2] = posx - 1;
            y[2] = posy + 1;
            x[3] = posx - 1;
            y[3] = posy + 2;
         }
         else if (nrot == 2)
         {
            x[1] = posx - 1;
            y[1] = posy; 
            x[2] = posx - 1;
            y[2] = posy - 1;
            x[3] = posx - 2;
            y[3] = posy - 1;
         }
         else if (nrot == 3)
         {
            x[1] = posx;
            y[1] = posy - 1;
            x[2] = posx + 1;
            y[2] = posy - 1;
            x[3] = posx + 1;
            y[3] = posy - 2;
         }
         break;
   
      case 'Z' :
         if (nrot == 1)
         {
            x[1] = posx;
            y[1] = posy + 1;
            x[2] = posx - 1;
            y[2] = posy - 1;
            x[3] = posx - 1;
            y[3] = posy;
         }
         else if (nrot == 2)
         {
            x[1] = posx - 1;
            y[1] = posy;
            x[2] = posx + 1;
            y[2] = posy - 1;
            x[3] = posx;
            y[3] = posy - 1;
         }
         else if (nrot == 3)
         {
            x[1] = posx;
            y[1] = posy - 1;
            x[2] = posx + 1; 
            y[2] = posy + 1;
            x[3] = posx + 1;
            y[3] = posy;
         }
         break;      
   }*/
};

 //creates object I
I::I(int posx, int posy, int orientation)
{
   x[0] = posx;//cell zero
   y[0] = posy;
   x[1] = posx; //cell one
   y[1] = posy + 1;
   x[2] = posx; //cell two
   y[2] = posy + 2;
   x[3] = posx; //cell three
   y[3] = posy + 3;
   //other cells will be placed in same order
   
   if (orientation > 0)
   {
      rotate(orientation);
   }  
};
char I::name(void) const
{
   return 'I';
};
 
 //creates object of type O
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
      
   if (orientation > 0)
   {
      rotate(orientation);
   }
};
char O::name(void) const
{
   return 'O';
};


 //creates object T
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
   
   if (orientation > 0)
   {
      rotate(orientation);
   }
};
char T::name(void) const
{
   return 'T';
};

 //creates object J
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
 
   if (orientation > 0)
   {
      rotate(orientation);
   }
};
char J::name(void) const
{
   return 'J';
};

 //creates object L
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
   
   if (orientation > 0)
   {
      rotate(orientation);
   }
};
char L::name(void) const
{
   return 'L';
};

 //creates object S
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
   
   if (orientation > 0)
   {
      rotate(orientation);
   }
};
char S::name(void) const
{
   return 'S';
};

 //Creates object Z
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
   
   if (orientation > 0)
   {
      rotate(orientation);
   }
};
char Z::name(void) const
{
   return 'Z';
};

