#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

int main()
{
    cout<<"\a\t\t\t\t\t\tLudu Snake-Ladder Game\n\n";
    cout<<"#Disclaimer: \t\tLudo is Haram Game for Muslim. So you should avoid to play this.\n\n";

    while(1)
    {

        int Number_of_Player;
        cout<<"Number of Player :\t";
        cin>>Number_of_Player;
        if(Number_of_Player<=0) return 0;
        cout<<"\nPress Any Key on Everytime :\n\n";
        cout<<"\a";

        int Board[Number_of_Player+1]={0},Temp=0;
        int Dice,i;

        while(1)
        {
            ///getch();
            Temp+=Number_of_Player*(Temp+1)+1;//not so necessary, you can also change 'c' differently
            Temp=Temp%99;//Minimized size, not so necessary, you can also change 'c' differently

            for(i=1;i<=Number_of_Player;i++)
            {
                Temp+=5;//not so necessary, you can also change 'c' differently
                getch();
                srand(time(NULL));

                    Dice=(rand()/(i+1)*i+rand()+Temp*Temp/i)%6;//just for different value of d in same time also,you can also change it differently but '%6' is must nedded
                    Dice+=1;//(0-5)-->(1-6)
                    if(Board[i]==0 && Dice!=1) Board[i]-=Dice;///'1' chara guti ber hobe na
                    Board[i]+=Dice;///position update

                    ///snakes
                    if(Board[i]==97)Board[i]=12;
                    if(Board[i]==63)Board[i]=3;
                    if(Board[i]==70)Board[i]=25;
                    if(Board[i]==32)Board[i]=13;
                    if(Board[i]==60)Board[i]=38;
                    if(Board[i]==89)Board[i]=53;
                    if(Board[i]==73)Board[i]=47;
                    if(Board[i]==82)Board[i]=43;


                    ///ladders
                    if(Board[i]==8)Board[i]=41;
                    if(Board[i]==50)Board[i]=93;
                    if(Board[i]==6)Board[i]=16;
                    if(Board[i]==55)Board[i]=80;
                    if(Board[i]==59)Board[i]=84;
                    if(Board[i]==26)Board[i]=29;


                   if(Board[i]>100) Board[i]-=Dice;///Don't cross 100
                   cout<<"Player-"<<i<<" : "<<Board[i]<<"(+"<<Dice<<")"<<"\t";///Print
                   if(Board[i]==100)///Winner
                        {cout<<"\a\n\n\n\t\t\t\t\t Congratulation!\n\t\t\t\t\tPlayer "<<i<<" is Winner\n\n\n"; goto again;}


            }
            cout<<endl;

        }


        again:
         //while(1)
        {
           getch();
        }
    }

}





