    #include <bits/stdc++.h>
    using namespace std;

    int main(){

        int r , c , k;
        cin >> r >> c >> k;

        vector<vector<int>> matrix(r,vector<int>(c));

        for(int i = 0 ; i < r ; i ++){
            for(int j = 0 ; j < c ; j ++){
                cin >> matrix[i][j];
            }
        }


        vector<vector<int>> layer;

        int top = 0 , bottom = r - 1 , left = 0 , right = c - 1;

        int layerCount = 0;
        while(top <= bottom && left <= right){

            vector<int> vals;
            for(int i = left ; i <= right ; i ++){
                vals.push_back(matrix[top][i]);
            }
            top += 1;

            for(int i = top ; i <= bottom ; i ++){
                vals.push_back(matrix[i][right]);
            }

            right -= 1;

            if(top <= bottom && left <= right){
                for(int i = right ; i >= left ; i--){
                    vals.push_back(matrix[bottom][i]);
                }

                bottom -= 1;

        
                for(int i = bottom ; i >= top ; i --){
                    vals.push_back(matrix[i][left]);
                }

                left += 1;
            }

            layer.push_back(vals);
        }

         for(auto &it : layer){
            int newK = k % it.size();
            rotate(it.begin(), it.begin() + newK, it.end());
        }
        
        int layerCount = 0;
        top = 0 , bottom = r - 1 , left = 0 , right = c - 1;
        while(top <= bottom && left <= right ){
            
            if(layerCount >= layer.size()) break;
            vector<int> vals = layer[layerCount];
            layerCount += 1;
            int val = 0;
            for(int i = left ; i <= right ; i ++){
                matrix[top][i] = vals[val++];
            }
            top += 1;

            for(int i = top ; i <= bottom ; i ++){
                matrix[i][right] = vals[val++];
            }

            right -= 1;

            if(top <= bottom && left <= right){
                for(int i = right ; i >= left ; i--){
                    // vals.push_back(matrix[bottom][i]);
                    matrix[bottom][i] = vals[val++];
                }
                

                bottom -= 1;

        
                for(int i = bottom ; i >= top ; i --){
                    // vals.push_back(matrix[i][left]);
                    matrix[i][left] = vals[val++];
                }

                left += 1;
            }
        }
        
        for(int i = 0 ; i < r ; i ++){
            for(int j = 0 ; j < c; j ++){
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }