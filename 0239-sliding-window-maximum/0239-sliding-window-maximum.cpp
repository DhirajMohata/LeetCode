class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for(int i=0; i<k; i++)
        {
            pq.push({nums[i], i});
        } 
        
        ans.push_back(pq.top().first);

        for(int i=k; i<nums.size(); i++)
        {
            while(!pq.empty() && pq.top().second<=(i-k))
                pq.pop();

            pq.push({nums[i], i});
            ans.push_back(pq.top().first);
        }

        return ans;
    }
};

// above solution is using sliding window and prioprity queue of pair in which we are storing value and their index in sorted manner




//Using Deque



// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) 
//     {
//         vector<int> ans;
//         deque<int> d;

//         for(int i=0; i<nums.size(); i++)
//         {
//             while(!d.empty() && nums[i]>=nums[d.back()])
//                 d.pop_back();
//             d.push_back(i);

//             if(d.front()==i-k)
//                 d.pop_front();

//             if(i>=k-1)
//                 ans.push_back(nums[d.front()]);
//         }
//         return ans;
//     }
// };

// here first element is always the biggest thats why we are removing all from the back which are smaller then current element