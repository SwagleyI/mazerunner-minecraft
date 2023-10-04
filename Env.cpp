Env::Env(){
this->length = 0;
this->width = 0;
envStructure = new char*[length];
for(int i =0; i < length; i++){
envStructure[i] = new char[width];
}
}
Env::Env(int length, int width) {
this->length = length;
this->width = width;
envStructure = new char*[length];
for(int i =0; i < length; i++){
envStructure[i] = new char[width];
}
}
Env::~Env(){
for(int i=0; i < this->length; i++){
delete[] this->envStructure[i];
}
delete[] this->envStructure;
}
int Env::getLength() {
return this->length