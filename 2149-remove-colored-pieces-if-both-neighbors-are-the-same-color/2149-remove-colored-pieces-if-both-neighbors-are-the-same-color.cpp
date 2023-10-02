class Solution {
public:
    bool winnerOfGame(string nums) 
    {
        int a = 0 , tempa = 0;
        int b = 0 , tempb = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]=='A')
            {
                tempa++;
            }
            else
            {
                a += max(tempa-2 , 0);
                tempa = 0;
            }

            if(nums[i]=='B')
            {
                tempb++;
            }
            else
            {
                b += max(tempb-2 , 0);
                tempb = 0;
            }
        }

        a += max(tempa-2 , 0);
        b += max(tempb-2 , 0);

        if(a>b)
            return true;
        else
            return false;
    }
};