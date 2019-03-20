#include<bits/stdc++.h>

using namespace std;
const int N = 10100;
char buf[N];
int main()
{
    int zhishu=0,base=1,i,j,point,before=0,tmp;
    char opr,zf;
    char *p;
    memset(buf, 0, sizeof(buf));
    //freopen("1024.in", "r", stdin);
    cin>>buf;
    opr=buf[0];//这个是记录正负号的
    p = buf+1;//把符号去掉
    int len = strlen(p);
    for(i=len-1; p[i]!='+' && p[i]!='-'; i--){
        //从右向左扫描, 把指数扫出来
        zhishu+=base*(p[i]-'0');
        base*=10;
    }
    zf=p[i];//指数的符号
    p[i-1]='\0';//去掉指数部分
    point=1;
    len = strlen(p);//数值的真正长度
    tmp = len;
    while(zhishu--){
        //处理指数, 也就是小学学的移位法
        if(zf=='-'){
            if(point>=1){
                swap(p[point-1], p[point]);
                point--;
                if(point==0)p[point]='0';
            }else
                before++;
        }else{
            if(point<tmp-1)
            {
                swap(p[point], p[point+1]);
                point++;
                if(point==len-1){
                    p[point] = '0';
                    len--;
                }
            }else
                p[len++]='0';
        }
    }
    p[len]='\0';
    if(opr=='-')
        cout<<'-';
    int flag=0;
    //before大于0说明结果是个小数, 前面有before+1个0
    while(before--){
        cout<<'0';
        if(flag==0){
            flag=1;
            cout<<'.';//保证只输出一个. 
        }
    }
    printf("%c", p[0]);
    if(flag==0 && '0'==p[0]){
            flag=1;
            cout<<'.';
    }
    for(i=1;i<len;i++)
        printf("%c", p[i]);
    return 0;
}
