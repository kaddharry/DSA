class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string r1="QWERTYUIOPqwertyuiop",r2="ASDFGHJKLasdfghjkl",r3="ZXCVBNMzxcvbnm";
        int a=0,b=0,c=0;
        vector<string>res;
        for(auto i:words){
            for(auto j:i){
                if(r1.find(j)!=string::npos)a++;
                if(r2.find(j)!=string::npos)b++;
                if(r3.find(j)!=string::npos)c++;
            }
            if(i.size()==max({a,b,c}))res.push_back(i);
            a=b=c=0;
        }
        return res;
    }
};