//#include <bits/stdc++.h>

#include <iostream>    // cout, cin, endl, printf
#include <cstdlib>     // rand, srand, abs, system()
#include <ctime>       // time() — srand(time(0)) এর জন্য
#include <thread>      // this_thread::sleep_for
#include <chrono>      // chrono::milliseconds
#include <string>      // string
#include <algorithm>   // fill, min, max
#include <cmath>

#include <windows.h>
#include <conio.h>                     //for getch() & kbhit condition;

/// Tabs & Carriage_Return
#define tab cout<<"\t";
#define tabs for (iGlobal=0;iGlobal<TabNumber;iGlobal++) tab
#define Multi_Tabs_1  tabs tab tab    //Likhagulo Middle Show korar jonno
#define Multi_Tabs_2 tabs tab cout << "  ";
#define Multi_Tabs_3 tabs cout << "     ";
#define Multi_Tabs_4 tabs
#define Carriage cout<<"\r";

///New-Line & Sound
#define NewLine cout << "\n";
#define Sound if(SoundFlag == true) cout << "\a";
//#define Auto_Change_Text_Color if (is_Continuous_Change_Color) changeTextColour();

#define Border_Sign          if(Snake_Marker==1 || Snake_Marker==2 || Snake_Marker==5 || Snake_Marker==6 || Snake_Marker==9) cout<<". ";                             else cout<<char(219);
#define Multiple_Border_Sign if(Marker==2) for(int i=0;i<21;i++) cout<<char(219); else if(Snake_Marker==1 || Snake_Marker==2 || Snake_Marker==5 || Snake_Marker==6 || Snake_Marker==9) for(int i=0;i< Snake_Area_Column + 1; i++) Border_Sign       else for(int i=0;i<2*Snake_Area_Column +1;i++) Border_Sign

#define show_Point  cout << "\tScore : " << (Level)*Point << "               " << endl << endl;
#define showScore   cout << "\tScore : " << Score << endl;
#define showLife    cout << "\t Life : " << Life << endl << endl;

using namespace std;

// Global Variables <below>
int Marker=1;
char Markered_Symbol, Design_Symbol;
char KEY;
                                                                                                                                                                                                                                    string Coder_Name = "Coded by \'Tajmil Anwar Tamim\'";
int Time_Delay=1;   //time Delay in every KEY-hit.
int KeyHit_Cheak_Count=0;

int TabNumber=6,iGlobal;

bool SoundFlag  = true;
bool is_Premium = false;
bool is_Playing = false;
//bool is_Continuous_Change_Color= false;

enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Yellow = 6,
    White = 7,
    Gray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    LightYellow = 14,
    BrightWhite = 15
};

// Function to set text color
void SetConsoleColor(ConsoleColor color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void SetConsoleColour(ConsoleColor textColor, ConsoleColor bgColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
}


int ColorVar;

void changeTextColour()
{
    ColorVar++;
    ColorVar = 8 + ColorVar % 8;

    if(ColorVar == 8) SetConsoleColor(White);
    if(ColorVar == 9) SetConsoleColor(LightBlue);
    if(ColorVar == 10) SetConsoleColor(LightGreen);
    if(ColorVar == 11) SetConsoleColor(LightCyan);
    if(ColorVar == 12) SetConsoleColor(LightRed);
    if(ColorVar == 13) SetConsoleColor(LightMagenta);
    if(ColorVar == 14) SetConsoleColor(LightYellow);
    if(ColorVar == 15) SetConsoleColor(BrightWhite);
}

void changeTextColour2()
{
    ColorVar++;
    if(ColorVar<0) ColorVar+=8;
    ColorVar = ColorVar % 8;

    if(ColorVar == 0) SetConsoleColour(Gray,BrightWhite);
    if(ColorVar == 1) SetConsoleColour(Blue,BrightWhite);
    if(ColorVar == 5) SetConsoleColour(Green,BrightWhite);
    if(ColorVar == 2) SetConsoleColour(Cyan,BrightWhite);
    if(ColorVar == 3) SetConsoleColour(Red,BrightWhite);
    if(ColorVar == 4) SetConsoleColour(Magenta,BrightWhite);
    if(ColorVar == 6) SetConsoleColour(Yellow,BrightWhite);
    if(ColorVar == 7) SetConsoleColour(Black,BrightWhite);
}

void changeBgColour()
{
    ColorVar++;
    ColorVar = 8 + ColorVar % 8;

    if(ColorVar == 8)  SetConsoleColour(Black, White );
    if(ColorVar == 10) SetConsoleColour(Black,LightBlue);
    if(ColorVar == 9)  SetConsoleColour(Black,Green);
    if(ColorVar == 11) SetConsoleColour(Black,LightCyan);
    if(ColorVar == 12) SetConsoleColour(Black,LightRed);
    if(ColorVar == 13) SetConsoleColour(Black,LightMagenta);
    if(ColorVar == 14) SetConsoleColour(Black,LightYellow);
    if(ColorVar == 15) SetConsoleColour(Black,BrightWhite);
}

void changeBgColour2()
{
    ColorVar++;
    if(ColorVar<0) ColorVar+=8;
    ColorVar = ColorVar % 8;

    if(ColorVar == 0) SetConsoleColour(BrightWhite,Black);
    if(ColorVar == 1) SetConsoleColour(BrightWhite,Blue);
    if(ColorVar == 2) SetConsoleColour(BrightWhite,Green);
    if(ColorVar == 3) SetConsoleColour(BrightWhite,Cyan);
    if(ColorVar == 4) SetConsoleColour(BrightWhite,Red);
    if(ColorVar == 5) SetConsoleColour(BrightWhite,Magenta);
    if(ColorVar == 6) SetConsoleColour(BrightWhite,Yellow);
    if(ColorVar == 7) SetConsoleColour(BrightWhite,Gray);
}

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void clearScreen() {

    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    DWORD cells = screen.dwSize.X * screen.dwSize.Y;

    FillConsoleOutputCharacterA(console, ' ', cells, topLeft, &written);
    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
                               cells, topLeft, &written);
    SetConsoleCursorPosition(console, topLeft);
}

int DisplayWorldView_Var=0;

void DisplayWorldView()
{
    DisplayWorldView_Var = 1 + DisplayWorldView_Var % 9;

    if(DisplayWorldView_Var==1) cout<<"\r"<<"Pray For Arakan                ";
    if(DisplayWorldView_Var==2) cout<<"\r"<<"Pray For Kashmir               ";
    if(DisplayWorldView_Var==3) cout<<"\r"<<"Pray For Uighur                ";
    if(DisplayWorldView_Var==4) cout<<"\r"<<"Pray For Filistin              ";
    if(DisplayWorldView_Var==5) cout<<"\r"<<"Pray For Yemen                 ";
    if(DisplayWorldView_Var==6) cout<<"\r"<<"Pray For Africa                ";
    if(DisplayWorldView_Var==7) cout<<"\r"<<"Pray For Baytul Mukaddis       ";
    if(DisplayWorldView_Var==8) cout<<"\r"<<"Pray For All Oppressed         ";
    if(DisplayWorldView_Var==9) cout<<"\r"<<"Never Forget Them              ";

    if(TabNumber<4) cout<<"                    ";
}


void Instruction()
{
    system("cls");
    cout<<"COMMON INSTRUCTIONS :  \n\n";

    changeTextColour();     cout<<"Press -->   \' or ; Key  :  to Change Text Colour     in Black BackGround\n";
    changeTextColour2();    cout<<"Press -->   \" or : Key  :  to Change Text Colour     in White BackGround\n"; NewLine
    changeBgColour2();      cout<<"Press -->   ] or [ Key  :  to Change BackGround Colour   with White Text\n";
    changeBgColour();       cout<<"Press -->   } or { Key  :  to Change BackGround Colour   with Black Text\n"; NewLine

    SetConsoleColor(BrightWhite);        cout<<"Press -->   \\ Key   : to Flush Color in Text/BackGround = White/Black\n";
    SetConsoleColour(Black,BrightWhite);  cout<<"Press -->   | Key   : to Flush Color in Text/BackGround = Black/White\n"; NewLine

//    SetConsoleColor(BrightWhite);
    cout<<"Press -->   '+' Key  : to Decrese  KeyHit Speed\n";
    cout<<"Press -->   '-' Key  : to Increase KeyHit Speed\n";  NewLine

    SetConsoleColour (Black,BrightWhite);
    cout<< "Press -->   '<' Key  : to Shift Texts  Left     \n";
    cout<< "Press -->   '>' Key  : to Shift Texts Right     \n";  NewLine

//    SetConsoleColor(BrightWhite);
    cout<< "Press -->   '`' Key  : to Mute       \n";
    cout<< "Press -->   '~' Key  : to UnMute     \n\n";

    cout<< "Press -->  <Small'p'> to Change SYMBOL MODE\n";
    cout<< "\t:[PREMIUM --> NORMAL OR NORMAL --> PREMIUM\n";
    cout<< "\t:Premium SYMBOL (This can be misbehave in Some System)\n";
    cout<< "\t:Normal  SYMBOL (Run Perfectly in All System)\n\n";

    cout<<"Always try to TURN OFF CAPS LOCK KEYS.\n";
    cout<<"\t:Because in KEY-PRESSING-TIME: Capital Some Letter Conflict with SCROLL KEYS.\n\n";

    SetConsoleColour (Black,BrightWhite);
    cout<<"Press -->  < Home Key >, to Goto Main Menu\n";
    cout<<"Press -->  < End  Key >, to close the Program or End the playing Game\n\n";

    //SetConsoleColor(BrightWhite);

    changeTextColour(); changeTextColour2();
    changeBgColour();   changeBgColour2();

    //getch();
}

void Snake_Instruction()
{
//    SetConsoleColour (Black,BrightWhite);

    cout<<"\n\nSNAKE-GAME INSTRUCTION :\n Here your target is Eat more Fruit to Increase Score. The Snake's Size is increasing according to eat Fruit. You should Control the Snake by using Arrow KEY.\
Select Snake Game Type & Select Level Then Play the Game. You can customize Snake Area Size. You can Also Change Snake Style & Color. You can Also see the Playing of AI.\n\nIn Playing Time : \n";

     Multi_Tabs_1 cout<<"To Move Snake         -> Press <      Arrow_Keys    >"<<endl;
     Multi_Tabs_1 cout<<"To Pause              -> Press <      Space Key     >"<<endl;
     Multi_Tabs_1 cout<<"To Change Snake Style -> Press < Small  i/o/p  Keys >"<<endl;
     Multi_Tabs_1 cout<<"To Shift PlayGround   -> Press < Angle Bracket Keys >"<<endl;
     Multi_Tabs_1 cout<<"To Change Color       -> Press <    []{}'\";:  Keys >"<<endl;
     Multi_Tabs_1 cout<<"Any Graphical Problem -> Press <      Enter-Key     >"<<endl;
     Multi_Tabs_1 cout<<"To Quit the Game      -> Press <       End Key      >\n"<<endl;
     Multi_Tabs_1 cout<<"Now to Back the Game  -> Press     Space/Enter Key   \n"<<endl;

//     changeTextColour(); changeTextColour2();
//     changeBgColour();   changeBgColour2();

     getch(); system("cls");

}


void Key_Hit_Maintainor()
{
    if(KEY=='+' || KEY=='=') {Time_Delay++; Sound if(Time_Delay>100) Time_Delay=91; if(Time_Delay>10) Time_Delay+=9; }
    if(KEY=='-' || KEY=='_') {Time_Delay--; Sound if(Time_Delay<0)   Time_Delay=0;  if(Time_Delay>10) Time_Delay-=9; }

    if (KEY=='p' && is_Premium == false) is_Premium = true ;
    else if (KEY=='p' && is_Premium == true ) is_Premium = false;

    if (KEY=='\''){ changeTextColour();  cout <<"\r[Text Colour Changed]"; }
    if (KEY=='"') { changeTextColour2(); cout <<"\r[Text Colour Changed]"; }
    if (KEY==';') { ColorVar -= 2; changeTextColour(); cout <<"\r[Text Colour Changed]"; }
    if (KEY==':') { ColorVar -= 2; changeTextColour2(); cout <<"\r[Text Colour Changed]"; }

    if (KEY=='}')   { changeBgColour();   cout <<"\r[BackGround Colour Changed]";}
    if (KEY==']')   { changeBgColour2();  cout <<"\r[BackGround Colour Changed]";}
    if (KEY=='{')   {ColorVar -= 2; changeBgColour();   cout <<"\r[BackGround Colour Changed]";}
    if (KEY=='[')   {ColorVar -= 2; changeBgColour2();  cout <<"\r[BackGround Colour Changed]";}

    if (KEY=='\\')  {ColorVar=0;    SetConsoleColor(BrightWhite);           cout <<"\r[Flash Color W/B]";}
    if (KEY=='|')   {ColorVar=0;    SetConsoleColour(Black,BrightWhite);    cout <<"\r[Flash Color B/W]";}

    if (KEY=='<' || KEY==',')  {TabNumber--; if(TabNumber<0) TabNumber=0; if((Marker==1 || Marker==2) && is_Playing == true) system("cls");}
    if (KEY=='>' || KEY=='.')  {TabNumber++;                              if((Marker==1 || Marker==2) && is_Playing == true) system("cls");}
    if (KEY=='^')  {TabNumber=5;                                          if((Marker==1 || Marker==2) && is_Playing == true) system("cls");}
    if (KEY=='`')  {SoundFlag=false; cout<<"\rMuted  ";}
    if (KEY=='~')  {SoundFlag= true; cout<<"\r\aUnmuted";}

    KeyHit_Cheak_Count++; // not necessery

//    if (KEY=='l' && is_Continuous_Change_Color==false) is_Continuous_Change_Color=true;
//    if (KEY=='l' && is_Continuous_Change_Color==true) is_Continuous_Change_Color= false;
}

char Dicission (char a)
{
    NewLine NewLine NewLine
    Multi_Tabs_2 cout << "\tTo Play Again     Press- <Space> or <Enter>  \n";
    Multi_Tabs_2 cout << "\tTo Goto Menu      Press- <Home>  or  <End>   \n";

    while(true)
    {
        this_thread::sleep_for(chrono::milliseconds(Time_Delay));
        if (kbhit())           //Control by arrow KEY
        {
            KEY = _getch();      Key_Hit_Maintainor();

            if    (KEY==' ' || KEY == 13 )                                  {a= '1';   break;}
            if    (KEY=='x' || KEY=='X' || KEY==71 )                        {a= '0';   break;}
            if    (KEY==79)                                                 {a= '0';   break;}

        }
    }

    NewLine NewLine NewLine
    system("cls");
    return a;
}

int  Snake_Area_Row = 15 , Snake_Area_Column = 20 ;

char Dicission_in_Snake_And_Pac_Game  (char a)
{
    NewLine
    Multi_Tabs_3 cout << "\tTo Play Again in Different Speed                 :  Press-  <Esc> \n";
    Multi_Tabs_3 cout << "\tTo Play Again in    Same   Speed                 :  Press- <Space> \n";
    Multi_Tabs_3 cout << "\tTo Goto Local Menu                               :  Press-  <Home>\n";
    Multi_Tabs_3 cout << "\tTo Goto Main  Menu                               :  Press-  <End>\n";

    while(true)
    {
        this_thread::sleep_for(chrono::milliseconds(Time_Delay));
        if (kbhit())           //Control by arrow KEY
        {
            KEY = _getch();      Key_Hit_Maintainor();

            if    (KEY== 32 || KEY == 13 )                                      {a= '3';   break;}
            if    (KEY== 27 )                                                   {a= '2';   break;}
            if    (KEY=='x' || KEY=='X' || KEY==71 )                            {a= '1';   break;}
            if    (KEY== 79)                                                    {a= '0';   break;}
        }
    }

    NewLine NewLine NewLine
    system("cls");
    return a;
}

char Dicission_TicTacToe (char a)
{
    NewLine
    Multi_Tabs_4 cout << "\tTo Play Again in 'Different Level'                     :  Press- <ESC> KEY\n";
    Multi_Tabs_4 cout << "\tTo Play Again in 'Same Level'                          :  Press- <Back-Space> KEY\n";
    Multi_Tabs_4 cout << "\tTo Play Again in 'Same Level' &   Same   'First Move'  :  Press- <Space> KEY \n";
    Multi_Tabs_4 cout << "\tTo Play Again in 'Same Level' & Opposite 'First Move'  :  Press- <Enter>\n";
    Multi_Tabs_4 cout << "\tTo Goto Main Menu                                      :  Press- <HOME> KEY\n";

    while(true)
    {
        this_thread::sleep_for(chrono::milliseconds(Time_Delay));
        if (kbhit())           //Control by arrow KEY
        {
            KEY = _getch();      Key_Hit_Maintainor();

//            if    (KEY>='0' && KEY<='4')                 {a= KEY;   break;}
            if    (KEY=='x' || KEY=='X' || KEY==71 || KEY==79 )      {a= '0';   break;}
            if    (KEY == 32)                            {a= '3';   break;}
            if    (KEY == 13)                            {a= '4';   break;}
            if    (KEY == 8 )                            {a= '2';   break;}
            if    (KEY == 27)                            {a= '1';   break;}

        }
    }

    system("cls");
    return a;
}

