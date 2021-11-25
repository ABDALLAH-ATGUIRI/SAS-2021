         #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>

    typedef struct
	{
        char preNom[10];
        char Nom[10];
        char CIN [10];
        float Montant;
      }compet;

    int C=0;
    compet P[50];

    void Le_menu()
	{
          printf("typer le Nom et le Prenome : ");
          scanf("%s",P[C].preNom);
          scanf("%s",P[C].Nom);
          printf("typer le CIN: ");
          scanf("%s",P[C].CIN);
          printf("typer le Montant :");
          scanf("%f",&P[C].Montant);
	}
	void Ordre_Ascendant()
	{
			compet T;
			int n,i,ech;
			n=C;
			do{
				ech=0;
				for(i=0;i<n-1;i++){
					if(P[i].Montant>P[i+1].Montant){
						T=P[i];
						P[i]=P[i+1];
						P[i+1]=T;
						ech++;
					}
				}
			}while(ech>0);
	}
	int serch( int j)
	{
		char CIN[10];
		
			CIN:
		printf(" le CIN de compt : ");
		scanf("%s",&CIN);

		for(j=0;j<C;j++)
		{
			if ( strcmp(P[j].CIN, CIN) == 0 ){
				printf("\n\t************************************************************************\n");
				printf(" Prenom : %s \n Nom : %s \n CIN : %s\n Montant : %.2f \n",P[j].preNom,P[j].Nom,P[j].CIN,P[j].Montant);
				printf("\n\t************************************************************************\n");
				return j ;
				}
			
			else if(j==C-1){
				printf("\t Ce compte n'est pas dans la liste \n");
				goto CIN ;
			}	
		}
	}

int main(){

float R,X ;
int i,n,j;

do{
	HERE:
		system("cls");
		printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf(" 1==> Pour entrer un compte \n 2==> Pour entrer plusieurs comptes \n 3==> Operation");
		printf("\n 4==> Affichage \n 5==> Fidelisation \n 6==> Quitter l'application \n");
		printf("---------------------------------------------------------------------------------------------------------------------\n ==> ");
        scanf("%d",&i);
        if(i>6||i<=0)goto HERE;
    switch(i){
            case 1:
			{
                n = 1;
                  printf("**************************************************************************************************\n");

                  printf("Compte bancaire NB %d :\n",C+1);
                  Le_menu();
                   C++;

                  printf("**************************************************************************************************\n");

              break;
            }
            case 2:
			{

              printf("Saisissez le nombre de comptes que vous souhaitez saisir : ");
              scanf("%d",&n);

              n += C;
              printf("**************************************************************************************************\n");
              for(i=C;i<n;i++)
                {
              printf("Compte bancaire NB %d :\n",i+1);
              Le_menu();
              C++;

              printf("**************************************************************************************************\n");
              }break;
            }
            case 3:
			{
            	do{
            		
            	system("cls");
                  
            	  for(i=0;i<C;i++)
				  {
            	  	printf("**************************************************************************************************\n");
           			printf("\tLe prenom :%s \n \tle nom : %s \n\t Le CIN : %s  \n",P[i].preNom,P[i].Nom,P[i].CIN);
                  }
					printf("--------------------------------------------------------------------------------------------------\n");
		            printf("\t1==>Retrait \n \t2==>Depot \n \t3==> Retour \n ==>");
		            scanf("%d",&i);
		        switch(i)
				{
		            case 1:{
		            		i=serch(j);
		            		do{
							
		              		printf(" Entrez le montant que vous souhaitez retirer : \n\n ==> ");
		              		scanf("%f",&R);
		              		if(R>P[i].Montant)printf(" \t\tcompte non soldable ");
		              		
		              		}while(R>P[i].Montant);
		              		
		              		P[i].Montant -= R ;
		              		printf("\t Nouveau montant = %.2f \n",P[i].Montant);
		              		goto HERE;
                        break;
                          }
                    case 2:{
                    		i=serch(j);
                      		printf(" Entrez le montant que vous souhaitez deposer : \n\n ==> ");
                      		scanf("%f",&R);
                     		P[i].Montant += R ;
                      		printf("\t Nouveau montant = %.2f \n",P[i].Montant);
                      		goto HERE;
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
         	case 4:
			 {
         		
         		system("cls");    		
			 	do{  
				 	printf("------------------------------------------------------------------------------------------------------\n");      
         			printf(" 1==> Par Ordre Ascendant \n 2==> Par Ordre Descendant \n" );
            		printf(" 3==> les comptes bancaires ayant un montant superieur a un chiffre introduit \n" );
            		printf(" 4==> les comptes bancaires ayant un montant superieur a un chiffre introduit \n 5==> Recherche par CIN \n 6==> Retour \n ");
            		printf("------------------------------------------------------------------------------------------------------\n ==> "); 
           			scanf("%d",&i);
         		switch(i){
         			case 1:{

         					Ordre_Ascendant();

							for(i=0;i<C;i++)
           					printf("%s , %s , %s , %.2f \n",P[i].preNom,P[i].Nom,P[i].CIN,P[i].Montant);

                    break;
                      }
    				case 2:{
							Ordre_Ascendant();
							for(i=C-1;i>=0;i--)
           					printf("%s , %s , %s , %.2f \n",P[i].preNom,P[i].Nom,P[i].CIN,P[i].Montant);
           					i=1;
                    break;
                    }
            		case 3:{

                  Ordre_Ascendant();
                 printf(" \t ==>Entrez le montant : ");
                    scanf("%f",&X);
                  for(i=0;i<C;i++){
                  if(X<P[i].Montant)
           					printf("%s , %s , %s , %.2f \n",P[i].preNom,P[i].Nom,P[i].CIN,P[i].Montant);
                          }
                          break;
                    }
                	case 4:{
                    Ordre_Ascendant();
                    printf(" \t ==>Entrez le montant : ");
                    scanf("%f",&X);
                    for(i=C-1;i>=0;i--){
                      if(X>P[i].Montant)
           					printf("%s , %s , %s , %.2f \n",P[i].preNom,P[i].Nom,P[i].CIN,P[i].Montant);
                        }
                        i=1;
						break;
                          }
                	case 5:{
              			serch(j);
               		 break;
                 			 }
            		case 6:{
                	goto HERE;
					break;
				}
                }
            }while(i>0);
                break;
              }
            case 5:
			{
				Ordre_Ascendant();
				
//            	for(i=C-3;i>=0,i<C;i++)
				i=C-3;
				if(i>>0)i=0;
				while(i<C && i>=0){
				
            		P[i].Montant+=(P[i].Montant*0.013);
            		printf("\n\t************************************************************************\n");
					printf(" Prenom : %s \n Nom : %s \n CIN : %s Montant : %.2f \n",P[i].preNom,P[i].Nom,P[i].CIN,P[i].Montant);
					printf("\n\t************************************************************************\n");
            		i++;
				}	
				system ("pause");
				goto HERE;
				break;
			} 
			case 6:
			{
					exit(0);	
				break;
			}
		}
            }while(i>0);         
        return 0;
      }
