
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void get_signal(int signo)
{
    write(1,"asdasda\n",8);
    sleep(5);
}

int	main(void)
{	
	signal(SIGINT, (void *)get_signal);
	while (1)
    {

    }
}