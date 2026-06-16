// optimal

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& student, vector<int>& cookie) {
        sort(student.begin(),student.end());
        sort(cookie.begin(),cookie.end());
        int studentIndex=0; 
        int cookieIndex=0;  
        while(studentIndex<student.size()&&cookieIndex<cookie.size()) {
            if(cookie[cookieIndex]>=student[studentIndex]) {
                studentIndex++; 
            }
            cookieIndex++; 
        }
        return studentIndex;
    }
};
int main() {
    vector<int> student={1,2,3};
    vector<int> cookie={1,1};
    Solution sol;
    int result=sol.findContentChildren(student,cookie);
    cout<<"Maximum number of content students: "<<result<<endl;
    return 0;
}

// Problem: assign cookies