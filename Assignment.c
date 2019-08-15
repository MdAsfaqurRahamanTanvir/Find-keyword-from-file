#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fp,*fk,*fl;
    char s[1000],m[20],l[20];
    int i,n,j,r=0,p=0,o,q;
    fp=fopen("program.txt","r");
    fl=fopen("list.txt","a");
    while(1)
    {
        r++;
        fgets(s,sizeof(s),fp);
        n=strlen(s);
        for(i=0 ; i<n ; i++)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                m[p]=s[i];
                p++;
            }
            else
            {
                q=strlen(m);
                if(q>0)
                {
                    fk=fopen("keyword.txt","r");
                    while(1)
                    {
                        fscanf(fk,"%s",l);
                        o=strcmp(m,l);
                        if(o==0)
                        {
                            printf("line: %d  keyword: %s \n",r,m);
                            fprintf(fl,"line: %d  keyword: %s \n",r,m);
                            break;
                        }
                        if(feof(fk))
                        {
                            break;
                        }
                    }
                    fclose(fk);
                    for(j=0 ; j<q ; j++)
                    {
                        m[j]='\0';
                    }
                }
                p=0;
            }
        }


        if(feof(fp))
            break;

    }
    fclose(fp);
    fclose(fl);
    return 0;
}
