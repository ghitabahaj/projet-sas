#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#include <dos.h>
#include<conio.h>
static int i ; 


int nb;

void menu();
void introduire_un_produit();
void introduire_plusieurs_produits();
//typedef struct{
//	int jour ;
//		int anne;
//	char mois[10];
//}date;

typedef struct 
{
    int Code;
	char Nom[20];
	int Quantite;
    float Prix;
    float prixttc;
   // int time;
    char date[50];
    int totalv;
    float total;
    
}produit;
produit pr[100];
int index = 0;
void supprimerProduit();
void Afficher();
void Listerproduitnom();
void Listerproduitprix();
void ListerProduit();
float prixttc(produit p);
void AcheterProduit();
void RechercheProduit(int code);
void Etatdestock();
void Alimenterstock();
int chercher(int code);
void statistique();
void stateall();


int main()
{
    int choix;
    char on;
    int coder , codea , q , codep ,qp , codes;

    do
    {
        system("CLS");
        menu();

        do
        {
            printf("Entrer Votre Choix : ");
            scanf("%d", &choix);

            switch (choix)
            {
            case 1:
            {
                system("CLS");
                printf("\n===============================================\n");
                printf("=====      AJOUTER UN NOUVEAU PRODUIT     =====\n");
                printf("===============================================\n");
                introduire_un_produit();
                Afficher();
                break;
            }

            case 2:
            {
                system("CLS");
                printf("\n===============================================\n");
                printf("====  AJOUTER PLUSIEURS NOUVEAUX PRODUITS  ====\n");
                printf("===============================================\n");
                introduire_plusieurs_produits();
                Afficher();
                break;
            }

            case 3:
            {
                system("CLS");
                printf("\n===============================================\n");
                printf("=====       LISTER TOUS LES PRODUITS      =====\n");
                printf("===============================================\n");
                Listerproduit();
                break;
            }

            case 4:
            {
                system("CLS");
                printf("\n===============================================\n");
                printf("=====            ACHETER PRODUIT          =====\n");
                printf("===============================================\n");
                AcheterProduit();
                break;
            }

            case 5:
            {
                system("CLS");
                printf("\n===============================================\n");
                printf("=====     RECHERCHER LES PRODUITS PAR     =====\n");
                printf("===============================================\n");
                printf("Entrez le code du produit que vous souhaitez rechercher!");
                scanf("%d",&coder);
                RechercheProduit(coder);
                break;
            }

            case 6:
            {
                system("CLS");
                printf("\n===============================================\n");
                printf("=====             ETAT DU STOCK           =====\n");
                printf("===============================================\n");
                printf("   === AFFICHAGE DES PRODUIT DONT LA QUANTITE EST INFERIEUR A 3 ===\n");
                Etatdestock();
                break;
            }

            case 7:
            {
                system("CLS");
                printf("\n===============================================\n");
                printf("=====          ALIMENTER LE STOCK         =====\n");
                printf("===============================================\n");
                Alimenterstock();
                
                break;
            }

            case 8:
            {
                system("CLS");
                printf("\n===============================================\n");
                printf("=====         STATISTIQUE DE VENTE        =====\n");
                printf("===============================================\n");
                //statistique();
                stateall();
                break;
            }
            
            case 9:
            	{
            	system("CLS");
                printf("\n===============================================\n");
                printf("=====         SUPPRIMER UN PRODUIT          =====\n");
                printf("===============================================\n");
                supprimerProduit();
                Afficher();
                break;
            		
				}
			case 10:
			   {
				system("CLS");
                printf("\n===============================================\n");
                printf("=====         AFFICHER LES PRODUITS         =====\n");
                printf("===============================================\n");
                Afficher();
				break;
				}	

            case 11:
            {
                system("CLS");
                break;
            }

            default:
            {
                system("CLS");
                menu();
                printf("SVP Entrer Votre Choix ( 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 ,10 , 11)\n");
                break;
            }
            } // fin switch

        } while (choix < 1 || choix > 11);

        printf("\n===============================================\n");
        printf("======   VOULEZ-VOUS CONTINUER : O/N ?   ======\n");
        printf("===============================================\n");
        scanf("%S", &on);

    } while (on == 'o' || on == 'O');
    system("CLS");
    printf("\n===============================================\n");
    printf("======     APPLICATION EST FERMER    ======\n");
    printf("===============================================\n");

    // system("PAUSE");
    return 0;
}

void menu()
{
    printf("\n===============================================\n");
    printf("======    LE MENU PRINCIPAL PERMET DE    ======\n");
    printf("===============================================\n");
    printf("== 1: AJOUTER UN NOUVEAU PRODUIT             ==\n");
    printf("== 2: AJOUTER PLUSIEURS NOUVEAUX PRODUITS    ==\n");
    printf("== 3: LISTER TOUS LES PRODUITS               ==\n");
    printf("== 4: ACHETER PRODUIT                        ==\n");
    printf("== 5: RECHERCHER LES PRODUITS PAR            ==\n");
    printf("== 6: ETAT DU STOCK                          ==\n");
    printf("== 7: ALIMENTER LE STOCK                     ==\n");
    printf("== 8: STATISTIQUE DE VENTE                   ==\n");
    printf("== 9: SUPPRIMER UN PRODUIT                   ==\n");
    printf("== 10: AFFICHER LES PRODUITS                  ==\n");
    printf("== 11: QUITTER LAPPLICATION                   ==\n");
    printf("===============================================\n\n");
} // fin fonctions

