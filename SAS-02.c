  #include<stdio.h>
  #include<string.h>

      typedef struct {
        char preNom[10];
        char Nom[10];
        char CIN [10];
        float Montant;
      }compet;

        int C=0;
      compet P[50];

        void Le_menu(){
		
          printf("typer le Nom : ");
          scanf("%s",P[C].preNom);
          scanf("%s",P[C].Nom);
          printf("typer le CIN: ");
          scanf("%s",P[C].CIN);
          printf("typer le Montant :");
          scanf("%f",&P[C].Montant);      
}

		void Ordre_Ascendant(){	
		
			compet T;
			int n,i,X ,ech;
			
			n=C;
			do{
				ech=0;
				for(i=0;i<n-1;i++){
					if(P[i].Montant>P[i+1].Montant){
						T=P[i];
						P[i+1]=T;
						ech++;
					}
				}
			}while(ech>0);
			
				
		}
		void Ordre_Descendant(){
			compet T;
			int n,i,X ,ech;
			
			n=C;
			do{
				ech=0;
				for(i=0;i<n-1;i++){
					if(P[i].Montant<P[i+1].Montant){
						T=P[i];
						P[i+1]=T;
						ech++;
					}
				}
			}while(ech>0);
			}
			

	int serch( int j){
		char CIN[10];
	
		printf(" le CIN de compt : ");
		scanf("%s",&CIN);
		
		for(j=0;j<C;j++)
		{
			if ( strcmp(P[j].CIN, CIN) == 0 ){
				printf("\t************************************************************************\n");
				printf("%s ,%s,%s,%.2f \n",P[j].preNom,P[j].Nom,P[j].CIN,P[j].Montant);
				
				return j ;	
				}
			
		}
		
		}

	







      int main(){
      	
		float R ;
        int i,n,j;
        
      

do{
	HERE:
        printf(" 1==> Pour entrer un compte \n 2==> Pour entrer plusieurs comptes \n 3==>Operation \n 4==> Affichage \n ==>");
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
              
              n += C;
              
              for(i=C;i<n;i++){

              printf("Compte bancaire NB %d :\n",i+1);
              
              Le_menu();
              C++;
				
              }
//              C=i;
//				C = n;
              break;
            }
            case 3:{
            	
            	do{
				
            	  for(i=0;i<C;i++)
           			printf("%s , %s , %s , %.2f \n",P[i].preNom,P[i].Nom,P[i].CIN,P[i].Montant);

		              printf("1==>Retrait \n 2==>Depot \n 3==> Retour \n ==>");
		              scanf("%d",&i);
		              switch(i){
		              	case 1:{	
		              		i=serch(j);
		              		printf(" Entrez le montant que vous souhaitez retirer \n ==> ");
		              		scanf("%f",&R);
		              		P[i].Montant -= R ;
		              		printf("\t %.2f \n ",P[i].Montant);
							break;
						  }
						case 2:{
							i=serch(j);
							printf(" Entrez le montant que vous souhaitez deposer \n ==> ");
							scanf("%f",&R);
							P[i].Montant += R ;
							printf("\t %.2f \n",P[i].Montant);
							break;
						}
						case 3:{
							goto HERE;
							break;
						}						
					  }
					}while(i>0);
          
            break;
			}
         	case 4:{
			 	do{
         		printf("1==> Par Ordre Ascendant \n 2==>Par Ordre Descendant \n " );
				printf("3==>les comptes bancaires ayant un montant sup??rieur ?? un chiffre introduit \n" );
				printf("4==>les comptes bancaires ayant un montant sup??rieur ?? un chiffre introduit \n 5==>Recherche par CIN \n==> ");
				scanf("%d",&i);
         		switch(i){
         		
					 
         			case 1:{
         				
         					Ordre_Ascendant();
								
							for(i=0;i<C;i++)
           					printf("%s , %s , %s , %.2f \n",P[i].preNom,P[i].Nom,P[i].CIN,P[i].Montant);
           					
						break;
					 }
					case 2:{
							Ordre_Descendant();
							for(i=0;i<C;i++)
           					printf("%s , %s , %s , %.2f \n",P[i].preNom,P[i].Nom,P[i].CIN,P[i].Montant);
						break;
					}
					case 3:{
						float X;
						Ordre_Descendant();
						printf(" Entrez le montant :");
						scanf("%f",&X);
						for(i=0;i<C;i++){
							if(X<P[i].Montant)
           					printf("%s , %s , %s , %.2f \n",P[i].preNom,P[i].Nom,P[i].CIN,P[i].Montant);
						}
						break;
					}
					case 4:{
						float X;
						Ordre_Ascendant();
						printf(" Entrez le montant :");
						scanf("%f",&X);
						for(i=0;i<C;i++){
							if(X>P[i].Montant)
           					printf("%s , %s , %s , %.2f \n",P[i].preNom,P[i].Nom,P[i].CIN,P[i].Montant);
							}
						break;
					}
					case 5:{
						serch(j);
						break;
					}	
				 }
				 }while(i>0);
				 	break;
		  		} 
			}
        }while(i>0);






        return 0;
      }

