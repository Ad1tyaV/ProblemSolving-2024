#include<iostream>
#include<vector>

using namespace std;

vector<int> spiralForm(vector<vector<int>>& matrix, int rows, int cols) {

    int rowStart = 0;
    int colStart = 0;
    int rowEnd = rows-1;
    int colEnd = cols-1;    
    vector<int> result;

    while(rowStart<=rowEnd && colStart<=colEnd) {
        // Go right
        for(int y=colStart; y<=colEnd; y++) {
            result.push_back(matrix[rowStart][y]);
        }
        rowStart++;

        // Go Down
        for(int x=rowStart; x<=rowEnd; x++) {
            result.push_back(matrix[x][colEnd]);
        }
        colEnd--;

        
        // Go left
        if(rowStart<=rowEnd) {
            for(int y=colEnd; y>=colStart; y--) {
                result.push_back(matrix[rowEnd][y]);
            }
            rowEnd--;
        }
        
        if (colStart <= colEnd) {
            for(int x=rowEnd; x>=rowStart; x--) {
                result.push_back(matrix[x][colStart]);
            }
            colStart++;
        }
        
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = {{1,    2,   3,   4},
                                  {5,    6,   7,   8},
                                  {9,   10,  11,  12},
                                  {13,  14,  15,  16 }};

    vector<int> result = spiralForm(matrix, matrix.size(), matrix[0].size());

    for(int x: result) {
        cout<<x<<"\t";
    }
    cout<<endl;

    return 0;
}

/*
6 6 2 28 2
12 26 3 28 7 
22 25 3 4 23
*/