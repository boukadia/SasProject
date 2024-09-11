#include<stdio.h>
#include<string.h>

int nbr_total = 0;
int choix,i=0;
typedef struct {
    int jour;
    int mois;
    int annee;
}Date;
typedef struct{
    int nombre_unique;
    char nom[100];
    char prenom[100];
    Date date_de_naissance;
    char departement[100];
    float note_generale;

}list_etudiant;

list_etudiant etudiant[500];
int CountDep=0;

void menu(){

    printf("---------------< MENU >---------------\n");
    printf("1) Ajouter un etudiant\n");

    printf("2) modifier les informations d'un etudiant\n");
    printf("3) Afficher les details d'un etudiant \n");
    printf("4) suprimer les details d'un etudiant \n");
    printf("5) La moyenne generale\n");
    printf("6) Statistique\n");
    printf("----------------------------------------\n");
    printf("Tapez votre choix:\t");
    scanf("%d", &choix);
    printf("----------------------------------------\n");
}

void ajouter(){
    printf("--------------ajouter un etudiant-----------------\n");
    printf("le nom: \t");
    scanf(" %[^\n]s", &etudiant[i].nom);
    printf("le prenom: \t");
    scanf(" %[^\n]s", &etudiant[i].prenom);
    printf("la date de naissance(j/m/ans): \n");
    scanf("%d %d %d",&etudiant[i].date_de_naissance.jour, &etudiant[i].date_de_naissance.mois, &etudiant[i].date_de_naissance.annee);
    printf("le note generale: \t");
    scanf("%f", &etudiant[i].note_generale);
    printf("departement: \t");
    scanf(" %[^\n]s", &etudiant[i].departement);
    nbr_total++;
    etudiant[i].nombre_unique =  nbr_total;
    i++;

}


int verification(){
    int numero;
    printf("saisir le numero");
    scanf("%d",&numero);
    for(i=0;i<nbr_total;i++)
    {
        if (numero==etudiant[i].nombre_unique)
        {
           return i;
        }
    }
        return -1;


}
//Afficher le nombre total d'étudiants inscrits.
// Afficher le nombre total d'étudiants inscrits.

// Afficher le nombre d'étudiants dans chaque département.

//Afficher les étudiants ayant une moyenne générale supérieure à un certain seuil
void Modifier() {
    int found=0;
    verification();
    int index = verification();
    printf("indice est :%d",index);

        for(i = index ; i <nbr_total ; i++){
            if(index != -1)
            {
            printf("Tapez le nom: ");
            scanf(" %[^\n]s",&etudiant[i].nom);
            printf("Tapez le prenom: ");
            scanf(" %[^\n]s",&etudiant[i].prenom);
            printf("Tapez le departement: ");
            scanf(" %[^\n]s",&etudiant[i].departement);
            printf("Tapez la note general: ");
            scanf("%f",&etudiant[i].note_generale);
            printf("Tapez la date du naissance: ");
            scanf("%d %d %d",&etudiant[i].date_de_naissance.jour,&etudiant[i].date_de_naissance.mois,&etudiant[i].date_de_naissance.annee);
            found++;
            }
        if(found!=0)
        {
                printf("l'etudiant  n'exixte pas !");
                break;
        }
        }

    printf("\n");
}
void Supprime(){
    int index = verification();
    printf("indice est :%d",index);
    if(index != -1)
    {
        for(i = index ; i <nbr_total-1 ; i++)
        {
            etudiant[i] = etudiant[i+1];
        }
        nbr_total--;
        printf("l'etudiant a ete supprimee \n");
    }
    else
        printf(" le numero n'existe pas !\n");
}
void  Aff_etu_SUP_seuil(){
   int seuil;
   printf ("choisir une seuil : ");
   scanf("%d",&seuil);
    for(i=0;i<nbr_total;i++){
        if(etudiant[i].note_generale>=seuil)
        {
          printf(" Nom complet :  %s\n",etudiant[i].nom,etudiant[i].prenom);
        }
    }
}

void moyenneGeneralTotal()
{
    int total_departements=0;
    float somme_generale=0,moyenne_depp;

   char T[20][50];

        for (int i=0;i<nbr_total;i++)
      {
          int p=1;
              for(int j=i+1;j<nbr_total;j++){
                  if (strcmp(etudiant[i].departement,etudiant[j].departement)!=0)
                  p=1;
                  else
                  {
                  goto point ;
                  }
             }

          if (p==1)
          {
            printf("%s\n",etudiant[i].departement);
           strcpy(T[CountDep],etudiant[i].departement);
           CountDep++;
         }

        point :
      }
      for(int i=0;i<CountDep;i++)
      {
        float somme=0;
        int lenghDep =0;
        for( int j=0;j<nbr_total;j++)
        {
            if (strcmp(T[i],etudiant[j].departement)==0)
            {
                somme=somme+etudiant[j].note_generale;
                lenghDep++;
            }

        }
        moyenne_depp=somme/ lenghDep;
        printf("departement %d %s %.2f \n ",i+1,etudiant[i].departement,moyenne_depp);
        somme_generale =somme_generale+ moyenne_depp;
        total_departements++;

      }
      float moyenne_generale = somme_generale/total_departements;
    printf("Moyenne generale de tous les départements: %.2f\n", moyenne_generale);
}
void Affichage_Liste_etudient(){
    for(i=0;i<nbr_total;i++){
        printf("-----------------------<L'etudient %d>------------------------------- \n",etudiant[i].nombre_unique);

        printf(" Nom:                      %s\n",etudiant[i].nom);
         printf(" prenom:                  %s\n",etudiant[i].prenom);
        printf(" La Note general:          %.2f \n",etudiant[i].note_generale);
        printf(" La date de naissance:     %d %d %d\n",etudiant[i].date_de_naissance.jour,etudiant[i].date_de_naissance.mois,etudiant[i].date_de_naissance.annee);
        printf(" Le departement: %s\n",etudiant[i].departement);
}
}

