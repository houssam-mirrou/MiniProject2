#include <stdlib.h>
#include <stdio.h>
#define MAX 300
#include <string.h>
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define reset "\e[0m"


int col_width=12;

void print_header_footer(){
    int i=0;
    printf("*");
	for(i=0;i<col_width+4;i++){
		printf("*");
	}
	printf("*");
	for(i=0;i<col_width+3;i++){
		printf("*");
	}
	printf("*");
	for(i=0;i<col_width+3;i++){
		printf("*");
	}
    printf("*");
	for(i=0;i<col_width+3;i++){
	    printf("*");
	}
	printf("*\n");
}


typedef struct contact {
    char nom [MAX];
    char numero [MAX];
    char adress [MAX];
} contact ; 

void print_value(contact cont){
    
    printf("** %-*s ** %-*s ** %-*s **\n", col_width, cont.nom,
        col_width, cont.adress,
        col_width, cont.numero);
}

int contact_trouv(contact cont[] ,int n,char nm[]){
    int i=0;
    for(i=0;i<n;i++){
        if(strcmp (cont[i].nom,nm) == 0){
            return 1;
        }
    }
    return 0;
}

void ajouter_contact(contact cont[],int n,contact nouv_cont){
    cont[n++]=nouv_cont;
}

void modifier_contact(contact cont[] , int n , char nm[]){
    int choix=0;
    int trouv=0;
    int idx=-1;
    for(int i=0;i<n;i++){
        if(strcmp(cont[i].nom,nm) == 0){
            idx=i;
            trouv=1;
        }
    }
    if(trouv == 0){
        printf("Le contact n'existe pas .\n");
        printf("Appuyer sur Entrer!!\n"reset);
        getchar();
        getchar();
        system("cls");
        return;
    }
    do{
        printf("Choisir :\n");
        printf("0 . Pour modifier numero.\n");
        printf("1 . Pour modifier adress.\n");
        printf("2 . Pour modifier les deux.\n");
        printf("Donner Votre Choix : ");
        scanf("%d",&choix);
    } while (choix<0 && choix>2);
    switch (choix)
    {
    case 0:
        printf("Donner votre nouveaux numero : ");
        scanf("%s",cont[idx].numero);
        printf("le mise a jour du numero a ete faite en succes.\n");
        break;
    case 1 :
        printf("Donner votre nouveaux adress : ");
        scanf("%s",cont[idx].adress);        
        printf("le mise a jour du l'adress a ete faite en succes.\n");
        break;
    case 2 :
        printf("Donner votre nouveaux numero : ");
        scanf("%s",cont[idx].numero);
        printf("Donner votre nouveaux adress : ");
        scanf("%s",cont[idx].adress);
        printf("le mise a jour du numero et l'adress a ete faite en succes.\n");
        break;
    }
}

void supprimer_contact(contact cont[],int n , char nm[]){
    int i;
    int sup=0;
    for(i =0 ;i<n ;i++){
        if(strcmp(cont[i].nom,nm) == 0){
            int j=i;
            while(j<n-1){
                cont[j] = cont[j+1];
                j++;
            }
            sup=1;
        }
    }
    if(sup==0){
        printf("***************************************************************\n");
        printf("**          le contact n'exist pas dans la list!!            **\n");
        printf("***************************************************************\n");
    }
    else{
        printf("***************************************************************\n");
        printf("**         le contact a ete supprimer en succee.             **\n");
        printf("***************************************************************\n");
    }
}

void afficher_contact(contact cont[],int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%s %s %s\n",cont[i].nom,cont[i].adress,cont[i].numero);
    }
}

void rechercher_contact(contact cont[],int n,char nm[]){
    int i ;
    int t=0;
    for( i =0 ; i < n ; i++ ){
        if(strcmp(cont[i].nom,nm) == 0){
            print_value(cont[i]);
            t=1;
        }
    }
    if(t==0){
        printf("***************************************************************\n");
        printf("**     le contact n'existe pas dans la list de contact !!    **\n");
        printf("***************************************************************\n");
    }
}

void main_2(){
    contact cont[MAX];
    int choix = 0;
    int x=0;
    int n=0;
    int i=0;
    char rech_nom[MAX];
    contact temp;
    while(x == 0){
        do {
            int i = 0;
            for(i=0 ;i < 65 ;i++){
                printf(BLU"*"reset);
            }
            printf("\n");
            printf(BLU"*\t 1. Ajouter un contact .                         \t*\n"reset);
            printf(GRN"*\t 2. Afficher les contacts disponibles.           \t*\n"reset);
            printf(YEL"*\t 3. Rechercher un contact par le nom.            \t*\n"reset);
            printf(MAG"*\t 4. Mettre a jour un contact.                    \t*\n"reset);
            printf(CYN"*\t 5. Supprimer un contact.                        \t*\n"reset);
            printf(RED"*\t 6. Quitter le programme.                        \t*\n");
            printf("*\t                                                 \t*\n");
            for(i=0 ;i < 65 ;i++){
                printf("*");
            }
            printf("\n"reset);
            printf("Donner votre choix : ");
            scanf("%d",&choix);
        } while(choix <1 && choix >6);
        switch(choix){
            case 1 :
                printf(BLU"************************************************************\n");
				printf("**                    Ajouter un contact                    **\n");
				printf("************************************************************\n");
                printf("\t Donner le nom du contact         : ");
				scanf("%s",temp.nom);
				printf("\t Donner le numero du contact      : ");
				scanf("%s",temp.numero);
				printf("\t Donner le adress du contact      : ");
				scanf("%s",temp.adress);
                cont[n]=temp;
                n++;
                printf("************************************************************\n");
				printf("**         Le Contact a ete ajouter avec succee.          **");
				printf("************************************************************\n");
				printf("Appuyer sur entrer ! "reset);
				getchar();
				getchar();
				system("cls");
				break;
            case 2 :
                if(n==0){
					printf(GRN"La list des contacts est vide!\n");
					printf("Appuyer sur entrer ! "reset);
					getchar();
					getchar();
					system("cls");
					break;
				}
                printf(GRN);
             
                print_header_footer();
                for(i=0;i<n;i++){
                     print_value(cont[i]);
                }
                print_header_footer();
                printf("Appuyer sur entrer ! "reset);
				getchar();
				getchar();
				system("cls");
                break;
            case 3 :
                printf(YEL"donner le contact a rechercher : ");
				scanf("%s",rech_nom);
				printf("\n");
                rechercher_contact(cont,n,rech_nom);
                printf("Appuyer sur entrer ! "reset);
				getchar();
				getchar();
				system("cls");
                break;
            case 4 :
                printf(MAG"**************************************************************\n");
				printf("**                 Mise a jour d' un contact                   **\n");
				printf("***************************************************************\n");
                printf("Donner le nom du contact : ");
                scanf("%s",rech_nom);

            case 5 :
                printf(CYN"***************************************************************\n");
				printf("**           Suppression d'un element du tableaux            **\n");
				printf("***************************************************************\n");
                printf("Donner le titre du livre a supprimer : ");
				scanf("%s",rech_nom);
                supprimer_contact(cont,n,rech_nom);
                printf("Appuyer sur entrer ! "reset);
				getchar();
				getchar();
				system("cls");
                break;
        }
    }
}

