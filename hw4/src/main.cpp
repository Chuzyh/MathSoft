#include<bits/stdc++.h>
#include "Window.h"
#include "Manderbrot.h"
#include "bitmap.h"
using namespace std;

/**
 * @brief 生成图片文件
 * 
 * @param argv[1] 文件名 
 * @param argv[2] 中心点x坐标
 * @param argv[3] 中心点y坐标
 * @param argv[4] 横向坐标范围
 */
int main(int argc, char *argv[])
{
	if (argc < 5)
	{
		std::cerr << "Usage: " << argv[0]
				  << " filename ox oy dimension" << std::endl;
		exit(-1);
	}
	
	Window win(std::atof(argv[2]), std::atof(argv[3]), std::atof(argv[4]));
	double lpp = win.get_lpp();
	double dim = win.get_dimension();
	int width = win.get_width();
	int height = win.get_height();
	double ox = win.get_ox() - dim;
	double oy = win.get_oy() - dim / width * height;
	int N = 255/3;

	char *cache = new char[width * height * 3];

	for (int j = 0; j < height; j++)
		for (int i = 0; i < width; i++)
		{
			double x = ox + lpp * i;
			double y = oy + lpp * j;
			int pos = width * j + i; 
			Manderbrot man(std::complex<double>{0.0, 0.0},
						   N,
						   std::complex<double>{x, y});
			while (!man.stop_criterion())
			{
				man.forward_step();
				if (man.is_disconvergence())
					break;
			}
			if (man.stop_criterion())
			{
				
				if(argc>5)
				{
					cache[pos * 3 + man.get_iteration_times()%3] = 255-man.get_iteration_times()*3;
				}else
				{
					cache[pos * 3] = 255-man.get_iteration_times()*3;
					cache[pos * 3 + 1] = 255-man.get_iteration_times()*3;
					cache[pos * 3 + 2] = 255-man.get_iteration_times()*3;
				
				}
			}
			else
			{
				cache[pos * 3] = 0;
				cache[pos * 3 + 1] = 0;
				cache[pos * 3 + 2] = 0;
			}
		}
	build_bmp(argv[1], width, height, cache);
	delete [] cache;
	return 0;
};
