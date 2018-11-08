/*
 *  Yapacaklarım
 *  1 - tek yönlü bağlı liste
 *      - sona ekleme fonksiyonu
 *      - yazdirma fonksiyonu
 *      - başa ekleme fonksiyonu
 *      - n. düğümden sonra ekleme fonksiyonu
 *      - verilen sayıdan sonra ekleme fonksiyonu
 *      - verilen düğümden sonra ekleme fonksiyonu
 *      - sondan silme fonksiyonu
 *      - baştan silme fonksiyonu
 *      - n. düğümden sonraki düğümü silme fonksiyonu
 *      - verilen sayının düğümünü silme fonksiyonu
 *      - verilen düğümü silme fonksiyonu
 *  2 - çift yönlü bağlı liste
 *      - sona ekleme fonksiyonu
 *      - yazdirma fonksiyonu
 *      - başa ekleme fonksiyonu
 *      - n. düğümden sonra ekleme fonksiyonu
 *      - verilen sayıdan sonra ekleme fonksiyonu
 *      - verilen düğümden sonra ekleme fonksiyonu
 *      - sondan silme fonksiyonu
 *      - baştan silme fonksiyonu
 *      - n. düğümden sonraki düğümü silme fonksiyonu
 *      - verilen sayının düğümünü silme fonksiyonu
 *      - verilen düğümü silme fonksiyonu
 *  3 - çevrimsel bağlı liste
 *      - sona ekleme fonksiyonu
 *      - başa ekleme fonksiyonu
 *      - n. düğümden sonra ekleme fonksiyonu
 *      - verilen sayıdan sonra ekleme fonksiyonu
 *      - verilen düğümden sonra ekleme fonksiyonu
 *      - sondan silme fonksiyonu
 *      - baştan silme fonksiyonu
 *      - n. düğümden sonraki düğümü silme fonksiyonu
 *      - verilen sayının düğümünü silme fonksiyonu
 *      - verilen düğümü silme fonksiyonu
 *  4 - diğer şeyler
 *      - parametre olarak verilen sayıya sahip düğümü geri döndüren fonksiyon
 */

#include<stdio.h>
#include<stdlib.h>

struct tNode {   // tek yönlü bağlı liste
    int data;
    struct tNode * next;
};

struct cNode {  // çift yönlü bağlı liste
    int data;
    struct cNode * prev;
    struct cNode * next;
};

// fonksiyonların imzaları
void tSonaEkle(struct tNode * , int);
void tYazdir(struct tNode *);
void tTerstenYazdir(struct tNode *);
void tBasaEkle(struct tNode **, int);
void tNdenSonraEkle(struct tNode *, int, int);
void tBsayisindanSonraEkle(struct tNode * , int, int);
void tVerilenDugumdenSonraEkle(struct tNode *, int);
void tSondanSil(struct tNode *);
void tBastanSil(struct tNode **);
void tNdenSonraSil(struct tNode *, int);
void tBsayisininDugumunuSil(struct tNode ** , int );
void tVerilenDugumuSil(struct tNode *, struct tNode *);
void cSonaEkle(struct cNode *, int);
void cYazdir(struct cNode *);
void cBasaEkle(struct cNode **, int);
void cNdenSonraEkle(struct cNode *, int , int);
void cBsayisindanSonraEkle(struct cNode * , int, int);

