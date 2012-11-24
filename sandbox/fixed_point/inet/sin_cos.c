#include <stdio.h> //����� ��� ������� getch();
#include <conio.h>
#include <math.h>

//#define M_PI ((float)3.141592653589793)

double mytan(double x, int i);
double mysin(double x, int i);
double mycos(double x, int i);
//double prevedpi(double x, int i);
double prevedpi(double x);

void main()
    {  int i;
	   printf("vvedite ygol\n");
	   //scanf("%c",&i);
	   //printf("tangens %c\n sinus %c\n cosinus %c", mytan, mysin, mycos);
       scanf("%d",&i);
	printf("tangens %lf, sinus %lf, cosinus %lf\n", (float)(mytan(i, 17)), (float)(mycos(i, 17)), (float)(mysin(i, 17)));
	printf("tangens %lf, sinus %lf, cosinus %lf\n", tan(i), cos(i), sin(i));
       getch();   
    }

//������� �� +-1/4 ��, i-���������� ������� � ����� (���� 15-17 ������������ �������� ������ � ����)
double mytan(double x, int i)
   {
   x=prevedpi(x);
   
   double ret=x*x;//��, ��� ����������    
       for(; i>=0; i--)
          {  
               ret=x/( (2*i+1)  - x*ret  );    
          }
   return ret;
   }

//������� �� +-1/4 ��, i-���������� ������� � ����� ��������
double mysin(double x, int i)
   {
   x=prevedpi(x);
   //� ������ ������ �������� ������ � +-��. ������� ����� ��� �� 4.
   double t=mytan(x/4, i);
   //������ �������� ����� � ������� ����� �/2
   double s=2*t/(1+t*t), c=(1-t*t)/(1+t*t);
   //������������� �������. ������ �� � ��� ������� x/2
   t=s/c;
   //������� ������� �����
   
   return ((2*t)/(1+t*t));
   }
double mycos(double x, int i)
   {
   x=prevedpi(x);
   //� ������ ������ �������� ������ � +-��. ������� ����� ��� �� 4.
   double t=mytan(x/4, i);
   //������ �������� ����� � ������� ����� �/2
   double s=2*t/(1+t*t), c=(1-t*t)/(1+t*t);
   //������������� �������. ������ �� � ��� ������� x/2
   t=s/c;
   //������� ������� ko�����
   
   return ((1-t*t)/(1+t*t));
   }


//���������� �� ��
double prevedpi(double x)
   {
   //������� ��� ������������ ��    
   int a=((int)(x/(M_PI)));   
       
       if(x/M_PI > 1.0 || x/M_PI < - 1.0 )
          {
          //���� ������������ ������ ����� ���       
          if(a%2 == 0)
           x = x - a*M_PI;
          else
           x =-(x - a*M_PI);
           
          }
   return x;
   }
