#pragma once

#ifdef __cplusplus
#error "HATA: SADECE C DERLEYİCİSİ KULLANILABİLİR!"
#endif

#include <stdio.h>

#define EĞER(kosul) if (kosul)
#define DEGIL(kosul) if (!(kosul))
#define DONGU(kosul) while (kosul)
#define BELIRLI_DONGU(kosul) for (kosul)
#define YAPI(name) struct name
#define BİTİR printf("\n \nPROGRAM BASARIYLA BITTI. KOD: 0 \n")

struct data {
    int bayt;
};

struct data VERI;

typedef struct {
    const short int libkod[2];
    char durum[2];
} BAGLANTI;

BAGLANTI API = {
    .libkod = {0xA0C0, 0xBC00},
    .durum = {'Y', 'Y'}
};

inline void YAZ(char yazma) {
    if (yazma != 0) {
        printf("%c", yazma);
    }
}

inline void OKU(char *okuma) {
    if (okuma != NULL) {
        scanf(" %c", okuma);
    }
}

inline void TAŞI(int *tasinan, int *tasiyan) {
    if (tasinan && tasiyan) {
        *tasinan = *tasiyan;
    }
}

inline void EKLE(int *hedef, int deger) {
    if (hedef) {
        *hedef += deger;
    }
}

inline void BÖL(int bolunen, int bolen, int *kalan) {
    if (bolen != 0 && kalan) {
        *kalan = bolunen % bolen;
    }
}

inline void KÜTÜPHANE(int libkodu, char durum) {
    if (libkodu != 0 && (durum == 'Y' || durum == 'D')) {
        if (API.libkod[0] == libkodu) {
            API.durum[0] = durum;
        } else if (API.libkod[1] == libkodu) {
            API.durum[1] = durum;
        }
    }
}