#include "header.h"//memnggil file header

void createList(list *L) {//buat list
    (*L).first = NULL;//pointer first diisi null
}

int countElement(list L) {//hitung isi list
    int count = 0;
    if(L.first != NULL) {//jika list tidak kosong
        element* flag; // pointer penunjuk elemen
        flag = L.first;//diisi dengan first
        while(flag != NULL) {//loop selama flag tidak null
            count++;//tambah count
            flag = flag->next;//
        }
    }
    return count;//rating kembalian 
}

void addFirst(char judul[], char production[], float rating, list *L) {//tambah diawal
    element *new; // pointer elemen baru
    new = (element*)malloc(sizeof(element));//siapkan elemen baru
    strcpy(new->container.judul, judul);//isi elemen
    strcpy(new->container.production, production);
    new->container.rating=rating;
    if((*L).first == NULL){//jika pointer first null
        new->next=NULL;//maka pointer next element new null
    }
    else{
        new->next = (*L).first; // pointer next elemen baru menunjuk ke elemen milik pointer first
    }
    (*L).first = new; // pointer first diinisialisasi oleh elemen baru
    new = NULL; // mengosongkan pointer baru
}


void addAfter(element* prev, char judul[], char production[], float rating, list *L) {//menambah element seteleah element ;ainya
    element *new;//membaut element baru
    new = (element*)malloc(sizeof(element));//
    strcpy(new->container.judul, judul);//salin rating ke element
    strcpy(new->container.production, production);
    new->container.rating=rating;
    if(prev->next == NULL) {
        // jika elemen baru akan ditambah setelah elemen terakhir
        new->next = NULL;
    } else {
        // jika elemen baru ditambah di tengah2
        // pointer next elemen baru menunjuk ke elemen yg ditunjuk pointer next elemen prev
        new->next = prev->next;
    }
    prev->next = new; // pointer next elemen prev menunjuk ke elemen baru
    new = NULL;
}

/* prosedur menambah 1 elemen di akhir list */
void addLast(char judul[], char production[], float rating, list *L) {
    if((*L).first == NULL) {
        // jika list kosong jalankan prosedur addFirst()
        addFirst(judul, production, rating, L);
    } else {
        // jika list tidak kosong cari elemen terakhir
        element *prev = (*L).first;
        while(prev->next != NULL) {
            prev = prev->next;
        }
        // tambahkan elemen baru setelah elemen terakhir
        // dgn prosedur addAfter()
        addAfter(prev, judul, production, rating, L);
    }
}

/* prosedur menghapus 1 elemen pertama list */
void delFirst(list *L) {
    if((*L).first != NULL) { 
        // jika ada elemen yg dihapus/list tidak kosong
        element *del = (*L).first; // pointer del menunjuk ke elemen pertama
        if(countElement(*L) == 1) {
            // jika elemen hanya 1
            (*L).first = NULL;
        } else {
            // jika elemen > 1
            // pindahkan pointer first ke elemen kedua
            (*L).first = (*L).first->next;
            del->next = NULL; // null kan pointer del next
        }
        free(del); // bebaskan del
    }
}

/* prosedur menghapus 1 elemen setelah elemen tertentu */
void delAfter(element *prev, list *L) {
    element *del = prev->next; // pointer del menunjuk elemen setelah elemen yg ditunjuk pointer prev next
    if(del != NULL) {
        // jika yg ditunjuk ada elemennya
        prev->next = del->next; // pointer prev next menunjuk elemen yg ditunjuk pointer del next
        del->next = NULL; // pointer del dibuat null
        free(del); // elemen del dibebaskan
    }
}

/* prosedur menghapus 1 elemen di akhir list */
void delLast(list *L) {
    if((*L).first != NULL) {
        // jika list ada isinya
        if(countElement(*L) == 1) {
            // jika elemen hanya 1
            delFirst(L);
        } else {
            element *last = (*L).first, *prev;
            while(last->next != NULL) {
                // mencari prev elemen terakhir
                prev = last;
                last = last->next;
            }
            // dihapus dgn prosedur delAfter()
            delAfter(prev, L);
        }
    }
}

/* prosedur menghapus seluruh elemen dalam list */
void delAll(list *L) {
    if(countElement(*L) != 0) {
        int i;
        for (i = countElement(*L); i >= 1; i--) {
            // hapus elemen dari belakang
            delLast(L);
        }
    }
}

/* prosedur mencetak seluruh elemen list */
void printElement(list L) {
    if(L.first != NULL) {
        // jika list ada isinya
        element *flag = L.first; // untuk menunjuk tiap elemen
        int i = 1;
        // printf("\n------------\nList\n============================\nfirst  ->[%p]\n", flag);
        while(flag != NULL) {
            // cetak isi elemen yg ditunjuk pointer flag
            // printf("[%p]%s - %s| [%p]\n", flag, flag->container.judul, flag->container.production, flag->next);
            printf("%s - %s\n", flag->container.judul, flag->container.production);
            flag = flag->next;
            i++;
        }
    } else {
        // jika list kosong
        printf("list kosong\n");
    }
    // printf("============================\n");
}

