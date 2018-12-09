#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");
    int lines=0;
    char *ch;

    while(!feof(fp))
    {
      ch = fgetc(fp);
      if(ch == '\n')
      {
        lines++;
      }
    }
    int x_pos[lines];
    int y_pos[lines];
    int label[lines];
    int x_pos_tmp=0;
    int y_pos_tmp=0;
    int line=0;
    int kk=lines;
    int nn;

    int max_x=0;
    int max_y=0;

    rewind(fp);
    while(!feof(fp)){
        fscanf(fp, "%d,", &x_pos_tmp);
        fscanf(fp, "%d\n",&y_pos_tmp);
        x_pos[line]=x_pos_tmp;
        y_pos[line]=y_pos_tmp;
        label[line]=line;
        if (x_pos_tmp>max_x) max_x=x_pos_tmp;
        if (y_pos_tmp>max_y) max_y=y_pos_tmp;
        line++;
        printf("%d, %d\n",x_pos[line-1],y_pos[line-1]);
    }

    int loc_arr[max_x+1][max_y+1];
    kk=max_x+1;
    while (kk--){
        nn=max_y+1;
        while (nn--){
            loc_arr[kk][nn]=0;
        }
    }

    kk=lines;
    while(kk--){
        printf("%d\n",label[kk]);
        loc_arr[x_pos[kk]][y_pos[kk]]=label[kk];
        printf("%d, %d\n",x_pos[kk],y_pos[kk]);
        printf("%d\n",loc_arr[x_pos[kk]][y_pos[kk]]);

    }
    nn=0;
    kk=0;
    printf("%d\n",max_x);
    printf("%d\n",max_y);

    bool all_filled=false;

    int loc_arr_tmp[max_x+1][max_y+1];
    int aa=0;

    while (!all_filled){
        aa=lines;
        nn=0;
        while(nn<max_y){
            kk=0;
            while(kk<max_x){
                loc_arr_tmp[kk][nn]=loc_arr[kk][nn];
                kk++;
            }
            printf("\n");
            nn++;
        }

        while(nn<max_y){
            kk=0;
            while(kk<max_x){
                loc_arr_tmp[kk][nn]=loc_arr[kk][nn];
                if ((loc_arr[kk][nn]!=0)&&(loc_arr[kk][nn+1]==0))


                kk++;
            }
            printf("\n");
            nn++;
        }
        while(aa--){
            printf("%d\n",label[kk]);
            loc_arr[x_pos[kk]][y_pos[kk]]=label[kk];
            printf("%d, %d\n",x_pos[kk],y_pos[kk]);
            printf("%d\n",loc_arr[x_pos[kk]][y_pos[kk]]);
            if (loc_arr)
        }
    }






//
//    fgets(buff, 255, (FILE*)fp);
//    printf("2: %s\n", buff );
//
//    fgets(buff, 255, (FILE*)fp);
//    printf("3: %s\n", buff );
//    fclose(fp);
//   // printf() displays the string inside quotation
//   printf("Hello, World!");
   return 0;
}
