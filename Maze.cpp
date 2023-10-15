#include "Maze.h"
#include <random>


Maze::Maze(mcpp::Coordinate basePoint, unsigned int xlen, 
                                    unsigned int zlen,
                                    bool mode)
                                    
{
}

void buildInMinecraft(char arr[i][j], int build_x, int build_y, int build_z, int height) {
    // VERY BASIC // MUST FIX ASAP //
    mcpp::MinecraftConnection mc;
    mcpp::Coordinate startCoord(build_x, build_y, build_z);
    for (int a = 0; a < arr[i].length; a++) {
        for (int b = 0; b < arr[j].length; b++) {
            mc.setBlock(startCoord+mcpp::Coordinate(a, 0, b), mcpp::Blocks::AIR);
            if (arr[a][b] == 'x'){
                mc.setBlock(startCoord+mcpp::Coordinate(a, 0, b), mcpp::Blocks::COAL_ORE);
            }
                
        }
    }
}

Maze::~Maze()
{
}