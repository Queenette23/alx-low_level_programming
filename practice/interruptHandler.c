// #include "shell.h" void interruptHandler(int sig_num){	sig_num = sig_num;	fflush(stdout);fflush(stdin);	exit(0);}
#include "shell.h"

void interruptHandler(int sig_num)
{
	sig_num = sig_num;
	fflush(stdout);
	fflush(stdin);
	exit(0);
}

int main()
{
	// Register the interrupt handler function
	signal(SIGINT, interruptHandler);

	// Rest of the code goes here...
}
