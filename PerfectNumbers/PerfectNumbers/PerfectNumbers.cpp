// PerfectNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPerfect(int);

int _tmain(int argc, _TCHAR* argv[])
{
	if (argc != 5)
	{
		perror("Usage: <prog_name> <lower_bound> <upper_bound> <step> <part>");
		exit(1);
	}

	int low, high, step, part;

	low = _tstoi(argv[1]);
	high = _tstoi(argv[2]);
	step = _tstoi(argv[3]);
	part = _tstoi(argv[4]);

    //round numbers to nearest evens
	low += low % 2;
	high -= high % 2;

	int oddStep = 2 * step;
	int oddPart = 2 * part;

	for (int i = low; i <= high; i += oddStep)
		if (isPerfect(i + oddPart))
			printf("\n%d", i + oddPart);

	//getchar();

	return 0;
}

int isPerfect(int n)
{
	int tempSum = 0;

	//We don't know if there are any odd perfect numbers,
	//but we know there are none that fit in our data types
	if (n % 2 == 1)
		return 0;
	
	for (int i = 2; i < n; i++)
		if (n % i == 0)
		{
			if (i > n / i)
				break;
			tempSum += i;
			tempSum += n / i;
		}	
	
	//1 is also a factor
	tempSum++;

	if (n == tempSum)
		return 1;
	return 0;
}