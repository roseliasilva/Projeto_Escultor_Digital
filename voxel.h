/**
* Classe Struct Voxel permite armazenar três tipos de informações: a cor do voxel, sua transparência e se ele deverá ser incluído ou não no modelo digital que representa a escultura. 
*/

struct Voxel {
  float r,g,b; // Colors
  float a;
  // Transparency
  bool isOn; // Included or not
};