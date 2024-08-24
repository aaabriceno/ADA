#include <iostream>
#include <cstdlib>  


struct Vector {
    int* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;
};


void Resize(Vector* pThis) {

    int* pNewVect = (int*)realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta));

    if (pNewVect == nullptr) {

        std::cerr << "Error: No se pudo redimensionar el vector." << std::endl;
        exit(1);
    }


    pThis->m_pVect = pNewVect;

    pThis->m_nMax += pThis->m_nDelta;
}


void Insert(Vector* pThis, int elem) {

    if (pThis->m_nCount == pThis->m_nMax) {
        Resize(pThis);
    }
    pThis->m_pVect[pThis->m_nCount++] = elem;
}


void InitVector(Vector* pThis, int delta) {
    pThis->m_pVect = nullptr;
    pThis->m_nCount = 0;
    pThis->m_nMax = 0;
    pThis->m_nDelta = delta;
}


void PrintVector(const Vector* pThis) {
    for (int i = 0; i < pThis->m_nCount; ++i) {
        std::cout << pThis->m_pVect[i] << " ";
    }
    std::cout << std::endl;
}


int main() {
    Vector myVector;
    int delta = 5;


    InitVector(&myVector, delta);


    Insert(&myVector, 10);
    Insert(&myVector, 20);
    Insert(&myVector, 30);
    Insert(&myVector, 40);
    Insert(&myVector, 50);

    Insert(&myVector, 60);
    Insert(&myVector, 70);
    Insert(&myVector, 70);
    Insert(&myVector, 70);


    std::cout << "Contenido del vector: " << std::endl;
    PrintVector(&myVector);

    free(myVector.m_pVect);

    return 0;
}
