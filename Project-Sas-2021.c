#include<stdio.h>

typedef struct compt{
	char preNom[10];
	char Nom[10];
	char CIN [10];
	float Montant;
}compet;

compet P[50];

	void Le_menu(){
		int i=0;
		
//	compet P[100];
	
		printf("typer le Nom : ");
		scanf("%s",P[i].preNom);
		scanf("%s",P[i].Nom);
		printf("typer le CIN: ");
		scanf("%s",P[i].CIN);
		printf("typer le Montant :");
		scanf("%f",&P[i].Montant);
	}




int main(){
	int i,n;
	int C=0;
//	compet *P[C];
	
	
	printf("hello : ");
	scanf("%d",&i);
	
		switch(i){
			case 1:{
					n = 1;
						printf("Compte bancaire NB %d :\n",C+1);
					
						Le_menu();
				
						C++;
				break;
			}
			case 2:{
				
				printf("Saisissez le nombre de comptes que vous souhaitez saisir : ");
				scanf("%d",&n);
			
				
				for(i=C;i<n;i++){
				
				printf("Compte bancaire NB %d :\n",C+1);
				Le_menu();
				C++;
				}
						
				break;
			}
		}

//	scanf("%d",&i);
//	
//	switch(i){
//		case 1:{

			for(i=0;i<C;i++)
			printf("%s ,%s,%s,%.2f \n",P[i].preNom,P[i].Nom,P[i].CIN,P[i].Montant);

//			break;
//		}
//	}
//	
	
	
	
	
	
	
	return 0;
}
			
		                                                                                                                   
	        	    
	        
	
	
					        