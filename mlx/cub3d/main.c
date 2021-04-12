#include <stdio.h>

int main()
{
	int	i;
	int	k;

	int	big_tmp;
	int	dist[5];

	dist[0] = 5;
	dist[1] = 2;
	dist[2] = 7;
	dist[3] = 1;
	dist[4] = 3;

	i = 0;

	while (i < 5)
	{

		k = i;
		while (k < 5)
		{
			if (dist[i] > dist[k])
			{
				big_tmp = dist[i];
				dist[i] = dist[k];
				dist[k] = big_tmp;
			}
			k++;
		}
		i++;
	}
	i = 0;
	while (i < 5)
	{
		printf("%d\n", dist[i]);
		i++;
	}
	
}