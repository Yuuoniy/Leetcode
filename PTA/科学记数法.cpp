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
    opr=buf[0];//����Ǽ�¼�����ŵ�
    p = buf+1;//�ѷ���ȥ��
    int len = strlen(p);
    for(i=len-1; p[i]!='+' && p[i]!='-'; i--){
        //��������ɨ��, ��ָ��ɨ����
        zhishu+=base*(p[i]-'0');
        base*=10;
    }
    zf=p[i];//ָ���ķ���
    p[i-1]='\0';//ȥ��ָ������
    point=1;
    len = strlen(p);//��ֵ����������
    tmp = len;
    while(zhishu--){
        //����ָ��, Ҳ����Сѧѧ����λ��
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
    //before����0˵������Ǹ�С��, ǰ����before+1��0
    while(before--){
        cout<<'0';
        if(flag==0){
            flag=1;
            cout<<'.';//��ֻ֤���һ��. 
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
