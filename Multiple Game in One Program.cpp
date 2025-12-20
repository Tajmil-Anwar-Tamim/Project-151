#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>                     //for getch() & kbhit condition;

// Tabs:
#define tab cout<<"\t";
#define tabs for (iGlobal=0;iGlobal<TabNumber;iGlobal++) tab
#define Multi_Tabs_1  tabs tab tab    //Likhagulo Middle Show korar jonno
#define Multi_Tabs_2 tabs tab cout << "  ";
#define Multi_Tabs_3 tabs cout << "     ";
#define Multi_Tabs_4 tabs
#define Carriage cout<<"\r";

//New-Line & Sound
#define NewLine cout << "\n";
#define Sound if(SoundFlag == true) cout << "\a";                 // Sound
//#define Auto_Change_Text_Color if (is_Continuous_Change_Color) changeTextColour();

#define Border_Sign          if(Mark==3) cout<<". ";                             else cout<<char(219);
#define Multiple_Border_Sign if(Mark==3) for(int i=0;i<11;i++) Border_Sign       else for(int i=0;i<21;i++) Border_Sign

#define show_Point  cout << "\tScore : " << (Level)*Point << endl << endl;
#define showScore   cout << "\tScore : " << Score << endl;
#define showLife    cout << "\t Life : " << Life << endl << endl;

using namespace std;

// Global Variables <below>
int Mark=1; char Marked_Symbol;
char KEY;

int Time_Delay=0;   //time delay in every KEY-hit.
int KeyHit_Cheak_Count=0;

int TabNumber=6,iGlobal;

bool SoundFlag  = true;
bool is_Premium = false;
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

int rd1=0, rd2=0, rd3=0;

void DisplayAdvise()
{
    rd1 = 1 + rd1 % 4;

    if(rd1==1) cout<<"\r"<<"BE OBIDIENT TO ALLAH (SUBH.)        ";
    if(rd1==2) cout<<"\r"<<"FOLLOW PROPHET MUHAMMAD (SM.)       ";
    if(rd1==3) cout<<"\r"<<"READ QURAN                          ";
    if(rd1==4) cout<<"\r"<<"FOLLOW SUNNAH, NOT WESTERN          ";

    if(TabNumber<4) cout<<"                    ";

}

void DisplayWorld()
{
    rd3 = 1 + rd3 % 3;

    //if(rd3==4) cout<<"\r"<<"Arise Your Brain               ";
    if(rd3==1) cout<<"\r"<<"Never Forget Filistin          ";
    if(rd3==2) cout<<"\r"<<"They Oppressed Heavily         ";
    if(rd3==3) cout<<"\r"<<"Stand with Them                ";

    if(TabNumber<4) cout<<"                    ";

}

void DisplayWorldView()
{
    rd2 = 1 + rd2 % 10;

    if(rd2==1) cout<<"\r"<<"Pray For Arakan                ";
    if(rd2==2) cout<<"\r"<<"Pray For Kashmir               ";
    if(rd2==3) cout<<"\r"<<"Pray For Uighur                ";
    if(rd2==4) cout<<"\r"<<"Pray For Gaza                 ";
    if(rd2==5) cout<<"\r"<<"Pray For Yemen                 ";
    if(rd2==7) cout<<"\r"<<"Pray For Africa                ";
    if(rd2==6) cout<<"\r"<<"Pray For Baytul Mukaddis       ";
    if(rd2==8) cout<<"\r"<<"Pray For Whole_Oppressed_Ummah ";
    if(rd2==9) cout<<"\r"<<"Never Forget Them              ";
    if(rd2==10) cout<<"\r"<<"One_Ummah One_Body             ";

    if(TabNumber<4) cout<<"                    ";

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

int changeTextColour2()
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

void Instruction()
{
    clearScreen();

    changeTextColour();  cout<<"Press < \' or ; Key >  :  to Change Text Colour     in Black BackGround\n";
    changeTextColour2(); cout<<"Press < \" or : Key >  :  to Change Text Colour     in White BackGround\n"; NewLine
    changeBgColour2();      cout<<"Press < ] or [ Key >  :  to Change BackGround Colour   with White Text\n";
    changeBgColour();       cout<<"Press < } or { Key >  :  to Change BackGround Colour   with Black Text\n"; NewLine

    SetConsoleColor(BrightWhite);       cout<<"Press < \\ Key >  : to Flush Color in Text/BackGround = White/Black\n";
    SetConsoleColour(Black,BrightWhite); cout<<"Press < | Key >  : to Flush Color in Text/BackGround = Black/White\n"; NewLine

//    SetConsoleColor(BrightWhite);
    cout<<"Press < + Key > : to Decrese  KeyHit Speed\n";
    cout<<"Press < - Key > : to Increase KeyHit Speed\n";  NewLine

    SetConsoleColour (Black,BrightWhite);
    cout<< "Press [ < Key ] : to Shift Texts  Left     \n";
    cout<< "Press [ > Key ] : to Shift Texts Right     \n";  NewLine

//    SetConsoleColor(BrightWhite);
    cout<< "Press < ` Key > : to Mute       \n";
    cout<< "Press < ~ Key > : to UnMute     \n\n";

    cout<< "Press <Small'p'> for Premium ASCII Mode (This can be misbehave in Some System)\n";
    cout<< "Press <Small'u'> for Come-back Normal  ASCII Mode\n\n";

    SetConsoleColour (Black,BrightWhite);
    cout<<"Press < Home Key >, to Goto Main Menu\n";
    cout<<"Press < End  Key >, to close the Program\n\n";

    //SetConsoleColor(BrightWhite);

    changeTextColour(); changeTextColour2();
    changeBgColour();   changeBgColour2();

    //getch();
}

void Manager()
{
    if(KEY=='+' || KEY=='=') {Time_Delay+=10; Sound if(Time_Delay>100) Time_Delay=100; }
    if(KEY=='-' || KEY=='_') {Time_Delay-=10; Sound if(Time_Delay<0)   Time_Delay=0; }

    if (KEY=='p') is_Premium = true;
    if (KEY=='u') is_Premium = false;

    if (KEY=='\'')
    {
        changeTextColour();
        cout <<"\r[Text Colour Changed]";
    }

    if (KEY=='"')
    {
        changeTextColour2();
        cout <<"\r[Text Colour Changed]";
    }

    if (KEY==';')
    {
        ColorVar -= 2;
        changeTextColour();
        cout <<"\r[Text Colour Changed]";
    }

    if (KEY==':')
    {
        ColorVar -= 2;
        changeTextColour2();
        cout <<"\r[Text Colour Changed]";
    }

    if (KEY=='}')
    {
        changeBgColour();
        cout <<"\r[BackGround Colour Changed]";
    }

    if (KEY=='{')
    {
        ColorVar -= 2;
        changeBgColour();
        cout <<"\r[BackGround Colour Changed]";
    }

    if (KEY==']')
    {
        changeBgColour2();
        cout <<"\r[BackGround Colour Changed]";
    }

    if (KEY=='[')
    {
        ColorVar -= 2;
        changeBgColour2();
        cout <<"\r[BackGround Colour Changed]";
    }

    if (KEY=='\\')
    {
        SetConsoleColor(BrightWhite);
        cout <<"\r[Flash Color W/B]";
    }

    if (KEY=='|')
    {
        SetConsoleColour(Black,BrightWhite);
        cout <<"\r[Flash Color B/W]";
    }

    if (KEY=='<' || KEY==',')  {TabNumber--; if(TabNumber<0) TabNumber=0; if(Mark==3 || Mark==4 || Mark==7 || Mark==8) clearScreen();}
    if (KEY=='>' || KEY=='.')  {TabNumber++; if(Mark==3 || Mark==4 || Mark==7 || Mark==8) clearScreen();}
    if (KEY=='^')  {TabNumber=6; if(Mark==3 || Mark==4 || Mark==7 || Mark==8) clearScreen(); }
    if (KEY=='`')  {SoundFlag=false; cout<<"\rMuted";}
    if (KEY=='~')  {SoundFlag= true; cout<<"\r\aUnmuted";}

    KeyHit_Cheak_Count++;

//    if (KEY=='l' && is_Continuous_Change_Color==false) is_Continuous_Change_Color=true;
//    if (KEY=='l' && is_Continuous_Change_Color==true) is_Continuous_Change_Color= false;
}

char Dicission (char a)
{
    NewLine NewLine NewLine
    Multi_Tabs_2 cout << "\tTo Play Again     Press- <Space> or <Enter>  \n";
    Multi_Tabs_2 cout << "\tTo Goto Menu      Press- <Home>  or  <End>   \n";
//    Multi_Tabs_2 cout << "\tTo Close Program  Press- <End>   \n";

    while(true)
    {
        this_thread::sleep_for(chrono::milliseconds(Time_Delay));
        if (kbhit())           //Control by arrow KEY
        {
            KEY = _getch();      Manager();

            if    (KEY==' ' || KEY == 13 )                                  {a= '1';   break;}
            if    (KEY=='x' || KEY=='X' || KEY==71 )                        {a= '0';   break;}
            if    (KEY==79)                                                 {a= '0';   break;}
//            if    (KEY==75)              {a= '1';   break;}
//            if    (KEY==77)              {a= '1';   break;}

        }
    }

    NewLine NewLine NewLine
    clearScreen();
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
            KEY = _getch();      Manager();

//            if    (KEY>='0' && KEY<='4')                 {a= KEY;   break;}
            if    (KEY=='x' || KEY==71 || KEY==79 )      {a= '0';   break;}
            if    (KEY == 32)                            {a= '3';   break;}
            if    (KEY == 13)                            {a= '4';   break;}
            if    (KEY == 8 )                            {a= '2';   break;}
            if    (KEY == 27)                            {a= '1';   break;}

        }
    }

    clearScreen();
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
            Manager();

        }
    }

    clearScreen();
    return a;
}

