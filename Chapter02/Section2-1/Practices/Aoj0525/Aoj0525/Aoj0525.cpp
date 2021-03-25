/*
Description:
看完代码有点感悟:
1. 没有图解, 也没有推理解释过程, 例如if (i&(i << j)) 这行
代码, 我就不知道它的深层含义.
2. 代码模块很清晰, 跟英语句子结构一样, 仔细分析主谓宾. 亦或者
说想图论一样, 两点一边: u 如何作用于v

Keywords:

ULR:
*/

#include <bits/stdc++.h>
using namespace std;

#define DATATXT

bitset<10000> cookie[10];		// stl

int main()
{
	// Prologue
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef DATATXT
	FILE *file;
	freopen_s(&file, "input.txt", "r", stdin); // File to stdin
#endif

	int R, C;
	while (cin >> R >> C && R > 0)
	{
		int i, j;
		for (i = 0; i < R; i++)
		{
			for (j = 0; j < C; j++)
			{
				bool upwards;
				cin >> upwards;
				cookie[i][j] = upwards;	// 好的初始化方式
			}
		}

		// 在横向一共有2^R 中变换
		int permute_r = 1 << R;
		int result = 0;
		for (i = 0; i < permute_r; ++i)
		{
			// 完成当前的变换
			for (j = 0; j < R; ++j)
			{
				// 这一行是否应当翻个面, 不懂这种二进制运算的含义
				if (i&(1 << j))
				{
					cookie[j].flip();
				}
			}

			// 对每一列分别算出朝上和朝下的煎饼个数, 取其最大值
			int possible_answer = 0;
			for (j = 0; j < C; ++j)
			{
				int up_cookie_count = 0;
				for (int k = 0; k < R; k++)
				{
					if (cookie[k][j])
					{
						++up_cookie_count;
					}

				}

				possible_answer += max(up_cookie_count,
					R - up_cookie_count);
			}

			// 结果取最大值
			result = max(result, possible_answer);

			// 复原
			for (j = 0; j < R; ++j)
			{
				if (i&(1 << j))
				{
					cookie[j].flip();
				}
			}
		}

		cout << result << endl;
	}

	return 0;
}