void introduire_un_produit()
{
     produit p;
    here:
    printf("\nEntrer Votre Code : ");
    scanf("%d", &p.Code);
    	
     int y = chercher(p.Code);
        if(y==1){
        	    printf("Ce produit deja existe !\n ");
             	goto here;
				}
    printf("\nEntrer Votre Nom : ");
    scanf("%s", p.Nom);

    printf("\nEntrer Votre Quantité : ");
    scanf("%d", &p.Quantite);

    printf("\nEntrer Votre Prix : ");
    scanf("%f", &p.Prix);
    
    printf("\nPRODUIT DE CODE %d EST CREER\n", p.Code);

    p.prixttc= p.Prix + (0.15 * p.Prix);
    
    p.totalv=0;
    
    p.total= 0;
    
    pr[index++] = p;

} // fin fonctions

void introduire_plusieurs_produits()
{
    printf("\nCOMBIEN DE PRODUITS VOULEZ-VOUS CREER ?\t");
    scanf("%d", &nb);
int j =0;
    for ( j = 1; j <= nb; j++)
    {
         produit p;

        printf("\n===============================================\n");
        printf("======      CREATION DE COMPTE N %d      ======\n", j);
        printf("===============================================\n");

        printf("\nEntrer Votre Code : ");
        scanf("%d", &p.Code);

        printf("\nEntrer Votre Nom : ");
        scanf("%s", p.Nom);

        printf("\nEntrer Votre Quantité : ");
        scanf("%d", &p.Quantite);

        printf("\nEntrer Votre Prix : ");
        scanf("%f", &p.Prix);

        printf("\nPRODUIT DE CODE %d EST CREER\n", p.Code);
        
         p.prixttc= p.Prix + (p.Prix * 0.15);
    
         p.totalv=0;
    
         p.total=0;

        pr[index++] = p;

    } // fin condition for

} 

void Afficher(){
	system("cls");
	int k=0;
	for (i=0;i<index;i++){
		printf("====   LES INFORMATIONS DU PRODUIT NUMERO %d.  ====\n",i+1);
		printf("le code du produit : %d \n",pr[i].Code);
		printf("le nom du produit est :%s\n",pr[i].Nom);
		printf("le prix du produits est %.3f\n",pr[i].Prix);
		printf("la quantite du produit dans le stock est %d\n",pr[i].Quantite);
		pr[i].prixttc = prixttc(pr[i]);
		printf("le prix ttc de ce produit est %.3f\n",pr[i].prixttc);	
		k++;	
	}
	if(k==0){
		printf("IL N EXISTE AUCUN PRODUIT");
	}
}

float prixttc(produit p){
	float prixttc=0;
    prixttc =	p.Prix + (0.15*p.Prix);
    return prixttc;
}



void Listerproduitnom(){
int ech;
produit tmp;
	do {
		ech =0;
		for(i=0;i<index-1;i++){
			if(strcmp(pr[i].Nom,pr[i+1].Nom)>0){
				tmp=pr[i];
				pr[i]=pr[i+1];
				pr[i+1]=tmp;
				ech++;
			}
			
		}
		
		
	}while(ech>0);
}

void Listerproduitprix(){

    int ech;
    produit tmp;
    do {
		ech =0;
		for(i=0;i<index-1;i++){
		       if(pr[i].Prix<pr[i+1].Prix){
		       	     tmp=pr[i];
		       	     pr[i]=pr[i+1];
		       	     pr[i+1]=tmp;
		       	     ech++;
			   }
			}
	
	}while(ech>0);
	
}

void Listerproduit(){
	
	int c=0;
	
	printf("---Est ce que vous voulez lister les produits par nom ou par prix!---\n");
	printf("SI PAR NOM VEUILLEZ ENTRER 1 \n");
	printf("SINON SI PAR PRIX VEUILLEZ ENTRER 2:");
	scanf("%d",&c);
	switch(c){
		case 1:
			{
				Listerproduitnom();
				Afficher();
				break;
			}
			
		case 2:
	     	{
			    Listerproduitprix();
			    Afficher();
			}	
		default:
		     break;	
	}
}

