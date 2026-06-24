//#include <bits/stdc++.h>

#include <iostream>    // cout, cin, endl, printf
#include <cstdlib>     // rand, srand, abs, system()
#include <ctime>       // time() — srand(time(0)) এর জন্য
#include <thread>      // this_thread::sleep_for
#include <chrono>      // chrono::milliseconds
#include <string>      // string
#include <algorithm>   // fill, min, max
#include <cmath>
#include <cstdio>

// Cross-platform layer: Windows / Linux / Mac / Android(Termux)

#if defined(_WIN32) || defined(_WIN64)
    #define PLATFORM_WINDOWS 1
    #include <windows.h>
    #include <conio.h>          // _getch(), kbhit() এমনিতেই আছে Windows এ
#else
    #define PLATFORM_POSIX 1    // Linux, Mac, Android/Termux সবার জন্য একই
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>

    // ── conio.h এর বদলে নিজস্ব kbhit() ──
    int kbhit()
    {
        struct termios oldt, newt;
        int oldf, ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
        fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        fcntl(STDIN_FILENO, F_SETFL, oldf);
        if (ch != EOF) { ungetc(ch, stdin); return 1; }
        return 0;
    }

    // ── conio.h এর বদলে নিজস্ব _getch() ──
    int _getch()
    {
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        newt.c_cc[VMIN]  = 1;
        newt.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        int ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }

    // Windows এ getch() নামটাও code এর কিছু জায়গায় ব্যবহার হয়েছে
    int getch() { return _getch(); }
#endif

#define HOME_KEY  1071
#define END_KEY   1079
#define LEFT_KEY  1075
#define RIGHT_KEY 1077
#define UP_KEY    1072
#define DOWN_KEY  1080
#define SPACE_KEY 32
#define ENTER_KEY 13
#define BACKSPACE_KEY 8
#define ESC_KEY 27


/// Tabs & Carriage_Return
#define tab cout<<" ";
#define tabs for (iGlobal=0;iGlobal<TabNumber;iGlobal++) tab
#define Multi_Tabs_1  tabs tab tab    //Likhagulo Middle Show korar jonno
#define Multi_Tabs_2 tabs tab cout << "";
#define Multi_Tabs_3 tabs cout << "";
#define Multi_Tabs_4 tabs
#define Carriage cout<<"\r";

///New-Line & Sound
#define NewLine cout << "\n";
#define Sound if(SoundFlag == true) cout << "\a";
//#define Auto_Change_Text_Color if (is_Continuous_Change_Color) changeTextColour();

#define Border_Sign          if(Marker==2) cout<<symbol(219); else if(!Snake_Boundary) {cout<<"."; if(!Joined_Single_Snake) cout<<" "; } else { cout<<symbol(219); if(!Joined_Single_Snake) cout<<symbol(219);};
#define Multiple_Border_Sign if(Marker==2) {for(int i=0;i<21;i++) cout<<symbol(219);} else if(!Snake_Boundary) { for(int i=0;i< Snake_Area_Column + 1; i++) Border_Sign }      else { for(int i=0;i<Snake_Area_Column +1;i++) Border_Sign }

#define show_Point  cout << "Score: " << (Level)*Point << "   " << endl << endl;
#define showScore   cout << "Score: " << Score << endl;
#define showLife    cout << " Life: " << Life << endl << endl;

using namespace std;

// Global Variables <below>
int Marker=1;
string Markered_Symbol, Design_Symbol;
int KEY;   // was 'char' — must be 'int' to hold the new safe HOME/END/Arrow-key values
string Coder_Name = "Coded by \'Tajmil Anwar Tamim\'";
int Time_Delay=10;   //time Delay in every KEY-hit.
int KeyHit_Cheak_Count=0;

int TabNumber=0,iGlobal=0;

bool SoundFlag  = true;
bool is_Premium = true;
bool is_Playing = false;
bool in_Windows = true;
//bool is_Continuous_Change_Color= false;

void Sleep (int _Time)
{
    this_thread::sleep_for(chrono::milliseconds(_Time));
}

void fontManager()
{
    #if defined(PLATFORM_WINDOWS)
        SetConsoleOutputCP(65001);
        SetConsoleCP(65001);

        // কিছু modern console (Windows Terminal / নতুন cmd.exe) raster
        // font না হলে CP437 glyph ঠিকভাবে আঁকে না। Raster font ("Terminal")
        // force করলে এই glyph গুলো guaranteed ভাবে আঁকা হয়।
        {
            CONSOLE_SCREEN_BUFFER_INFO csbi;
            GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
            int screenHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
            int screenWidth  = csbi.srWindow.Right - csbi.srWindow.Left + 1;

            DEVMODE dm = {};
            dm.dmSize = sizeof(dm);
            EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &dm);
            int pixelHeight = dm.dmPelsHeight;  // actual monitor pixel height
            int pixelWidth = dm.dmPelsWidth;  // actual monitor pixel height

//            cout<<screenHeight<<" "<<screenWidth<<" "<<pixelHeight<<" "<<pixelWidth; getch();

            CONSOLE_FONT_INFOEX cfi;
            cfi.cbSize = sizeof(cfi);
            cfi.nFont = 0;
            cfi.dwFontSize.X = 0;
            cfi.dwFontSize.Y = 16;
            cfi.FontFamily = FF_DONTCARE;
            cfi.FontWeight = FW_NORMAL;
//            wcscpy(cfi.FaceName, L"Terminal");   // raster font — CP437 glyph সাপোর্ট করে
            SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
        }
    #endif

    #if defined(PLATFORM_WINDOWS)
        Time_Delay=10;
        TabNumber=0;
        in_Windows = true;
//        Joined_Single_Snake=true;

    #else
        Time_Delay=10;
        TabNumber=0;
        in_Windows = false;

    #endif

}

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

// ─── Cross-platform colour: Windows attribute vs ANSI escape ─────
#if defined(PLATFORM_POSIX)
// Windows colour index → ANSI foreground / background code
static const int _ansi_fg[] = {30,34,32,36,31,35,33,37,90,94,92,96,91,95,93,97};
static const int _ansi_bg[] = {40,44,42,46,41,45,43,47,100,104,102,106,101,105,103,107};
#endif

// Function to set text color
void SetConsoleColor(ConsoleColor color) {
#if defined(PLATFORM_WINDOWS)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#else
    printf("\033[0;%dm", _ansi_fg[color]);
    fflush(stdout);
#endif
}

void SetConsoleColour(ConsoleColor textColor, ConsoleColor bgColor) {
#if defined(PLATFORM_WINDOWS)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgColor << 4) | textColor);
#else
    printf("\033[%d;%dm", _ansi_fg[textColor], _ansi_bg[bgColor]);
    fflush(stdout);
#endif
}

int ColorVar;


// Cross-platform symbol() helper:
//
// Windows console understands single-byte "extended ASCII" (CP437)
// codes like char(219)=full block, char(254)=small block,
// char(2)=smiley, char(4)=diamond — these display as graphics.
// Linux/Mac/Android terminals use UTF-8 and don't know CP437 at all,
// so the SAME byte values would show up broken (boxes/question marks).
// This function maps each Windows extended-ASCII code we use in the
// game to its UTF-8 equivalent on POSIX systems, while keeping the
// exact original single-char behaviour on Windows untouched.
// Returns std::string because a UTF-8 symbol can be multiple bytes.

std::string symbol(int windowsCode)
{
#if defined(PLATFORM_WINDOWS)
//    return std::string(1, (char)windowsCode);   // আগের মতোই — single raw byte
    switch (windowsCode)
    {
        case 219: return "\xe2\x96\x88";  // █
        case 254: return "\xe2\x96\xa0";  // ■
        case 176: return "\xe2\x96\x91";  // ░
        case 177: return "\xe2\x96\x92";  // ▒
        case 1:   return "\xe2\x98\xba";  // ☺
        case 2:   return "\xe2\x98\xbb";  // ☻
        case 3:   return "\xe2\x98\xbb";  // ☻
        case 4:   return "\xe2\x99\xa6";  // ♦
        case 5:   return "\xe2\x99\xa3";  // ♣
        case 6:   return "\xe2\x99\xa5";  // ♥
        case 251: return "\xe2\x88\x9a";  // √
        default:  return std::string(1, (char)windowsCode);
    }
#else
    switch (windowsCode)
    {
        case 219: return "\u2588";   // █  Full block      (Snake body - Double)
        case 254: return "\u25A0";   // ■  Small block      (Snake body)
        case 176: return "\u2591";   // ░  Light shade      (Bonus - Premium)
        case 177: return "\u2592";   // ▒  Medium shade     (Bonus - Premium, Step%2 hole)
        case 1:   return "\u263A";   // ☺  Smiley (black)   (PacMan)
        case 2:   return "\u263B";   // ☻  Smiley (white)   (Enemy / Snake Head / Markered_Symbol)
        case 3:   return "\u263B";   // ☻  Smiley (white)   (Enemy)
        case 4:   return "\u2666";   // ♦  Diamond          (Snake Tail)
        case 5:   return "\u2667";   //           (Bonus - Premium)
        case 6:   return "\u2668";   //           (Bonus - Premium)
        case 251: return "\u221A";   // √  Square root      (Markered_Symbol - non premium)
        default:  return std::string(1, (char)windowsCode);
    }
#endif
}

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
#if defined(PLATFORM_WINDOWS)
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    printf("\033[%d;%dH", y+1, x+1);   // ANSI: row;col (1-based)
    fflush(stdout);
#endif
}

void hideCursor() {
#if defined(PLATFORM_WINDOWS)
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
#else
    printf("\033[?25l");
    fflush(stdout);
#endif
}

void clearScreen() {
#if defined(PLATFORM_WINDOWS)

    system("cls");
//    COORD topLeft = {0, 0};
//    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
//    CONSOLE_SCREEN_BUFFER_INFO screen;
//    DWORD written;
//
//    GetConsoleScreenBufferInfo(console, &screen);
//    DWORD cells = screen.dwSize.X * screen.dwSize.Y;
//
//    FillConsoleOutputCharacterA(console, ' ', cells, topLeft, &written);
//    FillConsoleOutputAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
//    cells, topLeft, &written);
//    SetConsoleCursorPosition(console, topLeft);
#else
    printf("\033[2J\033[H");   // pura screen clear + cursor top-left e niye jay
    fflush(stdout);
#endif
}

int DisplayWorldView_Var=0;

