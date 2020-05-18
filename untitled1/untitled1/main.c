#include <stdio.h>
//#include "modeleH.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE 1024
#define SPECIALITES {"Informatique","Architecture","Medecine","Droit","Chimique","Mathematique","Journalisme","Marketing","Physique","Biologie","Economie"};
#define INFORMATQUE 1
#define  ARCHITECTURE 2
#define MEDECINE 3
#define DROIT 4
#define CHIMIQUE 5
#define MATHEMATIQUE 6
#define JOURNALISME 7
#define MARKETING 8
#define PHYSIQUE 9
#define BIOLOGIE 10
#define ECONOMIE 11
#define CET_ANNEE 2019
typedef struct  Buffer {
    char bloc[TAILLE+1];
    int suivant;
}Buffer;
typedef struct enseignant{
    char* matricule;
    char* nom;
    char* prenom;
    char* date_naissance;
    char* wilaya;
    char* sexe;
    char* sang;
    char* date_recrutement;
    char* grade;
    int specialite;
    char* diplome;
    char* taille;
    char* univ;
}enseignant;

typedef struct EnTete {
    int Tete;
    int Queue;
    int indice_libre;
    int taille_bloc;
//    int charcater_supp;

}EnTete;
typedef struct fichier {
    FILE* fich ;
    EnTete entete;
}fichier;

//typedef  struct bloc {
//    char data [TAILLE] ;
//}bloc ;
int random (int max,int min ){

    return (rand() % (max+1 - min)) + min;
}

char* rand_univ(){
    printf("Begin\n");
    char* tab[105]={"Universite de Bechar - Mohamed Tahri " , "Universite  de Mascara - Mustapha Stambouli" , "Universite de Saida - Tahar Moulay " , "Universite  de Tlemcen - Abou Bekr Belkaid" , "Universite  d'Adrar - Ahmed Draya " , "Universite  de Tiaret - Ibn Khaldoun " , "Universite  Sidi Bel Abbes - Djillali Liabes " , "Universite de Mostaganem - Abdelhamid Ibn Badis " , "Universite d'Oran1 - Ahmed Ben Bella " , "Universite Mohamed Boudiaf  des sciences et de la technologie - Mohamed Boudiaf  d'Oran " , "Universite  d'Oran 2 - Mohamed Ben Ahmed" , "Universite  de Bouira - Akli Mohand Oulhadj" , "Universite  de Djelfa - Ziane Achour " , "Universite de Ghardaia " , "Universite  de Khemis Miliana - Djilali Bounaama " ,"Universite  Medea - Yahia Fares" , "Universite des sciences et de la technologie d'Alger, Houari Boumediene " , "Universite de Bejaia - Abderrahmane Mira " , "Universite  de Chlef - Hassiba Benbouali" , "Universite  de Boumerdes - M'hamed Bougara " , "Universite de Tizi Ouzou - Mouloud Maameri " , " Universite  de Laghouat - Amar Telidji" , "Universite  Blida 1 - Saad Dahlab " , "Universite de Blida 2 - Lounici Ali " , "Universite d'Alger 1 - Benyoucef Benkhedda " , "Universite d'Alger 2 - Abou el Kacem Saâdallah " , "Universite d'Alger 3 - Brahim Soltane Chaibout " , "Universite de la Formation Continue " , "Universite  de Jijel - Mohammed Seddik Ben yahia" , "Universite de Tebessa - Larbi Tebessi " , "Universite de Bordj Bou Arreridj - Mohamed Bachir El Ibrahimi " , "Universite d'El Tarf - Chadli Bendjedid " , "Universite  de Khenchela - Abbas Laghrour" , "Universite  de Oum El Bouaghi - Larbi Ben M'hidi " , "Universite d'El Oued - Hamma Lakhdar" , "Universite de Souk Ahras - Mohammed-Cherif Messaadia " , "Universite  de Annaba - Badji Mokhtar" , "Universite  du 20 Août 1955 de Skikda " , "Universite  8 Mai 1945 de Guelma " , "Universite de Batna 1 - Hadj Lakhder" , "Universite  de Biskra - Mohamed Khider " , "Universite  de M'sila - Mohamed Boudiaf " , "Universite  de Ouargla - Kasdi Merbah " , "Universite des sciences islamiques Emir Abdelkader de Constantine" , "Universite  de Setif 1 - Ferhat Abbas " , "Universite  de Setif 2 - Mohamed Lamine Debaghine " , "Universite  de Constantine 1 - Freres Mentouri " , "Universite  de Constantine 2 - Abdelhamid Mehri " , "Universite de Constantine 3 -Salah Boubnider " , "Universite de Batna 2 - Mustapha Ben Boulaid " , "Centre Universitaire de Tissemsilt- Ahmed ben yahia el-wancharissi" , "Centre Universitaire  de Ain Temouchent - Belhadj Bouchaib" , "Centre universitaire de Relizane - Ahmed Zabana" , "Centre universitaire   de Naama - Ahmed Salhi" , "Centre universitaire   d'El Bayadh - Nour Bachir" , "Centre universitaire de Tindouf-Ali Kafi" , "Centre universitaire de Maghnia" , " Centre universitaire de Tamanrasset - Amine Elokkal El Hadj Moussa Eg Akhamouk" , "Centre universitaire de Tipaza - Abdallah Morsli" , "Centre Universitaire d'Illizi-Cheikh Amoud ben Mokhtar" , "Centre universitaire d'Aflou" , "Centre Universitaire de Mila - Abdelhafid Boussouf" , "Centre Universitaire de Barika - Si El Haoues" , " Ecole Nationale Polytechnique d'Oran - Maurice Audin" , "Ecole  Superieure d'Informatique (Sidi Bel Abbes)- 08 Mai 1945" , "Ecole Superieure des Sciences Appliquees de Tlemcen ex EP ST Tlemcen" , "Ecole Superieure de Management de Tlemcen  ex EPSECG Tlemcen" , "Ecole Superieure d'Economie d'Oran   ex EPSECG Oran" , "Ecole Superieure en Genie Electrique et Energetique d'Oran  ex EP ST Oran" , "Ecole Superieure Agronomique de Mostaganem  ex EP SNV Mostaganem" , "Ecole Superieure des sciences Biologiques  d' Oran ex EP SNV Oran" , " Ecole Nationale Polytechnique" , "Ecole nationale superieure d'hydraulique - Arbaoui Abdellah" , "Ecole nationale superieure des travaux publics -  Francis Jeanson" , "Ecole nationale superieure veterinaire - Rabie Bouchama" , "Ecole Polytechnique d'architecture et d'Urbanisme-Hocine Ait Ahmed" , "Ecole nationale superieure agronomique- Khalef Abdellah alias Kasdi Merbah" , "Ecole des hautes etudes commerciales" , "Ecole nationale superieure d'informatique" , "Ecole nationale superieure en statistique et en economie appliquee" , "Ecole Superieure de Commerce-Mouloud Kacem Nait Belkacem" , "Ecole nationale superieure des sciences de la mer et de l'amenagement du littoral" , "Ecole nationale superieure de management" , "Ecole Nationale Superieure de Technologie" , "Ecole nationale superieure de journalisme et des sciences de l'information" , "Ecole Nationale Superieure des sciences politiques" , "Ecole Superieure des Sciences de l'Aliment et des Industries Agroalimentaires d'Alger  ex  EP SNV Alger" , "Ecole Superieure des Sciences appliquees d'Alger ex EP ST Alger" , "Ecole nationale superieure des mines et de la metallurgie - Amar Laskri" , "Ecole Nationale Polytechnique de Constantine- Malek Bennabi" , "Ecole Nationale Superieure de Biotechnologie de Constantine - Tewfik Khaznadar" , "Ecole Superieure des Sciences de Gestion de Annaba ex  - EPSECG Annaba" , "Ecole Superieure des Technologies Industrielles de Annaba  ex EP ST Annaba" , "Ecole Superieure de Comptabilite et de Finance de Constantine ex EPSECG Constantine" , " Ecole Normale Superieure de Mostaganem" , "Ecole Normale Superieure d'Oran" , "Ecole normale superieure de Bechar" , " Ecole normale superieure de Bouzareah - Cheikh Mubarak Ben Mohamed Brahimi El Mili" , "Ecole normale superieure de Kouba - Mohamed Bachir El Ibrahimi" , "Ecole normale superieure de Laghouat - Taleb Abderrahmane" , "Ecole normale superieure de Constantine -Assia Djebar" , "Ecole normale superieure d'enseignement technologique de Skikda" , " Ecole normale superieure de setif - Messaoud Zeghar" , "Ecole normale superieure de Bou Saâda" , "Ecole normale superieure de Ouargla" };
    return tab[random(105, 1) - 1];
}

