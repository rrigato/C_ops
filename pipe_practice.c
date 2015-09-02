int main(int argc, char * argv[])
{
	int thepipe[2];
	pipe(thepipe);
	int return_value;
	return_value = fork();
	if (return_value ==0)
	{		
		close(thepipe[0]);
		dup2(thepipe[1], 1);
		close(thepipe[1]);
		excelp(argv[1], argv[1], NULL);


		
	}
	else
	{
		close(thepipe[1]);
		dup2(thepipe[0],0);
		execlp(argv[0],0);
	}
}
