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
    cout<<"\t\t\t\t\t\tSNAKE GAME [Box](10x10)\n\n";
    //cout<<"\t\t\t\t\t [Here You can move only '1' to '100']\n";
    cout<<"\t\t\t\t[Everytime You should press '1' to '9' for moving; \n\t\t\t\t 8'(up) or '2'(Down) or '4'(Left) or '6'(Right) or\n\t\t\t\t\t  '1'/'3'/'7'/'9' (Cross moving)\n\t\t\t\t\t (According to Keyboard Numarical Keys) ]\n";
    cout<<"\n\t\t\t\t [If Snake Bites it's Body or Border, then The Game is Over.]";

    new new new;
    temp++;

    Fruit  =  Randam_Function(Call);

    //Primary Declaration of Snake Body
    Snake_Body[1]  =  Snake_Head-1;
    Snake_Body[2]  =  Snake_Head-2;
    Snake_Body[3]  =  Snake_Head-3;

    while(1)
    {

        cyclebox://jate fruit snake er body borabor na ase
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
                goto cyclebox;
            }

        for(i = 0; i <= 100; i++)
        {
            Area[i] = ' ';
        }

        Area[Fruit] = temp%2+42; ///Fruit Symbol
        Area[Snake_Head] = 2; ///Snake Head Symbol

        for(i = Score+3; i>0; i--)
        {
            Area[Snake_Body[i]]  =  254;  ///Snake Body Symbol
        }
        Area[Snake_Body[Score+3]]  =  4;  ///Snake Tail Symbol

        new;
        TabM;  Brdr;  BrdrM;  new;
        TabM;  Brdr;

        for(i = 1; i <= 100; i++)
        {
           cout<<Area[i]<<" ";
           if(i%10  ==  0) {Brdr;  new;  TabM;  Brdr;  }
        }

        BrdrM new new

        TabM show

        if(Snake_Head > 100 || Snake_Head <= 0) break;

        cin>>Move;
        temp++; Change = 0;

        if(Move == '5' || Move == '0') continue;

        for(i = 3+Score; i>0; i--)
        {
            Snake_Body[i] =  Snake_Body[i-1];
        }
        Snake_Body[1] =  Snake_Head;

        if(Move == '6') {Snake_Head++;      if(Snake_Head%10 == 1){ Snake_Head = 0; continue; }}
        if(Move == '4') {Snake_Head--;      if(Snake_Head%10 == 0) { Snake_Head = 0; continue; }}
        if(Move == '2') {Snake_Head += 10;     }
        if(Move == '8') {Snake_Head -= 10;    }
        //otional
        if(Move == '3') {Snake_Head += 11;      if(Snake_Head%10 == 1){ Snake_Head = 0; continue; }}
        if(Move == '7') {Snake_Head -= 11;      if(Snake_Head%10 == 0) { Snake_Head = 0; continue; }}
        if(Move == '9') {Snake_Head -= 9;    if(Snake_Head%10 == 1) { Snake_Head = 0; continue; }}
        if(Move == '1') {Snake_Head += 9;    if(Snake_Head%10 == 0){ Snake_Head = 0; continue; }}

        if(Snake_Head > 100) continue;
        if(Snake_Head  <=   0) continue;

        for(i = 3 + Score; i > 0; i--)
        {
            if(Snake_Head == Snake_Body[i]) { Snake_Head = -100;  continue; }
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

    Sound
    if(Snake_Head == -100) cout<<"\n\n\t\t\t\t\t\t       TOUCH BODY!";
    else                 cout<<"\n\n\t\t\t\t\t\t       TOUCH BORDER!";
    cout<<"\n\t\t\t\t\t\t\tGAME OVER!"<<Move<<"\n\t\t\t\t\t\t\tSCORE : "<<Score<<endl;

    if(Score == 100)
    {
        Move = 2; //Smile Sign
        TabM cout<< "\tCongratulation!\n";
        TabM cout<<"\tHighest Score!"<<Move;
        new new
    }
    new new new
    getch();
}








