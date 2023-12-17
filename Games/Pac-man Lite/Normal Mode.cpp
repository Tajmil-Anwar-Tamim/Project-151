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
        int Score = 0,Temp=0,i,j,x = 0,Number_of_Enemy, Life=3,Level;
        int PacMan;
        char Move;
        char PlayGround[201],Fruit[201];                    /// Playground Size 10*10=100 (0-99) + ghost gulor dhakka khawar por randm possition ja (100 - 199) er moddhe thakbe
        //int Enemy[Number_of_Enemy];

        cout<<"\t\t\t\t\t\tPACMAN GAME (10x10) - Easy Mode\n\n";
        cout<<"\t\t\t\t\tEverytime You should press '1' to '9' for moving; \n\t\t\t\t 8'(up) or '2'(Down) or '4'(Left) or '6'(Right) or '5'(No Change) \n\t\t\t\t\t or '1'/'3'/'7'/'9' (Cross moving)\n\t\t\t\t\t(According to Keyboard Numarical Keys)\n";
        cout<<"\n\t\t\t\t If The Enemy Touch You, then You will Lost Your Life.\n";
        cout<<"\t\t\t\tIf The Enemy Touch Each Other, then They go away far from you\n";
        cout<<"\n\t\t\t\t     Your Target is to Eat all the Fruits on the Ground\n";


        new new new;

        new TabM cout<<"Choise Level";                      ///choise Level according to Number of ghost
        new TabM3 cout<<"Easy / Medium / Hard";
        new TabM2 cout<<"   Press - '1' / '2' / '3' : ";
        cin>>Level;
        new new

        if      (Level<=0) break;                           ///If You want to close the Program
        else if (Level==1) {TabM cout<<"EASY LEVEL\n";}
        else if (Level==2) {TabM cout<<"MEDIUM LEVEL\n";}
        else               {TabM cout<<"HARD LEVEL\n";}
        new

        for(i = 0; i < 100; i++)                            ///Initially sob gulo ghorei dote dekhabe
        {
            Fruit[i]=1;                                     ///'1' mane oi possition a fruit ache
        }

        pac_start:                                          ///if Pacman Lost his Life then Program Start from here

        if(Level==1)
        {
            Number_of_Enemy=2;                          ///Easy Level a 2 ta vut thakbe
            int Enemy[Number_of_Enemy];
            Enemy[0] = 0;
            Enemy[1] = 99;                              ///vut gulor initial possiton
        }

        else if(Level==2)
        {
            Number_of_Enemy=4;                          ///Medium Level a 4 ta vut thakbe
            int Enemy[Number_of_Enemy];
            Enemy[0] = 0;
            Enemy[1] = 99;
            Enemy[2] = 9;
            Enemy[3] = 90;                              ///vut gulor initial possiton
        }

        else
        {
            Number_of_Enemy=8;                          ///Hard Level a 8 ta vut thakbe
            int Enemy[Number_of_Enemy];
            Enemy[0] = 0;
            Enemy[1] = 99;
            Enemy[2] = 9;
            Enemy[3] = 90;
            Enemy[4] = 5;
            Enemy[5] = 95;
            Enemy[6] = 40;
            Enemy[7] = 49;                              ///vut gulor initial possiton
        }

        int Enemy[Number_of_Enemy];
        PacMan = 45;                                    ///Pacman er initial possition
        Temp=0;


        while(1)                                        ///protibar Move korar por Program ekhane chole asbe
        {

            for(i = 0; i < 100; i++)
            {
                PlayGround[i] = ' ';
            }

            for(i = 0; i < 100; i++)
            {
                if(Fruit[i] == 1) PlayGround[i] = '.';          ///jodi Fruit thake tobe Dot Sign dekhabe
            }

            PlayGround[PacMan] = 1;                         ///PacMan Symbol (Smile face Black)

            for(i=0;i<Number_of_Enemy;i++)
            {
                PlayGround[Enemy[i]] = 2;                   ///Enemy Symbol (Smile face White)
            }

            new;
            TabM;  Brdr;  BrdrM;  new;                      ///Border
            TabM;  Brdr;

            for(i = 0; i < 100; i++)
            {
               cout<<PlayGround[i]<<" ";                    ///Print PlayGround
               if(i%10 == 9) {Brdr;  new;  TabM;  Brdr;  }  ///proti 10 ghor por por new line asbe (jehutu Column 10 ta)
            }

            BrdrM new new

            TabM showScore                  ///Show Current Score
            TabM showLife                   ///Show Pacman remaining Life


            if(Life == 0)       break;              ///Remaining Life '0' hole khela sesh
            if(Score == 100)    break;              ///Sob fruit gulo khele khela sesh hobe
            if(Temp == -1)      goto pac_start;     ///jodi pacman er life kome jay tobe possition reform hobe


            for(i=0;i<Number_of_Enemy;i++)
            {
                if      (Enemy[i] /10 - PacMan/10 > 0) Enemy[i] -=10; ///Jodi Ghost er RowNumber Amar RowNumber theke BESHI hoy, tobe tar RowNumber Kombe & Amar Nikote asbe
                else if (Enemy[i] /10 - PacMan/10 < 0) Enemy[i] +=10; ///Jodi Ghost er RowNumber Amar RowNumber theke KOM   hoy, tobe tar RowNumber Barbe & Amar Nikote asbe
                                                                      ///R Same RowNumber hole No Change

                if      (Enemy[i] %10 - PacMan%10 > 0) Enemy[i] --;   ///Jodi Ghost er Column Number Amar Column Number theke BESHI hoy,tobe tar Column Number Kombe & Amar Nikote asbe
                else if (Enemy[i] %10 - PacMan%10 < 0) Enemy[i] ++;   ///Jodi Ghost er Column Number Amar Column Number theke  KOM  hoy,tobe tar Column Number Barbe & Amar Nikote asbe
                                                                      ///R Same Column Number hole No Change
            }

            cin>>Move;

            if(Move == 'x' || Move == 'X') {Life=0; break;} ///if You want to Close the Game press 'x'/'X';

            if(Move == '6') {PacMan++;        /** to move Right*/     if(PacMan%10 == 0)      PacMan --; /** Dont cross right border Right*/  }
            if(Move == '4') {PacMan--;        /** to move Left */     if((PacMan+20)%10 == 9) PacMan ++; /** Dont cross right border Right*/  } ///'-' Value Avoiding er jonno +20 dichi
            if(Move == '2') {PacMan += 10; }  /**to move Down  */
            if(Move == '8') {PacMan -= 10; }  /**to move Up    */

            //optional
            if(Move == '3') {PacMan += 11; /** to move Right-Down*/     if(PacMan%10      == 0)    PacMan --; }
            if(Move == '7') {PacMan -= 11; /** to move Left-Up   */     if((PacMan+20)%10 == 9)    PacMan ++; }
            if(Move == '9') {PacMan -= 9;  /** to move Right-Up  */     if((PacMan+20)%10 == 0)    PacMan --; }
            if(Move == '1') {PacMan += 9;  /** to move Left-Down */     if(PacMan%10      == 9)    PacMan ++; }

            if(PacMan >= 100) PacMan -= 10; ///Don't cross Down-Border
            if(PacMan <  0) PacMan += 10;   ///Don't cross Upper-Border

            for(i=0; i<100; i++)
            {
                if(PacMan == i && Fruit[i] == 1)/// jodi Pacman er position-a fruit thake
                {
                    Score++;                    /// tobe Score 1 barbe
                    Fruit[i]=0;                 /// & Fruit ta delete hoye jabe
                }
            }

            for(i=0;i<Number_of_Enemy;i++)
            {
                if(PacMan == Enemy[i] )     /// jodi Ghost Pacman er body touch kore
                {
                    Temp = -1;
                    Life --;                /// tobe Life kome jabe
                    break;
                }
            }


            for(i=0;i<Number_of_Enemy;i++)
            {
                for(j=i+1;j<Number_of_Enemy;j++)
                {

                    if(Enemy[i] == Enemy[j] && Temp != -1  )  ///Jodi Ghost gulor moddhe dhakka lage
                    {
                        Enemy[i] = 109 + 10*Number_of_Enemy-i;   ///tobe tara dure chole jabe & punaray nich theke ground a chole asar chestha korbe
                        Enemy[j] = 110 + 10*Number_of_Enemy+j;   /// "  "

                        Sound
                    }
                }
            }
        }

        if(Life==0)
        {
            Move = 2; ///Ghost Sign (white-Smile)
            Sound;
            cout<<"\n\t\t\t\t\t\t\tGame Over!"<<Move<<"\n\t\t\t\t\t\t\tScore : "<<Score<<endl;  new
        }

        if(Score == 100)
        {
            Sound
            Move = 1; /// Pacman sign (black-Smile)
            TabM cout<< "\tCongratulation!\n";
            TabM cout<<"\tHighest Score!"<<Move; ///100 is highest score , because there are 100 fruit in the ground
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
