#include <mcpp/mcpp.h>
#include "Env.h"
void ReadEnvSize(int& envLength, int& envWidth);
void readEnvStdin(char** EnvStruct, int length, int width);
void ReadBuildLocation(int& build_x, int& build_y, int& build_z);
int main(void){
std::cout << "Program started" << std::endl;
mcpp::MinecraftConnection mc;
mc.doCommand("time set day");
int envLength = 0;
int envWidth = 0;
ReadEnvSize(envLength, envWidth);
Env test_env(envLength, envWidth);
std::cout << "Length: " << test_env.getLength() <<
", Width: " << test_env.getWidth() << std::endl;
char readChar;
for (int row = 0; row < envLength; row++) {
for (int col = 0; col < envWidth; col++) {
std::cin >> readChar;
test_env.setEnvElement(row, col, readChar);
}
}
int build_x = 0;
int build_y = 0;
int build_z = 0;
ReadBuildLocation(build_x, build_y, build_z);
std::cout << "Building at X: " << build_x << ", Y: " << build_y <<
", Z: " << build_z << std::endl;
mcpp::Coordinate startCoord(build_x, build_y, build_z);
for (int row = 0; row < envLength; row++) {
for (int col = 0; col < envWidth; col++) {
mc.setBlock(startCoord+mcpp::Coordinate(row, 0, col), mcpp::Blocks::AIR);
if (test_env.getEnvElement(row, col) == 'x'){
mc.setBlock(startCoord+mcpp::Coordinate(row, 0, col),
mcpp::Blocks::BRICKS);
}
}
}
return EXIT_SUCCESS;
}