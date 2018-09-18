
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
/*

33可以表示为： 33 = 14 + 7562 / 398
还可以表示为： 33 = 21 + 5796 / 483
可以看到，在上述表示中， 1 ~ 9 这几个数字都只出现一次（不包括0）
类似这样的表示方法，33 有 8 种表示法

输入描述：
一个正整数 N （ N < 1000 * 1000 ）
输出描述：
输出数字 N 用 1 ~ 9 不重复不遗漏地组成上述表示的全部种数

*/

int get_len(int x)
{
	int len = 0;
	while (x > 0)
	{
		x = x / 10;
		len++;
	}
	return len;
}

int check_xyz(int x, int y, int z)
{
	int a[10] = { 0 };
	int i = 0, j = 0;
	int tx = 0, ty = 0, tz = 0;
	if ( y%z != 0)
	{
		return 1;
	}
	int len = get_len(x) + get_len(y) + get_len(z);
	if (len != 9)
	{
		return 1;
	}
	//printf("xyz = %d/%d/%x\n", x, y, z);
	for (i = 0; i < 9; )
	{
		//printf(" i = %d\n", i);
		tx = x % 10;
		if (tx > 0 && tx <= 9)
		{
			a[i++] = tx;
			x = x / 10;
		}


		ty = y % 10;
		if (ty>0 && ty <= 9)
		{
			a[i++] = ty;
			y = y / 10;
		}

		tz = z % 10;
		if (tz>0 && tz <= 9)
		{
			a[i++] = tz;
			z = z / 10;
		}
		if ( tx == 0 && ty == 0 && tz == 0 && i != 9 ) 
		{
			return 1;
		}
	}

	for (i = 0; i < 9; i++)
	{
		if (a[i] == 0)
		{
			return 1;
		}
		for (j = i; j < 9; j++)
		{
			if (a[j+1] == a[i])
			{
				return 1;
			}
		}
	}


	return 0;
}

int check_xy(int N, int x, int y)
{
	int lenx = get_len(x); // x 的长度
	int leny = get_len(y); // z 的长度，此处用 y 表示
	int lenNx = get_len((N-x)*y); // 估算 y 的长度
	int len = 9 - lenx - leny;
	if (lenNx != len)
	{
		return 1;
	}
	int i = 0, j = 0;
	int tx = 0, ty = 0;
	int a[10] = { 0 };
	for (i = 0; i < lenx + leny; )
	{
		tx = x % 10;
		if (tx > 0 && tx <= 9)
		{
			a[i++] = tx;
			x = x / 10;
		}
		ty = y % 10;
		if (ty>0 && ty <= 9)
		{
			a[i++] = ty;
			y = y / 10;
		}
		if (tx == 0 && ty == 0 && i != lenx + leny)
		{
			return 1;
		}
	}

	for (i = 0; i < lenx + leny; i++)
	{
		if (a[i] == 0)
		{
			return 1;
		}
		for (j = i; j < lenx + leny; j++)
		{
			if (a[j + 1] == a[i])
			{
				return 1;
			}
		}
	}

	return 0;
}

int check_x(int x)
{
	int len = get_len(x);
	int i = 0, j = 0;
	int tx = 0;
	int a[10] = {0};
	for (i = 0; i < len; i++)
	{
		tx = x % 10;
		if (tx > 0 && tx <= 9)
		{
			a[i] = tx;
			x = x / 10;
		}

	}

	for (i = 0; i < len; i++)
	{
		if (a[i] == 0)
		{
			return 1;
		}
		for (j = i; j < len; j++)
		{
			if (a[j + 1] == a[i])
			{
				return 1;
			}
		}

	}

	return 0;
}


int main(int argc, char **argv)
{
	int n = 0;
	int maxN = 1000 * 1000;
	int x = 0, y = 0, z = 0;
	int N = 11;// atoi(argv[1]);
	scanf("%d",&N);
	int maxY = 0;
	// z 的最大值
	int maxZ = (int)(987654321 / (maxN -N));
	int ZZ = pow(10, 9 - get_len(maxZ) - 1);
	if ( maxZ > ZZ )
	{
		maxZ = ZZ;
	}

	clock_t begin, end;
	double cost;
	//开始记录时间
	begin = clock();

	printf("input N = %d\n", N);
	if (N > maxN)
	{
		printf(" N(%d) > maxN(%d) \n", N, maxN);
		return -1;
	}
	int num = 0;
	int ret = 0;
	// 第一层循环，x 必然小于 N
	for (x = 1; x < N; x++)
	{
		// 判断 x 是否合法，不为 0 ，无重复数字
		ret = check_x(x);
		if (ret)
		{
			continue;
		}
		// 第二层循环，z 必然小于 maxZ
		for ( z = 2; z < maxZ; z++)
		{
			// 判断 x，z 是否合法，不为 0 ，无重复数字
			ret = check_xy(N, x, z);
			if (ret)
			{
				continue;
			}
			// 根据 xz 计算出 y 的最大可能值 
			maxY = pow(10, 9 - (get_len(x) + get_len(z)));

			// 最后一层循环，确定 y 值
			for (y = 2*z; y < maxY; y = y+z)
			{
				// 判断 x，y, z 是否合法，不为 0 ，无重复数字, 长度为 9
				ret = check_xyz(x, y, z);
				if (ret)
				{
					continue;
				}

				if (N == (x + y / z))
				{
					printf("%d = %d + %d / %d \n", N, x, y, z);
					num++;
					continue;
				}
			}

		}
	}
	end = clock();
	cost = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("constant CLOCKS_PER_SEC is: %ld, time cost is: %lf secs", CLOCKS_PER_SEC, cost);
	printf("num = %d\n", num);
	return 0;
}



















