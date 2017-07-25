/*
CPSC 351 - Assignment 1
System Calls
Group Members:
	Vimean Chea
	Kader Ustun
	Dana Shorts
	Jasem Altaweel
*/
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


int main() {

    string usrCmd;
    pid_t pid;

	do
	{
        cerr << "cmd>";
        cin >> usrCmd;
        
        
		if (usrCmd != "exit")
		{
            
            pid = fork();


			if (pid < 0) {
				printf ("Fork was unsuccessful.\n");
				return -1;
			}
			else if (pid == 0) {
				execlp (usrCmd.c_str(), usrCmd.c_str(), NULL);
			}
			else {
				wait(NULL);
				printf ("Child command completed.\n");
			}

		}
	}
	while (usrCmd != "exit");
	
return 0;
}
