#include <iostream>

template <typename Type>
class CVector {
private:
    Type* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

    void Init(int delta) {
        m_nDelta = delta;
        m_nCount = 0;
        m_nMax = delta;
        m_pVect = new Type[m_nMax];
    }

    void Resize() {
        Type* pNewVect = new Type[m_nMax + m_nDelta];
        for (int i = 0; i < m_nCount; ++i) {
            pNewVect[i] = m_pVect[i];
        }
        delete[] m_pVect;
        m_pVect = pNewVect;
        m_nMax += m_nDelta;
    }

public:
    CVector(int delta = 10) {
        Init(delta);
    }

    ~CVector() {
        delete[] m_pVect;
    }

    void Insert(const Type& elem) {
        if (m_nCount == m_nMax) {
            Resize();
        }
        m_pVect[m_nCount++] = elem;
    }

    Type GetAt(int index) const {
        if (index < 0 || index >= m_nCount) {
            std::cerr << "Index out of bounds" << std::endl;
            return Type();
        }
        return m_pVect[index];
    }

    int Size() const {
        return m_nCount;
    }

    int Capacity() const {
        return m_nMax;
    }
};

int main() {
    CVector<int> intVector(5);

    for (int i = 0; i < 12; ++i) {
        intVector.Insert(i * 2);
        std::cout << "Inserted: " << i * 2 << std::endl;
        std::cout << "Size: " << intVector.Size() << ", Capacity: " << intVector.Capacity() << std::endl;
    }

    std::cout << "\nElementos en el vector de enteros:" << std::endl;
    for (int i = 0; i < intVector.Size(); ++i) {
        std::cout << "Elemento en index " << i << ": " << intVector.GetAt(i) << std::endl;
    }

    CVector<std::string> stringVector(3);
    stringVector.Insert("Hello");
    stringVector.Insert("World");
    stringVector.Insert("!");

    std::cout << "\nElementos en el vector de strings:" << std::endl;
    for (int i = 0; i < stringVector.Size(); ++i) {
        std::cout << "Elemento en index " << i << ": " << stringVector.GetAt(i) << std::endl;
    }

    return 0;
}