void AcheterProduit(){
	int j=1  , codea , q;
	

	here:
	 printf("VEUILLEZ ENTRER LE CODE DU PRODUIT A ACHETER:");
     scanf("%d",&codea);
     int y = chercher(codea);
        if(y==0){
        	goto here;
				}
		
     printf("VEUILLEZ ENTRER LA QUANTITE DU PRODUIT A ACHETER:");
     scanf("%d",&q);
	for(i=0;i<index;i++){
		if(pr[i].Code == codea ){
			pr[i].Quantite = (pr[i].Quantite)-q; 	
             time_t t = time(NULL);
         	printf("le produit est  achete le %s \n" , ctime(&t) );
	       printf("la quantite du produit apres l achat est :%d \n",pr[i].Quantite);
	       pr[i].totalv++;
	       pr[i].total = pr[i].prixttc*pr[i].totalv;
	       strcpy(pr[i].date, ctime(&t));
	       printf("     Code de produit  |    Prix ttc      |  Total Vendus    |     Total     |    Date d'achat \n ");
	       printf("         %d           |     %.3f  DH     |     %d           |    %.2f DH    |       %s  ", pr[i].Code,pr[i].prixttc,pr[i].totalv,pr[i].total,pr[i].date);
	       
	       
	    
	       
	       
			 j=2;
		}
	}
	if(j==1){
		printf("CE PRODUIT N EXISTE PAS !!!");
	}

}


void RechercheProduit(int code  ){
	int j=1;
	       for(i=0;i<index;i++){
		        if(pr[i].Code==code){
		        	printf("les informations du produit  Numero %d.\n",i+1);
	              	printf("le code du produit : %d \n",pr[i].Code);
	             	printf("le nom du produit est :%s",pr[i].Nom);
	            	printf("le prix du produits est %.3f\n",pr[i].Prix);
	             	printf("la quantite du produit dans le stock est %d\n",pr[i].Quantite);  
					 j=2; 
				}
		   }
	if(j==2){
		printf("CE PRODUIT N EXISTE PAS !!!");
	}	    
		 
}


void Etatdestock(){
	int k=0;
	for(i=0;i<index;i++){
		if(pr[i].Quantite<3){
			     	printf("les informations du produit  Numero %d.\n",i+1);
	              	printf("le code du produit : %d \n",pr[i].Code);
	             	printf("le nom du produit est :%s \n",pr[i].Nom);
	            	printf("le prix du produits est %.3f DH \n",pr[i].Prix);
	             	printf("la quantite du produit dans le stock est %d DH\n",pr[i].Quantite);
	             	k++;
		}
	}
	
	if(k==0){
		printf("IL N EXISTE AUCUN PRODUIT DONT LA QUANTITE EST INFERIEURE A 3.\n");
	}
	
}


void Alimenterstock(){
	int codep , qp ;
	here:
	  printf("VEUILLEZ ENTRER LE CODE DU PRODUIT POUR LE METTRE A JOUR :");
      scanf("%d",&codep);
       int y = chercher(codep);
        if(y==0){
             	goto here;
				}
      printf("VEUILLEZ ENTRER LA QUANTITE DU PRODUIT POUR LE METTRE A JOUR :");
	  scanf("%d",&qp);
	  printf("\n");
      
      
	for(i=0;i<index;i++){
		if(pr[i].Code == codep){
		printf("LA QUANTITE AVANT LA METTRE A JOUR : %d",pr[i].Quantite);
			pr[i].Quantite+=qp;
		printf("LA QUANTITE APRES LA METTRE A JOUR : %d",pr[i].Quantite);
		}
	}
}

void supprimerProduit(){
	int codes , j;
	    here:
        printf("ENTREZ LE CODE DU PRODUIT QUE VOUS VOULEZ SUPPRIMER:");
        scanf("%d",&codes);
        int y = chercher(codes);
        if(y==0){
        	printf("CE CODE N EXISTE PAS VEUILLEZ ENTRER UN CODE QUI EXISTE \n");
             	goto here;
				}
	
              for(i=0;i<index;i++){
                       if(pr[i].Code==codes){
                           for(j=i;j<index-1;j++)
                              pr[j]=pr[j+1];
                                  index--;
                                  //  i--;
                                     }
                      }
	 

	 
	
}
int chercher(int code){
	int j=1;
	for(i=0;i<index;i++){
		if(pr[i].Code==code){
			j=2;
			return 1;
		}
	}
	
	if(j==1){
		return 0;
	}
}


void statistique(){
			
	for(i=0;i<index;i++)
      {
      	if(pr[i].totalv!=0){
		  
	
	printf("\t      Code de produit |    Prix ttc      |  Total Vendus       |     Total           |    Date d'achat \n ");
    printf("\t         %d           |     %.3f  DH     |     %d           |    %.2f DH    |       %s  ", pr[i].Code,pr[i].prixttc,pr[i].totalv,pr[i].total,pr[i].date);
			}			
		}
}

void stateall(){
	
	for(i=0;i<index;i++){
		if(difftime(pr[i].date, pr[i+1].date)<86400 && pr[i].totalv!=0){
	printf("\t      Code de produit |    Prix ttc      |  Total Vendus    |     Total     |       Date d'achat \n ");
    printf("\t         %d           |     %.3f  DH     |     %d           |    %.2f DH    |       %s  ", pr[i].Code,pr[i].prixttc,pr[i].totalv,pr[i].total,pr[i].date);
			}
			
		}
		
	}















