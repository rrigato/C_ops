#include "stdio.h"
#include "stdlib.h"
#include "string.h"
//can we assume that you will use a switch
//and the order of arguements will be ./ <executable name> cat -nET "file.txt"
//formating of -n switch leaves a 
int cat_check ( char *);
int main ( int argc, char * argv [])
{
	//exits the program if three arguements are not provided
	//if (argc != 4)
	//	exit(1);
	// gets seperate pointers for each string to test which commands the user entered.
	char * first_arg = argv[0];
	char * second_arg = argv[1];
	char * third_arg = argv[2];
	
	
	//check to make sure command is cat
	if (!cat_check (first_arg))
		exit(1);
	

	int Switch_count ;
	FILE * fp = NULL;
	if (argc ==3)
	{
		fp = fopen(third_arg, "r");
	}
	else if (argc ==2)
	{
		fp = fopen(second_arg, "r");
	}
	char letter ;
	int i = 1;
	int count = 0;
	if (fp)
	{
		if (argc ==3)
		{

			if (second_arg[1]== 'n' || second_arg[2] == 'n' || second_arg[3] == 'n')
				printf("\t%d ", i);
			while ((letter = getc(fp))!=EOF)
			{
				//checks if any of elements 1-3 of second arguement have the switch of T
				//element 0 will not have a switch because that has the dash for the option
				if ( letter == '\t' && (second_arg[1] =='T' || second_arg[2] == 'T' ||second_arg[3] =='T'))
					printf ("^I");
				else 

				{
					//checks letter read in for escape clause and prints a $ if E is selected as an option BEFORE the 
					//escape clause is shown on the screen
					if(letter == '\n' && (second_arg[1]== 'E' || second_arg[2] == 'E' || second_arg[3] == 'E'))
							{ printf("$");}
					printf("%c", letter);
					//checks letter read in for escape clause and prints line number AFTER the line is returned
					if (letter == '\n' && (second_arg[1]== 'n' || second_arg[2] == 'n' || second_arg[3] == 'n'))
						{++i; printf("\t%d ", i);}
				}
			}
		}

		else if (argc ==2) 
		{
			while ((letter = getc(fp))!= EOF)
			{
				printf("%c", letter);
			}
		}

		fclose (fp);	

	}
	else
	{ printf("Error could not open file");
		exit(1);
	}

	
	
}
int cat_check (char * first_arg)
{
	char CAT [] = "./cat";
	//returns 0 if equal <0 if string 1 is less >0 if str1 is greater
	if (!strcmp(first_arg, CAT))
		return 1;
	else return 0;
}


