#include "header.h"

int main(){
    // deklarasi variable
    list L;
    char judul[50], production[50];
    float rating;
    int i, stop=0;
    char sort_menu[20], order[10];

    createList(&L); //--------------------------------------> buat kerangka list L
    while(stop==0){
        scanf("%s", judul);
        if(stop_strip(judul)==1){
            stop=1;
        }
        else{
            scanf("%s%f", production, &rating);
            addFirst(judul, production, rating, &L); //
        }
    };
    scanf("%s%s", sort_menu, order);

    if(strcmp(sort_menu, "judul")==0){
        if(strcmp(order, "asc")==0){
            selection_sort_mintomax_title_v2(&L);
        }
        else if(strcmp(order, "desc")==0){
            selection_sort_maxtomin_title_v2(&L);
        }
    }
    else if(strcmp(sort_menu, "rating")==0){
        if(strcmp(order, "asc")==0){
            selection_sort_mintomax_rate_v2(&L);
        }
        else if(strcmp(order, "desc")==0){
            selection_sort_maxtomin_rate_v2(&L);
        }
    }
    // printf("--------------\n");
    printElement(L);
    return 0;
}