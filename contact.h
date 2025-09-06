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
#include <ctype.h>

int is_num(char c){
    if(c>='0' && c<='9'){
        return 1;
    }
    return 0;
}

int verif_numero(char numero[]){
    int i=0;
    if(strlen(numero) != 10){
        return 0;
    }
    if(numero[0]!='0' || (numero[1]!='6' && numero[1]!='7')){
        return 0;
    }
    for(i=0;i<10;i++){
        if(is_num(numero[i])!= 1){
            return 0;
        }
    }
    return 1;
}

int verif_adress(char adress[]){
    char d[10][30] = {
        "@gmail.com",
        "@hotmail.com",
        "@hotmail.fr",
        "@live.com",
        "@yahoo.com",
        "@outlook.fr",
        "@outlook.com"
    };
    int i=0;
    int j=0;
    int n = strlen(adress);
    int same = 0;
    for(i = 0;i<5;i++){
        int m = strlen(d[i]);
        int k = n-m;
        if(k<0){
            continue;
        }
        same = 1;
        for(j=0;j<m;j++){
            if(adress[k] != d[i][j]){
                same = 0;
                break;
            }
            k++;
        }
        if(same == 1){
            return 1;
        }
    }
    return 0;
}

//contact structures

typedef struct contact {
    char nom [MAX];
    char adress [MAX];
    char numero [MAX];
} contact ; 

int col_width = 20 ;

//print header **

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
	printf("*\n");
}


//print the value of the contact

void print_value(contact cont){
    printf("** %-*s ** %-*s ** %-*s **\n", col_width, cont.nom,
        col_width, cont.adress,
        col_width, cont.numero);
}

void print_value_with_header_and_footer(contact cont){
    print_header_footer();
    printf("** %-*s ** %-*s ** %-*s **\n", col_width, cont.nom,
        col_width, cont.adress,
        col_width, cont.numero);
    print_header_footer();
}

//print a title

void print_title(char title[] ){
    int total_width = (col_width * 3)+10;
    int title_len = strlen(title);

    if (title_len >= total_width) {
        printf("%s\n", title);
        return;
    }

    int pad_width = total_width - title_len;
    int left_padding = pad_width / 2;
    int right_padding = pad_width - left_padding;

    print_header_footer();
    printf("**%*s%s%*s**\n", left_padding, "", title, right_padding, "");

    print_header_footer();
}


void print_title2 (char title[],char color[]) {
    int menu_width = (col_width * 3);
    printf(color);
    printf("*");
    printf("\t");
    printf("%-*s", menu_width-2-1, title); 
    
    printf("\t");
    printf(" *\n");
}

//returns the index if the contact exist

int recherche_idx(contact cont[] ,int n,char nm[]){
    int i=0;
    for(i=0;i<n;i++){
        if(strcmp (cont[i].nom,nm) == 0){
            return i;
        }
    }
    return -1;
}

//adds a contact

int ajouter_contact(contact cont[],int n){
    char nm[30];
    printf("Donner le nom du contact         : ");
	scanf("%s",nm);
    int d = recherche_idx(cont,n,nm);
    if (d!=-1){
        print_title("Le contact est deja ajouter dans le list tu peut le modifier !!");
        return n;
    }
    strcpy(cont[n].nom,nm);
    do {
        printf("Donner le numero du contact      : ");
        scanf("%s",cont[n].numero);
        printf("Donner le adress du contact      : ");
        scanf("%s",cont[n].adress);
    } while(verif_adress(cont[n].adress) == 0 || verif_numero(cont[n].numero) == 0);
    n++;
    print_title("Le Contact a ete ajouter avec succee.");
    return n;
}

//modify a contact

void modifier_contact(contact cont[] , int n , char nm[]){
    int choix=0;
    int trouv=0;
    int idx=-1;
    idx = recherche_idx(cont,n,nm);
    if(idx==-1){
        print_title("Le contact n exist pas .");
    }
    else {
        system("cls");
        print_header_footer();
        print_title2("Choisir :",MAG);
        print_title2("1 . Pour modifier numero.",BLU);
        print_title2("2 . Pour modifier adress.",GRN);
        print_title2("3 . Pour modifier les deux.",CYN);
        print_header_footer();
        printf("Donner Votre Choix : ");
        do{
            scanf("%d",&choix);
        } while (choix<1 && choix>3);
        print_title("le contact avant la modification : ");
        printf("Le contact : \n");
        contact temp = {"Nom","Adress","Numero"};
        print_value_with_header_and_footer(temp);
        print_value(cont[idx]);
        print_header_footer();
        printf(reset);
        switch (choix) {
            case 1:
                printf(BLU);
                do {
                    printf("\t Donner votre nouveaux numero : ");
                    scanf("%s",cont[idx].numero);
                } while(verif_numero(cont[idx].numero)==0);
                break;
            case 2 :
                printf(GRN);
                do {
                    printf("\t Donner votre nouveaux adress : ");
                    scanf("%s",cont[idx].adress);
                } while(verif_numero(cont[idx].adress)==0);
                break;
            case 3 :
                printf(CYN);
                do{
                    printf("\t Donner votre nouveaux numero : ");
                    scanf("%s",cont[idx].numero);
                    printf("\t Donner votre nouveaux adress : ");
                    scanf("%s",cont[idx].adress);
                } while(verif_adress(cont[n].adress) == 0 || verif_numero(cont[n].numero) == 0);
                break;
        }
        print_title("le contact apres la modification :");
        printf("La Contact : \n");
        print_value_with_header_and_footer(temp);
        print_value(cont[idx]);
        print_header_footer();
    }
}

