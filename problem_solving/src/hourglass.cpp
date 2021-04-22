#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
    int max_sum = numeric_limits<int>::min();;
    for (int i=0;i<arr.size()-2;++i){
        int sum=numeric_limits<int>::min();
        for(int j=0;j<arr[0].size()-2;++j){
            sum=arr[i][j]   + arr[i][j+1]   + arr[i][j+2]
                            + arr[i+1][j+1] 
              + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2] 
            ;
            /*
            cout << i << " "<<j<<" " << sum << endl;
            cout << arr[i][j] << " + "
                 << arr[i][j+1] << " + "
                 << arr[i][j+2] << " + "
                 << arr[i+1][j+1]  << " + "
                 << arr[i+2][j] << " + "
                 << arr[i+2][j+1] << " + "
                 << arr[i+2][j+2] << " + "
                << endl;
                */
            if (sum > max_sum)
                max_sum=sum;
        }
        
        
    }
    return max_sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
