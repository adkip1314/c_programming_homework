#include <bits/stdc++.h>
static double pi = acos(-1);

int f(int x,int a,int b ,int c, int d ,int e){		
	int y = a*cos(b*pi*x/30)+c*sin(d*pi*x/30)+e;
	return y;
}


int main(void){
	int a,b,c,d,e;// ��{���Y��
	int x0, x1 ;   // x �b�d��
	int P;		  //�ҨD���I�� X �� 
	printf("�п�J5�ӫY�� :");
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	printf("�п�Jx�b�d�� :");
	scanf("%d%d",&x0,&x1);
	printf("�п�J�ҨD���I��x�� :"); 
	scanf("%d", &P);
	float Mp = (-a*sin(b*pi*P/30)*(b*pi/30)+c*cos(d*pi*P/30)*(d*pi/30)); //���I�ɼƤ��� 
	printf("��ڤ��u�ײv :%lf\n ",Mp);
	int tan = Mp;
	int Py = f(P ,a, b , c,  d , e);
	int i, j ,k ,l; // �j���ܼ�
	int px,py ; // �첾�P�_��
	int jud = 0 ;
	for(i = -35 ; i <= 35 ; i+=5){
		if(i <= -5)printf("  -%d",-i);
		else if ( i == 0)printf("    0");
		else if  (i == 5)printf("    5 ");
		else printf("   %d",i);
	}
	printf("\n");
	for(i = x0 ; i <= x1; i++){				
		for ( j = -39; j <= 40; j++ ){
			if((i%5 == 0)&&(j == 0)&&( i> 0)){
				printf("%d",i);
				k = (int)log10(i) ;
				j += k; 
				}
			else if ((i== 0)&&(j == 0)){
				printf("0");
			}
			else if ((i%5 == 0 )&&(j == 0)&&( i < -2)){
				printf("%d",i);
				k = log10(-i) + 1;
				j += (int)k;
			}
			else if (j == 0){
				printf("|");
			}
			else {
				if(i == x0){
					if( (i == P)){
						int Py = f(P ,a, b , c,  d , e);
						if(i == 0){
							px = 1;
						}
						else if (i > 0){
							px = (int)log10(i) + 1;
						}
						else{
							px = (int)log10(abs(i)) + 2;
						}
						if(Py == 0){
							py = 1;
						}
						else if ( Py> 0){
							py = (int)log10(Py) + 1;
						}
						else{
							py = (int)log10(abs(Py)) + 2;
						}
						if(j+px+py+7 == f(i,a,b,c,d,e)){
							printf("( %d, %d ) P",i,Py);
							j += px+py+7 ;
							jud = 1;
						}
						else if((jud !=1)&&(j == f(i,a,b,c,d,e))){
							printf("P ( %d, %d )",i,Py);
							j += px+py+7 ;
							}
						else if(j == f(i,a,b,c,d,e))
						printf("*");
						else if((j==1)||(j==-1))
						printf(" ");
						else if (j == 40)
						printf("Y");
						else if (j % 5== 0)
						printf("+");
						else
						printf("-");
					}
					else{
						if(j == f(i,a,b,c,d,e))
						printf("*");
						else if (j == 40)
						printf("Y");
						else if ((i >= P-5)&&(j == tan*(i - P) + Py)){
							if ((tan>0)&&(tan<=10))
								printf("\\");
							else if ((tan<0)&&(tan>-10))
								printf("\/");
							else if ((tan == 0))
								printf("|");
							else 
								printf("-");
						}
						else if((j==1)||(j==-1))
						printf(" ");
						else if (j % 5== 0)
						printf("+");
						else
						printf("-");
					}
				}
				else{	
					if( (i == P)){
	//					int Py = f(P ,a, b , c,  d , e);
						if(i == 0){
							px = 1;
						}
						else if (i > 0){
							px = (int)log10(i) + 1;
						}
						else{
							px = (int)log10(abs(i)) + 2;
						}
						if(Py == 0){
							py = 1;
						}
						else if ( Py> 0){
							py = (int)log10(Py) + 1;
						}
						else{
							py = (int)log10(abs(Py)) + 2;
						}
						if(j+px+py+7 == f(i,a,b,c,d,e)){
							printf("( %d, %d ) P",i,Py);
							j += px+py+7 ;
							jud = 1;
						}
						else if((jud !=1)&&(j == f(i,a,b,c,d,e))){
							printf("P ( %d, %d )",i,Py);
							j += px+py+7 ;
						}
						else{
							printf(" ");
						}
					}
					else if(j == f(i,a,b,c,d,e))
					printf("*");
					else if ((i >= P-5)&&(i <= P+5)&&(j == tan*(i - P) + Py)){
							if ((tan>0)&&(tan<=10))
								printf("\\");
							else if ((tan<0)&&(tan>-10))
								printf("\/");
							else if ((tan == 0))
								printf("|");
							else 
								printf("-");
						}
					else{
						printf(" ");
					}
				}
			}
		}printf("\n");
	}
	return 0;
}
