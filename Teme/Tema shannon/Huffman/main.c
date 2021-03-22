#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_H 100 //inaltimea maxima a arborelui Huffman

struct NodMinimHeap
{
    char info;
    unsigned proc;
    struct NodMinimHeap *st,*dr;
};

struct MinimHeap
{
    unsigned dim;
    unsigned capacitate;
    struct NodMinimHeap **a;
};

struct NodMinimHeap* NodNou(char info, unsigned proc)
{
    struct NodMinimHeap* aux = (struct NodMinimHeap*)malloc(sizeof(struct NodMinimHeap));
    aux->st = aux->dr = NULL;
    aux->info = info;
    aux->proc = proc;

    return aux;
};

struct MinimHeap* creareHeap(unsigned capacitate)
{
    struct MinimHeap* minH = (struct MinimHeap*)malloc(sizeof(struct MinimHeap));
    minH->dim = 0;
    minH->capacitate = capacitate;
    minH->a = (struct NodMinimHeap**)malloc(minH->capacitate * sizeof(struct NodMinimHeap*));

    return minH;
};

void swapminHNod(struct NodMinimHeap** b, struct NodMinimHeap** c)
{
    struct NodMinimHeap* temp = *b;
    *b = *c;
    *c = temp;
}

void transformMinHeap(struct MinimHeap* minH, int index)
{
    int mini = index;
    int stanga = 2*index + 1;
    int dreapta = 2*index + 2;
    if (stanga < minH->dim && minH->a[stanga]->proc < minH->a[mini]->proc)
        mini = stanga;
    if (dreapta < minH->dim && minH->a[dreapta]->proc < minH->a[mini]->proc)
        mini = dreapta;
    if (mini != index)
        {
            swapminHNod(&minH->a[mini],&minH->a[index]);
            transformMinHeap(minH,mini);
        }
}

int edim1(struct MinimHeap* minH)
{
    return (minH->dim == 1);
}

struct NodMinimHeap* extragemin(struct MinimHeap* minH)
{
    struct NodMinimHeap* aux = minH->a[0];
    minH->a[0] = minH->a[minH->dim - 1];
    --minH->dim;
    transformMinHeap(minH,0);

    return aux;
};

void adaugare(struct MinimHeap* minH, struct NodMinimHeap* nodminH)
{
    int i;
    ++minH->dim;
    i = minH->dim - 1;
    while (i && nodminH->proc < minH->a[(i-1)/2]->proc)
        {
            minH->a[i] = minH->a[(i-1)/2];
            i = (i-1)/2;
        }
    minH->a[i] = nodminH;
}

void construiesteMinHeap(struct MinimHeap* minH)
{
    int n = minH->dim - 1;
    int i;
    for (i=(n-1)/2;i>=0;--i)
        transformMinHeap(minH,i);
}

void afisare(int a[],int n)
{
    int i;
    for (i=0;i<n;++i)
        printf("%d",a[i]);
    printf("\n");
}

int frunza(struct NodMinimHeap* rad)
{
    return !(rad->st) && !(rad->dr);
}

struct MinimHeap* asamblareMinHeap(char info[],int proc[],int dim)
{
    int i;
    struct MinimHeap* minH = creareHeap(dim);
    for (i=0;i<dim;++i)
        minH->a[i] = NodNou(info[i],proc[i]);
    minH->dim = dim;
    construiesteMinHeap(minH);

    return minH;
};

struct NodMinimHeap* creareArbHuffman(char info[],int proc[],int dim)
{
    struct NodMinimHeap *sth,*drh,*vf;
    struct MinimHeap* minH = asamblareMinHeap(info,proc,dim);
    while(!edim1(minH))
        {
            sth = extragemin(minH);
            drh = extragemin(minH);
            //vom considera ca valoare pentru nodurile interne '_', neutilizate
            vf = NodNou('_',sth->proc + drh->proc);
            vf->st = sth;
            vf->dr = drh;
            adaugare(minH,vf);
        }
    return extragemin(minH);
};

void afiscoduri(struct NodMinimHeap* rad, int a[],int vf)
{
    if (rad->st)
        {
            a[vf] = 0;
            afiscoduri(rad->st, a, vf+1);
        }
    if (rad->dr)
        {
            a[vf] = 1;
            afiscoduri(rad->dr, a, vf+1);
        }
    if (frunza(rad))
        {
            printf("%c: ", rad->info);
            afisare(a,vf);
        }
}

void coduriHuff(char info[], int proc[], int dim)
{
    int a[MAX_TREE_H], vf = 0;
    struct NodMinimHeap* rad = creareArbHuffman(info,proc,dim);
    afiscoduri(rad,a,vf);
}

int main()
{
    int lungimesir,i;
    char *sir;
    int *vecproc;
    printf("Dati dimensiunea sirului de caractere: ");
    scanf("%d",&lungimesir);
    sir = (char*)malloc(lungimesir*sizeof(char));
    vecproc = (int*)malloc(lungimesir*sizeof(int));
    printf("Dati sirul de caractere pentru arborele Huffman: ");
    scanf("%s",sir);
    printf("Dati vectorul de procente pentru arborele Huffman: ");
    printf("\n");
    for(i=0;i<lungimesir;i++)
        {
            printf("vecproc[%d]=",i+1);
            scanf("%d",&vecproc[i]);
        }
    coduriHuff(sir,vecproc,lungimesir);

    return 0;
}