void affichage_les_3Premier () {
    {
    for(i=0;i<nbr_total;i++){


        printf(" Nom:                      %s\n",etudiant[i].nom);
         printf(" prenom:                  %s\n",etudiant[i].prenom);
        printf(" La Note general:          %.2f \n",etudiant[i].note_generale);
        printf(" La date de naissance:     %d %d %d\n",etudiant[i].date_de_naissance.jour,etudiant[i].date_de_naissance.mois,etudiant[i].date_de_naissance.annee);
        printf(" Le departement: %s\n",etudiant[i].departement);
}
}

}



void Rech_nom()                         //recherche
{
    int i;
    char rech[50];
    printf("tapez le nom d'etudiant ");
    scanf(" %[^\n]s", &rech);
    int disponible = 0;
    for (i = 0; i < nbr_total; i++)
    {
        if (strcmp(rech,etudiant[i].nom)==0)
        {
            disponible = 1;
            break;
        }
        else
            disponible = 0;
    }
    if (disponible == 1)
    {
        printf("on a trouver ce nom");
         printf("L'etudient a numero %d \n",etudiant[i].nombre_unique);
        printf(" Nom:       %s\n",etudiant[i].nom);
         printf(" prenom:       %s\n",etudiant[i].prenom);
        printf(" La Note general:      %f \n",etudiant[i].note_generale);
        printf(" La date de naissance:   %d %d %d\n",etudiant[i].date_de_naissance.jour,etudiant[i].date_de_naissance.mois,etudiant[i].date_de_naissance.annee);
        printf(" Le departement: %s\n",etudiant[i].departement);

    }
    else
    {
        printf("ce nom n'existe pas \n");
    }
        printf("\n");
}
void Rech_Departement() {
    int i, count = 0;
    char rech[50];
    printf("Tapez le département : ");
    scanf(" %[^\n]s", rech);

    for (i = 0; i < nbr_total; i++) {
        if (strcmp(rech, etudiant[i].departement) == 0) {
            if (count != 0)
             {
                printf("La liste des étudiants du département : %s\n", rech);
             }
            printf("L'étudiant numero %d : \n", etudiant[i].nombre_unique);
            printf("Nom et prenom :        %s %s\n", etudiant[i].nom, etudiant[i].prenom);
            printf("La Note générale :     %f\n", etudiant[i].note_generale);
            printf("La date de naissance : %d %d %d\n", etudiant[i].date_de_naissance.jour, etudiant[i].date_de_naissance.mois, etudiant[i].date_de_naissance.annee);
            count++;
        }
    }

    if (count == 0) {
        printf("Aucun étudiant trouvé dans ce département!\n");
    }

    printf("\n");
}

void affichage_NbrTotal_etud(){
  printf("%d\n",nbr_total);

}


int main(){

   do
    {
        menu();

        switch (choix){
        case 1: ajouter();
            break;

        case 2: Modifier();
           break;
         case 3: Supprime();
         break;
         case 4:  {
                  printf(" la liste d'etudiant est :\n");
                  Affichage_Liste_etudient();
                  }
                break;
         case 5 : moyenneGeneralTotal() ;
            break;
            case 9 :affichage_NbrTotal_etud();
            break;

         case 6 :
         {
               int OptionChoix;
            do
        {



          printf("---------------< MENU >---------------\n");
          printf("1) Affichage le nombre des etudiants\n");
          printf("2) Affiche nombre total dans chaque departement\n");
          printf("3) Afficher les etudians ayant une note general superieur a une seuil \n");
          printf("4) Les 3 premiers  etudiants \n");
          printf("5) Affichage du nombre d'étudiants ayant réussi dans chaque departement\n");
          printf("Choisissez une option : ");
          scanf("%d", &OptionChoix);
           switch(OptionChoix){
            case 1 : affichage_NbrTotal_etud();
            break;
            case 2 :
            break;
            case 3 : Aff_etu_SUP_seuil();
            break;
            case 4 :
            break;
            case 5 :
            break;
            case 0 : printf("sortir");
            break;
            default : printf("incorrecte choix!");
            break;

            }
         }while (OptionChoix!=0);
         break;
         }

         case 7: Rech_nom()  ;
         break;
       case 8: Rech_Departement();
            break;
        default:
        printf("Oops !!\n");
            break;
        }
    } while (choix != 0);
return 0;

}
