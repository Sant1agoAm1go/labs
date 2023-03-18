#include <stdio.h>
#include <math.h>
double iter(double a, double y, double n, double m, int *k) {
        double yn = pow(a,1/n);
        while (fabs(y-yn)>m) {
                y = y/(n*n)*((n*n-1)+1/2*(n+1)*a/(pow(y,n)-1/2*(n-1)*pow(y,n)/a));
                *k = *k + 1;
        }
        printf("Количество членов: ");
        printf("%d\n",*k);
        return y;
}
void checkInput(int h ){
    if (h == 0){
        scanf("%*s");
    }
}
int main() {
    double a, y, n, m;
    int i = 0, flag = 1;
    printf("Введите переменную а, нулевой член y0, корень n и точность m:\n");
    while (flag) {
        int x = scanf("%lf", &a);
        checkInput(x);
        int b = scanf("%lf", &y);
        checkInput(b);
        int c = scanf("%lf", &n);
        checkInput(c);
        int d = scanf("%lf", &m);
        checkInput(d);
        if (x+b+c+d == 4) {
            flag = 0;
        }
        else {
            printf("Ошибка ввода!\n");
            printf("Введены неправильные данные.\n");
            printf("Повторите ввод:\n");
        }
    }
    double s = iter(a,y,n,m,&i);
    printf("Мой корень: ");
    printf("%.15lf\n",s);
    printf("Мат. корень: %.15lf\n", pow(a,1/n));
    return 0;
}