int indice_univ(char* univ){
    int i;
    char* tab[105]={"Universite de Bechar - Mohamed Tahri " , "Universite  de Mascara - Mustapha Stambouli" , "Universite de Saida - Tahar Moulay " , "Universite  de Tlemcen - Abou Bekr Belkaid" , "Universite  d'Adrar - Ahmed Draya " , "Universite  de Tiaret - Ibn Khaldoun " , "Universite  Sidi Bel Abbes - Djillali Liabes " , "Universite de Mostaganem - Abdelhamid Ibn Badis " , "Universite d'Oran1 - Ahmed Ben Bella " , "Universite Mohamed Boudiaf  des sciences et de la technologie - Mohamed Boudiaf  d'Oran " , "Universite  d'Oran 2 - Mohamed Ben Ahmed" , "Universite  de Bouira - Akli Mohand Oulhadj" , "Universite  de Djelfa - Ziane Achour " , "Universite de Ghardaia " , "Universite  de Khemis Miliana - Djilali Bounaama " ,"Universite  Medea - Yahia Fares" , "Universite des sciences et de la technologie d'Alger, Houari Boumediene " , "Universite de Bejaia - Abderrahmane Mira " , "Universite  de Chlef - Hassiba Benbouali" , "Universite  de Boumerdes - M'hamed Bougara " , "Universite de Tizi Ouzou - Mouloud Maameri " , " Universite  de Laghouat - Amar Telidji" , "Universite  Blida 1 - Saad Dahlab " , "Universite de Blida 2 - Lounici Ali " , "Universite d'Alger 1 - Benyoucef Benkhedda " , "Universite d'Alger 2 - Abou el Kacem Saâdallah " , "Universite d'Alger 3 - Brahim Soltane Chaibout " , "Universite de la Formation Continue " , "Universite  de Jijel - Mohammed Seddik Ben yahia" , "Universite de Tebessa - Larbi Tebessi " , "Universite de Bordj Bou Arreridj - Mohamed Bachir El Ibrahimi " , "Universite d'El Tarf - Chadli Bendjedid " , "Universite  de Khenchela - Abbas Laghrour" , "Universite  de Oum El Bouaghi - Larbi Ben M'hidi " , "Universite d'El Oued - Hamma Lakhdar" , "Universite de Souk Ahras - Mohammed-Cherif Messaadia " , "Universite  de Annaba - Badji Mokhtar" , "Universite  du 20 Août 1955 de Skikda " , "Universite  8 Mai 1945 de Guelma " , "Universite de Batna 1 - Hadj Lakhder" , "Universite  de Biskra - Mohamed Khider " , "Universite  de M'sila - Mohamed Boudiaf " , "Universite  de Ouargla - Kasdi Merbah " , "Universite des sciences islamiques Emir Abdelkader de Constantine" , "Universite  de Setif 1 - Ferhat Abbas " , "Universite  de Setif 2 - Mohamed Lamine Debaghine " , "Universite  de Constantine 1 - Freres Mentouri " , "Universite  de Constantine 2 - Abdelhamid Mehri " , "Universite de Constantine 3 -Salah Boubnider " , "Universite de Batna 2 - Mustapha Ben Boulaid " , "Centre Universitaire de Tissemsilt- Ahmed ben yahia el-wancharissi" , "Centre Universitaire  de Ain Temouchent - Belhadj Bouchaib" , "Centre universitaire de Relizane - Ahmed Zabana" , "Centre universitaire   de Naama - Ahmed Salhi" , "Centre universitaire   d'El Bayadh - Nour Bachir" , "Centre universitaire de Tindouf-Ali Kafi" , "Centre universitaire de Maghnia" , " Centre universitaire de Tamanrasset - Amine Elokkal El Hadj Moussa Eg Akhamouk" , "Centre universitaire de Tipaza - Abdallah Morsli" , "Centre Universitaire d'Illizi-Cheikh Amoud ben Mokhtar" , "Centre universitaire d'Aflou" , "Centre Universitaire de Mila - Abdelhafid Boussouf" , "Centre Universitaire de Barika - Si El Haoues" , " Ecole Nationale Polytechnique d'Oran - Maurice Audin" , "Ecole  Superieure d'Informatique (Sidi Bel Abbes)- 08 Mai 1945" , "Ecole Superieure des Sciences Appliquees de Tlemcen ex EP ST Tlemcen" , "Ecole Superieure de Management de Tlemcen  ex EPSECG Tlemcen" , "Ecole Superieure d'Economie d'Oran   ex EPSECG Oran" , "Ecole Superieure en Genie Electrique et Energetique d'Oran  ex EP ST Oran" , "Ecole Superieure Agronomique de Mostaganem  ex EP SNV Mostaganem" , "Ecole Superieure des sciences Biologiques  d' Oran ex EP SNV Oran" , " Ecole Nationale Polytechnique" , "Ecole nationale superieure d'hydraulique - Arbaoui Abdellah" , "Ecole nationale superieure des travaux publics -  Francis Jeanson" , "Ecole nationale superieure veterinaire - Rabie Bouchama" , "Ecole Polytechnique d'architecture et d'Urbanisme-Hocine Ait Ahmed" , "Ecole nationale superieure agronomique- Khalef Abdellah alias Kasdi Merbah" , "Ecole des hautes etudes commerciales" , "Ecole nationale superieure d'informatique" , "Ecole nationale superieure en statistique et en economie appliquee" , "Ecole Superieure de Commerce-Mouloud Kacem Nait Belkacem" , "Ecole nationale superieure des sciences de la mer et de l'amenagement du littoral" , "Ecole nationale superieure de management" , "Ecole Nationale Superieure de Technologie" , "Ecole nationale superieure de journalisme et des sciences de l'information" , "Ecole Nationale Superieure des sciences politiques" , "Ecole Superieure des Sciences de l'Aliment et des Industries Agroalimentaires d'Alger  ex  EP SNV Alger" , "Ecole Superieure des Sciences appliquees d'Alger ex EP ST Alger" , "Ecole nationale superieure des mines et de la metallurgie - Amar Laskri" , "Ecole Nationale Polytechnique de Constantine- Malek Bennabi" , "Ecole Nationale Superieure de Biotechnologie de Constantine - Tewfik Khaznadar" , "Ecole Superieure des Sciences de Gestion de Annaba ex  - EPSECG Annaba" , "Ecole Superieure des Technologies Industrielles de Annaba  ex EP ST Annaba" , "Ecole Superieure de Comptabilite et de Finance de Constantine ex EPSECG Constantine" , " Ecole Normale Superieure de Mostaganem" , "Ecole Normale Superieure d'Oran" , "Ecole normale superieure de Bechar" , " Ecole normale superieure de Bouzareah - Cheikh Mubarak Ben Mohamed Brahimi El Mili" , "Ecole normale superieure de Kouba - Mohamed Bachir El Ibrahimi" , "Ecole normale superieure de Laghouat - Taleb Abderrahmane" , "Ecole normale superieure de Constantine -Assia Djebar" , "Ecole normale superieure d'enseignement technologique de Skikda" , " Ecole normale superieure de setif - Messaoud Zeghar" , "Ecole normale superieure de Bou Saâda" , "Ecole normale superieure de Ouargla" };
    for ( i = 0; i <= 104; i++) {
        if (!strcmp(univ, tab[i])) {
            break;
        }
    }
    return i+1;
}
char* rand_nom_pre(){
    char* mot=NULL;
    int taille = random(30, 4);
    mot = malloc((taille+1) * sizeof(char));
    for (int i = 0; i < taille; i++) {
        int lettre = random(26,1) ;
        mot[i]=(char)(lettre+96);
    }
    mot[taille] = '\0';
    return mot;
}
char* rand_mat(){
    char *mat = malloc(5* sizeof(char));
    int n=random(49999,11111)+random(50000,0);
    sprintf(mat, "%d", n);
    return mat;
}

