/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 0; i < triangle.size(); i++)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                if(j==0)
                    triangle[i][j]+= triangle[i-1][j];
                else if(j==triangle[i].size()-1)
                    triangle[i][j]+= triangle[i-1][j-1];
                else 
                     triangle[i][j]+= min(triangle[i-1][j],triangle[i-1][j-1]);

            }
            
        }
        return *min_element(triangle.back().begin(),triangle.back().end());
        
    }
};