char Dicission_snake (char a)
{
    NewLine
    Multi_Tabs_3 cout << "\tTo Play Again in Different Speed                 :  Press-  <Esc> \n";
    Multi_Tabs_3 cout << "\tTo Play Again in    Same   Speed                 :  Press- <Space> \n";
    Multi_Tabs_3 cout << "\tTo Goto Main Menu                                :  Press- <Home>\n";
    while(true)
    {
        this_thread::sleep_for(chrono::milliseconds(Time_Delay));
        if (kbhit())           //Control by arrow KEY
        {
            KEY = _getch();      Manager();

            if    (KEY==' ' || KEY == 13 )                          {a= '2';   break;}
            if    (KEY== 27 )                                       {a= '1';   break;}
            if    (KEY=='x' || KEY=='X' || KEY==79 || KEY==71 )     {a= '0';   break;}

        }
    }

    NewLine NewLine NewLine
    clearScreen();
    return a;
}

char Dicission_Mini (char a)
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
            KEY = _getch();      Manager();

//            if    (KEY>='0' && KEY<='3') {a= KEY; break;}
            if    (KEY=='x' || KEY == 71 || KEY==79  )   {a= '0';   break;}
            if    (KEY==77 || KEY==80  || KEY == 13  )   {a= '2';   break;}
            if    (KEY==' '  )                           {a= '1';   break;}
            if    (KEY==72 || KEY == 75  )               {a= '1';   break;}

        }
    }

    NewLine NewLine NewLine
    clearScreen();
    return a;
}

int Randam_Func_09 (int a)                  //Decited Computer's Chose Index in Tic Tac Toe Game
{
    a= rand() % 9;
    a++;
    return a;
}

int Randam_Function_100 (int Return_Fruit) //Decited Fruit possition in Snake Game
{
    /* srand(time(NULL)); */
    Return_Fruit= rand() % 100;
    Return_Fruit++;
    return Return_Fruit;
}

TTT_Index_Instruction()
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
                                                                                                                                                                                                                                                string Coder_Name = "Coded by \'Tajmil Anwar Tamim\'";
