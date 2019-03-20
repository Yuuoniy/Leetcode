#include <iostream>

using namespace std;

int main(){
    int n;
    char c;
    scanf("%d %c", &n, &c);
    if(n == 1){
        printf("%c\n0\n", c);
        return 0;
    }
    int rest = n, max = 0;
    for(int i = 1; rest >= 2 * i; i += 2){
        if(i == 1){
            rest -= i;
        }
        else{
            rest -= (2 * i);
            max = i;
        }
    }
    if(n < 7){
        printf("%c\n", c);
    }
    int blank = 0;
    for(int j = max; j > 0; j -= 2, ++blank){
        for(int k = 0; k < blank; ++k){
            printf("%c", ' ');
        }
        for(int l = 0; l < j; ++l){
            printf("%c", c);
        }
        printf("%c", '\n');
    }
    blank -= 2;
    for(int m = 3; blank >= 0; --blank, m += 2){
        for(int n = 0; n < blank; ++n){
            printf("%c", ' ');
        }
        for(int o = 0; o < m; ++o){
            printf("%c", c);
        }
        printf("%c", '\n');
    }
    printf("%d\n", rest);
    return 0;
}
