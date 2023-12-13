#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
using namespace std;

#define show cout<<"\tScore : "<<Score<<endl<<endl;
#define BrdrM cout<<"o o o o o o o o o o o ";
#define Brdr cout<<"o ";
#define new cout<<"\n";
#define TabM cout<<"\t\t\t\t\t\t";
#define Sound cout<<"\a";

    int Fruit,Score = 0,temp,Finish,Call,Change,i,x = 0;
    int Snake_Head = 46;
    int Snake_Body[110] = {0};
    char Move;
    char Area[111]; //0,1-100,NULL+Primary body Size(5)+Extra for avoid silly risk

    int Randam_Function(int Return_Fruit)
    {
        srand(time(NULL));
        Return_Fruit  =  rand() % 100;
        Return_Fruit++;
        return Return_Fruit;
    }

int main()
{
    while(1)
        {
            int Fruit,Score = 0,temp=0,Finish=0,Call,Change=0,i,x = 0;
            int Snake_Head = 46;
            int Snake_Body[110] = {0};
            char Move;
            char PlayGround [111]; //0,1-100,NULL+Primary body Size(5)+Extra for avoid silly risk

            cout<<"\t\t\t\t\t\tSNAKE GAME [Classic](10x10)\n\n";
            cout<<"\t\t\t\t[Everytime You should press '1' to '9' for moving; \n\t\t\t\t 8'(up) or '2'(Down) or '4'(Left) or '6'(Right) or\n\t\t\t\t\t  '1'/'3'/'7'/'9' (Cross moving)\n\t\t\t\t\t (According to Keyboard Numarical Keys) ]\n";
            cout<<"\n\t\t\t\t [If Snake Bites it's Body, then The Game is Over.]";

            new new new;
            temp++;

            Fruit  =  Randam_Function(Call);

            //First Declaration of Snake Body
            Snake_Body[1]  =  Snake_Head-1;
            Snake_Body[2]  =  Snake_Head-2;
            Snake_Body[3]  =  Snake_Head-3;
            //Snake_Body[4]  =  Snake_Head-4;

            while(1)
            {
                cycle://jate fruit snake er body borabor na ase
                    Change++;
                    for(i = 3+Score; i>0; i--)
                    {
                        if(Fruit == Snake_Body[i]) {x = -1;  break; }
                    }
                    if((x == -1 || Fruit == Snake_Head) && Change <= 100 )
                    {
                        x = 0;
                        Fruit++;
                        Fruit = 1+Fruit%100;
                        goto cycle;
                    }

                for(i = 0; i <= 100; i++)
                {
                    PlayGround [i] = ' ';
                }

                PlayGround [Fruit] = temp%2+42; ///Fruit Symbol
                PlayGround [Snake_Head] = 2; ///Snake Head Symbol

                for(i = Score+3; i>0; i--)
                {
                    PlayGround [Snake_Body[i]]  =  254; ///Snake Body Symbol
                }
                PlayGround [Snake_Body[Score+3]] = 4; ///Snake Tail Symbol

                new;
                TabM;  Brdr;  BrdrM;  new;///Border
                TabM;  Brdr;

                for(i = 1; i <= 100; i++)
                {
                   cout<<PlayGround [i]<<" "; ///PlayGround
                   if(i%10  ==  0) {Brdr;  new;  TabM;  Brdr;  }
                }

                BrdrM new new

                TabM show///Show Score

                if(Finish == -100) break;

        //        cout<<"Press '8'(Up) or '2'(Down) or '4'(Left) or '6'(Right) or '1/3/7/9' (Cross moving) :\t";
                cin>>Move;
                temp++; Change = 0;

                if(Move == '5' || Move == '0') continue;

                for(i = 3+Score; i>0; i--)
                {
                    Snake_Body[i] =  Snake_Body[i-1];
                }
                Snake_Body[1] =  Snake_Head;

                if(Move == '6') {Snake_Head++;      if(Snake_Head%10 == 1)Snake_Head -= 10; }
                if(Move == '4') {Snake_Head--;      if(Snake_Head%10 == 0) Snake_Head += 10; }
                if(Move == '2') {Snake_Head += 10;    }
                if(Move == '8') {Snake_Head -= 10;    }

                //optional
                if(Move == '3') {Snake_Head += 11;   if(Snake_Head%10 == 1)Snake_Head -= 10; }
                if(Move == '7') {Snake_Head -= 11;   if(Snake_Head%10 == 0) Snake_Head += 10; }
                if(Move == '9') {Snake_Head -= 9;    if(Snake_Head%10 == 1)Snake_Head -= 10; }
                if(Move == '1') {Snake_Head += 9;    if(Snake_Head%10 == 0) Snake_Head += 10; }

                if(Snake_Head > 100) Snake_Head -= 100;
                if(Snake_Head <=  0) Snake_Head += 100;

                for(i = 3+Score; i>0; i--)
                {
                    if(Snake_Head == Snake_Body[i]) { Finish = -100; continue; }
                }

                if(Snake_Head == Fruit)
                {
                    Score++;
                    if(Score == 96) Score += 4; //Highest point 100 korar jonno;
                    Sound
                    Fruit =  Randam_Function(Call);

                }

            }


            Move = 1; //Smile Sign

            Sound;
            cout<<"\n\t\t\t\t\t\t\tGame Over!"<<Move<<"\n\t\t\t\t\t\t\tScore : "<<Score<<endl;  new

            if(Score >= 100)
            {
                Move = 2; //Smile Sign
                TabM cout<< "\tCongratulation!\n";
                TabM cout<<"\tHighest Score!"<<Move;
                new new
            }

            new new new
            getch();

            int again;
            TabM cout<<"To Play Again, Press- '1' \n";
            TabM cout<<"To close, Press- 'Any-Key' \n";
            TabM cin>>again;
            new new new
            if(again==1) continue;
            else break;
        }
}