int main() {
    struct tNode * tHead = (struct tNode *)malloc(sizeof(struct tNode));
    tHead->data = 104;
    tHead->next = NULL;
    tSonaEkle(tHead, 10); tSonaEkle(tHead, 20); tSonaEkle(tHead, 30);
    tYazdir(tHead);
    tBasaEkle(&tHead, -999); // çift yıldızlı fonksiyonlarda & işareti ile değer göndermeye dikkat!!
    tYazdir(tHead);
    tNdenSonraEkle(tHead, 3, 13);
    tYazdir(tHead);
    tNdenSonraEkle(tHead, 6, 16);
    tBsayisindanSonraEkle(tHead, 104, 91);
    tBsayisindanSonraEkle(tHead, -999, 21);
    tBsayisindanSonraEkle(tHead, 16, 88);
    tYazdir(tHead);
    tVerilenDugumdenSonraEkle(tHead->next->next, 7);
    tYazdir(tHead);
    tSondanSil(tHead);
    tYazdir(tHead);
    tYazdir(tHead);
    tBastanSil(&tHead);
    tBastanSil(&tHead);
    tYazdir(tHead);
    tBsayisininDugumunuSil(&tHead, 104); // baş düğümü silmiş oldum
    tYazdir(tHead);
    tBsayisininDugumunuSil(&tHead, 91);
    tYazdir(tHead);
    tBsayisininDugumunuSil(&tHead, 21);
    tYazdir(tHead);
    tVerilenDugumuSil(tHead, tHead->next);
                            // ^ 2. düğümü silmiş oluyoruz
    tYazdir(tHead);

    printf("---- çift yönlü bağlı liste işlemleri ----\n");
    struct cNode * cHead = (struct cNode *)malloc(sizeof(struct cNode));
    cHead->prev = NULL;
    cHead->data = 99;
    cHead->next = NULL;
    cSonaEkle(cHead, 7);
    cSonaEkle(cHead, 8);
    cSonaEkle(cHead, 9);
    cYazdir(cHead);
    cSonaEkle(cHead, 18);
    cYazdir(cHead);
    cBasaEkle(&cHead, -9);
    cYazdir(cHead);
    cBasaEkle(&cHead, -11);
    cYazdir(cHead);
    cNdenSonraEkle(cHead, 3, 1);
    cYazdir(cHead);
    cBsayisindanSonraEkle(cHead, 99, 20);
    cYazdir(cHead);
    cBsayisindanSonraEkle(cHead, 18, 21);
    cYazdir(cHead);
    return 0;
}

// fonksiyonlar

