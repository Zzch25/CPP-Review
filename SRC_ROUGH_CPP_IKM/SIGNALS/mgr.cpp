#include <iostream>
#include <csignal>
#include <sys/types.h>
#include <unistd.h>
#include "def.h"

using namespace std;

int main()
{
	//Another hyper simple example, again this is trivial stuuuph

	cout << "Trivial topic, minimal template code :: HOWEVER, bitwise IPC and ACK viable therefore kill included\n\n";

	signal(SIGINT, handler_sigint);
	raise(SIGINT);

	kill(getpid(),SIGINT);

	return 0;
}
