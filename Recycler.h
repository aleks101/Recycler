#pragma once
#include <iostream>
#include "Reusable.h"

template<typename T, int C>
class Recycler {
public:
    static_assert(std::is_base_of<Reusable, T>::value, "T is not a subclass of Reusable!");
    Recycler(T* firstElement);
    ~Recycler();

    void SetFirstElement(T* firstElement);
    void Checkup();

private:
    Reusable* m_obj;
    T* m_firstEl;
};
template<typename T, int C>
Recycler<T, C>::Recycler(T* firstElement) {
    m_firstEl = firstElement;
    m_obj = NULL;
}
template<typename T, int C>
Recycler<T, C>::~Recycler() {
    m_firstEl = NULL;
    m_obj = NULL;
}
template<typename T, int C>
void Recycler<T, C>::SetFirstElement(T* firstElement) {
    m_firstEl = firstElement;
}
template<typename T, int C>
void Recycler<T, C>::Checkup() {
    for (int i = 0; i < C; i++) {
        m_obj = (m_firstEl + i);
        if (m_obj != NULL && m_obj->m_reuse) {
            m_obj->Reset();
            m_obj->m_reuse = false;
        }
    }
}