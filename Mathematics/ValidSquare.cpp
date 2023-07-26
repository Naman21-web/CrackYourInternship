class Solution {
public:
    int square(int a){
        return a*a;
    }

      bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1==p2 || p1==p3 || p1==p4 || p2==p3 || p2==p4 || p3==p4) return false;
        int x1 = p1[0];
        int y1 = p1[1];
        int x2 = p2[0];
        int y2 = p2[1];
        int x3 = p3[0];
        int y3 = p3[1];
        int x4 = p4[0];
        int y4 = p4[1];

        int a =square(y2-y1)+square(x2-x1);
        int b = square(x3-x1)+square(y3-y1);
        int c = square(y4-y3)+square(x4-x3);
        int d = square(x4-x2)+square(y4-y2);
        int e = square(x4-x1)+square(y4-y1);
        int f = square(x3-x2)+square(y3-y2);

        unordered_set<int> s;
        s.insert(a);
        s.insert(b);
        s.insert(c);
        s.insert(d);
        s.insert(e);
        s.insert(f);

        if(s.size()!=2) return false;
        return true;
    }
};