bool is_Team_named = false;
bool is_over_Wick_Selected = false;
bool is_Tossing = false;

string Team_1, Team_2;        //Team 2 tir nam
int Over_Total, Wicket_Total;
int win= 0, lost= 0, draw= 0;

char Dicission_cricket (char a)
{
    NewLine
    Multi_Tabs_4 cout << "To Play Again in  'Different Team'    &   'Different Over-Wicket'                         :  Press-'q'\n";
    Multi_Tabs_4 cout << "To Play Again in  '   Same   Team'    &   'Different Over-Wicket'                         :  Press-'w'\n";
    Multi_Tabs_4 cout << "To Play Again in  '   Same   Team'    &   '   Same   Over-Wicket'   with     Tossing      :  Press-'e'\n";
    Multi_Tabs_4 cout << "To Play Again in  '   Same   Team'    &   '   Same   Over-Wicket'  without   Tossing      :  Press-'r'\n";

    Multi_Tabs_4 cout << "To Goto Main Menu                                                                         :  Press-'x'\n";

    while(true)
    {
        this_thread::sleep_for(chrono::milliseconds(Time_Delay));
        if (kbhit())           //Control by arrow KEY
        {
            KEY = _getch();
            KEY = tolower(KEY);

            if    (KEY== 'q' || KEY=='!' )               {a= '1';   break;}
            if    (KEY== 'w' || KEY=='@' )               {a= '2';   break;}
            if    (KEY== 'e' || KEY=='#' )               {a= '3';   break;}
            if    (KEY== 'r' || KEY=='$' )               {a= '4';   break;}

            if    (KEY=='x' || KEY== 71 || KEY== 79 )     {a= '0';   break;}
            Key_Hit_Maintainor();

        }
    }

    system("cls");
    return a;
}

char Dicission_in_Mini_Games  (char a)
{
    NewLine
    Multi_Tabs_3 cout << "\tTo Play Again,               Press- <Space>\n";
    Multi_Tabs_3 cout << "\tTo Play Another  Mini GAME , Press- <Enter>\n";
    Multi_Tabs_3 cout << "\tTo Goto MENU,                Press- <Home>\n";

    while(true)
    {
        this_thread::sleep_for(chrono::milliseconds(Time_Delay));

        if (kbhit())           //Control by arrow KEY
        {
            KEY = _getch();      Key_Hit_Maintainor();

//            if    (KEY>='0' && KEY<='3') {a= KEY; break;}
            if    (KEY=='x' || KEY == 71 || KEY==79  )   {a= '0';   break;}
            if    (KEY==77 || KEY==80  || KEY == 13  )   {a= '2';   break;}
            if    (KEY==' '  )                           {a= '1';   break;}
            if    (KEY==72 || KEY == 75  )               {a= '1';   break;}

        }
    }

    NewLine NewLine NewLine
    system("cls");
    return a;
}

int Snake_Fruit_position_Declaration_Function  (int Return_Fruit) //Decited Fruit possition in Snake Game
{
    Return_Fruit= rand() % ( Snake_Area_Row * Snake_Area_Column );
    return Return_Fruit;
}

int Tic_Tac_Toe_Position_Genaration_Function (int Return_Tic_Tac_Toe_Random_Possition)                  //Decited Computer's Chose Index in Tic Tac Toe Game
{
    Return_Tic_Tac_Toe_Random_Possition = 1 + rand() % 9;
    return Return_Tic_Tac_Toe_Random_Possition;
}

void Tic_Tac_Toe_Index_Instructior_Function()
{
    NewLine
    Multi_Tabs_1   NewLine
    Multi_Tabs_1  cout << " 1 | 2 | 3 ";  NewLine
    Multi_Tabs_1  cout << "___|___|___";  NewLine
    Multi_Tabs_1  cout << " 4 | 5 | 6 ";  NewLine
    Multi_Tabs_1  cout << "___|___|___";  NewLine
    Multi_Tabs_1  cout << " 7 | 8 | 9 ";  NewLine
    Multi_Tabs_1  cout << "   |   |   ";  NewLine
    Multi_Tabs_1   NewLine NewLine

    Sound
    Multi_Tabs_1  NewLine                       //Index Border Degign
    Multi_Tabs_1
}

void Show_Main_Menu()
{
    hideCursor();  // cursor lukano
    if(KEY!=80 && KEY!=72) system("cls"); //All Previous Print Erased
    else                   gotoxy(0,0);

    if(is_Premium) Markered_Symbol = char(251);
    else           Markered_Symbol = char(251);

    if(is_Premium) Design_Symbol = char(2);
    else           Design_Symbol = '*';

    Multi_Tabs_1 cout << Design_Symbol << " WELCOME TO YOU IN GAME ERA "<< Design_Symbol;     for(int i=0;i<3;i++) NewLine

    Multi_Tabs_3 if(Marker==1) cout<<Markered_Symbol; else cout<<char(32); printf(" Press 1 :   to Enter                    SNAKE  ERA \n");
    Multi_Tabs_3 if(Marker==2) cout<<Markered_Symbol; else cout<<char(32); printf(" Press 2 :   to Enter                    PACMAN ERA \n\n");

    Multi_Tabs_3 if(Marker==3) cout<<Markered_Symbol; else cout<<char(32); printf(" Press 3 :   to Enter   TIC TAC TOE ERA (MAN VS COM)\n");
    Multi_Tabs_3 if(Marker==4) cout<<Markered_Symbol; else cout<<char(32); printf(" Press 4 :   to Enter   TIC TAC TOE ERA (MAN VS MAN)\n\n");

    Multi_Tabs_3 if(Marker==5) cout<<Markered_Symbol; else cout<<char(32); printf(" Press 5 :   to Enter          SNAKE-LADDER-LUDO ERA\n");
    Multi_Tabs_3 if(Marker==6) cout<<Markered_Symbol; else cout<<char(32); printf(" Press 6 :   to Enter                     SUDOKU ERA\n\n");

    Multi_Tabs_3 if(Marker==7) cout<<Markered_Symbol; else cout<<char(32); printf(" Press 7 :   to Enter                    CRICKET ERA\n");
    Multi_Tabs_3 if(Marker==8) cout<<Markered_Symbol; else cout<<char(32); printf(" Press 8 :   to Enter                 Mini GAMES ERA\n\n");

//    Multi_Tabs_3                                           cout<<char(32); printf(" Press (' \" ] } ),       to Change Text & BG Colour\n");                //Instruction end
    Multi_Tabs_3                                           cout<<char(32); printf(" Press ? :                to See    More Instruction\n");
    Multi_Tabs_3                                           cout<<char(32); printf(" Press X :                to CLOSE       THE PROGRAM\n\n");

    NewLine NewLine

}

