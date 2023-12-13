#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

#define showScore cout<<"\tScore : "<<Score<<endl;
#define showLife cout<<"\t Life : "<<Life<<endl<<endl;
#define BrdrM cout<<"o o o o o o o o o o o ";
#define Brdr cout<<"o ";
#define new cout<<"\n";
#define TabM cout<<"\t\t\t\t\t\t";
#define Sound cout<<"\a";

int main()
{

    while(1)
    {
        int Score = 0,Temp,i,j,x = 0,Number_of_Enemy=2,Life=3;
        int PacMan;
        char Move;
        char PlayGround[201],Fruit[201];
        int Enemy[Number_of_Enemy];

        cout<<"\t\t\t\t\tPacMan GAME (10x10) - Expert Mode\n\n";
        cout<<"\t\t\t\t\t Ghosts are understoood about your Next Move\n";
        cout<<"\t\t\t\t\tEverytime You should press '1' to '9' for moving; \n\t\t\t\t 8'(up) or '2'(Down) or '4'(Left) or '6'(Right) or '5'(No Change) \n\t\t\t\t\t or '1'/'3'/'7'/'9' (Cross moving)\n\t\t\t\t\t(According to Keyboard Numarical Keys)\n";
        cout<<"\n\t\t\t\t If Any of two ghost Touch You, then You will Lost Your Life.\n";
        cout<<"\t\t\t\tIf The Enemy Touch Each Other, then They go away far from you\n";
        cout<<"\n\t\t\t\tYour Target is to Eat all the Fruits on the Ground & You have 3 Life\n";


        new new new;

        for(i = 0; i < 100; i++)
        {
            Fruit[i]=1;
        }

        start:

        Enemy[0] = 0;
        Enemy[1] = 99;
        PacMan = 45;
        Temp=0;


        while(1)
        {

            for(i = 0; i < 100; i++)
            {
                PlayGround[i] = ' ';
            }

            for(i = 0; i < 100; i++)
            {
                if(Fruit[i] == 1) PlayGround[i] = '.';
            }

            PlayGround[PacMan] = 1; ///PacMan Symbol

            for(i=0;i<Number_of_Enemy;i++)
            {
                PlayGround[Enemy[i]] = 2;///Enemy Symbol
            }

            new;
            TabM;  Brdr;  BrdrM;  new;///Border
            TabM;  Brdr;

            for(i = 0; i < 100; i++)
            {
               cout<<PlayGround[i]<<" "; ///Print PlayGround
               if(i%10 == 9) {Brdr;  new;  TabM;  Brdr;  }
            }

            BrdrM new new

            TabM showScore///Show Score
            TabM showLife


            if(Life == 0) break;
            if(Score == 100) break;
            if(Temp == -1) goto start;

            cin>>Move;

            if(Move == '5' || Move == '0') ;

            if(Move == '6') {PacMan++;      if(PacMan%10 == 0)PacMan -=10; }
            if(Move == '4') {PacMan--;      if((PacMan+20)%10 == 9) PacMan +=10; }
            if(Move == '2') {PacMan += 10;    }
            if(Move == '8') {PacMan -= 10;    }

            //optional
            if(Move == '3') {PacMan += 11;   if(PacMan%10 == 0)PacMan -=10; }
            if(Move == '7') {PacMan -= 11;   if((PacMan+20)%10 == 9) PacMan +=10; }
            if(Move == '9') {PacMan -= 9;    if((PacMan+20)%10 == 0)PacMan -=10; }
            if(Move == '1') {PacMan += 9;    if(PacMan%10 == 9) PacMan +=10; }

            if(PacMan >= 100) PacMan -= 100 ;
            if(PacMan <  0) PacMan += 100;

            for(i=0;i<Number_of_Enemy;i++)
            {
                if(Enemy[i] /10-PacMan/10 > 0) Enemy[i] -=10;
                else if (Enemy[i] /10 -PacMan/10 < 0) Enemy[i] +=10;

                if(Enemy[i] %10-PacMan%10 > 0) Enemy[i] --;
                else if (Enemy[i] %10-PacMan%10 < 0) Enemy[i] ++;
            }

            for(i=0; i<100; i++)
            {
                if(PacMan == i && Fruit[i] == 1)
                {
                    Score++;
                    Fruit[i]=0;
                }
            }

            for(i=0;i<Number_of_Enemy;i++)
            {
                if(PacMan == Enemy[i] )
                {
                    Temp = -1;
                    Life --;
                    break;
                }
            }

            for(i=0;i<Number_of_Enemy;i++)
            {
                for(j=i+1;j<Number_of_Enemy;j++)
                {
                    if(Enemy[i] == Enemy[j] && Temp != -1  )
                    {
                        Enemy[i] = 189;
                        Enemy[j] = 190;
                        Sound
                    }
                }
            }

        }

        if(Life==0)
        {
            Move = 2; //Smile Sign
            Sound;
            cout<<"\n\t\t\t\t\t\t\tGame Over!"<<Move<<"\n\t\t\t\t\t\t\tScore : "<<Score<<endl;  new
        }

        if(Score == 100)
        {
            Sound
            Move = 1; //Smile Sign
            TabM cout<< "\tCongratulation!\n";
            TabM cout<<"\tHighest Score!"<<Move;
            new new
        }

        int again;
        new new new getch();
        TabM cout<<"To Play Again Press-'1'\n";
        TabM cout<<"To Close Press-'Any Key'\n";
        TabM;
        cin>>again;
        new new new
        if(again==1) continue;
        else break;
    }
}









