class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& nums) 
    {
        map<int,map<int,int>> row,col;
        map<pair<int,int>,map<int,int>> box;

        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(nums[i][j]!='.')
                {
                    int x=nums[i][j]-'0';
                    if(row[i][x]!=0)
                        return false;
                    else
                        row[i][x]++;

                    if(col[j][x]!=0)
                        return false;
                    else
                        col[j][x]++;

                    if(box[{i/3,j/3}][x]!=0)
                        return false;
                    else
                        box[{i/3,j/3}][x]++;
                }
            }
        }
        return true;
    }
};