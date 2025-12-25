/*

739. Daily Temperatures
Medium
Topics
premium lock icon
Companies
Hint
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is
the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which
this is possible, keep answer[i] == 0 instead.



Example 1:

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]


Constraints:

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

*/

/*

-- monotonic stack algo --
arr = [73,74,75,71,69,72,76,73]
i =    0  1  2  3  4  5  6  7
st = "">0; 0>1; 1>2; 2>23; 23>234; 234>25; 25>6; 6>67;
res_ops = ; 1-0=1; 2-1=1;;; 5-4=1,5-3=2; 6-5=1,6-2=4;;
res[i]=0  1  2  3  4  5  6  7 
	-  0  0  0  0  0  0  0  0
	-  1 
	-     1
	-              1
	-           2
	-                 1
	-        4
	=  1  1  4  2  1  1  0  0

*/

#include <bits/stdc++.h>
using namespace std;

// implementation #1
// idea: for every item, check forward for temp_diff, then report back (store in results)
// N^2, SLOW, will TLE for 10,000+ elements
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> results(n, 0);

    for (int curr_temp_idx = 0; curr_temp_idx < n; curr_temp_idx++) {
        if (auto it = find_if(temperatures.begin() + curr_temp_idx + 1,
                              temperatures.end(),
                              [&](int temp) { return temp > temperatures[curr_temp_idx]; });
            it != temperatures.end()) {
            // get it idx, calculate distance
            int found_temp_idx = std::distance(temperatures.begin(), it);
            int distance_to_curr_temp_idx = found_temp_idx - curr_temp_idx;

            // add pos
            results.push_back(distance_to_curr_temp_idx);
        } else {
            // add 0
            results.push_back(0);
        }
    }

    return results;
}

// implementation #2
// idea: for every new item, check backwards for temp_diff, store in results

auto main() -> int {
    // problem case

    return 0;
}