#ifdef __cplusplus
#error "HATA: SADECE C DERLEYİCİSİ KULLANILABİLİR!"
#endif

#include <stdlib.h>
#include <string.h>

typedef struct {
    void* veri;
    size_t eleman_boyutu;
    size_t boyut;
    size_t kapasite;
} Vector;

inline void OTO_SAYİ_BAŞLAT(Vector* v, size_t eleman_boyutu, size_t kapasite) {
    v->eleman_boyutu = eleman_boyutu;
    v->boyut = 0;
    v->kapasite = kapasite;
    v->veri = malloc(eleman_boyutu * kapasite);
}

inline void OTO_SAYİ_EKLE(Vector* v, void* eleman) {
    if (v->boyut >= v->kapasite) {
        v->kapasite *= 2;
        v->veri = realloc(v->veri, v->eleman_boyutu * v->kapasite);
    }
    memcpy((char*)v->veri + v->boyut * v->eleman_boyutu, eleman, v->eleman_boyutu);
    v->boyut++;
}

inline void* OTO_SAYİ_AL(Vector* v, size_t index) {
    if (index < v->boyut) {
        return (char*)v->veri + index * v->eleman_boyutu;
    }
    return NULL;
}

inline void OTO_SAYİ_TEMİZLE(Vector* v) {
    free(v->veri);
    v->veri = NULL;
    v->boyut = 0;
    v->kapasite = 0;
}
