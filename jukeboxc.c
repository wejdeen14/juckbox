#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#include<locale.h>
#define max_chanson 30
#define max_album 10
//declaration d'enrgistrement  chanson 
typedef struct chanson_t chanson_t ;
 struct chanson_t
{
char titre[63];	
int duree_sec;
};
chanson_t c;
chanson_t liste[max_chanson];
//declaration d'enregistrement d'album 
typedef struct album_t album_t ;
 struct album_t
{
char titre [63];
char artiste [63];
int annee ;
int nb_chanson;
chanson_t liste[max_chanson] ;
};
album_t a[max_album];
//declaration d'enregistrement du jukebox 
typedef struct jukebox_t jukebox_t ;
struct jukebox_t
{
    album_t catalogue[max_album];
	int nb_album;
	char proprietaire[63];
} ;
jukebox_t j[max_album];
// procedure saisie chanson 
 void saisie_chanson (chanson_t* c)
 {
 	printf(" saisie la titre de la chanson  :\n");
	scanf("%s",&c->titre);
	printf("-saisie la durée en seconde:\n ");
 	scanf("%d",&c->duree_sec);
 }
//procedure affi_chanson 
void affi_chanson(chanson_t c)
{
	printf(" la chanson est : %s et  la durée est: %d ",c.titre,c.duree_sec);
}
//procedure saisie album 
void saisie_album(album_t * a)
{
int j,k,i;
chanson_t tmp;
printf("*-*-*-*-*-*saisire l'albums*-*-*-*-*-*\n");
printf("\n saisir le titre d'album ':\n");
scanf("%s",&a->titre);
printf("saisir l'artiste d'album':\n");
scanf("%s",&a->artiste);
printf("saisir l'année d'album':\n");
scanf("%d",&a->annee);
printf("saisir nb de chanson d'albums':\n");
scanf("%d",&a->nb_chanson);
printf("saisie la liste :\n");
 for(i=0;i<a->nb_chanson;i++)
	{
		printf("donner le %i chanson \n",i+1);
	saisie_chanson(&a->liste[i]);
    }
    
for (i=1 ; i <a->nb_chanson-1; i++)
 {
    j = i;
    while (j > 0 && a->liste[j-1].titre > a->liste[j].titre)
    {
      tmp = a->liste[j];      
      a->liste[j] = a->liste[j-1];
      a->liste[j-1] = tmp;
      j--;
    }
}
}

//procedure affiche album 
void affi_album(album_t a)
{
int i;
printf("e titre : %s \n l'artiste :%s \n l'année: %d",a.titre,a.artiste,a.annee);
printf("\n");
for(i=0;i<a.nb_chanson;i++)
{
printf("le contenu de %d liste:",i+1);
affi_chanson(a.liste[i]);
printf("\n");
}
}
//fonction rech_chanson 
/*int rech_chanson(album_t a, char ttr )
{    
int i,dure ;
int inf,sup ,m ;
sup=a.nb_chanson;
inf=1;
dure=-1;
while((inf<=sup)&&(dure==-1))
{
	m=(inf+sup)/2;
	if (a.liste->titre[m]==ttr)
	{
		dure=m;
	}
	else 
	{
		if(a.liste->titre[m]<ttr)
		{
			inf=m+1;
		}
		else
		{
			sup=m-1;
		}	
}
return dure
}*/

