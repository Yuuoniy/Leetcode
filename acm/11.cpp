#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int bfs(vector<int>& possible){
    int size = possible.size();
    if(size == 1){
        return possible[0];
    }
    int ans = 999999999;
    for(int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            vector<int> newPossible;
            for(int k = 0; k < size; k++){
                if(k != i && k != j){
                    newPossible.push_back(possible[k]);
                }
            }
            newPossible.push_back(abs(possible[i] - possible[j]));
            ans = min(ans,bfs(newPossible));
            newPossible.pop_back();
            newPossible.push_back(possible[i] + possible[j]);
            ans = min(ans,bfs(newPossible));
            newPossible.pop_back();
            newPossible.push_back(possible[i] * possible[j]);
            ans = min(ans,bfs(newPossible));
            newPossible.pop_back();
        }
    }
    return ans;
}
int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        int n;
        scanf("%d",&n);
        vector<int> arr;
        for(int i = 0; i < n; i++){
            int tmp;
            scanf("%d",&tmp);
            arr.push_back(tmp);
        }
        int ans = bfs(arr);
        printf("%d\n",ans);
    }
    return 0;
}
