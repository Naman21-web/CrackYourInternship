class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> mp={{1,"I"},{2,"II"},{3,"III"},{4,"IV"},{5,"V"},{6,"VI"},{7,"VII"},{8,"VIII"},{9,"IX"},{10,"X"},{20,"XX"},{30,"XXX"},{40,"XL"},{50,"L"},{60,"LX"},{70,"LXX"},{80,"LXXX"},{90,"XC"},{100,"C"},{200,"CC"},{300,"CCC"},{400,"CD"},{500,"D"},{600,"DC"},{700,"DCC"},{800,"DCCC"},{900,"CM"},{1000,"M"},{2000,"MM"},{3000,"MMM"}};
        int x = num;
        int y=1;
        int z;
        vector<string> a(4,"");
        int i=0;
        while(x){
            z = x%10;
            z = z*y;
            a[i]= mp[z];
            y = y*10;
            x = x/10;
            i++;
        }
        string str;
        for(int i=a.size()-1;i>=0;i--){
            str += a[i];
        }
        return str;
    }
};