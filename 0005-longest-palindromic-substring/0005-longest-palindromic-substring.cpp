// class Solution {
// public:
//     bool ispal(int first, int last, string s)
//     {
//         int i=first,j=last;
//         while(first<=last)
//         {
//             if(s[first]!=s[last])
//             {
//                 return false;
//             }
//             first++;
//             last--;
//         }
//         cout << i << " " << j << "  ";
//         return true;
//     }

//     string longestPalindrome(string s) 
//     {
//         string rep="";
//         int x=0,len=0;
//         int n=s.length();

//         for(int i=0; i<n; i++)
//         {
//             for(int j=i; j<n; j++)
//             {
//                 if(ispal(i,j,s))
//                 {
//                     if(j-i>x)
//                     {
//                         x=j-i;
//                         len=i;
//                     }
//                 }
//             }
//         }

//         return s.substr(len,x+1);
//     }
// };



class Solution {
private: 
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }            
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int starting_index = 0;
        int max_len = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(s, i, j)){
                    if(j-i+1 > max_len){
                        max_len = j-i+1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);
    }
}; 