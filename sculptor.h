#include "voxel.h"

/*** A primeira etapa do projeto consiste em conceber uma classe em C++ que permita realizar operações em uma matriz tridimensional alocada dinamicamente. Os elementos dessa matriz guardam propriedades da escultura e são denominados Voxels (volume elements).
* Tal matriz possue dimensões de comprimento, altura e largura especificadas pelo usuário, onde os índices dos elementos nessa matriz coresponderiam às posições dos voxels no espaço discreto. Além disso há instancias de cores e transparência do voxel.
* A Classe Sculptor instancia todos os objetos e métodos que serão utilizados para a escultura do desenho, que por sua vez são inicializadas por um Contrutor e liberadas por um destrutor. 
*/
  
class Sculptor {
protected:
  Voxel ***v;
  int nx,ny,nz; // Dimensions
  float r,g,b,a; // Current drawing color

public:
  Sculptor(int _nx, int _ny, int _nz);
  ~Sculptor();

/**
* A partir dos métodos podemos criar voxels, blocos, elipsóides e esferas, assim como podemos excluí-las a partir dos comandos do usuário.

* O método setColor() recebe do usuário os dados da cor do voxel, armazenadas nas variáveis r, g e b usadas para compor uma cor específica, e sua transparência por a (alpha). Cada uma delas deve assumir valores de 0 a 1, sendo 0 a não inclusão da função da variável e 1 a sua presença total.
*/
  void setColor(float r_, float g_, float b_, float alpha);
/**
* O método putVoxel() ativa o voxel na posição (x,y,z) da matriz recebidas pelo usuário e atribui ao mesmo a cor atual de desenho.
*/
  void putVoxel(int x, int y, int z);
/**
* O método cutVoxel() desativa o voxel na posição (x,y,z) recebida pelo usuário.
*/
  void cutVoxel(int x, int y, int z);
/**
* O método putBox() ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho.
*/
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
/**
* O método cutBox() desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho.
*/
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
/**
*O método putSphere() recebe do usuário a posição (x,y,z) e seu raio, ativando assim todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho (r,g,b,a).
*/
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);
/**
* O método cutSphere() recebe do usuário a posição (x,y,z) e seu raio para desativar todos os voxels que satisfazem à equação da esfera.
*/
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
/**
* O método putEllipsoid() recebe do usuário a posição (x,y,z) e seus raios para ativar todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho.
*/
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
/**
* O método cutEllipsoid() recebe do usuário a posição (x,y,z) e seus raios para desativar todos os voxels que satisfazem à equação do elipsóide.
*/
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
/**
* O método writeOFF() grava as descrições da escultura até então elaboradas pelos métodos acima no formato OFF no arquivo filename enviado.
*/
  void writeOFF(const char* filename);
};