int main()
{
    hideCursor(); // কার্সর লুকানো
//    srand(time(NULL)); // র‍্যান্ডম সিড সেট করা

                char Again,Kall;
            /* srand(time(NULL)); */

        Menu:
            clearScreen(); //All Previous Print Erased
            //SetConsoleColour(Black,BrightWhite);

            if(is_Premium) Marked_Symbol = char(2);
            else           Marked_Symbol = char(251);

            Multi_Tabs_1 cout << char(32) << "   MULTIPLE GAMES  "<<char(32);     NewLine NewLine

            Multi_Tabs_3 if(Mark==1) cout<<Marked_Symbol; else cout<<char(32); printf(" Press 1,   to Play         TIC TAC TOE(Man vs Com)\n");
            Multi_Tabs_3 if(Mark==2) cout<<Marked_Symbol; else cout<<char(32); printf(" Press 2,   to Play         TIC TAC TOE(Man vs Man)\n\n");
            Multi_Tabs_3 if(Mark==3) cout<<Marked_Symbol; else cout<<char(32); printf(" Press 3,   to Play            SNAKE GAME (Classic)\n");
            Multi_Tabs_3 if(Mark==4) cout<<Marked_Symbol; else cout<<char(32); printf(" Press 4,   to Play            SNAKE GAME (  Box  )\n\n");
            Multi_Tabs_3 if(Mark==5) cout<<Marked_Symbol; else cout<<char(32); printf(" Press 5,   to Play        SNAKE-LUDO (vs Computer)\n");
            Multi_Tabs_3 if(Mark==6) cout<<Marked_Symbol; else cout<<char(32); printf(" Press 6,   to Play        SNAKE-LUDO (MultiPlayer)\n\n");
            Multi_Tabs_3 if(Mark==7) cout<<Marked_Symbol; else cout<<char(32); printf(" Press 7,   to Play              Pacman Lite (Easy)\n");
            Multi_Tabs_3 if(Mark==8) cout<<Marked_Symbol; else cout<<char(32); printf(" Press 8,   to Play              Pacman Lite (Hard)\n\n");

            Multi_Tabs_3 if(Mark==9) cout<<Marked_Symbol; else cout<<char(32); printf(" Press 9,   to Play                         SUDOKU\n");
            Multi_Tabs_3 if(Mark==10) cout<<Marked_Symbol; else cout<<char(32); printf(" Press A,   to Play                        CRICKET\n\n");

            Multi_Tabs_3 if(Mark==0) cout<<Marked_Symbol; else cout<<char(32); printf(" Press 0,   to Play                     Mini GAMES\n\n");

            Multi_Tabs_3                                                printf("  Press (' \" ] } ),       to Change Text & BG Colour\n\n");                //Instruction end
            Multi_Tabs_3                                                printf("  Press ?,                     For More Instruction\n");

            Multi_Tabs_3                                                printf("  Press X,                    to CLOSE  THE PROGRAM\n\n");

            NewLine NewLine

//            Multi_Tabs_1 printf("SWITCH CASE NUMBER");

//    Mark++;
//    cin  >>  Mark;
//    NewLine NewLine NewLine

    while(true)
    {
        hideCursor();

        this_thread::sleep_for(chrono::milliseconds(Time_Delay));
        KeyHit_Cheak_Count++;   if (KEY=='!') cout<<"\r"<<KeyHit_Cheak_Count<<"                      ";

        if (kbhit())           //Control by arrow KEY
        {
            KEY = _getch();
//            /** changeTextColour(); */

            if      (KEY>='0' && KEY<='9') {Mark= KEY-'0'; break;}
            else if (KEY=='x' || KEY=='X' || KEY==79) {Mark=100; break;}
            else if (KEY=='a' || KEY=='A') {Mark= KEY-55; break;}
            else if (KEY=='p') {is_Premium = true;  goto Menu;}
            else if (KEY=='u') {is_Premium = false; goto Menu; }
            else if (KEY=='?' || KEY=='/' ) {Instruction(); continue;}
            else if (KEY=='`')  {SoundFlag=false; cout<<"\rMuted";}
            else if (KEY=='~')  {SoundFlag= true; cout<<"\r\aUnmuted"; }
            else if (KEY=='<' || KEY==',' )  {TabNumber--; if(TabNumber<0) TabNumber=0; goto Menu;}
            else if (KEY=='>' || KEY=='.' )  {TabNumber++; goto Menu;}
            else if (KEY=='^')  {TabNumber=6; goto Menu;}
            else if (KEY=='\\'){SetConsoleColor(BrightWhite);         goto Menu;}
            else if (KEY=='|') {SetConsoleColour(Black,BrightWhite);  goto Menu;}
            else if (KEY=='\'' )  { changeTextColour();   goto Menu;}
            else if (KEY==';' )   { ColorVar -=2; changeTextColour();   goto Menu;}
            else if (KEY=='"' )   { changeTextColour2();  goto Menu;}
            else if (KEY==':' )   { ColorVar -=2; changeTextColour2();  goto Menu;}

            else if (KEY=='}')  { changeBgColour();   goto Menu;}
            else if (KEY==']')  { changeBgColour2();  goto Menu;}
            else if (KEY=='{')  { ColorVar -=2; changeBgColour();   goto Menu;}
            else if (KEY=='[')  { ColorVar -=2; changeBgColour2();  goto Menu;}
            //else if (KEY=='!') cout<<"\r"<<KeyHit_Cheak_Count<<"                          \t\t\t\t\t\t";
            else if ( KEY==13 || KEY==77 || KEY==32)   break;
            //else if (KEY==75) {goto Menu;}
            else if(KEY=='+' || KEY=='=') {Time_Delay+=10; if(Time_Delay<0) Time_Delay=0; if(Time_Delay>100) Time_Delay=100; cout<<"\rKeyHitDelay(ms): "<<Time_Delay<<"      ";}
            else if(KEY=='-' || KEY=='_') {Time_Delay-=10; if(Time_Delay<0) Time_Delay=0; if(Time_Delay>100) Time_Delay=100; cout<<"\rKeyHitDelay(ms): "<<Time_Delay<<"      ";}
            else if(KEY==80 ) { Mark++; if(Mark>10) Mark=0; goto Menu; Carriage Multi_Tabs_1 cout<<"\t\t         "<<Mark<<"      ";}
            else if(KEY==72 ) { Mark--; if(Mark<0) Mark=10; goto Menu; Carriage Multi_Tabs_1 cout<<"\t\t         "<<Mark<<"      ";}
            else if(KEY=='@' ){ cout<<"\r"<<Coder_Name;  /*printf("        SWITCH CASE NUMBER  : \t"); */}
            else if(KEY==8 || KEY==75 || KEY==71)   goto Menu;
//            else if (KEY=='g' && is_Continuous_Change_Color==false) is_Continuous_Change_Color=true;
//            else if (KEY=='g' && is_Continuous_Change_Color==true) is_Continuous_Change_Color= false;
            else if(KEY==32)   DisplayWorld();
            else if(KEY>=97 && KEY <=122           )   DisplayAdvise();
            else if(KEY>=32 && KEY <=126 && KEY!=75)   DisplayAdvise();
            else DisplayWorldView();

        }
    }
    clearScreen();

    switch (Mark){

    case 1:     //Tic Tac Toe (Man vs Computer - 3 Different Mode)

        while(1)
        {

            Multi_Tabs_4 cout << "\t       TIC TAC TOE   \n\n";
            Multi_Tabs_4 cout << "\t    [Man vs Computer]\n\n";

            cout << "  Press 'Left-Arrow-KEY'  to goto 'Back'\n";
            cout << "  Press 'HOME' or 'END'   to      'Exit'\n";


            NewLine Multi_Tabs_1  cout << "Choice Level";
            NewLine Multi_Tabs_2 cout << "Easy / Medium / Hard";
            NewLine Multi_Tabs_3 cout << "   Press - '1' / '2' / '3' : ";



            int Level;
            while(true)
            {
                this_thread::sleep_for(chrono::milliseconds(Time_Delay));

                if (kbhit())           //Control by arrow KEY
                {
                    KEY = _getch();      Manager();

                    if    (KEY>='1' && KEY<='3') {Level= KEY-'0'; break;}
                    if    (KEY == 'x' || KEY == 75 || KEY==71 || KEY==79) break;

                }
            }

            if(KEY=='x' || KEY == 75 || KEY==71 || KEY==79 ) goto Menu;

            clearScreen();

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
            Multi_Tabs_2 cout << "  Press 'i' for    'You'   \n";
            Multi_Tabs_2 cout << "  Press 'c' for 'Computer' \n";
            Multi_Tabs_2 cout << "  Press 't' for 'Tossing'\n";
            Multi_Tabs_2 cout << "   (Without Quatation) :\n\n";

            cout << "  Press 'Left-Arrow-KEY'    to goto 'Back'\n";
            cout << "  Press  <HOME> or <END>    to      'Exit'\n";

            char who;
            while(true)
            {
                this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                if (kbhit())           //Control by arrow KEY
                {
                    KEY = _getch();      Manager();

                    if    (KEY=='i' || KEY=='c' || KEY == 't' ) {who=KEY; break;}
                    if    (KEY=='I' || KEY=='C' || KEY == 'T' ) {who=KEY; break;}
                    if    (KEY==75 || KEY == 77 || KEY == 'x' ) break;
                    if    (KEY==71 || KEY==79 || KEY=='X') goto Menu;

                }
            }

            KEY= tolower(KEY);
            who=KEY;

            if(KEY=='i' || KEY=='c')    goto TTT_re;
            if(KEY=='k') {clearScreen(); continue;}
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
            clearScreen();

            int i, Me= 0, Computer= 0, Time= 0, Win_I= 0, Win_Com= 0, Call, con=0;
            char  Index_Data[11]; //'who' uses for who play first & Index_Data[10] contains Data which Index fill up or Not
            char Index_Symbol[11];    //Box-Symbol string (show 'x', 'o', ' ')

            for(i=0; i<= 9; i++)
            {
                Index_Data[i]= 0;
            }

            Print_Loop_ttt_vsc:             //Print_Update

                Multi_Tabs_4 cout << "\t       TIC TAC TOE   \n\n";
                Multi_Tabs_4 cout << "\t    [Man vs Computer]\n\n";
                if      (Level== 1) {Multi_Tabs_1 cout << "EASY LEVEL\n"; }
                else if (Level== 2) {Multi_Tabs_1 cout << "MEDIUM LEVEL\n"; }
                else                {Multi_Tabs_1 cout << "HARD LEVEL\n"; }
                NewLine
                for(iGlobal=0;iGlobal<TabNumber-2;iGlobal++) tab
                cout << "[Everytime Press 'Any Integer Number' from '1' to '9' For Push Your Symbol in the Box] " << endl << endl;

                Index_Data[Me]= 1;
                Index_Data[Computer]= 2;

                for(i= 0; i<= 9; i++)
                {
                    if(Index_Data[i]== 0) Index_Symbol[i]= ' ';     //Unfilled
                    if(Index_Data[i]== 1) Index_Symbol[i]= 'x';     //Filled by You
                    if(Index_Data[i]== 2) Index_Symbol[i]= 'o';     //Filled by Computer

                }

                TTT_Index_Instruction();

                for(i=1;i<=9;i++)  // Printing Loop
                {
                    /** changeTextColour(); */
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
                    Time++;                //kotota ghor fill up holo- seta count kora hocche

                    ReCall_Me:

                        //Multi_Tabs_2 cout << "Your Choice   :\t";

                        while(true)
                        {
                            hideCursor();
                            this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                            if (kbhit())           //Control by arrow KEY
                            {
                                KEY = _getch();      Manager();

                                if    (KEY>='1' && KEY<='9') {Me= KEY-'0'; break;}
                                if    (KEY==71 || KEY==79)      goto Menu;
                            }
                        }

//                        if(Me<=0 || Me>= 10)
//                        {NewLine Multi_Tabs_1 cout << "Wrong Input"; goto ReCall_Me; }              // jodi wrong chal dewa hoy, then- game close hobe


                        if(Index_Data[Me]  !=  0)                       //jodi ghor-tite already chal dewa hoye thake
                        {/*NewLine Multi_Tabs_1 cout << "Already Exist\n\n";*/ goto ReCall_Me; }   //tobe accept hobe na, punoray chal dewa lagbe

                    Index_Data[Me]= 1;//Index-tate Amar chal input holo

                    clearScreen();
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

                    if(Level== 1)                ///Easy mode : Computer sob chal randamly dibe
                    {
                        while(1)
                            {
                                Computer= Randam_Func_09(Call);
                                if(Index_Data[Computer]== 0 ) break;
                            }
                    }

                    else if(Level== 2)       ///Medium Level : kichuta buddhimotta apply korbe computer, bad computer a bishesh koushole fade fele harano somvob
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

//                        else if(Time== 2 && ( Index_Data [1]== 1 || Index_Data [3]== 1 || Index_Data [7]== 1 || Index_Data [9]== 1  )) { Computer= 5; }

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
                            /* srand(time(NULL)); */
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
                                Computer= Randam_Func_09(Call);
                                if(Index_Data[Computer]== 0 ) break;
                            }
                        }

                    }


                    if (Index_Data[Computer]==0) Index_Data[Computer]= 2; //Input of Computer (computer er chal dewa)
                    else                         {Time--; goto Com;}      // jodi Computer kono Filled ghore chal dey tahole chal hobe na & Computer abar chalbe

//                    Multi_Tabs_2 cout <<  "Computer Chose :\t" << Computer << endl << endl;  //Output Computer Choice

                    clearScreen();

                    goto Print_Loop_ttt_vsc;    //Print Update Result
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
            else                  goto Menu;
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

            Multi_Tabs_1 cout << "TIC TAC TOE\n";
            Multi_Tabs_1 cout << "[Man vs Man]\n\n";


            //ke age chalbe Player '1' na '2' naki Toss
            Multi_Tabs_2 cout<<"  Who Play First?\n";
            Multi_Tabs_2 cout<<" ('Player-1'/'Player-2')\n\n";
            Multi_Tabs_2 cout << "  Press '1' for 'Player 1'   \n";
            Multi_Tabs_2 cout << "  Press '2' for 'Player 2' \n";
            Multi_Tabs_2 cout << "  Press '0' for 'Tossing'\n";
            Multi_Tabs_2 cout << "  Press 'x' for 'Exit'\n";
            Multi_Tabs_2 cout << "   (Without Quatation) :\n\n";
            Multi_Tabs_1  cout<<"   ";

            char Who;
            while(true)
            {
                if (kbhit())           //Control by arrow KEY
                {
                    KEY = _getch();      Manager();

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

            clearScreen();

            for(i= 0; i<= 9; i++)
            {
                Index_Data[i]= 0;
            }

            Print_Loop_ttt_vs_man:   //Print_Loop

                clearScreen();

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
                cout << "[Everytime Press 'Any Intizer Number' from '1' to '9' For Push Your Symbol in the Box] " << endl << endl;

                TTT_Index_Instruction();

                for(i=1;i<=9;i++)
                {
                    /** changeTextColour(); */
                   cout<<" "<<Index_Symbol[i];
                   if (i==9) {NewLine Multi_Tabs_1 cout<<"   |   |   \n"; NewLine NewLine}
                   else if(i%3 == 0 ) { NewLine Multi_Tabs_1  cout <<"___|___|___\n"; Multi_Tabs_1  }
                   else   cout<<" |";
                }

                NewLine NewLine

                if(Time== 0 && who== 2) goto Player2;
                if(Time== 0) ;
                else if(Time%2== 1 && who== 2 || Time%2== 0 && who != 2) goto Back_2;
                else goto Back_1;

                while(1)
                {
                    Player1:

                        Time++;
                        cout << "Player-1 :   ";

                        Recall_Player1:

                            if (kbhit())           //Control by arrow KEY
                            {
                                this_thread::sleep_for(chrono::milliseconds(Time_Delay));

                                KEY = _getch();      Manager();

                                if      (KEY>='1' && KEY<='9') Player_1 = KEY-'0';
                                else if (KEY==71 || KEY==79) goto Menu;
                                else goto Recall_Player1;

                            }

                            else goto Recall_Player1;

                            if(Index_Data[Player_1] != 0)
                            {
//                                NewLine cout << "Already Exist\n\n";
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
                        cout << "Player-2 :   ";
                        Recall_Player2://

                            if (kbhit())           //Control by arrow KEY
                            {
                                this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                                KEY = _getch();      Manager();

                                if      (KEY>='1' && KEY<='9') Player_2 = KEY-'0';
                                else if    (KEY==71 || KEY==79) goto Menu;
                                else goto Recall_Player2;

                            }

                            else goto Recall_Player2;

                            if(Index_Data[Player_2] != 0)
                            {
//                                    NewLine cout << "Already Exist\n\n";
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
            NewLine Multi_Tabs_3

            Sound
            if(Win_1>0)         cout << "Congratulation! Player-1 is Winner.\n";
            else if(Win_2>0)    cout << "Congratulation! Player-2 is Winner.\n";
            else                cout << "\t\tMatch Drawn\n";

            Again = Dicission (Kall);
            if(Again!= '1') goto Menu;

        }

        break;


    case 3:     //SNAKE-CLASSIC
    case 4:

/*
        Here our target is eat more fruit to Increase Score. The Snake's Size
        is increasing according to eat fruit.
        If Snake Bites its Body then the Game is Over. If Score=100, then the Game will be
        Complete.
        Everytime We use 8/2/4/6/7/9/1/3 for moving to up/down/left/right/cross-move
*/
        while(1)
        {
            if(Mark==3)
            {
                Multi_Tabs_1 cout << "SNAKE GAME [Classic](10x10)\n\n";
                cout<<"#Instruction : Here your target is eat more Fruit to Increase Score. The Snake's Size is increasing according to eat Fruit. If the Snake Bites its Body then the Game is Over.If Score=100, then the Game will be Completed. You should Control the Snake by using Arrow KEY\n\n";
            }

            if(Mark==4)
            {
                Multi_Tabs_1 cout << "SNAKE GAME [Box](10x10)\n\n";
                cout<<"#Instruction : Here your target is eat more Fruit to Increase Score. The Snake's Size is increasing according to eat Fruit. If the Snake Bites its Body or Border then the Game is Over.If Score=100,\
                then the Game will be Completed. You should use Arrow KEYs to control the Snake.\n\n";
            }

            int Level;
            bool DoubleSnake = false;
            Multi_Tabs_1 cout<< "SPEED (1-8) :  ";

            while(true)
            {
                this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                if (kbhit())           //Control by arrow KEY
                {
                    KEY = _getch();      Manager();

                    if    (KEY>='1' && KEY<='8') {Level= KEY-'0'; break;}
                    if    (KEY=='x' || KEY==75)  goto Menu;

                }
            }

            int delay = 0;
//            delay = 450-50*Level; //Speed

            while(1)
            {
                clearScreen();
                int Tempo=0;
                bool Finish=false, is_Fruit_in_Blank_Space = true, BonusFlag=false;
                int Fruit, Bonus=0, Score = 0,Point= 0,temp,Call,Change,i,FruitCount=0, BonusCount=0;
                int Snake_Head=46, Snake_Body[108] = {0}; //0,1-100,Primary body Size(5)+Extra some for avoid silly risk
                char Move='6';
                char PlayGround[109]; //0,1-100,NULL+Primary body Size(5)+Extra some for avoid silly risk
                temp++;

                Fruit  =  Randam_Function_100(Call);

                //First Declaration of Snake Body (below)
                Snake_Body[1]  =  Snake_Head -1;
                Snake_Body[2]  =  Snake_Head -2;
                Snake_Body[3]  =  Snake_Head -3;

                while(1)
                {
                    hideCursor();
                    gotoxy(0,0);
                    /** changeTextColour(); */

                    while(1)                  //jate fruit snake er body borabor na ase
                    {
                        Change++;
                        for(i = 3+Score; i>0; i--)
                        {
                            if(Fruit == Snake_Body[i]) {is_Fruit_in_Blank_Space = false;  break; }
                        }
                        if((is_Fruit_in_Blank_Space == false || Fruit == Snake_Head) && Change <= 100 ) //Chnge variable ta NewLinear karon holo jodi snake body r size full arear soman hoy orthat fruit dewar moto kono jayga na thake tahole snake body borabor porbe , eta na dile oi muhurte program continiously choltei thakto, susthu vabe game complete hoto na
                        {
                            is_Fruit_in_Blank_Space = true;
                            Fruit++;
                            Fruit = 1+Fruit %100; //jate 100 overtek na kore
                        }

                        else break;
                    }

                    Change=0;

                    while(1)                  //jate fruit snake er body borabor na ase
                    {
                        if(BonusFlag==false) break;
                        Change++;
                        for(i = 3+Score; i>0; i--)
                        {
                            if(Bonus == Snake_Body[i]) {is_Fruit_in_Blank_Space = false;  break; }
                        }
                        if((is_Fruit_in_Blank_Space == false || Bonus == Snake_Head) && Change <= 100 ) //Chnge variable ta NewLinear karon holo jodi snake body r size full arear soman hoy orthat fruit dewar moto kono jayga na thake tahole snake body borabor porbe , eta na dile oi muhurte program continiously choltei thakto, susthu vabe game complete hoto na
                        {
                            is_Fruit_in_Blank_Space = true;
                            Bonus++;
                            Bonus = 1+Bonus %100; //jate 100 overtek na kore
                        }

                        else break;
                    }

                    Change=0;

                    for(i = 0; i <= 100; i++)
                    {
                        PlayGround [i] = ' ' ;
                    }


                    if(is_Premium)PlayGround [Bonus] = temp%2+5;
                    else          PlayGround [Bonus] = '$' - temp%2;

                    PlayGround [Fruit] = temp%2+42; //Fruit Symbol (*,+)

                    if(is_Premium) PlayGround [Snake_Head] = 2;    //Snake Head Symbol (Ascii 2)
                    else           PlayGround [Snake_Head] = '@';

                    for(i = Score+3; i>0; i--)
                    {
                        if     (!is_Premium)  PlayGround [Snake_Body[i]]  =  'o';
                        else if(!DoubleSnake) PlayGround [Snake_Body[i]]  =  254; //Snake Body Symbol
                        else if( DoubleSnake) PlayGround [Snake_Body[i]]  =  219; //Snake Body Symbol
                    }
                    if(is_Premium) PlayGround [Snake_Body[Score+3]] = 4; //Snake Tail Symbol
                    else           PlayGround [Snake_Body[Score+3]] = '-';

                    if(Mark==3) {Multi_Tabs_1 cout << "SNAKE GAME [Classic](10x10)\n\n";}
                    if(Mark==4) {Multi_Tabs_1 cout << "SNAKE GAME [Box](10x10)\n\n";}

                    Multi_Tabs_1 cout << "      Level : "<<Level<<endl;

                    NewLine;NewLine;
                    Multi_Tabs_1;  Border_Sign;  Multiple_Border_Sign;  NewLine;  //Border
                    Multi_Tabs_1;  Border_Sign;

                    for(i = 1; i <= 100; i++)
                    {
                       /** changeTextColour(); */
                       if(!DoubleSnake) cout<<PlayGround [i]<<" ";           // show Update resulte of Game-PlayGround
                       if( DoubleSnake) cout<<PlayGround [i]<<PlayGround[i];           // show Update resulte of Game-PlayGround
                       if(i%10 == 0) {Border_Sign;  NewLine;  Multi_Tabs_1;  Border_Sign;  }
                    }

                    Multiple_Border_Sign NewLine NewLine

                    Multi_Tabs_1 show_Point      //Show Score
                    Multi_Tabs_1 cout<<"    Fruit Count : "<<FruitCount<<endl;
                    Multi_Tabs_1 cout<<"    Bonus Count : "<<BonusCount<<endl;


                    this_thread::sleep_for(chrono::milliseconds(delay));    //Time delay for Update Printing

                    if(Mark==3) if(Finish) break; //snake nijeke bite korle game over
                    if(Mark==4) if(Snake_Head > 100 || Snake_Head<= 0 || Finish== true) break;

                    temp++; Change = 0;

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

                            else if(KEY=='0' || KEY=='5' || KEY==32 || KEY==13) getch();

                            else if(KEY=='x'  )  break;

                            else if(KEY=='i') DoubleSnake=false;
                            else if(KEY=='o') DoubleSnake=true;

                            else { Manager(); continue;}
                    }

//                     delay = 450-50*Level; ///Speed  ///You can off it

                     if(Level==1) delay=500;
                     if(Level==2) delay=300;
                     if(Level==3) delay=200;
                     if(Level==4) delay=100;
                     if(Level==5) delay=50;
                     if(Level==6) delay=25;
                     if(Level==7) delay=10;
                     if(Level==8) delay=0;

                    ///if(Move == '5' || Move == '0') continue; //no change

                    for(i = 3+Score; i>0; i--)
                    {
                        Snake_Body[i] =  Snake_Body[i-1];  //Snake er body possition update
                    }
                    Snake_Body[1] =  Snake_Head;

                    if(Mark==3)
                    {
                        //to move to up / down / left / right (below) - (According to KEY-board Numarical Pads)
                        if(Move == '6') {Snake_Head++;     /** to move Right */  if(Snake_Head%10 == 1) Snake_Head -= 10; /**Dan dike ber hoye gele oi borabor Bam dik diye asbe */ }
                        if(Move == '4') {Snake_Head--;     /** to move Down  */  if(Snake_Head%10 == 0) Snake_Head += 10; /**Bam dike ber hoye gele oi borabor Dan dik diye asbe */}
                        if(Move == '2') {Snake_Head += 10; /** to move Down  */   }
                        if(Move == '8') {Snake_Head -= 10; /** to move Up    */   }

                        if(Snake_Head > 100) Snake_Head -= 100; //box er ekdik diye snake ber hoye gele, oi borabor biporit dik theke snake fire asbe.
                        if(Snake_Head <=  0) Snake_Head += 100; // " " "

                    }

                    if(Mark==4)
                    {
                        if(Move== '6') {Snake_Head++;      if(Snake_Head%10== 1)  { Snake_Head= 0; continue; }}      //Box e touch lagle Game over
                        if(Move== '4') {Snake_Head--;      if(Snake_Head%10== 0)  { Snake_Head= 0; continue; }}      // " " "
                        if(Move== '8') {Snake_Head -= 10;    }
                        if(Move== '2') {Snake_Head += 10;    }

                        if(Snake_Head > 100) continue;  //Box e touch lagle Game over
                        if(Snake_Head <=  0) continue;  // " " "
                    }


                    for(i = 3+Score; i>0; i--)
                    {
                        if(Snake_Head == Snake_Body[i]) { Finish = true; continue; } //jodi Snake nijeke Bite kore, then game over
                    }

                    if(Snake_Head == Fruit)         //Snake Fruit eat korar sathe sathe -
                    {
                        Score++;
                        Point++;
                        FruitCount++;
                        if(Score == 97) Point += 1000; //Highest point 100 korar jonno;   //ekhane 3 holo snake er initial body size (not so necessary)
                        Sound
                        if(Score%5==0 && Score!=0) {BonusFlag=true; Tempo= 0; Bonus = Randam_Function_100(Call); Sound;}                     //-Sound hobe
                        Fruit =  Randam_Function_100(Call);     // -fruit er possition change hobe

                    }

                    Tempo++;
                    if(Tempo>25) {Bonus=0; BonusFlag=false;}


                    if(Snake_Head == Bonus)         //Snake Fruit eat korar sathe sathe -
                    {
                                            //-Score barbe
                        Sound
                        Point += 2*(30-Tempo);
                        Bonus=0;
                        BonusFlag=false;
                        BonusCount++;

                    }

                }


                Sound;

                if(Mark==4)
                {
                    if  (Finish)    { NewLine NewLine Multi_Tabs_1  cout << "       TOUCH BODY!";  }
                    else            { NewLine NewLine Multi_Tabs_1  cout << "       TOUCH BORDER!";}

                }
                NewLine Multi_Tabs_1 cout<<"\tGame Over!"<<endl;  NewLine

                if(Score >= 100)         //if snake size is equal to playground size
                {
                                              //Smile Sign
                    Multi_Tabs_1 cout<< "\tCongratulation!\n";
                    Multi_Tabs_1 cout<<"\tLevel Complete!";
                    NewLine NewLine
                }

                Again = Dicission_snake (Kall);
                if      (Again== '2') continue;
                else if (Again== '1') break;
                else                  goto Menu;

            }
        }
        break;

    case 5: //Ludo Snake-Ladder (vs Computer)

    /*
          Here There are 2 Player (I & Computer). Both Target is to reach 100.
          Who Reach to 100 Firstly, He is Winner.
          Every Time We Hit Dice. & The Dice Give us Value from 1 to 6.
          Ladder Help us to Increase our Possition & Snake Decrease our Possition.
    */

        while(true)
        {
            NewLine Multi_Tabs_1 cout << " LUDO SNAKE-LADDER GAME"; NewLine NewLine
            cout<<"#Instruction : Here There are 2 Player (You & Computer) are playing. Both Target is to reach 100. Every Time You should Hit Dice & The Dice Give you Value from 1 to 6. Ladder Help us to Increase Your Possition & Snake Decrease Your Possition. The Player, Who reach to 100 first, He is Winner. To Hit Dice Press Any-KEY Everytime.\n\n\n";

            int You= 0, Com= 0;
            int Dice, i, temp= 0;
            bool x= true;
            NewLine Multi_Tabs_1 cout << "Press Any KEY on Everytime \n\n";
            Sound

            while(true)
            {
                getch();

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
        break;


    case 6: //Ludo Snake-Ladder (Multiplayer)
/*
      Here There are multiple Players can Play. Everyone's Target is to reach 100.
      Who Reach to 100 Firstest, He is Winner.
      Every Time We Hit Dice. & The Dice Give us Value from 1 to 6.
      Ladder Help us to Increase our Possition & Snake Decrease our Possition.
*/
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

                NewLine Multi_Tabs_2 cout << "     Press Any KEY on Everytime \n\n";
                Sound

                int Board[Number_of_Player+1]= {0}, Temp= 0;
                int Dice, i;
                bool x= true;

                while(1)
                {
                    //getch();
//                    Temp += Number_of_Player*(Temp+1)+1; //not so necessary, you can also change 'c' differently
//                    Temp= Temp%99; //Minimized size, not so necessary, you can also change 'c' differently

                    for(i= 1; i<= Number_of_Player; i++)
                    {
//                        Temp += 5; //not so necessary, you can also change 'c' differently
                        getch();
                        /** changeTextColour(); */
                        ///* srand(time(NULL)); */

                            Dice= rand()%6; //just for different value of d in same time also, you can also change it differently but '%6' is must nedded
                            Dice++; //(0-5)-->(1-6)
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
        break;


    case 7:
    case 8:
        while(true)
        {
            Multi_Tabs_1 cout << "PACMAN GAME (10x10)\n\n";
            cout << "#Instruction : Here Pacman's Target is Eat All Fruit in the Box and Save Himself from Ghost. Ghost is Always try to catch Pacman. If Ghost Catch Pacman then Pacman's Life will Decreased. Use Arrow KEYs for Moving. Pacman has 3 Life. If Pacman lost his all life then Game is over. If PacMan Eat all fruit in the Box then Level will be Completed.\n\n";

            int Level;
            cout<< "SPEED (1-8) :  ";
            while(true)
            {
                this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                if (kbhit())           //Control by arrow KEY
                {
                    KEY = _getch();      Manager();

                    if    (KEY>='1' && KEY<='8') {Level= KEY-'0'; break;}
                    if    (KEY=='x' || KEY==75)  goto Menu;

                }
            }


            int delay = 0 ;
//            delay = 450-50*Level; //Speed

            while(true)
            {
                bool Temp= true;
                int Score = 0,i,j,x = 0,Number_of_Enemy=4, Life=3;
                int PacMan,Enemy[Number_of_Enemy];
                char Move;
                char PlayGround[111],Fruit[111];                    /// Playground Size 10*10=100 (0-99) + extra 10(just for avoiding silly risk

                for(i = 0; i < 100; i++)                            ///Initially sob gulo ghorei dot dekhabe
                {
                    Fruit[i]=1;                                     ///'1' indicate korse oi possition a fruit ache
                }

            pac_start:    ///if Pacman Lost his a Life then Program Start from here

                if(Mark==7)
                {
                   Number_of_Enemy=1;
                   PacMan,Enemy[Number_of_Enemy];
                   Enemy[0]=0;
                   PacMan = 99;
                }

                if(Mark==8)
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
                clearScreen();

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

                    this_thread::sleep_for(chrono::milliseconds(delay));


                    if(Life == 0)       break;              ///Remaining Life '0' hole Game Over
                    if(Score == 100)    break;              ///Sob fruit gulo khele Game Over & Highest Score hobe
                    if(Temp == false)      goto pac_start;     ///jodi pacman er life kome jay, tobe sobar possition reform hobe

                    if (kbhit())
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

                            else if(KEY=='0' || KEY=='5' || KEY==32 || KEY==13) getch();

                            else if(KEY=='+' || KEY=='=') {Level++; if(Level==9) Level--;}
                            else if(KEY=='-' || KEY=='_') {Level--; if(Level==0)  Level++;}

                            else if(KEY=='x'  )  break;

                            else {Manager(); continue;}
                    }

                     if(Level==1) delay=500;
                     if(Level==2) delay=300;
                     if(Level==3) delay=200;
                     if(Level==4) delay=100;
                     if(Level==5) delay=50;
                     if(Level==6) delay=25;
                     if(Level==7) delay=10;
                     if(Level==8) delay=0;

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
                        if(PacMan == Enemy[i] )     /// jodi Ghost Pacman er body touch kore-
                        {
                            Temp = false;
                            Life --;                /// -tobe Life kome jabe
                            Sound                   /// Sound hobe
                            break;
                        }
                    }
                }

                if(Life==0)
                {
                    Sound; NewLine Multi_Tabs_1
                    cout<<"\tGame Over!"; NewLine Multi_Tabs_1
                    cout<<"\tScore : "<<Score<<endl;  NewLine
                }

                if(Score == 100)
                {
                    Sound
                    Multi_Tabs_1 cout<< "\tCongratulation!\n";
                    Multi_Tabs_1 cout<<"\tLevel Complete!"; //100 is highest score , because there are 100 fruit in the ground
                    NewLine NewLine
                }

                Again = Dicission_snake (Kall);
                if      (Again== '2') continue;
                else if (Again== '1') break;
                else                  goto Menu;
            }
        }


    case 9: //Sudoku (Fixed Given Value)

/*
        Here We should Fill up All of the Blank Space properly (according to
        Sudoku Rules.)
*/
        while(true)
        {
            Multi_Tabs_1 cout << "\tSUDOKU GAME\n\n\n";
            cout<<"#Instruction : Here You should Fill Up All of the Blank Space Properly (According to Sudoku Rules).\n\n\Here ('*' Sign Before Number) Indicates Current Index, ('`' sign After Number) indicates Your Filled Index. To Change Index Possition Press <Arrow Keys: Left/Right/Up/Down>,   To insert value into the Index: Select Index Possition, then input the value < From 1 to 9>. If You want to Remove Inputed Value Press '0'. You can't change the Given Value. If you fill up all the blank space properly, then the level will be completed & You get Congratulation. Otherwise Game will be Running. But if you want to close the program : Press <Capital 'X'> \n\n\n";
            Multi_Tabs_3 cout << "You should Fill Up All The Empty(Dot Sign) Index by Inserting Proper Value\n\n";
            int Sudoku[101]= {0}, cnt, row=0, col=0, Index=11, Value=0, i, j, k;  //Sudoku holo Main Array jeti sokol index Value contain korbe, etake 2D array hisebeo NewLine a jaito but ami neini
            bool Temp[101]={false}, Marker[101] = {false};   // ei string-tar kaj holo, jate given index gulor value ami poriborton korte na pari.
            Marker [Index] = true;

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
//            Multi_Tabs_3 cout << "You should Fill Up All The Empty(Dot Sign) Index by Inserting Proper Value\n\n";
            NewLine NewLine

            while(true)
            {
                bool flag= true;

                cout<<"\r";

                Multi_Tabs_1 cout << "Enter Value of Marked Index";


                while(true)
                {
                    this_thread::sleep_for(chrono::milliseconds(Time_Delay));

                    if (kbhit())           //Control by arrow KEY
                    {
                        KEY = _getch();      Manager();

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

//                    Index=10*(row+1)+(col+1);
//                    Marker[Index] = true;
                }

                Index=10*(row+1)+(col+1);
                Marker[Index] = true;
                if    (!(KEY>='0' && KEY<='9')) {flag= false;   goto sudko;}

                if(Temp[Index]) {/**cout << "\r\t\t\t\t\tIndex[" << row << "][" << col << "]\t  = ";cout << "Not Changeable\n\n"; */ flag = false; goto sudko; }  //Given Value gulo Change kora jabe na
                //if(row==0 || col==0) {cout << "Index[" << row << "][" << col << "]\t  = ";cout << "ERROR INDEX!\n\n"; continue; }

//                if(Value<0) Value= -Value;
//                if(Value>9) Value= Value%10; //ei 2 line dewa khub important chilo na, tao diyechi ejonno je jate jekono value dile thikmoto Input hoy

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
                clearScreen();
                Multi_Tabs_1 cout << "\tSUDOKU GAME\n\n\n";
                cout<<"#Instruction: Here You should Fill Up All of the Blank Space Properly (According to Sudoku Rules).\n\n\To insert value in the Index, select row(1-9) & column(1-9) number of the Index, then input the value. You can't change the Given Value. If you fill up all the blank space properly, then the level will be completed & You get Congratulation. Otherwise Game will be Running. But if you want to close the program : Press 'x' \n\n\n";
                Multi_Tabs_3 cout << "You should Fill Up All The Empty(Dot Sign) Index by Inserting Proper Value.\n\n";
                NewLine Multi_Tabs_1

                //Print the Sudoku Matrix(Below)
                for(i= 11; i<100; i++)
                {
                    /** changeTextColour(); */
////                    cout << Sudoku[i] << "  ";
                    if      (Index==i) cout<<"*";
                    if      (Sudoku[i]== 0)            printf("%c  ", Sudoku[i]+'.'); //'0' use korle Empty Index gulo bujhte osubidha hoy, tai '.' use korechi
                    else if (Temp  [i]== 0)            printf("%c` ", Sudoku[i]+'0');
                    else                               printf("%c  ", Sudoku[i]+'0');
                    if((i%10)% 3== 0) cout << " ";
                    if((i/10)% 3== 0 && i%10== 9) {NewLine  Multi_Tabs_1}
                    if(i%10== 9) {i++; NewLine  Multi_Tabs_1}

                }

                cout << "\n\n";
//                Multi_Tabs_3 cout << "You should Fill Up All The Empty(Dot Sign) Index by Inserting Proper Value\n\n";

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

    case 0:

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

                        Multi_Tabs_1  cout<<"  Shooting Game\n\n";


                        Multi_Tabs_3 cout<<"Diffculty (Enter a Little Positive Intizer Number)  =  ";
                        cin>>Diffc ;
                        if(Diffc <0) goto Menu;

                        Multi_Tabs_3 cout<<"BULLET    (    Enter Number of Bullet with You   )  =  ";
                        cin>>Bulet;

                        int Enimi = ceil(Bulet/1.0/(Diffc +1));  // avarage luck

                        Multi_Tabs_3 cout<<"TARGATED ENEMY TO KILL                            =  "<<Enimi<<endl;

                        cout<<"\nEverytime Press Any KEY for shooting Bullet: \n\n";


                        for(int i=1;i<=Bulet;i++)
                        {
                            /* srand(time(NULL)); */
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
                            "\t   Targeted Enemy Left  : "<< Enimi-Kil <<endl;

                        }

                        NewLine Multi_Tabs_1
                        cout<<"Total Kill = "<<Kil<<endl;

                        NewLine Multi_Tabs_3
                        if(Kil> Enimi) cout<<"Congratulations! You Kill more than Target.\n";
                        if(Kil==Enimi) cout<<"Congratulations! You Kill  Equal to Target.\n";
                        if(Kil< Enimi) cout<<"Alas! You Kill Less than Target.\n";

                        Again = Dicission_Mini (Kall);
                        if      (Again== '1') ;
                        else if (Again== '2') goto MiniMenu;
                        else                  goto Menu;

                    }

                case 2:
                    while(1)
                    {
                        Multi_Tabs_1 cout<<"   Toss Game\n\n";
                        Multi_Tabs_4 cout<<"\tPress 'H' to chose Head\n";
                        Multi_Tabs_4 cout<<"\tPress 'T' to chose Tail\n";
                        Multi_Tabs_4 cout<<"\tPress 'x' to Close the game\n\n";

                        int win=0,lost=0;
                        while(1)
                        {
                            int n;
                            char you,com;
                            cout<<"Press 'H' or 'T' (without quatation)\t:\t";
                            while(true)
                            {
                                this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                                if (kbhit())           //Control by arrow KEY
                                {
                                    KEY = _getch();      Manager();

                                    if(KEY=='h' || KEY == 't' || KEY == 'x' || KEY==75) break;
                                    if(KEY=='H' || KEY == 'T' || KEY == 'X' || KEY==77) break;

                                }
                            }

                            clearScreen();
                            you=toupper(KEY);
                            if(you==75) goto Menu;
                            else if(you!='H' && you!= 'T') break;

                            /* srand(time(NULL)); */

                            n=rand()%2;
                            if(n==0) com='T';
                            else     com='H';

                            Multi_Tabs_1 cout<<"   Toss Game\n\n";
                            Multi_Tabs_4 cout<<"\tPress 'H' to chose Head\n";
                            Multi_Tabs_4 cout<<"\tPress 'T' to chose Tail\n";
                            Multi_Tabs_4 cout<<"\tPress 'x' to Close the game\n\n";



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

                        NewLine NewLine Multi_Tabs_1
                        if      (win>lost) cout<<"Congratulation!\n\t\t\t\t\tYou won More mach than Computer\n\n";
                        else if (win<lost) cout<<"    Sorry!     \n\t\t\t\t\tYou won Less match than Computer\n\n";
                        else               cout<<"    Drawn      \n\t\t\t\t\tYou won Equal mach than Computer\n\n";

                        Again = Dicission_Mini (Kall);
                        if      (Again== '1') ;
                        else if (Again== '2') goto MiniMenu;
                        else                  goto Menu;

                    }

                case 3:
                    while(1)
                    {
                        int Bulet,Kil=0,Shoot,Diffc,Temp=100 ;

                        Multi_Tabs_1  cout<<"  Battle Game\n\n";

                        Multi_Tabs_3 cout<<"Diffculty (Enter a Little Positive Intizer Number)  =  ";
                        cin>>Diffc ;
                        if(Diffc <0) goto Menu;

                        Multi_Tabs_3 cout<<"RPJ       (    Enter Number of Bullet with You   )  =  ";
                        cin>>Bulet;

                        int Enimi = ceil(Bulet/1.0/(Diffc +1));  // avarage luck

                        Multi_Tabs_3 cout<<"TARGATED TANK TO DESTROY                            =  "<<Enimi<<endl;

                        cout<<"\nEverytime Press Any KEY for shooting Bullet: \n\n";

                        for(int i=1;i<=Bulet;i++)
                        {

                            /* srand(time(NULL)); */
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
                            "\t   Targeted TANK Left  : "<< Enimi-Kil <<endl;

                        }

                        NewLine Multi_Tabs_1
                        cout<<"Total Brusted = "<<Kil<<endl;

                        NewLine Multi_Tabs_3
                        if(Kil> Enimi) cout<<"Congratulations! You Brust more than Target.\n";
                        if(Kil==Enimi) cout<<"Congratulations! You Brust  Equal to Target.\n";
                        if(Kil< Enimi) cout<<"Alas! You Brust Less than Target.\n";

                        Again = Dicission_Mini (Kall);
                        if      (Again== '1') ;
                        else if (Again== '2') goto MiniMenu;
                        else                  goto Menu;

                    }


                case 4:
                    while(1)
                    {
                        tabs cout<<"\tRock Paper Seissor Game\n\n";
                        tabs cout<<"\tPress 'R' to chose Rock\n";
                        tabs cout<<"\tPress 'P' to chose Paper\n";
                        tabs cout<<"\tPress 'Z' to chose Seissor\n";
                        tabs cout<<"\tPress 'X' to close the game\n\n";
                        int win=0,lost=0;

                        while(1)
                        {
                            int n;
                            Sound
                            char you,com;
                            cout<<"\nPress 'R' or 'P' or 'Z' (without quatation)\t:\t";
                            while(true)
                            {
                                this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                                if (kbhit())           //Control by arrow KEY
                                {
                                    KEY = _getch();      Manager();

                                    if(KEY=='r' || KEY == 'p' || KEY == 'z' || KEY == 'x' || KEY==75) break;
                                    if(KEY=='R' || KEY == 'P' || KEY == 'Z' || KEY == 'X' || KEY==77) break;

                                }
                            }

                            if(KEY==75) goto Menu;

                            you = toupper(KEY);
                            clearScreen();

                            if(you=='X' || you ==77) break;

                            n=rand()%3;
                            if     (n<1) com='R';
                            else if(n<2) com='P';
                            else         com='Z';

                            tabs cout<<"\tRock Paper Seissor Game\n\n";
                            tabs cout<<"\tPress 'R' to chose Rock\n";
                            tabs cout<<"\tPress 'P' to chose Paper\n";
                            tabs cout<<"\tPress 'Z' to chose Seissor\n";
                            tabs cout<<"\tPress 'X' to close the game\n\n";

                            NewLine
                            cout<<"Your    Choice         \t:\t"<<you<<endl;
                            cout<<"Computer Chose         \t:\t"<<com<<endl;

                            NewLine Multi_Tabs_1
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
                                clearScreen();
                                break;
                            }
                        }

                        tabs cout<<"\tRock Paper Seissor Game\n\n";
                        NewLine Multi_Tabs_2 cout<<"       Match Ended     ";
                        NewLine Multi_Tabs_2 cout<<"       Your Score= "<<win;
                        NewLine Multi_Tabs_2 cout<<"   & Computer's Score= "<<lost;

                        NewLine NewLine Multi_Tabs_1
                        if      (win>lost) cout<<"Congratulation!\n\t\t\t\t\tYou won More mach than Computer\n\n";
                        else if (win<lost) cout<<"    Sorry!     \n\t\t\t\t\tYou won Less match than Computer\n\n";
                        else               cout<<"    Drawn      \n\t\t\t\t\tYou won Equal mach than Computer\n\n";

                        Again = Dicission_Mini (Kall);
                        if      (Again== '1') ;
                        else if (Again== '2') goto MiniMenu;
                        else                  goto Menu;
                    }
                }
        }

    case 42:
    case 10:  //Head-Tail Type Cricket

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
                Multi_Tabs_3 cout<<"What do you want? Head / Tail? Press - '1' / '2'.\n\n";

                while(true)
                {
                    this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                    if (kbhit())           //Control by arrow KEY
                    {
                        KEY = _getch();  Manager();

                        if    (KEY=='1') {Your_Toss_Choise = 0; break;}
                        if    (KEY=='2') {Your_Toss_Choise = 1; break;}
                    }
                }

                Toss_Coin = rand()%2;

                if(Your_Toss_Choise == Toss_Coin)
                {
                    Multi_Tabs_2 cout<<"Congratulation! You won the Toss!\n\n";
                    Multi_Tabs_2 cout<<" Press '1' for  Batting First\n";
                    Multi_Tabs_2 cout<<" Press '2' for Fielding First\n";
                    NewLine

                    while(true)
                    {
                        this_thread::sleep_for(chrono::milliseconds(Time_Delay));
                        if (kbhit())           //Control by arrow KEY
                        {
                            KEY = _getch();  Manager();

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

            clearScreen();

            Multi_Tabs_1 cout << "    CRICKET      \n\n";
            Multi_Tabs_1 cout << char(2) << " " << Team_1 << "  vs  " << Team_2 << " " << char(2) <<endl<<endl;
            Multi_Tabs_1 cout<< Over_Total << " Over | " << Wicket_Total << " Wicket"<<endl<<endl<<endl;
            cout << "INTRODUCTION : \"Here Everytime you should Press 'Any KEY' from 0 to 6 to Bowling(in Bowling time) or to Hit the Ball(in Batting time)\". If You & Opportunate Team Select Same Number, then a Wicket is Fallen. Otherwise Hitted Value includes with Run. You should Play the Match in Limited Over & Limited Wickets. The Team Who get more Run, That is Winner. [To save time, You can Hit Multiple Ball in one-time by Press the digit Key At a Time.]\n\n";
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
                                    KEY = _getch(); Manager();

                                    if    (KEY>='0' && KEY<='6')                        { break;}
                                    if    (KEY=='x' || KEY=='X' || KEY==71 || KEY==79)   { goto Menu;}
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
                                    KEY = _getch();  Manager();

                                    if    (KEY>='0' && KEY<='6')                            { break;}
                                    if    (KEY=='x' || KEY=='X' || KEY==71 || KEY==79)       { goto Menu;}
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
                                    KEY = _getch();  Manager();

                                    if    (KEY>='0' && KEY<='6') { break;}
                                    if    (KEY=='x' || KEY=='X' || KEY==71 || KEY==79) {goto Menu;}
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
                                    KEY = _getch(); Manager();

                                    if    (KEY>='0' && KEY<='6')                            { break;}
                                    if    (KEY=='x' || KEY=='X' || KEY==71 || KEY==79)      {goto Menu;}
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

    default:
        Multi_Tabs_1  cout << " Program is Closed.\n\n";
        Multi_Tabs_2 cout << ""<<Coder_Name<<endl;
        Multi_Tabs_1  cout << " [ ALHAMDULILLAH ]\n";
        NewLine Multi_Tabs_1 cout << "Spacial Thanks to \n"; Multi_Tabs_4 cout<<"\tSharif Ahmed, Saminul Amin, Milon Miah "<<endl;
        NewLine

        getch();
//        clearScreen();
        Multi_Tabs_1 cout << " Jajakallahu Khairan.\n";
        Multi_Tabs_1 cout << "  See You Next Time.\n";
        getch();
//        clearScreen();
        cout<<"\n\nTotal KeyHit Cheak Time : "<<KeyHit_Cheak_Count;
        return 0;
    }
    goto Menu;
}

