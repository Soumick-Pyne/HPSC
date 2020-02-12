#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<math.h>

using namespace std;

int main()
{
	int ans = 1;
	while (ans != 0)
	{
		int i, j;
		double l = 0;
		const int n = 1000;
		double a[n][n], b[n][1], x[n][1], T[n][1],T_dash[n][1], e, k;
		cout << "[a].[x]=[b]" << endl;
		/*cout << "Enter Matrix a:" << endl;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				cout << "a[" << i << "," << j << "] = ";
				cin >> a[i][j];
			}
		cout << "Enter Matrix b:" << endl;
		for (i = 0; i < n; i++)
		{
			cout << "b[" << i << "][0] = ";
			cin >> b[i][0];
		}*/
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
			{
				if (i == j)
					a[i][j] =  1000;
				else
					a[i][j] = 1;
			}
		for (i = 0; i < n; i++)
		{
			b[i][0]= 1999;
		}
		e = 0.0000000001;
		for (i = 0; i < n; i++)
		{
			T[i][0] = 0;
			T_dash[i][0] = 0;
		}
		l = 0;
		while (1)
		{
			cout << "\nIteration no: " << l << "\n";
			for (i = 0; i < n; i++)
			{
				x[i][0] = (1 / a[i][i])*(b[i][0]);
				//cout << x[i][0] << " ";
				for (j = 0; j < n; j++)
				{
					if (j != i)
						x[i][0] = x[i][0] - (1 / a[i][i])*(a[i][j] * T[j][0]);
					//cout << x[i][0] << " ";
				}
				//cout << "\n";
				T_dash[i][0] = T[i][0];
				T[i][0] = x[i][0];
			}
			for (i = 0; i < n; i++)
			{
				k = fabs(x[i][0] - T_dash[i][0]);
				if (k >= e)
				{
					break;
				}
			}
			if (i == n)
			{
				break;
			}
			l++;

		};
		for (i = 0; i < n; i++)
			cout << "x" << i + 1 << "=" << x[i][0] << endl;

		//trying spectral radius calculation
		double p_G = 0, sum1 = 0, sum2 = 0, base = 0, expo = 0;
		for (i = 0; i < n; i++)
		{
			sum1 += (x[i][0] - T_dash[i][0])*(x[i][0] - T_dash[i][0]);
		}
		cout << sum1 << "\n";
		for (i = 0; i < n; i++)
		{
			sum2 += x[i][0] * x[i][0];
		}
		cout << sum2 << "\n";
		base = sum1 / sum2;
		cout << " base = " << base;
		expo = 1 / l;
		cout << "expo = " << expo;
		p_G = pow(base, expo);
		cout << "\nspectral radius of G matrix = " << p_G;
		cout << "\nconvergence rate = " << -1 * log(p_G);
		cout << "\ncontinue (1 or 0)?";
		cin >> ans;
	};
	_getch();
	return 0;
}

