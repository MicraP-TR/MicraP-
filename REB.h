#ifdef __cplusplus
#error "HATA: SADECE C DERLEYİCİSİ KULLANILABİLİR!"
#endif

#include "MicraP++ (25.2).h"
#include <stdlib.h>

struct reb {
    int bayt = 0;
    int bit = 0;
};

extern struct reb REB;

inline void REB_AYIR(int boyut) {
    if (API.durum[1] == 'D') {
        if (boyut > 0) {
            malloc(sizeof(int) * boyut);
        }
        return;
    }
}

inline void REB_EKLE(int* adres, int index, int veri) {
    if (API.durum[1] == 'D') {
        if (adres != NULL) {
            adres[index] = veri;
        }
    }
}

inline void REB_SİL(int* adres) {
    if (API.durum[1] == 'D') {
        if (adres != NULL) {
            free(adres);
        }
    }
}

inline void REB_TEMİZLE(int* adres) {
    if (API.durum[1] == 'D') {
        if (adres != NULL) {
            *adres = 0;
        }
    }
}

inline void ÖLÇ(int* adres) {
    if (API.durum[1] == 'D') {
        if (adres != NULL) {
            REB.bayt = sizeof((int)adres);
            REB.bit = sizeof((int) adres / 8);
        }
    }
}