int main()
{
  char Again,Kall;

  Menu:
    Show_Main_Menu();

    //Main_Menu_Controller
    while(true)
    {
        hideCursor();

        this_thread::sleep_for(chrono::milliseconds(Time_Delay));
        KeyHit_Cheak_Count++;   if (KEY=='!') cout<<"\r"<<KeyHit_Cheak_Count<<"                      ";

        if (kbhit())           //Control by arrow KEY
        {
            KEY = _getch();

            if      (KEY>='0' && KEY<='9') {Marker= KEY-'0'; break;}
            else if (KEY=='x' || KEY=='X' || KEY==79 ) {Marker=100; break;}

            else if (KEY==80 ) { Marker++; if(Marker>8) Marker=1; goto Menu; }
            else if (KEY==72 ) { Marker--; if(Marker<1) Marker=8; goto Menu; }

            else if (KEY=='p' && is_Premium == false) {is_Premium = true;  goto Menu;}
            else if (KEY=='p' && is_Premium == true ) {is_Premium = false; goto Menu; }

            else if (KEY=='?' || KEY=='/' ) {Instruction(); continue;}

            else if (KEY=='`')  {SoundFlag=false; cout<<"\rMuted";}
            else if (KEY=='~')  {SoundFlag= true; cout<<"\r\aUnmuted"; }

            else if (KEY=='<' || KEY==',' )  {TabNumber--; if(TabNumber<0) TabNumber=0; goto Menu;}
            else if (KEY=='>' || KEY=='.' )  {TabNumber++; goto Menu;}
            else if (KEY=='^')  {TabNumber=6; goto Menu;}

            else if (KEY=='\\'){ColorVar=0; SetConsoleColor(BrightWhite);         goto Menu;}
            else if (KEY=='|') {ColorVar=0; SetConsoleColour(Black,BrightWhite);  goto Menu;}

            else if (KEY=='\'' )  { changeTextColour();   goto Menu;}
            else if (KEY==';' )   { ColorVar -=2; changeTextColour();   goto Menu;}
            else if (KEY=='"' )   { changeTextColour2();  goto Menu;}
            else if (KEY==':' )   { ColorVar -=2; changeTextColour2();  goto Menu;}

            else if (KEY=='}')  { changeBgColour();   goto Menu;}
            else if (KEY==']')  { changeBgColour2();  goto Menu;}
            else if (KEY=='{')  { ColorVar -=2; changeBgColour();   goto Menu;}
            else if (KEY=='[')  { ColorVar -=2; changeBgColour2();  goto Menu;}

            else if (KEY=='!') ;
            else if(KEY=='@' ){ cout<<"\r"<<Coder_Name;  }

            else if(KEY==8 || KEY==75 || KEY==71 || KEY==32)   goto Menu;
            else if ( KEY==13 || KEY==77 )   break;

            else if(KEY=='+' || KEY=='=') {Time_Delay++; if(Time_Delay>100) Time_Delay=91; if(Time_Delay>10) Time_Delay+=9; cout<<"\rPolling_Delay(ms): "<<Time_Delay<<"                          ";}
            else if(KEY=='-' || KEY=='_') {Time_Delay--; if(Time_Delay<0  ) Time_Delay=0;  if(Time_Delay>10) Time_Delay-=9; cout<<"\rPolling_Delay(ms): "<<Time_Delay<<"                          ";}

//            else if (KEY=='g' && is_Continuous_Change_Color==false) is_Continuous_Change_Color=true;
//            else if (KEY=='g' && is_Continuous_Change_Color==true) is_Continuous_Change_Color= false;

            else if(KEY>=65 && KEY <=90            )   DisplayWorldView();
            else if(KEY>=97 && KEY <=122           )   DisplayWorldView();
            else if(KEY>=32 && KEY <=126 && KEY!=75)   DisplayWorldView();

            else ;

        }
    }

    system("cls");

    switch (Marker){

        case 1:     //SNAKE

          Snake_Menu:

            system("cls");
            int Snake_Marker;

            Multi_Tabs_3 printf("            $ WELCOME TO SNAKE ERA $\n\n");

            Multi_Tabs_3 printf(" Press --> 1 :    to Play              CLASSIC SNAKE GAME\n");
            Multi_Tabs_3 printf(" Press --> 2 :    to Play      NO-END  CLASSIC SNAKE GAME\n");
            Multi_Tabs_3 printf(" Press --> 3 :    to Play                  BOX SNAKE GAME\n");
            Multi_Tabs_3 printf(" Press --> 4 :    to Play      NO-SELF-HIT BOX SNAKE GAME\n\n");

            Multi_Tabs_3 printf(" Press --> 5 :    to see             AI CLASSIC SNAKE GAME\n");
            Multi_Tabs_3 printf(" Press --> 6 :    to see     NO-END  AI CLASSIC SNAKE GAME\n");
            Multi_Tabs_3 printf(" Press --> 7 :    to see                 AI BOX SNAKE GAME\n");
            Multi_Tabs_3 printf(" Press --> 8 :    to see     NO-SELF-HIT AI BOX SNAKE GAME \n\n");

            Multi_Tabs_3 printf(" Press --> 9 :    to see   SAFE-MOVE AI CLASSIC SNAKE GAME\n");
            Multi_Tabs_3 printf(" Press --> 0 :    to see   SAFE-MOVE AI   BOX   SNAKE GAME\n\n");

            Multi_Tabs_3 printf(" Press --> S :    to                  Customize Snake Area\n");
            Multi_Tabs_3 printf(" Press --> ? :    to                      see Instructions\n\n");

            Multi_Tabs_3 printf(" Press --> X :    to                       Go to Main Menu\n");

            while(true)
            {
                hideCursor();
                this_thread::sleep_for(chrono::milliseconds(Time_Delay));

                if (kbhit())           //Control by arrow KEY
                {
                    KEY = _getch();

                    Snake_Marker = KEY - '0';

                    if (Snake_Marker == 0)                             {if(Snake_Area_Column%2!=0) Snake_Area_Column++; if(Snake_Area_Row==1) Snake_Area_Row++; break;}
                    if (Snake_Marker >= 0 && Snake_Marker <= 9  )       break;
                    if (KEY=='x' || KEY=='X' || KEY==75 || KEY==71 || KEY==79 )     goto Menu;

                    Key_Hit_Maintainor();

                    if(KEY=='s')
                    {
                        system("cls"); Multi_Tabs_1 printf("     WELCOME TO SNAKE ERA\n\n");

                        Multi_Tabs_1 cout<<"Snake_Game_Settings\n\n";
                        cout<<"Enter Area Height (Enter a Intiger Number from 1 to 20) \t:\t ";
                        cin>> Snake_Area_Row; if(Snake_Area_Row<1) Snake_Area_Row=1;  if(Snake_Area_Row>20) Snake_Area_Row=20;

                        cout<<"Enter Area Weight (Enter a Intiger Number from 4 to 40) \t:\t ";
                        cin>> Snake_Area_Column; if(Snake_Area_Column<4) Snake_Area_Column=4;  if(Snake_Area_Column>40) Snake_Area_Column=40;

                        goto Snake_Menu;
                    }

                    if(KEY=='/'|| KEY=='?')
                    {
                             Instruction();
                             Snake_Instruction();
                             goto Snake_Menu;
                    }

                }
            }
            system("cls");

            while(true)
            {
                Multi_Tabs_1      printf("  $ WELCOME TO SNAKE ERA $\n\n");

                if(Snake_Marker==1)
                {
                    Multi_Tabs_1 cout << "    SNAKE GAME [Classic]\n\n";
                    cout<<"#Instruction : Here your target is eat more Fruit to Increase Score. The Snake's Size is increasing according to eat Fruit. If the Snake Bites its Body then the Game is Over. You should Control the Snake by using Arrow KEY\n\n";
                }

                if(Snake_Marker==2)
                {
                    Multi_Tabs_1 cout << "  SNAKE GAME [Classic-No-End]\n\n";
                    cout<<"#Instruction : Here your target is eat more Fruit to Increase Score. The Snake's Size is increasing according to eat Fruit. To Close the game Press - 'x' or 'end' Key. You should Control the Snake by using Arrow KEY\n\n";
                }

                if(Snake_Marker==3)
                {
                    Multi_Tabs_1 cout << "      SNAKE GAME [Box]\n\n";
                    cout<<"#Instruction : Here your target is eat more Fruit to Increase Score. The Snake's Size is increasing according to eat Fruit. If the Snake Bites its Body or Border then the Game is Over.\
                     You should use Arrow KEYs to control the Snake.\n\n";
                }

                if(Snake_Marker==4)
                {
                    Multi_Tabs_1 cout << "  SNAKE GAME [Box-No-Self-Hit]\n\n";
                    cout<<"#Instruction : Here your target is eat more Fruit to Increase Score. The Snake's Size is increasing according to eat Fruit. If the Snake Bites Border then the Game is Over.\
                    You should use Arrow KEYs to control the Snake.\n\n";
                }

                if(Snake_Marker==5) {Multi_Tabs_1 cout << "       AI SNAKE GAME [CLASSIC]    \n\n";}
                if(Snake_Marker==6) {Multi_Tabs_1 cout << "    AI SNAKE GAME [CLASSIC-NO-END]\n\n";}
                if(Snake_Marker==7) {Multi_Tabs_1 cout << "          AI SNAKE GAME [BOX]     \n\n";}
                if(Snake_Marker==8) {Multi_Tabs_1 cout << "  AI SNAKE GAME [BOX-N0-SELF-BITE]\n\n";}

                if(Snake_Marker==9) {Multi_Tabs_1 cout << "     AI SAFE SNAKE GAME [CLASSIC]  \n\n";}
                if(Snake_Marker==0) {Multi_Tabs_1 cout << "       AI_SAFE_ SNAKE GAME [BOX]   \n\n";}

                int Level;
                bool DoubleSnake = false, Ultra_Premium_Protector = false;
                Multi_Tabs_1 cout<< "        SPEED (1-8) :  ";

                while(true)
                {
                    this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                    if (kbhit())           //Control by arrow KEY
                    {
                        KEY = _getch();      Key_Hit_Maintainor();

                        if    (KEY>='1' && KEY<='8') {Level= KEY-'0'; break;}
                        if    (KEY==75 || KEY==71)  goto Snake_Menu;
                        if    (KEY==79 || KEY=='x') goto Menu;
                    }
                }

                int Delay = 0;

                while(1)
                {
                    system("cls");

                    is_Playing = true;
                    bool Finish=false, Is_Completed=false, is_Fruit_in_Blank_Space = true, BonusFlag=false;
                    int Fruit, Bonus=Snake_Area_Row * Snake_Area_Column, Score = 0,Point= 0, Call=0,Change=0,i,FruitCount=0, BonusCount=0, Step = 0, Bonus_Life_Var=0;
                    int Snake_Head= ( Snake_Area_Row /2)* Snake_Area_Column  +  Snake_Area_Column /2; //0-based: 0 to row*col-1
                    int Snake_Body[ Snake_Area_Row * Snake_Area_Column +5];
                    fill(Snake_Body, Snake_Body + Snake_Area_Row * Snake_Area_Column + 5, Snake_Area_Row * Snake_Area_Column); //sentinel = row*col (display range er baire)
                    char Move='6';
                    char PlayGround[ Snake_Area_Row * Snake_Area_Column +6]; //0-99,NULL+Primary body Size(4)+Extra some for avoid silly risk

                    Fruit  =  Snake_Fruit_position_Declaration_Function (Call);

                    //First Declaration of Snake Body (below)
                    Snake_Body[1]  =  Snake_Head -1;
                    Snake_Body[2]  =  Snake_Head -2;
                    Snake_Body[3]  =  Snake_Head -3;

                    while(1)
                    {
                        hideCursor();
                        gotoxy(0,0);

                        while(1)                  //jate Fruit snake er body borabor na ase
                        {
                            Change++;
                            for(i = 3+Score; i>0; i--)
                            {
                                if(Fruit == Snake_Body[i]) {is_Fruit_in_Blank_Space = false;  break; }
                            }
                            if((is_Fruit_in_Blank_Space == false || Fruit == Snake_Head) && Change <= Snake_Area_Row * Snake_Area_Column  ) //Chnge variable ta NewLinear karon holo jodi snake body r size full arear soman hoy orthat fruit dewar moto kono jayga na thake tahole snake body borabor porbe , eta na dile oi muhurte program continiously choltei thakto, susthu vabe game complete hoto na
                            {
                                is_Fruit_in_Blank_Space = true;
                                Fruit++;
                                Fruit = Fruit % (Snake_Area_Row * Snake_Area_Column); //jate row*col overtek na kore (0-based)
                            }

                            else break;
                        }

                        Change=0;

                        while(1)                  //jate Bonus snake er body borabor na ase
                        {
                            if(BonusFlag==false) break;
                            Change++;
                            for(i = 3+Score; i>0; i--)
                            {
                                if(Bonus == Snake_Body[i]) {is_Fruit_in_Blank_Space = false;  break; }
                            }
                            if((is_Fruit_in_Blank_Space == false || Bonus == Snake_Head) && Change <= Snake_Area_Row * Snake_Area_Column  ) //Chnge variable ta NewLinear karon holo jodi snake body r size full arear soman hoy orthat fruit dewar moto kono jayga na thake tahole snake body borabor porbe , eta na dile oi muhurte program continiously choltei thakto, susthu vabe game complete hoto na
                            {
                                is_Fruit_in_Blank_Space = true;
                                Bonus++;
                                Bonus = Bonus % (Snake_Area_Row * Snake_Area_Column); //jate row*col overtek na kore (0-based)
                            }

                            else break;
                        }

                        Change=0;

                        for(i = 0; i <  Snake_Area_Row * Snake_Area_Column ; i++)
                        {
                            PlayGround [i] = ' ' ;
                        }

                        if(is_Premium && !Ultra_Premium_Protector)   PlayGround [Bonus] = 5  + Step%2;
                        else if(is_Premium)     PlayGround [Bonus] =  176 + Step%2;
                        else                    PlayGround [Bonus] = '$' - Step%2;

                        PlayGround [Fruit] = Step%2+42; //Fruit Symbol (*,+)

                        for(i = Score+3; i>0; i--)
                        {
                            if     (!is_Premium && !DoubleSnake)  PlayGround [Snake_Body[i]]  =  'o';
                            if     (!is_Premium &&  DoubleSnake)  PlayGround [Snake_Body[i]]  =  'O';

                            if     ( is_Premium && !DoubleSnake)  PlayGround [Snake_Body[i]]  =  254; //Snake Body Symbol
                            if     ( is_Premium &&  DoubleSnake)  PlayGround [Snake_Body[i]]  =  219; //Snake Body Symbol
                        }

                        if(is_Premium && !Ultra_Premium_Protector) PlayGround [Snake_Body[Score+3]] = 4;    //Snake Tail Symbol
                        else           PlayGround [Snake_Body[Score+3]] = '-';

                        if(is_Premium && !Ultra_Premium_Protector) PlayGround [Snake_Head] = 2;    //Snake Head Symbol (Ascii 2)
                        else           PlayGround [Snake_Head] = '@';


                                             Multi_Tabs_1  printf("     $ WELCOME TO SNAKE ERA $     \n\n");

                        if(Snake_Marker==1) {Multi_Tabs_1 cout << "       SNAKE GAME [CLASSIC]       \n\n";}
                        if(Snake_Marker==2) {Multi_Tabs_1 cout << "     SNAKE GAME [CLASSIC-NO-END]  \n\n";}
                        if(Snake_Marker==3) {Multi_Tabs_1 cout << "         SNAKE GAME [BOX]         \n\n";}
                        if(Snake_Marker==4) {Multi_Tabs_1 cout << "   SNAKE GAME [BOX-N0-SELF-BITE]  \n\n";}

                        if(Snake_Marker==5) {Multi_Tabs_1 cout << "      AI SNAKE GAME [CLASSIC]    \n\n";}
                        if(Snake_Marker==6) {Multi_Tabs_1 cout << "   AI SNAKE GAME [CLASSIC-NO-END]\n\n";}
                        if(Snake_Marker==7) {Multi_Tabs_1 cout << "         AI SNAKE GAME [BOX]     \n\n";}
                        if(Snake_Marker==8) {Multi_Tabs_1 cout << "  AI SNAKE GAME [BOX-N0-SELF-BITE]\n\n";}

                        if(Snake_Marker==9) {Multi_Tabs_1 cout << "     AI SAFE SNAKE GAME [CLASSIC]  \n\n";}
                        if(Snake_Marker==0) {Multi_Tabs_1 cout << "       AI_SAFE_ SNAKE GAME [BOX]   \n\n";}


                                             Multi_Tabs_1 cout << "             Level : "<<Level<<endl;

                        NewLine;NewLine;
                        Multi_Tabs_1;  Border_Sign;  Multiple_Border_Sign;  NewLine;  //Border
                        Multi_Tabs_1;  Border_Sign;

                        for(i = 0; i <  Snake_Area_Row * Snake_Area_Column ; i++)
                        {
                           /** changeTextColour(); */
                           if(!DoubleSnake) cout<<PlayGround [i]<<" ";           // show Update resulte of Game-PlayGround
                           if( DoubleSnake) cout<<PlayGround [i]<<PlayGround[i];           // show Update resulte of Game-PlayGround
                           if((i+1)% Snake_Area_Column  == 0) {Border_Sign;  NewLine;  Multi_Tabs_1;  Border_Sign;  }
                        }

                        Multiple_Border_Sign NewLine NewLine

                                             Multi_Tabs_1 cout<<"         ";    show_Point
                                             Multi_Tabs_1 cout<<"           Fruit Count : "<<FruitCount<<endl;
                                             Multi_Tabs_1 cout<<"           Bonus Count : "<<BonusCount<<endl;
                                             Multi_Tabs_1 cout<<"           Step        : "<<Step      <<endl;
                                             NewLine
                                             Multi_Tabs_1 cout<<"   To See Instructions : Press Slash Key "<<endl;


                        this_thread::sleep_for(chrono::milliseconds(Delay));    //Time Delay for Update Printing

                        if(Finish || Is_Completed)  break;//snake nijeke bite korle game over
                        if(Snake_Marker==3 || Snake_Marker==4 || Snake_Marker==7 || Snake_Marker==8 || Snake_Marker==0) if(Snake_Head >= Snake_Area_Row * Snake_Area_Column  || Snake_Head< 0 ) break;

                        Step++;

                        if (kbhit())           //Control by arrow KEY
                        {
                                KEY = _getch();
                            // Check for arrow KEY input
                                if(KEY==72 || KEY=='8' || KEY=='w' ) // Up arrow
                                    Move='8';

                                else if(KEY==80 || KEY=='2' || KEY=='s' )// Down arrow
                                    Move='2';

                                else if(KEY==75 || KEY=='4' || KEY=='a' ) // Left arrow
                                    Move='4';

                                else if(KEY==77 || KEY=='6' || KEY=='d') // Right arrow
                                    Move='6';

                                else if(KEY=='+' || KEY=='=') {Level++; if(Level==9) Level--;}
                                else if(KEY=='-' || KEY=='_') {Level--; if(Level==0) Level++;}

                                else if(KEY=='0' || KEY=='5' || KEY==32 )   getch();
                                else if(KEY==13  || KEY==8              )   system("cls");

                                else if(KEY=='/' || KEY=='?') {system("cls"); Instruction(); Snake_Instruction(); system("cls"); }

                                else if(KEY=='x'  )  break;

                                else if(DoubleSnake==true  && KEY=='o') DoubleSnake=false;
                                else if(DoubleSnake==false && KEY=='o') DoubleSnake=true;

                                else if(Ultra_Premium_Protector==true  && KEY=='i') Ultra_Premium_Protector=false;
                                else if(Ultra_Premium_Protector==false && KEY=='i') Ultra_Premium_Protector=true;

                                else { Key_Hit_Maintainor(); continue;}
                        }

                        if(Snake_Marker==5)
                        {
                            bool rp,rm,cp,cm;
                            rp=rm=cp=cm=true;

                            int total = Snake_Area_Row * Snake_Area_Column;

                            // Wrap-aware body collision check
                            int right_pos = (Snake_Head % Snake_Area_Column == Snake_Area_Column-1)
                                            ? (Snake_Head - Snake_Area_Column + 1) : (Snake_Head + 1);
                            int left_pos  = (Snake_Head % Snake_Area_Column == 0)
                                            ? (Snake_Head + Snake_Area_Column - 1) : (Snake_Head - 1);
                            int down_pos  = (Snake_Head + Snake_Area_Column) % total;
                            int up_pos    = (Snake_Head - Snake_Area_Column + total) % total;

                            for(i = 2+Score; i>0; i--)
                            {
                                if(right_pos == Snake_Body[i]) cp=false;
                                if(left_pos  == Snake_Body[i]) cm=false;
                                if(down_pos  == Snake_Body[i]) rp=false;
                                if(up_pos    == Snake_Body[i]) rm=false;
                            }

                            int S_Row = (Snake_Head) / Snake_Area_Column;
                            int S_Col = (Snake_Head) % Snake_Area_Column;

                            int F_Row = BonusFlag ? (Bonus) / Snake_Area_Column : (Fruit) / Snake_Area_Column;
                            int F_Col = BonusFlag ? (Bonus) % Snake_Area_Column : (Fruit) % Snake_Area_Column;

                            //  Wrap-aware shortest direction (Marker 7-এর মতোই, কিন্তু wrap সহ)
                            int dr = F_Row - S_Row;
                            int dc = F_Col - S_Col;

                            if (dr >  Snake_Area_Row/2)    dr -= Snake_Area_Row;
                            if (dr < -Snake_Area_Row/2)    dr += Snake_Area_Row;
                            if (dc >  Snake_Area_Column/2) dc -= Snake_Area_Column;
                            if (dc < -Snake_Area_Column/2) dc += Snake_Area_Column;

                            if      (dc > 0 && cp) Move = '6';
                            else if (dc < 0 && cm) Move = '4';
                            else if (dr > 0 && rp) Move = '2';
                            else if (dr < 0 && rm) Move = '8';

                            else if (cp) Move = '6';
                            else if (cm) Move = '4';
                            else if (rp) Move = '2';
                            else if (rm) Move = '8';

                            else /** Move='5';*/ {Finish = true; break;}
                        }

                        if(Snake_Marker==6)
                        {
                            int S_Row = (Snake_Head) / Snake_Area_Column;
                            int S_Col = (Snake_Head) % Snake_Area_Column;

                            int F_Row = BonusFlag ? (Bonus) / Snake_Area_Column : (Fruit) / Snake_Area_Column;
                            int F_Col = BonusFlag ? (Bonus) % Snake_Area_Column : (Fruit) % Snake_Area_Column;

                            // Wrap-aware shortest direction (Marker 8 এর মতো, কিন্তু wrap সহ)
                            int dr = F_Row - S_Row;
                            int dc = F_Col - S_Col;

                            if (dr >  Snake_Area_Row/2)    dr -= Snake_Area_Row;
                            if (dr < -Snake_Area_Row/2)    dr += Snake_Area_Row;
                            if (dc >  Snake_Area_Column/2) dc -= Snake_Area_Column;
                            if (dc < -Snake_Area_Column/2) dc += Snake_Area_Column;

                            if      (dr < 0) Move = '8';
                            else if (dr > 0) Move = '2';
                            else if (dc < 0) Move = '4';
                            else if (dc > 0) Move = '6';
                        }

                        if(Snake_Marker==7)
                        {
                            bool rp,rm,cp,cm;
                            rp=rm=cp=cm=true;

                            for(i = 2+Score; i>0; i--)
                            {
                                if(Snake_Head+1 == Snake_Body[i]) cp=false;
                                if(Snake_Head-1 == Snake_Body[i]) cm=false;
                                if(Snake_Head+ Snake_Area_Column == Snake_Body[i]) rp=false;
                                if(Snake_Head- Snake_Area_Column == Snake_Body[i]) rm=false;

                            }

                            int S_Row = (Snake_Head) / Snake_Area_Column;
                            int S_Col = (Snake_Head) % Snake_Area_Column; //if(S_Col==0) S_Col=10;

                            int F_Row = BonusFlag ?  (Bonus) / Snake_Area_Column : (Fruit) / Snake_Area_Column;
                            int F_Col = BonusFlag ?  (Bonus) % Snake_Area_Column : (Fruit) % Snake_Area_Column;

                            if      (S_Col < F_Col && cp && S_Col != Snake_Area_Column-1) Move = '6';  // একই row, Snake বামে → ডানে যাও
                            else if (S_Col > F_Col && cm && S_Col != 0               ) Move = '4';  // একই row, Snake ডানে → বামে যাও
                            else if (S_Row < F_Row && rp && S_Row != Snake_Area_Row-1) Move = '2';  // Snake উপরে → নিচে যাও
                            else if (S_Row > F_Row && rm && S_Row != 0               ) Move = '8';  // Snake নিচে → উপরে যাও

                            else if(cp && S_Col != Snake_Area_Column-1) Move = '6';
                            else if(cm && S_Col != 0               )    Move = '4';
                            else if(rp && S_Row != Snake_Area_Row-1)    Move = '2';
                            else if(rm && S_Row != 0               )    Move = '8';

                            else /** Move='5';*/ {Finish = true; break;}

                        }

                        if(Snake_Marker==8)
                        {
                            int S_Row = (Snake_Head) / Snake_Area_Column;
                            int S_Col = (Snake_Head) % Snake_Area_Column;

                            int F_Row = BonusFlag ?  (Bonus) / Snake_Area_Column : (Fruit) / Snake_Area_Column;
                            int F_Col = BonusFlag ?  (Bonus) % Snake_Area_Column : (Fruit) % Snake_Area_Column;

                            if      (S_Row > F_Row && S_Row != 0               ) Move = '8';  // Snake নিচে → উপরে যাও
                            else if (S_Row < F_Row && S_Row != Snake_Area_Row-1) Move = '2';  // Snake উপরে → নিচে যাও
                            else if (S_Col > F_Col && S_Col != 0               ) Move = '4';  // একই row, Snake ডানে → বামে যাও
                            else if (S_Col < F_Col && S_Col != Snake_Area_Column-1) Move = '6';  // একই row, Snake বামে → ডানে যাও
                        }

                        if(Snake_Marker==9)
                        {
                            int row = Snake_Area_Row;
                            int col = Snake_Area_Column;
                            int sh = Snake_Head;
                            short mv = Move - '0';

                            int srow = sh / col;
                            int scol = sh % col;


                            if (col % 2 == 0)
                            {
                                if(scol % 2 == 0) if(srow==row-1)  mv=6; else  mv=2;
                                else              if(srow==0)      mv=6; else  mv = 8;
                            }

                            else if(row % 2 == 0)
                            {
                                if(row%4==0 || row%4==1) // ei shorte snake row er initial head row = odd hobe
                                {
                                    if(srow%2==0)   if(scol==col-1) mv=2; else mv=6;
                                    else            if(scol==0)     mv=2; else mv=4;
                                }

                                else
                                {
                                    if(srow%2==0) if(scol==0)      mv=2;  else mv=4;
                                    else          if(scol==col-1)  mv=2;  else mv=6;
                                }
                            }

                            else
                            {
                                if     (scol == col-2) if(srow%2==0)   mv=6; else               mv=8;
                                else if(scol == col-1) if(srow==0)     mv=6; else if(srow%2==0) mv=8; else mv=4;
                                else if(scol%2==0)     if(srow==row-1) mv=6; else               mv=2;
                                else                   if(srow==0)     mv=6; else               mv=8;
                            }

                            Move = char(mv) + '0';

                        }

                        if(Snake_Marker==0)
                        {
                            int row = Snake_Area_Row;
                            int col = Snake_Area_Column;
                            int sh = Snake_Head;
                            short mv = Move - '0';

                            int srow = sh / col;
                            int scol = sh % col;


                            if (srow == 0)
                            {
                                if(scol == 0)    mv=2;
                                else             mv=4;
                            }

                            else if(scol % 2 == 0)
                            {
                                    if(srow==row-1)  mv=6;
                                    else             mv=2;
                            }

                            else
                            {
                                if     (srow==1)  {if(scol==col-1) mv=8; else     mv=6;}
                                else              mv=8;
                            }

                            Move = char(mv) + '0';

                        }

                         if(Level==1) Delay=500;
                         if(Level==2) Delay=300;
                         if(Level==3) Delay=200;
                         if(Level==4) Delay=100;
                         if(Level==5) Delay=50;
                         if(Level==6) Delay=25;
                         if(Level==7) Delay=10;
                         if(Level==8) Delay=0;


                        for(i = 3+Score; i>0; i--)
                        {
                            Snake_Body[i] =  Snake_Body[i-1];  //Snake er body possition update
                        }
                        Snake_Body[1] =  Snake_Head;

                        if(Snake_Marker==1 || Snake_Marker==2 || Snake_Marker==5 || Snake_Marker==6 || Snake_Marker==9)
                        {
                            //to move to up / down / left / right (below) - (According to KEY-board Numarical Pads)
                            if(Move == '6') {Snake_Head++;     /** to move Right */  if(Snake_Head% Snake_Area_Column  == 0) Snake_Head -=  Snake_Area_Column ; /**Dan dike ber hoye gele oi borabor Bam dik diye asbe */ }
                            if(Move == '4') {Snake_Head--;     /** to move Left  */  if(Snake_Head < 0 || Snake_Head% Snake_Area_Column  == Snake_Area_Column-1) Snake_Head +=  Snake_Area_Column ; /**Bam dike ber hoye gele oi borabor Dan dik diye asbe */}
                            if(Move == '2') {Snake_Head +=  Snake_Area_Column ; /** to move Down  */   }
                            if(Move == '8') {Snake_Head -=  Snake_Area_Column ; /** to move Up    */   }

                            if(Snake_Head >= Snake_Area_Row * Snake_Area_Column ) Snake_Head -=  Snake_Area_Row * Snake_Area_Column ; //box er ekdik diye snake ber hoye gele, oi borabor biporit dik theke snake fire asbe.
                            if(Snake_Head <   0                                 ) Snake_Head +=  Snake_Area_Row * Snake_Area_Column ; // " " "

                        }

                        if(Snake_Marker==3 || Snake_Marker==4 || Snake_Marker==7 || Snake_Marker==8 || Snake_Marker==0)
                        {
                            if(Move== '6') {Snake_Head++;      if(Snake_Head% Snake_Area_Column == 0)                        { Snake_Head= -1; continue; }}      //Box e touch lagle Game over
                            if(Move== '4') {Snake_Head--;      if(Snake_Head < 0 || (Snake_Head+1)% Snake_Area_Column == 0)  { Snake_Head= -1; continue; }}      // " " "
                            if(Move== '8') {Snake_Head -=  Snake_Area_Column ;    }
                            if(Move== '2') {Snake_Head +=  Snake_Area_Column ;    }

                            if(Snake_Head >= Snake_Area_Row * Snake_Area_Column ) continue;  //Box e touch lagle Game over
                            if(Snake_Head <   0) continue;  // " " "
                        }


                        for(i = 3+Score; i>0; i--)
                        {
                            if(Snake_Head == Snake_Body[i]) { if(Snake_Marker==1 || Snake_Marker==3 || Snake_Marker==9) {Finish = true;} continue; } //jodi Snake nijeke Bite kore, then game over
                        }

                        if(Snake_Head == Fruit)         //Snake Fruit eat korar sathe sathe -
                        {
                            Score++;
                            Point++;
                            FruitCount++;
                            Sound
                            if(Score%5==0 && Score!=0) {BonusFlag=true; Bonus_Life_Var= 0; Bonus = Snake_Fruit_position_Declaration_Function (Call); Sound;}                     //-Sound hobe
                            Fruit =  Snake_Fruit_position_Declaration_Function (Call);     // -fruit er possition change hobe
                        }

                        if(BonusFlag)   Bonus_Life_Var++;
                        if(Bonus_Life_Var>5+ Snake_Area_Row + Snake_Area_Column ) {Bonus=Snake_Area_Row * Snake_Area_Column; BonusFlag=false;}

                        if(Snake_Head == Bonus)         //Snake Bonus eat korar sathe sathe -
                        {
                            Sound
                            Point += 2*((10+Snake_Area_Row+ Snake_Area_Column )-Bonus_Life_Var);
                            Bonus = Snake_Area_Row * Snake_Area_Column;
                            BonusFlag=false;
                            BonusCount++;
                        }

                        if(Score >= Snake_Area_Row * Snake_Area_Column -3)
                        {
                            Is_Completed = true;
                        }
                    }

                    is_Playing = false;
                    Sound;

                    if(Snake_Marker==3 || Snake_Marker==4)
                    {
                        if  (Finish)    { NewLine NewLine Multi_Tabs_1  cout << "       TOUCH BODY!";  }
                        else            { NewLine NewLine Multi_Tabs_1  cout << "       TOUCH BORDER!";}
                    }

                    if (!Is_Completed) {NewLine Multi_Tabs_1 cout<<"\t    Game Over!"<<endl;  NewLine}
                    else
                    {
                        NewLine NewLine
                        Multi_Tabs_1 cout<< "\tCongratulation!\n";
                        Multi_Tabs_1 cout<<"\tLevel Complete!";
                        NewLine NewLine
                    }

                    Again = Dicission_in_Snake_And_Pac_Game  (Kall);
                    if      (Again== '3') continue;
                    else if (Again== '2') break;
                    else if (Again== '1') goto Snake_Menu;
                    else                  goto Menu;

                }
            }
            break;

     case 2:

          PacMan_Menu:

            system("cls");
            int Pac_Marker;

            Multi_Tabs_3 printf("          WELCOME TO PAAMAN ERA\n\n");
            Multi_Tabs_3 printf(" Press --> 1 :   to Play      PACMAN in EASY MODE\n");
            Multi_Tabs_3 printf(" Press --> 2 :   to Play      PACMAN in HARD MODE\n\n");

//            Multi_Tabs_3 printf(" Press --> 8 :   to          Customize PacMan Area\n");
            Multi_Tabs_3 printf(" Press --> 9 :   to               see Instructions\n");
            Multi_Tabs_3 printf(" Press --> 0 :   to                Go to Main Menu\n");

            while(true)
            {
                hideCursor();
                this_thread::sleep_for(chrono::milliseconds(Time_Delay));

                if (kbhit())           //Control by arrow KEY
                {
                    KEY = _getch();

                    Pac_Marker = KEY - '0';

                    if (Pac_Marker >= 1 && Pac_Marker <= 2  ) break;
                    if (KEY=='x' || KEY==75 || KEY=='0')  goto Menu;

                    if(Pac_Marker == 9)
                    {
                             Instruction();
                             cout << "\n#PacMan Instruction :\n Here Pacman's Target is Eat All Fruit in the Box and Save Himself from Ghost. Ghost is Always try to catch Pacman. If Ghost Catch Pacman then Pacman's Life will Decreased. Use Arrow KEYs for Moving. Pacman has 3 Life. If Pacman lost his all life then Game is over. If PacMan Eat all fruit in the Box then Level will be Completed.\n\n";

                             getch(); goto PacMan_Menu;
                    }

                    Key_Hit_Maintainor();

                }
            }
            system("cls");

            while(true)
            {
                Multi_Tabs_1 cout << "PACMAN GAME \n\n";
                cout << "#Instruction : Here Pacman's Target is Eat All Fruit in the Box and Save Himself from Ghost. Ghost is Always try to catch Pacman. If Ghost Catch Pacman then Pacman's Life will Decreased. Use Arrow KEYs for Moving. Pacman has 3 Life. If Pacman lost his all life then Game is over. If PacMan Eat all fruit in the Box then Level will be Completed.\n\n";

                int Level;
                cout<< "SPEED (1-8) :  ";
                while(true)
                {
                    this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                    if (kbhit())           //Control by arrow KEY
                    {
                        KEY = _getch();      Key_Hit_Maintainor();

                        if    (KEY>='1' && KEY<='8') {Level= KEY-'0'; break;}
                        if    (KEY=='x' || KEY==75)  goto Menu;

                    }
                }

                int Delay = 0 ;
    //            Delay = 450-50*Level; //Speed

                while(true)
                {
                    is_Playing = true;
                    bool Temp= true;
                    int Score = 0,i,j,x = 0,Number_of_Enemy=1, Life=3;
                    int PacMan,Enemy[Number_of_Enemy];
                    char Move;
                    char PlayGround[111],Fruit[111];                    /// Playground Size 10*10=100 (0-99) + extra 10(just for avoiding silly risk

                    for(i = 0; i < 100; i++)                            ///Initially sob gulo ghorei dot dekhabe
                    {
                        Fruit[i]=1;                                     ///'1' indicate korse oi possition a fruit ache
                    }

                pac_start:    ///if Pacman Lost his a Life then Program Start from here

                    if(Pac_Marker==1)
                    {
                       Number_of_Enemy=1;
                       PacMan,Enemy[Number_of_Enemy];
                       Enemy[0]=0;
                       PacMan = 99;
                    }

                    if(Pac_Marker==2)
                    {
                        Number_of_Enemy=4;
                        PacMan,Enemy[Number_of_Enemy];
                        Enemy[0]=0;
                        Enemy[1]=99;
                        Enemy[2]=9;
                        Enemy[3]=90;
                        PacMan = 45;
                    }
                                                     ///Pacman er initial possition
                    Temp=true;
                    system("cls");

                    while(true)                                        ///Protibar Move korar por Program ekhane chole asbe
                    {
                        hideCursor();
                        gotoxy(0,0);
                        /** changeTextColour(); */

                        for(i = 0; i < 100; i++)
                        {
                            PlayGround[i] = ' ';
                        }

                        for(i = 0; i < 100; i++)
                        {
                            if(Fruit[i] == 1) PlayGround[i] = '.';          ///jodi Fruit thake tobe Dot Sign dekhabe
                        }

                        if(is_Premium) PlayGround[PacMan] = 1;          ///PacMan Symbol (Smile face Black)
                        else           PlayGround[PacMan] ='O';

                        for(i=0;i<Number_of_Enemy;i++)
                        {
                            if(is_Premium) PlayGround[Enemy[i]] = 2;                   ///Enemy Symbol (Smile face White)
                            else           PlayGround[Enemy[i]] = 'X';
                        }

                        Multi_Tabs_1 cout << "PACMAN GAME \n\n";
                        Multi_Tabs_1 cout << " Level : "<<Level<<endl;

                        NewLine;NewLine;NewLine;NewLine;NewLine;NewLine;
                        Multi_Tabs_1;  Border_Sign;  Multiple_Border_Sign;  NewLine;  //Border
                        Multi_Tabs_1;  Border_Sign;

                        for(i = 0; i < 100; i++)
                        {
                        /** changeTextColour(); */
                           cout<<PlayGround[i]<<" ";                    ///Print PlayGround
                           if(i%10 == 9) {Border_Sign;  NewLine;  Multi_Tabs_1;  Border_Sign;  }  ///proti 10 ghor por por NewLine line asbe (jehutu Column 10 ta)
                        }

                        Multiple_Border_Sign NewLine NewLine

                        Multi_Tabs_1 showScore                  ///Show Current Score
                        Multi_Tabs_1 showLife                   ///Show Pacman remaining Life

                        this_thread::sleep_for(chrono::milliseconds(Delay));


                        if(Life == 0)       break;              ///Remaining Life '0' hole Game Over
                        if(Score == 100)    break;              ///Sob fruit gulo khele Game Over & Highest Score hobe
                        if(Temp == false)      goto pac_start;     ///jodi pacman er life kome jay, tobe sobar possition reform hobe

                        if (kbhit())
                        {
                            KEY = _getch();

                            // Check for arrow KEY input
                            if(KEY==72 || KEY=='8' || KEY=='w' )        Move='8';
                            else if(KEY==80 || KEY=='2' || KEY=='s' )   Move='2';
                            else if(KEY==75 || KEY=='4' || KEY=='a' )   Move='4';   // Left arrow
                            else if(KEY==77 || KEY=='6' || KEY=='d')    Move='6';   // Right arrow

                            else if(KEY==13)    system("cls");
                            else if(KEY=='0' || KEY=='5' || KEY==32) getch();

                            else if(KEY=='+' || KEY=='=') {Level++; if(Level==9)  Level--;}
                            else if(KEY=='-' || KEY=='_') {Level--; if(Level==0)  Level++;}

                            else if(KEY=='x'  )  break;

                            else {Key_Hit_Maintainor(); continue;}
                        }

                         if(Level==1) Delay=500;
                         if(Level==2) Delay=300;
                         if(Level==3) Delay=200;
                         if(Level==4) Delay=100;
                         if(Level==5) Delay=50;
                         if(Level==6) Delay=25;
                         if(Level==7) Delay=10;
                         if(Level==8) Delay=0;

                        for(i=0;i<Number_of_Enemy;i++)
                        {
                            if      (Enemy[i] /10 - PacMan/10 > 0) Enemy[i] -=10; ///Jodi Ghost er RowNumber Amar RowNumber theke BESHI hoy, tobe tar RowNumber Kombe & Amar Nikote asbe
                            else if (Enemy[i] /10 - PacMan/10 < 0) Enemy[i] +=10; ///Jodi Ghost er RowNumber Amar RowNumber theke KOM   hoy, tobe tar RowNumber Barbe & Amar Nikote asbe
                                                                                  ///R Same RowNumber hole No Change

                            if      (Enemy[i] %10 - PacMan%10 > 0) Enemy[i] --;   ///Jodi Ghost er Column Number Amar Column Number theke BESHI hoy,tobe tar Column Number Kombe & Amar Nikote asbe
                            else if (Enemy[i] %10 - PacMan%10 < 0) Enemy[i] ++;   ///Jodi Ghost er Column Number Amar Column Number theke  KOM  hoy,tobe tar Column Number Barbe & Amar Nikote asbe
                                                                                  ///R Same Column Number hole No Change

                        }

                        if(Move == '6') {PacMan++;        /** to move Right*/     if(PacMan%10 == 0)      PacMan --; /** Dont cross right border */  }
                        if(Move == '4') {PacMan--;        /** to move Left */     if((PacMan+20)%10 == 9) PacMan ++; /** Dont cross Left border */  } ///'-' Value Avoiding er jonno +20 dichi
                        if(Move == '2') {PacMan += 10; }  /**to move Down  */
                        if(Move == '8') {PacMan -= 10; }  /**to move Up    */

                        if(PacMan >= 100) PacMan -= 10; ///Don't cross Down-Border
                        if(PacMan <  0) PacMan += 10;   ///Don't cross Upper-Border

                        for(i=0; i<100; i++)
                        {
                            if(PacMan == i && Fruit[i] == 1)/// jodi Pacman er position-a fruit thake -
                            {
                                Score++;                    /// - tobe Score 1 barbe
                                Fruit[i]=0;                 /// & Fruit ta delete hoye jabe
                            }
                        }

                        for(i=0;i<Number_of_Enemy;i++)
                        {
                            if(PacMan == Enemy[i] )     /// jodi Ghost Pacman ke dhore felbe
                            {
                                Temp = false;
                                Life --;                /// -tobe Life kome jabe
                                Sound                   /// Sound hobe
                                break;
                            }
                        }
                    }

                    if(Life == 0)
                    {
                        Sound; NewLine Multi_Tabs_1
                        cout<<"\tGame Over!"; NewLine Multi_Tabs_1
                        cout<<"\tScore : "<<Score<<endl;  NewLine
                        is_Playing = false;
                    }

                    if(Score == 100)
                    {
                        Sound
                        Multi_Tabs_1 cout<< "\tCongratulation!\n";
                        Multi_Tabs_1 cout<<"\tLevel Complete!";          //100 is highest score , because there are 100 fruit in the ground
                        NewLine NewLine
                        is_Playing = false;
                    }

                    Again = Dicission_in_Snake_And_Pac_Game (Kall);
                    if      (Again== '3') continue;
                    else if (Again== '2') break;
                    else if (Again== '1') goto PacMan_Menu;
                    else                  goto Menu;
                }
            }
            break;


        case 3:     //Tic Tac Toe (Man vs Computer - 3 Different Mode)

            while(1)
            {

                Multi_Tabs_4 cout << "\t       TIC TAC TOE   \n\n";
                Multi_Tabs_4 cout << "\t    [Man vs Computer]\n\n";

                cout << "  Press --> 'Left-Arrow-KEY'  to goto 'Back'\n";
                cout << "  Press --> 'HOME' or 'END'   to      'Exit'\n";

                NewLine Multi_Tabs_1  cout << "Choice Level";
                NewLine Multi_Tabs_2 cout << "Easy / Medium / Hard";
                NewLine Multi_Tabs_3 cout << "   Press --> '1' / '2' / '3' : ";

                int Level;
                while(true)
                {
                    this_thread::sleep_for(chrono::milliseconds(Time_Delay));

                    if (kbhit())           //Control by arrow KEY
                    {
                        KEY = _getch();      Key_Hit_Maintainor();

                        if    (KEY>='1' && KEY<='3') {Level= KEY-'0'; break;}
                        if    (KEY == 'x' || KEY == 75 || KEY==71 || KEY==79) break;

                    }
                }

                if(KEY=='x' || KEY == 75 || KEY==71 || KEY==79 ) goto Menu;

                system("cls");

                Multi_Tabs_4 cout << "\t       TIC TAC TOE   \n\n";
                Multi_Tabs_4 cout << "\t    [Man vs Computer]\n\n";

                if      (Level<= 0) break; //if you want to close the game
                else if (Level== 1) {Multi_Tabs_1 cout << "EASY LEVEL\n"; }
                else if (Level== 2) {Multi_Tabs_1 cout << "MEDIUM LEVEL\n"; }
                else                {Multi_Tabs_1 cout << "HARD LEVEL\n"; }
                NewLine

                TTT_first_move:
                Multi_Tabs_2 cout << "    Who Play First?\n";
                Multi_Tabs_2 cout << "  ('You'/'Computer')\n\n";
                Multi_Tabs_2 cout << "  Press --> 'i' for    'You'   \n";
                Multi_Tabs_2 cout << "  Press --> 'c' for 'Computer' \n";
                Multi_Tabs_2 cout << "  Press --> 't' for 'Tossing'\n";
                Multi_Tabs_2 cout << "   (Without Quatation) :\n\n";

                cout << "  Press --> 'Left-Arrow-KEY'    to goto 'Back'\n";
                cout << "  Press -->  <HOME> or <END>    to      'Exit'\n";

                char who;
                while(true)
                {
                    this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                    if (kbhit())           //Control by arrow KEY
                    {
                        KEY = _getch();      Key_Hit_Maintainor();

                        if    (KEY=='i' || KEY=='c' || KEY == 't' ) {who=KEY; break;}
                        if    (KEY=='I' || KEY=='C' || KEY == 'T' ) {who=KEY; break;}
                        if    (KEY==75 || KEY == 77 || KEY == 'x' ) break;
                        if    (KEY==71 || KEY==79 || KEY=='X') goto Menu;
                    }
                }

                KEY= tolower(KEY);
                who=KEY;

                if(KEY=='i' || KEY=='c')    goto TTT_re;
                if(KEY=='k') {system("cls"); continue;}
                if(KEY=='m') who='t';
                if(KEY=='x') goto Menu;

                if(who == 't' )            //Tossing
                {
                    /* srand(time(NULL)); */
                    if(rand() %2== who %2 ) {NewLine Multi_Tabs_2 cout << "  You won the Toss\n" ; who= 'i'; }
                    else {NewLine Multi_Tabs_2 cout << "Computer won the Toss\n" ; who= 'c'; }
                }

                NewLine Multi_Tabs_3 cout<<"Press Any KEY to Start the Match\n";
                getch();

                TTT_re:
                system("cls");

                int i, Me= 0, Computer= 0, Time= 0, Win_I= 0, Win_Com= 0, Call, con=0;
                char  Index_Data[11]; //'who' uses for who play first & Index_Data[10] contains Data which Index fill up or Not
                char Index_Symbol[11];    //Box-Symbol string (show 'x', 'o', ' ')

                for(i=0; i<= 9; i++)
                {
                    Index_Data[i]= 0;
                }

                Print_Loop_Tic_Tac_Toe_Man_vs_Computer:             //Print_Update

                    gotoxy(0,0);

                    Multi_Tabs_4 cout << "\t       TIC TAC TOE   \n\n";
                    Multi_Tabs_4 cout << "\t    [Man vs Computer]\n\n";
                    if      (Level== 1) {Multi_Tabs_1 cout << "EASY LEVEL\n"; }
                    else if (Level== 2) {Multi_Tabs_1 cout << "MEDIUM LEVEL\n"; }
                    else                {Multi_Tabs_1 cout << "HARD LEVEL\n"; }
                    NewLine
                    for(iGlobal=0;iGlobal<TabNumber-2;iGlobal++) tab
                    cout << "[Every turn, Press a Number from 1 to 9 to Place Your Mark in the Corresponding Box.] " << endl << endl;

                    Index_Data[Me]= 1;
                    Index_Data[Computer]= 2;

                    for(i= 0; i<= 9; i++)
                    {
                        if(Index_Data[i]== 0) Index_Symbol[i]= ' ';     //Unfilled
                        if(Index_Data[i]== 1) Index_Symbol[i]= 'x';     //Filled by You
                        if(Index_Data[i]== 2) Index_Symbol[i]= 'o';     //Filled by Computer

                    }

                    Tic_Tac_Toe_Index_Instructior_Function();

                    for(i=1;i<=9;i++)  // Printing Loop
                    {
                       cout<<" "<<Index_Symbol[i];
                       if (i==9) {NewLine Multi_Tabs_1 cout<<"   |   |   \n"; NewLine NewLine}
                       else if(i%3 == 0 ) { NewLine Multi_Tabs_1  cout <<"___|___|___\n"; Multi_Tabs_1  }
                       else   cout<<" |";
                    }

                    NewLine

                    if(Time== 0 && who== 'c') goto Com;             //Computer er First chal hole
                    if(Time== 0) ;
                    else if(Time%2== 1 && who== 'c' || Time%2== 0 && who != 'c') goto Come_Back_2;     //Jor o bijor tomo chaler hiseb (Computer age chal dile bijor tomo chal gulo Computer er ar ami age chal dile jor tomo chal gulo Computer er)
                    else goto Come_Back_1;                                                              // " " "

                while(1)
                {
                    You:

                        while(true)
                        {
                            hideCursor();
                            this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                            if (kbhit())           //Control by arrow KEY
                            {
                                KEY = _getch();

                                if         (KEY>='1' && KEY<='9') {Me= KEY-'0'; Time++; break;}
                                else if    (KEY=='X' || KEY==79)  {goto Menu;}
                                else                              {Key_Hit_Maintainor(); system("cls"); goto Print_Loop_Tic_Tac_Toe_Man_vs_Computer;}
                            }
                        }

                        if(Index_Data[Me]  !=  0)   {Time--; goto You; }       //jodi ghor-tite already chal dewa hoye thake --> tobe accept hobe na, punoray chal dewa lagbe

                        Index_Data[Me]= 1; //Index-tate Amar chal input holo

                        goto Print_Loop_Tic_Tac_Toe_Man_vs_Computer;        //for printing update result

                        Come_Back_1:         //print kore punoray fire ase

                            if(Index_Data[1]== 1 && Index_Data[2]== 1 && Index_Data[3]== 1 || Index_Data[4]== 1 && Index_Data[5]== 1 && Index_Data[6]== 1 || Index_Data[7]== 1 && Index_Data[8]== 1 && Index_Data[9]== 1 || Index_Data[1]== 1 && Index_Data[4]== 1 && Index_Data[7]== 1 || Index_Data[2]== 1 && Index_Data[5]== 1 && Index_Data[8]== 1 || Index_Data[3]== 1 && Index_Data[6]== 1 && Index_Data[9]== 1 ||  Index_Data[3]== 1 && Index_Data[5]== 1 && Index_Data[7]== 1 || Index_Data[1]== 1 && Index_Data[5]== 1 && Index_Data[9]== 1 )
                            {
                                Win_I++;
                                break;              //Ami jitle game finished hobe
                            }
                        if(Time== 9) break;        //sob (9ta) ghor puron hole game finished

                    Com:

                        Time++;                     //kotobar chal dewa holo/ kotota Index puron holo, seta count kora hocche

                        if(Level== 1)                ///Easy mode : Computer sob chal randamly dibe
                        {
                            while(1)
                                {
                                    Computer= Tic_Tac_Toe_Position_Genaration_Function(Call);
                                    if(Index_Data[Computer]== 0 ) break;
                                }
                        }

                        else if(Level== 2)       ///Medium Level : kichuta buddhimotta apply korbe computer, but computer a bishesh koushole fade fele harano somvob
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
                                    Computer= Tic_Tac_Toe_Position_Genaration_Function(Call);
                                    if(Index_Data[Computer]== 0 ) break;
                                }
                            }
                        }

                        else            //Hard Level (Harano osomvob - hoy com. jiGlobale nahoy draw) - Medium er sathe aro kichu shorto add kora hoyeche jate com. ke fade feleo harano na jay)
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

                            //Some Extra-intelegence of Computer (below) <-- jate kono vabe fad e felano na jay
                            else if (Time== 1)
                            {
                               /* srand(time(NULL)); */
                               Computer= (2*(rand()%4))+1;
                               if(Computer== 5) Computer= 9;

                            }

                            else if(Time== 2 )
                            {
                                if(Index_Data [5]==0) Computer=5;
                                else                  Computer=(2*(rand()%5))+1;
                            }

                            else if (Time==3 && Index_Data [5]== 1)
                            {
                                if(Index_Data [1]== 2) Computer=9;
                                if(Index_Data [9]== 2) Computer=1;
                                if(Index_Data [3]== 2) Computer=7;
                                if(Index_Data [7]== 2) Computer=3;
                            }

                            else if (Time==3 )
                            {
                                if     (Index_Data [1]== 2 && (Index_Data [3]== 1 || Index_Data [7]== 1)) Computer=9;
                                else if(Index_Data [9]== 2 && (Index_Data [3]== 1 || Index_Data [7]== 1)) Computer=1;
                                else if(Index_Data [3]== 2 && (Index_Data [1]== 1 || Index_Data [9]== 1)) Computer=7;
                                else if(Index_Data [7]== 2 && (Index_Data [1]== 1 || Index_Data [9]== 1)) Computer=3;
                                else if(Index_Data [1]== 2 && Index_Data [9]== 1 )                        {Computer=3; con=7;}
                                else if(Index_Data [9]== 2 && Index_Data [1]== 1 )                        {Computer=7; con=3;}
                                else if(Index_Data [3]== 2 && Index_Data [7]== 1 )                        {Computer=9; con=1;}
                                else if(Index_Data [7]== 2 && Index_Data [3]== 1 )                        {Computer=1; con=9;}
                                else if(Index_Data [5]== 0)                                               Computer = 5;
                                else                                                                      Computer = ((rand()%5)*2)+1 ;

                            }


                            else if(Time== 4 && ( Index_Data [1]== 1 && Index_Data [9]== 1 && Index_Data [5]== 2 || Index_Data [3]== 1 && Index_Data [7]== 1 && Index_Data [5]== 2  ))
                            {
                                Computer = (1+rand()%4)*2;
                            }

                            else if(Time== 4)
                            {
                                if      (Index_Data [2]== 1 && Index_Data [8]== 1 )    Computer=6;
                                else if (Index_Data [4]== 1 && Index_Data [6]== 1 )    Computer=8;

                                else if (Index_Data [2]== 1 && Index_Data [6]== 1 )    Computer=3;
                                else if (Index_Data [2]== 1 && Index_Data [4]== 1 )    Computer=1;
                                else if (Index_Data [4]== 1 && Index_Data [8]== 1 )    Computer=7;
                                else if (Index_Data [6]== 1 && Index_Data [8]== 1 )    Computer=9;

                                else if (Index_Data [2]== 1 && Index_Data [9]== 1 || Index_Data [1]== 1 && Index_Data [6]== 1 )    Computer=3;
                                else if (Index_Data [2]== 1 && Index_Data [7]== 1 || Index_Data [3]== 1 && Index_Data [4]== 1 )    Computer=1;
                                else if (Index_Data [4]== 1 && Index_Data [9]== 1 || Index_Data [1]== 1 && Index_Data [8]== 1 )    Computer=7;
                                else if (Index_Data [6]== 1 && Index_Data [7]== 1 || Index_Data [3]== 1 && Index_Data [8]== 1 )    Computer=9;

                                else                                                                                               Computer=(2*(rand()%5))+1;

                            }

                            else if (Time==5)
                            {
                                if(con!=0) Computer=con;
                                else if  (Index_Data [1]== 2 && Index_Data [2]== 1 ) Computer=7;
                                else if  (Index_Data [1]== 2 && Index_Data [4]== 1 ) Computer=3;
                                else if  (Index_Data [3]== 2 && Index_Data [2]== 1 ) Computer=9;
                                else if  (Index_Data [3]== 2 && Index_Data [6]== 1 ) Computer=1;
                                else if  (Index_Data [7]== 2 && Index_Data [4]== 1 ) Computer=9;
                                else if  (Index_Data [7]== 2 && Index_Data [8]== 1 ) Computer=1;
                                else if  (Index_Data [9]== 2 && Index_Data [6]== 1 ) Computer=7;
                                else if  (Index_Data [9]== 2 && Index_Data [8]== 1 ) Computer=3;
                                else                                                 Computer = ((rand()%5)*2)+1;
                            }

                            else if (Time==6)
                            {
                                if      (Index_Data [2]== 1 && Index_Data [8]== 1 && Index_Data [4]== 1)    Computer=9;
                                else if (Index_Data [2]== 1 && Index_Data [4]== 1 && Index_Data [6]== 1)    Computer=7;
                                else if (Index_Data [4]== 0 && Index_Data [6]== 0 && Index_Data [5]== 2)    Computer=6;
                                else if (Index_Data [2]== 0 && Index_Data [8]== 0 && Index_Data [5]== 2)    Computer=8;
                                else                                                                        Computer=(2*(rand()%5))+1;

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
                                    Computer= Tic_Tac_Toe_Position_Genaration_Function(Call);
                                    if(Index_Data[Computer]== 0 ) break;
                                }
                            }

                        }


                        if (Index_Data[Computer]==0) Index_Data[Computer]= 2; //Input of Computer (computer er chal dewa)
                        else                         {Time--; goto Com;}      // jodi Computer kono Filled ghore chal dey tahole chal hobe na & Computer abar chalbe

                        goto Print_Loop_Tic_Tac_Toe_Man_vs_Computer;    //Print Update Result
                        Come_Back_2:                 //Come Back after printing

                        if(Index_Data[1]== 2 && Index_Data[2]== 2 && Index_Data[3]== 2 || Index_Data[4]== 2 && Index_Data[5]== 2 && Index_Data[6]== 2 || Index_Data[7]== 2 && Index_Data[8]== 2 && Index_Data[9]== 2 || Index_Data[1]== 2 && Index_Data[4]== 2 && Index_Data[7]== 2 || Index_Data[2]== 2 && Index_Data[5]== 2 && Index_Data[8]== 2 || Index_Data[3]== 2 && Index_Data[6]== 2 && Index_Data[9]== 2 ||  Index_Data[3]== 2 && Index_Data[5]== 2 && Index_Data[7]== 2 || Index_Data[1]== 2 && Index_Data[5]== 2 && Index_Data[9]== 2 )
                        {
                            Win_Com++;
                            break;           //Computer jitle-o game finished
                        }


                        if(Time== 9) break; //sob ghor puron hole-o game finished
                }

                NewLine Multi_Tabs_3

                Sound
                if         (Win_I   >   0)        cout << "Congratulation! You are Winner.\n";
                else if    (Win_Com >   0)        cout << "\t Sorry! You are Loser.\n";
                else                              cout << "\t\tMatch Drawn\n";

                Again = Dicission_TicTacToe (Kall);

                if      (Again=='1') continue;
                else if (Again=='2') goto TTT_first_move;
                else if (Again=='3' ) goto TTT_re;
                else if (Again=='4' )
                {
                     if(who=='i') who='c';
                     else if(who=='c') who='i';
                     goto TTT_re;
                }
                else                 goto Menu;
            }
            break;


        case 4:     //Tic Tac Toe (Man vs Man)

            while(1)
            {
                int  i, Player_1= 0, Player_2= 0, Time= 0, Win_1= 0, Win_2= 0;
                short Index_Data [10];
                char Index_Symbol [10];

                Multi_Tabs_1 cout << "TIC TAC TOE\n";
                Multi_Tabs_1 cout << "[Man vs Man]\n\n";


                //ke age chalbe Player '1' na '2' naki Toss
                Multi_Tabs_2 cout<<"  Who Play First?\n";
                Multi_Tabs_2 cout<<" ('Player-1'/'Player-2')\n\n";
                Multi_Tabs_2 cout << "  Press --> '1' for 'Player 1' \n";
                Multi_Tabs_2 cout << "  Press --> '2' for 'Player 2' \n";
                Multi_Tabs_2 cout << "  Press --> '0' for 'Tossing'\n";
                Multi_Tabs_2 cout << "  Press --> 'x' for 'Exit'\n";
                Multi_Tabs_2 cout << "   (Without Quatation) :\n\n";
                Multi_Tabs_1  cout<<"   ";

                char Who;
                while(true)
                {
                    if (kbhit())           //Control by arrow KEY
                    {
                        KEY = _getch();      Key_Hit_Maintainor();

                        if    (KEY=='1' || KEY=='2' || KEY == '0' || KEY=='x' || KEY == 75  ) { break;}


                    }
                }
                int who= KEY-'0';

                if(KEY == 'x' || KEY == 75 ) goto Menu;
                if(who==0 )
                {
                    /* srand(time(NULL)); */
                    if(rand() %2== who %2 ) {NewLine Multi_Tabs_2 cout << "Player-1 won the Toss\n" ; who= 1; }
                    else                    {NewLine Multi_Tabs_2 cout << "Player-2 won the Toss\n" ; who= 2; }

                    NewLine Multi_Tabs_3 cout<<"Press Any KEY to Start the Match\n";
                    getch();
                }

                system("cls");

                for(i= 0; i<= 9; i++)
                {
                    Index_Data[i]= 0;
                }

                Print_Loop_Tic_Tac_Toe_Man_vs_Man :   //Print_Loop

                    //system("cls");
                    gotoxy(0,0);

                    Index_Data[Player_1]= 1;
                    Index_Data[Player_2]= 2;

                    for(i= 0; i<= 9; i++)
                    {
                        if(Index_Data[i]== 0) Index_Symbol[i]= ' ';
                        if(Index_Data[i]== 1) Index_Symbol[i]= 'x';
                        if(Index_Data[i]== 2) Index_Symbol[i]= 'o';

                    }

                    Multi_Tabs_1 cout << "TIC TAC TOE\n";
                    Multi_Tabs_1 cout << "[Man vs Man]\n\n";
                    for(iGlobal=0;iGlobal<TabNumber-2;iGlobal++) tab
                    cout << "[Every turn, Press a Number from 1 to 9 to Place Your Mark in the Corresponding Box.] " << endl << endl;

                    Tic_Tac_Toe_Index_Instructior_Function();

                    for(i=1;i<=9;i++)
                    {
                       cout<<" "<<Index_Symbol[i];
                       if     (i   == 9 ) {NewLine Multi_Tabs_1  cout <<"   |   |   \n"; NewLine NewLine}
                       else if(i%3 == 0 ) {NewLine Multi_Tabs_1  cout <<"___|___|___\n"; Multi_Tabs_1      }
                       else   cout<<" |";
                    }

                    NewLine NewLine

                    hideCursor();

                    if(Time== 0 && who== 2) {Multi_Tabs_2 cout << "  Now Player-2 's Turn   "; goto Player_2_TicTacToe;}
                    if(Time== 0) ;
                    else if(Time%2== 1 && who== 2 || Time%2== 0 && who != 2) goto Back_2;
                    else goto Back_1;

                    while(1)
                    {

                        Multi_Tabs_2 cout << "  Now Player-1 's Turn   ";

                        Player_1_TicTacToe:

                            if (kbhit())           //Control by arrow KEY
                            {
                                this_thread::sleep_for(chrono::milliseconds(Time_Delay));

                                KEY = _getch();

                                if      (KEY>='1' && KEY<='9') {Player_1 = KEY-'0'; Time++;}
                                else if (KEY=='X' || KEY==79 )  goto Menu;
                                else                           { Key_Hit_Maintainor(); system("cls"); goto Print_Loop_Tic_Tac_Toe_Man_vs_Man ;}

                            }

                            else goto Player_1_TicTacToe;

                            if(Index_Data[Player_1] != 0)
                            {
//                                NewLine cout << "Already Exist\n\n";
                                Time--;
                                goto Player_1_TicTacToe;
                            }

                            Index_Data[Player_1]= 1;

                            goto Print_Loop_Tic_Tac_Toe_Man_vs_Man ;

                            Back_1:

                                if(Index_Data[1]== 1 && Index_Data[2]== 1 && Index_Data[3]== 1 || Index_Data[4]== 1 && Index_Data[5]== 1 && Index_Data[6]== 1 || Index_Data[7]== 1 && Index_Data[8]== 1 && Index_Data[9]== 1 || Index_Data[1]== 1 && Index_Data[4]== 1 && Index_Data[7]== 1 || Index_Data[2]== 1 && Index_Data[5]== 1 && Index_Data[8]== 1 || Index_Data[3]== 1 && Index_Data[6]== 1 && Index_Data[9]== 1 ||  Index_Data[3]== 1 && Index_Data[5]== 1 && Index_Data[7]== 1 || Index_Data[1]== 1 && Index_Data[5]== 1 && Index_Data[9]== 1 )
                                {
                                    Win_1++;
                                    break;
                                }
                            if(Time== 9) break;


                        Multi_Tabs_2 cout << "  Now Player-2 's Turn   ";
                        Player_2_TicTacToe://

                            if (kbhit())           //Control by arrow KEY
                            {
                                this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                                KEY = _getch();      Key_Hit_Maintainor();

                                if      (KEY>='1' && KEY<='9') {Player_2 = KEY-'0'; Time++;}
                                else if (KEY=='X' || KEY==79 )  goto Menu;
                                else                           { Key_Hit_Maintainor(); system("cls"); goto Print_Loop_Tic_Tac_Toe_Man_vs_Man ;}

                            }

                            else goto Player_2_TicTacToe;

                            if(Index_Data[Player_2] != 0)
                            {
//                                    NewLine cout << "Already Exist\n\n";
                                    Time--;
                                    goto Player_2_TicTacToe;
                            }

                            Index_Data[Player_1]= 2;

                            goto Print_Loop_Tic_Tac_Toe_Man_vs_Man ;

                            Back_2:

                            if(Index_Data[1]== 2 && Index_Data[2]== 2 && Index_Data[3]== 2 || Index_Data[4]== 2 && Index_Data[5]== 2 && Index_Data[6]== 2 || Index_Data[7]== 2 && Index_Data[8]== 2 && Index_Data[9]== 2 || Index_Data[1]== 2 && Index_Data[4]== 2 && Index_Data[7]== 2 || Index_Data[2]== 2 && Index_Data[5]== 2 && Index_Data[8]== 2 || Index_Data[3]== 2 && Index_Data[6]== 2 && Index_Data[9]== 2 ||  Index_Data[3]== 2 && Index_Data[5]== 2 && Index_Data[7]== 2 || Index_Data[1]== 2 && Index_Data[5]== 2 && Index_Data[9]== 2 )
                            {
                                Win_2++;
                                break;
                            }

                            if(Time== 9) break;

                    }

                Sound
                NewLine Multi_Tabs_3

                Sound
                if     (Win_1>0)    cout << "Congratulation! Player-1 is Winner.\n";
                else if(Win_2>0)    cout << "Congratulation! Player-2 is Winner.\n";
                else                cout << "\t\tMatch Drawn\n";

                Again = Dicission (Kall);
                if(Again!= '1') goto Menu;

            }

            break;

        case 5: //Ludo Snake-Ladder (vs Computer)

            Snake_Ladder_Ludo_Menu:

            system("cls");
            int Ludo_Marker;

            Multi_Tabs_3 printf("        WELCOME TO SNAKE-LADDER LUDO\n\n");
            Multi_Tabs_3 printf(" Press --> 1 :   to Play           MAN VS COMPUTER\n");
            Multi_Tabs_3 printf(" Press --> 2 :   to Play           MULTIPLE PLAYER\n\n");
            Multi_Tabs_3 printf(" Press --> 9 :   to               see Instructions\n");
            Multi_Tabs_3 printf(" Press --> 0 :   to                Go to Main Menu\n");

            while(true)
            {
                this_thread::sleep_for(chrono::milliseconds(Time_Delay));

                if (kbhit())           //Control by arrow KEY
                {
                    KEY = _getch();

                    Ludo_Marker = KEY - '0';

                    if (Ludo_Marker >= 1 && Ludo_Marker <= 2  ) break;
                    if (KEY=='x' || KEY==75 || KEY=='0')  goto Menu;


                    if(Ludo_Marker == 9)
                    {
                             cout<<"\nPress Any key to Hit the Dice. We get Any Value Randomly from 1 to 6. There are some Snakes & Ladder on Board. If You reached to 100, then You are Winner\n\n";
                             cout<<"Snakes : 97 --> 12 , 63 --> 3 , 70 --> 25, 32 --> 13, 60 --> 38, 89 --> 53, 73 --> 47, 82 --> 43 \n";
                             cout<<"Ladders : 8 --> 41, 50 --> 93, 55 --> 80, 59 --> 84, 6-->16, 26 --> 29\n\n";

                             getch(); goto Snake_Ladder_Ludo_Menu;
                    }

                    Key_Hit_Maintainor();
                }
            }
            system("cls");

            if(Ludo_Marker==1)
            {
                while(true)
                {
                    NewLine Multi_Tabs_1 cout << " LUDO SNAKE-LADDER GAME"; NewLine NewLine
                    cout<<"#Instruction : Here There are 2 Player (You & Computer) are playing. Both Target is to reach 100. Every Time You should Hit Dice & The Dice Give you Value from 1 to 6. Ladder Help us to Increase Your Possition & Snake Decrease Your Possition. The Player, Who reach to 100 first, He is Winner. To Hit Dice Press Any-KEY Everytime.\n\n\n";

                    int You= 0, Com= 0;
                    int Dice, i, temp= 0;
                    bool x= true;

                    NewLine Multi_Tabs_3 cout << "     Press -->      Any    KEY to  HIT  The DICE   ";
                    NewLine Multi_Tabs_3 cout << "     Press -->  Home/End/X KEY to CLOSE The GAME \n\n";

                    Sound

                    while(true)
                    {
                        KEY = _getch();
                        if (KEY=='x' || KEY=='X' || KEY==71 || KEY==79) goto Menu;

                        for(i= 1; i<= 2; i++)
                        {
                            /** changeTextColour(); */
                            //getch();
                            temp += 67;
                            temp= temp%100;
                            /* srand(time(NULL)); */

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
                               Multi_Tabs_3 cout << "Your Possition= " << You << "(+" << Dice << ")" << "\t";
                               if(You== 100)
                                    {
                                        Sound
                                        NewLine NewLine NewLine Multi_Tabs_1 cout << "\tCongratulation!";
                                        NewLine Multi_Tabs_1 cout << "\tYou are Winner.\n";
                                        x= false;
                                        break;
                                    }
                            }

                            if(i== 2)
                            {
                                Dice= (rand()/3/temp)%6; //jodi randam number 2 khetrei same ache tai vinno songkha dara vag dichi
                                Dice ++;
                                if(Com== 0 && Dice != 1) Com -= Dice; //'1' sara guti ber hobe na
                                Com += Dice;

                                //Snakes
                                if(Com== 97)Com= 12;
                                if(Com== 63)Com=  3;
                                if(Com== 70)Com= 25;
                                if(Com== 32)Com= 13;
                                if(Com== 60)Com= 38;
                                if(Com== 89)Com= 53;
                                if(Com== 73)Com= 47;
                                if(Com== 82)Com= 43;

                                //Laders
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
                                    NewLine NewLine NewLine Multi_Tabs_1 cout << "\t\tSorry";
                                    NewLine Multi_Tabs_1 cout << "\t  You are Loser\n";
                                    x= false;
                                    break;
                                }
                            }

                        }
                        if(x== false) break;
                        NewLine

                    }
                    x= true;
                    Again = Dicission (Kall);
                    if(Again!= '1') goto Menu;

                }
            }


            if(Ludo_Marker==2)
            {
                while(true)
                {
                    Sound
                    NewLine Multi_Tabs_1
                    cout << " LUDU SNAKE-LADDER GAME\n\n";
                    cout << "#Instruction : Here There are Multiple Players can Play. Atfirst you should Select the Number of Player. Then Press Any KEY to Hit the Dice. The Dice Gives you a Value from 1 to 6. Ladder Help you to Increase your Possitions & Snake Decrease your Possitions. Everyone's Target is to reach to 100. The Player Who reach to 100 First, He is Winner.\n\n";
                    //cout << "#Disclaimer: \t\tLudo is Haram Game for Muslim. So you should avoid to play this.\n\n";

                        int Number_of_Player;

                        Multi_Tabs_1 cout << "Number of Player :\t";
                        cin >> Number_of_Player;

                        if(Number_of_Player<= 0) goto Menu;
//                        if(Number_of_Player> 10) Number_of_Player=10;

                        NewLine Multi_Tabs_3 cout << "     Press -->      Any    KEY to  HIT  The DICE   ";
                        NewLine Multi_Tabs_3 cout << "     Press -->  Home/End/X KEY to CLOSE The GAME \n\n";
                        Sound

                        int Board[Number_of_Player+1]= {0}, Temp= 0;
                        int Dice, i;
                        bool x= true;

                        while(1)
                        {

                            for(i= 1; i<= Number_of_Player; i++)
                            {

                                KEY = _getch();
                                if (KEY=='x' || KEY=='X' || KEY==71 || KEY==79) goto Menu;
                                /** changeTextColour(); */
                                ///* srand(time(NULL)); */

                                    Dice= rand()%6; //just for different value of d in same time also, you can also change it differently but '%6' is must nedded
                                    Dice++; //(0-5)-->(1-6)
                                    if(Board[i]== 0 && Dice != 1) Board[i] -= Dice; //'1' chara guti ber hobe na
                                    Board[i] += Dice; //position update

                                    //Snakes
                                    if(Board[i]== 97)Board[i]= 12;
                                    if(Board[i]== 63)Board[i]= 3;
                                    if(Board[i]== 70)Board[i]= 25;
                                    if(Board[i]== 32)Board[i]= 13;
                                    if(Board[i]== 60)Board[i]= 38;
                                    if(Board[i]== 89)Board[i]= 53;
                                    if(Board[i]== 73)Board[i]= 47;
                                    if(Board[i]== 82)Board[i]= 43;


                                    //Ladders
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
                                            NewLine NewLine NewLine
                                            Multi_Tabs_1
                                            cout << " Congratulation!\n\t\t\t\t\t\tPlayer " << i << " is Winner\n\n\n";
                                            x= false;
                                            break;
                                        }


                            }
                            NewLine
                            if(x== false) break;

                        }

                    x= true;
                    Again = Dicission (Kall);
                    if(Again!= '1') goto Menu;
                }
            }
            break;

        case 6: //Sudoku (Fixed Given Value)

            while(true)
            {
                Multi_Tabs_1 cout << "\tSUDOKU GAME\n\n\n";
                cout<<"#Instruction : Here You should Fill Up All of the Blank Space Properly (According to Sudoku Rules).\n\n Here ('*' Sign Before Number) Indicates Current Index, ('`' sign After Number) indicates Your Filled Index. To Change Index Possition Press <Arrow Keys: Left/Right/Up/Down>,   To insert value into the Index: Select Index Possition, then input the value < From 1 to 9>. If You want to Remove Inputed Value Press '0'. You can't change the Given Value. If you fill up all the blank space properly, then the level will be completed & You get Congratulation. Otherwise Game will be Running. But if you want to close the program : Press <Capital 'X' or END KEY> \n\n\n";
                Multi_Tabs_3 cout << "You should Fill Up All The Empty(Dot Sign) Index by Inserting Proper Value\n\n";
                int Sudoku[101]= {0}, cnt, row=0, col=0, Index=11, Value=0, i, j, k;  //Sudoku holo Main Array jeti sokol index Value contain korbe, etake 2D array hisebeo NewLine a jaito but ami neini
                bool Temp[101]={false}, Markerer[101] = {false};   // ei string-tar kaj holo, jate given index gulor value ami poriborton korte na pari.
                Markerer [Index] = true;

                //Given Index Value (below) <-- Eigulo ami amar iccha onujayi sohoj vabe diyechi, onno jekono proper value input dewa jabe
                /* srand(time(NULL)); */
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

                Multi_Tabs_1                                //Likha gulo jate majhe dekha jay
                cout<<"*";

                //Initial print(below Loop)
                for(i= 11; i<100; i++)
                {
                    if  (Sudoku[i]== 0)   printf("%c  ", Sudoku[i]+'.');
                    else                  printf("%c  ", Sudoku[i]+'0');

                    if((i%10)% 3== 0)               cout << " ";
                    if((i/10)% 3== 0 && i%10== 9)  {NewLine  Multi_Tabs_1}
                    if(i%10== 9)                   {i++; NewLine  Multi_Tabs_1}

                }
                Sound

                //(below-Loop)--> kongulo index initially faka chilo r kongulo faka chilo na seta jachai
                for(i= 0; i<= 100; i++)
                {
                    if(Sudoku[i]== 0 ) Temp[i]= false ;
                    else               Temp[i]= true ;
                }

                cout << "\n\n\n";

                NewLine NewLine

                while(true)
                {
                    bool flag= true;

                    cout<<"\r";

                    Multi_Tabs_1 cout << "Enter Value of Markered Index";
                    hideCursor();


                    while(true)
                    {
                        this_thread::sleep_for(chrono::milliseconds(Time_Delay));

                        if (kbhit())           //Control by arrow KEY
                        {
                            KEY = _getch();      Key_Hit_Maintainor();

                            if    (KEY==72)  {row--;break;}
                            if    (KEY==80)  {row++;break;}
                            if    (KEY==75)  {col--;break;}
                            if    (KEY==77)  {col++;break;}
                            if    (KEY>='0' && KEY<='9') {Value= KEY-'0'; break;}
                            if    (KEY=='X') goto Menu;
                            if    (KEY==71 || KEY==79) goto Menu;

                        }
                        row+=9; row%=9;
                        col+=9; col%=9;

                    }

                    Index=10*(row+1)+(col+1);
                    Markerer[Index] = true;
                    if    (!(KEY>='0' && KEY<='9')) {flag= false;   goto sudko;}

                    if(Temp[Index]) {/**cout << "\r\t\t\t\t\tIndex[" << row << "][" << col << "]\t  = ";cout << "Not Changeable\n\n"; */ flag = false; goto sudko; }  //Given Value gulo Change kora jabe na


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
                            if(cnt != 1) {flag= 0; break; }  //Sobgulo Number Kebol-Matro 1 bar ache kina; na thakle shorto puron hoyni
                        }
                        if(flag== 0) break;
                    }

                    //Column-Wise Shorto puron hoyeche kina seta jachai(below-Loop)
                    for(k= 1; k<= 9; k++)
                    {
                        if(!flag) break;

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
                        if(!flag) break;
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
                        if(!flag) break;
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
                        if(!flag) break;
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
                        if(!flag) break;
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
                        if(!flag) break;
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
                        if(!flag) break;
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
                        if(!flag) break;
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
                        if(!flag) break;
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
                        if(!flag) break;
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

                sudko:

                    system("cls");
                    Multi_Tabs_1 cout << "\tSUDOKU GAME\n\n\n";

                    cout<<"#Instruction : Here You should Fill Up All of the Blank Space Properly (According to Sudoku Rules).\n\n Here ('*' Sign Before Number) Indicates Current Index, ('`' sign After Number) indicates Your Filled Index. To Change Index Possition Press <Arrow Keys: Left/Right/Up/Down>,   To insert value into the Index: Select Index Possition, then input the value < From 1 to 9>. If You want to Remove Inputed Value Press '0'. You can't change the Given Value. If you fill up all the blank space properly, then the level will be completed & You get Congratulation. Otherwise Game will be Running. But if you want to close the program : Press <Capital 'X' or END KEY or HOME KEY> \n\n\n";

                    Multi_Tabs_4 cout << "You should Fill Up All The Empty(Dot Sign) Index by Inserting Proper Value.\n\n";
                    NewLine Multi_Tabs_1

                    //Print the Sudoku Matrix(Below)
                    for(i= 11; i<100; i++)
                    {
                        /** changeTextColour(); */
                        if      (Index==i) cout<<"*";
                        if      (Sudoku[i]== 0)            printf("%c  ", Sudoku[i]+'.'); //'0' use korle Empty Index gulo bujhte osubidha hoy, tai '.' use korechi
                        else if (Temp  [i]== 0)            printf("%c` ", Sudoku[i]+'0');
                        else                               printf("%c  ", Sudoku[i]+'0');
                        if((i%10)% 3== 0) cout << " ";
                        if((i/10)% 3== 0 && i%10== 9) {NewLine  Multi_Tabs_1}
                        if(i%10== 9) {i++; NewLine  Multi_Tabs_1}

                    }

                    cout << "\n\n";

                    Sound

                    if(flag== true){Multi_Tabs_1 cout << "     Congratulation!\n"; Multi_Tabs_2; cout<<" You Filled All the Space Properly!\n\n"; break; } //jodi Shobgulo Shorto thik moto fill up hoy, tobe Ami thik moto Game sompurno korte perechi

                }

                getch(); Multi_Tabs_1 cout << "   Again Congratulation!\n";
                getch(); Multi_Tabs_1 cout << "  Further Congratulation!\n"; // 3 time Congratulation (not so necessary)
                getch(); Multi_Tabs_1; cout<<"Many Many Congratulatipon!\n";
                Multi_Tabs_1 cout << "       Thank You!\n";


                Again = Dicission (Kall);
                if(Again!= '1') goto Menu;

            }
            break;

        case 7:

            while(1)
            {
                int Cri_Choise;

                Multi_Tabs_1 cout << "    CRICKET      \n\n";

                Multi_Tabs_1 cout << "Your Team Name    : ";      if(!is_Team_named) cin >> Team_1; else cout<< Team_1 <<endl;
                Multi_Tabs_1 cout << "Opposit Team Name : ";      if(!is_Team_named) cin >> Team_2; else cout<< Team_2 <<endl;
                NewLine NewLine


                Multi_Tabs_1 cout << "    Over   : ";       if(!is_over_Wick_Selected) cin >>   Over_Total;  else cout<<Over_Total  <<endl;  if(Over_Total  <1) goto Menu; //if i want to close this Game
                Multi_Tabs_1 cout << "    Wicket : ";       if(!is_over_Wick_Selected) cin >> Wicket_Total;  else cout<<Wicket_Total<<endl;  if(Wicket_Total<1) goto Menu; //if i want to close this Game
                NewLine NewLine

                if(!is_Tossing)
                {
                    int Your_Toss_Choise, Toss_Coin;

                    Multi_Tabs_1 cout<<"      Now Tossing! \n\n";
                    Multi_Tabs_3 cout<<"What do you want? Head / Tail? Press --> - 'H' / 'T'.\n\n";

                    while(true)
                    {
                        this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                        if (kbhit())           //Control by arrow KEY
                        {
                            KEY = _getch();

                            if    (KEY=='h') {Your_Toss_Choise = 0; break;}
                            if    (KEY=='t') {Your_Toss_Choise = 1; break;}
                        }
                    }

                    Toss_Coin = rand()%2;

                    if(Your_Toss_Choise == Toss_Coin)
                    {
                        Multi_Tabs_2 cout<<"Congratulation! You won the Toss!\n\n";
                        Multi_Tabs_2 cout<<" Press --> '1' for  Batting First\n";
                        Multi_Tabs_2 cout<<" Press --> '2' for Fielding First\n";
                        NewLine

                        while(true)
                        {
                            this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                            if (kbhit())           //Control by arrow KEY
                            {
                                KEY = _getch();

                                if    (KEY=='1') {break;}
                                if    (KEY=='2') {break;}
                            }
                        }

                        Cri_Choise = int(KEY - '0');
                    }

                    else
                    {
                        Multi_Tabs_3    cout<<"Oh! Opportunate Team won the Toss & ";
                        if(rand()%2)   {cout<<"Decited to Bat First\n";  Cri_Choise = 2;}
                        else           {cout<<"Decited to Ball First\n"; Cri_Choise = 1;}

                        NewLine

                        Multi_Tabs_1 cout<<"Press Any Key to Continue";
                        getch();
                    }

                }

                system("cls");

                Multi_Tabs_1 cout << "    CRICKET      \n\n";
                Multi_Tabs_1 cout << char(2) << " " << Team_1 << "  vs  " << Team_2 << " " << char(2) <<endl<<endl;
                Multi_Tabs_1 cout<< Over_Total << " Over | " << Wicket_Total << " Wicket"<<endl<<endl<<endl;
                cout << "INSTRUCTION : \"Here Everytime you should Press 'Any KEY' from 0 to 6 to Bowling(in Bowling time) or to Hit the Ball(in Batting time)\". If You & Opportunate Team Select Same Number, then a Wicket is Fallen. Otherwise Hitted Value includes with Run. You should Play the Match in Limited Over & Limited Wickets. The Team Who get more Run, That is Winner. [IF YOU WANT TO FACE MULTIPLE BALL AT_A_TIME FOR SAVING YOUR TIME -->  PRESS & HOLD KEY <from 0 to 6> ]\n\n";
                NewLine

                switch (Cri_Choise){

                    case 1:

                        while(true)
                        {
                            int over = Over_Total, wick = Wicket_Total;
                            int Run= 0, w= 0, Ball= 0, temp;
                            int Hit, c, Hit_Op, i;

                            NewLine Multi_Tabs_2 cout << "Everytime Press any KEY from '0' to '6'  :\n\n";

                            cout << Team_1 << " Batting  :\n\n";

                            while(1)
                            {
                                /** changeTextColour(); */
                                Ball++;
                                int pRun= Run, pw= w;
                                temp += (rand()%100);
                                temp= temp%100;

                                while(true)
                                {
                                    this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                                    if (kbhit())           //Control by arrow KEY
                                    {
                                        KEY = _getch();

                                        if    (KEY>='0' && KEY<='6')                        { break;}
                                        if    (KEY=='x' || KEY=='X' || KEY==71 || KEY==79)  {is_Team_named = false; is_over_Wick_Selected = false; is_Tossing = false; goto Menu;}
                                        if    (KEY==77 || KEY==' ')                         {KEY=rand()%7 +'0';   break;}

                                    }
                                }

                                Hit= KEY-'0';
                                if(Hit>6 || Hit<0) Hit= 0;

                                /* srand(time(NULL)); */

                                c= (rand()+temp)%100;
                                c++;
                                if      (c<2) Hit_Op= 0;
                                else if (c<5) Hit_Op= 1;
                                else if (c<12)Hit_Op= 2;
                                else if (c<24)Hit_Op= 3;
                                else if (c<41)Hit_Op= 4;
                                else if (c<71)Hit_Op= 5;
                                else          Hit_Op= 6;

                                if(Hit== Hit_Op) {w++; Run -= Hit; Sound }

                                Run += Hit;

                                Carriage Multi_Tabs_1 cout  << Ball/6 << "." << Ball%6 << ":    " << Run << "/" << w << " (+" << Run-pRun << "/" << w-pw << ")         ";
                                if(w== wick || Ball== 6*over ) break;

                            }

                            int myRun= Run;
                            cout << endl << Team_1 << " : " << Run << "/" << w << endl;

                            cout << "Target : " << Run+1 << endl << endl;

                             Run= 0;
                             w= 0;
                             Ball= 0;

                            cout << Team_2 << " Batting  :\n\n";
                            while(1)
                            {
                                /** changeTextColour(); */
                                Ball++;
                                int pRun= Run, pw= w;
                                temp += (rand()%100);
                                temp= temp%100;
                                while(true)
                                {
                                    this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                                    if (kbhit())           //Control by arrow KEY
                                    {
                                        KEY = _getch();

                                        if    (KEY>='0' && KEY<='6')                            { break;}
                                        if    (KEY=='x' || KEY=='X' || KEY==71 || KEY==79)      {is_Team_named = false; is_over_Wick_Selected = false; is_Tossing = false; goto Menu;}
                                        if    (KEY==77 || KEY==' ')                             {KEY=rand()%7 +'0';   break;}

                                    }
                                }

                                Hit= KEY-'0';

                                /* srand(time(NULL)); */

                                Hit_Op= (rand()+temp)%7;

                                if(Hit== Hit_Op) {w++; Run -= Hit_Op; Sound}

                                Run += Hit_Op;

                                Carriage Multi_Tabs_2 cout << Ball/6 << "." << Ball%6 << ":    " << Run << "/" << w << "    (Need: " <<  myRun-Run+1 << "/" << wick-w << "(" << (6*over-Ball)/6 << "." << (6*over-Ball)%6 << ")) (+" << Run-pRun << "/" << w-pw << ")           ";
                                if(w== wick || Ball== 6*over || Run>myRun ) break;

                            }

                            int oppRun= Run;
                            cout << endl << Team_2 << " : " << Run << "/" << w << endl;

                            NewLine Multi_Tabs_1

                            if(oppRun>myRun) cout << Team_2 << " won by " << wick-w << " Wicket\n";
                            if(oppRun<myRun) cout << Team_1 << " won by " << myRun-oppRun << " Run\n";

                            NewLine
                            if(oppRun<myRun)    { win++; Multi_Tabs_2  cout << "Congratulation! Your Team " << Team_1 << " is Winner\n"; }
                            if(oppRun== myRun)  {draw++; Multi_Tabs_2  cout << "\tMatch Drawn\n"; }
                            if(oppRun>myRun)    {lost++; Multi_Tabs_2  cout << "Sorry! Opportunate Team " << Team_2 << " is Winner\n"; }

                            NewLine NewLine

                            break;
                        }
                        break;


                    case 2:
                        while(true)
                        {
                            int Run= 0, Wicket= 0, Ball= 0, Temp;
                            int My_Hit, Com_Hit_Temp, Com_Hit, i;

                            NewLine Multi_Tabs_2 cout << "Everytime Press any KEY from '0' to '6'  :\n\n";

                            cout << Team_2 << " Batting  :\n\n";

                            //Bowling Loop (below)
                            while(1)
                            {
                                /** changeTextColour(); */
                                Ball++;
                                int Run_Previous= Run, Wicket_Previous= Wicket;

                                Temp += (rand() % 100);
                                Temp= Temp % 100;


                                while(true)
                                {
                                    this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                                    if (kbhit())           //Control by arrow KEY
                                    {
                                        KEY = _getch();

                                        if    (KEY>='0' && KEY<='6') { break;}
                                        if    (KEY=='x' || KEY=='X' || KEY==71 || KEY==79) { is_Team_named = false; is_over_Wick_Selected = false; is_Tossing = false; goto Menu;}
                                        if    (KEY==77 || KEY==' ')              {KEY=rand()%7 +'0';   break;}

                                    }
                                }

                                My_Hit= KEY-'0';

                                /* srand(time(NULL)); */

                                Com_Hit= (rand()+Temp) % 7;//Output: 0 to 6

                                if(My_Hit== Com_Hit) {Wicket++;Run -= Com_Hit; Sound} //jodi Amar Select kora songkha r Computer er Select kora songkha Same hoy tobe Wicket porbe

                                Run += Com_Hit;                                   //- r same na hole Computer er select kora songkha Run hisebe add hobe

                                Carriage Multi_Tabs_1 cout << Ball/6 << "." << Ball % 6 << ":    " << Run << "/" << Wicket << " (+" << Run-Run_Previous << "/" << Wicket-Wicket_Previous << ")              " ;
                                if(Wicket== Wicket_Total || Ball== 6*Over_Total ) break;

                            }
                            int Op_Run= Run;

                            cout << endl << Team_2 << " : " << Run << "/" << Wicket << endl;
                            cout << "Target : " << Run+1 << endl << endl;

                             Run= 0;
                             Wicket= 0;
                             Ball= 0;


                            cout << Team_1 << " Batting  :\n\n";

                            while(1)
                            {
                                /** changeTextColour(); */
                                Ball++;
                                int Run_Previous= Run, Wicket_Previous= Wicket;

                                Temp += (rand() % 991);
                                Temp= Temp % 100;

                                while(true)
                                {
                                    this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                                    if (kbhit())           //Control by arrow KEY
                                    {
                                        KEY = _getch();

                                        if    (KEY>='0' && KEY<='6')                            { break;}
                                        if    (KEY=='x' || KEY=='X' || KEY==71 || KEY==79)      {is_Team_named = false; is_over_Wick_Selected = false; is_Tossing = false; goto Menu;}
                                        if    (KEY==77 || KEY==' ')                             {KEY=rand()%7 +'0';   break;}

                                    }
                                }

                                My_Hit= KEY - '0';
                                if(My_Hit>6 || My_Hit<0) My_Hit= 0;

                                /* srand(time(NULL)); */

                                Com_Hit_Temp= (rand()+Temp) % 100;
                                Com_Hit_Temp++;

                                if      (Com_Hit_Temp< 2)   Com_Hit= 0;
                                else if (Com_Hit_Temp< 5)   Com_Hit= 1;
                                else if (Com_Hit_Temp<12)   Com_Hit= 2;
                                else if (Com_Hit_Temp<24)   Com_Hit= 3;
                                else if (Com_Hit_Temp<41)   Com_Hit= 4;
                                else if (Com_Hit_Temp<71)   Com_Hit= 5;
                                else                        Com_Hit= 6;

                                if(My_Hit== Com_Hit) {Wicket++;Run -= My_Hit; Sound}

                                Run += My_Hit;

                                Carriage Multi_Tabs_2 cout  << Ball/6 << "." << Ball % 6 << ":    " << Run << "/" << Wicket << "    (Need: " << Op_Run+1-Run << "/" << Wicket_Total-Wicket << "(" << (6*Over_Total-Ball)/6 << "." << (6*Over_Total-Ball) % 6 << ")) (+" << Run-Run_Previous << "/" << Wicket-Wicket_Previous << ")               ";
                                if(Wicket== Wicket_Total || Ball== 6*Over_Total || Run>Op_Run) break;
                            }

                            int My_Run= Run;

                            cout << endl << Team_1 << " : " << My_Run << "/" << Wicket << endl;

                            NewLine Multi_Tabs_1
                            if(My_Run>Op_Run) cout << Team_1 << " won by " << Wicket_Total-Wicket << " Wicket\n";
                            if(My_Run<Op_Run) cout << Team_2 << " won by " << Op_Run-Run << " Run\n";

                            NewLine
                            if(My_Run >  Op_Run) {win++;  Multi_Tabs_2  cout << "Congratulation! Your Team " << Team_1 << " is Winner\n";}
                            if(My_Run== Op_Run) {draw++;  Multi_Tabs_1 cout << "\tMatch Drawn\n";}
                            if(My_Run <  Op_Run) {lost++; Multi_Tabs_2 cout << "Sorry! Opportunate Team " << Team_2 << " is Winner\n";}

                            break;
                        }
                        break;
                    }

                    Again = Dicission_cricket (Kall);
                    if(Again== '0') goto Menu;
                    if(Again== '1') { is_Team_named = false; is_over_Wick_Selected = false; is_Tossing = false;}
                    if(Again== '2') { is_Team_named = true; is_over_Wick_Selected = false;  is_Tossing = false;}
                    if(Again== '3') { is_Team_named = true; is_over_Wick_Selected = true;   is_Tossing = false;}
                    if(Again== '4') { is_Team_named = true; is_over_Wick_Selected = true;   is_Tossing = true;}
                }

                break;

        case 8:

            while(1)
            {
                Multi_Tabs_1 cout<<"  Mini GAMES\n\n";

                /* srand(time(NULL)); */
                int Choice = 3;

                MiniMenu:

                    Choice++;
    //                if(KEY==72)  Choice-=2;
                    if(Choice>4) Choice-=4;

                    switch(Choice){

                    case 1:
                        while(1)
                        {
                            int Bulet,Kil=0,Shoot,Diffc,Temp=100 ;

                            Multi_Tabs_1  cout<<"  SHOOTING GAME\n\n";

                            Multi_Tabs_3 cout<<"Diffculty (Enter a Little Positive Intizer Number)  =  ";
                            cin>>Diffc ;
                            if(Diffc <0) goto Menu;

                            Multi_Tabs_3 cout<<"BULLET    (    Enter Number of Bullet with You   )  =  ";
                            cin>>Bulet;

                            int Enimi = ceil(Bulet/1.0/(Diffc +1));  // avarage luck

                            Multi_Tabs_3 cout<<"TARGATED ENEMY TO KILL                            =  "<<Enimi<<endl;

                            NewLine NewLine Multi_Tabs_2 cout<<"TO SHOT BULLET    : Press -->      ANY     KEY\n";
                                            Multi_Tabs_2 cout<<"TO Close the Game : Press --> <HOME/END/X> KEY\n\n";


                            for(int i=1;i<=Bulet;i++)
                            {
                                /* srand(time(NULL)); */
                                Temp++;

                                KEY = _getch();
                                if (KEY=='x' || KEY=='X' || KEY==71 || KEY==79) goto Menu;

                                Shoot = rand() *3/2 + Temp;
                                Shoot++;

                                if(rand() %(Diffc+1) == Shoot %(Diffc+1)) Kil++;

                                cout<<"\t\t";
                                cout<<  \
                                "Current Kill  : "<<Kil<< \
                                "\t   Bullet Spends  : "<< i<< \
                                "\t   Bullet Left  : "<<Bulet-i<< \
                                "\t   Targeted Enemy Left  : "<< Enimi-Kil <<endl;

                            }

                            NewLine Multi_Tabs_1
                            cout<<"Total Kill = "<<Kil<<endl;

                            NewLine Multi_Tabs_3
                            if(Kil> Enimi) cout<<"Congratulations! You Kill more than Target.\n";
                            if(Kil==Enimi) cout<<"Congratulations! You Kill  Equal to Target.\n";
                            if(Kil< Enimi) cout<<"Alas! You Kill Less than Target.\n";

                            Again = Dicission_in_Mini_Games  (Kall);
                            if      (Again== '1') ;
                            else if (Again== '2') goto MiniMenu;
                            else                  goto Menu;

                        }

                    case 2:
                        while(1)
                        {
                            Multi_Tabs_1 cout<<"   Toss Game\n\n";
                            Multi_Tabs_4 cout<<"\tPress --> 'H' to chose Head\n";
                            Multi_Tabs_4 cout<<"\tPress --> 'T' to chose Tail\n";
                            Multi_Tabs_4 cout<<"\tPress --> 'x' to Close the game\n\n";

                            int win=0,lost=0;
                            while(1)
                            {
                                int n;
                                char you,com;
//                                cout<<"Press --> 'H' or 'T' (without quatation)\t:\t";
                                while(true)
                                {
                                    this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                                    if (kbhit())           //Control by arrow KEY
                                    {
                                        KEY = _getch();      Key_Hit_Maintainor();

                                        if(KEY=='h' || KEY == 't' || KEY == 'x' || KEY==75) break;
                                        if(KEY=='H' || KEY == 'T' || KEY == 'X' || KEY==77) break;

                                    }
                                }

                                system("cls");
                                you=toupper(KEY);
                                if(you==75) goto Menu;
                                else if(you!='H' && you!= 'T') break;

                                /* srand(time(NULL)); */

                                n=rand()%2;
                                if(n==0) com='T';
                                else     com='H';

                                Multi_Tabs_1 cout<<"   Toss Game\n\n";
                                Multi_Tabs_4 cout<<"\tPress --> 'H' to chose Head\n";
                                Multi_Tabs_4 cout<<"\tPress --> 'T' to chose Tail\n";
                                Multi_Tabs_4 cout<<"\tPress --> 'x' to Close the game\n\n";



                                NewLine
                                cout<<"  You chose       : "<<you ; NewLine
                                cout<<"& Computer chose  : "<<com<<"\n\n";

                                Sound NewLine NewLine Multi_Tabs_1
                                if(you==com) { cout<<"  Winner\n\n"; win++;}
                                else         { cout<<"   Loser \n\n";                           lost++;}

                            }
                            Multi_Tabs_1 cout<<"   Toss Game\n\n";

                            Sound
                            NewLine Multi_Tabs_3 cout<<"          Match Ended     ";
                            NewLine Multi_Tabs_3 cout<<"          Your Score=  "<<win;
                            NewLine Multi_Tabs_3 cout<<"      & Computer's Score=  "<<lost;

                            NewLine NewLine Multi_Tabs_3
                            if      (win>lost) cout<<"Congratulation! You won More  match than Computer!\n\n";
                            else if (win<lost) cout<<" Sorry! You won Less  match than Computer!\n\n";
                            else               cout<<" Drawn! You won Equal match than Computer!\n\n";

                            Again = Dicission_in_Mini_Games  (Kall);
                            if      (Again== '1') ;
                            else if (Again== '2') goto MiniMenu;
                            else                  goto Menu;

                        }

                    case 3:
                        while(1)
                        {
                            int Bulet,Kil=0,Shoot,Diffc,Temp=100 ;

                            Multi_Tabs_1  cout<<"    BATTLE GAME\n";
                            Multi_Tabs_1  cout<<"[PALESTINE vs ISRAEL]\n\n";

                            Multi_Tabs_3 cout<<"Diffculty (Enter a Little Positive Intizer Number)  =  ";
                            cin>>Diffc ;
                            if(Diffc <0) goto Menu;

                            Multi_Tabs_3 cout<<"RPJ       (    Enter Number of Bullet with You   )  =  ";
                            cin>>Bulet;

                            int Enimi = ceil(Bulet/1.0/(Diffc +1));  // avarage luck

                            Multi_Tabs_3 cout<<"TARGATED MARCAVA TANK TO DESTROY                     =  "<<Enimi<<endl;

                            NewLine NewLine Multi_Tabs_2 cout<<"TO LAUNCH     RPJ : Press -->      ANY     KEY\n";
                                            Multi_Tabs_2 cout<<"TO Close the Game : Press --> <HOME/END/X> KEY\n\n";


                            for(int i=1;i<=Bulet;i++)
                            {
                                Temp++;

                                KEY = _getch();
                                if (KEY=='x' || KEY=='X' || KEY==71 || KEY==79) goto Menu;

                                Shoot = rand() *3/2 + Temp;
                                Shoot++;

                                if(rand() %(Diffc+1) == Shoot %(Diffc+1)) Kil++;

                                cout<<"\t\t";
                                cout<<  \
                                "Current Brusted TANK  : "<<Kil<< \
                                "\t   RPJ Spends  : "<< i<< \
                                "\t   RPJ Left  : "<<Bulet-i<< \
                                "\t   Targeted TANK Left  : "<< Enimi-Kil <<endl;

                            }

                            NewLine Multi_Tabs_1
                            cout<<"Total Brusted = "<<Kil<<endl;

                            NewLine Multi_Tabs_3
                            if(Kil> Enimi) cout<<"Congratulations! You Brust more than Target.\n";
                            if(Kil==Enimi) cout<<"Congratulations! You Brust  Equal to Target.\n";
                            if(Kil< Enimi) cout<<"Alas! You Brust Less than Target.\n";

                            Again = Dicission_in_Mini_Games  (Kall);
                            if      (Again== '1') ;
                            else if (Again== '2') goto MiniMenu;
                            else                  goto Menu;

                        }


                    case 4:
                        while(1)
                        {
                            tabs cout<<"\tRock Paper Seissor Game\n\n";
                            tabs cout<<"\tPress --> 'R' to chose Rock\n";
                            tabs cout<<"\tPress --> 'P' to chose Paper\n";
                            tabs cout<<"\tPress --> 'S' to chose Seissor\n";
                            tabs cout<<"\tPress --> 'X' to close the game\n\n";
                            int win=0,lost=0;

                            while(1)
                            {
                                int n;
                                Sound
                                char you,com;
//                                cout<<"\nPress --> 'R' or 'P' or 'Z' (without quatation)\t:\t";
                                while(true)
                                {
                                    this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                                    if (kbhit())           //Control by arrow KEY
                                    {
                                        KEY = _getch();      Key_Hit_Maintainor();

                                        if(KEY=='r' || KEY == 'p' || KEY == 's' || KEY == 'x' || KEY==75) break;
                                        if(KEY=='R' || KEY == 'P' || KEY == 'S' || KEY == 'X' || KEY==77) break;

                                    }
                                }

                                if(KEY==75) goto Menu;

                                you = toupper(KEY);
                                system("cls");

                                if(you=='X' || you ==77) break;

                                n=rand()%3;
                                if     (n<1) com='R';
                                else if(n<2) com='P';
                                else         com='S';

                                tabs cout<<"\tRock Paper Seissor Game\n\n";
                                tabs cout<<"\tPress --> 'R' to chose Rock\n";
                                tabs cout<<"\tPress --> 'P' to chose Paper\n";
                                tabs cout<<"\tPress --> 'S' to chose Seissor\n";
                                tabs cout<<"\tPress --> 'X' to close the game\n\n";

                                NewLine
                                cout<<"Your    Choice         \t:\t"<<you<<endl;
                                cout<<"Computer Chose         \t:\t"<<com<<endl;

                                NewLine Multi_Tabs_1
                                if(you==com) cout<<"Drawn\n\n";

                                else if (you=='P' && com=='R' || you=='S' && com=='P' || you=='R' && com=='S')
                                {
                                    win++;
                                    cout<<"Winner\n\n";
                                }
                                else if (you=='R' && com=='P' || you=='P' && com=='S' || you=='S' && com=='R')
                                {
                                    lost++;
                                    cout<<"Loser\n\n";
                                }

                                else
                                {
                                    cout<<"Error! Give Correct Input\n\n";
                                    system("cls");
                                    break;
                                }
                            }

                            tabs cout<<"\tRock Paper Seissor Game\n\n";
                            NewLine Multi_Tabs_2 cout<<"       Match Ended     ";
                            NewLine Multi_Tabs_2 cout<<"       Your Score= "<<win;
                            NewLine Multi_Tabs_2 cout<<"   & Computer's Score= "<<lost;

                            NewLine NewLine Multi_Tabs_3
                            if      (win>lost) cout<<"Congratulation! You won More  match than Computer!\n\n";
                            else if (win<lost) cout<<" Sorry! You won Less  match than Computer!\n\n";
                            else               cout<<" Drawn! You won Equal match than Computer!\n\n";

                            Again = Dicission_in_Mini_Games (Kall);
                            if      (Again== '1') ;
                            else if (Again== '2') goto MiniMenu;
                            else                  goto Menu;
                        }
                    }
            }

        case 100:
            Multi_Tabs_1  cout << " Program is Closed.\n\n";
            Multi_Tabs_2 cout << ""<<Coder_Name<<endl;
            Multi_Tabs_1  cout << " [ ALHAMDULILLAH ]\n";
            NewLine Multi_Tabs_1 cout << "Spacial Thanks to \n"; Multi_Tabs_4 cout<<"\t\t  Sharif Uddin "<<endl;
            NewLine

            getch();
            Multi_Tabs_1 cout << "Jajakallahu Khairan\n";
            Multi_Tabs_2 cout << "Meet with You Next Time InshaAllah\n";

            getch();
            cout<<"\n\nTotal Polling   : "<<KeyHit_Cheak_Count<<endl;

            return 0;

        default:
            goto Menu;

    }
    goto Menu;
}
