
#include <windows.h>

int main(void){
	
	STARTUPINFOW si = {0};
	PROCESS_INFORMATION pi = {0};




    CreateProcessW(
        L"C:\\Windows\\System32\\calc.exe",
        NULL,
        NULL,
        NULL,
        FALSE,
        0,
		NULL,
		NULL,
		&si,
		&pi
    );

    return 0;

}

/*
BOOL CreateProcessW(
  [in, optional]      LPCWSTR               lpApplicationName,
  [in, out, optional] LPWSTR                lpCommandLine,
  [in, optional]      LPSECURITY_ATTRIBUTES lpProcessAttributes,
  [in, optional]      LPSECURITY_ATTRIBUTES lpThreadAttributes,
  [in]                BOOL                  bInheritHandles,
  [in]                DWORD                 dwCreationFlags,
  [in, optional]      LPVOID                lpEnvironment,
  [in, optional]      LPCWSTR               lpCurrentDirectory,
  [in]                LPSTARTUPINFOW        lpStartupInfo,
  [out]               LPPROCESS_INFORMATION lpProcessInformation
);
*/