// tek yönlü bağlı liste fonksiyonları başında t olanlar
void tSonaEkle(struct tNode * n, int alinan) {
    struct tNode * newNode = (struct tNode *)malloc(sizeof(struct tNode));
    newNode->data = alinan;
    newNode->next = NULL;
    while(n->next!=NULL) {
        n = n->next;
    }
    n->next = newNode;
}
void tYazdir(struct tNode * n) {  // orginali bu free yi iyice anlamak adına yukarıdakini bozuyorum
    while(n!=NULL){
        printf("%6d", n->data);
        n = n->next;
    }
    printf("\n");
}
void tBasaEkle(struct tNode ** n, int alinan) {
    struct tNode * newNode = (struct tNode *)malloc(sizeof(struct tNode));
    newNode->data = alinan;
    newNode->next = (*n);  // yeni düğümü baş düğüme bağladım 
    (*n) = newNode;       // yeni düğümü baş düğüm yaptım
}
void tNdenSonraEkle(struct tNode * n, int a, int alinan) {
    struct tNode * newNode = (struct tNode *)malloc(sizeof(struct tNode));
    newNode->data = alinan;
    for(int i = 1; i<a; i++) {   // for döngüsünün a sayısı kadar değil a-1 sayısı kadar dönmesini istiyoruz, o yüzden 1 den başlattık
        n = n->next;
    }
    newNode->next = n->next;
    n->next = newNode;
} 
void tBsayisindanSonraEkle( struct tNode * n, int b, int alinan) {
    struct tNode * newNode = (struct tNode *)malloc(sizeof(struct tNode));
    newNode->data = alinan;
    while(n->next!=NULL) {
        if(n->data == b) {
            break;
        }
        n = n->next;
    }
    newNode->next = n->next;
    n->next = newNode;
}
void tVerilenDugumdenSonraEkle(struct tNode * verilenDugum, int alinan) {
    struct tNode * newNode = (struct tNode *)malloc(sizeof(struct tNode));
    newNode->data = alinan;
    newNode->next = verilenDugum->next;
    verilenDugum->next = newNode;
}
void tSondanSil(struct tNode * n) {
    while(n->next->next!=NULL) {  //sonran bir önceki düğümü elde etmeye çalışıyoruz
        n = n->next;
    }
    // artık n sondan bir önceki düğüm
    n->next = NULL;
    free(n->next);
}
void tBastanSil(struct tNode ** n) { // baş düğümde değişiklik yapacağımız için fonksiyona main içerisindeki tHead pointerının ramdeki adresini yollamamız gerekiyor
    free((*n));
    (*n) = (*n)->next;     // yeni baş, önceki baştan hemen sonra gelen düğüm
}
void tNdenSonraSil(struct tNode * n, int a) {
    for(int i = 1; i<a; i++) {
        n = n->next;        
    } // n silmek istediğimiz düğümün bir önündeki düğüm
    struct tNode * silinecekDugum = n->next;  // silinecek düğümün ram adresini "silinecekDugum" ismindeki bir pointerda korudum
    n->next = n->next->next;
    free(silinecekDugum);
}
void tBsayisininDugumunuSil(struct tNode ** n, int b) {
    if((*n)->data == b) {
        // bu blok çalışıyorsa demek ki b harfi head'in datasıymış, head'i silmemiz gerekiyor
        tBastanSil(n);  // tekrar yazmaya üşendim Xd
    } else {
        // silinmesi gereken düğüm baştan farklı bir düğüm
        struct tNode * gezgin = *n;
        struct tNode * gezgin2 = gezgin->next;
        // ^ bağlı listeye ardışık olarak gezecekler
        while(gezgin2->next!=NULL) {
            if(gezgin2->data==b) {
                break;
            }
            gezgin = gezgin2;
            gezgin2 = gezgin2->next;
        }
        // bu satırda artık gezgin2 silmek istediğimiz düğüm, gezgin ise silmek istediğimiz düğümün bir önceki düğüm
        //struct tNode * silinecekDugum = gezgin2;
        gezgin->next = gezgin2->next;
        free(gezgin2);
    }
    // eğer b hiçbir düğümün datasında yoksa en son düğümü siliyor, bu durumun yaşanmaması için döngüden sonraki işlemler bir koşula bağlanabilir, ben bu şekilde bırakıcam
}
void tVerilenDugumuSil(struct tNode * n, struct tNode * silinecekDugum) {
    /*
     *  bu fonksiyonu yazmanın zorluğu verilen düğümün bir önceki düğümüne erişemiyor olmamızdan kaynaklı, bu zorluğu aşmak için silmeyi düşündüğümüz
     *  düğüm ile bağlangıç düğümünü de göndermemiz gerekiyor
     */
    while(n->next!=silinecekDugum) {    
        // ^ silinecek düğümün bir önceki düğümünü elde etmeye çalışıyoruz, döngümüz bu düğümü bulunca duracak
        n = n->next;
    }
    // n bu satırdan itibaren silinecekDugum 'ün bir öncesindeki düğüm
    n->next = silinecekDugum->next;
    free(silinecekDugum);
    // silinecekDugum 'e head'i yollarsak istediğimiz sonucu elde edemeyiz
}
// çift yönlü bağlı liste fonksiyonları başında c olanlar
void cSonaEkle(struct cNode * n, int alinan) {
    struct cNode * newNode = (struct cNode *)malloc(sizeof(struct cNode));
    newNode->data = alinan;
    newNode->next = NULL;
    while(n->next!=NULL) {
        n = n->next;
    }
    n->next = newNode;
    newNode->prev = n;
}
void cYazdir(struct cNode * n) {
    while(n!=NULL) {
        printf("%6d", n->data);
        n = n->next;
    }
    printf("\n");
}
void cBasaEkle(struct cNode **n, int alinan) {
    struct cNode * newNode = (struct cNode *)malloc(sizeof(struct cNode));
    newNode->data = alinan;
    newNode->prev = NULL; // head olacağı için öncesi null
    newNode->next = (*n);
    (*n)->prev = newNode;
    (*n) = newNode;
}
void cNdenSonraEkle(struct cNode * n, int N,  int alinan){
    struct cNode * newNode = (struct cNode *)malloc(sizeof(struct cNode));
    newNode->data = alinan;
    for( int i = 0; i<N-1; i++) {
        n = n->next;
    }
    newNode-> next = n->next;
    n->next = newNode;
    newNode->next->prev = newNode;
    newNode->prev = n;
}
void cBsayisindanSonraEkle( struct cNode * n, int b, int alinan) {
    struct cNode * newNode = (struct cNode *)malloc(sizeof(struct cNode));
    newNode->data = alinan;
    while(n->next!=NULL) {
        if(n->data==b) {
            break;
        }
        n = n->next;
    }
    newNode-> next = n->next;
    n->next = newNode;
    if (newNode->prev!=NULL) {
        newNode->next->prev = newNode;
    }
    newNode->prev = n;
}


