//Applications de quelques fonctions d'ajout et de suppression sur une liste simplement chain�e

#include<stdio.h>
#include<stdlib.h>

// D�finition de la structure de la bo�te
struct BOX{
    int data;            // Donn�e stock�e dans la bo�te
    struct BOX* next;    // Pointeur vers la prochaine bo�te
};
typedef struct BOX BOX;  // Alias pour la structure BOX

// Fonction pour ajouter un �l�ment au d�but de la liste
BOX* AjouterAuDebut (BOX* debut , int element){
    BOX* b; // D�claration d'un pointeur de bo�te
    
    b=(BOX*)malloc(sizeof(BOX)); // Allocation de m�moire pour une nouvelle bo�te
    
    if (b==NULL){ // V�rification de l'allocation r�ussie
        printf("erreur de l'allocation");
        exit (-1); // Quitter le programme avec un code d'erreur
    }
    
    b->data = element; // Assigner la valeur � la bo�te cr��e
    
    if (debut->next == NULL){ // V�rifier si la liste est vide
        b->next = NULL; // Si oui, la prochaine bo�te pointe vers NULL
    }
    
    b->next= debut; // La nouvelle bo�te pointe vers l'ancien d�but de liste
    return b; // Retourner la nouvelle bo�te qui est maintenant le d�but de la liste
}

// Fonction pour ajouter des �l�ments au milieu de la liste 
BOX* AjouterAuMilieu (BOX* p,BOX* p1 , int element){
	BOX* b; // D�claration d'un pointeur de bo�te
    
    b=(BOX*)malloc(sizeof(BOX)); // Allocation de m�moire pour une nouvelle bo�te
    
    if (b==NULL){ // V�rification de l'allocation r�ussie
        printf("erreur de l'allocation");
        exit (-1); // Quitter le programme avec un code d'erreur
    }
    
    b->data = element; // Assigner la valeur � la bo�te cr��e
    
    p->next=b;
    b->next=p1;
    p1=NULL; //supprimer l'ancienne liaison 
    
    return b;	
}

// Fonction pour ajouter des �l�ments a la fin de la liste 
BOX* AjouterQueue(BOX* p1, int element){
	
	BOX* b; // D�claration d'un pointeur de bo�te
    
    b=(BOX*)malloc(sizeof(BOX)); // Allocation de m�moire pour une nouvelle bo�te
    
    if (b==NULL){ // V�rification de l'allocation r�ussie
        printf("erreur de l'allocation");
        exit (-1); // Quitter le programme avec un code d'erreur
    }
    
    b->data = element; // Assigner la valeur � la bo�te cr��e
    
    p1->next=b;
    b->next=NULL;
    return b;
}


// Fonction pour supprimer un �l�ment au d�but de la liste
BOX* SupprimerTeteListe (BOX* p){
	BOX* p1= p->next; 
	free(p);
	p=NULL;
	return p1;
}

// Fonction pour supprimer un �l�ment a la fin de la liste
BOX* SupprimerQueueListe(BOX* p){
	BOX* p1 = NULL;
	while (p->next != NULL){
		p1 =p; //l'adresse de l'avant dernier element 
		p=p->next; //l'adresse du dernier element
	}
	free(p);
	p=NULL;
	p1->next=NULL;
	return p1;
}

// Fonction pour supprimer un �l�ment au milieu de la liste
BOX* SupprimerAuMilieu (BOX* p,BOX* p1){
	BOX* p3=NULL;
	p3=p1;
	p->next=p1->next;
	p3->next=NULL;
	free(p3);
	p3=NULL;
	return p->next;
}
 
// Fonction pour afficher les �l�ments de la liste
void afficheListe(BOX* debut){
    if (debut == NULL){
        printf("la liste est vide\n");
        return; //quitter la fonction
    }
    
    while(debut != NULL){
        printf("%d --> ", debut->data);
        debut = debut->next;
    }
    printf("NULL\n");
}



int main(){
	BOX* p=NULL; // Initialisation du pointeur de d�but de liste � NULL
	
	//remplissage du premier element 
	p=(BOX*)malloc(sizeof(BOX)); // Allocation de m�moire pour chaque boite 
	if (p==NULL){ // V�rification de l'allocation r�ussie
	    printf("erreur de l'allocation");
	    return 1; // Quitter le programme avec un code d'erreur
	}
	printf("donner les donnees de la boite 1 : ");
	scanf("%d",&p->data);
	p->next = NULL; // Initialisation du champ 'next' � NULL
	
	//remplissage du reste de la liste chainee 
	BOX* p1 = p; // Utilisation de p1 pour garder une r�f�rence � la t�te de la liste
	for (int i=0; i<3 ; i++){
		p1->next=(BOX*)malloc(sizeof(BOX)); // Allocation de m�moire pour chaque boite 
	    if (p1->next==NULL){ // V�rification de l'allocation r�ussie
	        printf("erreur de l'allocation");
	        return 1; // Quitter le programme avec un code d'erreur
    	}
    	p1=p1->next; //avancer p1
		printf("donner les donnees de la boite %d : ",i+2);
		scanf("%d",&p1->data);
		p1->next = NULL; // Initialisation du champ 'next' � NULL pour la derni�re bo�te	
	}
	
	//ajout d'un �l�ment � la t�te de la liste
	int d1; //data
	printf("donner les donnees a ajouter a la tete de la liste : ");
	scanf("%d",&d1);
	p=AjouterAuDebut(p,d1);
	
	//ajout d'un �l�ment au milieu de la liste
	int d2; //data
	printf("donner les donnees a ajouter au milieu de la liste : ");
	scanf("%d",&d2);
	p1=p->next;
	BOX* p2= AjouterAuMilieu (p,p1,d2);
	
	//ajout d'un �l�ment � la fin de la liste 
	int d3; //data
	printf("donner les donnees a ajouter a la fin de la liste : ");
	scanf("%d",&d3);
	p1=p; //initialisation de p1
	while(p1->next != NULL){
		p1=p1->next;
	}
	p1= AjouterQueue(p1,d3);
	
	//affichage de la liste avant la supression
	printf("La chaine avant la suppression\n");
	afficheListe(p);
	
	//supprimer un �l�ment au d�but de la liste
	p=SupprimerTeteListe(p);
	
	//affichage de la liste apres la supression
	printf("La chaine apres la suppression au debut : \n");
	afficheListe(p);
	
	//supprimer un �l�ment a la fin de la liste
	p1=SupprimerQueueListe(p);
	
	//affichage de la liste apres la supression
	printf("La chaine apres la suppression a la fin \n");
	afficheListe(p);
	
	//supprimer un �l�ment au milieu
	p1=p; // initialiser p1
	p2=NULL; 
	p1=p->next;
	p2= SupprimerAuMilieu (p,p1); //suppression de p1
	
	//affichage de la liste apres la supression
	printf("La chaine apres la suppression au milieu \n");
	afficheListe(p);
	
	
	//lib�ration de la m�moire
	while (p->next != NULL){
		p=SupprimerTeteListe(p);	
	}
	free(p);
	p=NULL; 
	
	//affichage de la liste apres liberation 
	printf("La chaine apres la liberation : \n");
	afficheListe(p);
	
	return 0;
}
