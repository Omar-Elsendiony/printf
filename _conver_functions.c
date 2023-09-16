void reverseArr (char *arr, int size)
{
	int i = 0;
	int j = 0;
	int tmp = 0;

	while (arr[i] && i < size)
	{
		++i;
	}
	j = i - 1;
	i = 0;
	while (i < j)
	{
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
		++i;
		--j;
	}
}

void converIntToStr(char *arr, int num, int size)
{
	int tmp = 0;
	int i = 0;

	while (num != 0 && i < size)
	{
		tmp = num % 10;
		num /= 10;
		arr[i] = '0' + tmp;
		++i;
	}
	reverseArr (arr, size);
}