char* rand_date_naiss(){
    int mois = random(12, 1);
    int annee = random(1993, 1953);
    int jours;
    if ((mois % 2 == 1 && mois < 8) || (mois % 2 == 0 && mois >= 8)) {
        jours = random(31, 1);
    }else if (mois!=2){jours=random(30,1);}
    else{ jours = random(28, 1); }
    char *mot = malloc(10 * sizeof(char));
    mot[0]= (jours/10) + 48;
    mot[1]= (jours%10) + 48;
    mot[2] = '/';
    mot[3]= (mois/10) + 48;
    mot[4]= (mois%10) + 48;
    mot[5] = '/';
    mot[6]= annee/1000 +48;
    mot[7]= (annee/100) % 10 +48;
    mot[8]= (annee/10) % 10 + 48;
    mot[9] = annee % 10+ 48;
    mot[10] = '\0';

    return mot;
}

char* rand_date_recrut(){
    int mois = random(12, 1);
    int annee = random(2019, 1980);
    int jours;
    if ((mois % 2 == 1 && mois < 8) || (mois % 2 == 0 && mois >= 8)) {
        jours = random(31, 1);
    }else if (mois!=2){jours=random(30,1);}
    else{ jours = random(28, 1); }
    char *mot = malloc(10 * sizeof(char));
    mot[0]= (jours/10) + 48;
    mot[1]= (jours%10) + 48;
    mot[2] = '/';
    mot[3]= (mois/10) + 48;
    mot[4]= (mois%10) + 48;
    mot[5] = '/';
    mot[6]= annee/1000 +48;
    mot[7]= (annee/100) % 10 +48;
    mot[8]= (annee/10) % 10 + 48;
    mot[9] = annee % 10+ 48;
    mot[10] = '\0';

    return mot;
}

char* rand_sang(){

    char* tab[8]={"O+", "A+", "B+", "O-", "A-", "AB+", "B-", "AB-"};
    return  tab[random(8, 1) - 1];
}

char *rand_sexe(){
    char* sexe[2]={"Masculin","Feminin"};
    return sexe[random(2, 1) - 1];
};
char* rand_grade(char* sexe){
    char* masculin[8] = {"Professeur", "Maitre de conferences Rang A", "Maitre de conferences Rang B","Maitre assistant Rang A", "Maitre assistant Rang B", "Assistant"};
    char* feminin[8] = {"Professeure", "Maitre de conferences Rang A", "Maitre de conferences Rang B","Maitre assistante Rang A", "Maitre assistante Rang B", "Assistante"};
    if (!strcmp(sexe,"Masculin")){
        return masculin[random(6, 1) - 1];
    }else{return feminin[random(6, 1) - 1];}
}
int rand_specialte(){
    return random(11, 1) ;
}
char* rand_diplome(){
    char* diplome[5]={"Doctorat Etat", "Doctorat en sciences","PhD","HDR","Magistere"};
    return diplome[random(5, 1) - 1];
}
char* rand_wilaya(){
    char* wilaya[48]={"Adrar","Chlef","Laghouat","Oum El Bouaghi","Batna","Bejaia" ,"Biskra","Bechar","Blida","Bouira","Tamanrasset","Tebessa","Tlemcen","Tiaret","Tizi Ouzou","Alger","Djelfa","Jijel","Setif","Saida","Skikda","Sidi Bel Abbas","Annaba","Guelma","Constantine","Medea","Mostaganem","M'Sila","Mascara","Ouatgla","Oran","El Bayadh","Illizi","Bordj Bou Arreridj","Boumerdes","El Tarf","Tindouf","Tissemsilt","El Oued","Khenchela","Souk Ahras","Tipaza","Mila","Ain Defla","Naama","Ain Temouchent","Ghardaia","Relizane"};
    return (wilaya[random(48, 1) - 1]);
}

char* calcul_taille(enseignant enr){
    int taille=strlen(enr.matricule)+strlen(enr.nom)+strlen(enr.prenom)+strlen(enr.date_naissance)+strlen(enr.date_naissance)+strlen(enr.wilaya)+strlen(enr.sexe)+strlen(enr.sang);

    char* result = malloc(4 * sizeof(char));
    sprintf(result, "%d", taille+200);
//    printf("result = %s\n", result);
    return result;
}

enseignant construire_enseignant(){
    enseignant enr;
    enr.matricule=rand_mat();
    enr.nom=rand_nom_pre();
    enr.prenom=rand_nom_pre();
    enr.date_naissance=rand_date_naiss();
    enr.wilaya=rand_wilaya();
    enr.sexe=rand_sexe();
    enr.sang=rand_sang();
    enr.date_recrutement=rand_date_recrut();
    enr.grade=rand_grade(enr.sexe);
    enr.specialite=rand_specialte();
    enr.diplome=rand_diplome();
    enr.univ = rand_univ();
    enr.taille=0;
    return enr;
}
void recuperer_mat ( int matricule , int* i  , int* j, int *specialite,int* univ, int* ancien){
    FILE *index = fopen("index_mat.bin", "rb");
    char* index_mat = malloc(27*sizeof(char));
    index_mat[0] = '\0';
    char* i_j_char=malloc(5*sizeof(char));
    fseek(index, (matricule - 11111) * 27 * sizeof(char), SEEK_SET);
    fseek(index, 6 * sizeof(char), SEEK_CUR);
    fread(i_j_char, 5 * sizeof(char), 1, index);
    printf("%s\n",i_j_char);
    *i = atoi(i_j_char);
    fseek(index, sizeof(char), SEEK_CUR);
    fread(i_j_char, 4 * sizeof(char), 1, index);
    i_j_char[4]='\0';
    printf("%s\n", i_j_char);
    *j = atoi(i_j_char);
    fseek(index, sizeof(char), SEEK_CUR);
    fread(i_j_char, 2 * sizeof(char), 1, index);
    i_j_char[2] = '\0';
    * specialite = atoi(i_j_char);
    fseek(index, sizeof(char), SEEK_CUR);
    fread(i_j_char, 3 * sizeof(char), 1, index);
    i_j_char[3] = '\0';
    * univ = atoi(i_j_char);
    fseek(index, sizeof(char), SEEK_CUR);
    fread(i_j_char, 2 * sizeof(char), 1, index);
    i_j_char[2] = '\0';
    printf("before %s\n", i_j_char);
    * ancien = atoi(i_j_char);
    printf("ancien= %d !!", *ancien);
    fclose(index);
}
void recuperer_mat_sans_ouverture (FILE* index ,int matricule , int* i  , int* j, int *specialite , int *univ , int* ancien ){
    char* index_mat = malloc(27*sizeof(char));
    index_mat[0] = '\0';
    char* i_j_char=malloc(5*sizeof(char));
    fseek(index, (matricule - 11111) * 27 * sizeof(char), SEEK_SET);
    fseek(index, 6 * sizeof(char), SEEK_CUR);
    fread(i_j_char, 5 * sizeof(char), 1, index);
    *i = atoi(i_j_char);
    fseek(index, sizeof(char), SEEK_CUR);
    fread(i_j_char, 4 * sizeof(char), 1, index);
    i_j_char[4]='\0';
    *j = atoi(i_j_char);
    fseek(index, sizeof(char), SEEK_CUR);
    fread(i_j_char, 2 * sizeof(char), 1, index);
    i_j_char[2] = '\0';
    * specialite = atoi(i_j_char);
    fseek(index, sizeof(char), SEEK_CUR);
    fread(i_j_char, 3 * sizeof(char), 1, index);
    i_j_char[3] = '\0';
    * univ = atoi(i_j_char);
    fseek(index, sizeof(char), SEEK_CUR);
    fread(i_j_char, 2 * sizeof(char), 1, index);
    i_j_char[2] = '\0';
    *ancien = atoi(i_j_char);
}

