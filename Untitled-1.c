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
    printf("0) sortir \n");
    printf("1) Ajouter un etudiant\n");
    printf("2) modifier les informations d'un etudiant\n");
    printf("3) suprimer les details d'un etudiant \n");
    printf("4) Afficher l list des  etudiants \n");
    printf("5) La moyenne generale\n");
    printf("6) Statistique\n");
    printf("7) Recherche un etudiant par son nom\n");
    printf("8) recherche un etudiant par son departement\n");
    printf("9) trier un etudiant par \n");
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
    printf("La  note generale: \t");
    scanf("%f", &etudiant[i].note_generale);
    printf("departement: \t");
    scanf(" %[^\n]s", &etudiant[i].departement);
    nbr_total++;
    etudiant[i].nombre_unique =  nbr_total;
    i++;

}

void Rech_Departement() {
    int i, count = 0;
    char rech[50];
    printf("Tapez le departement : ");
    scanf(" %[^\n]s", rech);

    for (i = 0; i < nbr_total; i++) {
        if (strcmp(rech, etudiant[i].departement) == 0) {
            if (count != 0)
             {
                printf("La liste des etudiants du departement : %s\n", rech);
             }
            printf("L'étudiant numero %d : \n", etudiant[i].nombre_unique);
            printf("Nom et prenom :        %s %s\n", etudiant[i].nom, etudiant[i].prenom);
            printf("La Note générale :     %f\n", etudiant[i].note_generale);
            printf("La date de naissance : %d %d %d\n", etudiant[i].date_de_naissance.jour, etudiant[i].date_de_naissance.mois, etudiant[i].date_de_naissance.annee);
            count++;
        }
    }

    if (count == 0) {
        printf("Aucun etudiant trouve dans ce departement!\n");
    }

    printf("\n");
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

void Modifier() {
    int found=0;
    verification();
    int index = verification();

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

void affichage_NbrTotal_etud(){
  printf("%d\n",nbr_total);

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

void moyenneGeneralTotal()
{
    int total_departements=0, CountDep = 0;
    float somme_generale=0,moyenne_depp = 0;

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
        moyenne_depp = somme/ lenghDep;
        printf("departement %d %s %.2f \n ",i+1,etudiant[i].departement,moyenne_depp);
        somme_generale =somme_generale+ moyenne_depp;
        total_departements++;

      }
      float moyenne_generale = somme_generale/total_departements;
    printf("Moyenne generale de tous les departements: %.2f\n", moyenne_generale);
}

void AffNomReusParDep() {
    char departements[100][50];                         // Tableau pour stocker les noms des départements
    int nombres_reussite[100] = {0};                     // Tableau pour stocker les comptes d'étudiants ayant réussi dans chaque département
    int nb_departements = 0;

                                                         // Remplir les departements et compter les reussit
    for (int i = 0; i < nbr_total; i++) {
        if (etudiant[i].note_generale >= 10) {           // On considere comme reussi si la note est >= 10
            int j;
            for (j = 0; j < nb_departements; j++) {
                if (strcmp(departements[j], etudiant[i].departement) == 0) {
                    nombres_reussite[j]++;
                    break;
                }
            }
            if (j == nb_departements) {
                strcpy(departements[nb_departements], etudiant[i].departement);
                nombres_reussite[nb_departements] = 1;
                nb_departements++;
            }
        }
    }

                                                         // Afficher les resultats
    printf("Nombre d'etudiants ayant reussi dans chaque departement :\n");
    for (int i = 0; i < nb_departements; i++) {
        printf("Departement %s : %d etudiant(s) ayant reussi\n", departements[i], nombres_reussite[i]);
    }
}

void TriEtudParNom() {
    list_etudiant temp;
    for (int i = 0; i < nbr_total - 1; i++) {
        for (int j = i + 1; j < nbr_total; j++) {
            if (strcmp(etudiant[i].nom, etudiant[j].nom) > 0) {
                                                  // Échanger les étudiants[i] et étudiants[j]
                temp = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = temp;
            }
        }
    }
}

void TriEtudParNote() {
    list_etudiant temp;
    for (int i = 0; i < nbr_total - 1; i++) {
        for (int j = i + 1; j < nbr_total; j++) {
            if (etudiant[i].note_generale < etudiant[j].note_generale) {
                                                    // echanger les etudiants[i] et etudiants[j]
                temp = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = temp;
            }
        }
    }
}

void Aff_Nbr_Etud_Deppa() {
    char departements[20][50];                      // Tableau de stocker les noms des departements
    int nombres[20] = {0};                          // Tableau de stocker les comptes d'etudiants de chaque departement
    int nb_departements = 0;

                                                    // Remplir les departements
    for (int i = 0; i < nbr_total; i++) {
        int j;
        for (j = 0; j < nb_departements; j++) {
            if (strcmp(departements[j], etudiant[i].departement) == 0) {
                nombres[j]++;
                break;
            }
        }
        if (j == nb_departements) {
            strcpy(departements[nb_departements], etudiant[i].departement);
            nombres[nb_departements] = 1;
            nb_departements++;
        }
    }

    // Afficher les résultats
    printf("Nombre d'etudiants dans chaque departement :\n");
    for (int i = 0; i < nb_departements; i++) {
        printf("Departement %s : %d etudiant(s)\n", departements[i], nombres[i]);
    }
}

void Affich_PreM3() {
    if (nbr_total < 3) {
        printf("Il y a moins de 3 étudiants dans la liste.\n");
        return;
    }

                                                         // Trier les etudiants par note (ordre decroissant)
    list_etudiant temp;
    for (int i = 0; i < nbr_total - 1; i++) {
        for (int j = i + 1; j < nbr_total; j++) {
            if (etudiant[i].note_generale < etudiant[j].note_generale) {
                                                        // echanger les etudiants[i] et étudiants[j]
                temp = etudiant[i];
                etudiant[i] = etudiant[j];
                etudiant[j] = temp;
            }
        }
    }

                                                          // Afficher les trois premiers etudiants
    printf("Les 3 étudiants ayant les meilleures notes sont :\n");
    for (int i = 0; i < 3; i++) {
        printf("-----------------------< L'etudiant %d >-------------------------------\n", etudiant[i].nombre_unique);
        printf("Nom:                      %s\n", etudiant[i].nom);
        printf("Prenom:                   %s\n", etudiant[i].prenom);
        printf("Note generale:            %.2f\n", etudiant[i].note_generale);
        printf("Date de naissance:        %d %d %d\n", etudiant[i].date_de_naissance.jour, etudiant[i].date_de_naissance.mois, etudiant[i].date_de_naissance.annee);
        printf("Departement:              %s\n", etudiant[i].departement);
    }
}

void TriEtudParNoteSUP10() {
    list_etudiant etudiants_sup_10[500]; // Tableau temporaire pour stocker les etudiants avec note > 10
    int count = 0;

    // Filtrer les etudiants avec une note superieure à 10
    for (int i = 0; i < nbr_total; i++) {
        if (etudiant[i].note_generale > 10) {
            etudiants_sup_10[count] = etudiant[i];
            count++;
        }
    }

    // Trier les etudiants avec note > 10 par leur note (ordre decroissant)
    list_etudiant temp;
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (etudiants_sup_10[i].note_generale < etudiants_sup_10[j].note_generale) {
                                                          // echanger les etudiants[i] et etudiants[j]
                temp = etudiants_sup_10[i];
                etudiants_sup_10[i] = etudiants_sup_10[j];
                etudiants_sup_10[j] = temp;
            }
        }
    }

                                                                        // Afficher les résultats
    printf("Liste des etudiants avec une note superieure à 10, tri par note (ordre decroissant) :\n");
    for (int i = 0; i < count; i++) {
        printf("-----------------------< L'etudiant %d >-------------------------------\n", etudiants_sup_10[i].nombre_unique);
        printf("Nom:                      %s\n", etudiants_sup_10[i].nom);
        printf("Prenom:                   %s\n", etudiants_sup_10[i].prenom);
        printf("Note generale:            %.2f\n", etudiants_sup_10[i].note_generale);
        printf("Date de naissance:        %d %d %d\n", etudiants_sup_10[i].date_de_naissance.jour, etudiants_sup_10[i].date_de_naissance.mois, etudiants_sup_10[i].date_de_naissance.annee);
        printf("Departement:              %s\n", etudiants_sup_10[i].departement);
    }
}



