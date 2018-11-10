/*
 *  Yapacaklarım
 *  (+ lar yaptıklarım)
 *  1 - tek yönlü bağlı liste
 *      + sona ekleme fonksiyonu
 *      + yazdirma fonksiyonu
 *      + başa ekleme fonksiyonu
 *      + n. düğümden sonra ekleme fonksiyonu
 *      + verilen sayıdan sonra ekleme fonksiyonu
 *      + verilen düğümden sonra ekleme fonksiyonu
 *      + sondan silme fonksiyonu
 *      + baştan silme fonksiyonu
 *      + n. düğümden sonraki düğümü silme fonksiyonu
 *      + verilen sayının düğümünü silme fonksiyonu
 *      + verilen düğümü silme fonksiyonu
 *      - son düğümü geriye döndüren fonksiyon
 *  2 - çift yönlü bağlı liste
 *      + sona ekleme fonksiyonu
 *      + yazdirma fonksiyonu
 *      + başa ekleme fonksiyonu
 *      + n. düğümden sonra ekleme fonksiyonu
 *      + verilen sayıdan sonra ekleme fonksiyonu
 *      + verilen düğümden sonra ekleme fonksiyonu
 *      + sondan silme fonksiyonu
 *      + baştan silme fonksiyonu
 *      + n. düğümü silen fonksiyon
 *      + verilen sayının düğümünü silme fonksiyonu
 *      + verilen düğümü silme fonksiyonu
 *      + son düğümü geriye döndüren fonksiyon
 *  3 - çevrimsel bağlı liste
 *      + sona ekleme fonksiyonu
 *      + yazdirma fonksiyonu
 *      + başa ekleme fonksiyonu
 *      - n. düğümden sonra ekleme fonksiyonu
 *      - verilen sayıdan sonra ekleme fonksiyonu
 *      - verilen düğümden sonra ekleme fonksiyonu
 *      - sondan silme fonksiyonu
 *      - baştan silme fonksiyonu
 *      - n. düğümden sonraki düğümü silme fonksiyonu
 *      - verilen sayının düğümünü silme fonksiyonu
 *      - verilen düğümü silme fonksiyonu
 *      - son düğümü geriye döndüren fonksiyon
 *  4 - diğer şeyler
 *      - parametre olarak verilen sayıya sahip düğümü geri döndüren fonksiyon
 *      - parametre olarak verilen iki düğümün yerlerini değiştiren fonksiyon
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
void cVerilenDugumdenSonraEkle(struct cNode *, int);
void cSondanSil(struct cNode *);
void cBastanSil(struct cNode **);
void cNdugumuSil(struct cNode * , int);
void cBsayisininDugumunuSil(struct cNode ** , int);
void cVerilenDugumuSil(struct cNode *);
void cevSonaEkle(struct tNode *, int);
void cevYazdir(struct tNode *);
void cevBasaEkle(struct tNode **, int);
/*
 *  boşluk
 */
struct cNode * cSonDugumuVer(struct cNode *);

