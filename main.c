#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include "COMP.h"

float s ;

int main()
{
    s = 0 ;
    remove("Resultat.csv");
    rename("fichier a remplir.csv","test.txt");
    recuperationDesInfos();
    remove("temp.txt");
    rename("test2.txt","Resultat.csv");
    rename("test.txt","fichier a remplir.csv");

}

void recuperationDesInfos(){
    FILE* ptr = NULL;
    char buffer[250] = {0};
    ptr = fopen("test.txt","r");
    int i=0;
    char neme[10];
    if (ptr != NULL) {
        while((fgets(buffer,250,ptr)!= NULL)){
            i++;
            if (i>1){
            ReplaceByspece(buffer,strlen(buffer));
            }}

        fclose(ptr);
    }
    readFromtemp();

}

void ReplaceByspece(char *buffer ,int n)
{
    FILE* ptr = NULL;
    ptr=fopen("temp.txt","a");
    int i;
    for (i=0;i<n;i++){
        if (buffer[i]==';')buffer[i]=' ';
        if (buffer[i]==',')buffer[i]='.';
    }
    if(ptr!=NULL){
        fprintf(ptr,"%s",buffer);
        fclose(ptr);}
    }


void readFromtemp(){
    mach Machine;
    FILE* ptr = NULL;
    ptr = fopen("temp.txt","r");
    if (ptr != NULL){

    while((fscanf(ptr,"%s %f %f %d",Machine.name,&Machine.PA,&Machine.cphi,&Machine.q)!=EOF)){
            PuissanceDubatteries(&Machine);
            Resultat(&Machine);
    }
    fclose(ptr);}
    ptr = fopen("test2.txt","a");
    fprintf(ptr,"\n;;;;; %.0f",s);
    fclose(ptr);
    }


void PuissanceDubatteries(mach *Machine){
    float t1,t2;
    int x;
    x = 3.14159265359/180;
    t1 = tan((acos(Machine->cphi)));
    t2 = tan((acos(0.97)));
    Machine->CP = -Machine->PA*(t2-t1);
    Machine->CPG = Machine->CP * Machine->q;
        s = s + Machine->CPG;
}

void Resultat(mach *Machine){
    FILE* ptr=NULL;
    static int i=0;
    ptr = fopen("test2.txt","a");
    if(ptr != NULL){
        if (i==0)fprintf(ptr,"Machine;Puissance Active (KVA) ;Facteur de puissance ;Quantite;Puissance du batterie;Compensation par groupe");
        fprintf(ptr,"\n%s;%.3f;%.3f;%d;%.0f;%.1f",Machine->name,Machine->PA,Machine->cphi,Machine->q,Machine->CP,Machine->CPG);
        i++;
        fclose(ptr);
    }}


