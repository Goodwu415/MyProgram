#include <stdio.h>
#include <math.h>

int n = 0;
double X1,Y1,x,y,R;

void endpoint(double L, double W);//x,y ��㣬X1��Y1�յ�

int main()
{
	double L,W,a,v,s;// a �Ƕȣ� v �ٶȣ�s ʱ�䣬L W �߽�
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&L,&W,&x,&y,&R,&a,&v,&s);
	
	while( L != 0 && W != 0 && x != 0 && y != 0 && R != 0 && a !=0 && v != 0 && s != 0)
	{
		a = a * asin(1)*2 /180;
		X1 = x + s * v * cos(a);
		
		Y1 = y + s * v * sin(a);
		while( X1 < 0 || X1 > L || Y1 < 0 || Y1 > W)// �������ұ߽��� 
		{
			endpoint(L-R, W - R);
		}
		if(X1 >= 0 + R && X1 <= L && Y1 >= 0+R && Y1 <= W)// ���ھ������ж� 
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
	slope = (Y1 - y) / (X1 - x);//б�� 
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
