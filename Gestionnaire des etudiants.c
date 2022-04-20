#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Declarations

int i, j, c, d, n = 0, choix, mat;
char classe[100];

struct etudiant
	{
		int mat;
		char nom[100], prenom[100];
		float moy;
		char classe[100];
		int j, m, a;
	};

struct etudiant etudiants[100];

//Fonctions

void ajouter_etudiant()
	{
		etq1:
		printf("Saisir les donnees de l'etudiant.\n\n");
		c = 0;
		printf("Saisir la matricule: ");
		scanf("%d", &etudiants[n].mat);
		fflush(stdin);
		if(n >= 1)
			for(i = 0; i <= n-1; i++)
				if(etudiants[n].mat == etudiants[i].mat)
					{ 
						printf("\nL'etudiant est deja enregiste.\n\n");
						c++;
						break;
					}
		if(c == 0)
			{
				printf("Classe: ");
				gets(etudiants[n].classe);
				fflush(stdin);
				printf("Nom: ");
				gets(etudiants[n].nom);
				fflush(stdin);
				printf("Prenom: ");
				gets(etudiants[n].prenom);
				fflush(stdin);
				printf("Date de naissance.\n");
				do
					{
						printf("Jour: ");
						scanf("%d", &etudiants[n].j);
						fflush(stdin);
					}
				while(etudiants[n].j < 1 || etudiants[n].j > 31);
				do
					{
						printf("Mois: ");
						scanf("%d", &etudiants[n].m);
						fflush(stdin);
					}
				while(etudiants[n].m < 1 || etudiants[n].m > 12);
				do
					{
						printf("Annee: ");
						scanf("%d", &etudiants[n].a);
						fflush(stdin);
					}
				while(etudiants[n].a < 1900 || etudiants[n].a > 2020);
				do
					{
						printf("Moyenne: ");
						scanf("%f", &etudiants[n].moy);
						fflush(stdin);
					}
				while(etudiants[n].moy < 0 || etudiants[n].moy > 20);
				printf("\n");
				n = n+1;
			}
		do
			{
				printf("Tappez 'Y' pour retourner au menu principale ou 'N' pour reessayer.\n\n");
				scanf("%c", &d);
				fflush(stdin);
				printf("\n");
			}
		while(d != 'Y' && d != 'N');
			if(d == 'Y')
				system("cls");
			if(d == 'N')
				goto etq1;
	}

void rechercher_par_mat()
	{
		etq2:
		c = 0;
		printf("Saisir la matricule: ");
		scanf("%d", &mat);
		fflush(stdin);
		for(i = 0; i <= n; i++)
				if(etudiants[i].mat == mat)
					{
						printf("\n");
						printf("Classe: %s\n", etudiants[i].classe);
						printf("Nom: %s\n", etudiants[i].nom);
						printf("Prenom: %s\n", etudiants[i].prenom);
						printf("Sa date de naissance est: %d/%d/%d\n", etudiants[i].j, etudiants[i].m, etudiants[i].a);
						printf("Moyenne: %.2f\n\n", etudiants[i].moy);
						c++;
						break;
					}
		if(c == 0)
			printf("\nMatricule introuvable.\n\n");
		do
			{
				printf("Tappez 'Y' pour retourner au menu principale ou 'N' pour reessayer.\n\n");
				scanf("%c", &d);
				fflush(stdin);
				printf("\n");
			}
		while(d != 'Y' && d != 'N');
			if(d == 'Y')
				system("cls");
			if(d == 'N')
				goto etq2;
	}

void afficher_admis_par_classe()
	{
		int x;
		etq3:
		c = 0;
		x = 0;
		printf("Saisir la classe: ");
		gets(classe);
		fflush(stdin);
		for(i = 0; i <= n; i++)
			if(strcmp(etudiants[i].classe, classe) == 0)
				{
					x++;
					break;
				}
		if(x == 0)
			printf("\nClasse introuvable.\n\n");
		else
			{
				for(i = 0; i <= n; i++)
					if(strcmp(etudiants[i].classe, classe) == 0)
						if(etudiants[i].moy > 10)
							{
								printf("\nLes etudiants admis sont: \n\n");
								break;
							}
				for(i = 0; i <= n; i++)
					if(strcmp(etudiants[i].classe, classe) == 0)
						if(etudiants[i].moy > 10)
							{
								printf("Numero matricule: %d\n", etudiants[i].mat);
								printf("Classe: %s\n", etudiants[i].classe);
								printf("Nom: %s\n", etudiants[i].nom);
								printf("Prenom: %s\n", etudiants[i].prenom);
								printf("Sa date de naissance est: %d/%d/%d\n", etudiants[i].j, etudiants[i].m, etudiants[i].a);
								printf("Moyenne: %.2f\n\n", etudiants[i].moy);
								c++;
							}
				if(c == 0)
					printf("\nAucun etudiant est admis parmis cette classe.\n\n");
			}
		do
			{
				printf("Tappez 'Y' pour retourner au menu principale ou 'N' pour reessayer.\n\n");
				scanf("%c", &d);
				fflush(stdin);
				printf("\n");
			}
		while(d != 'Y' && d != 'N');
			if(d == 'Y')
				system("cls");
			if(d == 'N')
				goto etq3;
	}

