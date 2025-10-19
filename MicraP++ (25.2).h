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

static void YAZ(char yazma) {
    if (yazma != 0) printf("%c", yazma);
}

static void OKU(char *okuma) {
    if (okuma != NULL) scanf(" %c", okuma);
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
