class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(1){
            slow = nqs(slow);
            fast = nqs(nqs(fast));

            if(fast == 1) break; //if fast is 1, then slow would eventually become 1
            if(slow == fast) return false; //oop exists so no happy number
        }
        return true;
    }
private:
    int nqs(int n){
        //nqs means number squared sum
        int result = 0;
        while(n){
            result += (n%10) * (n%10);
            n /= 10;
        }
        return result;
    }

};