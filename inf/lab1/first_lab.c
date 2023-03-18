#include <stdio.h>
int  even(int n) {
    int s = 2;
    while (n>1) {
        while(n%s!=0) {
            s+=1;
        }
        n/=s;
        printf("%d ",s);
    }
    return 0;
}
int main() {
    int n = 0;
    printf("Введите число: ");
    scanf("%d",&n);
    printf("Его простые множители: ");
    even(n);
    printf("\n");
    return 0;
}
