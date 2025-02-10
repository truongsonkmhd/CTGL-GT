#include <iostream>
#include <stdio.h>
#include <windows.h>

//Khai báo các bi?n toàn c?c
HANDLE hStdin;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

//Ghi l?i và thoát ra
VOID WriteError (LPSTR lpszMessage){ 
    printf("%s\n", lpszMessage); 
    ExitProcess(0); 
}

//Hàm này cho phép di chuy?n con tr? ghi c?a std lên b?t c? v? trí x,y nào trên console
void gotoXY(int x, int y){ 
    CursorPosition.X = x; 
    CursorPosition.Y = y; 
    SetConsoleCursorPosition(console,CursorPosition); 
}

// hàm này d? l?y v? trí chu?t trên std
void GetMousePosWin(MOUSE_EVENT_RECORD mer)
{
    // Khai báo các bi?n mà hàm c?n
    int x,y;
    INPUT_RECORD Inrec;
    DWORD eventRead;
    HANDLE hStdIn;
    DWORD dwMode;
    bool Captured=false;
    hStdIn = GetStdHandle(STD_INPUT_HANDLE);
    dwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

    //Ki?m tra xem console dã ? ch? d? ch?p nh?n input t? chu?t chua
    if( SetConsoleMode( hStdIn, dwMode | ENABLE_MOUSE_INPUT) == TRUE)

        GetConsoleMode(hStdIn, &dwMode);
        SetConsoleMode(hStdIn, (dwMode & (ENABLE_MOUSE_INPUT)));

        // vòng l?p này s? l?y các event c?a trong b? nh? ra d? x? lý
        do
        {
            PeekConsoleInput(hStdIn, &Inrec, 1, &eventRead);
            if( eventRead ) 
            {
                ReadConsoleInput(hStdIn, &Inrec, 1, &eventRead);
                x= Inrec.Event.MouseEvent.dwMousePosition.X ;
                y= Inrec.Event.MouseEvent.dwMousePosition.Y ;
                switch (Inrec.EventType )
                {

                case MOUSE_EVENT:
                    {
                        Captured = true;
                        gotoXY(0,0);
                        std::cout << "x location  " << x << " ";
                        gotoXY(0,1);
                        std::cout << "y location  " << y << " ";
                        break;  
                    }
                }
            }

        }while(!Captured);
}


int main() 
{ 
    DWORD cNumRead, fdwMode, i; 
    INPUT_RECORD irInBuf[128]; 
    int counter=0;


    hStdin = GetStdHandle(STD_INPUT_HANDLE); 
    fdwMode = ENABLE_EXTENDED_FLAGS; 
    fdwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT; 

    // Vòng l?p d? quét qua các event 
    while (!counter)
    { 
        ReadConsoleInput(hStdin,irInBuf,128,&cNumRead);
        for (i = 0; i < cNumRead; i++) 
        {
            switch(irInBuf[i].EventType){
            case MOUSE_EVENT: // khi có event c?a chu?t
                GetMousePosWin(irInBuf[i].Event.MouseEvent);
                break; 
            // ngoài ra còn có event c?a bàn phím, c?a chu?t
            default: 
                break; 
            } 
        }
    } 

    return 0; 
}