char* modifier_mat(int matricule , int i , int j , int specialite , int univ , int ancien){
    FILE* index = fopen("index_mat.bin", "rb+");
    fseek(index, (matricule - 11111) * 27 * sizeof(char), SEEK_SET);
    fseek(index,6* sizeof(char),SEEK_CUR);
    char i_j[21]={'0'};
    i_j[0]=i/10000 +48;
    i_j[1]=(i/1000)% 10 +48;
    i_j[2]=(i/100)%10 +48;
    i_j[3]=(i/10)%10 +48;
    i_j[4]=(i)%10 +48;
    i_j[5] = '#';
    i_j[6] = j / 1000 + 48;
    i_j[7]=(j/100)%10 +48;
    i_j[8] = (j / 10) % 10 + 48;
    i_j[9] = j % 10 + 48;
    i_j[10] = '#';
    i_j[11] = specialite / 10 +48;
    i_j[12] = specialite % 10 + 48;
    i_j[13] = '#';
    i_j[14] = univ / 100 +48;
    i_j[15] = (univ/10) %10 + 48 ;
    i_j[16] = univ%10 +48;
    i_j[17] = '#';
    i_j[18] = ancien / 10 + 48;
    i_j[19] = ancien % 10 + 48;
    i_j[20] = '\n';
    fwrite(i_j,strlen(i_j)* sizeof(char),1,index);
    fclose(index);
}

char* joindre( enseignant ens){
    char* specialite[11] =SPECIALITES;
    char* result=malloc(400* sizeof(char));
    result[0] = '\0';
//    strcat(result, ens.taille);
//    strcat(result, "#");
    strcat(result, ens.matricule);
    strcat(result, "#");
    strcat(result, ens.nom);
    strcat(result, "#");
    strcat(result,ens.prenom);
    strcat(result, "#");
    strcat(result, ens.date_naissance);
    strcat(result, "#");
    strcat(result, ens.wilaya);
    strcat(result, "#");
    strcat(result, ens.sexe);
    strcat(result, "#");
    strcat(result, ens.sang);
    strcat(result, "#");
    strcat(result, ens.date_recrutement);
    strcat(result, "#");
    strcat(result, ens.grade);
    strcat(result, "#");
    strcat(result,  specialite[ens.specialite - 1]);
    strcat(result, "#");
    strcat(result, ens.diplome);
    strcat(result, "#");
    strcat(result, ens.univ);
    strcat(result, "##");
    char* final = malloc((strlen(result)+7)*sizeof(char)) ;
    sprintf(final,"%d",strlen(result));
    strcat(final, "#N#");
//    printf("\n%s\n", final);
    strcat(final, result);
    return final;
}
void Afficher_entete(fichier* F){
    printf("Tete : %d\nQueue : %d\nindice libre : %d\n", F->entete.Tete,F->entete.Queue,F->entete.indice_libre);
}

void chevau(char* enr,Buffer* buf, fichier* f , int size[]){
    int cpt = 0;
//    printf("Le Buf esssst : %d", buf->suivant);
    int taille=strlen(buf->bloc);
    for(int i=taille; i<=TAILLE-1;i++){
        buf->bloc[i - 1] = enr[cpt];
        cpt++;
    }
    int now;
    buf->bloc[TAILLE - 1] = ';';
    buf->bloc[TAILLE];
//    buf->bloc[TAILLE-1] = '\0';
    if (buf->suivant == -1) {
        buf->suivant = 2;
    }else{
        buf->suivant = size[0];
    }
    char suiv[5]={'0'};
    suiv[0]=(buf->suivant)/10000 +48;
    suiv[1]=((buf->suivant)/1000)% 10 +48;
    suiv[2]=(buf->suivant/100)%10 +48;
    suiv[3]=(buf->suivant/10)%10 +48;
    suiv[4]=(buf->suivant)%10 +48;
    suiv[5] = '\0';
//    printf("le suivaaaaaaaant estttt %s \n", suiv);
//    size[0] += strlen(buf->bloc);
    size[0]+=1;
    fseek(f->fich, 0, SEEK_END);
//    printf("bien");
    fwrite(buf->bloc, TAILLE*sizeof(char),1, f->fich);
    fwrite(suiv, 5*sizeof(char), 1, f->fich);
    char point_virgule = ';';
    fwrite( &point_virgule, sizeof(char), 1, f->fich);
//    printf("bieeen\n");
//    printf("%d : apres chevau :\n %s\n",strlen(buf->bloc), buf->bloc);
    buf->bloc[0] = '\0';
    f->entete.Queue=buf->suivant;
    int j=0;
    while (cpt != strlen(enr)) {
        buf->bloc[j] = enr[cpt];
        j++;
        cpt++;
    }
    buf->bloc[j] = '\0';
//    printf("\n\nle reste : %s\n\n",buf->bloc);
}

void concat(Buffer* buf, char* enr , fichier* f , int size[]){
//    printf("strlen(bloc) = %d\nstrlen(enr)= %d\n", strlen(buf->bloc), strlen(enr));
    if(strlen(enr)+strlen(buf->bloc)<=TAILLE){
//        printf("concat !\n");
        strcat(buf->bloc, enr);
    }else{
//        printf("\ncheveau!!\n");
//        printf("%s\n\n\n", buf->bloc);
        chevau(enr,buf , f,size);
    }
}
char* entete_to_str(fichier* file){
    char *chaine = malloc(16*sizeof(char));
    printf("on a :\n");
    Afficher_entete(file);
    chaine[0]=file->entete.Tete/10000 +48;
    chaine[1]=(file->entete.Tete/1000)%10 +48;
    chaine[2]=(file->entete.Tete/100)%10 + 48;
    chaine[3]=(file->entete.Tete/10)%10 + 48;
    chaine[4]=file->entete.Tete%10 +48;
    chaine[5] = '\0';
    printf("%s now :\n",chaine);
    chaine[5] = ';';
    chaine[6]=file->entete.Queue/10000 + 48;
    chaine[7]=(file->entete.Queue/1000)%10 + 48;
    chaine[8]=(file->entete.Queue/100)%10 + 48;
    chaine[9]=(file->entete.Queue/10)%10 + 48;
    chaine[10]=file->entete.Queue%10 + 48;
    chaine[11] = ';';
    chaine[12]=file->entete.indice_libre/1000 + 48;
    chaine[13]=(file->entete.indice_libre/100)%10 + 48;
    chaine[14]=(file->entete.indice_libre/10)%10 + 48;
    chaine[15]=file->entete.indice_libre%10 + 48;
    chaine[16] = ';';
    chaine[17] = '\0';
    printf("la chaine finale est : %s\n \n \n",chaine);
    return chaine;
}

int recuperer_annee(char* date ){
    char *result_str = malloc(5 * sizeof(char));
    result_str[0] = '\0';
    for (int i = 6; i <= 9; i++) {
        strcat(result_str,&date[i]);
    }
    result_str[4] = '\0';
    return atoi(result_str);

}

int anciennete (enseignant ens ){
    return CET_ANNEE - recuperer_annee(ens.date_recrutement);
}

