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
		close(thepipe[0]);
		dup2(thepipe[1],1);
		int thepipe2[2];
		pipe(thepipe2);
		return_value = fork();
		if (return_value == 0)
			execlp(argv[2],argv[2], NULL);
		else;
			wait();
	}
}
