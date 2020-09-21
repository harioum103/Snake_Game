#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<conio.h>


using namespace std;
bool gameOver;

const int width=20;
const int height=20;
int x,y,fruitX,fruitY,score;
int tailX[100],tailY[100];
int ntail;
enum eDirecton {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirecton dir;



void Setup(){
    gameOver=false;
    dir=STOP;
    x=width/2;
    y=height/2;
    fruitX=rand()%width;
    fruitY=rand()%height;
    score=0;
    
}
void Draw(){
    system("cls");
    for(int i=0;i<width;i++)
        cout<<"#";
        cout<<endl;
        for(int i=0;i<height;i++){
            for(int j=0;j<width;j++){
                if(j==0||j==width-1)
                cout<<"#";
                else if(i==x&&j==y)
                cout<<"O";
                else if(i==fruitX&&j==fruitY)
                cout<<"F"; 
                else {
                    for(int k=0;k<ntail;k++){
                        bool print=false;
                        if(tailX[k]==j&&tailY[k]==i){
                            cout<<"o";
                            print=true;
                        }
                        if(!print){
                            cout<<" ";
                        }
                    }
                    
                }
            }
            cout<<endl;
        }
        
    for(int i=0;i<width;i++)
        cout<<"#";
        cout<<endl;
        
        cout<<"score:"<<score<<endl ;
    
    
}
void Input(){
    if(_kbhit()){

        switc(_getch()){
            case 'a':
            dir = LEFT;
            break;

            case 'w':
            dir=UP;
            break;
            
            case 's':
            dir=DOWN;
            break;
            
            case 'd':
            dir=RIGHT;
            break;
            
            case 'x':
            gameOver=true;
            break;

        }
    }
    
}
void Logic(){
    int prevX=tailX[0];
    int prevY=tailY[0];
    int prev2x,prev2y;
    tailX[0]=x;
    tailY[0]=y;
    for(int i=1;i<ntail;i++){
        prev2x=tailX[i];
        prev2y=tailY[i];
        tailX[i]=prevX;
        tailY[i]=prevY;
        prevX=prev2x;
        prevY=prev2y;
    }
   switch (dir)
   {
    case LEFT:
    x--;
    break;
    case RIGHT:
    x++;
    break;
    case UP:
    y++;
    break;
    case DOWN:
    y--;
    break;
    default:
    break;

   
   
   }
   if(x<0||x>width||y<0||y>height)
   gameOver=true; 
   for(int i=0;i<ntail;i++)
   if(tailX[i]==x&&tailY[i]==y)
   gameOver=true;
   if(x==fruitX&&y==fruitY){
       score+=10;
       ntail++;
       fruitY=rand()%height;
       fruitX=rand()%width;
   }
}

int main() {
Setup();
while(!gameOver){
    
    Draw();
    Input();
    Logic();
    
    
}
	return 0;
}
