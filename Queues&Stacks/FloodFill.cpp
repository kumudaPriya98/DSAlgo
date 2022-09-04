#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
    if (newColor == image[sr][sc]) return image;
    dfs(image, sr, sc, newColor, image[sr][sc]);
    return image;
}

void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor) {
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() ||
       image[sr][sc] != oldColor) return;

    image[sr][sc] = newColor;
    for (int i = -1; i < 2; i++) {
        dfs(image, sr + i, sc, newColor, oldColor);
        dfs(image, sr, sc + i, newColor, oldColor);
    }
}