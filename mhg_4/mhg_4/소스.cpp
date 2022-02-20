#define MAXNUM 1000
void main()
{
	void findMax(int[MAXNUM]);
	int numList[MAXNUM];
	¡¦.
		findMax(numList);
	¡¦.
}
void findMax(int local_array[])
{
	int i, max = local_array[0];
	for (i = 1; i < MAXNUM; i = i + 1)
		if (max < local_array[i])
			max = local_array[i];
	printf(¡° % d¡±, max);
}
#define MAXNUM 1000
void main()
{
	int findMax(int[MAXNUM]);
	int numList[MAXNUM];
	¡¦.
		newmax = findMax(numList);
	¡¦.
}
int findMax(int local_array[])
{
	int i, max = local_array[0];
	for (i = 1; i < MAXNUM; i = i + 1)
		if (max < local_array[i])
			max = local_array[i];
	return max;
}