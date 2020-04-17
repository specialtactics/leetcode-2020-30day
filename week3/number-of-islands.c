void iterateSquare(int **seen, char** grid, int vertical, int startingHorizontal, int maxI, int maxJ);

int numIslands(char** grid, int rows, int* cols){
    int **seen = (int **)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; ++i) {
        seen[i] = (int *)malloc((*cols) * sizeof(int));
        for (int j = 0; j < *cols; ++j) {
            seen[i][j] = 0;
        }
    }
    int islands = 0;

    // Loop through
    for (int i = 0; i < rows; ++ i) {
        for (int j = 0; j < *cols; ++j) {
            if (seen[i][j] == 0 && grid[i][j] == '1') {
                ++islands;
                iterateSquare(seen, grid, i, j, rows, *cols);
            }
        }
    }
    
    for (int i = 0; i < rows; ++i) free(seen[i]);
    free(seen);
    
    return islands;
}


void iterateSquare(int **seen, char** grid, int vertical, int startingHorizontal, int maxI, int maxJ) {
    // Horizonally right
    for (int b = startingHorizontal; b < maxJ; ++b) {
        if (grid[vertical][b] != '1') {
            break;
        } else {
            seen[vertical][b] = 1;

            if (vertical - 1 >= 0) {
                if (grid[vertical-1][b] == '1' && seen[vertical-1][b] == 0) {
                    iterateSquare(seen, grid, vertical - 1, b, maxI, maxJ);                    
                }                         
            }
            if (vertical + 1 < maxI) {
                printf("1| %d, %d\n", vertical+1, b);
                if (grid[vertical+1][b] == '1' && seen[vertical+1][b] == 0) {
                    iterateSquare(seen, grid, vertical + 1, b, maxI, maxJ);                    
                }             
            }
        }
    }

    // Horizonally left
    for (int b = (startingHorizontal - 1); b >= 0; --b) {
        if (grid[vertical][b] != '1') {
            break;
        } else {
            seen[vertical][b] = 1;

            if (vertical - 1 >= 0) {
                if (grid[vertical-1][b] == '1' && seen[vertical-1][b] == 0) {
                    iterateSquare(seen, grid, vertical - 1, b, maxI, maxJ);                    
                }                    
            }
            if (vertical + 1 < maxI) {
                printf("2| %d, %d\n", vertical+1, b);
                if (grid[vertical+1][b] == '1' && seen[vertical+1][b] == 0) {
                    iterateSquare(seen, grid, vertical + 1, b, maxI, maxJ);                    
                }                    
            }
        }
    }
} 
