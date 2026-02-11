#include "Ball.h"
#include <vector>
#include "raylib.h"
#pragma once
struct SpatialHash{//Define Spatial Hash which we use to optimize ball to ball collision
    int width{0};
    int height{0};
    float cell_size{0.0};
    std::vector< std::vector<int> > Grid;    
    SpatialHash(int w,int h, float cs) : width(w),height(h),cell_size(cs) {
    Grid.resize((width * height) / (cell_size*cell_size));
    }
    SpatialHash() = default;
    //We create an Insert function such that we give each ball a different index putting said index inside the grid vector and we assign Ball.ind to the coordinates of its center in the Hash
    void Insert(Ball& Ball,int index){
        int i = Ball.pos.x / cell_size;
        int j = Ball.pos.y / cell_size;
        Ball.ind = Vec2(i,j);
        Grid[(j * (width / cell_size)) + i].push_back(index);
    }
    //We clear the vector while mainteining its initial size
    void Clear(){
        for (std::vector <int>& cell: Grid){
            cell.clear();
        }
    }  
};
//We create a vector of indexes for all balls that are either inside neighbouring cells or inside the same cell as the one given
std::vector <int> GetNeighbours(SpatialHash& S, Vec2 Ind){
        std::vector <int> poss_colliders;
        int cols = S.width / S.cell_size;
        int rows = S.height / S.cell_size;
        for (int i=-1; i <= 1; i++){
            for (int j=-1; j <= 1; j++){
                int x = Ind.x + i;
                int y = Ind.y + j;
                if (x >= 0 and x <cols and y>=0 and y<rows){
                    for (int index: S.Grid[(y * cols) + x]){
                        poss_colliders.push_back(index);
                    }
                }
            }
        }
        return poss_colliders;
}
//Define Draw function with the objective to Debug and use it in Debug Mode
void Draw(SpatialHash Grid) {
        int n = Grid.width / Grid.cell_size;
        int m = Grid.height / Grid.cell_size;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (Grid.Grid[(j * n) + i].size() == 0){
                DrawRectangleLines(Grid.cell_size * i, Grid.cell_size * j, Grid.cell_size, Grid.cell_size, WHITE);
                }
                else{
                    DrawRectangleLines(Grid.cell_size * i, Grid.cell_size * j, Grid.cell_size, Grid.cell_size, RED);
                }
            }
        }
    }