class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        heights.push_back(0);  // Add a sentinel to ensure we empty the stack at the end

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = (st.empty()) ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }

        return maxArea;
    }

    // Function to find the maximal rectangle in the binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Update the histogram heights array
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            // Calculate the maximal rectangle for the current row's histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
 