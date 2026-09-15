int maxArea(int* height, int heightSize) {
    if (heightSize < 2 || heightSize > 1000000) return 0;

    int max_area = INT_MIN;
    int curr_area = 0;
    
    int left_index = 0;
    int right_index = heightSize - 1;

    while (left_index < right_index) {
        int left_height = height[left_index];
        int right_height = height[right_index];

        if (left_height < right_height) {
            curr_area = left_height * (right_index - left_index);
            max_area = (max_area < curr_area) ? curr_area : max_area;
            left_index++;

        } else if (left_height > right_height) {
            curr_area = right_height * (right_index - left_index);
            max_area = (max_area < curr_area) ? curr_area : max_area;
            right_index--;
            
        } else {
            curr_area = left_height * (right_index - left_index);
            max_area = (max_area < curr_area) ? curr_area : max_area;
            left_index++;
        }
        
    }

    return max_area;
}