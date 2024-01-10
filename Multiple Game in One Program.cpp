#include <bits/stdc++.h>
//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
//#include <math.h>
#include <conio.h>                        //for getch();

#define TabM  cout << "\t\t\t\t\t\t";    //Likhagulo Middle Show korar jonno
#define TabM2 cout << "\t\t\t\t     ";
#define TabM3 cout << "\t\t\t\t\t  ";
#define TabM4 cout << "\t\t\t\t";

#define New   cout << "\n";             //New Line
#define Sound cout << "\a";             // Sound

#define BrdrM for(int i=0;i<21;i++) cout<<cc;       //playground border design
#define Brdr cout<<cc;

#define show        cout << "\tScore : " << Score << endl << endl;
#define showScore   cout << "\tScore : " << Score << endl;
#define showLife    cout << "\t Life : " << Life << endl << endl;

using namespace std;

string Dicission (string a)
{
    New New New getch();
    TabM3 cout << "\tTo Play Again Press-'1'\n";
    TabM3 cout << "\tTo Goto Menu  Press-'0'\n";
    TabM  cin >> a;
    New New New
    system("cls");
    return a;
}

string Dicission_Mini (string a)
{
    New getch();
    TabM2 cout << "\tTo Play Again,               Press-'1'\n";
    TabM2 cout << "\tTo Play Another  Mini GAME , Press-'2'\n";
    TabM2 cout << "\tTo Goto MENU,                Press-'0'\n";
    TabM  cin >> a;
    New New New
    system("cls");
    return a;
}

int Randam_Func_09 (int a)                  //Decited Computer's Chose Index in Tic Tac Toe Game
{
    srand(time(NULL));
    a= rand() % 9;
    a++;
    return a;
}

int Randam_Function_100 (int Return_Fruit) //Decited Fruit possition in Snake Game
{
    srand(time(NULL));
    Return_Fruit= rand() % 100;
    Return_Fruit++;
    return Return_Fruit;
}