int stop_strip(char arr[]){
    int i=0;
    while(i<strlen(arr)){
        if(arr[i]=='-'){
            // printf("nah loh\n");
            return 1;
        }
        i++;
    }
    return 0;
}
//---------------------------------------------------------------
void selection_sort_mintomax_title(list *L){
    element *key;
    element *temp;
    key=(*L).first;
    while(key!=NULL){
        temp=key->next;
        while(temp!=NULL){
            if(strcmp(key->container.judul, temp->container.judul)>0){
                swapNode(key, temp);
            }
            temp=temp->next;
        }
        key=key->next;
    }
}
void selection_sort_mintomax_title_v2(list *L){
    element *key;
    element *temp;
    element *before;
    int tukar;
    do{
        tukar = 0;
        key=(*L).first;
        while(key!=NULL){
            temp=key->next;
            while(temp!=NULL){
                // printf("------------!\n");
                // printElement(*L);
                // printf("STATE : before[%p] - key[%p] - temp[%p]\n", before, key, temp);
                if(strcmp(key->container.judul, temp->container.judul)>0){
                    // printf("TUKAR | %s - %s\n", key->container.judul, temp->container.judul);
                    if(key==(*L).first){
                        (*L).first=temp;
                        before=(*L).first;
                    }
                    else{
                        before->next=temp;
                    }
                    key->next=temp->next;
                    temp->next=key;
                    before=temp;
                    temp=key;

                    tukar=1;
                }
                else{
                    before=key;
                    key=key->next;
                    temp=key;
                }
                temp=temp->next;
            }
            key=key->next;
        }
    }while(tukar==1);
}
//---------------------------------------------------------------
void selection_sort_maxtomin_title(list *L){
    element *key;
    element *temp;
    key=(*L).first;
    while(key!=NULL){
        temp=key->next;
        while(temp!=NULL){
            if(strcmp(key->container.judul, temp->container.judul)<0){
                swapNode(key, temp);
            }
            temp=temp->next;
        }
        key=key->next;
    }
}
void selection_sort_maxtomin_title_v2(list *L){
    element *key;
    element *temp;
    element *before;
    int tukar;
    do{
        tukar = 0;
        key=(*L).first;
        while(key!=NULL){
            temp=key->next;
            while(temp!=NULL){
                // printf("------------!\n");
                // printElement(*L);
                // printf("STATE : before[%p] - key[%p] - temp[%p]\n", before, key, temp);
                if(strcmp(key->container.judul, temp->container.judul)<0){
                    // swapNode(key, temp);
                    // printf("TUKAR | %s - %s\n", key->container.judul, temp->container.judul);
                    if(key==(*L).first){
                        (*L).first=temp;
                        before=(*L).first;
                    }
                    else{
                        before->next=temp;
                    }
                    key->next=temp->next;
                    temp->next=key;
                    before=temp;
                    temp=key;

                    tukar=1;
                }
                else{
                    before=key;
                    key=key->next;
                    temp=key;
                }
                temp=temp->next;
            }
            key=key->next;
        }
    }while(tukar==1);
}
//---------------------------------------------------------------
void selection_sort_mintomax_rate(list *L){
    element *key;
    element *temp;
    key=(*L).first;
    while(key!=NULL){
        temp=key->next;
        while(temp!=NULL){
            if(key->container.rating > temp->container.rating){
                swapNode(key, temp);
            }
            temp=temp->next;
        }
        key=key->next;
    }
}
void selection_sort_mintomax_rate_v2(list *L){
    element *key;
    element *temp;
    element *before;
    int tukar;
    do{
        tukar = 0;
        key=(*L).first;
        while(key!=NULL){
            temp=key->next;
            while(temp!=NULL){
                // printf("------------!\n");
                // printElement(*L);
                // printf("STATE : before[%p] - key[%p] - temp[%p]\n", before, key, temp);
                if(key->container.rating > temp->container.rating){
                    // swapNode(key, temp);
                    // printf("TUKAR | %s - %s\n", key->container.judul, temp->container.judul);
                    if(key==(*L).first){
                        (*L).first=temp;
                        before=(*L).first;
                    }
                    else{
                        before->next=temp;
                    }
                    key->next=temp->next;
                    temp->next=key;
                    before=temp;
                    temp=key;

                    tukar=1;
                }
                else{
                    before=key;
                    key=key->next;
                    temp=key;
                }
                temp=temp->next;
            }
            key=key->next;
        }
    }while(tukar==1);
}
//---------------------------------------------------------------
void selection_sort_maxtomin_rate(list *L){
    element *key;
    element *temp;
    key=(*L).first;
    while(key!=NULL){
        temp=key->next;
        while(temp!=NULL){
            if(key->container.rating < temp->container.rating){
                swapNode(key, temp);
            }
            temp=temp->next;
        }
        key=key->next;
    }
}
void selection_sort_maxtomin_rate_v2(list *L){
    element *key;
    element *temp;
    element *before;
    int tukar;
    do{
        tukar = 0;
        key=(*L).first;
        while(key!=NULL){
            temp=key->next;
            while(temp!=NULL){
                // printf("------------!\n");
                // printElement(*L);
                // printf("STATE : before[%p] - key[%p] - temp[%p]\n", before, key, temp);
                if(key->container.rating < temp->container.rating){
                    // swapNode(key, temp);
                    // printf("TUKAR | %s - %s\n", key->container.judul, temp->container.judul);
                    if(key==(*L).first){
                        (*L).first=temp;
                        before=(*L).first;
                    }
                    else{
                        before->next=temp;
                    }
                    key->next=temp->next;
                    temp->next=key;
                    before=temp;
                    temp=key;

                    tukar=1;
                }
                else{
                    before=key;
                    key=key->next;
                    temp=key;
                }
                temp=temp->next;
            }
            key=key->next;
        }
    }while(tukar==1);
}
//---------------------------------------------------------------