fichier* chargement_initial(int entier){
    fichier* F = malloc(sizeof(fichier));
    FILE *index = fopen("test.bin", "rb+");
    F->fich= fopen("test.bin", "wb");
    F->entete.indice_libre=0;
    F->entete.Tete=1;
    F->entete.Queue=1;
    F->entete.taille_bloc=TAILLE;
    char *entete_str = malloc(17*sizeof(char));
    int useless;
    entete_str=entete_to_str(F);
    printf("l'entete est : %s", entete_str);
    scanf("%d", &useless);
    fwrite(&F->entete, strlen(entete_str)* sizeof(char), 1, F->fich);
    char *mot = NULL;
    char* mot2=NULL;
    int i_index;
    int j_index;
    int spec_index;
    int univ;
    int ancien_index;
//    char* bloc = malloc(sizeof(char)*TAILLE);
    Buffer* buf = malloc(sizeof(Buffer));
    buf->bloc[0] = '\0';
    buf->suivant=-1;
    int  size[2];
    size[0]=2;
    enseignant ens ;
    int taille;
    srand(time(NULL));
    for (int i = 0; i < entier; i++) {
        ens=construire_enseignant();
        recuperer_mat(atoi(ens.matricule),&i_index,&j_index,&spec_index,&univ,&ancien_index);
        if(i_index==0 && j_index==0){
        mot = joindre(ens);
        printf("Apres jointure: %s\n",mot);
        modifier_mat(atoi(ens.matricule), F->entete.Queue, strlen(buf->bloc),ens.specialite,indice_univ(ens.univ),anciennete(ens));
        concat(buf, mot, F , size);
//        printf("%d termine \n", i);
//        taille=( taille+strlen(mot) ) % TAILLE;
//        printf("%d / %d \n" , taille , TAILLE );
        }else{
            printf("%s  existe dejaaa !!!!",ens.matricule);
            i--;
        }
    }
    if (strlen(buf->bloc)!=TAILLE) {
        fwrite(buf->bloc, strlen(buf->bloc)*sizeof(char),1, F->fich);
        F->entete.indice_libre = strlen(buf->bloc)+1;
    }
    fseek (F->fich,0,SEEK_SET);

    fwrite(entete_to_str(F), strlen(entete_to_str(F))*sizeof(char), 1, F->fich);


    printf("Final Size : %d et final entete %s\n", size[0] , entete_to_str(F));
    printf("Tete : %d\nQueue : %d\nindice libre : %d\n", F->entete.Tete,F->entete.Queue,F->entete.indice_libre);
    return F;
}


EnTete recuperer_entete (FILE* f){
    EnTete result;
    char* info=malloc(5*sizeof(char));
    rewind(f);
    fread(info, 5*sizeof(char), 1, f);
    result.Tete = atoi(info);
    fseek(f, sizeof(char), SEEK_CUR);
    fread(info, 5*sizeof(char), 1, f);
    result.Queue = atoi(info);
    fseek(f, sizeof(char), SEEK_CUR);
    fread(info, 4*sizeof(char), 1, f);
    info[4] = '\0';
    result.indice_libre = atoi(info);
    result.taille_bloc=TAILLE;
    rewind(f);
    return result;


}



fichier* ouvrir(char nom_file[20]){
    fichier* result = malloc(sizeof(fichier));
    result->fich = fopen(nom_file, "rb+");
    result->entete = recuperer_entete(result->fich);
    fseek(result->fich, 0, SEEK_SET);
    return result;
}

void LirDir(fichier* F , int i , Buffer* buf , int* suivant){
    fseek(F->fich, 17* sizeof(char) + (i - 1) * (F->entete.taille_bloc+6)*sizeof(char), SEEK_SET);
    fread(buf->bloc, TAILLE*sizeof(char),1, F->fich);
    buf->bloc[TAILLE] = '\0';
    printf("voila : \n%s ", buf->bloc);
//    printf("%d\n\n\n%s",strlen(buf->bloc),buf->bloc);
//    fseek(F->fich, sizeof(char),SEEK_CUR);
    char suiv[6];
    fread(suiv, 5 * sizeof(char), 1, F->fich);
    suiv[5] = '\0';
    buf->suivant = atoi(suiv);
    (*suivant) = atoi(suiv);
    printf("\n%d\n", (*suivant));

}


void EcrireDir(fichier* F , int i , Buffer* buf){
    if (strlen(buf->bloc)==TAILLE && i==F->entete.Queue) {
        rewind(F->fich);
        fseek(F->fich, 17* sizeof(char) + (i - 1) * (F->entete.taille_bloc + 6) * sizeof(char), SEEK_SET);
        fwrite(buf->bloc, TAILLE * sizeof(char), 1, F->fich);
        char suiv[6];
        suiv[0] = (buf->suivant) / 10000 + 48;
        suiv[1] = ((buf->suivant) / 1000) % 10 + 48;
        suiv[2] = (buf->suivant / 100) % 10 + 48;
        suiv[3] = (buf->suivant / 10) % 10 + 48;
        suiv[4] = (buf->suivant) % 10 + 48;
        suiv[5] = '\0';
        fwrite(suiv, 5 * sizeof(char), 1, F->fich);
    }else{
        printf("Sinon yaaay !!\n");
        printf("la position est : %d\n", i);
        buf->bloc[strlen(buf->bloc)]='\0';
        printf("a inserer : %s avec taille %d\n", buf->bloc,strlen(buf->bloc));
        rewind(F->fich);
        fseek(F->fich, 17* sizeof(char) + (i - 1) * (F->entete.taille_bloc + 6) * sizeof(char), SEEK_SET);
        fwrite(buf->bloc, strlen(buf->bloc) * sizeof(char), 1, F->fich);
    }
}
void chevau_ens(char* enr,Buffer* buf, fichier* f , int size){
    int cpt = 0;
    int taille=strlen(buf->bloc);
    for(int i=taille; i<=TAILLE-1;i++){
        buf->bloc[i - 1] = enr[cpt];
        cpt++;
    }
    int now;
    buf->bloc[TAILLE - 1] = ';';
    buf->bloc[TAILLE] = '\0';
    printf("\nle bloc final :%s\n",buf->bloc);
//    buf->bloc[TAILLE-1] = '\0';
    buf->suivant =f->entete.Queue+1;
    char suiv[6]={'0'};
    suiv[0]=(buf->suivant)/10000 +48;
    suiv[1]=((buf->suivant)/1000)% 10 +48;
    suiv[2]=(buf->suivant/100)%10 +48;
    suiv[3]=(buf->suivant/10)%10 +48;
    suiv[4]=(buf->suivant)%10 +48;
    suiv[5] = ';';
    printf("\nle sivant est : %s\n", suiv);
//    printf("le suivaaaaaaaant estttt %s \n", suiv);char
//    size[0] += strlen(buf->bloc);
    rewind(f->fich);
    fseek(f->fich, 17* sizeof(char) + (f->entete.Queue - 1) * (f->entete.taille_bloc + 6) * sizeof(char), SEEK_SET);
    fwrite(buf->bloc, strlen(buf->bloc) * sizeof(char), 1, f->fich);
//    fseek(f->fich, -2 * sizeof(char), SEEK_END);
    fwrite(suiv,6*sizeof(char),1,f->fich);
//    printf("bien");"
//    fwrite(buf->bloc, TAILLE*sizeof(char),1, f->fich);
//    fwrite(suiv, 6*sizeof(char), 1, f->fich);
//    printf("bieeen\n");
//    printf("%d : apres chevau :\n %s\n",strlen(buf->bloc), buf->bloc);
    buf->bloc[0] = '\0';
    int suivante =f->entete.Queue +1;
    int j=0;
    while (cpt != strlen(enr)) {
        buf->bloc[j] = enr[cpt];
        j++;
        cpt++;
    }
    buf->bloc[j] = '\0';
    printf("Le reste : %s\n", buf->bloc);
//    printf("\n\nle reste : %s\n\n",buf->bloc);
//    fseek (f->fich,0,SEEK_SET);
    fseek(f->fich, 17 * sizeof(char) + (suivante - 1) * (f->entete.taille_bloc + 6) * sizeof(char), SEEK_SET);
    fwrite(buf->bloc, strlen(buf->bloc) * sizeof(char), 1, f->fich);
    f->entete.indice_libre = j;
    f->entete.Queue += 1;
    fseek (f->fich,0,SEEK_SET);
    fwrite(entete_to_str(f), strlen(entete_to_str(f)) * sizeof(char), 1, f->fich);
}