int main() {
    struct tNode * first = (struct tNode *)malloc(sizeof(struct tNode));
    first->next = first;
    first->data = 9;
    // ^ next'i kendisine bağlı potansiyel bir çevrimsel bağlı liste
    
    cevSonaEkle(first, 100);
    cevYazdir(first);
    cevSonaEkle(first, 101);
    cevYazdir(first);
    cevSonaEkle(first, -109);
    cevYazdir(first);
    cevBasaEkle(&first, 1);
    cevYazdir(first);

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
void tYazdir(struct tNode * n) {
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
void cVerilenDugumdenSonraEkle(struct cNode * verilenDugum, int alinan) {
    struct cNode * newNode = (struct cNode *)malloc(sizeof(struct cNode));
    newNode->data = alinan;
    newNode->prev = verilenDugum;
    newNode->next = verilenDugum->next;
    if(verilenDugum->next!=NULL) {  // son düğümün verilmesi durumunda, son düğümün next'i null a eşit, ve NULL 'ın prev i olmayacağı için burada patlar, if patlamaması için
        newNode->next->prev = newNode;
    } else {
        verilenDugum->next = newNode;
    }
}
void cSondanSil(struct cNode * n) {
    while(n->next!=NULL) {
        n = n->next;
    }
    n->prev->next = NULL;
    free(n);
}
void cBastanSil(struct cNode **n) {
    (*n) = (*n)->next;
    // artık yeni baş, eski baştan sonraki düğüm
    free((*n)->prev);  //yeni baş'ın previ eski başı verecek
    (*n)->prev = NULL;
}
void cNdugumuSil(struct cNode * n, int N) {
    if(N==1) {
        printf("Bu fonksiyon ile baş düğümü silemezsiniz !\n");
        return;
    }
    for(int i = 1; i<N; i++) {
        n = n->next;
    }
    n->prev->next = n->next;
    if(n->next!=NULL) {     
        n->next->prev = n->prev;  // NULL->prev olamayacağı için bu kontrolü yazmazsak program burada patlar
    }
    free(n);
}
void cBsayisininDugumunuSil(struct cNode ** n, int b) {
    int arananSayiBulunduMu = 0;  // aranan sayının düğümlerin datasında olmama ihtimali karşın
    if((*n)->data==b) {
        // head silinmek isteniyor
        (*n) = (*n)->next;
        free((*n)->prev);
        (*n)->prev = NULL;
    } else {
        // baştan farklı bir düğüm silinmek isteniyor
        struct cNode * gezgin = (*n);  // çift yıldız kullanılmış fonksiyonlarda eğer başı (*n) şeklinde gezdirirsek baş düğümü kaybederiz, o yüzden çift yıldız kullanılmış
                                                                                    // fonksiyonlarda baş düğümü gezgin bir pointer'a kopyaladıktan sonra, bu gezgin pointer
                                                                                    //  ı gezdirmek gerekir
        while(gezgin->next!=NULL) {
            gezgin = gezgin->next;
            if(gezgin->data==b) {
                arananSayiBulunduMu = 1;
                break;
            }
        }
        // bu satırdan itibaren gezgin silmek istediğimiz düğüm ya da son düğüm, kontrol edelim
        if(arananSayiBulunduMu==0) {
            printf("! silmek istediğiniz sayı bu düğümlerin datalarında bulunmuyor!\nHerhangi bir silme işlemi gerçekleşmedi\n");
            return; // fonksiyondan çıkmak için
        }
        // fonksiyondan çıkılmadıysa bu satırdan itibaren gezgin düğümü silinmek isteyen düğüm
        gezgin->prev->next = gezgin->next;
        if(gezgin->next!=NULL) {   // silmek istediğimiz düğümün son düğüm olma ihtimaline karşı, bunun sebebini yukarıdaki silme fonksiyonunda yazdım
            gezgin->next->prev = gezgin->prev;
        }
        free(gezgin);
    }
}

void cVerilenDugumuSil(struct cNode * silinecekDugum) {
    if(silinecekDugum->prev==NULL) {
        printf("! Bu fonksiyon ile baş düğümü silemezsiniz !\n");
        return;
    }
    silinecekDugum->prev->next = silinecekDugum->next;
    if(silinecekDugum->next!=NULL) {
        silinecekDugum->next->prev = silinecekDugum->prev;
    }
    free(silinecekDugum);
}


struct cNode * cSonDugumuVer(struct cNode * n) { 
    // ^ bu fonksiyona head'i vericez bize son düğümü dönecek
    while(n->next!=NULL) {
        n = n->next;
    }
    // n bu satırdan itibaren son düğüm
    return n;  // geriye döndürüyoruz
}

// çevrimsel tek yönlü bağlı liste fonksiyonları başında cev olanlar
void cevSonaEkle(struct tNode * head, int alinan) {
    struct tNode * gezici = head;  // n'i yani baş düğümü kaybetmek istemiyorum, çünkü while döngüsünü sonlandırmam için ona ihtiyacım olacak
    while(gezici->next!=head) {
        gezici = gezici->next;
    }
    // bu satırdan itibaren gezici son düğüm
    struct tNode * yeniDugum = (struct tNode *)malloc(sizeof(struct tNode));
    gezici->next = yeniDugum;
    yeniDugum->data = alinan;
    yeniDugum->next = head;  //sona eklediğim düğümün next'i head olmalı
}
void cevYazdir(struct tNode * n) {
    struct tNode * gezici = n;  // n 'i kaybetmemem lazım
    do{
        printf("%5d", gezici->data);
        gezici = gezici->next;
    } while(gezici!=n);
    printf("\n");
}
void cevBasaEkle(struct tNode **n, int alinan) {
    // çift yönlü olmadığı için son'u bulmam gerekecek, çünkü sonDüğüm'ün next'ini yeni başın düğümü yapmam lazım
    struct tNode * gezgin = (*n);
    while(gezgin->next!=(*n)) {
        gezgin = gezgin->next;
    }
    // bu satırda gezgin son düğüm
    struct tNode * yeniDugum = (struct tNode *)malloc(sizeof(struct tNode));
    yeniDugum->data = alinan;
    gezgin->next = yeniDugum;
    yeniDugum->next = (*n);  // yeni düğümün nextini baş düğüme bağladım
    (*n) = yeniDugum;  // main fonksiyonu içerisindeki ilk düğümü tutan pointer artık yeniDugumun ram adresini tutuyor, yani yeni baş bu
}


