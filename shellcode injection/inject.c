#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[]){
    if (argc == 1){
        printf("[*] Usage: inject.exe <PID>");
        return 0;
    }

    int pid = atoi(argv[1]);
    printf("[*] PID: %d\n", pid);

    HANDLE hProc = OpenProcess(
        PROCESS_ALL_ACCESS,
        FALSE,
        pid
    );
    if (hProc == 0){
        printf("[*] Failed to obtain handle, exiting...");
        return 0;
    }
    printf("[*] Obtained handle: %x", hProc);



    return 0;

}