void swapNode(element *x, element *y){
    char tempstring[50];
    strcpy(tempstring, x->container.judul);
    strcpy(x->container.judul, y->container.judul);
    strcpy(y->container.judul, tempstring);

    strcpy(tempstring, x->container.production);
    strcpy(x->container.production, y->container.production);
    strcpy(y->container.production, tempstring);

    float temprate = x->container.rating;
    x->container.rating = y->container.rating;
    y->container.rating = temprate;
}

// void show_sort(list *L){
//     element *flag, *temp, *before;
//     int n=countElement(*L), i, tukar;
//     do{
//         tukar=0;
//         flag=(*L).first;
//         for(i=0;i<1; i++){
//             printf("loop ke -%d=========\n", i+1);
//             temp=flag->next;
//             if(strcmp(flag->container.judul, temp->container.judul)<0){
//                 printf("tukar %s - %s\n", flag->container.judul, temp->container.judul);
//                 printf("State : before[%p] || flag[%p] || temp[%p]\n", before, flag, temp);
//                 if(flag==(*L).first){
//                     flag->next=temp->next;
//                     temp->next=flag;
//                     (*L).first=temp;
//                     before=temp;
//                     // printElement(*L);
//                 }
//                 else{
//                     flag->next=temp->next;
//                     before->next=temp;
//                     temp->next=flag;
//                     before=temp;
//                 }
//                 tukar=1;
//             }
//             else{
//                 flag=flag->next;
//             }
//             printElement(*L);
//             printf("[%d]-------------------\n", n);
//         }
//         printf("ada pertukaran=====================\n");
//     }while(tukar==1);


//     // flag=(*L).first;
//     // temp=flag->next;
//     // flag->next=temp->next;
//     // temp->next=flag;
//     // (*L).first=temp;
//     // before=temp;
//     // printElement(*L);

//     // printf("-------------------\n");
//     // temp=flag->next;
//     // printf("--- before[%p] || flag[%p] || temp[%p]\n", before, flag, temp);
//     // flag->next=temp->next;
//     // before->next=temp;
//     // temp->next=flag;
//     // before=temp;
//     // printElement(*L);



//     // printf("-------------------\n");
//     // temp=flag->next;
//     // printf("--- before[%p] || flag[%p] || temp[%p]\n", before, flag, temp);
//     // flag->next=temp->next;
//     // before->next=temp;
//     // temp->next=flag;
//     // before=temp;
//     // printElement(*L);

//     // printf("-------------------\n");
//     // temp=flag->next;
//     // printf("--- before[%p] || flag[%p] || temp[%p]\n", before, flag, temp);
//     // flag->next=temp->next;
//     // before->next=temp;
//     // temp->next=flag;
//     // before=temp;
//     // printElement(*L);
//     // printf("==============================\n");

//     // flag=(*L).first;
//     // temp=flag->next;
//     // flag->next=temp->next;
//     // (*L).first=temp;
//     // temp->next=flag;
//     // before=temp;
//     // printElement(*L);

//     // printf("-------------------\n");
//     // temp=flag->next;
//     // printf("--- before[%p] || flag[%p] || temp[%p]\n", before, flag, temp);
//     // flag->next=temp->next;
//     // before->next=temp;
//     // temp->next=flag;
//     // before=temp;
//     // printElement(*L);

//     // printf("-------------------\n");
//     // temp=flag->next;
//     // printf("--- before[%p] || flag[%p] || temp[%p]\n", before, flag, temp);
//     // flag->next=temp->next;
//     // before->next=temp;
//     // temp->next=flag;
//     // before=temp;
//     // printElement(*L);

//     // printf("-------------------\n");
//     // temp=flag->next;
//     // printf("--- before[%p] || flag[%p] || temp[%p]\n", before, flag, temp);
//     // flag->next=temp->next;
//     // before->next=temp;
//     // temp->next=flag;
//     // before=temp;
//     // printElement(*L);

// }