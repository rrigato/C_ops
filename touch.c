#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//int touch_check ( char *);
int touch_options( char *);
int main ( int argc, char * argv [])
{
	/*char * arg_0 = argv[0];
	if (touch_check(arg_0))
	{
		//good to proceed with the program
		printf("good to go");
	}
	else
	{
		printf("Error improper system command\n");
		exit(1);
	}*/
	char * option_check = NULL;
	char * file_name = NULL;
	option_check = argv[1];
	if (argc ==1)
	{
		printf("touch: missing file operand\n");
		printf("Try 'touch --help' for more information\n");
		exit(1);
	}
	if (option_check[0] =='-')
	{
		int options = 0;
		options = touch_options(option_check);
	}
	else
	{
		option_check = NULL;
		file_name = argv[1];
	}
	return 0;
}

int touch_options(char * second_arg)
{
	int i = 0;
	int result = 0;
	while (second_arg[i] != '\0')
	{
		i++;
	}
	if (i ==4)
	{
		if (	   (second_arg[1] =='m'||second_arg[2]=='m' || second_arg[3] == 'm')
			&& (second_arg[1] =='t'||second_arg[2]=='t' || second_arg[3] == 't')
			&& (second_arg[1] =='a'||second_arg[2]=='a' || second_arg[3] == 'a')    )
		{
			result =1;
			return result;
		}
		else
		{
			printf("improper options");
			exit(1);
		}

	}
	else if (i==3)
	{
		if (	   (second_arg[1] =='m'||second_arg[2]=='m')
			&& (second_arg[1] =='t'||second_arg[2]=='t')	)
		{
			result =2; return result;
		}

		else if (	  (second_arg[1] =='m'||second_arg[2]=='m')
				&&(second_arg[1] =='a'||second_arg[2]=='a')	)
		{
			result =3; return result;
		}

		else if (	  (second_arg[1] =='a'||second_arg[2]=='a')
				&&(second_arg[1] =='t'||second_arg[2]=='t')	)
		{
			result =4; return result;
		}
	}
	else if (i==2)
	{
		if ( second_arg[1] =='a')
		{
			result =5; return result;
		}
		else if ( second_arg[1] =='m')
		{
			result = 6; return result;
		}

		else if ( second_arg[1] =='t')
		{
			result = 7; return result;
		}

		
	}
}
/*
int touch_check (char * arg_0)
{
	char compare [] = "./touch";
	if (!strcmp(arg_0, compare) ==0)
		return 1;
	return 0;
}*/
