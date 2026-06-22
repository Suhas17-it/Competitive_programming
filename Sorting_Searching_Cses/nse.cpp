#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<long long> arr(n);

    for(int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }

    stack<int> st;

    vector<int> left(n,0);

    
    for(int i = 0 ; i < n ; i ++){

        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }

        if(!st.empty()){
            left[i] = st.top() + 1;
        }
        st.push(i);
    }

    for(int x : left) cout << x << " " ;
    cout << endl;
}