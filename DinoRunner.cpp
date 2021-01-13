//Windows
#include <windows.h>
#include <bits/stdc++.h>
#include <comdef.h>
using namespace std;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" )
bool Installed_Java(){
    size_t Size = WinExec("java.exe",SW_HIDE);
    HWND Window = FindWindowA("ConsoleWindowClass",NULL);
    if(Window){
        ShowWindow(Window,SW_HIDE);
    }
    return Size > 31 ;
}
int main(){
    if(!Installed_Java()){
        if(MessageBoxA(NULL,"You aren't install java! Install it?","Error",MB_YESNO|MB_ICONERROR)==IDYES){
            system("start http://download.fixdown.com/soft/java864.exe");
        }
        else
        {
            return 0;
        }
    }
    system("java -jar path_to_dino");
    return 0;
}