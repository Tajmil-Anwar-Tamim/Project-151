#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;

while(1)
{
    int You=0,Com=0;
    int Dice,i,temp=0;
    cout<<"\a";

    while(1)
    {
        getch();
        cout<<"\a";

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

                //snakes
                if(You==97)You=12;
                if(You==63)You=3;
                if(You==70)You=25;
                if(You==32)You=13;
                if(You==60)You=38;
                if(You==89)You=53;
                if(You==73)You=47;
                if(You==82)You=43;


                //ladders
                if(You==8)You=41;
                if(You==50)You=93;
                if(You==6)You=16;
                if(You==55)You=80;
                if(You==59)You=84;
                if(You==26)You=29;

               //
               if(You>100) You-=Dice;
               cout<<"Your Possition = "<<You<<"(+"<<Dice<<")"<<"\t";
               if(You==100) {cout<<"\a\n\n\n\t\t\t\t\tCongratulation\n\t\t\t\t\tYou are Winner\n"; goto bye;}
            }
            if(i==2)
            {
                Dice=(rand()/3/temp)%6;//jodi randam number 2 khetrei same ache tai vinno songkha dara vag dichi
                Dice+=1;
                if(Com==0 && Dice!=1) Com-=Dice;//'1' sara guti ber hobe na
                Com+=Dice;

                //snakes
                if(Com==97)Com=12;
                if(Com==63)Com=3;
                if(Com==70)Com=25;
                if(Com==32)Com=13;
                if(Com==60)Com=38;
                if(Com==89)Com=53;
                if(Com==73)Com=47;
                if(Com==82)Com=43;


                //laders
                if(Com==8)Com=41;
                if(Com==50)Com=93;
                if(Com==6)Com=16;
                if(Com==55)Com=80;
                if(Com==59)Com=84;
                if(Com==26)Com=29;

               if(Com>100) Com-=Dice;
               cout<<"\tComputer Possition = "<<Com<<"(+"<<Dice<<")"<<"\t";
               if(Com==100) {cout<<"\a\n\n\n\t\t\t\t\t    Sorry\n\t\t\t\t\tYou are Loser\n"; goto bye;}
            }

        }
        cout<<endl;

    }

    bye:
    while(1)
    {
       getch();
    }

}





