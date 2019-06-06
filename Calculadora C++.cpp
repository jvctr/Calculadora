#include <stdio.h>
#include <stdlib.h>
#define pi 3.14159265359
#define expo 2.71828182846
double ex        (float);
float  fac       (float);
float  rad       (float);
float  seno      (float);
float  cosen     (float);
float  tan       (float);
float  raiz      (float,float);
float  pot       (float,float);
float  deFra     (float,float);
float  logaritmo (float,float);

int propi(int x,int y);
int sig  (int x);
int menu ();

void lim(){
	fflush(stdin);
	printf("\n\nPressione <ENTER> para continuar...");
	getchar();
	system("cls");
}


int main(){
    float x,y;
    int n;
    do{
        n=menu();
        system("cls");
        switch(n){
            case 1: printf("\n***************** SENO *****************\n");
                    printf("Insira o valor de x\n:");
                    scanf("%f",&x);
                    x=seno(x);
                    printf("\n-> %g\n\n",x);
            break;
            case 2: printf("\n**************** COSENO ****************\n");
                    printf("Insira o valor de x\n:");
                    scanf("%f",&x);
                    x=cosen(x);
                    printf("\n-> %g\n\n",x);
            break;

            case 3: printf("\n**************** TANGENTE ****************\n");
                    printf("Insira o valor de x\n:");
                    scanf("%f",&x);
                    x=tan(x);
                    printf("\n-> %g\n\n",x);
            break;
            case 4: printf("\n************** Fatorial **************\n");
                    printf("Insira o valor de x\n:");
                    scanf("%f",&x);
                    x=fac(x);
                    printf("\n-> %g\n\n",x);
            break;
            case 5: printf("\n************** POTENCIA **************\n");
                    printf("Insira o coeficiente\n");
                    scanf("%f",&x);
                    printf("Insira o Expoente\n:");
                    scanf("%f",&y);
                    x=pot(x,y);
                    printf("\n-> %g\n\n",x);
            break;

            case 6: printf("\n************** LOGARITMO **************\n");
                    printf("Insira a base\n");
                    scanf("%f",&x);
                    printf("Insira o Logarirmo\n:");
                    scanf("%f",&y);
                    x=logaritmo(x,y);
                    printf("\n-> %g\n\n",x);
            break;
            case 7: printf("\n********** LOGARITMO NATURAL **********\n");
                    printf("Insira o Logarirmo\n:");
                    scanf("%f",&y);
                    x=logaritmo(expo,y);
                    printf("\n-> %g\n\n",x);
            break;
            case 8: printf("\n************** EXPONENCIAL **************\n");
                    printf("Insira o valor de x\n:");
                    scanf("%f",&x);
                    x=ex(x);
                    printf("\n-> %g\n\n",x);
            break;
            case 9: printf("\n************** RAIZ QUADRADA **************\n");
                    scanf("%f",&x);
                    x=raiz(x,2);
                    printf("\n-> %g\n\n",x);

            break;
            default:;
        }
	lim();
    }while(n<12);

return 0;
}

int menu(){
    int n;
    printf("********** Calculadora Cientifica **********");
    printf("\n 1 .-Seno ");
    printf("\n 2 .-Coseno ");
    printf("\n 3 .-Tangente ");
	printf("\n 4 .-Fatorial ");
	printf("\n 5 .-Potencia");
	printf("\n 6 .-Logaritmo Base Necima");
	printf("\n 7 .-Logaritmo Natural");
    printf("\n 8 .-Exponencial ");
	printf("\n 9 .-Raiz Quadrada ");
    printf("\n 10.-Sair");
    scanf("%d",&n);
    return n;
}
int sig(int x){
    if(x%2==0)
        return 1;
    else
        return -1;
}
float pot(float x,float n){
    if(n==0)
        return 1;
    return x*pot(x,n-1);
}
float fac(float x){
    if(x==0)
        return 1;
    return x*fac(x-1);
}
float rad(float x){
    double y=0;
    int z,n;
    printf("\n 1.-Radianos\n 2.-Graus\n\n:");
    scanf("%d",&n);
    if(n==1){
		y=x*180/pi;

		z=y;
	    y=y-z;
	    z=z%180;
	    y=z+y;

	    y=y*pi/180;
        return y;
    }
    else{
    	y=x;
 		if(y>180){
	 		z=y;
		    y=y-z;
		    z=z%180;
		    y=z+y;
		 }
        return y*pi/180;
    }
}

float seno(float x){
    int i,j,n=10;
    float num,den,s,sen=0;
    x=rad(x);

    for(i=0;i<n;i++){
        j=2*i+1;
        num=pot(x,j);
        den=fac(j);
        s=sig(i);
        sen+=(num/den)*s;
    }
    return sen;
}
float cosen(float x){
   int i,j,n=10;
   double num,den,s,cos=0;
   x=rad(x);
   for(i=0;i<n;i++){
   		j=i*2;
	    num=pot(x,j);
	    den=fac(j);
	    s=sig(i);
	    cos+=(num/den)*s;
   }
   return cos;
}
float tan(float x){
  int i,j,n=10;
    float num,den,s,sen=0,cos=0;
    x=rad(x);
    for(i=0;i<n;i++){
        j=2*i+1;
        num=pot(x,j);
        den=fac(j);
        s=sig(i);
        sen+=(num/den)*s;

        j=i*2;
        num=pot(x,j);
        den=fac(j);
        s=sig(i);
        cos+=(num/den)*s;
    }
    x=sen/cos;
    return x;
}
double ex(float x){
    int i,n=35;
    double num,den,e=0;
	if(x>13){
		printf("\nMatch Error\n");
		return 0;
	}
    for(i=0;i<n;i++){
        num=pot(x,i);
        den=fac(i);
        e+=num/den;
    }
    return e;
}
float logaritmo(float x,float y){
	float i,j;
	float log=0;
	for(i=1;log<y;i++){
		log=1;
		for(j=0;j<i;j++)
			log*=x;
	}
	i--;
	j=i;
	if(log>y){
		log=0;
		j--;
		for(i=j;log<y;i+=0.01){
			log=0;
			log=deFra(i,x);
		}
		i-=0.02;
	}
	return i;
}

float raiz(float x,float y){
	float base=0,j,a=1,i,k;
	for( j=a;base<x;j+=a){
		base=0;
		base=pot(j,y);
	}
	j-=a;
	i=j;
	if(base>x){
		j-=a;
		base=0;
		a=0.0001;

		for( i=j+a;base<x;i+=a){
			base=1;
			for(k=1;k<=y;k++)
				base*=i;
		}
		i-=a;
	}
	return i;
}

float deFra(float x,float z){
	int a,i,j,den=100;

	a=x*100;
	den=100;

	for(j=0;j<10;j++){

		for(i=1;i<100;i++){
			if(a%i==0 && den%i==0){
				a/=i;
				den/=i;
			}
		}
	}
	z=pot(z,a);
	den=raiz(z,den);

	return den;
}
