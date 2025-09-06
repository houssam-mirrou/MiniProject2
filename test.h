#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verif_adress(char adress[]){
    char d[10][30] = {
        "@gmail.com",
        "@hotmail.com",
        "@hotmail.fr",
        "@live.com",
        "@yahoo.com"
    };
    int i=0;
    int j=0;
    int n = strlen(adress);
    int same = 0;
    for(i = 0;i<5;i++){
        int m = strlen(d[i]);
        int k = n-m;
        if(k<0){
            continue;
        }
        same = 1;
        for(j=0;j<m;j++){
            if(adress[k] != d[i][j]){
                same = 0;
                break;
            }
            k++;
        }
        if(same == 1){
            return 1;
        }
    }
    return 0;
}
