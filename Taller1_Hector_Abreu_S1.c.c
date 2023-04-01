#include <stdio.h>

#define TOTAL 100000
#define SD 0.05
#define UD 0.10
#define MD 0.15
#define LS 0.60

int main () {
//control de for, puntaje peleadores por round, esquina reglamentaria, puntos mamximo de tarjeta.
	int i, j, puntFloyd, puntCanelo, esq, tarj = 10;
//decision del ganador del round y caidas por round.
	int dec_f = 0, dec_c = 0, dec_emp = 0, caidas;
//tipo de victoria por round por peleador.
	int decisionDivididaFloyd = 0, decisionUnanimeFloyd = 0, decisionDivididaCanelo = 0, decisionUnanimeCanelo = 0, decisionMayoria = 0;	
//rounds ganados y perdidos de cada peleador.
	int acumGanadosFloyd = 0, acumPerdidosFloyd = 0, acumGanadosCanelo = 0, acumPerdidosCanelo = 0;
//tarjeta mayor y menor del encuentro.
	int tarjMayor = -1, tarjMenor = 10;
//puntaje total de los peleadores.
	int puntTotalFloyd = 0, puntTotalCanelo = 0;
//ganancias totales de los peleadores.
	float gananciasFloyd = 0, gananciasCanelo = 0;
	
	
	
	
	printf("===============================================================");
	printf("\nBienvenido al programa de automatizacion de tarjetas de la DAZN.");
	printf("\nPresentando la pelea de Floyd Mayweather Vs Canelo Alvarez.");
	printf("\n===============================================================\n");
	printf("\n[1]Esquina roja: Floyd Mayweather\n[2]Esquina azul: Canelo Alvarez\n[3]Empate\n");
	printf("\n===============================================================\n");
	
	for (i = 1; i <= 12; i++){
		
		for (j = 1;j <=3; j++){
			
			printf("\nJuez Num.%d, que esquina fue el ganador del round Num.%d: ", j, i);
			scanf("%d", &esq);

			if (esq == 1){
				dec_f = dec_f + 1;
				}else if (esq == 2){
					dec_c = dec_c + 1;
					}else if (esq == 3){
						dec_emp = dec_emp + 1;
						}
		}
		
		if ((dec_f == 2) && (dec_c < 2) && (dec_emp < 2)){
			puntFloyd = puntFloyd + tarj;
			puntCanelo = puntCanelo + (tarj - 1);
			}else if ((dec_f < 2) && (dec_c == 2) && (dec_emp < 2)){
				puntFloyd = puntFloyd + (tarj - 1);
				puntCanelo = puntCanelo + tarj;
				}else if ((dec_f == 3) && (dec_c < 3) && (dec_emp < 3)){
					puntFloyd = puntFloyd + tarj;
					puntCanelo = puntCanelo + (tarj - 1);
					}else if ((dec_f < 3) && (dec_c == 3) && (dec_emp < 3)){
						puntFloyd = puntFloyd + (tarj - 1);
						puntCanelo = puntCanelo + tarj;	
						}else if ((dec_f == 1) && (dec_c == 1) && (dec_emp == 1)){
							puntFloyd = puntFloyd + tarj;
							puntCanelo = puntCanelo + tarj;
							}
		
		printf("\nCuantas veces cayo la esquina roja: ");
		scanf("%d", &caidas);
		puntFloyd = puntFloyd - (caidas * 2);
		
		printf("Cuantas veces cayo la esquina azul: ");
		scanf("%d", &caidas);
		puntCanelo = puntCanelo - (caidas * 2);

		if (puntFloyd > tarjMayor){
			tarjMayor = puntFloyd;
		}else if (puntCanelo > tarjMayor){
			tarjMayor = puntCanelo;
		}
		
		if (puntFloyd < tarjMenor){
			tarjMenor = puntFloyd;
		}else if (puntCanelo < tarjMenor){
			tarjMenor = puntCanelo;
		}
		printf("\nPuntaje Esquina roja round Num.%d:%d", i, puntFloyd);
		printf("\nPuntaje Esquina azul round Num.%d:%d", i, puntCanelo);
		
		if ((dec_f == 2) && (dec_c < 2) && (dec_emp < 2)){
			printf("\n\nEn el round Num.%d el vencedor por Decision Dividida fue la esquina roja.", i);
			decisionDivididaFloyd = decisionDivididaFloyd + 1;
			acumGanadosFloyd = acumGanadosFloyd + 1;
			acumPerdidosCanelo = acumPerdidosCanelo + 1;
			}else if ((dec_f < 2) && (dec_c == 2) && (dec_emp < 2)){
				printf("\n\nEn el round Num.%d el vencedor por Decision Dividida fue la esquina azul.", i);
				decisionDivididaCanelo = decisionDivididaCanelo + 1;
				acumGanadosCanelo = acumGanadosCanelo + 1;
				acumPerdidosFloyd = acumPerdidosFloyd + 1;
				}else if ((dec_f == 3) && (dec_c == 0) && (dec_emp == 0)){
					printf("\n\nEn el round Num.%d el vencedor por Decision Unanime fue la esquina roja.", i);
					decisionUnanimeFloyd = decisionUnanimeFloyd + 1;
					acumGanadosFloyd = acumGanadosFloyd + 1;
					acumPerdidosCanelo = acumPerdidosCanelo + 1;
					}else if ((dec_f == 0) && (dec_c == 3) && (dec_emp == 0)){
						printf("\n\nEn el round Num.%d el vencedor por Decision Unanime fue la esquina azul.", i);
						decisionUnanimeCanelo = decisionUnanimeCanelo + 1;
						acumGanadosCanelo = acumGanadosCanelo + 1;
						acumPerdidosFloyd = acumPerdidosFloyd + 1;
						}else if ((dec_f == 1) && (dec_c == 1) && (dec_emp == 1)){
							printf("\n\nEn el round Num.%d el vencedor por Decision Por Mayoria fueron ambos.", i);
							decisionMayoria = decisionMayoria + 1;
							acumGanadosFloyd = acumGanadosFloyd + 1;
							acumGanadosCanelo = acumGanadosCanelo + 1;
							}	
		
		puntTotalFloyd = puntTotalFloyd + puntFloyd;
		puntTotalCanelo = puntTotalCanelo + puntCanelo;
		printf("\n\n===============================================================\n\n");
						
		dec_f = 0;
		dec_c = 0;
		dec_emp = 0;
		puntFloyd = 0;
		puntCanelo = 0;				
}

	if (puntTotalFloyd > puntTotalCanelo){
		printf("El ganador del encuentro es Floyd Mayweather.\n\n");
		gananciasFloyd = gananciasFloyd + TOTAL;
		gananciasCanelo = gananciasCanelo + (TOTAL - (TOTAL * LS));
	}else if (puntTotalFloyd < puntTotalCanelo){
		printf("El ganador del encuentro es Canelo Alvarez.\n\n");
		gananciasCanelo = gananciasCanelo + TOTAL;
		gananciasFloyd = gananciasFloyd + (TOTAL - (TOTAL * LS));
		}else if(puntTotalFloyd = puntTotalCanelo){
			printf("El resultado del encuentro fue un Empate.\n\n");
			gananciasCanelo = gananciasCanelo + TOTAL;
			gananciasFloyd = gananciasFloyd + TOTAL;
		}
	
	
	printf("\nEl puntaje total de la Esquina roja fue de %d Puntos.\nEl puntaje total de la Esquina Azul es de %d Puntos.", puntTotalFloyd, puntTotalCanelo);
	
	gananciasFloyd = gananciasFloyd + ((decisionDivididaFloyd * (TOTAL * SD)) + (decisionUnanimeFloyd * (TOTAL * UD)) + (decisionMayoria * (TOTAL * MD))); 
	gananciasCanelo = gananciasCanelo +	((decisionDivididaCanelo * (TOTAL * SD)) + (decisionUnanimeCanelo * (TOTAL * UD)) + (decisionMayoria * (TOTAL * MD)));
	
	printf("\n\nLa Esquina Roja gano %d Rounds.\nY perdio %d Rounds.\n\nLa Esquina Azul gano %d Rounds.\nY perdio %d Rounds.", acumGanadosFloyd, acumPerdidosFloyd, acumGanadosCanelo, acumPerdidosCanelo);
	printf("\n\nLa tarjeta mayor del encuentro fue de %d puntos.\nLa tarjeta menor del encuentro due de %d puntos.", tarjMayor, tarjMenor);
	printf("\n\nFloyd Mayweather tiene una Ganancia Total de %g$\n", gananciasFloyd);
	printf("Canelo Alvarez tiene una Ganancia Total de %g$\n\n", gananciasCanelo);
	return 0;
}