void DisplayWorldView()
{
    DisplayWorldView_Var =  DisplayWorldView_Var % 10;

    if(DisplayWorldView_Var==0) cout<<"\r"<<"Pray For Gaza                  ";
    if(DisplayWorldView_Var==1) cout<<"\r"<<"Never Forget Them              ";
    if(DisplayWorldView_Var==2) cout<<"\r"<<"Pray For Gaza                  ";
    if(DisplayWorldView_Var==3) cout<<"\r"<<"Pray For Kashmir               ";
    if(DisplayWorldView_Var==4) cout<<"\r"<<"Pray For Uighur                ";
    if(DisplayWorldView_Var==5) cout<<"\r"<<"Pray For Arakan                ";
    if(DisplayWorldView_Var==6) cout<<"\r"<<"Pray For Yemen                 ";
    if(DisplayWorldView_Var==7) cout<<"\r"<<"Pray For Africa                ";
    if(DisplayWorldView_Var==8) cout<<"\r"<<"Pray For All Oppressed Peoples ";
    if(DisplayWorldView_Var==9) cout<<"\r"<<"Never Forget Them              ";

    DisplayWorldView_Var++;
    // if(TabNumber<4) cout<<"                    ";
}


void Instruction()
{
    clearScreen();
    cout<<"COMMON INSTRUCTIONS:\n\n";

    cout<< "Arrow/WASD Keys : Control(in Game)/Select(in Menu)\n";
    cout<< "Enter/Right: Enter Game\n\n";

    cout<<"' or ;  : Text Color (Black BG)\n";
    cout<<"\" or :  : Text Color (White BG)\n\n";
    cout<<"] or [  : BG Color (White Text)\n";
    cout<<"} or {  : BG Color (Black Text)\n\n";

     cout<<"\\ : Flash W/B\n";
     cout<<"| : Flash B/W\n\n";

    cout<<"+ : Decrease Speed\n";
    cout<<"- : Increase Speed\n\n";

    cout<< "< : Shift Left\n";
    cout<< "> : Shift Right\n\n";
    cout<< "` : Mute\n";
    cout<< "~ : UnMute\n\n";
    cout<< "p : Toggle PREMIUM/NORMAL\n\n";

    cout<<"f    : Refresh\n";
    cout<<"Home : Main Menu\n";
    cout<<"End  : Close\n\n";
}

void Snake_Instruction()
{
    cout<<"\nSNAKE INSTRUCTION:\nEat fruit to grow & increase score. Use Arrow/WASD keys.\n\nIn Playing:\n";

    Multi_Tabs_1 cout<<"Move Snake         : Arrow Keys / WASD\n";
    Multi_Tabs_1 cout<<"Pause              : Space\n";
    Multi_Tabs_1 cout<<"Change Snake Style : u/i/o/p\n";
    Multi_Tabs_1 cout<<"Shift PlayGround   : <,>\n";
    Multi_Tabs_1 cout<<"Change Color       : []{}';:  \n";
    Multi_Tabs_1 cout<<"Refresh Screen     : Enter\n";
    Multi_Tabs_1 cout<<"Quit the Game      : End/X\n\n";
    Multi_Tabs_1 cout<<"Back to Game       : Space/Enter\n\n";

    getch(); clearScreen();

}

int ReadKey()
{
    int k = _getch();

#if defined(PLATFORM_WINDOWS)

    if (k == 0 || k == 224)        // Windows extended-key prefix byte
    {
        int scan = _getch();        // the real scan code follows

        switch (scan)
        {
            case 72: return UP_KEY;
            case 80: return DOWN_KEY;
            case 75: return LEFT_KEY;
            case 77: return RIGHT_KEY;
            case 71: return HOME_KEY;
            case 79: return END_KEY;
            default: return 2000 + scan;   // Ins/Del/PgUp/PgDn/F-keys etc, also kept safely out of byte range
        }
    }

    return k;   // ordinary character — letters, digits, symbols — unchanged

#else
    // Linux/Mac/Android(Termux): Arrow/Home/End keys send a 3-byte
    // ANSI escape sequence: ESC(27) '[' (91) <code>
    // e.g. Up = 27,91,65   Down = 27,91,66
    //      Right = 27,91,67  Left = 27,91,68
    //      Home = 27,91,72  End = 27,91,70   (also 27,91,49,126 / 27,91,52,126 on some terminals)

    if (k == ESC_KEY)
    {
        if (!kbhit()) return ESC_KEY;     // shudhu ESC chapa hoyeche, kono sequence na

        int second = _getch();
        if (second != '[' && second != 'O')   // ekti normal ESC sequence na hole ferot dao
            return ESC_KEY;

        int code = _getch();

        switch (code)
        {
            case 65: return UP_KEY;       // ESC [ A
            case 66: return DOWN_KEY;     // ESC [ B
            case 67: return RIGHT_KEY;    // ESC [ C
            case 68: return LEFT_KEY;     // ESC [ D
            case 72: return HOME_KEY;     // ESC [ H
            case 70: return END_KEY;      // ESC [ F

            // কিছু terminal এ Home/End/Ins/Del/PgUp/PgDn একটা digit + '~' আকারে আসে
            case '1': case '7':
                if (kbhit()) { int t=_getch(); if(t=='~') return HOME_KEY; }
                return HOME_KEY;
            case '4': case '8':
                if (kbhit()) { int t=_getch(); if(t=='~') return END_KEY; }
                return END_KEY;
            case '2':  // Insert: 27,91,2,126
                if (kbhit()) { int t=_getch(); if(t=='~') return 2002; }
                return 2002;
            case '3':  // Delete: 27,91,3,126
                if (kbhit()) { int t=_getch(); if(t=='~') return 2003; }
                return 2003;
            case '5':  // PageUp: 27,91,5,126
                if (kbhit()) { int t=_getch(); if(t=='~') return 2005; }
                return 2005;
            case '6':  // PageDown: 27,91,6,126
                if (kbhit()) { int t=_getch(); if(t=='~') return 2006; }
                return 2006;

            default:
                return 2000 + code;
        }
    }

    if (k == 127) return BACKSPACE_KEY;   // Linux/Mac Backspace = 127, Windows er sathe mile dilam
    if (k == 10)  return ENTER_KEY;       // kichu terminal e Enter = 10 (LF), Windows er 13 er sathe mile dilam

    return k;   // ordinary character — letters, digits, symbols — unchanged

#endif
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

    if (KEY=='<' || KEY==',')  {TabNumber--; if(TabNumber<0) TabNumber=0; if((Marker==1 || Marker==2) && is_Playing == true) clearScreen();}
    if (KEY=='>' || KEY=='.')  {TabNumber++;                              if((Marker==1 || Marker==2) && is_Playing == true) clearScreen();}
    if (KEY=='^')  {TabNumber=3;                                          if((Marker==1 || Marker==2) && is_Playing == true) clearScreen();}
    if (KEY=='`')  {SoundFlag=false; cout<<"\rMuted  ";}
    if (KEY=='~')  {SoundFlag= true; cout<<"\r\aUnmuted";}

    KeyHit_Cheak_Count++; // not necessery

    //    if (KEY=='l' && is_Continuous_Change_Color==false) is_Continuous_Change_Color=true;
    //    if (KEY=='l' && is_Continuous_Change_Color==true) is_Continuous_Change_Color= false;
}

char Dicission (char a)
{
    NewLine NewLine NewLine
    Multi_Tabs_4 cout << "Play Again: <Space>\n";
    Multi_Tabs_4 cout << "Goto Menu : <Home/End/X>\n";

    while(true)
    {
        Sleep(Time_Delay);
        if (kbhit())           //Control by arrow KEY
        {
            KEY = ReadKey();      Key_Hit_Maintainor();

            if    (KEY==' ' || KEY == ENTER_KEY )                                  {a= '1';   break;}
            if    (KEY=='x' || KEY=='X' || KEY==HOME_KEY )                        {a= '0';   break;}
            if    (KEY==END_KEY)                                                 {a= '0';   break;}

        }
    }

    NewLine NewLine NewLine
    clearScreen();
    return a;
}

int  Snake_Area_Row = 10 , Snake_Area_Column = 15 ;
bool Snake_Premium=true, DoubleSnake = true, Ultra_Premium_Protector = false, Joined_Single_Snake=false;
bool Snake_Boundary=false, Self_Hit=true;
bool Pac_Premium = true;


char Dicission_in_Snake_And_Pac_Game  (char a)
{
    NewLine
    Multi_Tabs_3 cout << "Same Speed  : <Space>\n";
    Multi_Tabs_3 cout << "Diff Speed  : <Esc>\n";
    Multi_Tabs_3 cout << "Local Menu  : <Home>\n";
    Multi_Tabs_3 cout << "Main Menu   : <End>\n";

    while(true)
    {
        Sleep(Time_Delay);
        if (kbhit())           //Control by arrow KEY
        {
            KEY = ReadKey();      Key_Hit_Maintainor();

            if    (KEY== SPACE_KEY || KEY == ENTER_KEY )                             {a= '3';   break;}
            if    (KEY== ESC_KEY )                                                   {a= '2';   break;}
            if    (KEY=='x' || KEY=='X' || KEY==HOME_KEY )                           {a= '1';   break;}
            if    (KEY== END_KEY)                                                    {a= '0';   break;}
        }
    }

    NewLine NewLine NewLine
    clearScreen();
    return a;
}

