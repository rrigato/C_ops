{
	int thepipe[2];
	pipe(thepipe);
	int return_value;
	return_value = fork();
	if (return_value ==0)
	{
		excelp(argv[1], argv[2]
}
