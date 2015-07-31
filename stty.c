#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "termios.h"
#include "unistd.h"
int option(char *);
void echo_option( int, char *);
void a_option (char *);
void erase(char *, char );
void iuclc_option(int, char *);
int main(int argc, char * argv[])
{
	if (argc !=2 && argc!= 3)
	{
		printf("stty: invalid number of arguements \n");
		printf("Try 'stty--help' for more information.\n");
		exit(1);
	}
	
	char * option_check = argv[1];
	int return_value = 0;
	
	return_value = option(option_check);
	switch(return_value){
		case 1:
			echo_option(return_value, option_check);
			break;
		case 2:
			echo_option(return_value, option_check);
			break;
		case 3:
			a_option(option_check);
			break;
		case 4:
			{
				if (argc !=3)
				{
					printf("stty: invalid number of arguements \n");
					printf("Try 'stty--help' for more information.\n");
					exit(1);
				}
				char new_erase_key = argv[2][0];
				erase(option_check, new_erase_key);
				break;
			}
		default:
			iuclc_option(return_value, option_check);
			break;
	
	}
	return 0;
}




//  returns 1 if echo, 2 if -echo, 3 if -a, 4 if erase, 5 if iuclc, 6 if -iuclc
//prints an error otherwise 
int option(char * option_check)
{
	int selected = 0;	
	char echo[] = "echo";
	char dash_echo[] = "-echo";
	char a[] = "-a";
	char erase[] = "erase";
	char iuclc[] = "iuclc";
	char dash_iuclc[] = "-iuclc";

	if (strcmp(option_check, echo) == 0)
	{
		selected += 1;
	}
	if (strcmp(option_check, dash_echo) == 0)
	{
		selected += 2;
	}
	if (strcmp(option_check, a) == 0)
	{
		selected += 3;
	}
	if (strcmp(option_check, erase) == 0)
	{
		selected += 4;
	}
	
	if (strcmp(option_check, iuclc) == 0)
	{
		selected += 5;
	}
	if (strcmp(option_check, dash_iuclc) == 0)
	{
		selected += 6;
	}
	if (selected == 0 )
	{
		printf("stty: invalid arguement %s\n", option_check);
		printf("Try 'stty--help' for more information.\n");
		exit(1);
	}
	return selected;
}


void echo_option( int value, char * option_name)
{
	struct termios info;
	if( tcgetattr( 0, &info ) == -1 )
	{
		perror ("tcgetattr");
		exit(1);
	}
	//update setting
	if (value ==1)
	{
		info.c_lflag |= ECHO;
	}
	else
		info.c_lflag &= ~ECHO;
	//send settings back
	if( tcsetattr( 0, TCSANOW, &info ) == -1 )
        {
		perror("tcsetattr");
		exit(1);
	}
	

}

void a_option (char * option_name)
{
	struct termios info;
	if( tcgetattr( 0, &info ) == -1 )
	{
		perror ("tcgetattr");
		exit(1);
	}
	
	if (info.c_iflag & IMAXBEL)
		printf("The IMAXBEL bit is ON.\n");
	else
		printf("The IMAXBEL bit is OFF.\n");
	
	if (info.c_iflag & IXOFF)
		printf("The IXOFF bit is ON.\n");
	else
		printf("The IXOFF bit is OFF.\n");

	if (info.c_iflag & IXANY)
		printf("The IXANY bit is ON.\n");
	else
		printf("The IXANY bit is OFF.\n");



	if (info.c_oflag & VTDLY)
		printf("The VTDLY bit is ON.\n");
	else
		printf("The VTDLY bit is OFF.\n");

	if (info.c_oflag & FFDLY)
		printf("The FFDLY bit is ON.\n");
	else
		printf("The FFDLY bit is OFF.\n");
		
	if (info.c_oflag & BSDLY)
		printf("The BSDLY bit is ON.\n");
	else
		printf("The BSDLY bit is OFF.\n");
		
		
		
	if (info.c_cflag & CRTSCTS)
		printf("The CRTSCTS bit is ON.\n");
	else
		printf("The CRTSCTS bit is OFF.\n");

	if (info.c_cflag & CLOCAL)
		printf("The CLOCAL bit is ON.\n");
	else
		printf("The CLOCAL bit is OFF.\n");
		
	if (info.c_cflag & HUPCL)
		printf("The HUPCL bit is ON.\n");
	else
		printf("The HUPCL bit is OFF.\n");



	if (info.c_lflag & FLUSHO)
		printf("The FLUSHO bit is ON.\n");
	else
		printf("The FLUSHO bit is OFF.\n");

	if (info.c_lflag & PENDIN)
		printf("The PENDIN bit is ON.\n");
	else
		printf("The PENDIN bit is OFF.\n");
		
	if (info.c_lflag & TOSTOP)
		printf("The TOSTOP bit is ON.\n");
	else
		printf("The TOSTOP bit is OFF.\n");



	if (info.c_lflag & FLUSHO)
		printf("The FLUSHO bit is ON.\n");
	else
		printf("The FLUSHO bit is OFF.\n");

	if (info.c_lflag & PENDIN)
		printf("The PENDIN bit is ON.\n");
	else
		printf("The PENDIN bit is OFF.\n");
		
	if (info.c_lflag & TOSTOP)
		printf("The TOSTOP bit is ON.\n");
	else
		printf("The TOSTOP bit is OFF.\n");		
		
}
void erase(char * option_name, char new_key)
{
	struct termios info;
	if( tcgetattr( 0, &info ) == -1 )
	{
		perror ("tcgetattr");
		exit(1);
	}
	info.c_cc[VERASE] = new_key;
	if( tcsetattr( 0, TCSANOW, &info ) == -1 )
        {
		perror("tcsetattr");
		exit(1);
	}
	
}

void iuclc_option(int value, char * option_name)
{

	struct termios info;
	if( tcgetattr( 0, &info ) == -1 )
	{
		perror ("tcgetattr");
		exit(1);
	}
	//update setting
	if (value ==5)
	{
		info.c_iflag |= IUCLC;
	}
	else
		info.c_iflag &= ~IUCLC;
	//send settings back
	if( tcsetattr( 0, TCSANOW, &info ) == -1 )
        {
		perror("tcsetattr");
		exit(1);
	}
	
}

