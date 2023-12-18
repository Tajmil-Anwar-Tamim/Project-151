#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define TabM cout<<"\t\t\t\t\t\t";      ///Multiple Tab (just for design - to show text / graph in Middle)
#define TabM2 cout<<"\t\t\t\t     ";    /// " "
#define TabM3 cout<<"\t\t\t\t\t  ";     /// " "
#define TabM4 cout<<"\t\t\t\t ";        /// " " //we use different types of multiple tabs according to sentence wide
#define new cout<<"\n";                 ///new line

#define StrM cout<<"* * * * ";          ///Grid border
#define Str cout<<"* ";                 /// " "

#define Sound cout<<"\a";               ///Alert Sound

using namespace std;

int Randam_Func(int a)    /// this function give us a value from 1 to 9 randamly
{
    srand(time(NULL));
    a = rand() % 9;
    a++;
    return a;
}

int main()
{
    while(1)
    {
        int i,Me=0,Computer=0,Time=0,Win_I=0,Win_Com=0,Call,Level;
        char who,Grid_Data[10]; ///who uses for who play first
        char Grid_Symbol[10];   ///Box-Symbol String (show 'x','o',' ')

        cout<<"\t\t\t\t\t       TIC TAC TIC\n\n";
        cout<<"\t\t\t  "; cout<<"[Everytime Press '1' to '9' For Push Your Symbol in the Box] "<<endl<<endl;


            ///Show the Grid Numbers (below)
            TabM Str StrM new
            TabM Str cout<<"1 2 3 "; Str new
            TabM Str cout<<"4 5 6 "; Str new
            TabM Str cout<<"7 8 9 "; Str new
            TabM Str StrM new new

            for(i=0;i<=9;i++)
            {
                Grid_Data[i]=0;
            }

//           new cout<<"\t\t\t  "; cout<<"[Everytime Press '1' to '9' For Push Your Symbol in the Box] "<<endl<<endl;

            Print_Loop:///Print_Update

            Grid_Data[Me]=1;
            Grid_Data[Computer]=2;

            for(i=0;i<=9;i++)
            {
                if(Grid_Data[i] == 0) Grid_Symbol[i]=' ';///Unfilled
                if(Grid_Data[i] == 1) Grid_Symbol[i]='x';///Your Filled Symbol
                if(Grid_Data[i] == 2) Grid_Symbol[i]='o';///Computer Filled Symbol

            }

            new
            Sound
            TabM Str StrM new ///Grid Border Degign
            TabM Str
            for(i=1;i<=9;i++)
            {
               cout<<Grid_Symbol[i]<<" ";
               if(i%3 == 0) {Str new TabM Str }
            }

            StrM new new

            if(Time==0)///only first time show these (below)
                {
                    new TabM cout<<"Choise Level";
                    new TabM3 cout<<"Easy / Medium / Hard";
                    new TabM2 cout<<"   Press - '1' / '2' / '3' : ";
                    cin>>Level;
                    new new

                    if      (Level<=0) break; ///if you want to close the game
                    else if (Level==1) {TabM cout<<"EASY LEVEL\n";}
                    else if (Level==2) {TabM cout<<"MEDIUM LEVEL\n";}
                    else               {TabM cout<<"HARD LEVEL\n";}
                    new

                    ///who play
                    TabM3 cout<<"  Who Play First?\n";
                    TabM3 cout<< "('You'/'Computer')\n";
                    TabM4 cout<<"Press 'I' for 'You' or 'C' for 'Computer'\n";
                    TabM4 cout<<"     Press 'Other Any Key' for Tossing\n";
                    TabM3 cout<<" (Without Quatation) :\n\n";
                    TabM  cout<<"   ";

                    cin>>who;
                    who=tolower(who);
                    if(who!='i' && who!='c') ///Tossing
                    {
                        srand(time(NULL));
                        if(rand() %2 == who %2 ) {new TabM3 cout<<"  You won the Toss\n" ;who='i';}
                        else {new TabM3 cout<<"Computer won the Toss\n" ; who='c';}
                    }
                }

            if(Time == 0 && who == 'c') goto Com;
            if(Time == 0) ;
            else if(Time%2 == 1 && who == 'c' || Time%2 == 0 && who!='c') goto Come_Back_2;
            else goto Come_Back_1;



        while(1)
        {
            You:
                Time++; ///kotota ghor fill up holo- seta count kora hocche

                ReCall_Me:

                    new new TabM3 cout<<"Your Choise   :\t";
                    cin>>Me;
//                    Me = Me % 10;
                    if(Me<0 || Me >= 10)
                    {new TabM cout<<"Wrong Input"; break; }              /// jodi wrong chal dewa hoy, then- game close hobe


                    if(Grid_Data[Me] != 0)                      ///jodi ghor-tite already chal dewa hoye thake
                    {cout<<"Already Exist\n\n";goto ReCall_Me;} ///tobe accept hobe na, punoray chal dewa lagbe

                Grid_Data[Me]=1;  ///Grid-tate Amar chal input holo

                goto Print_Loop;  ///for printing update result

                Come_Back_1:      ///print kore punoray fire asa

                    if(Grid_Data[1] == 1 && Grid_Data[2] == 1 && Grid_Data[3] == 1 || Grid_Data[4] == 1 && Grid_Data[5] == 1 && Grid_Data[6] == 1 || Grid_Data[7] == 1 && Grid_Data[8] == 1 && Grid_Data[9] == 1 || Grid_Data[1] == 1 && Grid_Data[4] == 1 && Grid_Data[7] == 1 || Grid_Data[2] == 1 && Grid_Data[5] == 1 && Grid_Data[8] == 1 || Grid_Data[3] == 1 && Grid_Data[6] == 1 && Grid_Data[9] == 1 ||  Grid_Data[3] == 1 && Grid_Data[5] == 1 && Grid_Data[7] == 1 || Grid_Data[1] == 1 && Grid_Data[5] == 1 && Grid_Data[9] == 1 )
                    {
                        Win_I++;
                        break;       ///Ami jitle game finished hobe
                    }
                if(Time == 9) break; ///sob (9ta) ghor puron holegame finished

            Com:
                Time++;                 ///kotobar chal dewa holo/ kotota grid puron holo, seta count kora hocche

                if(Level==1)            ///Easy mode : Computer sob chal randamly dibe
                {
                    while(1)
                        {
                            Computer = Randam_Func(Call);
                            if(Grid_Data[Computer] == 0 ) break;
                        }
                }

                else if(Level==2)       ///Medium Level : kichuta buddhimotta apply korbe computer, bad computer a bishesh koushole fade fele harano somvob
                {
                    ///Attack of Computer (Computer er nije jitar Formula gulo)
                    if     (Grid_Data[1] == 2 && Grid_Data[2] == 2 && Grid_Data[3] == 0)  { Grid_Data[3] = 2; Computer =3;}
                    else if(Grid_Data[1] == 2 && Grid_Data[3] == 2 && Grid_Data[2] == 0)  { Grid_Data[2] = 2; Computer =2;}
                    else if(Grid_Data[2] == 2 && Grid_Data[3] == 2 && Grid_Data[1] == 0)  { Grid_Data[1] = 2; Computer =1;}
                    else if(Grid_Data[4] == 2 && Grid_Data[5] == 2 && Grid_Data[6] == 0)  { Grid_Data[6] = 2; Computer =6;}
                    else if(Grid_Data[4] == 2 && Grid_Data[6] == 2 && Grid_Data[5] == 0)  { Grid_Data[5] = 2; Computer =5;}
                    else if(Grid_Data[5] == 2 && Grid_Data[6] == 2 && Grid_Data[4] == 0)  { Grid_Data[4] = 2; Computer =4;}
                    else if(Grid_Data[7] == 2 && Grid_Data[8] == 2 && Grid_Data[9] == 0)  { Grid_Data[9] = 2; Computer =9;}
                    else if(Grid_Data[7] == 2 && Grid_Data[9] == 2 && Grid_Data[8] == 0)  { Grid_Data[8] = 2; Computer =8;}
                    else if(Grid_Data[8] == 2 && Grid_Data[9] == 2 && Grid_Data[7] == 0)  { Grid_Data[7] = 2; Computer =7;}
                    else if(Grid_Data[1] == 2 && Grid_Data[4] == 2 && Grid_Data[7] == 0)  { Grid_Data[7] = 2; Computer =7;}
                    else if(Grid_Data[1] == 2 && Grid_Data[7] == 2 && Grid_Data[4] == 0)  { Grid_Data[4] = 2; Computer =4;}
                    else if(Grid_Data[4] == 2 && Grid_Data[7] == 2 && Grid_Data[1] == 0)  { Grid_Data[1] = 2; Computer =1;}
                    else if(Grid_Data[2] == 2 && Grid_Data[5] == 2 && Grid_Data[8] == 0)  { Grid_Data[8] = 2; Computer =8;}
                    else if(Grid_Data[2] == 2 && Grid_Data[8] == 2 && Grid_Data[5] == 0)  { Grid_Data[5] = 2; Computer =5;}
                    else if(Grid_Data[5] == 2 && Grid_Data[8] == 2 && Grid_Data[2] == 0)  { Grid_Data[2] = 2; Computer =2;}
                    else if(Grid_Data[3] == 2 && Grid_Data[6] == 2 && Grid_Data[9] == 0)  { Grid_Data[9] = 2; Computer =9;}
                    else if(Grid_Data[3] == 2 && Grid_Data[9] == 2 && Grid_Data[6] == 0)  { Grid_Data[6] = 2; Computer =6;}
                    else if(Grid_Data[6] == 2 && Grid_Data[9] == 2 && Grid_Data[3] == 0)  { Grid_Data[3] = 2; Computer =3;}
                    else if(Grid_Data[1] == 2 && Grid_Data[5] == 2 && Grid_Data[9] == 0)  { Grid_Data[9] = 2; Computer =9;}
                    else if(Grid_Data[1] == 2 && Grid_Data[9] == 2 && Grid_Data[5] == 0)  { Grid_Data[5] = 2; Computer =5;}
                    else if(Grid_Data[5] == 2 && Grid_Data[9] == 2 && Grid_Data[1] == 0)  { Grid_Data[1] = 2; Computer =1;}
                    else if(Grid_Data[3] == 2 && Grid_Data[5] == 2 && Grid_Data[7] == 0)  { Grid_Data[7] = 2; Computer =7;}
                    else if(Grid_Data[3] == 2 && Grid_Data[7] == 2 && Grid_Data[5] == 0)  { Grid_Data[5] = 2; Computer =5;}
                    else if(Grid_Data[5] == 2 && Grid_Data[7] == 2 && Grid_Data[3] == 0)  { Grid_Data[3] = 2; Computer =3;}

                    ///Depends of Computer(computer er amar jita atkanor formula gulo)
                    else if(Grid_Data[1] == 1 && Grid_Data[2] == 1 && Grid_Data[3] == 0)  { Grid_Data[3] = 2; Computer =3;}
                    else if(Grid_Data[1] == 1 && Grid_Data[3] == 1 && Grid_Data[2] == 0)  { Grid_Data[2] = 2; Computer =2;}
                    else if(Grid_Data[2] == 1 && Grid_Data[3] == 1 && Grid_Data[1] == 0)  { Grid_Data[1] = 2; Computer =1;}
                    else if(Grid_Data[4] == 1 && Grid_Data[5] == 1 && Grid_Data[6] == 0)  { Grid_Data[6] = 2; Computer =6;}
                    else if(Grid_Data[4] == 1 && Grid_Data[6] == 1 && Grid_Data[5] == 0)  { Grid_Data[5] = 2; Computer =5;}
                    else if(Grid_Data[5] == 1 && Grid_Data[6] == 1 && Grid_Data[4] == 0)  { Grid_Data[4] = 2; Computer =4;}
                    else if(Grid_Data[7] == 1 && Grid_Data[8] == 1 && Grid_Data[9] == 0)  { Grid_Data[9] = 2; Computer =9;}
                    else if(Grid_Data[7] == 1 && Grid_Data[9] == 1 && Grid_Data[8] == 0)  { Grid_Data[8] = 2; Computer =8;}
                    else if(Grid_Data[8] == 1 && Grid_Data[9] == 1 && Grid_Data[7] == 0)  { Grid_Data[7] = 2; Computer =7;}
                    else if(Grid_Data[1] == 1 && Grid_Data[4] == 1 && Grid_Data[7] == 0)  { Grid_Data[7] = 2; Computer =7;}
                    else if(Grid_Data[1] == 1 && Grid_Data[7] == 1 && Grid_Data[4] == 0)  { Grid_Data[4] = 2; Computer =4;}
                    else if(Grid_Data[4] == 1 && Grid_Data[7] == 1 && Grid_Data[1] == 0)  { Grid_Data[1] = 2; Computer =1;}
                    else if(Grid_Data[2] == 1 && Grid_Data[5] == 1 && Grid_Data[8] == 0)  { Grid_Data[8] = 2; Computer =8;}
                    else if(Grid_Data[2] == 1 && Grid_Data[8] == 1 && Grid_Data[5] == 0)  { Grid_Data[5] = 2; Computer =5;}
                    else if(Grid_Data[5] == 1 && Grid_Data[8] == 1 && Grid_Data[2] == 0)  { Grid_Data[2] = 2; Computer =2;}
                    else if(Grid_Data[3] == 1 && Grid_Data[6] == 1 && Grid_Data[9] == 0)  { Grid_Data[9] = 2; Computer =9;}
                    else if(Grid_Data[3] == 1 && Grid_Data[9] == 1 && Grid_Data[6] == 0)  { Grid_Data[6] = 2; Computer =6;}
                    else if(Grid_Data[6] == 1 && Grid_Data[9] == 1 && Grid_Data[3] == 0)  { Grid_Data[3] = 2; Computer =3;}
                    else if(Grid_Data[1] == 1 && Grid_Data[5] == 1 && Grid_Data[9] == 0)  { Grid_Data[9] = 2; Computer =9;}
                    else if(Grid_Data[1] == 1 && Grid_Data[9] == 1 && Grid_Data[5] == 0)  { Grid_Data[5] = 2; Computer =5;}
                    else if(Grid_Data[5] == 1 && Grid_Data[9] == 1 && Grid_Data[1] == 0)  { Grid_Data[1] = 2; Computer =1;}
                    else if(Grid_Data[3] == 1 && Grid_Data[5] == 1 && Grid_Data[7] == 0)  { Grid_Data[7] = 2; Computer =7;}
                    else if(Grid_Data[3] == 1 && Grid_Data[7] == 1 && Grid_Data[5] == 0)  { Grid_Data[5] = 2; Computer =5;}
                    else if(Grid_Data[5] == 1 && Grid_Data[7] == 1 && Grid_Data[3] == 0)  { Grid_Data[3] = 2; Computer =3;}

                    else if(Time==9)                ///seshe je ghor faka thakbe setate chalbe (time complexity komanor jonno just, not so necessary)
                        {   for(i=1;i<=9;i++)   {if(Grid_Data[i] == 0) Computer=i;}  }

                    else                            /// kono shortoi na mille randamly chal dibe computer
                    {
                        while(1)
                        {
                            Computer = Randam_Func(Call);
                            if(Grid_Data[Computer] == 0 ) break;
                        }
                    }

                }

                else            ///Hard Level (Harano osomvob - hoy com. jitbe nahoy draw) - Medium er sathe aro kichu shorto add kora hoyeche jate com. ke fade feleo harano na jay)
                {
                    ///Attacks
                    if     (Grid_Data [1] == 2 && Grid_Data [2] == 2 && Grid_Data [3] == 0)  { Grid_Data [3] = 2; Computer =3;}
                    else if(Grid_Data [1] == 2 && Grid_Data [3] == 2 && Grid_Data [2] == 0)  { Grid_Data [2] = 2; Computer =2;}
                    else if(Grid_Data [2] == 2 && Grid_Data [3] == 2 && Grid_Data [1] == 0)  { Grid_Data [1] = 2; Computer =1;}
                    else if(Grid_Data [4] == 2 && Grid_Data [5] == 2 && Grid_Data [6] == 0)  { Grid_Data [6] = 2; Computer =6;}
                    else if(Grid_Data [4] == 2 && Grid_Data [6] == 2 && Grid_Data [5] == 0)  { Grid_Data [5] = 2; Computer =5;}
                    else if(Grid_Data [5] == 2 && Grid_Data [6] == 2 && Grid_Data [4] == 0)  { Grid_Data [4] = 2; Computer =4;}
                    else if(Grid_Data [7] == 2 && Grid_Data [8] == 2 && Grid_Data [9] == 0)  { Grid_Data [9] = 2; Computer =9;}
                    else if(Grid_Data [7] == 2 && Grid_Data [9] == 2 && Grid_Data [8] == 0)  { Grid_Data [8] = 2; Computer =8;}
                    else if(Grid_Data [8] == 2 && Grid_Data [9] == 2 && Grid_Data [7] == 0)  { Grid_Data [7] = 2; Computer =7;}
                    else if(Grid_Data [1] == 2 && Grid_Data [4] == 2 && Grid_Data [7] == 0)  { Grid_Data [7] = 2; Computer =7;}
                    else if(Grid_Data [1] == 2 && Grid_Data [7] == 2 && Grid_Data [4] == 0)  { Grid_Data [4] = 2; Computer =4;}
                    else if(Grid_Data [4] == 2 && Grid_Data [7] == 2 && Grid_Data [1] == 0)  { Grid_Data [1] = 2; Computer =1;}
                    else if(Grid_Data [2] == 2 && Grid_Data [5] == 2 && Grid_Data [8] == 0)  { Grid_Data [8] = 2; Computer =8;}
                    else if(Grid_Data [2] == 2 && Grid_Data [8] == 2 && Grid_Data [5] == 0)  { Grid_Data [5] = 2; Computer =5;}
                    else if(Grid_Data [5] == 2 && Grid_Data [8] == 2 && Grid_Data [2] == 0)  { Grid_Data [2] = 2; Computer =2;}
                    else if(Grid_Data [3] == 2 && Grid_Data [6] == 2 && Grid_Data [9] == 0)  { Grid_Data [9] = 2; Computer =9;}
                    else if(Grid_Data [3] == 2 && Grid_Data [9] == 2 && Grid_Data [6] == 0)  { Grid_Data [6] = 2; Computer =6;}
                    else if(Grid_Data [6] == 2 && Grid_Data [9] == 2 && Grid_Data [3] == 0)  { Grid_Data [3] = 2; Computer =3;}
                    else if(Grid_Data [1] == 2 && Grid_Data [5] == 2 && Grid_Data [9] == 0)  { Grid_Data [9] = 2; Computer =9;}
                    else if(Grid_Data [1] == 2 && Grid_Data [9] == 2 && Grid_Data [5] == 0)  { Grid_Data [5] = 2; Computer =5;}
                    else if(Grid_Data [5] == 2 && Grid_Data [9] == 2 && Grid_Data [1] == 0)  { Grid_Data [1] = 2; Computer =1;}
                    else if(Grid_Data [3] == 2 && Grid_Data [5] == 2 && Grid_Data [7] == 0)  { Grid_Data [7] = 2; Computer =7;}
                    else if(Grid_Data [3] == 2 && Grid_Data [7] == 2 && Grid_Data [5] == 0)  { Grid_Data [5] = 2; Computer =5;}
                    else if(Grid_Data [5] == 2 && Grid_Data [7] == 2 && Grid_Data [3] == 0)  { Grid_Data [3] = 2; Computer =3;}
                    ///Depends
                    else if(Grid_Data [1] == 1 && Grid_Data [2] == 1 && Grid_Data [3] == 0)  { Grid_Data [3] = 2; Computer =3;}
                    else if(Grid_Data [1] == 1 && Grid_Data [3] == 1 && Grid_Data [2] == 0)  { Grid_Data [2] = 2; Computer =2;}
                    else if(Grid_Data [2] == 1 && Grid_Data [3] == 1 && Grid_Data [1] == 0)  { Grid_Data [1] = 2; Computer =1;}
                    else if(Grid_Data [4] == 1 && Grid_Data [5] == 1 && Grid_Data [6] == 0)  { Grid_Data [6] = 2; Computer =6;}
                    else if(Grid_Data [4] == 1 && Grid_Data [6] == 1 && Grid_Data [5] == 0)  { Grid_Data [5] = 2; Computer =5;}
                    else if(Grid_Data [5] == 1 && Grid_Data [6] == 1 && Grid_Data [4] == 0)  { Grid_Data [4] = 2; Computer =4;}
                    else if(Grid_Data [7] == 1 && Grid_Data [8] == 1 && Grid_Data [9] == 0)  { Grid_Data [9] = 2; Computer =9;}
                    else if(Grid_Data [7] == 1 && Grid_Data [9] == 1 && Grid_Data [8] == 0)  { Grid_Data [8] = 2; Computer =8;}
                    else if(Grid_Data [8] == 1 && Grid_Data [9] == 1 && Grid_Data [7] == 0)  { Grid_Data [7] = 2; Computer =7;}
                    else if(Grid_Data [1] == 1 && Grid_Data [4] == 1 && Grid_Data [7] == 0)  { Grid_Data [7] = 2; Computer =7;}
                    else if(Grid_Data [1] == 1 && Grid_Data [7] == 1 && Grid_Data [4] == 0)  { Grid_Data [4] = 2; Computer =4;}
                    else if(Grid_Data [4] == 1 && Grid_Data [7] == 1 && Grid_Data [1] == 0)  { Grid_Data [1] = 2; Computer =1;}
                    else if(Grid_Data [2] == 1 && Grid_Data [5] == 1 && Grid_Data [8] == 0)  { Grid_Data [8] = 2; Computer =8;}
                    else if(Grid_Data [2] == 1 && Grid_Data [8] == 1 && Grid_Data [5] == 0)  { Grid_Data [5] = 2; Computer =5;}
                    else if(Grid_Data [5] == 1 && Grid_Data [8] == 1 && Grid_Data [2] == 0)  { Grid_Data [2] = 2; Computer =2;}
                    else if(Grid_Data [3] == 1 && Grid_Data [6] == 1 && Grid_Data [9] == 0)  { Grid_Data [9] = 2; Computer =9;}
                    else if(Grid_Data [3] == 1 && Grid_Data [9] == 1 && Grid_Data [6] == 0)  { Grid_Data [6] = 2; Computer =6;}
                    else if(Grid_Data [6] == 1 && Grid_Data [9] == 1 && Grid_Data [3] == 0)  { Grid_Data [3] = 2; Computer =3;}
                    else if(Grid_Data [1] == 1 && Grid_Data [5] == 1 && Grid_Data [9] == 0)  { Grid_Data [9] = 2; Computer =9;}
                    else if(Grid_Data [1] == 1 && Grid_Data [9] == 1 && Grid_Data [5] == 0)  { Grid_Data [5] = 2; Computer =5;}
                    else if(Grid_Data [5] == 1 && Grid_Data [9] == 1 && Grid_Data [1] == 0)  { Grid_Data [1] = 2; Computer =1;}
                    else if(Grid_Data [3] == 1 && Grid_Data [5] == 1 && Grid_Data [7] == 0)  { Grid_Data [7] = 2; Computer =7;}
                    else if(Grid_Data [3] == 1 && Grid_Data [7] == 1 && Grid_Data [5] == 0)  { Grid_Data [5] = 2; Computer =5;}
                    else if(Grid_Data [5] == 1 && Grid_Data [7] == 1 && Grid_Data [3] == 0)  { Grid_Data [3] = 2; Computer =3;}

                    ///Some Extra-intelegence of Computer (below)
                    else if (Time==1)
                    {
                       srand(time(NULL));
                       Computer = (2*(rand()%5))+1;
                    }
                    else if(Time==2 && ( Grid_Data [1]==1 || Grid_Data [3]==1 || Grid_Data [7]==1 || Grid_Data [9]==1  )) {Grid_Data [5]==2; Computer=5;}
                    else if(Time==2 && Grid_Data [5]==1 )
                    {
                        Randam_Func(Call) ;
                        Computer=(rand()%4+1)*2-1;
                        if(Computer==5) Computer=9;
                    }

                    else if (Time==3 && Grid_Data [5]==0)
                    {
                        Computer=5;
                    }

                    else if (Time==3)
                    {

                        while(1)
                        {
                            Computer==Randam_Func(Call) ;
                            if(Computer%2==0) Computer++;
                            else if(Grid_Data [Computer]!=0) Computer++;
                            else break;
                            Computer=Computer%10;
                        }
                    }

                    else if(Time==4 && ( Grid_Data [1]==1 && Grid_Data [9]==1 && Grid_Data [5]==2 || Grid_Data [3]==1 && Grid_Data [7]==1 && Grid_Data [5]==2  ))
                    {
                        srand(time(NULL));
                        Computer  = (1+rand()%4)*2;
                    }

                    else if(Time==9)
                    {
                        for(i=1;i<=9;i++)
                        {
                            if(Grid_Data [i] == 0) Computer=i;
                        }
                    }


                    else /// uporer kono shorto-i na mille Randam number Call korbe
                    {
                        while(1)
                        {
                            Computer = Randam_Func(Call);
                            if(Grid_Data[Computer] == 0 ) break;
                        }
                    }

                }


                Grid_Data[Computer]=2; ///Input of Computer (computer er chal dewa)

                new new TabM3 cout<< "Computer Chose :\t"<<Computer<<endl<<endl; ///Output Computer choise

                goto Print_Loop;    ///Print Update Result
                Come_Back_2:        ///Come Back after printing

                if(Grid_Data[1] == 2 && Grid_Data[2] == 2 && Grid_Data[3] == 2 || Grid_Data[4] == 2 && Grid_Data[5] == 2 && Grid_Data[6] == 2 || Grid_Data[7] == 2 && Grid_Data[8] == 2 && Grid_Data[9] == 2 || Grid_Data[1] == 2 && Grid_Data[4] == 2 && Grid_Data[7] == 2 || Grid_Data[2] == 2 && Grid_Data[5] == 2 && Grid_Data[8] == 2 || Grid_Data[3] == 2 && Grid_Data[6] == 2 && Grid_Data[9] == 2 ||  Grid_Data[3] == 2 && Grid_Data[5] == 2 && Grid_Data[7] == 2 || Grid_Data[1] == 2 && Grid_Data[5] == 2 && Grid_Data[9] == 2 )
                {
                    Win_Com++;
                    break;           ///Computer jitleo game finished
                }


                if(Time == 9) break; ///sob ghor puron holeo game finished


        }

        new TabM2

        Sound
        if         (Win_I   >   0)        cout<<"Congratulation! You are Winner.\n";
        else if    (Win_Com >   0)        cout<<"\t Sorry! You are Loser.\n";
        else                              cout<<"\t\tMatch Drawn\n";

        new new new getch();
        TabM2 cout<<"\tTo Play Again Press-'1';\n";
        TabM2 cout<<"\tTo Close Press-'Any other Number';\n";
        int again;
        cin>>again;
        if(again==1) continue;      ///punoray game start hobe
        else break;                 ///program close hobe
    }
    return 0;
}
