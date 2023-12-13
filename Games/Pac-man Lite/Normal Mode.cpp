#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define TabM cout<<"\t\t\t\t\t\t";
#define TabM2 cout<<"\t\t\t\t     ";
#define TabM3 cout<<"\t\t\t\t\t  ";
#define TabM4 cout<<"\t\t\t\t ";

#define new cout<<"\n";
#define Sound cout<<"\a";

#define BrdrM cout<<"o o o o o o o o o o o ";
#define Brdr cout<<"o ";

#define showScore cout<<"\tScore : "<<Score<<endl;
#define showLife cout<<"\t Life : "<<Life<<endl<<endl;

using namespace std;
int main()
{
    while(1)
    {
        int Score = 0,Temp=0,i,j,x = 0,Number_of_Enemy,Life=3,Level;
        int PacMan;
        char Move;
        char PlayGround[201],Fruit[201];
        //int Enemy[Number_of_Enemy];

        cout<<"\t\t\t\t\t\tPACMAN GAME (10x10) - Easy Mode\n\n";
        cout<<"\t\t\t\t\tEverytime You should press '1' to '9' for moving; \n\t\t\t\t 8'(up) or '2'(Down) or '4'(Left) or '6'(Right) or '5'(No Change) \n\t\t\t\t\t or '1'/'3'/'7'/'9' (Cross moving)\n\t\t\t\t\t(According to Keyboard Numarical Keys)\n";
        cout<<"\n\t\t\t\t If The Enemy Touch You, then You will Lost Your Life.\n";
        cout<<"\t\t\t\tIf The Enemy Touch Each Other, then They go away far from you\n";
        cout<<"\n\t\t\t\t     Your Target is to Eat all the Fruits on the Ground\n";


        new new new;

        new TabM cout<<"Choise Level";
        new TabM3 cout<<"Easy / Medium / Hard";
        new TabM2 cout<<"   Press - '1' / '2' / '3' : ";
        cin>>Level;
        new new
        if      (Level<=0) break;
        else if (Level==1) {TabM cout<<"EASY LEVEL\n";}
        else if (Level==2) {TabM cout<<"MEDIUM LEVEL\n";}
        else               {TabM cout<<"HARD LEVEL\n";}
        new

        for(i = 0; i < 100; i++)
        {
            Fruit[i]=1;
        }

        pac_start:

        if(Level==1)
        {
            Number_of_Enemy=2;
            int Enemy[Number_of_Enemy];
            Enemy[0] = 0;
            Enemy[1] = 99;
        }

        else if(Level==2)
        {
            Number_of_Enemy=4;
            int Enemy[Number_of_Enemy];
            Enemy[0] = 0;
            Enemy[1] = 99;
            Enemy[2] = 9;
            Enemy[3] = 90;
        }

        else
        {
            Number_of_Enemy=8;
            int Enemy[Number_of_Enemy];
            Enemy[0] = 0;
            Enemy[1] = 99;
            Enemy[2] = 9;
            Enemy[3] = 90;
            Enemy[4] = 5;
            Enemy[5] = 95;
            Enemy[6] = 40;
            Enemy[7] = 49;
        }

        int Enemy[Number_of_Enemy];
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

            if(Temp!=-1) PlayGround[PacMan] = 1; ///PacMan Symbol

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
            if(Temp == -1) goto pac_start;


            for(i=0;i<Number_of_Enemy;i++)
            {
                if(Enemy[i] /10-PacMan/10 > 0) Enemy[i] -=10;
                else if (Enemy[i] /10 -PacMan/10 < 0) Enemy[i] +=10;

                if(Enemy[i] %10-PacMan%10 > 0) Enemy[i] --;
                else if (Enemy[i] %10-PacMan%10 < 0) Enemy[i] ++;
            }

            cin>>Move;

            if(Move == '5' || Move == '0') ;

            if(Move == '6') {PacMan++;      if(PacMan%10 == 0)PacMan --; }
            if(Move == '4') {PacMan--;      if((PacMan+20)%10 == 9) PacMan ++; }
            if(Move == '2') {PacMan += 10;    }
            if(Move == '8') {PacMan -= 10;    }

            //optional
            if(Move == '3') {PacMan += 11;   if(PacMan%10 == 0)PacMan --; }
            if(Move == '7') {PacMan -= 11;   if((PacMan+20)%10 == 9) PacMan ++; }
            if(Move == '9') {PacMan -= 9;    if((PacMan+20)%10 == 0)PacMan --; }
            if(Move == '1') {PacMan += 9;    if(PacMan%10 == 9) PacMan ++; }

            if(PacMan >= 100) PacMan -= 10;
            if(PacMan <  0) PacMan += 10;///Don't cross Border

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
                        Enemy[i] = 109 + Number_of_Enemy;
                        Enemy[j] = 110 + Number_of_Enemy;
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
        TabM; cin>>again;
        new new new
        if(again==1) continue;
        else break;
    }
}