int rech_chanson(album_t a, char* titre )
{     int i;
int dure;
dure=-1;
	for(i=0;i<a.nb_chanson;i++)
	{
		if( strcmp(a.liste[i].titre,titre)==0)
			dure= a.liste[i].duree_sec;
	}
	return dure;
}
//duree totale 
int duree_totale(album_t a)
{
	int i ,somme;
	somme=0;
	for(i=0;i<a.nb_chanson;i++)
	{
		somme=somme+a.liste[i].duree_sec;
	}
	return somme;
}
//saisie jukbox 
void saisie_jukebox(jukebox_t*j)
{
	int i;
	printf("*-*-*-*-*-*saisie jukebox*-*-*-*-*-*\n");
	printf("saisie les nombre d'albums  \n");
	scanf("%d",&j->nb_album);
	printf("saisie le proprietaire d'album' ");
    scanf("%s",&j->proprietaire);
    printf("saisie le catalogue \n");
	for(i=0;i<j->nb_album;i++)
	{
	saisie_album(&j->catalogue[i]);
}
}
//procedure d'afficher du jukbox
void affi_juckbox(jukebox_t j)
{
printf("*-*-*-*-*-*l'affichage jukebox est:*-*-*-*-*-*\n ");
printf("le nombre de chanson: %d \n ",j.nb_album);
printf("le propriétaire d'album: %s \n",j.proprietaire);
 int i;
	for (i=0;i< j.nb_album; i++)
	{	printf("\n le contenue du  %d album \n ",i+1); 
		affi_album(j.catalogue[i]);
		printf("\n");
	}
}
//fonction plus long album
int plus_long_album(jukebox_t j)
{
int  i;
int indice ;
int plus_lg;
plus_lg=duree_totale(j.catalogue[0]);
indice=0;
for(i=1;i<j.nb_album;i++)
{
if(indice<(duree_totale(j.catalogue[i])))
{
	plus_lg=duree_totale(j.catalogue[i]);
	indice=i;
}
	}
	return indice;	
}
//fontion inserer_album
bool inserer_album(album_t a, jukebox_t j)
{
	bool test;
	int pos,i;
	test=0;
	for(i=j.nb_album-1;i>=pos-1;i--)
	{
		j.catalogue[i+1] = j.catalogue[i];
		j.catalogue[pos-1] =j.catalogue[max_album+1];
		if(j.catalogue[i].annee == j.catalogue[max_album+1].annee && j.catalogue[i].artiste ==  j.catalogue[max_album+1].artiste && j.catalogue[i].nb_chanson ==  j.catalogue[max_album+1].nb_chanson )
		{
			test=1;
		}
		else
		{
			test=0; 
		}
	}
	return test;
}
main ()
{
setlocale(LC_CTYPE,"");
album_t a;
album_t inserlbum;
jukebox_t j;
int choix;
bool verif;
printf("Choisir un choix  \n");
	do{ printf("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
		printf("\n 1-Saisie d'un jukebox' ");
		printf("\n 2-Affichage d'un jukebox");
		printf("\n 3-Recherche d'un chanson dans d'un album du jukebox et afficher sa durée  ");
		printf("\n 4-Affichage du titre de l'album l'artiste de l'album le plus long  ");
		printf("\n 5-Insertin d'album ");
		printf("\n 6-Quitter  ");
		printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**-*-*-*-*-*-*-*-*\n");
		printf("Donner votre choix: ");
		scanf("%d",&choix);
	switch(choix)
	{
		case 1:
		printf("\n LE CHOIX :  SAISIE D'UN JUKEBOX");
		printf("\n");
		saisie_jukebox(&j);
		break;
	    case 2:
		printf("\n Le choix : l'affichage d'un jukebox''");
		printf("\n");
		affi_juckbox(j);
		break;
		case 3:
		printf("\n Le choix: la recherche d'un chanson dans un album du jukebox et l'affichage sa durée ");
		printf("\n");
		char ttr;
		printf("saisie le titre ");
        scanf("%s",&ttr);
		int i, duree;
		for(i=0;i<j.nb_album;i++)
		{
			duree = rech_chanson(j.catalogue[i],&ttr);
			if(duree != -1)
			{
				printf("\n la chanson  recherchée dans l'album et sa durree : %d \n", duree);
					break;
			}
		}
		if(duree == -1)
			printf("chanson ne trouve  pas");
		break;
			int ind;
			case 4:
		printf("\n Le choix  : afficher le titre et l'artistede l'album le plus long");
		printf("\n");
		ind=plus_long_album(j);
		printf("le titre de l'album le plus long est %s \n",j.catalogue[ind].titre);
		printf("l'artiste de l'album le plus long est %s \n",j.catalogue[ind].artiste);
		break;
		verif=0;
		case 5:
		printf("\n le choix :L'insere un nouveau album:");
		verif=inserer_album(inserlbum,j);
		if (verif!=0)
		{
		saisie_album(&inserlbum);
		}
		else 
		{
		printf(" impossible d'inserer un nouveaux  album ''");
		}
		break;
		case 6:
		printf("\n le choix : quitter le programme");
		exit(6);
		break;
		default:
		printf("donne un nouveau choix ");
		break;
	}
	} while(choix != 6);

	return 0;
}


