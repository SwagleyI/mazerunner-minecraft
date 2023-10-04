#ifndef ENV
#define ENV
class Env {
public:
//constructors/de-constructors
Env();
Env(int length, int width);
~Env();
//methods
int getLength();
int getWidth();
void setEnvElement(int, int, char);
char getEnvElement(int, int);
private:
//Fields
int length;
int width;
char **envStructure;
};
#endif //ENV