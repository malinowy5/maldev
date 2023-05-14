#include <windows.h>

int main(void){
    MessageBoxW(
        NULL,
        L"testboxłł",
        L"box1",
        MB_OK | MB_ICONINFORMATION
    );

    return 0;

}