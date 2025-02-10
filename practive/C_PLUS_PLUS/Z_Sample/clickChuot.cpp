#include <iostream>
#include <stdio.h>
#include <windows.h>

//Khai b�o c�c bi?n to�n c?c
HANDLE hStdin;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

//Ghi l?i v� tho�t ra
VOID WriteError (LPSTR lpszMessage){ 
    printf("%s\n", lpszMessage); 
    ExitProcess(0); 
}

//H�m n�y cho ph�p di chuy?n con tr? ghi c?a std l�n b?t c? v? tr� x,y n�o tr�n console
void gotoXY(int x, int y){ 
    CursorPosition.X = x; 
    CursorPosition.Y = y; 
    SetConsoleCursorPosition(console,CursorPosition); 
}

// h�m n�y d? l?y v? tr� chu?t tr�n std
void GetMousePosWin(MOUSE_EVENT_RECORD mer)
{
    // Khai b�o c�c bi?n m� h�m c?n
    int x,y;
    INPUT_RECORD Inrec;
    DWORD eventRead;
    HANDLE hStdIn;
    DWORD dwMode;
    bool Captured=false;
    hStdIn = GetStdHandle(STD_INPUT_HANDLE);
    dwMode = ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;

    //Ki?m tra xem console d� ? ch? d? ch?p nh?n input t? chu?t chua
    if( SetConsoleMode( hStdIn, dwMode | ENABLE_MOUSE_INPUT) == TRUE)

        GetConsoleMode(hStdIn, &dwMode);
        SetConsoleMode(hStdIn, (dwMode & (ENABLE_MOUSE_INPUT)));

        // v�ng l?p n�y s? l?y c�c event c?a trong b? nh? ra d? x? l�
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

    // V�ng l?p d? qu�t qua c�c event 
    while (!counter)
    { 
        ReadConsoleInput(hStdin,irInBuf,128,&cNumRead);
        for (i = 0; i < cNumRead; i++) 
        {
            switch(irInBuf[i].EventType){
            case MOUSE_EVENT: // khi c� event c?a chu?t
                GetMousePosWin(irInBuf[i].Event.MouseEvent);
                break; 
            // ngo�i ra c�n c� event c?a b�n ph�m, c?a chu?t
            default: 
                break; 
            } 
        }
    } 

    return 0; 
}
