class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = matrix.front().size();

        vector<int> answer; answer.reserve(m*n);

        int top = 0; int bottom = m - 1;
        int left = 0; int right = n - 1;

        while (top <= bottom && left <= right){
            for (int i = left; i <= right; i++){
                answer.emplace_back(matrix.at(top).at(i));
            }
            top++; 

            if (top > bottom) break;

            for (int j = top; j <= bottom; j++){
                answer.emplace_back(matrix.at(j).at(right));
            }
            right--; // the next horizontal to right should stop before i = n - 2

            if (left > right) break;

            for (int k = right; k >= left; k--){
                 answer.emplace_back(matrix.at(bottom).at(k));
            }
            bottom--;

            if (top > bottom) break; 

            for (int f = bottom; f >= top; f--){
                answer.emplace_back(matrix.at(f).at(left));
            }
            left++;
        }
        return answer;
    }
};
const size_t BUFFER_SIZE = 0x6fafffff;
alignas(std::max_align_t) char buffer[BUFFER_SIZE]; size_t buffer_pos = 0; 
void* operator new(size_t size) { 
    constexpr std::size_t alignment = alignof(std::max_align_t); 
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment; 
    size_t total_size = size + padding; 
    char* aligned_ptr = &buffer[buffer_pos + padding]; 
    buffer_pos += total_size; return aligned_ptr; 
    } 
void operator delete(void* ptr, unsigned long) noexcept {} 
void operator delete(void* ptr) noexcept {} 
void operator delete[](void* ptr) noexcept {}