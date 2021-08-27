class Solution {
public
    vectorint spiralOrder(vectorvectorint& matrix) {
        if (matrix.size() == 0  matrix[0].size() == 0) {
            return {};
        }
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int rows = matrix.size(), columns = matrix[0].size();
        vectorvectorbool visited(rows, vectorbool(columns));
        int total = rows  columns;
        vectorint order(total);

        int row = 0, column = 0;
        int directionIndex = 0;
        for (int i = 0; i  total; i++) {
            order[i] = matrix[row][column];
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex][0], nextColumn = column + directions[directionIndex][1];
            if (nextRow  0  nextRow = rows  nextColumn  0  nextColumn = columns  visited[nextRow][nextColumn]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
        return order;
    }
};

