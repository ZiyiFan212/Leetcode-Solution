// thanks to the inspiration of youtube video, and from the medium leve water question

int trap(int* height, int heightSize) {
    if (heightSize <= 1) return 0;

    int water = 0;
    int left_index = 0, right_index = heightSize - 1;

    int left_max = height[left_index];
    int right_max = height[heightSize - 1];// left and right bound

    while (left_index != right_index) {
        left_max = (height[left_index] > left_max) ? height[left_index] : left_max;
        right_max = (height[right_index] > right_max) ? height[right_index] : right_max; // updating


        if (left_max > right_max) {
            int curr_area = right_max - height[right_index];
            water += (curr_area > 0) ? curr_area : 0;

            right_index--;
        } else if (left_max < right_max) { 
            int curr_area2 = left_max - height[left_index];
            water += (curr_area2 > 0) ? curr_area2 : 0;
            
            left_index++; 
        } else {
            int curr_area3 = left_max - height[left_index];
            water += (curr_area3 > 0) ? curr_area3 : 0;

            left_index++;
        }
    }
    
    return water;
}