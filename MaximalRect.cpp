#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int max_area = 0;
    heights.push_back(0); // Add a zero height to handle remaining elements in the stack.
    for (int i = 0; i < heights.size(); ++i) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            int h = heights[st.top()];
            st.pop();
            int width = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area, h * width);
        }
        st.push(i);
    }
    return max_area;
}

int maximalRectangle(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    int rows = matrix.size(), cols = matrix[0].size();
    vector<int> heights(cols, 0);
    int max_area = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            heights[j] = (matrix[i][j] == 1) ? heights[j] + 1 : 0;
        }
        max_area = max(max_area, largestRectangleArea(heights));
    }

    return max_area;
}