//affichage de toutes les contact

void afficher_contacts(contact cont[] ,int n){
    if(n == 0){
        print_title("La list des contact est vide !!");
        return;
    }
    contact temp = {"Nom","Adress","Numero"};
    print_value_with_header_and_footer(temp);
    int i ;
    for(i=0;i<n;i++){
        print_value(cont[i]);
    }
    print_header_footer();
}

// supprimer contact

int supprimer_contact(contact cont[],int n , char nm[]) {
    int i;
    int idx=-1;
    idx=recherche_idx(cont,n,nm);
    char c;
    if(idx == -1){
        print_title("Le contact n'existe pas !!");
    }
    else {
        printf("\t Vous etes sure tu veux le supprimer (O/N) : ");
        do{
            scanf("%c",&c);
            c = toupper(c);
        } while(c!='O' && c!='N');
        switch(c){
            case 'O' :
                while(( idx = recherche_idx(cont,n,nm) )!=-1){
                    for(i = idx ; i<n-1 ; i++){
                        cont[i] = cont[i+1];
                    }
                    n--;
                }
            case 'N' :
                print_title("Vouz avez choisir de ne pas supprimer le contact .");
        }
    }
    if(c == 'O'){
        print_title("La list des contact apres la suppression.");
        printf("\n");
        afficher_contacts(cont,n);
    }
    return n;
}

void rechercher_contact(contact cont[],int n,char nm[]){
    int i ;
    int idx = recherche_idx(cont,n,nm);
    if(idx != -1){
        contact temp = {"Nom","Adress","Numero"};
        print_value_with_header_and_footer(temp);
        print_value(cont[idx]);
        print_header_footer();
    }
    else {
        print_title("Le contact n'existe pas dans la list !!");
    }
}

void main_2() {
    contact cont[MAX];
    int n=0;
    int x=0;
    int i=0;
    char nm[30];
    int choix=-1;
    contact temp;
    while(x == 0){
        int i = 0;
        printf(BLU);
        print_header_footer();
        print_title2(" 1. Ajouter un contact ." ,BLU);
        print_title2(" 2. Afficher les contacts disponibles." ,GRN);
        print_title2(" 3. Rechercher un contact par le nom." ,YEL);
        print_title2(" 4. Mettre a jour un contact." ,MAG);
        print_title2(" 5. Supprimer un contact." ,CYN);
        print_title2(" 6. Quitter le programme." ,RED);
        print_header_footer();
        printf("\n"reset);
        do {
            printf("Donner votre choix : ");
            scanf("%d",&choix);
        } while(choix <1 && choix >6);
        switch(choix) {
            case 1 :
                printf(BLU);
                print_title("Ajouter un contact");
                n=ajouter_contact(cont,n);
                break;
            case 2 :
                if(n==0){
                    printf(GRN);
                    print_title("La list des contacts est vide!");
                    break;
                }
                printf(GRN);
                afficher_contacts(cont,n);
                break;
            case 3 :
                printf(YEL);
                printf("donner le contact a rechercher : ");
				scanf("%s",nm);
				printf("\n");
                rechercher_contact(cont,n,nm);
                break;
            case 4 :
                printf(MAG);
                print_title("Mise a jour d' un contact");
                printf("Donner le nom du contact : ");
                scanf("%s",nm);
                modifier_contact(cont,n,nm);
                break;
            case 5 :
                printf(CYN);
                print_title("Suppression d'un element du tableaux");
                printf("Donner le titre du livre a supprimer : ");
				scanf("%s",nm);
                n=supprimer_contact(cont,n,nm);
                break;
            case 6 :
                return;
        }
        printf("Appuyer sur entrer ! "reset);
		getchar();
		getchar();
		system("cls");
    }
}




