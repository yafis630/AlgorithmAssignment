#include <stdio.h>
int max(int a, int b) 
{
	if(a>b)
	return a;
	else
    return b;
 }

int knapSack(int c, int wt[], int val[], int n)
{
int i, w;
    int table[n + 1][c + 1];
  
    for (i = 0; i <= n; i++) 
    {
        for (w = 0; w <= c; w++) 
        {
            if (i == 0 || w == 0)
                table[i][w] = 0;
            else if (wt[i - 1] <= w)
                table[i][w] = max(val[i - 1]
                          +table[i - 1][w - wt[i - 1]],
                          table[i - 1][w]);
            else
                table[i][w] = table[i - 1][w];
        }
    }
  
    return table[n][c];
}

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int c = 50;
	int n = sizeof(val) / sizeof(val[0]);
	printf("%d", knapSack(c, wt, val, n));
	return 0;
}

