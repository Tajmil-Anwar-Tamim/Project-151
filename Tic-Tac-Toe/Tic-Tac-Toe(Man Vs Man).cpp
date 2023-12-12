#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#define TabM cout<<"\t\t\t\t\t\t";
#define TabM2 cout<<"\t\t\t\t     ";
#define new cout<<"\n";
#define StrM cout<<"* * * * ";
#define Str cout<<"* ";

using namespace std;

int main()
{
    while(1)
    {
        int i,Player_1=0,Player_2=0,Case=0,Win_1=0,Win_2=0;
        char Box_Data[10];
        char Box_Symbol[10];

        cout<<"\t\t\t\t\t       TIC TAC TIC\n";
        cout<<"\t\t\t\t\t       [Man vs Man]\n\n";

        TabM Str StrM new
        TabM Str cout<<"1 2 3 "; Str new
        TabM Str cout<<"4 5 6 "; Str new
        TabM Str cout<<"7 8 9 "; Str new
        TabM Str StrM new new

        cout<<"Who Play First?(Player-1 / Player-2)  {Press '1' or '2'} : ";
        int P;
        cin>>P;
        P=(P+1)%2+1;

        for(i=0;i<=9;i++)
        {
            Box_Data[i]=0;
        }

        for(i=0;i<=9;i++)
        {
            if(Box_Data[i]==0) Box_Symbol[i]=' ';
            if(Box_Data[i]==1) Box_Symbol[i]='x';
            if(Box_Data[i]==2) Box_Symbol[i]='o';

        }

        Print_Loop:///Print_Loop

        Box_Data[Player_1]=1;
        Box_Data[Player_2]=2;

        for(i=0;i<=9;i++)
        {
            if(Box_Data[i]==0) Box_Symbol[i]=' ';
            if(Box_Data[i]==1) Box_Symbol[i]='x';
            if(Box_Data[i]==2) Box_Symbol[i]='o';

        }

        new
        cout<<"\a";
        TabM Str StrM new
        TabM Str
        for(i=1;i<=9;i++)
        {
           cout<<Box_Symbol[i]<<" ";
           if(i%3==0) {Str new TabM Str }
        }

        StrM new new

        if(Case==0 && P==2) goto Player2;
        if(Case==0) ;
        else if(Case%2==1 && P==2 || Case%2==0 && P!=2) goto Back_2;
        else goto Back_1;

        while(1)
        {
            Player1:
                Case++;

                Recall_Player1:
                    cout<<"\nPlayer-1\t:\t";
                    cin>>Player_1;

                    if(Box_Data[Player_1]==1 || Box_Data[Player_1]==2)
                        {cout<<"Already Exist\n\n";goto Recall_Player1;}

                Box_Data[Player_1]=1;

                goto Print_Loop;

                Back_1:

                    if(Box_Data[1]==1 && Box_Data[2]==1 && Box_Data[3]==1 || Box_Data[4]==1 && Box_Data[5]==1 && Box_Data[6]==1 || Box_Data[7]==1 && Box_Data[8]==1 && Box_Data[9]==1 || Box_Data[1]==1 && Box_Data[4]==1 && Box_Data[7]==1 || Box_Data[2]==1 && Box_Data[5]==1 && Box_Data[8]==1 || Box_Data[3]==1 && Box_Data[6]==1 && Box_Data[9]==1 ||  Box_Data[3]==1 && Box_Data[5]==1 && Box_Data[7]==1 || Box_Data[1]==1 && Box_Data[5]==1 && Box_Data[9]==1 )
                    {
                        Win_1++;
                        break;
                    }

            Player2:
                Case++;

                Recall_Player2:///
                    cout<<"Player-2\t:\t";
                    cin>>Player_2;

                    if(Box_Data[Player_2]==1 || Box_Data[Player_2]==2)
                    {
                            cout<<"Already Exist\n\n";
                            goto Recall_Player2;
                    }

                Box_Data[Player_1]=2;

                goto Print_Loop;

                Back_2:

                if(Box_Data[1]==2 && Box_Data[2]==2 && Box_Data[3]==2 || Box_Data[4]==2 && Box_Data[5]==2 && Box_Data[6]==2 || Box_Data[7]==2 && Box_Data[8]==2 && Box_Data[9]==2 || Box_Data[1]==2 && Box_Data[4]==2 && Box_Data[7]==2 || Box_Data[2]==2 && Box_Data[5]==2 && Box_Data[8]==2 || Box_Data[3]==2 && Box_Data[6]==2 && Box_Data[9]==2 ||  Box_Data[3]==2 && Box_Data[5]==2 && Box_Data[7]==2 || Box_Data[1]==2 && Box_Data[5]==2 && Box_Data[9]==2 )
                {
                    Win_2++;
                    break;
                }

                if(Case==9) break;


        }

        cout<<"\a";
        new TabM2

        cout<<"\a";
        if(Win_1>0)cout<<"Congratulation! Player-1 is Winner.\n";
        else if(Win_2>0)cout<<"Congratulation! Player-2 is Winner.\n";
        else cout<<"\t\tMatch Drawn\n";



        new new new getch();
    }




}