int main(){
int option;
   do
    {
        menu();

        switch (choix)
        {
         case 1: ajouter();
         break;
         case 2: Modifier();
         break;
         case 3: Supprime();
         break;
         case 4:
             {
                 printf(" la liste d'etudiant est :\n");
                 Affichage_Liste_etudient();
             }
         break;
         case 5 : moyenneGeneralTotal() ;
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
                        case 0 : printf("sortir");
                        break;
                        case 1 : affichage_NbrTotal_etud();
                        break;
                        case 2 : Aff_Nbr_Etud_Deppa();
                        break;
                        case 3 : Aff_etu_SUP_seuil();
                        break;
                        case 4 : Affich_PreM3();
                        break;
                        case 5 : AffNomReusParDep();
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
         case 9 :
             {

               int Option;
            do
        {
          printf("---------------< MENU >---------------\n");
          printf("1) Trier les etudiants par son nom\n");
          printf("2) Trier les etudiants par son notes\n");
          printf("3) Afficher les etudians ayant une note general superieur a une seuil \n");
          printf("Choisissez une option : ");
          scanf("%d", &Option);
           switch(Option)
           {
            case 0 : printf("sortir");
            break;
            case 1 : TriEtudParNom();
                     printf("La liste des étudiants triée par nom est :\n");
                     Affichage_Liste_etudient();
            break;

            case 2 : TriEtudParNote();
                     printf("La liste d'etudiants est :\n");
                     Affichage_Liste_etudient();
            break;
            case 3 : TriEtudParNoteSUP10();
            break;

            default : printf("incorrecte choix!");
            break;

            }
         }while (option == 0);

        break;

                 }
        default:
        printf("Oops !!\n");
            break;
        }
    } while (choix != 0);

return 0;

}