void ajouterEns(fichier* file , enseignant ens){
    char* enr = NULL;
    int suivant;
    int size = file->entete.Queue;
    Buffer *buf = malloc(sizeof(Buffer));
    enr = joindre(ens);
    LirDir(file,file->entete.Queue,buf,&suivant);
    buf->suivant = suivant;
    if(strlen(enr)+strlen(buf->bloc)<=TAILLE){
        strcat(buf->bloc, enr);
        EcrireDir(file, file->entete.Queue, buf);
        file->entete.indice_libre = strlen(buf->bloc);
    }else{
        chevau_ens(enr,buf , file,size);
    }

}

void creer_index_mat(int min , int max ){
    char* mat = malloc(23*sizeof(char));
    FILE* index = fopen("index_mat.bin", "wb");
    for (int i = min; i <= max; i++) {
        sprintf(mat, "%d", i);
        strcat(mat,"#00000#0000#00#000#00\n");
        printf("voila : %s", mat);
        fwrite(mat, strlen(mat) * sizeof(char), 1, index);
    }
    fclose(index);
}
char* to_String_2(int val){
    char *result = malloc(3 * sizeof(char));
    result[0] = val / 10 +48;
    result[1] = val % 10 + 48;
    result[2] = '\0';
    return result;

}
char* to_String_3(int val){
    char *result = malloc(4 * sizeof(char));
    result[0] = val / 100 +48;
    result[1]= (val/10)%10 +48;
    result[2] = val % 10 + 48;
    result[3] = '\0';
    return result;
}

char* toString_5 (int matricule){
    char *result = malloc(7 * sizeof(char));
    result[0] = matricule / 10000 + 48;
    result[1] = (matricule / 1000) % 10 + 48;
    result[2] = (matricule / 100) % 10+48;
    result[3] = (matricule / 10) % 10+48;
    result[4] = matricule % 10+48;
    result[5] = '\0';
    return result;
}

char* toString_6 (int taille){
    char *result = malloc(7 * sizeof(char));
    result[0] = taille / 100000 + 48;
    result[1] = (taille / 10000) % 10 + 48;
    result[2] = (taille / 1000) % 10+48;
    result[3] = (taille / 100) % 10+48;
    result[4] = (taille/10) % 10+48;
    result[5] = taille % 10+48;
    result[6] = '\0';
    return result;
}

//void ajouter_index_specialite(enseignant ens){
//    FILE* index = fopen("index_spec.bin", "rb");
//    char* spec=malloc(19* sizeof(char));
//    char* taille_str=malloc(5* sizeof(char));
//    char* sub_part=malloc(100000 * sizeof(char));
//    char *part1 = malloc(500000 * sizeof(char));
//    char *part2 = malloc(500000 * sizeof(char));
//    part1[0] = '\0';
//    part2[0] = '\0';
//    int taille_part1=0;
//    int taille_total;
//    char *taille_total_str = malloc(6 * sizeof(char));
//    fread(taille_total_str, 6 * sizeof(char), 1, index);
//    taille_total=atoi(taille_total_str);
//    fseek(index, sizeof(char), SEEK_CUR);
//        // IL FAUT INCREMENTER LA TAILLE DE SPECILAITE LORSQU4ON AJOUTE ( EXMPLE 00024 INFORMATIQUE DOIT ETRE 00030INFORMATIQUE °
//        for (int i = 1; i <= ens.specialite; i++) {
//            fread(taille_str, 5 * sizeof(char), 1, index);
//            strcat(part1, taille_str);
////            else{ printf("taille_str =%s,atoi = %d",taille_str,atoi(taille_str));strcat(part1, toString_5(atoi(taille_str) + 6)); printf("j'ai ecrit %s\n !!!",toString_5(atoi(taille_str) + 6));}
//            printf("j'ai lit %s\n", taille_str);
//            taille_part1 += 5 + 14 + atoi(taille_str) + 1;
////            fseek(index, (atoi(taille_str) + 14 + 1) * sizeof(char), SEEK_CUR);
//            fread(sub_part, (atoi(taille_str) + 14 + 1) * sizeof(char),1, index);
//            strcat(part1, sub_part);
//        }
//        printf("taille total est : %d mais taille part1 = %d", taille_total,strlen(part1)-1);
//        part1[strlen(part1) - 1] = '\0';
//        strcat(part1, ens.matricule);
//        strcat(part1, "##");
//        part1[strlen(part1)] = '\0';
//        fread(part2, (taille_total - taille_part1) * sizeof(char), 1, index);
//        part2[strlen(part2)] = '\0';
//        printf("part1=\n%s\n", part1);
//        printf("part2=\n%s\n", part2);
//        FILE *test = fopen("t.bin", "wb");
//        FILE *result = fopen("index_spec.bin", "wb");
//        char* taille_new= toString_6(taille_total+6);
//        strcat(taille_new, "#");
//        fwrite(taille_new, strlen(taille_new) * sizeof(char), 1, test);
//        fwrite(part1, strlen(part1) * sizeof(char), 1, test);
//        fwrite(part2, strlen(part2) * sizeof(char), 1, test);
//        fwrite(taille_new, strlen(taille_new) * sizeof(char), 1, result);
//        fwrite(part1, strlen(part1) * sizeof(char), 1, result);
//        fwrite(part2, strlen(part2) * sizeof(char), 1, result);
////        fread(spec, 19 * sizeof(char), 1, index);
////        spec[19] = '\0';
////        printf(" et la prochaine specialte est : '%s'", spec);
//}

