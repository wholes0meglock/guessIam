#include <bits/stdc++.h>
using namespace std;
#define int long long

void help()
{
    int n, k;
    cin >> n >> k;
    vector<int> vec;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        vec.push_back(num);
    }

    map<int, vector<int>> positions;
    for(int i = 0; i < n; i++) {
        positions[vec[i]].push_back(i);
    }

    int answer = INT_MAX;
    
    for(auto &color_data : positions) {
        vector<int> &pos = color_data.second;
        int m = pos.size();
        
        // Calculate gaps between consecutive planks of this color
        vector<int> gaps;
        gaps.push_back(pos[0]); // gap from start to first occurrence
        for(int i = 1; i < m; i++) {
            gaps.push_back(pos[i] - pos[i-1] - 1);
        }
        gaps.push_back(n - pos[m-1] - 1); // gap from last occurrence to end
        
        // Sort gaps to find the largest one
        sort(gaps.begin(), gaps.end());
        
        // We can potentially repaint one plank to reduce the maximum gap
        // The strategy: take the largest gap and split it in half by repainting
        int largest_gap = gaps.back();
        int second_largest = gaps.size() > 1 ? gaps[gaps.size()-2] : 0;
        
        // If we repaint in the middle of the largest gap, we reduce it
        int new_max_gap = max(second_largest, largest_gap / 2);
        answer = min(answer, new_max_gap);
    }
    
    cout << answer << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    { 
        help();
    }
    return 0;
}