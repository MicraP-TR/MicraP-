#pragma once

#ifdef __cplusplus
#error "HATA: SADECE C DERLEYİCİSİ KULLANILABİLİR!"
#endif

#include <stdlib.h>

typedef struct {
    int bayt;
    int bit;
} RAM;

extern RAM REB;

inline int* REB_AYIR(int boyut) {
    if (boyut > 0) {
        return malloc(sizeof(int) * boyut);
    }
    return NULL;
}

inline void REB_EKLE(int* adres, int index, int veri) {
    if (adres != NULL) adres[index] = veri;
}

inline void REB_SİL(int* adres) {
    if (adres != NULL) {
        free(adres);
    }
}

inline void REB_TEMIZLE(int* adres) {
    if (adres != NULL) *adres = 0;
}

inline void ÖLÇ(int* adres) {
    if (adres != NULL) {
        REB.bayt = sizeof(*adres);
        REB.bit = REB.bayt * 8;
    }
}