int main()
{
            string Again,Kall;
            char cc=219; //Border Sign

        Menu:
            system("cls");
            TabM cout << "   MULTIPLE GAME   ";         New New
            TabM2 printf("Press 1,   to Play         TIC TAC TOE(Man vs Com)\n");
            TabM2 printf("Press 2,   to Play         TIC TAC TOE(Man vs Man)\n\n");
            TabM2 printf("Press 3,   to Play            SNAKE GAME (Classic)\n");
            TabM2 printf("Press 4,   to Play            SNAKE GAME (  Box  )\n\n");
            TabM2 printf("Press 5,   to Play        SNAKE-LUDO (vs Computer)\n");
            TabM2 printf("Press 6,   to Play        SNAKE-LUDO (MultiPlayer)\n\n");
            TabM2 printf("Press 7,   to Play                         SUDOKU\n");
            TabM2 printf("Press 8,   to Play                     Mini GAMES\n\n");
            TabM2 printf("Press 0,   to CLOSE                   THE PROGRAM\n\n");                //Introduction end

            New New //New Line

            TabM2 printf("SWITCH CASE NUMBER (0 to 8): \t");

    int mark;
    cin  >>  mark;
    New New New
    system("cls");

    switch (mark){

    case 1:     //Tic Tac Toe (Man vs Computer - 3 Different Mode)

        while(1)
        {
            int i, Me= 0, Computer= 0, Time= 0, Win_I= 0, Win_Com= 0, Call, Level;
            char who, Index_Data[11]; //'who' uses for who play first & Index_Data[10] contains Data which Index fill up or Not
            char Index_Symbol[11];    //Box-Symbol string (show 'x', 'o', ' ')

            cout << "\t\t\t\t\t       TIC TAC TOE   \n\n";
            cout << "\t\t\t\t\t    [Man vs Computer]\n\n";


            New TabM  cout << "Choice Level";
            New TabM3 cout << "Easy / Medium / Hard";
            New TabM2 cout << "   Press - '1' / '2' / '3' : ";
            cin >> Level;
            New New
            system("cls");

            cout << "\t\t\t\t\t       TIC TAC TOE   \n\n";
            cout << "\t\t\t\t\t    [Man vs Computer]\n\n";

            if      (Level<= 0) break; //if you want to close the game
            else if (Level== 1) {TabM cout << "EASY LEVEL\n"; }
            else if (Level== 2) {TabM cout << "MEDIUM LEVEL\n"; }
            else                {TabM cout << "HARD LEVEL\n"; }
            New

            TabM3 cout << "    Who Play First?\n";
            TabM3 cout << "  ('You'/'Computer')\n\n";
            TabM4 cout << "  Press 'I' for 'You' or 'C' for 'Computer'\n";
            TabM4 cout << "       Press 'Other Any Key' for Tossing\n";
            TabM3 cout << "   (Without Quatation) :\n\n";
            TabM  cout << "    ";

            cin >> who;
            who= tolower(who);

            if(who != 'i' && who != 'c')            //Tossing
            {
                srand(time(NULL));
                if(rand() %2== who %2 ) {New TabM3 cout << "  You won the Toss\n" ; who= 'i'; }
                else {New TabM3 cout << "Computer won the Toss\n" ; who= 'c'; }
            }

            New TabM2 cout<<"Press Any Key to Start the Match\n";
            getch();
            system("cls");


            for(i= 0; i<= 9; i++)
            {
                Index_Data[i]= 0;
            }

            Print_Loop_ttt_vsc:             //Print_Update

                cout << "\t\t\t\t\t       TIC TAC TOE   \n\n";
                cout << "\t\t\t\t\t    [Man vs Computer]\n\n";
                cout << "\t\t  [Everytime Press Any Key from '1' to '9' For Push Your Symbol in the Box] " << endl << endl;


                Index_Data[Me]= 1;
                Index_Data[Computer]= 2;

                for(i= 0; i<= 9; i++)
                {
                    if(Index_Data[i]== 0) Index_Symbol[i]= ' ';     //Unfilled
                    if(Index_Data[i]== 1) Index_Symbol[i]= 'x';     //Filled by You
                    if(Index_Data[i]== 2) Index_Symbol[i]= 'o';     //Filled by Computer

                }


                New
                TabM   New
                TabM  cout << " 1 | 2 | 3 ";  New
                TabM  cout << "___|___|___";  New
                TabM  cout << " 4 | 5 | 6 ";  New
                TabM  cout << "___|___|___";  New
                TabM  cout << " 7 | 8 | 9 ";  New
                TabM  cout << "   |   |   ";  New
                TabM   New New

                Sound
                TabM  New                       //Index Border Degign
                TabM

                for(i=1;i<=9;i++)
                {
                   cout<<" "<<Index_Symbol[i];
                   if (i==9) {New TabM cout<<"   |   |   \n"; New New}
                   else if(i%3 == 0 ) { New TabM  cout <<"___|___|___\n"; TabM  }
                   else   cout<<" |";
                }

                New New

                if(Time== 0 && who== 'c') goto Com;             //Computer er First chal hole
                if(Time== 0) ;
                else if(Time%2== 1 && who== 'c' || Time%2== 0 && who != 'c') goto Come_Back_2;     //Jor o bijor tomo chaler hiseb (Computer age chal dile bijor tomo chal gulo Computer er ar ami age chal dile jor tomo chal gulo Computer er)
                else goto Come_Back_1;                                                              // " " "



            while(1)
            {
                You:
                    Time++;                //kotota ghor fill up holo- seta count kora hocche

                    ReCall_Me:

                        New New TabM3 cout << "Your Choice   :\t";
                        cin >> Me;
    //                    Me= Me % 10;
                        if(Me<0 || Me>= 10)
                        {New TabM cout << "Wrong Input"; goto ReCall_Me ; }              // jodi wrong chal dewa hoy, then- game close hobe


                        if(Index_Data[Me]  !=  0)                       //jodi ghor-tite already chal dewa hoye thake
                        {cout << "Already Exist\n\n"; goto ReCall_Me; }   //tobe accept hobe na, punoray chal dewa lagbe

                    Index_Data[Me]= 1;//Index-tate Amar chal input holo

                    system("cls");
                    goto Print_Loop_ttt_vsc;        //for printing update result

                    Come_Back_1:         //print kore punoray fire ase

                        if(Index_Data[1]== 1 && Index_Data[2]== 1 && Index_Data[3]== 1 || Index_Data[4]== 1 && Index_Data[5]== 1 && Index_Data[6]== 1 || Index_Data[7]== 1 && Index_Data[8]== 1 && Index_Data[9]== 1 || Index_Data[1]== 1 && Index_Data[4]== 1 && Index_Data[7]== 1 || Index_Data[2]== 1 && Index_Data[5]== 1 && Index_Data[8]== 1 || Index_Data[3]== 1 && Index_Data[6]== 1 && Index_Data[9]== 1 ||  Index_Data[3]== 1 && Index_Data[5]== 1 && Index_Data[7]== 1 || Index_Data[1]== 1 && Index_Data[5]== 1 && Index_Data[9]== 1 )
                        {
                            Win_I++;
                            break;              //Ami jitle game finished hobe
                        }
                    if(Time== 9) break;        //sob (9ta) ghor puron holegame finished

                Com:

                    Time++;                     //kotobar chal dewa holo/ kotota Index puron holo, seta count kora hocche

                    if(Level== 1)                //Easy mode : Computer sob chal randamly dibe
                    {
                        while(1)
                            {
                                Computer= Randam_Func_09(Call);
                                if(Index_Data[Computer]== 0 ) break;
                            }
                    }

                    else if(Level== 2)       //Medium Level : kichuta buddhimotta apply korbe computer, bad computer a bishesh koushole fade fele harano somvob
                    {
                        //Attack of Computer (Computer er nije jitar Formula gulo)
                        if     (Index_Data [1]== 2 && Index_Data [2]== 2 && Index_Data [3]== 0)  {  Computer = 3; }
                        else if(Index_Data [1]== 2 && Index_Data [3]== 2 && Index_Data [2]== 0)  {  Computer = 2; }
                        else if(Index_Data [2]== 2 && Index_Data [3]== 2 && Index_Data [1]== 0)  {  Computer = 1; }
                        else if(Index_Data [4]== 2 && Index_Data [5]== 2 && Index_Data [6]== 0)  {  Computer = 6; }
                        else if(Index_Data [4]== 2 && Index_Data [6]== 2 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 2 && Index_Data [6]== 2 && Index_Data [4]== 0)  {  Computer = 4; }
                        else if(Index_Data [7]== 2 && Index_Data [8]== 2 && Index_Data [9]== 0)  {  Computer = 9; }
                        else if(Index_Data [7]== 2 && Index_Data [9]== 2 && Index_Data [8]== 0)  {  Computer = 8; }
                        else if(Index_Data [8]== 2 && Index_Data [9]== 2 && Index_Data [7]== 0)  {  Computer = 7; }
                        else if(Index_Data [1]== 2 && Index_Data [4]== 2 && Index_Data [7]== 0)  {  Computer = 7; }
                        else if(Index_Data [1]== 2 && Index_Data [7]== 2 && Index_Data [4]== 0)  {  Computer = 4; }
                        else if(Index_Data [4]== 2 && Index_Data [7]== 2 && Index_Data [1]== 0)  {  Computer = 1; }
                        else if(Index_Data [2]== 2 && Index_Data [5]== 2 && Index_Data [8]== 0)  {  Computer = 8; }
                        else if(Index_Data [2]== 2 && Index_Data [8]== 2 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 2 && Index_Data [8]== 2 && Index_Data [2]== 0)  {  Computer = 2; }
                        else if(Index_Data [3]== 2 && Index_Data [6]== 2 && Index_Data [9]== 0)  {  Computer = 9; }
                        else if(Index_Data [3]== 2 && Index_Data [9]== 2 && Index_Data [6]== 0)  {  Computer = 6; }
                        else if(Index_Data [6]== 2 && Index_Data [9]== 2 && Index_Data [3]== 0)  {  Computer = 3; }
                        else if(Index_Data [1]== 2 && Index_Data [5]== 2 && Index_Data [9]== 0)  {  Computer = 9; }
                        else if(Index_Data [1]== 2 && Index_Data [9]== 2 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 2 && Index_Data [9]== 2 && Index_Data [1]== 0)  {  Computer = 1; }
                        else if(Index_Data [3]== 2 && Index_Data [5]== 2 && Index_Data [7]== 0)  {  Computer = 7; }
                        else if(Index_Data [3]== 2 && Index_Data [7]== 2 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 2 && Index_Data [7]== 2 && Index_Data [3]== 0)  {  Computer = 3; }

                        //Depends of Computer(computer er amar jita atkanor formula gulo)
                        else if(Index_Data [1]== 1 && Index_Data [2]== 1 && Index_Data [3]== 0)  {  Computer = 3; }
                        else if(Index_Data [1]== 1 && Index_Data [3]== 1 && Index_Data [2]== 0)  {  Computer = 2; }
                        else if(Index_Data [2]== 1 && Index_Data [3]== 1 && Index_Data [1]== 0)  {  Computer = 1; }
                        else if(Index_Data [4]== 1 && Index_Data [5]== 1 && Index_Data [6]== 0)  {  Computer = 6; }
                        else if(Index_Data [4]== 1 && Index_Data [6]== 1 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 1 && Index_Data [6]== 1 && Index_Data [4]== 0)  {  Computer = 4; }
                        else if(Index_Data [7]== 1 && Index_Data [8]== 1 && Index_Data [9]== 0)  {  Computer = 9; }
                        else if(Index_Data [7]== 1 && Index_Data [9]== 1 && Index_Data [8]== 0)  {  Computer = 8; }
                        else if(Index_Data [8]== 1 && Index_Data [9]== 1 && Index_Data [7]== 0)  {  Computer = 7; }
                        else if(Index_Data [1]== 1 && Index_Data [4]== 1 && Index_Data [7]== 0)  {  Computer = 7; }
                        else if(Index_Data [1]== 1 && Index_Data [7]== 1 && Index_Data [4]== 0)  {  Computer = 4; }
                        else if(Index_Data [4]== 1 && Index_Data [7]== 1 && Index_Data [1]== 0)  {  Computer = 1; }
                        else if(Index_Data [2]== 1 && Index_Data [5]== 1 && Index_Data [8]== 0)  {  Computer = 8; }
                        else if(Index_Data [2]== 1 && Index_Data [8]== 1 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 1 && Index_Data [8]== 1 && Index_Data [2]== 0)  {  Computer = 2; }
                        else if(Index_Data [3]== 1 && Index_Data [6]== 1 && Index_Data [9]== 0)  {  Computer = 9; }
                        else if(Index_Data [3]== 1 && Index_Data [9]== 1 && Index_Data [6]== 0)  {  Computer = 6; }
                        else if(Index_Data [6]== 1 && Index_Data [9]== 1 && Index_Data [3]== 0)  {  Computer = 3; }
                        else if(Index_Data [1]== 1 && Index_Data [5]== 1 && Index_Data [9]== 0)  {  Computer = 9; }
                        else if(Index_Data [1]== 1 && Index_Data [9]== 1 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 1 && Index_Data [9]== 1 && Index_Data [1]== 0)  {  Computer = 1; }
                        else if(Index_Data [3]== 1 && Index_Data [5]== 1 && Index_Data [7]== 0)  {  Computer = 7; }
                        else if(Index_Data [3]== 1 && Index_Data [7]== 1 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 1 && Index_Data [7]== 1 && Index_Data [3]== 0)  {  Computer = 3; }

                        else if(Time== 9)                //seshe je ghor faka thakbe setate chalbe (time complexity komanor jonno just, not so necessary)
                            {   for(i= 1; i<= 9; i++)   {if(Index_Data[i]== 0) Computer= i; }  }

                        else                            // kono shortoi na mille randamly chal dibe computer
                        {
                            while(1)
                            {
                                Computer= Randam_Func_09(Call);
                                if(Index_Data[Computer]== 0 ) break;
                            }
                        }

                    }

                    else            //Hard Level (Harano osomvob - hoy com. jitbe nahoy draw) - Medium er sathe aro kichu shorto add kora hoyeche jate com. ke fade feleo harano na jay)
                    {
                        //Attack of Computer (Computer er nije jitar Formula gulo)
                        if     (Index_Data [1]== 2 && Index_Data [2]== 2 && Index_Data [3]== 0)  {  Computer = 3; }
                        else if(Index_Data [1]== 2 && Index_Data [3]== 2 && Index_Data [2]== 0)  {  Computer = 2; }
                        else if(Index_Data [2]== 2 && Index_Data [3]== 2 && Index_Data [1]== 0)  {  Computer = 1; }
                        else if(Index_Data [4]== 2 && Index_Data [5]== 2 && Index_Data [6]== 0)  {  Computer = 6; }
                        else if(Index_Data [4]== 2 && Index_Data [6]== 2 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 2 && Index_Data [6]== 2 && Index_Data [4]== 0)  {  Computer = 4; }
                        else if(Index_Data [7]== 2 && Index_Data [8]== 2 && Index_Data [9]== 0)  {  Computer = 9; }
                        else if(Index_Data [7]== 2 && Index_Data [9]== 2 && Index_Data [8]== 0)  {  Computer = 8; }
                        else if(Index_Data [8]== 2 && Index_Data [9]== 2 && Index_Data [7]== 0)  {  Computer = 7; }
                        else if(Index_Data [1]== 2 && Index_Data [4]== 2 && Index_Data [7]== 0)  {  Computer = 7; }
                        else if(Index_Data [1]== 2 && Index_Data [7]== 2 && Index_Data [4]== 0)  {  Computer = 4; }
                        else if(Index_Data [4]== 2 && Index_Data [7]== 2 && Index_Data [1]== 0)  {  Computer = 1; }
                        else if(Index_Data [2]== 2 && Index_Data [5]== 2 && Index_Data [8]== 0)  {  Computer = 8; }
                        else if(Index_Data [2]== 2 && Index_Data [8]== 2 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 2 && Index_Data [8]== 2 && Index_Data [2]== 0)  {  Computer = 2; }
                        else if(Index_Data [3]== 2 && Index_Data [6]== 2 && Index_Data [9]== 0)  {  Computer = 9; }
                        else if(Index_Data [3]== 2 && Index_Data [9]== 2 && Index_Data [6]== 0)  {  Computer = 6; }
                        else if(Index_Data [6]== 2 && Index_Data [9]== 2 && Index_Data [3]== 0)  {  Computer = 3; }
                        else if(Index_Data [1]== 2 && Index_Data [5]== 2 && Index_Data [9]== 0)  {  Computer = 9; }
                        else if(Index_Data [1]== 2 && Index_Data [9]== 2 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 2 && Index_Data [9]== 2 && Index_Data [1]== 0)  {  Computer = 1; }
                        else if(Index_Data [3]== 2 && Index_Data [5]== 2 && Index_Data [7]== 0)  {  Computer = 7; }
                        else if(Index_Data [3]== 2 && Index_Data [7]== 2 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 2 && Index_Data [7]== 2 && Index_Data [3]== 0)  {  Computer = 3; }

                        //Depends of Computer(computer er amar jita atkanor formula gulo)
                        else if(Index_Data [1]== 1 && Index_Data [2]== 1 && Index_Data [3]== 0)  {  Computer = 3; }
                        else if(Index_Data [1]== 1 && Index_Data [3]== 1 && Index_Data [2]== 0)  {  Computer = 2; }
                        else if(Index_Data [2]== 1 && Index_Data [3]== 1 && Index_Data [1]== 0)  {  Computer = 1; }
                        else if(Index_Data [4]== 1 && Index_Data [5]== 1 && Index_Data [6]== 0)  {  Computer = 6; }
                        else if(Index_Data [4]== 1 && Index_Data [6]== 1 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 1 && Index_Data [6]== 1 && Index_Data [4]== 0)  {  Computer = 4; }
                        else if(Index_Data [7]== 1 && Index_Data [8]== 1 && Index_Data [9]== 0)  {  Computer = 9; }
                        else if(Index_Data [7]== 1 && Index_Data [9]== 1 && Index_Data [8]== 0)  {  Computer = 8; }
                        else if(Index_Data [8]== 1 && Index_Data [9]== 1 && Index_Data [7]== 0)  {  Computer = 7; }
                        else if(Index_Data [1]== 1 && Index_Data [4]== 1 && Index_Data [7]== 0)  {  Computer = 7; }
                        else if(Index_Data [1]== 1 && Index_Data [7]== 1 && Index_Data [4]== 0)  {  Computer = 4; }
                        else if(Index_Data [4]== 1 && Index_Data [7]== 1 && Index_Data [1]== 0)  {  Computer = 1; }
                        else if(Index_Data [2]== 1 && Index_Data [5]== 1 && Index_Data [8]== 0)  {  Computer = 8; }
                        else if(Index_Data [2]== 1 && Index_Data [8]== 1 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 1 && Index_Data [8]== 1 && Index_Data [2]== 0)  {  Computer = 2; }
                        else if(Index_Data [3]== 1 && Index_Data [6]== 1 && Index_Data [9]== 0)  {  Computer = 9; }
                        else if(Index_Data [3]== 1 && Index_Data [9]== 1 && Index_Data [6]== 0)  {  Computer = 6; }
                        else if(Index_Data [6]== 1 && Index_Data [9]== 1 && Index_Data [3]== 0)  {  Computer = 3; }
                        else if(Index_Data [1]== 1 && Index_Data [5]== 1 && Index_Data [9]== 0)  {  Computer = 9; }
                        else if(Index_Data [1]== 1 && Index_Data [9]== 1 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 1 && Index_Data [9]== 1 && Index_Data [1]== 0)  {  Computer = 1; }
                        else if(Index_Data [3]== 1 && Index_Data [5]== 1 && Index_Data [7]== 0)  {  Computer = 7; }
                        else if(Index_Data [3]== 1 && Index_Data [7]== 1 && Index_Data [5]== 0)  {  Computer = 5; }
                        else if(Index_Data [5]== 1 && Index_Data [7]== 1 && Index_Data [3]== 0)  {  Computer = 3; }

                        //Some Extra-intelegence of Computer (below) <-- jate kono vabe fade felano na jay
                        else if (Time== 1)
                        {
                           srand(time(NULL));
                           Computer= (2*(rand()%5))+1;
                        }
                        else if(Time== 2 && ( Index_Data [1]== 1 || Index_Data [3]== 1 || Index_Data [7]== 1 || Index_Data [9]== 1  )) { Computer= 5; }

                        else if(Time== 2 && Index_Data [5]== 1 )
                        {
                            Randam_Func_09(Call) ;
                            Computer= (rand()%4+1)*2-1;
                            if(Computer== 5) Computer= 9;
                        }

                        else if (Time== 3 && Index_Data [5]== 0)
                        {
                            Computer= 5;
                        }

                        else if (Time== 3)
                        {

                            while(1)
                            {
                                Computer== Randam_Func_09(Call) ;
                                if(Computer%2== 0) Computer++;
                                else if(Index_Data [Computer] != 0) Computer++;
                                else break;
                                Computer= Computer%10;
                            }
                        }

                        else if(Time== 4 && ( Index_Data [1]== 1 && Index_Data [9]== 1 && Index_Data [5]== 2 || Index_Data [3]== 1 && Index_Data [7]== 1 && Index_Data [5]== 2  ))
                        {
                            srand(time(NULL));
                            Computer = (1+rand()%4)*2;
                        }

                        else if(Time== 9)
                        {
                            for(i= 1; i<= 9; i++)
                            {
                                if(Index_Data [i]== 0) Computer= i;
                            }
                        }


                        else                // uporer kono shorto-i na mille Randam number Call korbe
                        {
                            while(1)
                            {
                                Computer= Randam_Func_09(Call);
                                if(Index_Data[Computer]== 0 ) break;
                            }
                        }

                    }


                    Index_Data[Computer]= 2; //Input of Computer (computer er chal dewa)

                    New New TabM3 cout <<  "Computer Chose :\t" << Computer << endl << endl;  //Output Computer Choice

                    system("cls");
                    goto Print_Loop_ttt_vsc;    //Print Update Result
                    Come_Back_2:                 //Come Back after printing

                    if(Index_Data[1]== 2 && Index_Data[2]== 2 && Index_Data[3]== 2 || Index_Data[4]== 2 && Index_Data[5]== 2 && Index_Data[6]== 2 || Index_Data[7]== 2 && Index_Data[8]== 2 && Index_Data[9]== 2 || Index_Data[1]== 2 && Index_Data[4]== 2 && Index_Data[7]== 2 || Index_Data[2]== 2 && Index_Data[5]== 2 && Index_Data[8]== 2 || Index_Data[3]== 2 && Index_Data[6]== 2 && Index_Data[9]== 2 ||  Index_Data[3]== 2 && Index_Data[5]== 2 && Index_Data[7]== 2 || Index_Data[1]== 2 && Index_Data[5]== 2 && Index_Data[9]== 2 )
                    {
                        Win_Com++;
                        break;           //Computer jitle-o game finished
                    }


                    if(Time== 9) break; //sob ghor puron hole-o game finished


            }

            New TabM2

            Sound
            if         (Win_I   >   0)        cout << "Congratulation! You are Winner.\n";
            else if    (Win_Com >   0)        cout << "\t Sorry! You are Loser.\n";
            else                              cout << "\t\tMatch Drawn\n";

            Again = Dicission (Kall);
            if(Again!= "1") goto Menu;              //program close hobe
        }
        break;





    case 2:     //Tic Tac Toe (Man vs Man)

        // Tic Tac Toe (Man vs Man) Game ti onekta Tic Tac Toe (Man vs Computer) er motoi
        // Sudhu Parthokko holo Ekhane 2 jon Player khelbe (Computer khelbe na)

        while(1)
        {
            int  i, Player_1= 0, Player_2= 0, Time= 0, Win_1= 0, Win_2= 0;
            char Index_Data [10];
            char Index_Symbol [10];

            cout << "\t\t\t\t\t       TIC TAC TOE\n";
            cout << "\t\t\t\t\t       [Man vs Man]\n\n";


            //ke age chalbe Player '1' na '2' naki Toss
            TabM3 cout<<"  Who Play First?\n";
            TabM3 cout<<" ('Player-1'/'Player-2')\n\n";
            TabM4 cout<<"Press- '1' for 'Player-1' or Press- '2' for 'Player-2'\n";
            TabM4 cout<<"  or Press Other 'Any Key' for Tossing\n";
            TabM3 cout<<" (Without Quatation) :\n\n";
            TabM  cout<<"   ";

            char Who;
            cin >> Who;
            int who= Who-'0';

            if(who<= 0) goto Menu;
            if(who>2)
            {
                srand(time(NULL));
                if(rand() %2== who %2 ) {New TabM3 cout << "Player-1 won the Toss\n" ; who= 1; }
                else                    {New TabM3 cout << "Player-2 won the Toss\n" ; who= 2; }
            }

            New TabM2 cout<<"Press Any Key to Start the Match\n";
            getch();
            system("cls");

            for(i= 0; i<= 9; i++)
            {
                Index_Data[i]= 0;
            }

            Print_Loop_ttt_vs_man:   //Print_Loop

                system("cls");

                Index_Data[Player_1]= 1;
                Index_Data[Player_2]= 2;

                for(i= 0; i<= 9; i++)
                {
                    if(Index_Data[i]== 0) Index_Symbol[i]= ' ';
                    if(Index_Data[i]== 1) Index_Symbol[i]= 'x';
                    if(Index_Data[i]== 2) Index_Symbol[i]= 'o';

                }

                cout << "\t\t\t\t\t       TIC TAC TOE   \n\n";
                cout << "\t\t\t\t\t    [Man vs Computer]\n\n";
                cout << "\t\t  [Everytime Press Any Key from '1' to '9' For Push Your Symbol in the Box] " << endl << endl;

                New
                TabM   New
                TabM  cout << " 1 | 2 | 3 ";  New
                TabM  cout << "___|___|___";  New
                TabM  cout << " 4 | 5 | 6 ";  New
                TabM  cout << "___|___|___";  New
                TabM  cout << " 7 | 8 | 9 ";  New
                TabM  cout << "   |   |   ";  New
                TabM   New New

                Sound
                TabM  New                       //Index Border Degign
                TabM

                for(i=1;i<=9;i++)
                {
                   cout<<" "<<Index_Symbol[i];
                   if (i==9) {New TabM cout<<"   |   |   \n"; New New}
                   else if(i%3 == 0 ) { New TabM  cout <<"___|___|___\n"; TabM  }
                   else   cout<<" |";
                }

                New New





                if(Time== 0 && who== 2) goto Player2;
                if(Time== 0) ;
                else if(Time%2== 1 && who== 2 || Time%2== 0 && who != 2) goto Back_2;
                else goto Back_1;

                while(1)
                {
                    Player1:

                        Time++;

                        Recall_Player1:

                            cout << "Player-1 :   ";
                            cin >> Player_1;

                            if(Player_1>9 || Player_1<1 )
                            {
                                New cout << "Error Input\n\n";
                                goto Menu;
                            }

                            if(Index_Data[Player_1] != 0)
                            {
                                New cout << "Already Exist\n\n";
                                goto Recall_Player1;
                            }



                        Index_Data[Player_1]= 1;


                        goto Print_Loop_ttt_vs_man;

                        Back_1:

                            if(Index_Data[1]== 1 && Index_Data[2]== 1 && Index_Data[3]== 1 || Index_Data[4]== 1 && Index_Data[5]== 1 && Index_Data[6]== 1 || Index_Data[7]== 1 && Index_Data[8]== 1 && Index_Data[9]== 1 || Index_Data[1]== 1 && Index_Data[4]== 1 && Index_Data[7]== 1 || Index_Data[2]== 1 && Index_Data[5]== 1 && Index_Data[8]== 1 || Index_Data[3]== 1 && Index_Data[6]== 1 && Index_Data[9]== 1 ||  Index_Data[3]== 1 && Index_Data[5]== 1 && Index_Data[7]== 1 || Index_Data[1]== 1 && Index_Data[5]== 1 && Index_Data[9]== 1 )
                            {
                                Win_1++;
                                break;
                            }
                        if(Time== 9) break;

                    Player2:
                        Time++;

                        Recall_Player2://
                            cout << "Player-2 :   ";
                            cin >> Player_2;

                            if(Player_2>9 || Player_2<1 )
                            {
                                New cout << "Error Input\n\n";
                                goto Menu;
                            }

                            if(Index_Data[Player_2] != 0)
                            {
                                    New cout << "Already Exist\n\n";
                                    goto Recall_Player2;
                            }

                        Index_Data[Player_1]= 2;

                        goto Print_Loop_ttt_vs_man;

                        Back_2:

                        if(Index_Data[1]== 2 && Index_Data[2]== 2 && Index_Data[3]== 2 || Index_Data[4]== 2 && Index_Data[5]== 2 && Index_Data[6]== 2 || Index_Data[7]== 2 && Index_Data[8]== 2 && Index_Data[9]== 2 || Index_Data[1]== 2 && Index_Data[4]== 2 && Index_Data[7]== 2 || Index_Data[2]== 2 && Index_Data[5]== 2 && Index_Data[8]== 2 || Index_Data[3]== 2 && Index_Data[6]== 2 && Index_Data[9]== 2 ||  Index_Data[3]== 2 && Index_Data[5]== 2 && Index_Data[7]== 2 || Index_Data[1]== 2 && Index_Data[5]== 2 && Index_Data[9]== 2 )
                        {
                            Win_2++;
                            break;
                        }

                        if(Time== 9) break;

                }

            Sound
            New TabM2

            Sound
            if(Win_1>0)         cout << "Congratulation! Player-1 is Winner.\n";
            else if(Win_2>0)    cout << "Congratulation! Player-2 is Winner.\n";
            else                cout << "\t\tMatch Drawn\n";

            Again = Dicission (Kall);
            if(Again!= "1") goto Menu;

        }

        break;






    case 3:     //SNAKE-CLASSIC

/*
        Here our target is eat more fruit to Increase Score. The Snake's Size
        is increasing according to eat fruit.
        If Snake Bites its Body then the Game is Over. If Score=100, then the Game will be
        Complete.
        Everytime We use 8/2/4/6/7/9/1/3 for moving to up/down/left/right/cross-move
*/
        while(1)
        {
            int Fruit,Score = 0,temp,Finish=0,Call,Change,i,x = 0,Level;
            int Snake_Head = 46;    //snake head initial possition
            int Snake_Body[108] = {0}; //0,1-100,Primary body Size(5)+Extra some for avoid silly risk
            char key,Move='6';
            char PlayGround[109]; //0,1-100,NULL+Primary body Size(5)+Extra some for avoid silly risk

            cout << "\t\t\t\t\t\tSNAKE GAME [Classic](10x10)\n\n";
            cout<<"#Introduction : Here your target is eat more Fruit to Increase Score. The Snake's Size is increasing according to eat Fruit. If the Snake Bites its Body then the Game is Over.If Score=100, then the Game will be Completed. You should Choice Level according to Snake's Speed.\n\n";

            cout<< "LEVEL (1-10) :  ";
            cin>>Level;
            int delay = 500-50*Level;
            New New New;
            temp++;

            Fruit  =  Randam_Function_100(Call);

            //First Declaration of Snake Body (below)
            Snake_Body[1]  =  Snake_Head -1;
            Snake_Body[2]  =  Snake_Head -2;
            Snake_Body[3]  =  Snake_Head -3;

            while(1)
            {
                system("cls");

                cycle:                  //jate fruit snake er body borabor na ase
                    Change++;
                    for(i = 3+Score; i>0; i--)
                    {
                        if(Fruit == Snake_Body[i]) {x = -1;  break; }
                    }
                    if((x == -1 || Fruit == Snake_Head) && Change <= 100 ) //Chnge variable ta Newar karon holo jodi snake body r size full arear soman hoy orthat fruit dewar moto kono jayga na thake tahole snake body borabor porbe , eta na dile oi muhurte program continiously choltei thakto, susthu vabe game complete hoto na
                    {
                        x = 0;
                        Fruit++;
                        Fruit = 1+Fruit%100; //jate 100 overtek na kore
                        goto cycle;
                    }

                for(i = 0; i <= 100; i++)
                {
                    PlayGround [i] = ' ' ;
                }

                PlayGround [Fruit] = temp%2+42; //Fruit Symbol (*,+)
                PlayGround [Snake_Head] = '@';    //Snake Head Symbol (Ascii 2)

                for(i = Score+3; i>0; i--)
                {
                    PlayGround [Snake_Body[i]]  =  254; //Snake Body Symbol
                }
                PlayGround [Snake_Body[Score+3]] = '-'; //Snake Tail Symbol

                cout << "\t\t\t\t\t\tSNAKE GAME [Classic](10x10)\n\n";
                cout << "\t\t\t\t\t\t      Level : "<<Level<<endl;

                New;New;New;New;New;New;
                TabM;  Brdr;  BrdrM;  New;  //Border
                TabM;  Brdr;

                for(i = 1; i <= 100; i++)
                {
                   std:cout<<PlayGround [i]<<" ";           // show Update resulte of Game-PlayGround
                   if(i%10 == 0) {Brdr;  New;  TabM;  Brdr;  }
                }

                BrdrM New New

                TabM show       //Show Score

                //std::cout << "\r";
                //std::cout.flush();

                std::this_thread::sleep_for(std::chrono::milliseconds(delay));




                if(Finish == -1) break; //snake nijeke bite korle game over

                temp++; Change = 0;

                if (kbhit())
                {
                        key = getch();

                    // Check for arrow key input
                        if(key==72) // Up arrow

                            Move='8';

                        else if(key==80)// Down arrow

                            Move='2';

                        else if(key==75) // Left arrow

                            Move='4';

                        else if(key==77) // Right arrow
                            Move='6';

                        else continue;
                }

                if(Move == '5' || Move == '0') continue; //no change

                for(i = 3+Score; i>0; i--)
                {
                    Snake_Body[i] =  Snake_Body[i-1];  //Snake er body possition update
                }
                Snake_Body[1] =  Snake_Head;

                //to move to up / down / left / right / cross (below) - (According to Key-board Numarical Pads)
                if(Move == '6') {Snake_Head++;     /** to move Right */  if(Snake_Head%10 == 1) Snake_Head -= 10; /**Dan dike ber hoye gele oi borabor Bam dik diye asbe */ }
                if(Move == '4') {Snake_Head--;     /** to move Down  */  if(Snake_Head%10 == 0) Snake_Head += 10; /**Bam dike ber hoye gele oi borabor Dan dik diye asbe */}
                if(Move == '2') {Snake_Head += 10; /** to move Down  */   }
                if(Move == '8') {Snake_Head -= 10; /** to move Up    */   }

                if(Snake_Head > 100) Snake_Head -= 100; //box er ekdik diye snake ber hoye gele, oi borabor biporit dik theke snake fire asbe.
                if(Snake_Head <=  0) Snake_Head += 100; // " " "

                for(i = 3+Score; i>0; i--)
                {
                    if(Snake_Head == Snake_Body[i]) { Finish = -1; continue; } //jodi Snake nijeke Bite kore, then game over
                }

                if(Snake_Head == Fruit)         //Snake Fruit eat korar sathe sathe -
                {
                    Score++;                    //-Score barbe
                    if(Score == 97) Score += 3; //Highest point 100 korar jonno;   //ekhane 4 holo snake er initial body size (not so necessary)
                    Sound                       //-Sound hobe
                    Fruit =  Randam_Function_100(Call);     // -fruit er possition change hobe

                }

            }


            Move = 1; //Smile Sign

            Sound;
            cout<<"\n\t\t\t\t\t\t\tGame Over!"<<Move<<endl;  New

            if(Score >= 100)         //if snake size is equal to playground size
            {
                Move = 2;                           //Smile Sign
                TabM cout<< "\tCongratulation!\n";
                TabM cout<<"\tLevel Complete!"<<Move;
                New New
            }

            Again = Dicission (Kall);
            if(Again!= "1") goto Menu;


        }
        break;





    case 4:     //SNAKE-BOX

        //Ei Game ti-r orthat Snake (Box)-er sathe purboborti Snake (Classic) er Besh mill royeche.
        //Sudhu Parthokko ei jaygay je Snake er Body er pashapashi Border e touch lagleo Game over hobe.
        //Tai Comment khub ekta beshi add korsi na, karon beshir vag comment-e purboborti Snake Classic a add kora hoyeche

            while(1)
        {
            int Fruit,Score = 0,temp,Finish=0,Call,Change,i,x = 0,Level;
            int Snake_Head = 46;    //snake head initial possition
            int Snake_Body[108] = {0}; //0,1-100,Primary body Size(5)+Extra some for avoid silly risk
            char key,Move='6';
            char PlayGround[109]; //0,1-100,NULL+Primary body Size(5)+Extra some for avoid silly risk

            cout << "\t\t\t\t\t\tSNAKE GAME [Box](10x10)\n\n";
            cout<<"#Introduction : Here your target is eat more Fruit to Increase Score. The Snake's Size is increasing according to eat Fruit. If the Snake Bites its Body or Border then the Game is Over.If Score=100, then the Game will be Completed. You should Choice Level according to Snake's Speed.\n\n";

            cout<< "LEVEL (1-10) :  ";
            cin>>Level;
            int delay = 500-50*Level;
            New New New;
            temp++;

            Fruit  =  Randam_Function_100(Call);

            //First Declaration of Snake Body (below)
            Snake_Body[1]  =  Snake_Head -1;
            Snake_Body[2]  =  Snake_Head -2;
            Snake_Body[3]  =  Snake_Head -3;

            while(1)
            {
                system("cls");

                cyclebox://jate fruit snake er body borabor na ase
                    Change++;
                    for(i= 3+Score; i>0; i--)
                    {
                        if(Fruit== Snake_Body[i]) {x= -1;  break; }
                    }
                    if((x== -1 || Fruit== Snake_Head) && Change<= 100 )
                    {
                        x= 0;
                        Fruit++;
                        Fruit= 1+Fruit%100;
                        goto cyclebox;
                    }

                for(i = 0; i <= 100; i++)
                {
                    PlayGround [i] = ' ' ;
                }

                PlayGround [Fruit] = temp%2+42; //Fruit Symbol (*,+)
                PlayGround [Snake_Head] = '@';    //Snake Head Symbol (Ascii 2)

                for(i = Score+3; i>0; i--)
                {
                    PlayGround [Snake_Body[i]]  =  254; //Snake Body Symbol
                }
                PlayGround [Snake_Body[Score+3]] = '-'; //Snake Tail Symbol

                cout << "\t\t\t\t\t\tSNAKE GAME [Box](10x10)\n\n";
                cout << "\t\t\t\t\t\t      Level : "<<Level<<endl;

                New;New;New;New;New;New;
                TabM;  Brdr;  BrdrM;  New;  //Border
                TabM;  Brdr;

                for(i = 1; i <= 100; i++)
                {
                   cout<<PlayGround [i]<<" ";           // show Update resulte of Game-PlayGround
                   if(i%10 == 0) {Brdr;  New;  TabM;  Brdr;  }
                }

                BrdrM New New

                TabM show       //Show Score

                //std::cout << "\r";
                //std::cout.flush();

                std::this_thread::sleep_for(std::chrono::milliseconds(delay));

                if(Snake_Head > 100 || Snake_Head<= 0 || Finish==-1) break;

                temp++; Change = 0;

                if (kbhit())
                {
                        key = getch();

                    // Check for arrow key input
                        if(key==72) // Up arrow

                            Move='8';

                        else if(key==80)// Down arrow

                            Move='2';

                        else if(key==75) // Left arrow

                            Move='4';

                        else if(key==77) // Right arrow
                            Move='6';

                        else continue;
                }

                if(Move == '5' || Move == '0') continue; //no change

                for(i = 3+Score; i>0; i--)
                {
                    Snake_Body[i] =  Snake_Body[i-1];  //Snake er body possition update
                }
                Snake_Body[1] =  Snake_Head;

                //Move to up/down/left/right/cross Moving (below)
                if(Move== '6') {Snake_Head++;      if(Snake_Head%10== 1)  { Snake_Head= 0; continue; }}      //Box e touch lagle Game over
                if(Move== '4') {Snake_Head--;      if(Snake_Head%10== 0)  { Snake_Head= 0; continue; }}      // " " "
                if(Move== '8') {Snake_Head -= 10;    }
                if(Move== '2') {Snake_Head += 10;    }

                if(Snake_Head > 100) continue;  //Box e touch lagle Game over
                if(Snake_Head <=  0) continue;  // " " "

                for(i = 3+Score; i>0; i--)
                {
                    if(Snake_Head == Snake_Body[i]) { Finish = -1; continue; } //jodi Snake nijeke Bite kore, then game over
                }

                if(Snake_Head == Fruit)         //Snake Fruit eat korar sathe sathe -
                {
                    Score++;                    //-Score barbe
                    if(Score == 97) Score += 3; //Highest point 100 korar jonno;   //ekhane 4 holo snake er initial body size (not so necessary)
                    Sound                       //-Sound hobe
                    Fruit =  Randam_Function_100(Call);     // -fruit er possition change hobe

                }

            }


            Move= 1; //Smile Sign

            Sound
            if(Finish==-1) cout << "\n\n\t\t\t\t\t\t       TOUCH BODY!";
            else                   cout << "\n\n\t\t\t\t\t\t       TOUCH BORDER!";
            cout << "\n\t\t\t\t\t\t\tGAME OVER!" << Move << endl;

            if(Score== 100)
            {
                Move= 2; //Smile Sign
                TabM cout <<  "\tCongratulation!\n";
                TabM cout << "\tLevel Complete!" << Move;
                New New
            }
            Again = Dicission (Kall);
            if(Again!= "1") goto Menu;
        }
        break;

    case 5: //Ludo Snake-Ladder (vs Computer)

/*
      Here There are 2 Player (I & Computer). Both Target is to reach 100.
      Who Reach to 100 Firstly, He is Winner.
      Every Time We Hit Dice. & The Dice Give us Value from 1 to 6.
      Ladder Help us to Increase our Possition & Snake Decrease our Possition.
*/

    New TabM cout << " LUDO SNAKE-LADDER GAME"; New New
    cout<<"#INTRODUCTION: Here There are 2 Player (You & Computer) are playing. Both Target is to reach 100. Every Time You should Hit Dice & The Dice Give you Value from 1 to 6. Ladder Help us to Increase Your Possition & Snake Decrease Your Possition. The Player, Who reach to 100 first, He is Winner. To Hit Dice Press Any-Key Everytime.\n\n\n";
        while(1)
        {
            int You= 0, Com= 0;
            int Dice, i, x= 0, temp= 0;
            New TabM cout << "Press Any Key on Everytime \n\n";
            Sound

            while(1)
            {
                getch();

                for(i= 1; i<= 2; i++)
                {
                    //getch();
                    temp += 67;
                    temp= temp%100;
                    srand(time(NULL));

                    if(i== 1)
                    {
                        Dice= (rand()/2/temp)%6;         //jodi randam number 2 khetrei same ache tai vinno songkha dara vag dichi
                        Dice ++;
                        if(You== 0 && Dice != 1) You -= Dice;    //'1' sara guti ber hobe na
                        You += Dice;

                        //snakes
                        if(You== 97)You= 12;
                        if(You== 63)You=  3;
                        if(You== 70)You= 25;
                        if(You== 32)You= 13;
                        if(You== 60)You= 38;
                        if(You== 89)You= 53;
                        if(You== 73)You= 47;
                        if(You== 82)You= 43;


                        //ladders
                        if(You== 8)  You= 41;
                        if(You== 50) You= 93;
                        if(You== 6)  You= 16;
                        if(You== 55) You= 80;
                        if(You== 59) You= 84;
                        if(You== 26) You= 29;


                       if(You>100) You -= Dice;
                       TabM2 cout << "Your Possition= " << You << "(+" << Dice << ")" << "\t";
                       if(You== 100)
                            {
                                Sound
                                New New New TabM cout << "\tCongratulation!";
                                New TabM cout << "\tYou are Winner.\n";
                                x= 1;
                                break;
                            }
                    }

                    if(i== 2)
                    {
                        Dice= (rand()/3/temp)%6; //jodi randam number 2 khetrei same ache tai vinno songkha dara vag dichi
                        Dice ++;
                        if(Com== 0 && Dice != 1) Com -= Dice; //'1' sara guti ber hobe na
                        Com += Dice;

                        //snakes
                        if(Com== 97)Com= 12;
                        if(Com== 63)Com=  3;
                        if(Com== 70)Com= 25;
                        if(Com== 32)Com= 13;
                        if(Com== 60)Com= 38;
                        if(Com== 89)Com= 53;
                        if(Com== 73)Com= 47;
                        if(Com== 82)Com= 43;


                        //laders
                        if(Com==  8)  Com= 41;
                        if(Com== 50)  Com= 93;
                        if(Com==  6)  Com= 16;
                        if(Com== 55)  Com= 80;
                        if(Com== 59)  Com= 84;
                        if(Com== 26)  Com= 29;

                       if(Com>100) Com -= Dice;
                       cout << "\tComputer Possition= " << Com << "(+" << Dice << ")" << "\t";
                       if(Com== 100)
                        {
                            Sound
                            New New New TabM cout << "\t\tSorry";
                            New TabM cout << "\t  You are Loser\n";
                            x= 1;
                            break;
                        }
                    }

                }
                if(x== 1) break;
                New

            }
            x= 0;
            Again = Dicission (Kall);
            if(Again!= "1") goto Menu;

        }
        break;




    case 6: //Ludo Snake-Ladder (Multiplayer)
/*
      Here There are multiple Players can Play. Everyone's Target is to reach 100.
      Who Reach to 100 Firstest, He is Winner.
      Every Time We Hit Dice. & The Dice Give us Value from 1 to 6.
      Ladder Help us to Increase our Possition & Snake Decrease our Possition.
*/
        while(1)
        {
            Sound
            New TabM
            cout << " LUDU SNAKE-LADDER GAME\n\n";
            cout << "#INTRODUCTION : Here There are Multiple Players can Play. Atfirst you should Select the Number of Player. Then Press Any Key to Hit the Dice. The Dice Gives you a Value from 1 to 6. Ladder Help you to Increase your Possitions & Snake Decrease your Possitions. Everyone's Target is to reach to 100. The Player Who reach to 100 First, He is Winner.\n\n";
            //cout << "#Disclaimer: \t\tLudo is Haram Game for Muslim. So you should avoid to play this.\n\n";

                int Number_of_Player;
                TabM cout << "Number of Player :\t";
                cin >> Number_of_Player;
                if(Number_of_Player<= 0) goto Menu;

                New TabM3 cout << "     Press Any Key on Everytime \n\n";
                Sound

                int Board[Number_of_Player+1]= {0}, Temp= 0, x= 0;
                int Dice, i;

                while(1)
                {
                    //getch();
                    Temp += Number_of_Player*(Temp+1)+1; //not so necessary, you can also change 'c' differently
                    Temp= Temp%99; //Minimized size, not so necessary, you can also change 'c' differently

                    for(i= 1; i<= Number_of_Player; i++)
                    {
                        Temp += 5; //not so necessary, you can also change 'c' differently
                        getch();
                        srand(time(NULL));

                            Dice= (rand()/(i+1)*i+rand()+Temp*Temp/i)%6; //just for different value of d in same time also, you can also change it differently but '%6' is must nedded
                            Dice += 1; //(0-5)-->(1-6)
                            if(Board[i]== 0 && Dice != 1) Board[i] -= Dice; //'1' chara guti ber hobe na
                            Board[i] += Dice; //position update

                            //snakes
                            if(Board[i]== 97)Board[i]= 12;
                            if(Board[i]== 63)Board[i]= 3;
                            if(Board[i]== 70)Board[i]= 25;
                            if(Board[i]== 32)Board[i]= 13;
                            if(Board[i]== 60)Board[i]= 38;
                            if(Board[i]== 89)Board[i]= 53;
                            if(Board[i]== 73)Board[i]= 47;
                            if(Board[i]== 82)Board[i]= 43;


                            //ladders
                            if(Board[i]==  8)    Board[i]= 41;
                            if(Board[i]== 50)   Board[i]= 93;
                            if(Board[i]==  6)    Board[i]= 16;
                            if(Board[i]== 55)   Board[i]= 80;
                            if(Board[i]== 59)   Board[i]= 84;
                            if(Board[i]== 26)   Board[i]= 29;


                           if(Board[i]>100) Board[i] -= Dice; //Don't cross 100

                           cout << "Player-" << i << " : " << Board[i] << "(+" << Dice << ")" << "\t"; //Print

                           if(Board[i]== 100)//Winner
                                {
                                    Sound
                                    New New New
                                    TabM
                                    cout << " Congratulation!\n\t\t\t\t\t\tPlayer " << i << " is Winner\n\n\n";
                                    x= 1;
                                    break;
                                }


                    }
                    New
                    if(x== 1) break;

                }

            x= 0;
            Again = Dicission (Kall);
            if(Again!= "1") goto Menu;
        }
        break;




    case 7: //Sudoku (Fixed Given Value)

/*
        Here We should Fill up All of the Blank Space properly (according to
        Sudoku Rules.)
*/
        while(1)
        {
            TabM cout << "\tSUDOKU GAME\n\n\n";
            cout<<"#Introduction: Here You should Fill Up All of the Blank Space Properly (According to Sudoku Rules).\nTo insert value in the Index, select row(1-9) & column(1-9) number of the Index, then input the value. You can't change the Given Value. If you fill up all the blank space properly, then the level will be completed & You get Congratulation. Otherwise Game will be Running. But if you want to close the program, Select Negetive Value of row or column.   \n\n\n";
            int Sudoku[101]= {0}, cnt, row, col, Index, Value, i, j, k;  //Sudoku holo Main Array jeti sokol index Value contain korbe, etake 2D array hisebeo Newa jaito but ami neini
            char Temp[101];   // ei string-tar kaj holo, jate given index gulor value ami poriborton korte na pari.


            //Given Index Value (below) <-- Eigulo ami amar iccha onujayi sohoj vabe diyechi, onno jekono proper value input dewa jabe
            srand(time(NULL));
            int Randam= rand() %9 +1;

            Sudoku[21]= Randam + 1;
            Sudoku[22]= Randam + 2;
            Sudoku[23]= Randam + 3;
            Sudoku[24]= Randam + 4;
            Sudoku[26]= Randam + 6;
            Sudoku[27]= Randam + 7;
            Sudoku[28]= Randam + 8;
            Sudoku[29]= Randam + 9;

            Sudoku[31]= Randam + 4;
            Sudoku[32]= Randam + 5;
            Sudoku[33]= Randam + 6;
            Sudoku[34]= Randam + 7;
            Sudoku[36]= Randam + 9;
            Sudoku[37]= Randam + 1;
            Sudoku[38]= Randam + 2;
            Sudoku[39]= Randam + 3;

            Sudoku[41]= Randam + 2;
            Sudoku[42]= Randam + 3;
            Sudoku[43]= Randam + 1;
            Sudoku[44]= Randam + 5;
            Sudoku[46]= Randam + 4;
            Sudoku[47]= Randam + 8;
            Sudoku[48]= Randam + 9;
            Sudoku[49]= Randam + 7;

            Sudoku[61]= Randam + 8;
            Sudoku[62]= Randam + 9;
            Sudoku[63]= Randam + 7;
            Sudoku[64]= Randam + 2;
            Sudoku[66]= Randam + 1;
            Sudoku[67]= Randam + 5;
            Sudoku[68]= Randam + 6;
            Sudoku[69]= Randam + 4;

            Sudoku[71]= Randam + 6;
            Sudoku[72]= Randam + 4;
            Sudoku[73]= Randam + 5;
            Sudoku[74]= Randam + 9;
            Sudoku[76]= Randam + 8;
            Sudoku[77]= Randam + 3;
            Sudoku[78]= Randam + 1;
            Sudoku[79]= Randam + 2;

            Sudoku[81]= Randam + 9;
            Sudoku[82]= Randam + 7;
            Sudoku[83]= Randam + 8;
            Sudoku[84]= Randam + 3;
            Sudoku[86]= Randam + 2;
            Sudoku[87]= Randam + 6;
            Sudoku[88]= Randam + 4;
            Sudoku[89]= Randam + 5;

            for(i=11;i<100;i++)
            {
                if(Sudoku[i]>9) Sudoku[i]=Sudoku[i]-9;
            }

            TabM                                //Likha gulo jate majhe dekha jay

            //Initial print(below Loop)
            for(i= 11; i<100; i++)
            {
                if  (Sudoku[i]== 0)   printf("%c  ", Sudoku[i]+'.');
                else                  printf("%c  ", Sudoku[i]+'0');

                if((i%10)% 3== 0)               cout << " ";
                if((i/10)% 3== 0 && i%10== 9)  {New  TabM}
                if(i%10== 9)                   {i++; New  TabM}

            }
            Sound

            //(below-Loop)--> kongulo index initially faka chilo r kongulo faka chilo na seta jachai
            for(i= 0; i<= 100; i++)
            {
                if(Sudoku[i]== 0 ) Temp[i]= 0 ;
                else               Temp[i]= 1 ;
            }

            cout << "\n\n\n";
            TabM2 cout << "You should Fill Up All The Empty(Dot Sign) Index by Inserting Proper Value\n\n";


            while(1)
            {
                char flag= 1;                                       //Shorto Puron Korte perechi kina seta jachai

                cout << "Enter 'ROW' & 'COLUMN' Number [Separately or Combinedly]  : ";
                cin>>row;

                if(row/10!=0) {col= row %10;    row= row /10; }         // keu jodi chay row column er majhe kono space na diye direct likhte pare se jonno
                else         cin>>col;

                if(row<0 || col<0 ) goto Menu;                      //if I want to close the program
                if(col >9) col= 0;
                if(row >9) row= 0;                                 //ei 2 line dewa khub important chilo na, tao diyechi ejonno je jate Big Value dileo Program thik moro Run hoy

                Index=10*row+col;

////              cout<<"Enter Index Number \t: ";
////              cin>>Index;
////              row=Index/10; col=Index%10;
////              if(Index<0 || Index >99) goto Menu;

                if(Temp[Index] != 0) {cout << "Not Changeable\n\n"; continue; }  //Given Value gulo Change kora jabe na
                if(row==0 || col==0) {cout << "ERROR SWITCH\n\n"; continue; }

                cout << "Index[" << row << "][" << col << "]\t  = ";
                cin >> Value;  //Index Value Input

                system("cls");

                if(Value<0) Value= -Value;
                if(Value>9) Value= Value%10; //ei 2 line dewa khub important chilo na, tao diyechi ejonno je jate jekono value dile thikmoto Input hoy

                Sudoku[Index]= Value; //Initilized

                //Row-Wise Shorto puron hoyeche kina seta jachai(below-Loop)
                for(k= 1; k<= 9; k++)
                {
                    for(j= 11; j<= 91; j += 10)
                    {
                        cnt= 0;
                        for(i= j; i<= j+8; i++)
                        {
                            if(Sudoku[i]== k) cnt++;
                        }
                        if(cnt != 1) {flag= 0; break; }
                    }
                    if(flag== 0) break;
                }

                //Row-Wise Shorto puron hoyeche kina seta jachai(below-Loop)
                for(k= 1; k<= 9; k++)
                {
                    if(flag== 0) break;

                    for(j= 11; j<= 19; j++)
                    {
                        cnt= 0;
                        for(i= j; i<= 99; i += 10)
                        {
                            if(Sudoku[i]== k) cnt++;
                        }
                        if(cnt  !=  1) {flag= 0; break; } //Sobgulo Number Kebol-Matro 1 bar ache kina; na thakle shorto puron hoyni
                    }
                    if(flag== 0) break;
                }


                //(3*3)-Size er Box gulote Shorto puron hoyeche kina seta jachai (below 9 Macro loop)

                for(k= 1; k<= 9; k++)           //3*3(1) cheak
                {
                    if(flag== 0) break;
                        cnt= 0;
                    for(j= 11; j<= 39; j += 10)
                    {
                        for(i= j; i<= j+2; i++)
                        {
                            if(Sudoku[i]== k) cnt++;
                        }

                    }
                    if(cnt != 1) {flag= 0; break; }
                }

                for(k= 1; k<= 9; k++)           //3*3(2) cheak
                {
                    if(flag== 0) break;
                        cnt= 0;
                    for(j= 14; j<= 39; j += 10)
                    {
                        for(i= j; i<= j+2; i++)
                        {
                            if(Sudoku[i]== k) cnt++;
                        }

                    }
                    if(cnt != 1) {flag= 0; break; }

                }

                 for(k= 1; k<= 9; k++)           //3*3(3) cheak
                {
                    if(flag== 0) break;
                                    cnt= 0;
                    for(j= 17; j<= 39; j += 10)
                    {
                        for(i= j; i<= j+2; i++)
                        {
                            if(Sudoku[i]== k) cnt++;
                        }

                    }
                    if(cnt != 1) {flag= 0; break; }
                }

                 for(k= 1; k<= 9; k++)           //3*3(4) cheak
                {
                    if(flag== 0) break;
                                    cnt= 0;
                    for(j= 41; j<= 69; j += 10)
                    {

                        for(i= j; i<= j+2; i++)
                        {
                            if(Sudoku[i]== k) cnt++;
                        }

                    }
                    if(cnt != 1) {flag= 0; break; }
                }

                 for(k= 1; k<= 9; k++)           //3*3(5) cheak
                {
                    if(flag== 0) break;
                                    cnt= 0;
                    for(j= 44; j<= 69; j += 10)
                    {

                        for(i= j; i<= j+2; i++)
                        {
                            if(Sudoku[i]== k) cnt++;
                        }

                    }
                    if(cnt != 1) {flag= 0; break; }
                }

                 for(k= 1; k<= 9; k++)           //3*3(6) cheak
                {
                    if(flag== 0) break;
                                    cnt= 0;
                    for(j = 47; j<= 69; j += 10)
                    {
                        for(i= j; i<= j+2; i++)
                        {
                            if(Sudoku[i]== k) cnt++;
                        }

                    }
                    if(cnt != 1) {flag= 0; break; }
                }

                 for(k= 1; k<= 9; k++)           //3*3(7) cheak
                {
                    if(flag== 0) break;
                                    cnt= 0;
                    for(j= 71; j<= 99; j += 10)
                    {

                        for(i= j; i<= j+2; i++)
                        {
                            if(Sudoku[i]== k) cnt++;
                        }

                    }
                    if(cnt != 1) {flag= 0; break; }
                }

                 for(k= 1; k<= 9; k++)           //3*3(8) cheak
                {
                    if(flag== 0) break;
                                    cnt= 0;
                    for(j= 74; j<= 99; j += 10)
                    {

                        for(i= j; i<= j+2; i++)
                        {
                            if(Sudoku[i]== k) cnt++;
                        }

                    }
                    if(cnt != 1) {flag= 0; break; }
                }

                 for(k= 1; k<= 9; k++)           //3*3(9) cheak
                {
                    if(flag== 0) break;
                                    cnt= 0;
                    for(j= 77; j<= 99; j += 10)
                    {

                        for(i= j; i<= j+2; i++)
                        {
                            if(Sudoku[i]== k) cnt++;
                        }

                    }
                    if(cnt != 1) {flag= 0; break; }
                }


                TabM cout << "\tSUDOKU GAME\n\n\n";
                cout<<"#Introduction: Here You should Fill Up All of the Blank Space Properly (According to Sudoku Rules).\nTo insert value in the Index, select row(1-9) & column(1-9) number of the Index, then input the value. You can't change the Given Value. If you fill up all the blank space properly, then the level will be completed & You get Congratulation. Otherwise Game will be Running. But if you want to close the program, Select Negetive Value of Row or Column.   \n\n\n";

                New TabM

                //Print the Sudoku Matrix(Below)
                for(i= 11; i<100; i++)
                {
////                    cout << Sudoku[i] << "  ";
                    if      (Sudoku[i]== 0)            printf("%c  ", Sudoku[i]+'.'); //'0' use korle Empty Index gulo bujhte osubidha hoy, tai '.' use korechi
                    else if (Temp  [i]== 0)            printf("%c` ", Sudoku[i]+'0');
                    else                               printf("%c  ", Sudoku[i]+'0');
                    if((i%10)% 3== 0) cout << " ";
                    if((i/10)% 3== 0 && i%10== 9) {New  TabM}
                    if(i%10== 9) {i++; New  TabM}

                }

                cout << "\n\n";
                TabM2 cout << "You should Fill Up All The Empty(Dot Sign) Index by Inserting Proper Value\n\n";


                Sound

                if(flag== 1){TabM cout << "   Congratulation\n"; break; } //jodi Shobgulo Shorto thik moto fill up hoy, tobe Ami thik moto Game sompurno korte perechi

            }

            getch(); TabM cout << "   Congratulation\n";
            getch(); TabM cout << "   Congratulation\n"; // 3 time Congratulation (not so necessary)


            Again = Dicission (Kall);
            if(Again!= "1") goto Menu;


        }
        break;

    case 8:

        while(1)
        {
            TabM cout<<"  Mini GAMES\n\n";

            srand(time(NULL));
            int Choice = rand() %4;

            MiniMenu:

                Choice++;
                if(Choice>4) Choice-=4;

                switch(Choice){

                case 1:
                    while(1)
                    {
                        int Bulet,Kil=0,Shoot,Diffc,Temp=100 ;

                        TabM  cout<<"  Shooting Game\n\n";

                        TabM2 cout<<"Diffculty (Enter a Little Positive Intizer Number)  =  ";
                        cin>>Diffc ;
                        if(Diffc <0) goto Menu;

                        TabM2 cout<<"BULLET    (    Enter Number of Bullet with You   )  =  ";
                        cin>>Bulet;

                        int Enimi = ceil(Bulet/1.0/(Diffc +1));  // avarage luck

                        TabM2 cout<<"TARGATED ENEMY TO KILL                            =  "<<Enimi<<endl;

                        cout<<"\nEverytime Press Any Key for shooting Bullet: \n\n";


                        for(int i=1;i<=Bulet;i++)
                        {

                            srand(time(NULL));
                            Temp++;
                            getch();
                            Shoot = rand() *3/2 + Temp;
                            Shoot++;

                            if(rand() %(Diffc+1) == Shoot %(Diffc+1)) Kil++;

                            cout<<"\t\t";
                            cout<<  \
                            "Current Kill  : "<<Kil<< \
                            "\t   Bullet Spends  : "<< i<< \
                            "\t   Bullet Left  : "<<Bulet-i<< \
                            "\t   Target Enemy Left  : "<< Enimi-Kil <<endl;

                        }

                        New TabM
                        cout<<"Total Kill = "<<Kil<<endl;

                        New TabM2
                        if(Kil> Enimi) cout<<"Congratulations! You Kill more than Target.\n";
                        if(Kil==Enimi) cout<<"Congratulations! You Kill  Equal to Target.\n";
                        if(Kil< Enimi) cout<<"Alas! You Kill Less than Target.\n";

                        Again = Dicission_Mini (Kall);
                        if      (Again== "1") ;
                        else if (Again== "2") goto MiniMenu;
                        else                  goto Menu;

                    }

                case 2:
                    while(1)
                    {
                        cout<<"\t\t\t\t\t\t   Toss Game\n\n";
                        cout<<"\t\t\t\t\tPress 'H' to chose Head\n";
                        cout<<"\t\t\t\t\tPress 'T' to chose Tail\n";
                        cout<<"\t\t\t\t\tPress 'x' to Close the game\n\n";

                        int win=0,lost=0;
                        while(1)
                        {
                            int n;
                            char you,com;
                            cout<<"Press 'H' or 'T' (without quatation)\t:\t";
                            cin>>you;
                            system("cls");
                            you=toupper(you);
                            if(you!='H' && you!= 'T') break;

                            srand(time(NULL));

                            n=rand()%2;
                            if(n==0) com='T';
                            else     com='H';

                            cout<<"\t\t\t\t\t\t   Toss Game\n\n";
                            cout<<"\t\t\t\t\tPress 'H' to chose Head\n";
                            cout<<"\t\t\t\t\tPress 'T' to chose Tail\n";
                            cout<<"\t\t\t\t\tPress 'x' to Close the game\n\n";


                            New
                            cout<<"  You chose       : "<<you ; New
                            cout<<"& Computer chose  : "<<com<<"\n\n";

                            Sound New New TabM
                            if(you==com) { cout<<"  Winner\n\n"; win++;}
                            else         { cout<<"   Loser \n\n";                           lost++;}

                        }
                        cout<<"\t\t\t\t\t\t   Toss Game\n\n";

                        Sound
                        New TabM2 cout<<"          Match Ended     ";
                        New TabM2 cout<<"          Your Score=  "<<win;
                        New TabM2 cout<<"      & Computer's Score=  "<<lost;

                        New New TabM
                        if      (win>lost) cout<<"Congratulation!\n\t\t\t\t\tYou won More mach than Computer\n\n";
                        else if (win<lost) cout<<"    Sorry!     \n\t\t\t\t\tYou won Less match than Computer\n\n";
                        else               cout<<"    Drawn      \n\t\t\t\t\tYou won Equal mach than Computer\n\n";

                        Again = Dicission_Mini (Kall);
                        if      (Again== "1") ;
                        else if (Again== "2") goto MiniMenu;
                        else                  goto Menu;

                    }

                case 3:
                    while(1)
                    {
                        int Bulet,Kil=0,Shoot,Diffc,Temp=100 ;

                        TabM  cout<<"  Battle Game\n\n";

                        TabM2 cout<<"Diffculty (Enter a Little Positive Intizer Number)  =  ";
                        cin>>Diffc ;
                        if(Diffc <0) goto Menu;

                        TabM2 cout<<"RPJ       (    Enter Number of Bullet with You   )  =  ";
                        cin>>Bulet;

                        int Enimi = ceil(Bulet/1.0/(Diffc +1));  // avarage luck

                        TabM2 cout<<"TARGATED TANK TO DESTROY                            =  "<<Enimi<<endl;

                        cout<<"\nEverytime Press Any Key for shooting Bullet: \n\n";


                        for(int i=1;i<=Bulet;i++)
                        {

                            srand(time(NULL));
                            Temp++;
                            getch();
                            Shoot = rand() *3/2 + Temp;
                            Shoot++;

                            if(rand() %(Diffc+1) == Shoot %(Diffc+1)) Kil++;

                            cout<<"\t\t";
                            cout<<  \
                            "Current Brusted TANK  : "<<Kil<< \
                            "\t   RPJ Spends  : "<< i<< \
                            "\t   RPJ Left  : "<<Bulet-i<< \
                            "\t   Target TANK Left  : "<< Enimi-Kil <<endl;

                        }

                        New TabM
                        cout<<"Total Brusted = "<<Kil<<endl;

                        New TabM2
                        if(Kil> Enimi) cout<<"Congratulations! You Brust more than Target.\n";
                        if(Kil==Enimi) cout<<"Congratulations! You Brust  Equal to Target.\n";
                        if(Kil< Enimi) cout<<"Alas! You Brust Less than Target.\n";

                        Again = Dicission_Mini (Kall);
                        if      (Again== "1") ;
                        else if (Again== "2") goto MiniMenu;
                        else                  goto Menu;

                    }


                case 4:
                    while(1)
                    {
                        cout<<"\t\t\t\t\tRock Paper Seissor Game\n\n";
                        cout<<"\t\t\t\t\tPress 'R' to chose Rock\n";
                        cout<<"\t\t\t\t\tPress 'P' to chose Paper\n";
                        cout<<"\t\t\t\t\tPress 'Z' to chose Seissor\n";
                        cout<<"\t\t\t\t\tPress 'X' to close the game\n\n";
                        int win=0,lost=0;
                        while(1)
                        {
                            int n;
                            Sound
                            char you,com;
                            cout<<"\nPress 'R' or 'P' or 'Z' (without quatation)\t:\t";
                            cin>>you;
                            you = toupper(you);
                            system("cls");

                            if(you=='X') break;

                            srand(time(NULL));

                            n=rand()%3;
                            if     (n<1) com='R';
                            else if(n<2) com='P';
                            else         com='Z';

                            cout<<"\t\t\t\t\tRock Paper Seissor Game\n\n";
                            cout<<"\t\t\t\t\tPress 'R' to chose Rock\n";
                            cout<<"\t\t\t\t\tPress 'P' to chose Paper\n";
                            cout<<"\t\t\t\t\tPress 'Z' to chose Seissor\n";
                            cout<<"\t\t\t\t\tPress 'X' to close the game\n\n";

                            New
                            cout<<"Your    Choice         \t:\t"<<you<<endl;
                            cout<<"Computer Chose         \t:\t"<<com<<endl;

                            New TabM
                            if(you==com) cout<<"Drawn\n\n";

                            else if (you=='P' && com=='R' || you=='Z' && com=='P' || you=='R' && com=='Z')
                            {
                                win++;
                                cout<<"Winner\n\n";
                            }
                            else if (you=='R' && com=='P' || you=='P' && com=='Z' || you=='Z' && com=='R')
                            {
                                lost++;
                                cout<<"Loser\n\n";
                            }

                            else
                            {
                                cout<<"Error! Give Correct Input\n\n";
                                break;
                            }


                        }

                        cout<<"\t\t\t\t\tRock Paper Seissor Game\n\n";
                        New TabM3 cout<<"       Match Ended     ";
                        New TabM3 cout<<"       Your Score= "<<win;
                        New TabM3 cout<<"   & Computer's Score= "<<lost;

                        New New TabM
                        if      (win>lost) cout<<"Congratulation!\n\t\t\t\t\tYou won More mach than Computer\n\n";
                        else if (win<lost) cout<<"    Sorry!     \n\t\t\t\t\tYou won Less match than Computer\n\n";
                        else               cout<<"    Drawn      \n\t\t\t\t\tYou won Equal mach than Computer\n\n";

                        Again = Dicission_Mini (Kall);
                        if      (Again== "1") ;
                        else if (Again== "2") goto MiniMenu;
                        else                  goto Menu;
                    }


                }

        }


    case 0:
        cout << "\t\t\t\t\t\t Program is Closed.\n";
        cout << "\t\t\t\t\t\tJajakallahu Khairan.\n\n";
        getch();
        return 0;


    default:
        cout << "\t\t\t\t\t\tError Switching!\n\t\t\t\t\t\tProgram is Closed.\n";
        cout << "\t\t\t\t\t\tJajakallahu Khairan.\n\n";
        getch();
        return 0;
    }

    goto Menu;

}
