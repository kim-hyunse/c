#include <stdio.h>

#define MAXNUM 1000

void findMax(int local_array[]);

	int main()

{
	
	int numList[MAXNUM];

	findMax(numList);
	return 0;
}
)
{
	int  max = local_array[0];
	for (int i = 0; i < MAXNUM; i++)
	{
	
	if (max < local_array[i])
		max = local_array[i];
	printf(" % d", max);
    }
}