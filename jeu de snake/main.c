/*____________________________________FARES Amir G02______________________________________*/
/*_________________________________This my first project__________________________________*/
#include <stdio.h>
#include <stdlib.h>
/*________________________________________________________________________________________*/
struct element
{
    int x,y;
    struct element*suiv;
};
typedef struct element element;
typedef struct element* liste;
/*________________________________________________________________________________________*/
int main()
{
    char m[10][10];
/*Remplissage de la matrice_______________________________________________________________*/
    for(int l=0;l<10;l++)
    {
        for(int c=0;c<10;c++)
        {
            m[l][c]='*';
        }
    }
/*affichage de la matrice_________________________________________________________________*/
    for(int l=0;l<10;l++)
    {
        printf("                            ");
        for(int c=0;c<10;c++)
        {
            printf("%c ",m[l][c]);
        }
        printf("\n");
    }
/*creation de snake_______________________________________________________________________*/
    liste creation(liste snake)
	{
		int n, i;
		liste p = NULL;
		liste q = NULL;
        p=malloc(sizeof(element));
        printf("combien de maillon du snake (entre 2 et 9) : ");
		scanf("%d",&n);getchar();
		while((n<2)||(n>9))
        {
            printf("Doit etre le nombre de maillon entre 2 et 9 : ");
            scanf("%d",&n);getchar();
        }
		printf("Donnez les coordonnee de la tete du snake :\n");
		scanf("%d",&p->x);getchar();
		scanf("%d",&p->y);getchar();
		while((p->x>9)||(p->x<0)||(p->y>9)||(p->y<0))
        {
            printf("---> Erreur ! Les coordonnee entre 0 et 9 :\n");
            scanf("%d",&p->x);getchar();
            scanf("%d",&p->y);getchar();
        }
		int l=p->x;
		int c=p->y;
		snake = p;
		liste pt=p;
		for (i = 1; i < n; i++)
		{
            printf("Donnez les coordonnee de la %deme maillon du snake :\n",i+1);
                    q=malloc(sizeof(element));
			scanf("%d",&l);getchar();
			scanf("%d",&c);getchar();
			while((l>9)||(l<0)||(c>9)||(c<0))
        {
            printf("---> Erreur ! Les coordonnee entre 0 et 9 :\n");
            scanf("%d",&l);getchar();
            scanf("%d",&c);getchar();
        }
    while((l>pt->x+1)||(l<pt->x-1)||(c>pt->y+1)||(c<pt->y-1)||((l==pt->x)&&(c==pt->y)))
            {
                printf("Le snake doit etre adjacente (donnez une autre coordonnee) : \n");
                scanf("%d",&l);getchar();
                scanf("%d",&c);getchar();
            }
			q->x=l;
			q->y=c;
			p->suiv = q;
			p=q;
			pt=q;
		}
		p->suiv = NULL;
		return(snake);
	}
    liste snake=NULL;
    snake=creation(snake);
/*creation de snake dans le matrice_______________________________________________________*/
    liste p;
    int l=0;
    int c=0;
    while(l<10)
        {
            c=0;
            while(c<10)
            {
                p=snake;
                while(p!=NULL)
                {
                    if(((p->y)==l)&&((p->x)==c)&&(p==snake))
                    {
                        m[l][c]='O';
                    }
                    if(((p->y)==l)&&((p->x)==c)&&(p!=snake))
                    {
                        m[l][c]='o';
                    }
                    p=p->suiv;
                }
                c++;
            }
            l++;
        }
/*affichage de la matrice_________________________________________________________________*/
    for(int l=0;l<10;l++)
    {
        printf("                            ");
        for(int c=0;c<10;c++)
        {
            printf("%c ",m[l][c]);
        }
        printf("\n");
    }
/*mouvement de snake______________________________________________________________________*/
printf("Donnez une derection (nord,sud,est,ouest 'en minuscule')pour Deplacer le snake :");
    char rep[5];int sw=0;
    scanf("%c",&rep[0]);getchar();
    int a,b;
    p=snake;
    switch(rep[0])
    {
        case'n':
            {
                if((p->y)==0)
                {
                    a=9;
                }
                else
                {
                    a=(p->y)-1;
                }
                b=(p->x);
            }break;
        case's':
            {
                if((p->y)==9)
                {
                    a=0;
                }
                else
                {
                    a=(p->y)+1;
                }
                b=(p->x);
            }break;
        case'e':
            {
                if((p->x)==9)
                {
                    b=0;
                }
                else
                {
                    b=(p->x)+1;
                }
                a=(p->y);
            }break;
        case'o':
            {
                if((p->x)==0)
                {
                    b=9;
                }
                else
                {
                    b=(p->x)-1;
                }
                a=(p->y);
            }break;
        default:
            {
                printf("\n---> Erreur ! n'est pas (nord ou sud ou est ou ouest) \n");
                sw=1;
            }break;
            }
    liste mouvement(liste snake,int a,int b)
        {
/*suprime de la derniere maillon__________________________________________________________*/
                liste p,q;
                p=snake;
                while((p->suiv)!=NULL)
                {
                    q=p;
                    p=p->suiv;
                }
                q->suiv=NULL;
                free(p);
/*creation de la premiere maillon_________________________________________________________*/
                q=malloc(sizeof(element));
                //
                q->y=a;
                q->x=b;
                //
                q->suiv=snake;
                snake=q;
            //
            return(snake);
        }
    snake=mouvement(snake,a,b);
/*recreation de snake dans la matrice_____________________________________________________*/
/*Remplissage de la matrice_______________________________________________________________*/
    for(int l=0;l<10;l++)
    {
        for(int c=0;c<10;c++)
        {
            m[l][c]='*';
        }
    }
/*creation de snake dans la matrice_______________________________________________________*/
    l=0;
    c=0;
    while(l<10)
        {
            c=0;
            while(c<10)
            {
                p=snake;
                while(p!=NULL)
                {
                    if(((p->y)==l)&&((p->x)==c)&&(p==snake))
                    {
                        m[l][c]='O';
                    }
                    if(((p->y)==l)&&((p->x)==c)&&(p!=snake))
                    {
                        m[l][c]='o';
                    }
                    p=p->suiv;
                }
                c++;
            }
            l++;
        }
/*affichage de la matrice_________________________________________________________________*/
    if(sw==0)
    {
        for(int l=0;l<10;l++)
        {
            printf("                            ");
            for(int c=0;c<10;c++)
            {
                printf("%c ",m[l][c]);
            }
            printf("\n");
        }
    }
    return 0;
}
