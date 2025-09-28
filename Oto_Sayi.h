#ifdef __cplusplus
#error "HATA: SADECE C DERLEYİCİSİ KULLANILABİLİR!"
#endif

#include <stdlib.h>
#include <string.h>

#include "MicraP++ (25.2).h"

typedef struct {
    void* veri;
    size_t eleman_boyutu;
    size_t boyut;
    size_t kapasite;
} Vector;

inline void OTO_SAYİ_BAŞLAT(Vector* v, size_t eleman_boyutu, size_t kapasite) {
    if (API.durum[0] == 'D') {
        v->eleman_boyutu = eleman_boyutu;
        v->boyut = 0;
        v->kapasite = kapasite;
        v->veri = malloc(eleman_boyutu * kapasite);
        if (API.durum[0] == 'D') {
            printf("0xA KUTUPHANESI, BILINMEYEN BIR SEBEBLE AKTIF?\n");
        } else if (API.durum[0] == 'Y') {
            API.durum[0] = 'D';
        }
    } else {
        printf("API kapalı!\n");
        return;
    }
}

inline void OTO_SAYİ_EKLE(Vector* v, void* eleman) {
    if (API.durum[0] == 'D') {
        if (v->boyut >= v->kapasite) {
            v->kapasite *= 2;
            v->veri = realloc(v->veri, v->eleman_boyutu * v->kapasite);
        }
        memcpy((char*)v->veri + v->boyut * v->eleman_boyutu, eleman, v->eleman_boyutu);
        v->boyut++;
    } else {
        return;
    }
}

inline void* OTO_SAYİ_AL(Vector* v, size_t index) {
    if (API.durum[0] == 'D') {
        if (index < v->boyut) {
            return (char*)v->veri + index * v->eleman_boyutu;
        }
        return NULL;
    } else {
        return;
    }
}

inline void OTO_SAYİ_TEMİZLE(Vector* v) {
    if (API.durum[0] == 'D') {
        free(v->veri);
        v->veri = NULL;
        v->boyut = 0;
        v->kapasite = 0;
    }
}