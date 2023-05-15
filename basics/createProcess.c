#include <windows.h>
#include <stdio.h>
int main(void){
	
	STARTUPINFOW si = {0};
	PROCESS_INFORMATION pi = {0};




    CreateProcessW(
        L"C:\\Windows\\System32\\notepad.exe",
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

	printf("[*] Process started,\n	PID: %d, hProcess: %x\n	TID: %d, hThread: %x\n", pi.dwProcessId, pi.hProcess, pi.dwThreadId, pi.hThread);

	WaitForSingleObject(
		pi.hProcess, // handle to the created notepad process
		INFINITE // only return when signaled, no timeout
	);

	CloseHandle(
		pi.hProcess
	);

	printf("[*] Process closed!");
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


DWORD WaitForSingleObject(
  [in] HANDLE hHandle,
  [in] DWORD  dwMilliseconds
);
*/