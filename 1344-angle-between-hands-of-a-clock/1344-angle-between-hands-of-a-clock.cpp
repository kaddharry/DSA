class Solution {
public:
    double angleClock(int hour, int minutes) {
        //angle between every hour number is 30deg each
        //position of hour hand is directly dependend on minute hand
        //60 minutes --> 30 deg change in hour hand
        //1 minute costs 0.5 deg change in hour hand
        //if time is 3:30, then position of hour hand is cal as
        //pos of hr hand = hour * 30 + minutes * 0.5
        //pos of min hand = minutes*6 (as 60 minutes --> 360deg, so 1 min -->6 deg)
        //result = |hour hand pos - min hand pos|
        //NOTE: for hour hand == 12, set is to 00

        if(hour == 12) hour = 0;
        float deghr = 0, degmin = 0;
        deghr = hour * 30 + float(minutes) * 0.5;
        degmin = minutes*6;
        float result = abs(deghr - degmin);
        result = result > 180? (360 - result):result;
        return result;
    }
};