char Dicission_TicTacToe (char a)
{
    NewLine
    Multi_Tabs_4 cout << "Same Level + Same 1st  : <Space>\n";
    Multi_Tabs_4 cout << "Same Level + Oppo 1st  : <Enter>\n";
    Multi_Tabs_4 cout << "Same Level             : <Back-Space>\n";
    Multi_Tabs_4 cout << "Diff Level             : <HOME>\n";
    Multi_Tabs_4 cout << "Main Menu              : <END>\n";

    while(true)
    {
        Sleep(Time_Delay);
        if (kbhit())           //Control by arrow KEY
        {
            KEY = ReadKey();      Key_Hit_Maintainor();

            //            if    (KEY>='0' && KEY<='4')         {a= KEY;   break;}
            if    (KEY=='x' || KEY=='X' || KEY==END_KEY )      {a= '0';   break;}
            if    (KEY == SPACE_KEY)                           {a= '3';   break;}
            if    (KEY == ENTER_KEY)                           {a= '4';   break;}
            if    (KEY == BACKSPACE_KEY)                       {a= '2';   break;}
            if    (KEY == HOME_KEY)                            {a= '1';   break;}

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
     cout << "Diff Team + Diff Over/Wkt : 'q'\n";
     cout << "Same Team + Diff Over/Wkt : 'w'\n";
     cout << "Same Team + Same + Toss   : 'e'\n";
     cout << "Same Team + Same no Toss  : 'r'\n";
     cout << "Main Menu                 : 'x'\n";

    while(true)
    {
        Sleep(Time_Delay);
        if (kbhit())           //Control by arrow KEY
        {
            KEY = ReadKey();

            if    (KEY=='x' || KEY=='X' || KEY== HOME_KEY || KEY== END_KEY )     {a= '0';   break;}

            if (KEY < 256)      // only fold real characters through tolower(); ignore Up/Down/Left/Right/etc.
            {
                KEY = tolower(KEY);

                if    (KEY== 'q' || KEY=='!' )               {a= '1';   break;}
                if    (KEY== 'w' || KEY=='@' )               {a= '2';   break;}
                if    (KEY== 'e' || KEY=='#' )               {a= '3';   break;}
                if    (KEY== 'r' || KEY=='$' )               {a= '4';   break;}
            }

            Key_Hit_Maintainor();

        }
    }

    clearScreen();
    return a;
}

char Dicission_in_Mini_Games  (char a)
{
    NewLine
    Multi_Tabs_3 cout << "Play Again   : <Space>\n";
    Multi_Tabs_3 cout << "Another Game : <Enter>\n";
    Multi_Tabs_3 cout << "Main Menu    : <Home>\n";

    while(true)
    {
        Sleep(Time_Delay);

        if (kbhit())           //Control by arrow KEY
        {
            KEY = ReadKey();      Key_Hit_Maintainor();

            //            if    (KEY>='0' && KEY<='3') {a= KEY; break;}
            if    (KEY=='x' || KEY=='X' || KEY == HOME_KEY || KEY==END_KEY  )   {a= '0';   break;}
            if    (KEY==RIGHT_KEY || KEY==DOWN_KEY  || KEY == ENTER_KEY  )      {a= '2';   break;}
            if    (KEY==' '  )                                                  {a= '1';   break;}
            if    (KEY==UP_KEY || KEY == LEFT_KEY  )                            {a= '1';   break;}

        }
    }

    NewLine NewLine NewLine
    clearScreen();
    return a;
}

int Snake_or_Pac_Lavel_Generator(int Level)
{
    int Delay;

    if(Level==1) Delay=500;
    if(Level==2) Delay=300;
    if(Level==3) Delay=200;
    if(Level==4) Delay=100;
    if(Level==5) Delay=50;
    if(Level==6) Delay=25;
    if(Level==7) Delay=10;
    if(Level==8) Delay=0;

    return Delay;
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
    Multi_Tabs_1   NewLine

    Sound
}


void Print_Ludo(int *Board,int n, int Dice, int k)
{
    hideCursor();
    clearScreen();
    Multi_Tabs_1 cout << "LUDO SNAKE-LADDER\n\n";
    Multi_Tabs_1 cout << "[MULTI-PLAYER]\n\n";

    Multi_Tabs_4 cout<<"S:97>12,63>3,70>25,32>13,60>38,73>47,82>43\n";
    Multi_Tabs_4 cout<<"L:6>16,8>41,26>29,50>93,55>80,59>84,66>88\n\n";

    NewLine Multi_Tabs_3 cout << "Any KEY=Dice  Home/End/X=Quit\n\n";

    for(int i=1;i<=n;i++)
    {
        Multi_Tabs_1 cout<<"    ";
        if(i==k) cout<<Markered_Symbol; else cout<<" ";
        cout << " Player-" << i << " : " << Board[i];
        if(Board[k]==100 && i==k  )           cout<< "(+" << Dice << ")" ;
        if(i+1==k || (k==1 && i==n) ) cout<< "(+" << Dice << ")" ;

        NewLine
    }

    Sound

}

void Show_Main_Menu()
{
    hideCursor();  // cursor lukano
    if(KEY=='*') Sleep(10*Time_Delay);

    if(KEY==DOWN_KEY || KEY==UP_KEY || KEY=='w' || KEY=='s') gotoxy(0,0);
    else                                                     clearScreen(); //All Previous Print Erased

    if(is_Premium) Markered_Symbol = symbol(2);
    else           Markered_Symbol = symbol(251);

    if(is_Premium) Design_Symbol = symbol(2);
    else           Design_Symbol = "*";

    Multi_Tabs_1 cout << Design_Symbol << " GAME ERA "<< Design_Symbol;     for(int i=0;i<2;i++) NewLine

    Multi_Tabs_3 if(Marker==1) cout<<Markered_Symbol; else cout<<" "; printf(" 1: SNAKE\n");
    Multi_Tabs_3 if(Marker==2) cout<<Markered_Symbol; else cout<<" "; printf(" 2: PACMAN\n\n");

    Multi_Tabs_3 if(Marker==3) cout<<Markered_Symbol; else cout<<" "; printf(" 3: TIC TAC TOE (vs COM)\n");
    Multi_Tabs_3 if(Marker==4) cout<<Markered_Symbol; else cout<<" "; printf(" 4: TIC TAC TOE (vs MAN)\n\n");

    Multi_Tabs_3 if(Marker==5) cout<<Markered_Symbol; else cout<<" "; printf(" 5: SNAKE-LADDER-LUDO\n");
    Multi_Tabs_3 if(Marker==6) cout<<Markered_Symbol; else cout<<" "; printf(" 6: SUDOKU\n\n");

    Multi_Tabs_3 if(Marker==7) cout<<Markered_Symbol; else cout<<" "; printf(" 7: CRICKET\n");
    Multi_Tabs_3 if(Marker==8) cout<<Markered_Symbol; else cout<<" "; printf(" 8: Mini GAMES\n\n");

    Multi_Tabs_3                                       cout<<" "; printf(" ?: MORE INSTRUCTIONS\n");
    Multi_Tabs_3                                       cout<<" "; printf(" *: DEMO\n\n");

    Multi_Tabs_3                                       cout<<" "; printf(" ENTER: Marked Game\n");
    Multi_Tabs_3                                       cout<<" "; printf("   END: Close\n\n");

}

int main()
{
    fontManager();

    char Again,Kall;

    Menu:
    Show_Main_Menu();

    //Main_Menu_Controller
    while(true)
    {
        hideCursor();

        Sleep(Time_Delay);
        KeyHit_Cheak_Count++;   if (KEY=='!') cout<<"\r"<<KeyHit_Cheak_Count<<"                      ";

        if (kbhit())           //Control by arrow KEY
        {
            KEY = ReadKey();

            if      (KEY>='0' && KEY<='9')                  {Marker= KEY-'0'; break;}
            else if (KEY=='x' || KEY=='X' || KEY==END_KEY ) {Marker=100; break;}

            else if (KEY==DOWN_KEY || KEY=='s' ) { Marker++; if(Marker>8) Marker=1; goto Menu; }
            else if (KEY==UP_KEY   || KEY=='w' ) { Marker--; if(Marker<1) Marker=8; goto Menu; }

            else if (KEY=='p' && is_Premium == false) {is_Premium = true;  goto Menu;}
            else if (KEY=='p' && is_Premium == true ) {is_Premium = false; goto Menu; }

            else if (KEY=='?' || KEY=='/' ) {Instruction(); continue;}

            else if (KEY=='`')  {SoundFlag=false; cout<<"\rMuted";}
            else if (KEY=='~')  {SoundFlag= true; cout<<"\r\aUnmuted"; }

            else if (KEY=='<' || KEY==',' )  {TabNumber--; if(TabNumber<0) TabNumber=0; goto Menu;}
            else if (KEY=='>' || KEY=='.' )  {TabNumber++; goto Menu;}
            else if (KEY=='^')               {TabNumber=6; goto Menu;}

            else if (KEY=='\\')     {ColorVar=0; SetConsoleColor(BrightWhite);         goto Menu;}
            else if (KEY=='|')      {ColorVar=0; SetConsoleColour(Black,BrightWhite);  goto Menu;}

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

            else if (KEY== BACKSPACE_KEY || KEY==LEFT_KEY || KEY==HOME_KEY || KEY==SPACE_KEY)   goto Menu;
            else if ( KEY==ENTER_KEY || KEY==RIGHT_KEY )                                        break;

            else if(KEY=='+' || KEY=='=') {Time_Delay++; if(Time_Delay>100) Time_Delay=91; if(Time_Delay>10) Time_Delay+=9; cout<<"\rPolling_Delay(ms): "<<Time_Delay<<"                          ";}
            else if(KEY=='-' || KEY=='_') {Time_Delay--; if(Time_Delay<0  ) Time_Delay=0;  if(Time_Delay>10) Time_Delay-=9; cout<<"\rPolling_Delay(ms): "<<Time_Delay<<"                          ";}

            //            else if (KEY=='g' && is_Continuous_Change_Color==false) is_Continuous_Change_Color=true;
            //            else if (KEY=='g' && is_Continuous_Change_Color==true) is_Continuous_Change_Color= false;


            else if(KEY=='f' || KEY=='F')
            {
                Marker=1;
                Time_Delay=1;   //time Delay in every KEY-hit.
                TabNumber=4;

                SoundFlag  = true;
                is_Premium = true;
                is_Playing = false;

                ColorVar=0; SetConsoleColor(BrightWhite);   goto Menu;
            }

            else if(KEY=='*')
            {
                Instruction();  Show_Main_Menu(); if (kbhit()) { getch(); goto Menu;}
                for(int i=0;i<8;i++){changeTextColour();  Show_Main_Menu(); cout<<"\r*/B"; if (kbhit()) { getch(); goto Menu;}}
                for(int i=0;i<8;i++){changeTextColour2(); Show_Main_Menu(); cout<<"\r*/W"; if (kbhit()) { getch(); goto Menu;}}
                for(int i=0;i<8;i++){changeBgColour();    Show_Main_Menu(); cout<<"\rB/*"; if (kbhit()) { getch(); goto Menu;}}
                for(int i=0;i<8;i++){changeBgColour2();   Show_Main_Menu(); cout<<"\rW/*"; if (kbhit()) { getch(); goto Menu;}}
                ColorVar=0; SetConsoleColor(BrightWhite); Show_Main_Menu();if (kbhit()) { getch(); goto Menu;}

                TabNumber--; Show_Main_Menu();if (kbhit()) { getch(); goto Menu;}
                TabNumber--; Show_Main_Menu();if (kbhit()) { getch(); goto Menu;}
                TabNumber++; Show_Main_Menu();if (kbhit()) { getch(); goto Menu;}
                TabNumber++; Show_Main_Menu();if (kbhit()) { getch(); goto Menu;}
                TabNumber++; Show_Main_Menu();if (kbhit()) { getch(); goto Menu;}
                TabNumber--; Show_Main_Menu();if (kbhit()) { getch(); goto Menu;}

                SoundFlag=false; Show_Main_Menu(); cout<<"\rMuted";       if (kbhit()) { getch(); goto Menu;} this_thread::sleep_for(chrono::milliseconds(Time_Delay*10));
                SoundFlag= true; Show_Main_Menu(); cout<<"\r\aUnmuted";   if (kbhit()) { getch(); goto Menu;} this_thread::sleep_for(chrono::milliseconds(Time_Delay*10));
                SoundFlag=false; Show_Main_Menu(); cout<<"\rMuted";       if (kbhit()) { getch(); goto Menu;} this_thread::sleep_for(chrono::milliseconds(Time_Delay*10));
                SoundFlag= true; Show_Main_Menu(); cout<<"\r\aUnmuted";   if (kbhit()) { getch(); goto Menu;} this_thread::sleep_for(chrono::milliseconds(Time_Delay*10));

                KEY=DOWN_KEY; cout<<"\r                                                   ";
                for(int i=0;i<8;i++) {Marker++; if(Marker>8) Marker=1; Show_Main_Menu(); if (kbhit()) { getch(); goto Menu;} this_thread::sleep_for(chrono::milliseconds(1));}

                goto Menu;
            }

            else if(KEY>=65 && KEY <=90            )   DisplayWorldView();
            else if(KEY>=97 && KEY <=122           )   DisplayWorldView();
            else if(KEY>=SPACE_KEY && KEY <=126    )   DisplayWorldView();

            else ;

        }
    }

    clearScreen();

    switch (Marker){

        case 1:     //SNAKE

            Snake_Menu:

            clearScreen();
            int Snake_Marker;

            Multi_Tabs_3 printf("  $ SNAKE ERA $\n\n");

            Multi_Tabs_3 printf(" 1: CLASSIC SNAKE\n");
            Multi_Tabs_3 printf(" 2: CLASSIC NO-END\n\n");
            Multi_Tabs_3 printf(" 3: BOX SNAKE\n");
            Multi_Tabs_3 printf(" 4: BOX NO-SELF-HIT\n\n");

            Multi_Tabs_3 printf(" 5: AI CLASSIC\n");
            Multi_Tabs_3 printf(" 6: AI CLASSIC NO-END\n\n");
            Multi_Tabs_3 printf(" 7: AI BOX\n");
            Multi_Tabs_3 printf(" 8: AI BOX NO-SELF-HIT\n\n");

            Multi_Tabs_3 printf(" 9: AI SAFE CLASSIC\n");
            Multi_Tabs_3 printf(" 0: AI SAFE BOX\n\n");

            Multi_Tabs_3 printf(" S: Snake Area\n");
            Multi_Tabs_3 printf(" ?: Instructions\n\n");

            Multi_Tabs_3 printf(" X: Main Menu\n\n");

            while(true)
            {
                hideCursor();
                Sleep(Time_Delay);

                if (kbhit())           //Control by arrow KEY
                {
                    KEY = ReadKey();

                    Snake_Marker = KEY - '0';

                    if (Snake_Marker == 0)                             {if(Snake_Area_Column%2!=0) Snake_Area_Column++; if(Snake_Area_Row==1) Snake_Area_Row++; break;}
                    if (Snake_Marker >= 0 && Snake_Marker <= 9  )       break;
                    if (KEY=='x' || KEY=='X' || KEY==LEFT_KEY || KEY==HOME_KEY || KEY==END_KEY )     goto Menu;

                    Key_Hit_Maintainor();

                    if(KEY=='s' || KEY=='S')
                    {
                        clearScreen(); Multi_Tabs_1 printf("     WELCOME TO SNAKE ERA\n\n");

                        Multi_Tabs_1 cout<<"Snake_Game_Settings\n\n";
                        cout<<"Height (1-20): ";
                        cin>> Snake_Area_Row; if(Snake_Area_Row<1) Snake_Area_Row=1;  if(Snake_Area_Row>20) Snake_Area_Row=20;

                        cout<<"Width  (4-40): ";
                        cin>> Snake_Area_Column; if(Snake_Area_Column<4) Snake_Area_Column=4;  if(Snake_Area_Column>40) Snake_Area_Column=40;

                        goto Snake_Menu;
                    }

                    if(KEY=='/')
                    {
                        Snake_Instruction();
                        goto Snake_Menu;
                    }

                    if(KEY=='?')
                    {
                        Instruction();
                        Snake_Instruction();
                        goto Snake_Menu;
                    }

                }
            }
            clearScreen();

            while(true)
            {
                Multi_Tabs_1      printf("  $ WELCOME TO SNAKE ERA $\n\n");

                if(Snake_Marker==1)
                {
                    Multi_Tabs_1 cout << "SNAKE [Classic]\n\n";
                    cout<<"Eat fruit to grow. Avoid self-hit. Arrow Keys to move.\n\n";
                }

                if(Snake_Marker==2)
                {
                    Multi_Tabs_1 cout << "SNAKE [Classic-No-End]\n\n";
                    cout<<"Eat fruit to grow. No death by self-hit. X/End to quit.\n\n";
                }

                if(Snake_Marker==3)
                {
                    Multi_Tabs_1 cout << "SNAKE [Box]\n\n";
                    cout<<"Eat fruit to grow. Avoid self/border hit. Arrow Keys.\n\n";
                }

                if(Snake_Marker==4)
                {
                    Multi_Tabs_1 cout << "SNAKE [Box-No-Self-Hit]\n\n";
                    cout<<"Eat fruit to grow. Only border kills. Arrow Keys.\n\n";
                }

                if(Snake_Marker==5) {Multi_Tabs_1 cout << "AI SNAKE [CLASSIC]\n\n";}
                if(Snake_Marker==6) {Multi_Tabs_1 cout << "AI SNAKE [CLASSIC-NO-END]\n\n";}
                if(Snake_Marker==7) {Multi_Tabs_1 cout << "AI SNAKE [BOX]\n\n";}
                if(Snake_Marker==8) {Multi_Tabs_1 cout << "AI SNAKE [BOX-NO-SELF]\n\n";}

                if(Snake_Marker==9) {Multi_Tabs_1 cout << "AI SAFE SNAKE [CLASSIC]\n\n";}
                if(Snake_Marker==0) {Multi_Tabs_1 cout << "AI SAFE SNAKE [BOX]\n\n";}

                int Level;
                Multi_Tabs_1 cout<< "        SPEED (1-8) :  ";

                while(true)
                {
                    Sleep(Time_Delay);
                    if (kbhit())           //Control by arrow KEY
                    {
                        KEY = ReadKey();      Key_Hit_Maintainor();

                        if    (KEY>='1' && KEY<='8') {Level= KEY-'0'; break;}
                        if    (KEY==LEFT_KEY || KEY==HOME_KEY)  goto Snake_Menu;
                        if    (KEY==END_KEY || KEY=='x' || KEY=='X') goto Menu;
                    }
                }

                int Delay = Snake_or_Pac_Lavel_Generator(Level);

                while(true)
                {
                    clearScreen();

                    is_Playing = true;
                    bool Finish=false, Is_Completed=false, Is_Quit=false, is_Fruit_in_Blank_Space = true, BonusFlag=false;
                    int Fruit=0, Bonus=Snake_Area_Row * Snake_Area_Column, Score = 0,Point= 0, Call=0,Change=0,i,FruitCount=0, BonusCount=0, Step = 0, Bonus_Life_Var=0;
                    int Snake_Head= ( Snake_Area_Row /2)* Snake_Area_Column  +  Snake_Area_Column /2 + 1; //0-based: 0 to row*col-1
                    int Snake_Body[ Snake_Area_Row * Snake_Area_Column +5];
                    fill(Snake_Body, Snake_Body + Snake_Area_Row * Snake_Area_Column + 5, Snake_Area_Row * Snake_Area_Column); //sentinel = row*col (display range er baire)
                    char Move='6';
                    string PlayGround[ Snake_Area_Row * Snake_Area_Column +6]; //0-99,NULL+Primary body Size(4)+Extra some for avoid silly risk

                    Fruit  =  Snake_Fruit_position_Declaration_Function (Call);

                    //First Declaration of Snake Body (below)
                    Snake_Body[1]  =  Snake_Head -1;
                    Snake_Body[2]  =  Snake_Head -2;
                    Snake_Body[3]  =  Snake_Head -3;

                    while(true)
                    {
                        hideCursor();
                        gotoxy(0,0);

                        if(Snake_Marker==1 || Snake_Marker==2 || Snake_Marker==5 || Snake_Marker==6 || Snake_Marker==9) Snake_Boundary=false;
                        else                                                                                            Snake_Boundary=true;

                        if(Snake_Marker==2 || Snake_Marker==4 || Snake_Marker==6 || Snake_Marker==8 )                   Self_Hit=false;
                        else                                                                                            Self_Hit=true;

                        while(true)                  //jate Fruit snake er body borabor na ase
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

                        while(true)                  //jate Bonus snake er body borabor na ase
                        {
                            if( !BonusFlag ) break;
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
                            PlayGround [i] = " " ;
                        }

                        if(Snake_Premium && !Ultra_Premium_Protector)   PlayGround [Bonus] = symbol(5  + Step%2);
                        else if(Snake_Premium)     PlayGround [Bonus] =  symbol(176 + Step%2);
                        else                    PlayGround [Bonus] = string(1, char('$' - Step%2));

                        PlayGround [Fruit] = string(1, char(Step%2+'*')); //Fruit Symbol (*,+)

                        for(i = Score+3; i>0; i--)
                        {
                            if     (!Snake_Premium && !DoubleSnake)  PlayGround [Snake_Body[i]]  =  "o";
                            if     (!Snake_Premium &&  DoubleSnake)  PlayGround [Snake_Body[i]]  =  "O";

                            if     ( Snake_Premium && !DoubleSnake)  PlayGround [Snake_Body[i]]  =  symbol(254); //Snake Body Symbol
                            if     ( Snake_Premium &&  DoubleSnake)  PlayGround [Snake_Body[i]]  =  symbol(219); //Snake Body Symbol
                        }

                        if(Snake_Premium && !Ultra_Premium_Protector) PlayGround [Snake_Body[Score+3]] = symbol(4);    //Snake Tail Symbol
                        else           PlayGround [Snake_Body[Score+3]] = "-";

                        if(Snake_Premium && !Ultra_Premium_Protector) PlayGround [Snake_Head] = symbol(2);    //Snake Head Symbol (Ascii 2)
                        else           PlayGround [Snake_Head] = "@";


                        Multi_Tabs_1  printf("  $ SNAKE ERA $\n");

                        if(Snake_Marker==1) {Multi_Tabs_1 cout << "SNAKE [CLASSIC]\n";}
                        if(Snake_Marker==2) {Multi_Tabs_1 cout << "SNAKE [CLASSIC-NO-END]\n";}
                        if(Snake_Marker==3) {Multi_Tabs_1 cout << "SNAKE [BOX]\n";}
                        if(Snake_Marker==4) {Multi_Tabs_1 cout << "SNAKE [BOX-NO-SELF-HIT]\n";}

                        if(Snake_Marker==5) {Multi_Tabs_1 cout << "AI SNAKE [CLASSIC]\n";}
                        if(Snake_Marker==6) {Multi_Tabs_1 cout << "AI SNAKE [CLASSIC-NO-END]\n";}
                        if(Snake_Marker==7) {Multi_Tabs_1 cout << "AI SNAKE [BOX]\n";}
                        if(Snake_Marker==8) {Multi_Tabs_1 cout << "AI SNAKE [BOX-NO-SELF]\n";}

                        if(Snake_Marker==9) {Multi_Tabs_1 cout << "AI SAFE [CLASSIC]\n";}
                        if(Snake_Marker==0) {Multi_Tabs_1 cout << "AI SAFE [BOX]\n";}


                        Multi_Tabs_1 cout << "Level : "<<Level<<endl;

                        NewLine;
                        Multi_Tabs_1;  Border_Sign;  Multiple_Border_Sign;  NewLine;  //Border
                        Multi_Tabs_1;  Border_Sign;

                        for(i = 0; i <  Snake_Area_Row * Snake_Area_Column ; i++)
                        {
                            /** changeTextColour(); */
                            if(Joined_Single_Snake) cout<<PlayGround [i];
                            else if(!DoubleSnake) cout<<PlayGround [i]<<" ";           // show Update resulte of Game-PlayGround
                            else if( DoubleSnake) cout<<PlayGround [i]<<PlayGround[i];           // show Update resulte of Game-PlayGround
                            if((i+1)% Snake_Area_Column  == 0) {Border_Sign;  NewLine;  Multi_Tabs_1;  Border_Sign;  }
                        }

                        Multiple_Border_Sign NewLine NewLine

                        Multi_Tabs_1 cout<<"         ";    show_Point
                        Multi_Tabs_1 cout<<"           Fruit Count : "<<FruitCount<<endl;
                        Multi_Tabs_1 cout<<"           Bonus Count : "<<BonusCount<<endl;
                        Multi_Tabs_1 cout<<"           Step        : "<<Step      <<endl;
                        NewLine
                        Multi_Tabs_1 cout<<"/?=Help  X/End=Quit"<<endl;


                        Sleep(Delay);    //Time Delay for Update Printing

                        if(Finish || Is_Completed)  break;//snake nijeke bite korle game over
                        if(Snake_Boundary) { if(Snake_Head >= Snake_Area_Row * Snake_Area_Column  || Snake_Head< 0 ) break; }

                        Step++;

                        if (kbhit())           //Control by arrow KEY
                        {
                            KEY = ReadKey();
                            // Check for arrow KEY input
                            if(KEY==UP_KEY || KEY=='8' || KEY=='w' || KEY=='W' ) // Up arrow
                            Move='8';

                            else if(KEY==DOWN_KEY || KEY=='2' || KEY=='s'  || KEY=='S' )// Down arrow
                            Move='2';

                            else if(KEY==LEFT_KEY || KEY=='4' || KEY=='a'  || KEY=='A' ) // Left arrow
                            Move='4';

                            else if(KEY==RIGHT_KEY || KEY=='6' || KEY=='d'  || KEY=='D') // Right arrow
                            Move='6';

                            else if(KEY=='+' || KEY=='=') {Level++; if(Level==9) Level--; Delay = Snake_or_Pac_Lavel_Generator(Level);}
                            else if(KEY=='-' || KEY=='_') {Level--; if(Level==0) Level++; Delay = Snake_or_Pac_Lavel_Generator(Level);}

                            else if(KEY=='0' || KEY=='5' || KEY==SPACE_KEY )   getch();
                            else if(KEY==ENTER_KEY  || KEY==BACKSPACE_KEY  )   clearScreen();

                            else if(KEY=='/') {clearScreen(); Snake_Instruction(); clearScreen(); }
                            else if(KEY=='?') {clearScreen(); Instruction(); Snake_Instruction(); clearScreen(); }

                            else if(KEY=='x' || KEY=='X' || KEY==END_KEY ) {Is_Quit=true; break;}

                            else if(DoubleSnake==true  && KEY=='o') DoubleSnake=false;
                            else if(DoubleSnake==false && KEY=='o') DoubleSnake=true;

                            else if(Ultra_Premium_Protector==true  && KEY=='u') Ultra_Premium_Protector=false;
                            else if(Ultra_Premium_Protector==false && KEY=='u') Ultra_Premium_Protector=true;

                            else if(Snake_Premium==true  && KEY=='p') Snake_Premium=false;
                            else if(Snake_Premium==false && KEY=='p') Snake_Premium=true;

                            else if(Joined_Single_Snake==true  && KEY=='i') {Joined_Single_Snake=false; clearScreen();}
                            else if(Joined_Single_Snake==false && KEY=='i') {Joined_Single_Snake=true;  clearScreen();}

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

                        for(i = 3+Score; i>0; i--)
                        {
                            Snake_Body[i] =  Snake_Body[i-1];  //Snake er body possition update
                        }
                        Snake_Body[1] =  Snake_Head;

                        if( !Snake_Boundary )
                        {
                            //to move to up / down / left / right (below) - (According to KEY-board Numarical Pads)
                            if(Move == '6') {Snake_Head++;     /** to move Right */  if(Snake_Head% Snake_Area_Column  == 0) Snake_Head -=  Snake_Area_Column ; /**Dan dike ber hoye gele oi borabor Bam dik diye asbe */ }
                            if(Move == '4') {Snake_Head--;     /** to move Left  */  if(Snake_Head < 0 || Snake_Head% Snake_Area_Column  == Snake_Area_Column-1) Snake_Head +=  Snake_Area_Column ; /**Bam dike ber hoye gele oi borabor Dan dik diye asbe */}
                            if(Move == '2') {Snake_Head +=  Snake_Area_Column ; /** to move Down  */   }
                            if(Move == '8') {Snake_Head -=  Snake_Area_Column ; /** to move Up    */   }

                            if(Snake_Head >= Snake_Area_Row * Snake_Area_Column ) Snake_Head -=  Snake_Area_Row * Snake_Area_Column ; //box er ekdik diye snake ber hoye gele, oi borabor biporit dik theke snake fire asbe.
                            if(Snake_Head <   0                                 ) Snake_Head +=  Snake_Area_Row * Snake_Area_Column ; // " " "

                        }

                        if( Snake_Boundary )
                        {
                            if(Move== '6') {Snake_Head++;      if(Snake_Head% Snake_Area_Column == 0)                        { Snake_Head= Snake_Area_Row*Snake_Area_Column; continue; }}      //Box e touch lagle Game over
                            if(Move== '4') {Snake_Head--;      if(Snake_Head < 0 || (Snake_Head+1)% Snake_Area_Column == 0)  { Snake_Head= Snake_Area_Row*Snake_Area_Column; continue; }}      // " " "
                            if(Move== '8') {Snake_Head -=  Snake_Area_Column ;    }
                            if(Move== '2') {Snake_Head +=  Snake_Area_Column ;    }

                            if(Snake_Head >= Snake_Area_Row * Snake_Area_Column ) { Snake_Head= Snake_Area_Row*Snake_Area_Column; continue; }  //Box e touch lagle Game over
                            if(Snake_Head <   0)                                  { Snake_Head= Snake_Area_Row*Snake_Area_Column; continue; } // " " "
                        }


                        for(i = 3+Score; i>0; i--)
                        {
                            if(Snake_Head == Snake_Body[i]) { if(Self_Hit) {Finish = true;} continue; } //jodi Snake nijeke Bite kore, then game over
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

                    if(Snake_Boundary)
                    {
                        if  (Finish)    { NewLine NewLine Multi_Tabs_1  cout << "       TOUCH BODY!";  }
                        else            { NewLine NewLine Multi_Tabs_1  cout << "       TOUCH BORDER!";}
                    }

                    if      (Is_Quit  )     {NewLine Multi_Tabs_1 cout<<"\t    Game Quit!"<<endl;  NewLine}

                    else if (!Is_Completed) {NewLine Multi_Tabs_1 cout<<"\t    Game Over!"<<endl;  NewLine}

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

            clearScreen();
            int Pac_Marker;

            Multi_Tabs_3 printf("  $ PACMAN ERA $\n\n");
            Multi_Tabs_3 printf(" 1: EASY MODE\n");
            Multi_Tabs_3 printf(" 2: HARD MODE\n\n");
            Multi_Tabs_3 printf(" 9: Instructions\n");
            Multi_Tabs_3 printf(" 0: Main Menu\n");

            while(true)
            {
                hideCursor();
                Sleep(Time_Delay);

                if (kbhit())           //Control by arrow KEY
                {
                    KEY = ReadKey();

                    Pac_Marker = KEY - '0';

                    if (Pac_Marker >= 1 && Pac_Marker <= 2  ) break;
                    if (KEY=='x' || KEY==LEFT_KEY || KEY=='0')  goto Menu;

                    if(Pac_Marker == 9)
                    {
                        Instruction();
                        cout << "\nPACMAN: Eat all fruit. Avoid ghost. 3 lives. Arrow Keys.\n\n";

                        getch(); goto PacMan_Menu;
                    }

                    Key_Hit_Maintainor();

                }
            }
            clearScreen();

            while(true)
            {
                Multi_Tabs_1 cout << "PACMAN GAME \n\n";
                cout << "PACMAN: Eat all fruit. Avoid ghost. 3 lives. Arrow Keys.\n\n";

                int Level;
                cout<< "SPEED (1-8) :  ";
                while(true)
                {
                    Sleep(Time_Delay);
                    if (kbhit())           //Control by arrow KEY
                    {
                        KEY = ReadKey();      Key_Hit_Maintainor();

                        if    (KEY>='1' && KEY<='8') {Level= KEY-'0'; break;}
                        if    (KEY=='x' || KEY==LEFT_KEY)  goto Menu;

                    }
                }

                int Delay = Snake_or_Pac_Lavel_Generator(Level);
                //            Delay = 450-50*Level; //Speed

                while(true)
                {
                    is_Playing = true;
                    bool Temp= true;
                    int Score = 0,i,j,x = 0,Number_of_Enemy=1, Life=3;
                    int PacMan,Enemy[Number_of_Enemy];
                    char Move;
                    bool Fruit[111];
                    string PlayGround[111];                    /// Playground Size 10*10=100 (0-99) + extra 10(just for avoiding silly risk

                    for(i = 0; i < 100; i++)                            ///Initially sob gulo ghorei dot dekhabe
                    {
                        Fruit[i]=true;                                     ///'1' indicate korse oi possition a fruit ache
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
                    clearScreen();

                    while(true)                                        ///Protibar Move korar por Program ekhane chole asbe
                    {
                        hideCursor();
                        gotoxy(0,0);
                        /** changeTextColour(); */

                        for(i = 0; i < 100; i++)
                        {
                            PlayGround[i] = " ";
                        }

                        for(i = 0; i < 100; i++)
                        {
                            if(Fruit[i] == true) PlayGround[i] = ".";          ///jodi Fruit thake tobe Dot Sign dekhabe
                        }

                        if(Pac_Premium) PlayGround[PacMan] = symbol(1);          ///PacMan Symbol (Smile face Black)
                        else           PlayGround[PacMan] ="O";

                        for(i=0;i<Number_of_Enemy;i++)
                        {
                            if(Pac_Premium) PlayGround[Enemy[i]] = symbol(2);                   ///Enemy Symbol (Smile face White)
                            else           PlayGround[Enemy[i]] = "X";
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

                        Sleep(Delay);


                        if(Life == 0)       break;              ///Remaining Life '0' hole Game Over
                        if(Score == 100)    break;              ///Sob fruit gulo khele Game Over & Highest Score hobe
                        if(Temp == false)      goto pac_start;     ///jodi pacman er life kome jay, tobe sobar possition reform hobe

                        if (kbhit())
                        {
                            KEY = ReadKey();

                            // Check for arrow KEY input
                            if     (KEY==UP_KEY || KEY=='8' || KEY=='w' )     Move='8';
                            else if(KEY==DOWN_KEY || KEY=='2' || KEY=='s' )   Move='2';
                            else if(KEY==LEFT_KEY || KEY=='4' || KEY=='a' )   Move='4';   // Left arrow
                            else if(KEY==RIGHT_KEY || KEY=='6' || KEY=='d')    Move='6';   // Right arrow

                            else if(KEY==ENTER_KEY)    clearScreen();
                            else if(KEY=='0' || KEY=='5' || KEY==SPACE_KEY) getch();

                            else if(KEY=='+' || KEY=='=') {Level++; if(Level==9)  Level--; Delay = Snake_or_Pac_Lavel_Generator(Level);}
                            else if(KEY=='-' || KEY=='_') {Level--; if(Level==0)  Level++; Delay = Snake_or_Pac_Lavel_Generator(Level);}

                            else if(KEY=='x' || KEY=='X' || KEY==END_KEY )  break;

                            else if (KEY=='p' && Pac_Premium == false) Pac_Premium = true ;
                            else if (KEY=='p' && Pac_Premium == true ) Pac_Premium = false;

                            else {Key_Hit_Maintainor(); continue;}
                        }

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
                            if(PacMan == i && Fruit[i] == true)/// jodi Pacman er position-a fruit thake -
                            {
                                Score++;                    /// - tobe Score 1 barbe
                                Fruit[i]=false;                 /// & Fruit ta delete hoye jabe
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

            while(true)
            {
                Multi_Tabs_4 cout << "TIC TAC TOE\n";
                Multi_Tabs_4 cout << "[Man vs Computer]\n\n";

                cout << "Left=Back  HOME/END=Exit\n";

                NewLine Multi_Tabs_1  cout << "Level: 1=Easy 2=Med 3=Hard : ";

                int Level;

                while(true)
                {
                    Sleep(Time_Delay);

                    if (kbhit())           //Control by arrow KEY
                    {
                        KEY = ReadKey();      Key_Hit_Maintainor();

                        if    (KEY>='1' && KEY<='3') {Level= KEY-'0'; break;}
                        if    (KEY == 'x' || KEY == LEFT_KEY || KEY==HOME_KEY || KEY==END_KEY) break;

                    }
                }

                if(KEY=='x' || KEY == LEFT_KEY || KEY==HOME_KEY || KEY==END_KEY ) goto Menu;

                clearScreen();

                Multi_Tabs_4 cout << "\t       TIC TAC TOE   \n\n";
                Multi_Tabs_4 cout << "\t    [Man vs Computer]\n\n";

                if      (Level<= 0) break; //if you want to close the game
                else if (Level== 1) {Multi_Tabs_1 cout << "EASY LEVEL\n"; }
                else if (Level== 2) {Multi_Tabs_1 cout << "MEDIUM LEVEL\n"; }
                else                {Multi_Tabs_1 cout << "HARD LEVEL\n"; }
                NewLine

                TTT_first_move:
                Multi_Tabs_2 cout << "Who First? i=You c=Computer t=Toss\n";
                cout << "Left=Back  HOME/END=Exit\n";

                char who;
                bool Go_Back = false;

                while(true)
                {
                    Sleep(Time_Delay);
                    if (kbhit())           //Control by arrow KEY
                    {
                        KEY = ReadKey();      Key_Hit_Maintainor();

                        if    (KEY=='i' || KEY=='I' ) {who='i'; break;}
                        if    (KEY=='c' || KEY=='C' ) {who='c'; break;}
                        if    (KEY=='t' || KEY=='T' ) {who='t'; break;}
                        if    (KEY=='x' || KEY=='X' || KEY==HOME_KEY || KEY==END_KEY) goto Menu;
                        if    (KEY==LEFT_KEY) {Go_Back = true; break;}
                    }
                }

                if(Go_Back) {clearScreen(); continue;}

                if(who=='i' || who=='c')    goto TTT_re;

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

                NewLine Multi_Tabs_1
                for(i=1;i<=9;i++)  // Printing Loop
                {
                    cout<<" "<<Index_Symbol[i];
                    if (i==9) {NewLine Multi_Tabs_1 cout<<"   |   |   \n"; NewLine NewLine}
                    else if(i%3 == 0 ) { NewLine Multi_Tabs_1  cout <<"___|___|___\n"; Multi_Tabs_1  }
                    else   cout<<" |";
                }

                Tic_Tac_Toe_Index_Instructior_Function();

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
                        Sleep(Time_Delay);
                        if (kbhit())           //Control by arrow KEY
                        {
                            KEY = ReadKey();

                            if         (KEY>='1' && KEY<='9') {Me= KEY-'0'; Time++; break;}
                            else if    (KEY=='X' || KEY==END_KEY)  {goto Menu;}
                            else                              {Key_Hit_Maintainor(); clearScreen(); goto Print_Loop_Tic_Tac_Toe_Man_vs_Computer;}
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
                            while(true)
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
                            while(true)
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

            while(true)
            {
                int  i, Player_1= 0, Player_2= 0, Time= 0, Win_1= 0, Win_2= 0;
                short Index_Data [10];
                char Index_Symbol [10];

                Multi_Tabs_1 cout << "TIC TAC TOE\n";
                Multi_Tabs_1 cout << "[Man vs Man]\n\n";


                Multi_Tabs_2 cout<<"Who First? 1=P1 2=P2 0=Toss x=Exit\n";
                Multi_Tabs_1  cout<<"   ";

                char Who;
                while(true)
                {
                    if (kbhit())           //Control by arrow KEY
                    {
                        KEY = ReadKey();      Key_Hit_Maintainor();

                        if    (KEY=='1' || KEY=='2' || KEY == '0' || KEY=='x' || KEY == LEFT_KEY  ) { break;}


                    }
                }
                int who= KEY-'0';

                if(KEY == 'x' || KEY == LEFT_KEY ) goto Menu;
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

                Print_Loop_Tic_Tac_Toe_Man_vs_Man :   //Print_Loop

                //clearScreen();
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

                for(i=1;i<=9;i++)
                {
                    cout<<" "<<Index_Symbol[i];
                    if     (i   == 9 ) {NewLine Multi_Tabs_1  cout <<"   |   |   \n"; NewLine NewLine}
                    else if(i%3 == 0 ) {NewLine Multi_Tabs_1  cout <<"___|___|___\n"; Multi_Tabs_1      }
                    else   cout<<" |";
                }

                Tic_Tac_Toe_Index_Instructior_Function();

                hideCursor();

                if(Time== 0 && who== 2) {Multi_Tabs_2 cout << "  Now Player-2 's Turn   "; goto Player_2_TicTacToe;}
                if(Time== 0) ;
                else if(Time%2== 1 && who== 2 || Time%2== 0 && who != 2) goto Back_2;
                else goto Back_1;

                while(true)
                {

                    Multi_Tabs_2 cout << "  Now Player-1 's Turn   ";

                    Player_1_TicTacToe:

                    if (kbhit())           //Control by arrow KEY
                    {
                        Sleep(Time_Delay);

                        KEY = ReadKey();

                        if      (KEY>='1' && KEY<='9') {Player_1 = KEY-'0'; Time++;}
                        else if (KEY=='X' || KEY==END_KEY )  goto Menu;
                        else                           { Key_Hit_Maintainor(); clearScreen(); goto Print_Loop_Tic_Tac_Toe_Man_vs_Man ;}

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
                        Sleep(Time_Delay);
                        KEY = ReadKey();      Key_Hit_Maintainor();

                        if      (KEY>='1' && KEY<='9') {Player_2 = KEY-'0'; Time++;}
                        else if (KEY=='X' || KEY==END_KEY )  goto Menu;
                        else                           { Key_Hit_Maintainor(); clearScreen(); goto Print_Loop_Tic_Tac_Toe_Man_vs_Man ;}

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

            clearScreen();
            int Ludo_Marker;

            Multi_Tabs_3 printf("  $ SNAKE-LADDER LUDO $\n\n");
            Multi_Tabs_3 printf(" 1: MAN VS COMPUTER\n");
            Multi_Tabs_3 printf(" 2: MULTIPLE PLAYER\n\n");
            Multi_Tabs_3 printf(" 9: Instructions\n");
            Multi_Tabs_3 printf(" 0: Main Menu\n");

            while(true)
            {
                Sleep(Time_Delay);

                if (kbhit())           //Control by arrow KEY
                {
                    KEY = ReadKey();

                    Ludo_Marker = KEY - '0';

                    if (Ludo_Marker >= 1 && Ludo_Marker <= 2  ) break;
                    if (KEY=='x' || KEY==LEFT_KEY || KEY=='0')  goto Menu;


                    if(Ludo_Marker == 9)
                    {
                        cout<<"\nAny key=Dice. Reach 100 to win.\n";
                        cout<<"S:97>12,63>3,70>25,32>13,60>38,73>47,82>43\n";
                        cout<<"L:6>16,8>41,26>29,50>93,55>80,59>84,66>88\n\n";

                        getch(); goto Snake_Ladder_Ludo_Menu;
                    }

                    Key_Hit_Maintainor();
                }
            }
            clearScreen();

            if(Ludo_Marker==1)
            {
                while(true)
                {
                    NewLine Multi_Tabs_1 cout << " LUDO SNAKE-LADDER GAME"; NewLine NewLine
                    cout<<"LUDO SNAKE-LADDER (vs Computer)\nRoll dice to move. Reach 100 to win. Snakes go back, Ladders go up.\n\n\n";

                    int You= 0, Com= 0;
                    int Dice=0, i, temp= 0;
                    bool x= true;

                    NewLine Multi_Tabs_3 cout << "Any KEY=Dice  Home/End/X=Quit\n\n";

                    Sound

                    while(true)
                    {
                        KEY = ReadKey();
                        if (KEY=='x' || KEY=='X' || KEY==HOME_KEY || KEY==END_KEY) goto Menu;
                        Key_Hit_Maintainor();

                        for(i= 1; i<= 2; i++)
                        {
                            /** changeTextColour(); */
                            //getch();
                            temp += 67;
                            temp= 1+temp%100;
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
//                                if(You== 89)You= 53;
                                if(You== 73)You= 47;
                                if(You== 82)You= 43;


                                //ladders
                                if(You== 8)  You= 41;
                                if(You== 50) You= 93;
                                if(You== 6)  You= 16;
                                if(You== 55) You= 80;
                                if(You== 59) You= 84;
                                if(You== 26) You= 29;
                                if(You== 66) You= 88;


                                if(You>100) You -= Dice;
                                Multi_Tabs_4 cout << "Your Possition= " << You << "(+" << Dice << ")" << "  ";
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
//                                if(Com== 89)Com= 53;
                                if(Com== 73)Com= 47;
                                if(Com== 82)Com= 43;

                                //Laders
                                if(Com==  8)  Com= 41;
                                if(Com== 50)  Com= 93;
                                if(Com==  6)  Com= 16;
                                if(Com== 55)  Com= 80;
                                if(Com== 59)  Com= 84;
                                if(Com== 26)  Com= 29;
                                if(Com== 66)  Com= 88;


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
                    cout << "LUDO (Multiplayer): Select players. Roll dice each turn. Reach 100 to win.\n\n";
                    //cout << "#Disclaimer: \t\tLudo is Haram Game for Muslim. So you should avoid to play this.\n\n";

                    int Number_of_Player;

                    Multi_Tabs_1 cout << "Number of Player :\t";
                    cin >> Number_of_Player;

                    if(Number_of_Player<= 0) goto Menu;
                    if(Number_of_Player> 100) Number_of_Player=100;

//                    NewLine Multi_Tabs_3 cout << "     Press -->      Any    KEY to  HIT  The DICE   ";
//                    NewLine Multi_Tabs_3 cout << "     Press -->  Home/End/X KEY to CLOSE The GAME \n\n";
//                    Sound

                    int Board[Number_of_Player+1];
                    fill(Board, Board + Number_of_Player + 1, 0);
                    int Temp = 0;

                    int Dice=0, i;
                    bool x= true;

                    while(true)
                    {

                        for(i= 1; i<= Number_of_Player; i++)
                        {
                            Print_Ludo(Board,Number_of_Player,Dice,i);

                            KEY = ReadKey();
                            if (KEY=='x' || KEY=='X' || KEY==HOME_KEY || KEY==END_KEY) goto Menu;
                            Key_Hit_Maintainor();
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
//                            if(Board[i]== 89)Board[i]= 53;
                            if(Board[i]== 73)Board[i]= 47;
                            if(Board[i]== 82)Board[i]= 43;


                            //Ladders
                            if(Board[i]==  8)   Board[i]= 41;
                            if(Board[i]== 50)   Board[i]= 93;
                            if(Board[i]==  6)   Board[i]= 16;
                            if(Board[i]== 55)   Board[i]= 80;
                            if(Board[i]== 59)   Board[i]= 84;
                            if(Board[i]== 26)   Board[i]= 29;
                            if(Board[i]== 66)   Board[i]= 88;//



                            if(Board[i]>100) Board[i] -= Dice; //Don't cross 100

//                            cout << "Player-" << i << " : " << Board[i] << "(+" << Dice << ")" << "\t"; //Print

                            if(Board[i] == 100)//Winner
                            {
                                Sound
                                Print_Ludo(Board,Number_of_Player,Dice,i);
                                NewLine NewLine NewLine
                                Multi_Tabs_1 cout << " Congratulation!\n";
                                Multi_Tabs_2 cout << "        Player " << i << " is Winner\n\n\n";
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
        {
            int puzzles[6][9][9] =
            {
            // Level 0: Very Easy (2 blanks)
            {
                { 5, 3, 0, 6, 7, 8, 9, 1, 2 },
                { 6, 7, 2, 1, 9, 5, 3, 4, 8 },
                { 1, 9, 8, 3, 4, 2, 5, 6, 7 },
                { 8, 5, 9, 7, 6, 1, 4, 2, 3 },
                { 4, 2, 6, 8, 5, 3, 7, 9, 1 },
                { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
                { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
                { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
                { 3, 4, 5, 2, 8, 6, 1, 7, 0 },
            },
            // Level 1: Easy (5 blanks)
            {
                { 5, 3, 0, 0, 7, 8, 9, 1, 2 },
                { 6, 7, 2, 1, 9, 5, 3, 0, 8 },
                { 1, 9, 8, 3, 4, 2, 5, 6, 7 },
                { 8, 5, 9, 7, 6, 1, 4, 2, 0 },
                { 4, 2, 6, 8, 5, 3, 7, 9, 1 },
                { 7, 1, 3, 9, 2, 4, 8, 5, 6 },
                { 9, 6, 1, 5, 3, 7, 2, 8, 4 },
                { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
                { 3, 4, 5, 2, 8, 6, 0, 7, 9 },
            },
            // Level 2: Medium (12 blanks)
            {
                { 5, 3, 0, 0, 7, 0, 0, 1, 2 },
                { 6, 0, 2, 1, 9, 5, 3, 0, 8 },
                { 1, 9, 8, 0, 4, 2, 5, 6, 0 },
                { 8, 5, 9, 7, 6, 1, 0, 2, 3 },
                { 4, 2, 6, 8, 0, 3, 7, 9, 1 },
                { 7, 1, 3, 9, 2, 4, 8, 0, 6 },
                { 9, 6, 1, 5, 3, 7, 2, 8, 0 },
                { 2, 8, 7, 4, 1, 9, 6, 3, 5 },
                { 0, 4, 5, 2, 8, 6, 1, 7, 9 },
            },
            // Level 3: Hard (20 blanks)
            {
                { 5, 3, 0, 0, 7, 0, 0, 0, 2 },
                { 6, 0, 2, 1, 9, 5, 3, 0, 0 },
                { 0, 9, 8, 0, 4, 2, 5, 6, 0 },
                { 8, 5, 9, 7, 0, 1, 0, 2, 3 },
                { 4, 2, 6, 0, 5, 0, 7, 9, 1 },
                { 7, 1, 0, 9, 2, 4, 8, 0, 6 },
                { 9, 6, 1, 5, 0, 7, 2, 8, 0 },
                { 2, 8, 7, 4, 1, 9, 0, 3, 5 },
                { 0, 4, 5, 2, 8, 0, 1, 7, 9 },
            },
            // Level 4: Very Hard (51 blanks)
            {
                { 0, 0, 0, 6, 0, 0, 4, 0, 0 },
                { 7, 0, 0, 0, 0, 3, 6, 0, 0 },
                { 0, 0, 0, 0, 9, 1, 0, 8, 0 },
                { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 5, 0, 1, 8, 0, 0, 0, 3 },
                { 0, 0, 0, 3, 0, 6, 0, 4, 5 },
                { 0, 4, 0, 2, 0, 0, 0, 6, 0 },
                { 9, 0, 3, 0, 0, 0, 0, 0, 0 },
                { 0, 2, 0, 0, 0, 0, 1, 0, 0 },
            },
            // Level 5: Expert (63 blanks)
            {
                { 8, 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 0, 3, 6, 0, 0, 0, 0, 0 },
                { 0, 7, 0, 0, 9, 0, 2, 0, 0 },
                { 0, 5, 0, 0, 0, 7, 0, 0, 0 },
                { 0, 0, 0, 0, 4, 5, 7, 0, 0 },
                { 0, 0, 0, 1, 0, 0, 0, 3, 0 },
                { 0, 0, 1, 0, 0, 0, 0, 6, 8 },
                { 0, 0, 8, 5, 0, 0, 0, 1, 0 },
                { 0, 9, 0, 0, 0, 0, 4, 0, 0 },
            }
            };

            const char* levelNames[6] = {
                "Very Easy", "Easy", "Medium", "Hard", "Very Hard", "Expert"
            };

            while(true)
            {
                clearScreen();
                Multi_Tabs_1 cout << "SUDOKU\n\n";

                Multi_Tabs_2 cout << "Difficulty:\n\n";
                Multi_Tabs_3 cout << "1: Very Easy\n";
                Multi_Tabs_3 cout << "2: Easy\n";
                Multi_Tabs_3 cout << "3: Medium\n";
                Multi_Tabs_3 cout << "4: Hard\n";
                Multi_Tabs_3 cout << "5: Very Hard\n";
                Multi_Tabs_3 cout << "6: Expert\n\n";
                Multi_Tabs_3 cout << "HOME/END/X: Menu\n\n";

                int SudokuLevel = 0;
                while(true)
                {
                    Sleep(Time_Delay);
                    if(kbhit())
                    {
                        KEY = ReadKey(); Key_Hit_Maintainor();
                        if (KEY >= '1' && KEY <= '6') { SudokuLevel = KEY - '0'; break; }
                        if (KEY == 'X' || KEY=='x' || KEY==LEFT_KEY || KEY == HOME_KEY || KEY == END_KEY) goto Menu;
                    }
                }

                clearScreen();


                Multi_Tabs_1 cout << "\tSUDOKU GAME\n\n";
                Multi_Tabs_1 cout << "[ " << levelNames[SudokuLevel-1] << " Level ]\n\n";
                cout<<"Fill blanks(.) with 1-9. Arrow Keys=move, 0=clear.\n*=selected, `=your fill. Can't change given numbers.\n\n";
                Multi_Tabs_3 cout << "Fill all dots to complete!\n\n";
                int Sudoku[101]= {0}, cnt, row=0, col=0, Index=11, Value=0, i, j, k;  //Sudoku holo Main Array jeti sokol index Value contain korbe, etake 2D array hisebeo NewLine a jaito but ami neini
                bool Temp[101]={false}, Markerer[101] = {false};   // ei string-tar kaj holo, jate given index gulor value ami poriborton korte na pari.
                Markerer [Index] = true;

                //Given Index Value (below) <-- Eigulo ami amar iccha onujayi sohoj vabe diyechi, onno jekono proper value input dewa jabe
                /* srand(time(NULL)); */

                //Pass the Values from 3D Puzzles to 1D Sudoku
                for(i=0;i<9;i++)
                {
                    for(j=0;j<9;j++)
                    {
                        Sudoku[(i+1)*10+(j+1)] = puzzles[SudokuLevel-1][i][j];
                    }
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

                NewLine NewLine

                while(true)
                {
                    bool flag= true;

                    cout<<"\r";

                    Multi_Tabs_3 cout << "*=Selected  .=Blank  N`=Yours  N=Given\n";
                    Multi_Tabs_3 cout << "Arrows=Move  1-9=Fill  0=Clear  X/End=Quit\n\n";

                    hideCursor();

                    while(true)
                    {
                        Sleep(Time_Delay);

                        if (kbhit())           //Control by arrow KEY
                        {
                            KEY = ReadKey();      Key_Hit_Maintainor();

                            if    (KEY==UP_KEY    || KEY=='w')  {row--;break;}
                            if    (KEY==DOWN_KEY  || KEY=='s')  {row++;break;}
                            if    (KEY==LEFT_KEY  || KEY=='a')  {col--;break;}
                            if    (KEY==RIGHT_KEY || KEY=='d')  {col++;break;}
                            if    (KEY>='0' && KEY<='9') {Value= KEY-'0'; break;}
                            if    (KEY=='X') goto Menu;
                            if    (KEY==HOME_KEY || KEY==END_KEY) goto Menu;

                        }
                        row+=9; row%=9;
                        col+=9; col%=9;

                    }

                    Index=10*(row+1)+(col+1);
                    Markerer[Index] = true;
                    if    (!(KEY>='0' && KEY<='9')) {flag= false;   goto Sudoku_Print_Field;}

                    if(Temp[Index]) {/**cout << "\r\t\t\t\t\tIndex[" << row << "][" << col << "]\t  = ";cout << "Not Changeable\n\n"; */ flag = false; goto Sudoku_Print_Field; }  //Given Value gulo Change kora jabe na

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

                    Sudoku_Print_Field:

                    clearScreen();
                    Multi_Tabs_1 cout << "SUDOKU [" << levelNames[SudokuLevel-1] << "]\n\n";
                    Multi_Tabs_4 cout << "Fill all dots(.) with proper values.\n\n";
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

                    NewLine

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
        }
            break;

        case 7:

            while(1)
            {
                int Cri_Choise;

                Multi_Tabs_1 cout << "    CRICKET      \n\n";

                Multi_Tabs_1 cout << "Your Team : ";      if(!is_Team_named) cin >> Team_1; else cout<< Team_1 <<endl;
                Multi_Tabs_1 cout << "Opp  Team : ";      if(!is_Team_named) cin >> Team_2; else cout<< Team_2 <<endl;
                NewLine NewLine


                Multi_Tabs_1 cout << "Overs  : ";  if(!is_over_Wick_Selected) cin >>   Over_Total;  else cout<<Over_Total  <<endl;  if(Over_Total  <1) goto Menu;
                Multi_Tabs_1 cout << "Wickets: ";  if(!is_over_Wick_Selected) cin >> Wicket_Total;  else cout<<Wicket_Total<<endl;  if(Wicket_Total<1) goto Menu;
                NewLine NewLine

                if(!is_Tossing)
                {
                    int Your_Toss_Choise, Toss_Coin;

                    Multi_Tabs_1 cout<<"Tossing! H=Head T=Tail\n";

                    while(true)
                    {
                        Sleep(Time_Delay);
                        if (kbhit())           //Control by arrow KEY
                        {
                            KEY = ReadKey();

                            if    (KEY=='h' || KEY == 'H') {Your_Toss_Choise = 0; break;}
                            if    (KEY=='t' || KEY == 'T') {Your_Toss_Choise = 1; break;}
                        }
                    }

                    Toss_Coin = rand()%2;

                    if(Your_Toss_Choise == Toss_Coin)
                    {
                        Multi_Tabs_2 cout<<"You won Toss! 1=Bat First 2=Field First\n";

                        while(true)
                        {
                            Sleep(Time_Delay);
                            if (kbhit())           //Control by arrow KEY
                            {
                                KEY = ReadKey();

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
                Multi_Tabs_1 cout << symbol(2) << " " << Team_1 << "  vs  " << Team_2 << " " << symbol(2) <<endl<<endl;
                Multi_Tabs_1 cout<< Over_Total << " Over | " << Wicket_Total << " Wicket"<<endl<<endl<<endl;
//                cout << "CRICKET: Press 0-6. Same number = Wicket. Different = Run. More runs win!\n\n";
                NewLine

                switch (Cri_Choise){

                    case 1:

                        while(true)
                        {
                            int over = Over_Total, wick = Wicket_Total;
                            int Run= 0, w= 0, Ball= 0, temp;
                            int Hit, c, Hit_Op, i;

                            Multi_Tabs_2 cout << "Press 0-6 each ball:\n";

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
                                    Sleep(Time_Delay);
                                    if (kbhit())           //Control by arrow KEY
                                    {
                                        KEY = ReadKey();

                                        if    (KEY>='0' && KEY<='6')                        { break;}
                                        if    (KEY=='x' || KEY=='X' || KEY==HOME_KEY || KEY==END_KEY)  {is_Team_named = false; is_over_Wick_Selected = false; is_Tossing = false; goto Menu;}
                                        if    (KEY==RIGHT_KEY || KEY==' ')                         {KEY=rand()%7 +'0';   break;}

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
                                    Sleep(Time_Delay);
                                    if (kbhit())           //Control by arrow KEY
                                    {
                                        KEY = ReadKey();

                                        if    (KEY>='0' && KEY<='6')                            { break;}
                                        if    (KEY=='x' || KEY=='X' || KEY==HOME_KEY || KEY==END_KEY)      {is_Team_named = false; is_over_Wick_Selected = false; is_Tossing = false; goto Menu;}
                                        if    (KEY==RIGHT_KEY || KEY==' ')                             {KEY=rand()%7 +'0';   break;}

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

                            Multi_Tabs_2 cout << "Press 0-6 each ball:\n";

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
                                    Sleep(Time_Delay);
                                    if (kbhit())           //Control by arrow KEY
                                    {
                                        KEY = ReadKey();

                                        if    (KEY>='0' && KEY<='6') { break;}
                                        if    (KEY=='x' || KEY=='X' || KEY==HOME_KEY || KEY==END_KEY) { is_Team_named = false; is_over_Wick_Selected = false; is_Tossing = false; goto Menu;}
                                        if    (KEY==RIGHT_KEY || KEY==' ')              {KEY=rand()%7 +'0';   break;}

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
                                    Sleep(Time_Delay);
                                    if (kbhit())           //Control by arrow KEY
                                    {
                                        KEY = ReadKey();

                                        if    (KEY>='0' && KEY<='6')                            { break;}
                                        if    (KEY=='x' || KEY=='X' || KEY==HOME_KEY || KEY==END_KEY)      {is_Team_named = false; is_over_Wick_Selected = false; is_Tossing = false; goto Menu;}
                                        if    (KEY==RIGHT_KEY || KEY==' ')                             {KEY=rand()%7 +'0';   break;}

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
                int Choice = 2;

                MiniMenu:

                Choice+=2;
                //                if(KEY==UP_KEY)  Choice-=2;
                if(Choice>4) Choice-=4;

                switch(Choice){

                    case 1:
                        while(1)
                        {
                            int Bulet,Kil=0,Shoot,Diffc,Temp=100 ;

                            Multi_Tabs_1  cout<<"SHOOTING GAME\n\n";

                            Multi_Tabs_3 cout<<"Difficulty (positive int): ";
                            cin>>Diffc ;
                            if(Diffc <0) goto Menu;

                            Multi_Tabs_3 cout<<"Bullets: ";
                            cin>>Bulet;

                            int Enimi = ceil(Bulet/1.0/(Diffc +1));  // avarage luck

                            Multi_Tabs_3 cout<<"Target to Kill: "<<Enimi<<endl;

                            NewLine Multi_Tabs_2 cout<<"Any KEY=Shoot  HOME/END/X=Quit\n\n";


                            for(int i=1;i<=Bulet;i++)
                            {
                                /* srand(time(NULL)); */
                                Temp++;

                                KEY = ReadKey();
                                if (KEY=='x' || KEY=='X' || KEY==HOME_KEY || KEY==END_KEY) goto Menu;

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
                                    Sleep(Time_Delay);
                                    if (kbhit())           //Control by arrow KEY
                                    {
                                        KEY = ReadKey();      Key_Hit_Maintainor();

                                        if(KEY=='h' || KEY == 't' || KEY == 'x' || KEY==LEFT_KEY) break;
                                        if(KEY=='H' || KEY == 'T' || KEY == 'X' || KEY==RIGHT_KEY) break;

                                    }
                                }

                                clearScreen();
                                if(KEY==LEFT_KEY) goto Menu;
                                if(KEY==RIGHT_KEY) break;
                                you=toupper(KEY);
                                if(you!='H' && you!= 'T') break;

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

                            Multi_Tabs_3 cout<<"Difficulty (positive int): ";
                            cin>>Diffc ;
                            if(Diffc <0) goto Menu;

                            Multi_Tabs_3 cout<<"RPG count: ";
                            cin>>Bulet;

                            int Enimi = ceil(Bulet/1.0/(Diffc +1));  // avarage luck

                            Multi_Tabs_3 cout<<"Target Tanks: "<<Enimi<<endl;

                            Multi_Tabs_2 cout<<"Any KEY=Launch  HOME/END/X=Quit\n\n";


                            for(int i=1;i<=Bulet;i++)
                            {
                                Temp++;

                                KEY = ReadKey();
                                if (KEY=='x' || KEY=='X' || KEY==HOME_KEY || KEY==END_KEY) goto Menu;

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
                                    Sleep(Time_Delay);

                                    if (kbhit())           //Control by arrow KEY
                                    {
                                        KEY = ReadKey();      Key_Hit_Maintainor();

                                        if(KEY=='r' || KEY == 'p' || KEY == 's' || KEY == 'x' || KEY==LEFT_KEY) break;
                                        if(KEY=='R' || KEY == 'P' || KEY == 'S' || KEY == 'X' || KEY==RIGHT_KEY) break;

                                    }
                                }

                                if(KEY==LEFT_KEY) goto Menu;
                                if(KEY==RIGHT_KEY) break;

                                you = toupper(KEY);
                                clearScreen();

                                if(you=='X') break;

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
                                    clearScreen();
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
            Multi_Tabs_2 cout << "Closed\n";
            Multi_Tabs_2 cout << ""<<Coder_Name<<endl;

            Multi_Tabs_2  cout << "Special Thanks: Sharif Uddin\n\n";

            getch();
//            Multi_Tabs_2 cout << "Jajakallahu Khairan\nMeet Again InshaAllah\n";

            getch();
            cout<<"\nPolling: "<<KeyHit_Cheak_Count<<endl;

            return 0;

        default:
            goto Menu;

    }
    goto Menu;
}


