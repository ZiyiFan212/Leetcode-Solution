int recursion(int i, int j, int** memory, int** matrix, int row_size, int col_size) {
    if (memory[i][j] > 0) return memory[i][j];
    int current_value = matrix[i][j];
    int counter = 1;

    int result = 0;

    // up
    if ((i + 1 < row_size) && (matrix[i + 1][j] > current_value)) {
        int result = recursion(i+1, j, memory, matrix, row_size, col_size);
        if ((result + 1) > counter) {
            counter = result + 1;
        }
    }
    // down
    if ((i - 1 > -1) && (matrix[i - 1][j] > current_value)) {
        int result = recursion(i-1, j, memory, matrix, row_size, col_size);
        if ((result + 1) > counter) {
            counter = result + 1;
        }
    }
    // left
    if ((j - 1 > -1) && (matrix[i][j - 1] > current_value)) {
        int result = recursion(i, j-1, memory, matrix, row_size, col_size);
        if ((result + 1) > counter) {
            counter = result + 1;
        }
    }
    // right
    if ((j + 1 < col_size) && (matrix[i][j + 1] > current_value)) {
        int result = recursion(i, j+1, memory, matrix, row_size, col_size);
        if ((result + 1) > counter) {
            counter = result + 1;
        }
    }
    memory[i][j] = counter;
    return counter;     
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize < 1) return 0;
    if (*matrixColSize > 200) return 0;

    int answer = 1;
    int i = 0, j = 0;

    int** memory = (int**) malloc(sizeof(int*) * matrixSize); 
    for (int row = 0; row < matrixSize; row++) {     
       memory[row] = (int*) calloc(*matrixColSize, sizeof(int));     
    }

    while (i < matrixSize) {
        int c = recursion(i, j, memory, matrix, matrixSize, *matrixColSize);
        answer = (c > answer) ? c : answer;

        if ((j + 1) < *matrixColSize) {
            j++;
        } else {
            i++;
            j = 0;
        }
    }

    free( memory );
    return answer;
}
