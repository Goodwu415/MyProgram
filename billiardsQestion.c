#include <stdio.h>
#include <math.h>

int n = 0;
double X1,Y1,x,y,R;

void endpoint(double L, double W);//x,y 起点，X1，Y1终点

int main()
{
	double L,W,a,v,s;// a 角度， v 速度，s 时间，L W 边界
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&L,&W,&x,&y,&R,&a,&v,&s);
	
	while( L != 0 && W != 0 && x != 0 && y != 0 && R != 0 && a !=0 && v != 0 && s != 0)
	{
		a = a * asin(1)*2 /180;
		X1 = x + s * v * cos(a);
		
		Y1 = y + s * v * sin(a);
		while( X1 < 0 || X1 > L || Y1 < 0 || Y1 > W)// 上下左右边界检测 
		{
			endpoint(L-R, W - R);
		}
		if(X1 >= 0 + R && X1 <= L && Y1 >= 0+R && Y1 <= W)// 球在矩形内判断 
		{
			printf("%.2lf %.2lf\n",X1, Y1);
		}	
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&L,&W,&x,&y,&R,&a,&v,&s);
	}
		 
	return 0;
}
void endpoint(double L, double W) 
{
	double upx, downx, righty, lefty, slope;
	slope = (Y1 - y) / (X1 - x);//斜率 
	upx = (W - y) / slope + x;
	downx = (0.0 + R - y) / slope + x;
	
	righty = slope * (L - x) + y;
	lefty = slope * (0.0 + R - x)+y;
	
	if(Y1 > W && y < W && upx >= 0 + R && upx <= L)
	{
		x = upx;
		y = W;
		Y1 = Y1 -2 *(Y1 - W);
		return ;
	}else if(Y1 < 0 + R && y > 0+R && downx >= 0 + R && downx <= L)
	{
		x = downx;
		y = 0 + R;
		Y1 = Y1 - 2 * (Y1 - R);
		return;
	}else if(X1 > L && x < L && righty >= 0 + R && righty <= W)
	{
		x = L;
		y = righty;
		X1 = X1 - 2 * (X1 - L);
		return;
	}else if(X1 < 0 + R && x > 0 + R && lefty >= 0 + R && lefty <= W)
	{
		x = 0 + R;
		y = lefty;
		X1 = X1 - 2 * (X1 - R);
		return;
	}
	return;
	
}
