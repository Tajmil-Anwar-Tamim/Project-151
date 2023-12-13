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

using namespace std;

int main()
{
    new TabM cout<<" LUDO SNAKE-LADDER GAME"; new new
     while(1)
        {
            int You=0,Com=0;
            int Dice,i,x=0,temp=0;
            new TabM cout<<"Press Any Key on Everytime \n\n";
            Sound

            while(1)
            {
                getch();
                Sound

                for(i=1;i<=2;i++)
                {
                    //getch();
                    temp++;
                    srand(time(NULL));

                    if(i==1)
                    {
                        Dice=(rand()/2/temp)%6;//jodi randam number 2 khetrei same ache tai vinno songkha dara vag dichi
                        Dice+=1;
                        if(You==0 && Dice!=1) You-=Dice;//'1' sara guti ber hobe na
                        You+=Dice;

                        ///snakes
                        if(You==97)You=12;
                        if(You==63)You=3;
                        if(You==70)You=25;
                        if(You==32)You=13;
                        if(You==60)You=38;
                        if(You==89)You=53;
                        if(You==73)You=47;
                        if(You==82)You=43;


                        ///ladders
                        if(You==8)  You=41;
                        if(You==50) You=93;
                        if(You==6)  You=16;
                        if(You==55) You=80;
                        if(You==59) You=84;
                        if(You==26) You=29;


                       if(You>100) You-=Dice;
                       TabM2 cout<<"Your Possition = "<<You<<"(+"<<Dice<<")"<<"\t";
                       if(You==100)
                            {
                                Sound
                                new new new TabM cout<<"\tCongratulation!";
                                new TabM cout<<"\tYou are Winner.\n";
                                x=1;
                                break;
                            }
                    }

                    if(i==2)
                    {
                        Dice=(rand()/3/temp)%6;//jodi randam number 2 khetrei same ache tai vinno songkha dara vag dichi
                        Dice+=1;
                        if(Com==0 && Dice!=1) Com-=Dice;//'1' sara guti ber hobe na
                        Com+=Dice;

                        ///snakes
                        if(Com==97)Com=12;
                        if(Com==63)Com=3;
                        if(Com==70)Com=25;
                        if(Com==32)Com=13;
                        if(Com==60)Com=38;
                        if(Com==89)Com=53;
                        if(Com==73)Com=47;
                        if(Com==82)Com=43;


                        ///laders
                        if(Com==8)  Com=41;
                        if(Com==50) Com=93;
                        if(Com==6)  Com=16;
                        if(Com==55) Com=80;
                        if(Com==59) Com=84;
                        if(Com==26) Com=29;

                       if(Com>100) Com-=Dice;
                       cout<<"\tComputer Possition = "<<Com<<"(+"<<Dice<<")"<<"\t";
                       if(Com==100)
                        {
                            Sound
                            new new new TabM cout<<"\t\tSorry";
                            new TabM cout<<"\t  You are Loser\n";
                            x=1;
                            break;
                        }
                    }

                }
                if(x==1) break;
                new

            }
            x=0;
            new new new getch();
            TabM cout<<"To Play Again Press-'1';\n";
            TabM cout<<"To goto Menu  Press-'0';\n";
            int again;
            cin>>again;
            if(again==1) continue;
            else break;
        }
}