void afficher_par_classe()
	{
		int x;
		etq4:
		x = 0;
		c = 0;
		printf("Saisir la classe: ");
		gets(classe);
		fflush(stdin);
		for(i = 0; i <= n; i++)
			if(strcmp(etudiants[i].classe, classe) == 0)
				{
					x++;
					break;
				}
		if(x == 0)
			printf("\nClasse introuvable.\n\n");
		else
			{
				if(c == 0)
					for(i = 0; i <= n; i++)
						if(strcmp(etudiants[i].classe, classe) == 0)
							{
								printf("\nLes etudiants de cette classe sont: \n\n");
								c++;
								break;
							}
				for(i = 0; i <= n; i++)
					if(strcmp(etudiants[i].classe, classe) == 0)
						{
								printf("Numero matricule: %d\n", etudiants[i].mat);
								printf("Classe: %s\n", etudiants[i].classe);
								printf("Nom: %s\n", etudiants[i].nom);
								printf("Prenom: %s\n", etudiants[i].prenom);
								printf("Sa date de naissance est: %d/%d/%d\n", etudiants[i].j, etudiants[i].m, etudiants[i].a);
								printf("Moyenne: %.2f\n\n", etudiants[i].moy);
						}
			}
		do
			{
				printf("Tappez 'Y' pour retourner au menu principale ou 'N' pour reessayer.\n\n");
				scanf("%c", &d);
				fflush(stdin);
				printf("\n");
			}
		while(d != 'Y' && d != 'N');
			if(d == 'Y')
				system("cls");
			if(d == 'N')
				goto etq4;
	}

void supprimer()
	{
		etq5:
		c = 0;
		printf("Saisir la matricule de l'etudiant: ");
		scanf("%d", &mat);
		fflush(stdin);
		for(i = 0; i <= n-1; i++)
			if(etudiants[i].mat == mat)
				{
					for(i; i <= n; i++)
						etudiants[i] = etudiants[i+1];
					printf("\nL'etudiant qui a %d pour matricule a ete supprime avec succes.\n\n", mat);
					c++;
					n = n-1;
					break;
				}
		if(c == 0)
			printf("\nMatricule introuvable.\n\n");
		do
			{
				printf("Tappez 'Y' pour retourner au menu principale ou 'N' pour reessayer.\n\n");
				scanf("%c", &d);
				fflush(stdin);
				printf("\n");
			}
		while(d != 'Y' && d != 'N');
			if(d == 'Y')
				system("cls");
			if(d == 'N')
				goto etq5;
	}

void modifier_classe()
	{
		etq6:
		c = 0;
		printf("Saisir la matricule de l'etudiant: ");
		scanf("%d", &mat);
		fflush(stdin);
		for(i = 0; i <= n; i++)
			if(etudiants[i].mat == mat)
				{
					printf("\nSa classe actuelle est: %s\n", etudiants[i].classe);
					printf("\nEntrer sa nouvelle classe: ");
					gets(etudiants[i].classe);
					fflush(stdin);
					printf("\n");
					c++;
				}
		if(c == 0)
			printf("\nMatricule introuvable.\n\n");
		do
			{
				printf("Tappez 'Y' pour retourner au menu principale ou 'N' pour reessayer.\n\n");
				scanf("%c", &d);
				fflush(stdin);
				printf("\n");
			}
		while(d != 'Y' && d != 'N');
			if(d == 'Y')
				system("cls");
			if(d == 'N')
				goto etq6;
	}

void quitter()
	{
		system("cls");
		printf("\n\n\t-------------FIN------------\n\n\n");
		printf("\n\n\t------------MERCI-----------\n\n\n");
		system("pause");
	}

//Menu principale

int main()
	{
		etqm:
		do
			{
				printf("\n      ******    Gestion des etudiants    ****** \n\n");
				printf("==========================================================\n\n");
				printf("  Totale des etudiants : %d\n\n", n);
				printf("      <1>. Ajouter un etudiant----------------------------\n");
				printf("      <2>. Supprimer un etudiant--------------------------\n");
				printf("      <3>. Rechercher-------------------------------------\n");
				printf("      <4>. Modifier la classe-----------------------------\n");
				printf("      <5>. Liste par classe-------------------------------\n");
				printf("      <6>. Liste des admis par classe---------------------\n");
				printf("      <7>. Quitter----------------------------------------\n\n");
				printf("==========================================================\n\n");
				printf("Entre votre choix: ");
				scanf("%d", &choix);
				printf("\n");
				fflush(stdin);
				if(n == 0 && choix != 1 && choix >= 2 && choix <= 6)
					{
						system("cls");
						printf("Ajouter d'abord au moins un etudiant!\n\n");
						goto etqm;
					}
				else
					switch(choix)
						{
							case 1: system("cls"); ajouter_etudiant(); break;
							case 2: system("cls"); supprimer(); break;
							case 3: system("cls"); rechercher_par_mat(); break;
							case 4: system("cls"); modifier_classe(); break;
							case 5: system("cls"); afficher_par_classe(); break;
							case 6: system("cls"); afficher_admis_par_classe(); break;
							case 7: system("cls"); quitter(); break;
							default: system("cls"); printf("Choix invalide!\n");
						}
			}
		while(choix != 7);

	}
