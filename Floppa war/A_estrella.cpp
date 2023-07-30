#include ""
#include <iostream>
#include <vector>
#include <math.h>
#include <float.h>

int COLUMNAS = 10;
int FILAS = 10;

class celda {
public:
    int posX, posY  ; // posicion en la matriz
    float f,g,h   ;   // euristica f(n) = g(n) + h(n)
    celda(){
        f = FLT_MAX;
		g = FLT_MAX;
		h = FLT_MAX;
		posX = -1;
		posY = -1;
    } 
};

bool rango(int posX,int posY){ // evaluar si la posicion esta dentro de la matriz
    return (posX >= 0) && (posX < FILAS) && (posY >= 0) && (posY < COLUMNAS);
}
bool es_camino(std::vector<std::vector<int>> mapa, int posX,int posY){ // verifica si la celda esta bloqueada o no 
    if (mapa[posX][posY] == 1)
        return true;
    else if (mapa[posX][posY] == -1)
        return false;
    else
        return false;
}
float valor_h(int posX, int posY,int FposX,int FposY){// distancia euclidiana
	return static_cast<float>(sqrt((posX - FposX) * (posX - FposX) + (posY - FposY) * (posY - FposY)));
}
bool es_el_Destino(int posX, int posY,int FposX,int FposY){ // revisa si es el destino
	if (posX == FposX && posY == FposY)
		return (true);
	else
		return (false);
}
void ruta_seguir(std::vector<std::vector<celda>>MatrizCelda,int FposX,int FposY)
{
	printf("\nEl camino es: ");
	int row = FposX;
	int col = FposY;
    std::vector<celda> array;

	while (!(MatrizCelda[row][col].posX == row  && MatrizCelda[row][col].posY == col)) {
        celda auxiliar;
        auxiliar.posX = row;
        auxiliar.posY = col;
		array.insert(array.begin(),auxiliar);
		int temp_row = MatrizCelda[row][col].posX;
		int temp_col = MatrizCelda[row][col].posY;
		row = temp_row;
		col = temp_col;
	}
    celda auxiliar;
    auxiliar.posX = row;
    auxiliar.posY = col;
	array.insert(array.begin(),auxiliar);
	for(const auto &recorrido : array)
        std::cout << " -> " <<"(" <<recorrido.posX << "," << recorrido.posY << ")";

	return;
}