void ajouter_index_specialite(enseignant ens){
    char* taille_all_str_7=malloc(7* sizeof(char));
    char* sub_taille_str=malloc(6* sizeof(char));
    int taille_7;
    char* part1 =malloc(100000* sizeof(char));
    char* part2 =malloc(100000* sizeof(char));
    char *sub_part = malloc(100000 * sizeof(char));
    part1[0] = '\0';
    sub_part[0] = '\0';
    taille_all_str_7[0] = '\0';
    sub_taille_str[0]='\0';
    part2[0] = '\0';
    FILE *index = fopen("index_spec.bin", "rb");
    FILE *test = fopen("result.bin", "wb");
    fread(taille_all_str_7, 6 * sizeof(char), 1, index);//000286
    taille_all_str_7[6] = '\0';
    fseek(index, sizeof(char), SEEK_CUR); // #
    strcat(part1, toString_6(atoi(taille_all_str_7) + 6));
    strcat(part1, "#");
    int a_lire;
    taille_7 = atoi(taille_all_str_7);
    for (int i = 1; i <= ens.specialite; i++) {
        fread(sub_taille_str, 5 * sizeof(char), 1, index);//00000
        sub_taille_str[5] = '\0';
        printf("sub_taille_str %d = %s\n", i, sub_taille_str);
        if (i != ens.specialite) {
            strcat(part1, sub_taille_str);
        }else{
            strcat(part1, toString_5(atoi(sub_taille_str) + 6));
        }

        fread(sub_part, (atoi(sub_taille_str) + 14 + 1) * sizeof(char), 1, index);//INFORMATIQUE:xxxxx##
        printf("je viens de lire %d\n",atoi(sub_taille_str) + 14 + 1);
        sub_part[atoi(sub_taille_str) + 14 + 1] = '\0';
        strcat(part1, sub_part);
        printf("part1 %d = %s\n", i,part1);
    }
    int taille_part1 = strlen(part1);
    part1[strlen(part1) - 1] = '\0'; // pour se debarasser de deuxieme #
    strcat(part1, ens.matricule);
    strcat(part1, "##");
    part1[strlen(part1)] = '\0';
    fwrite(part1, strlen(part1) * sizeof(char), 1, test);
    fread(part2, (taille_7 + 7 - taille_part1) * sizeof(char), 1, index);
    part2[strlen(part2)] = '\0';
    printf("part2=\n%s",part2);
    fwrite(part2, strlen(part2) * sizeof(char), 1, test);
    index = fopen("index_spec.bin", "wb");
    fwrite(part1, strlen(part1) * sizeof(char), 1, index);
    fwrite(part2, strlen(part2) * sizeof(char), 1, index);
    fclose(index);
    fclose(test);
}
void creer_index_specialite (int min , int max ){
    FILE* index=fopen("index_mat.bin","rb");
    FILE *index_spec = fopen("index_spec.bin", "wb");
    char* buf =malloc(1000000*sizeof(char));
    char* buf_final=malloc(1000000*sizeof(char));
    buf[0]='\0';
    buf_final[0] = '\0';
    int t=0;
    int i,j,spec,univ,anciennete;
    char* mat=malloc(7*sizeof(char));
    int test=1;
    char *info=malloc(100000*sizeof(char)),*archi=malloc(100000*sizeof(char)),*med=malloc(100000*sizeof(char)),*dro=malloc(100000*sizeof(char)) , *chim=malloc(100000*sizeof(char)) , *math=malloc(100000*sizeof(char)) , *jour=malloc(100000*sizeof(char)) , *mark=malloc(100000*sizeof(char)) , *phy= malloc(100000*sizeof(char)),*bio=malloc(100000*sizeof(char)),*eco=malloc(100000*sizeof(char));
    info[0] = '\0';archi[0]='\0';med[0]='\0';dro[0]='\0';chim[0]='\0';math[0]='\0';jour[0]='\0';mark[0]='\0';phy[0]='\0';bio[0]='\0';eco[0]='\0';
    printf("initially everything is good !!!");
    for (int matricule = min; matricule <= max; matricule++) {
        recuperer_mat_sans_ouverture(index,matricule,&i,&j,&spec,&univ,&anciennete);
        printf("spec = %d",spec);
        printf("matricule= %d\n", matricule);
        if (i != 0) {
            printf("entrer !!\n");
            mat = toString_5(matricule);
            mat[5] = '#';
            mat[6] = '\0';
            printf("mat= %s spec=%d\n", mat,spec);
            if (test) {
                scanf("%d",&t);
                test=0;
            }

            switch(spec) {
                case INFORMATQUE:
//                    strcat(info, toString_5(matricule));
                    strcat(info, mat);
                    printf("info= %s\n", info);
                    break;
                case ARCHITECTURE:
//                    strcat( archi, toString_5(matricule));
                    strcat(archi, mat);
                    printf("archi= %s\n", archi);
                    break;
                case MEDECINE:
//                    strcat(med, toString_5(matricule));
                    strcat(med, mat);
                    printf("med= %s\n", med);
                    break;
                case DROIT:
//                    strcat(dro, toString_5(matricule));
                    strcat(dro, mat);
                    printf("dro= %s\n", dro);
                    break;
                case  CHIMIQUE:
//                    strcat(chim, toString_5(matricule));
                    strcat(chim, mat);
                    printf("chim %s\n", chim);
                    break;
                case MATHEMATIQUE:
//                    strcat(math, toString_5(matricule));
                    strcat(math, mat);
                    printf("math= %s\n", math);
                    break;
                case JOURNALISME:
//                    strcat(jour, toString_5(matricule));
                    strcat(jour, mat);
                    printf("jour= %s\n", jour);
                    break;
                case MARKETING:
//                    strcat(mark, toString_5(matricule));
                    strcat(mark, mat);
                    printf("mark= %s\n", mark);
                    break;
                case PHYSIQUE:
//                    strcat(phy, toString_5(matricule));
                    strcat(phy, mat);
                    printf("phy= %s\n", phy);
                    break;
                case BIOLOGIE:
//                    strcat(bio, toString_5(matricule));
                    strcat(bio, mat);
                    printf("bio= %s\n", bio);
                    break;
                case ECONOMIE:
//                    strcat(eco, toString_5(matricule));
                    strcat(eco, mat);
                    printf("eco= %s\n", eco);
                    break;
                default:
                    printf("wtttttf §§§\n");
                    break;

            }
        }
    }
    strcat(buf, toString_5(strlen(info)));
    printf("1");
    strcat(buf,"INFORMATIQUE :");
    printf("1");
    printf("info = %s\n",info);
    scanf("%d", &t);
    strcat(buf, info);
    printf("1");
    strcat(buf, "#");
    printf("1");
    strcat(buf, toString_5(strlen(archi)));
    printf("1");
    strcat(buf,"ARCHITECTURE :");
    printf("1");
    strcat(buf, archi);
    printf("1");
    strcat(buf, "#");
    printf("1");
    strcat(buf, toString_5(strlen(med)));
    printf("1");
    strcat(buf,"MEDECINE     :");
    printf("1");
    strcat(buf, med);
    printf("1");
    strcat(buf, "#");
    printf("1");
    strcat(buf, toString_5(strlen(dro)));
    printf("1");
    strcat(buf,"DROIT        :");
    printf("1");
    strcat(buf, dro);
    printf("1");
    strcat(buf, "#");
    printf("1");
    strcat(buf, toString_5(strlen(chim)));
    printf("1");
    strcat(buf,"CHIMIQUE     :");
    strcat(buf, chim);
    strcat(buf, "#");
    strcat(buf, toString_5(strlen(math)));
    strcat(buf,"MATHEMATIQUE :");
    strcat(buf, math);
    strcat(buf, "#");
    strcat(buf, toString_5(strlen(jour)));
    strcat(buf,"JOURNALISME  :");
    strcat(buf, jour);
    strcat(buf, "#");
    strcat(buf, toString_5(strlen(mark)));
    strcat(buf,"MARKETING    :");
    strcat(buf, mark);
    strcat(buf, "#");
    strcat(buf, toString_5(strlen(phy)));
    strcat(buf,"PHYSIQUE     :");
    strcat(buf, phy);
    strcat(buf, "#");
    strcat(buf, toString_5(strlen(bio)));
    strcat(buf,"BIOLOGIE     :");
    strcat(buf, bio);
    strcat(buf, "#");
    strcat(buf, toString_5(strlen(eco)));
    strcat(buf,"ECONOMIE     :");
    strcat(buf, eco);
    strcat(buf, "#");
    buf[strlen(buf)] = '\0';
    strcat(buf_final,toString_6(strlen(buf)));
    strcat(buf_final, "#");
    strcat(buf_final, buf);
    fwrite(buf_final, strlen(buf_final) * sizeof(char),1, index_spec);
    fclose(index);
    fclose(index_spec);
}
void construire_bits_map_univ(int min , int max) {
    FILE *index = fopen("index_mat.bin", "rb");
    FILE *bit = fopen("bit_univ.bin", "wb");
    char *tab[105];
    char *zeros = malloc(88889 * sizeof(char));
    int i, j, mat, spec, univ,anciennete;
    zeros[0] = '\0';
    for (int ii = 11111; ii <= 99999; ii++) {
        strcat(zeros, "0");
    }
    zeros[strlen(zeros)] = '\0';
    printf("!!!");
    for (int jj = 1; jj <= 105; jj++) {
        tab[jj-1] = malloc(88889 * sizeof(char));
        tab[jj-1][0] = '\0';
        strcat(tab[jj-1], zeros);
        tab[jj-1][strlen(tab[jj-1])] = '\0';
    }
//    printf("\n%s\n", tab[80]);
    printf("\n!!!!!");

    for (int k = 0; k <= 88888; k++) {
        recuperer_mat_sans_ouverture(index, k+11111, &i, &j, &spec, &univ,&anciennete);
        if (i!=0){
            printf("copier %c",tab[univ - 1][k]);
            tab[univ - 1][k] = 49;
            printf("apres %c",tab[univ - 1][k] );}
    }
    printf("univ 5 =\n%s\n", tab[4]);
    char *entete = malloc(8 * sizeof(char));
    entete[0] = '\0';
    strcat(entete, to_String_3(min));
    strcat(entete, ";");
    strcat(entete, to_String_3(max));
    strcat(entete, ";");
    entete[strlen(entete)] = '\0';
    fwrite(entete, strlen(entete) * sizeof(char), 1, bit);
    for (int kk = min; kk <= max; kk++) {
        fwrite(to_String_3(kk), 3 * sizeof(char), 1, bit);
        fwrite(":", sizeof(char), 1, bit);
        fwrite(tab[kk - 1], strlen(tab[kk - 1]) * sizeof(char), 1, bit);
        if(kk!=max){ fwrite("\n", sizeof(char), 1, bit); }
    }


}


