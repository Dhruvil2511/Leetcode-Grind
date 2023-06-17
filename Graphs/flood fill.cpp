class Solution {
public:
    void fillColor(vector<vector<int>>& image,int row,int col,int oldColor,int color){
        if(row<0||row>image.size()-1||col<0 || col>image[row].size()-1|| image[row][col]!=oldColor)return;
        
        image[row][col]=color;
        fillColor(image,row+1,col,oldColor,color);
        fillColor(image,row-1,col,oldColor,color);
        fillColor(image,row,col+1,oldColor,color);
        fillColor(image,row,col-1,oldColor,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];
        if(oldColor==color)return image;
        fillColor(image,sr,sc,oldColor,color);
        return image;
    }
};
