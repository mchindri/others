nclude <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 *  * Auto-generated code below aims at helping you parse
 *   * the standard input according to the problem statement.
 *    **/

int seen[500];
int m[500][500];

int ft_min(int n, int N)
{
	int min = -1;
	if (seen[n] == -1)
		return 1;
	seen[n] == 1;
	int i;
	for (i = 0; i < N; i++)
	{
		if (m[n][i] == 1 && seen[i] == 0)
		{
			int aux;
			aux = ft_min(i,N);
			if (min== -1 || (min != -1 && aux < min))
				min = aux;
		}
	}
	seen[n] = 0;
	return min;
}


int main()
{
	int N; // the total number of nodes in the level, including the gateways
	int L; // the number of links
	int E; // the number of exit gateways
	scanf("%d%d%d", &N, &L, &E);


	/* for(int i = 0; i < N; i++)
	 *          for(int j = 0; j < N; j++)
	 *                       m[i][j] = seen[i] =0;
	 *                       */
	for (int i = 0; i < L; i++) {
		int N1; // N1 and N2 defines a link between these nodes
		int N2;
		scanf("%d%d", &N1, &N2);
		m[N1][N2] = 1;
		m[N2][N1] = 1;
	}
	int g[20];
	for (int i = 0; i < E; i++) {
		int EI; // the index of a gateway node
		scanf("%d", &EI);
		g[i] = EI;
	}


	while (1) {
		int min;
		int min_ki;
		int min_k;
		int min_i;
		int SI; 
		scanf("%d", &SI);
		seen[SI] = -1;

		min_ki = -1;
		int aux;
		for(int k; k < E; k++)
		{
			min_i = -1;
			for(int i = 0; i < N; i++)
			{
				if (m[g[k]][i] == 1)
				{

					seen[g[k]] = 1;
					if (seen[i] != 1)
					{
						aux = ft_min(i,N);
						if (min_i == -1)
						{
							min_i = i;
							min = aux;
						}
						else if (aux < min)
						{
							min_i = i;
							min = aux;
						}
					}

					seen[g[k]] = 0;
				}
			}
			if (min_ki == -1)
			{
				min_ki = min_i;
				min_k = min;
			}
			else if (min < min_k)
			{
				min_ki = min_i;
				min_k = min;
			}
		}

		printf("%d %d\n", min_ki,g[min_ki]); 
	}

	return 0;
}
