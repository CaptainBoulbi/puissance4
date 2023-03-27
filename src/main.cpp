#include <iostream>

void afficherMap (char map[6][7]){
	std::cout << " _______" << std::endl;
	for (int i=0; i<6; i++){
		std::cout << "|";
		for (int y=0; y<7; y++){
			std::cout << map[i][y];
		}
		std::cout << "|" << std::endl;
	}
	std::cout << " ‾‾‾‾‾‾‾"<< std::endl;
}

void remplirMap(char map[6][7]){
	for (int i=0; i<6; i++){
		for (int y=0; y<7; y++){
			map[i][y]=' ';
		}
	}
}

bool manche(char map[6][7], int pos, char j){
	if (pos < 0 || pos > 7){
		return false;
	}

	int i=6;
	while (map[i][pos] != ' ' && i>=0){ i--; }

	if (i<0){
		return false;
	}else{
		map[i][pos] = j;
		return true;
	}
}

bool egal(char a, char b, char c, char d){
	return (a == b && b == c && c == d && d != ' ');
}

bool pattern(char map[6][7], int x, int y){
	if (egal(map[x][y], map[x+1][y+1], map[x+2][y+2], map[x+3][y+3])){ return true; }
	if (egal(map[x][y], map[x][y+1], map[x][y+2], map[x][y+3])){ return true; }
	if (egal(map[x][y], map[x+1][y], map[x+2][y], map[x+3][y])){ return true; }
	if (egal(map[x][y], map[x+1][y-1], map[x+2][y-2], map[x+3][y+3])){ return true; }
	return false;
}

bool victoire(char j){
	std::cout << "\nVictoire des : " << j << std::endl;
	return true;
}

bool fin(char map[6][7]){
	for (int i=0; i<6; i++){
		for (int y=0; y<7; y++){
			if (pattern(map, i, y)){ return victoire(map[i][y]); }
		}
	}
	return false;
}

char joueurSuiv(char j){
	if (j == 'X'){
		j = 'O';
	}else{
		j = 'X';
	}
	return j;
}

int main(){
	char map[6][7];
	remplirMap(map);
	char joueur = 'X';
	int pos;

	do{
		afficherMap(map);
		do{
			std::cout << "tour joueur " << joueur << " : ";
			std::cin >> pos;
		}while (!manche(map, pos-1, joueur));
		
		joueur = joueurSuiv(joueur);
	}while (!fin(map));
	afficherMap(map);

	return 0;
}
