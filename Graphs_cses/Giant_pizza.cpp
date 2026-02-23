#include <bits/stdc++.h>
using namespace std;

const int maxi = 100005 + 1;
int comp[2*maxi];
bool vis[2*maxi];
vector<int> g[2*maxi] , r[2*maxi];
stack<int> st;
void dfs1(int i){

    vis[i] = 1;
    for(int v : g[i]){
        if(!vis[v]){
            dfs1(v);
        }
    }

    st.push(i);
}
void dfs2(int u,int c){
    comp[u] = c;

    for(int v : r[u]){
        if(!comp[v]){
            dfs2(v,c);
        }
    }
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);


    int n , m;
    cin >> n >> m;

    auto id = [&](int x){
        if(x > 0) return x;
        return m + (-x);
    };

    auto neg = [&](int x){
        if(x <= m) return x + m;
        return x - m;
    };

    for(int i = 0 ; i < n ; i ++){

        int a , b;
        char c , d;

        cin >> c >> a >> d >> b;

        a = (c == '+') ? a : -a;
        b = (d == '+') ? b : -b;

        int A = id(a);
        int B = id(b);

        int nA = neg(A);
        int nB = neg(B);


        g[nA].push_back(B);
        g[nB].push_back(A);

        r[A].push_back(nB);
        r[B].push_back(nA);

    }


    for(int i = 1 ; i <= 2 * m ; i ++){
        if(!vis[i]){
            dfs1(i);
        }
    }
    int c = 0;
    while(!st.empty()){
        auto node = st.top();
        st.pop();
        if(!comp[node]){
            dfs2(node,++c);
        }
    }


    for(int i = 1 ; i <= m ; i ++){
        if(comp[i] == comp[i + m]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }

    for(int i = 1 ; i <= m ; i ++){
        if(comp[i] > comp[i + m]){
            cout<<"+\n";
        }
        else{
            cout<<"-\n";
        }
    }
}