void construire_bits_map_anciennete(int max) { // evident que min=0
    FILE *index = fopen("index_mat.bin", "rb");
    FILE *bit = fopen("bit_anciennete.bin", "wb");
    char *tab[40];
    char *zeros = malloc(88889 * sizeof(char));
    int i, j, mat, spec, univ,anciennete;
    zeros[0] = '\0';
    printf("!\n");
    for (int ii = 11111; ii <= 99999; ii++) {
        strcat(zeros, "0");
    }
    zeros[strlen(zeros)] = '\0';
    printf("!\n");
    for (int jj = 0; jj <= max; jj++) {
        tab[jj] = malloc(88889 * sizeof(char));
        tab[jj][0] = '\0';
        strcat(tab[jj], zeros);
        tab[jj][strlen(tab[jj])] = '\0';
    }
//    printf("\n%s\n", tab[80]);
    printf("!\n");

    for (int k = 0; k <= 88888; k++) {
        recuperer_mat_sans_ouverture(index, k+11111, &i, &j, &spec, &univ,&anciennete);
        if (i!=0){
            printf("copier %c",tab[anciennete][k]);
            tab[anciennete][k] = 49;
            printf("apres %c",tab[anciennete][k] );}
    }
    printf("!\n");
    printf("univ 5 =\n%s\n", tab[4]);
    char *entete = malloc(9 * sizeof(char));
    entete[0] = '\0';
    strcat(entete, to_String_3(0));
    strcat(entete, ";");
    strcat(entete, to_String_3(max));
    strcat(entete, ";");
    entete[strlen(entete)] = '\0';
    printf("!\n");
    fwrite(entete, strlen(entete) * sizeof(char), 1, bit);
    for (int kk = 0; kk <= max; kk++) {
        fwrite(to_String_3(kk), 3 * sizeof(char), 1, bit);
        fwrite(":", sizeof(char), 1, bit);
        fwrite(tab[kk], strlen(tab[kk]) * sizeof(char), 1, bit);
        if(kk!=max){ fwrite("\n", sizeof(char), 1, bit); }
    }
    printf("!\n");


}


void recuperer_entete_bin(FILE* index , int* min , int* max){
    rewind(index);
    char *max_str = malloc(4 * sizeof(char));
    char *min_str = malloc(4 * sizeof(char));
    max_str[0] = '\0';
    min_str[0] = '\0';
    rewind(index);
    fread(min_str, 3 * sizeof(char), 1, index);
    min_str[3] = '\0';
    fseek(index, sizeof(char), SEEK_CUR);
    fread(max_str, 3 * sizeof(char), 1, index);
    max_str[3] = '\0';
    printf("min_str =%s et max_str = %s\n",min_str,max_str);
    *min = atoi(min_str);
    *max = atoi(max_str);
}

void modifier_bit ( FILE* index, int cle , int indice , int bin  ){
    int min , max;
    recuperer_entete_bin(index, &min, &max);
}


//    printf("avant\n");
//    strcat(tab[min], "abc");
//    printf("apres\n");
//    strcat(tab[max], "efg");
//    tab[0][strlen(tab[min])] = '\0';
//    tab[1][strlen(tab[max])] = '\0';
//    printf("%s | %s", tab[min], tab[max]);
//}


//void construire_bits_map(FILE* fich , int min , int max  ){
//    char *entete = malloc(8 * sizeof(char));
//    char *zeros = malloc(88889 * sizeof(char));
//    zeros[0] = '\0';
//    entete[0] = '\0';
//    strcat(entete, to_String_3(min));
//    strcat(entete, ";");
//    strcat(entete, to_String_3(max));
//    strcat(entete, ";");
//    entete[strlen(entete)] = '\0';
//    fwrite(entete, strlen(entete) * sizeof(char), 1, fich);

//    strcat(zeros, "\n");
//    zeros[strlen(zeros)] = '\0';
//    for (int i = min; i <max; i++) {
//        fwrite(to_String_3(i), 3 * sizeof(char), 1, fich);
//        fwrite(":", sizeof(char), 1, fich);
//        fwrite(zeros, strlen(zeros) * sizeof(char), 1, fich);
//    }
//    fwrite(to_String_3(max), 3 * sizeof(char), 1, fich);
//    fwrite(":", sizeof(char), 1, fich);
//    zeros[strlen(zeros) - 1] = '\0';
//    fwrite(zeros, strlen(zeros) * sizeof(char), 1, fich);
//
//}

//void ajouter_anciennte(enseignant ens ){
//    FILE* bit = fopen("bit_anciennete.bin", "rb+");
//    int min,max;
//    char* min_str = malloc(4 * sizeof(char));
//    char *max_str = malloc(4 * sizeof(char));
//    min_str[0]='\0';
//    max_str[0]='\0';
//    fread(min_str,3*sizeof(char),1,bit);
//    min_str[3] = '\0';
//    fseek(bit, sizeof(char), SEEK_CUR);
//    fread(max_str,3*sizeof(char),1,bit);
//    fseek(bit, sizeof(char), SEEK_CUR);
//    max_str[3] = '\0';
//    min=atoi(min_str);
//    max = atoi(max_str);
//    printf("min = %d , max = %d\n", min, max);
//
//}



int main() {
    Buffer* buf = malloc(sizeof(Buffer));
    Buffer* buf2 = malloc(sizeof(Buffer));
    fichier* file ;
    int i=999 ,j=999, univ=999;
    int test=99999;
    int spec=0,anciennete=666;
    srand(time(NULL));
//
//////////    char *testo = malloc(sizeof(char));
//////////    testo[0] = '\0';
//////////    printf("%s", testo);
//////////    goto end;
//////
//    char* index_mat = malloc(17*sizeof(char));
//    creer_index_mat(11111, 99999);
////    modifier_mat(33333, 33, 33, 3, 33,11);
//    chargement_initial(10000);
//    recuperer_mat(33333,&i,&j,&spec,&univ,&anciennete);
//    printf("i= %d , anciennete= %d",i,anciennete);
//    printf(" i= %d , j= %d , spec = %d , univ=%d",i,j,spec,univ);
//    printf(" i = %d et j= %d\n", i, j);
////////    modifier_mat(88888, 4982, 42,3,100);
////////    recuperer_mat(88888,&i,&j,&spec,&univ);
////    printf(" i = %d et j= %d\nspec = %d", i, j,spec);
////////    end:
// PROBLEME 4,5 aussi , faut mieux fare chargement initiale avec moins d'enregistrement
//    enseignant ens=construire_enseignant();
//        ens.specialite =7 ;
//       ens.matricule = "00020";
//       printf("la specialite est : %d\n", ens.specialite);
//        ajouter_index_specialite(ens);
//    printf("\n anciennete!!\n");
    construire_bits_map_anciennete(39);
    construire_bits_map_univ(1, 105);
    FILE *index = fopen("bit_univ.bin", "rb+");
    int min, max;
    recuperer_entete_bin(index,&min,&max);
    printf("min =%d et max = %d",min,max);
////    enseignant ens;
////    ens = construire_enseignant();
//////    ajouter_anciennte(ens);
//////    construire_bits_map_univ(1,105);
////    printf("%d", recuperer_annee(ens.date_recrutement));


}