void buscador_Aestrella(std::vector<std::vector<int>> mapa,int posX, int posY,int FposX,int FposY){
    if(rango(posX,posY) == false || rango(FposX,FposY)== false ){
        std::cout <<"la posicion incial o el destino estan fuera de rango"<<std::endl;
        return;
    }
    if(es_camino(mapa,posX,posY) == false ||es_camino(mapa,FposX,FposY) == false){
        std::cout <<"la posicion incial o el destino estan no es un camino"<<std::endl;
        return;
    }
    if(es_el_Destino(posX,posY,FposX,FposY) == true){
        std::cout <<"estamos en el destino"<<std::endl;
        return;
    }

    std::vector<std::vector<bool>> closedList (FILAS,std::vector<bool>(COLUMNAS,false)); // verifica si la posicion ya fue revisada
    std::vector<std::vector<celda>> MatrizCelda (FILAS,std::vector<celda>(COLUMNAS));  //  contiene detalles de cada una de las posiciones del mapa
    int i,j; // posiciones a recorrer

    i = posX, j = posY;
	MatrizCelda[i][j].f = 0.0;
	MatrizCelda[i][j].g = 0.0;
	MatrizCelda[i][j].h = 0.0;
	MatrizCelda[i][j].posX = i;
	MatrizCelda[i][j].posY = j;

    std::vector<celda> openList; //

    openList.push_back(MatrizCelda[i][j]);

    bool Destino_encontrado = false;

    while (!openList.empty()){
        celda p = *openList.begin();
 
        openList.erase(openList.begin()); //eliminamos el primer elemento del openList

        i = p.posX;
		j = p.posY;
		closedList[i][j] = true;
        /*
            N.O   N   N.E
			   \  |  /
				\ | /
		   O----Celda----E
				/ | \
			   /  |  \
			S.O   S   S.E

        Celda-->posicion de la celda (i, j)
		N --> Norte (i-1, j)
		S --> Sur	 (i+1, j)
		E --> Este	 (i, j+1)
		O --> Oeste		 (i, j-1)
		N.E--> Nor-Este (i-1, j+1)
		N.O--> Nor-Oeste (i-1, j-1)
		S.E--> Sur-Oeste (i+1, j+1)
		S.O--> Sur-Oeste (i+1, j-1)
        */
        float gNew, hNew, fNew;
    //----------- 1er Sucesor (Norte) ------------
	    if (rango(i - 1, j) == true) {// Verifica si la celda esta en la matriz
            
			if (es_el_Destino(i - 1, j,FposX,FposY) == true) { // verifica si la celda sucesora es el destino
				// designa el padre de la celda
				MatrizCelda[i - 1][j].posX = i;
				MatrizCelda[i - 1][j].posY = j;
				std::cout << "Se encontro la celda destino\n" << std::endl;
                ruta_seguir(MatrizCelda,FposX,FposY);
				Destino_encontrado = true;
				break;
			}
			else if (closedList[i - 1][j] == false && es_camino(mapa, i - 1, j) == true) { //verifica si la celda ya esta cerrada
				gNew = MatrizCelda[i][j].g + 1.0;
				hNew = valor_h(i - 1, j,FposX,FposY);
				fNew = gNew + hNew;
                //std::cout<<"1er"<<std::endl;
				if (MatrizCelda[i - 1][j].f == FLT_MAX  || MatrizCelda[i - 1][j].f > fNew) {//verifica si se mejora el camino
                    MatrizCelda[i - 1][j].posX = i - 1;   
					MatrizCelda[i - 1][j].posY = j;
					openList.push_back(MatrizCelda[i - 1][j]);  //actualiza openList con la posicion de la celda
					//actualiza la celda
					MatrizCelda[i - 1][j].f = fNew;
					MatrizCelda[i - 1][j].g = gNew;
					MatrizCelda[i - 1][j].h = hNew;
                    // designa el padre de la celda
					MatrizCelda[i - 1][j].posX = i; 
					MatrizCelda[i - 1][j].posY = j;
				}
			}
		}
		//----------- 2do Sucesor (Sur) ------------
	    if (rango(i + 1, j) == true) {// Verifica si la celda esta en la matriz
        
			if (es_el_Destino(i + 1, j,FposX,FposY) == true) {// verifica si la celda sucesora es el destino
				// designa el padre de la celda
				MatrizCelda[i + 1][j].posX = i;
				MatrizCelda[i + 1][j].posY = j;
				std::cout << "Se encontro la celda destino\n" << std::endl;
                ruta_seguir(MatrizCelda,FposX,FposY);
				Destino_encontrado = true;
				break;
			}
			else if (closedList[i + 1][j] == false && es_camino(mapa, i + 1, j) == true) { //verifica si la celda ya esta cerrada
				gNew = MatrizCelda[i][j].g + 1.0;
				hNew = valor_h(i + 1, j,FposX,FposY);
				fNew = gNew + hNew;
                //std::cout << "2do" << std::endl;
				if (MatrizCelda[i + 1][j].f == FLT_MAX  || MatrizCelda[i + 1][j].f > fNew) {//verifica si se mejora el camino
                    MatrizCelda[i + 1][j].posX = i + 1;   
					MatrizCelda[i + 1][j].posY = j;
					openList.push_back(MatrizCelda[i + 1][j]);  //actualiza openList con la posicion de la celda
					//actualiza la celda
					MatrizCelda[i + 1][j].f = fNew;
					MatrizCelda[i + 1][j].g = gNew;
					MatrizCelda[i + 1][j].h = hNew;
                    // designa el padre de la celda
					MatrizCelda[i + 1][j].posX = i; 
					MatrizCelda[i + 1][j].posY = j;
				}
			}
		}
        //----------- 3er Sucesor (Este) ------------
        if (rango(i, j + 1) == true) {// Verifica si la celda esta en la matriz
           
			if (es_el_Destino(i, j + 1,FposX,FposY) == true) {// verifica si la celda sucesora es el destino
				// designa el padre de la celda
				MatrizCelda[i][j + 1].posX = i;
				MatrizCelda[i][j + 1].posY = j;
				std::cout << "Se encontro la celda destino\n" << std::endl;
                ruta_seguir(MatrizCelda,FposX,FposY);
				Destino_encontrado = true;
				break;
			}
			else if (closedList[i][j + 1] == false && es_camino(mapa,i, j + 1) == true) { //verifica si la celda ya esta cerrada
				gNew = MatrizCelda[i][j].g + 1.0;
				hNew = valor_h(i, j + 1,FposX,FposY);
				fNew = gNew + hNew;
                //std::cout << "3er" << std::endl;
				if (MatrizCelda[i][j + 1].f == FLT_MAX  || MatrizCelda[i][j + 1].f > fNew) {//verifica si se mejora el camino
                    MatrizCelda[i][j + 1].posX = i;   
					MatrizCelda[i][j + 1].posY = j + 1;
					openList.push_back(MatrizCelda[i][j + 1]);  //actualiza openList con la posicion de la celda
					//actualiza la celda
					MatrizCelda[i][j + 1].f = fNew;
					MatrizCelda[i][j + 1].g = gNew;
					MatrizCelda[i][j + 1].h = hNew;
                    // designa el padre de la celda
					MatrizCelda[i][j + 1].posX = i; 
					MatrizCelda[i][j + 1].posY = j;
				}
			}
		}
        //----------- 4to Sucesor (Oeste) ------------
        if (rango(i, j - 1) == true) {// Verifica si la celda esta en la matriz
            
			if (es_el_Destino(i, j - 1,FposX,FposY) == true) {// verifica si la celda sucesora es el destino
				// designa el padre de la celda
				MatrizCelda[i][j - 1].posX = i;
				MatrizCelda[i][j - 1].posY = j;
				std::cout << "Se encontro la celda destino\n" << std::endl;
                ruta_seguir(MatrizCelda,FposX,FposY);
				Destino_encontrado = true;
				break;
			}
			else if (closedList[i][j - 1] == false && es_camino(mapa,i, j - 1) == true) { //verifica si la celda ya esta cerrada
				gNew = MatrizCelda[i][j - 1].g + 1.0;
				hNew = valor_h(i, j + 1,FposX,FposY);
				fNew = gNew + hNew;
                //std::cout << "4to" << std::endl;
				if (MatrizCelda[i][j - 1].f == FLT_MAX  || MatrizCelda[i][j - 1].f > fNew) {//verifica si se mejora el camino
                    MatrizCelda[i][j - 1].posX = i;   
					MatrizCelda[i][j - 1].posY = j - 1;
					openList.push_back(MatrizCelda[i][j - 1]);  //actualiza openList con la posicion de la celda
					//actualiza la celda
					MatrizCelda[i][j - 1].f = fNew;
					MatrizCelda[i][j - 1].g = gNew;
					MatrizCelda[i][j - 1].h = hNew;
                    // designa el padre de la celda
					MatrizCelda[i][j - 1].posX = i; 
					MatrizCelda[i][j - 1].posY = j;
				}
			}
		}
        //----------- 5to Sucesor (Nor-Este) ------------
        if (rango(i - 1, j + 1) == true) {// Verifica si la celda esta en la matriz
        
			if (es_el_Destino(i - 1, j + 1,FposX,FposY) == true) {// verifica si la celda sucesora es el destino
				// designa el padre de la celda
				MatrizCelda[i - 1][j + 1].posX = i;
				MatrizCelda[i - 1][j + 1].posY = j;
				std::cout << "Se encontro la celda destino\n" << std::endl;
                ruta_seguir(MatrizCelda,FposX,FposY);
				Destino_encontrado = true;
				break;
			}
			else if (closedList[i - 1][j + 1] == false && es_camino(mapa, i - 1, j + 1) == true) { //verifica si la celda ya esta cerrada
				gNew = MatrizCelda[i][j].g + 1.414;
				hNew = valor_h(i - 1, j + 1,FposX,FposY);
				fNew = gNew + hNew;
                //std::cout << "5to" << std::endl;
				if (MatrizCelda[i - 1][j + 1].f == FLT_MAX  || MatrizCelda[i - 1][j + 1].f > fNew) {//verifica si se mejora el camino
                    MatrizCelda[i - 1][j + 1].posX = i - 1;   
					MatrizCelda[i - 1][j + 1].posY = j + 1;
					openList.push_back(MatrizCelda[i - 1][j + 1]);  //actualiza openList con la posicion de la celda
					//actualiza la celda
					MatrizCelda[i - 1][j + 1].f = fNew;
					MatrizCelda[i - 1][j + 1].g = gNew;
					MatrizCelda[i - 1][j + 1].h = hNew;
                    // designa el padre de la celda
					MatrizCelda[i - 1][j + 1].posX = i; 
					MatrizCelda[i - 1][j + 1].posY = j;
				}
			}
		}
        //----------- 6to Sucesor (Nor-Oeste) ------------
        if (rango(i - 1, j - 1) == true) {// Verifica si la celda esta en la matriz
        
			if (es_el_Destino(i - 1, j - 1,FposX,FposY) == true) {// verifica si la celda sucesora es el destino
				// designa el padre de la celda
				MatrizCelda[i - 1][j - 1].posX = i;
				MatrizCelda[i - 1][j - 1].posY = j;
				std::cout << "Se encontro la celda destino\n" << std::endl;
                ruta_seguir(MatrizCelda,FposX,FposY);
				Destino_encontrado = true;
				break;
			}
			else if (closedList[i - 1][j - 1] == false && es_camino(mapa, i - 1, j - 1) == true) { //verifica si la celda ya esta cerrada
				gNew = MatrizCelda[i][j].g + 1.414;
				hNew = valor_h(i - 1, j - 1,FposX,FposY);
				fNew = gNew + hNew;
                //std::cout << "6to" << std::endl;
				if (MatrizCelda[i - 1][j - 1].f == FLT_MAX  || MatrizCelda[i - 1][j - 1].f > fNew) {//verifica si se mejora el camino
                    MatrizCelda[i - 1][j - 1].posX = i - 1;   
					MatrizCelda[i - 1][j - 1].posY = j - 1;
					openList.push_back(MatrizCelda[i - 1][j - 1]);  //actualiza openList con la posicion de la celda
					//actualiza la celda
					MatrizCelda[i - 1][j - 1].f = fNew;
					MatrizCelda[i - 1][j - 1].g = gNew;
					MatrizCelda[i - 1][j - 1].h = hNew;
                    // designa el padre de la celda
					MatrizCelda[i - 1][j - 1].posX = i; 
					MatrizCelda[i - 1][j - 1].posY = j;
				}
			}
		}
        //----------- 7mo Sucesor (Sur-Este) ------------
	    if (rango(i + 1, j + 1) == true) {// Verifica si la celda esta en la matriz
		    
			if (es_el_Destino(i + 1, j + 1,FposX,FposY) == true) {// verifica si la celda sucesora es el destino
				// designa el padre de la celda
				MatrizCelda[i + 1][j + 1].posX = i;
				MatrizCelda[i + 1][j + 1].posY = j;
				std::cout << "Se encontro la celda destino\n" << std::endl;
                ruta_seguir(MatrizCelda,FposX,FposY);
				Destino_encontrado = true;
				break;
			}
			else if (closedList[i + 1][j + 1] == false && es_camino(mapa, i + 1, j + 1) == true) { //verifica si la celda ya esta cerrada
				gNew = MatrizCelda[i][j].g + 1.414;
				hNew = valor_h(i + 1, j + 1,FposX,FposY);
				fNew = gNew + hNew;
                //std::cout << "7mo" << std::endl;
				if (MatrizCelda[i + 1][j + 1].f == FLT_MAX  || MatrizCelda[i + 1][j + 1].f > fNew) {//verifica si se mejora el camino
                    MatrizCelda[i + 1][j + 1].posX = i + 1;   
					MatrizCelda[i + 1][j + 1].posY = j + 1;
					openList.push_back(MatrizCelda[i + 1][j + 1]);  //actualiza openList con la posicion de la celda
					//actualiza la celda
					MatrizCelda[i + 1][j + 1].f = fNew;
					MatrizCelda[i + 1][j + 1].g = gNew;
					MatrizCelda[i + 1][j + 1].h = hNew;
                    // designa el padre de la celda
					MatrizCelda[i + 1][j + 1].posX = i; 
					MatrizCelda[i + 1][j + 1].posY = j;
				}
			}
		}
        //----------- 8vo Sucesor (Sur-Oeste) ------------
	    if (rango(i + 1, j - 1) == true) {// Verifica si la celda esta en la matriz
            
			if (es_el_Destino(i + 1, j - 1,FposX,FposY) == true) {// verifica si la celda sucesora es el destino
				// designa el padre de la celda
				MatrizCelda[i + 1][j - 1].posX = i;
				MatrizCelda[i + 1][j - 1].posY = j;
				std::cout << "Se encontro la celda destino\n" << std::endl;
                ruta_seguir(MatrizCelda,FposX,FposY);
				Destino_encontrado = true;
				break;
			}
			else if (closedList[i + 1][j - 1] == false && es_camino(mapa, i + 1, j - 1) == true) { //verifica si la celda ya esta cerrada
				gNew = MatrizCelda[i][j].g + 1.414;
				hNew = valor_h(i + 1, j - 1,FposX,FposY);
				fNew = gNew + hNew;
                //std::cout << "8vo" << std::endl;
				if (MatrizCelda[i + 1][j - 1].f == FLT_MAX  || MatrizCelda[i + 1][j - 1].f > fNew) {//verifica si se mejora el camino
                    MatrizCelda[i + 1][j - 1].posX = i + 1;   
					MatrizCelda[i + 1][j - 1].posY = j - 1;
					openList.push_back(MatrizCelda[i + 1][j - 1]);  //actualiza openList con la posicion de la celda
					//actualiza la celda
					MatrizCelda[i + 1][j - 1].f = fNew;
					MatrizCelda[i + 1][j - 1].g = gNew;
					MatrizCelda[i + 1][j - 1].h = hNew;
                    // designa el padre de la celda
					MatrizCelda[i + 1][j - 1].posX = i; 
					MatrizCelda[i + 1][j - 1].posY = j;
				}
			}
		}
    }
    if (Destino_encontrado == false)
		std::cout << "No se encontro la celda destino" << std::endl;
}

//            <-----------PRUEBA DEL ALGORITMO----------->
/*
int main (){

    int M [FILAS][COLUMNAS] = {  { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                 { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
                                 { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                                 { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
                                 { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                                 { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                                 { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
                                 { 1, 0, 1, 1, 0, 1, 0, 1, 1, 1 },
                                 { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                                 { 1, 0, 1, 0, 0, 0, 1, 0, 0, 1 } };
    
    std::vector<std::vector<int>> Matriz (FILAS,std::vector<int>(COLUMNAS)); 
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            Matriz[i][j] = M[i][j];
        }
    }
    for(int i = 0; i < FILAS; i++){
        for(int j = 0; j < COLUMNAS; j++){
            std::cout << (Matriz[i][j] ? ". " : "O "); 
        }
        std::cout<<std::endl;
    }
    buscador_Aestrella(Matriz,9,0,0,0);
    return 0;
}
*/