class Solution {
public:
    int convert(string s){
        int hh=stoi(s.substr(0,2));
        int mm=stoi(s.substr(3,2));
        int ss=stoi(s.substr(6,2));
        return hh*3600+mm*60+ss;
    }
    int secondsBetweenTimes(string startTime, string endTime) {
        return convert(endTime)-convert(startTime);
    }
};