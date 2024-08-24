#include <iostream>
using namespace std;

class CVector {
private:
    int* m_pVect;
    int m_nCount;
    int m_nMax;
    int m_nDelta;

    void Init(int delta) {
        m_nDelta = delta;
        m_nCount = 0;
        m_nMax = delta;
        m_pVect = new int[m_nMax];
    }

    void Resize() {
        int* pNewVect = new int[m_nMax + m_nDelta];
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

    void Insert(int elem) {
        if (m_nCount == m_nMax) {
            Resize();
        }
        m_pVect[m_nCount++] = elem;
    }

    int GetAt(int index) const {
        if (index < 0 || index >= m_nCount) {
            cerr << "Index out of bounds" << endl;
            return -1;
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
    CVector myVector(5);
    for (int i = 0; i < 12; ++i) {
        myVector.Insert(i * 2);
        cout << "Inserted: " << i * 2 << endl;
        cout << "Size: " << myVector.Size() << ", Capacity: " << myVector.Capacity() << endl;
    }

    cout << "\nElements in the vector:" << endl;
    for (int i = 0; i < myVector.Size(); ++i) {
        cout << "Element at index " << i << ": " << myVector.GetAt(i) << endl;
    }

    return 0;
}
