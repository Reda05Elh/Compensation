#ifndef DEF_COMP
#define DEF_COMP

typedef struct mach {
    char name[20];
    float PA;
    float cphi;
    int q;
    float CP;
    float CPG;
}mach;

void Resultat(mach *Machine);
void PuissanceDubatteries(mach *Machine);
void readFromtemp();
void ReplaceByspece(char *buffer ,int n);
void recuperationDesInfos();

#endif
