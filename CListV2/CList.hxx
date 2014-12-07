#ifndef __CLIST_HXX__
#define __CLIST_HXX__

#include "CList.h"
#include <iostream>

#define TEMPL template<typename T>
#define TEMPLINL TEMPL inline

#define SDDLIST nsSdD::CList<T>

TEMPLINL
SDDLIST::CList () noexcept
    : m_Head (std::make_shared<CNode<T>>(T(), nullptr, nullptr)), m_Tail (std::make_shared<CNode<T>> (T(), nullptr, m_Head))
{
    m_Head->SetSuivant(m_Tail);
}

TEMPLINL
SDDLIST::CList (unsigned n) noexcept
    : m_Head (std::make_shared<CNode<T>>(T(), nullptr, nullptr)), m_Tail (std::make_shared<CNode<T>> (T(), nullptr, m_Head))
{
    m_Head->SetSuivant(m_Tail);
    for (unsigned i = 0; i < n; ++i)
    {
        push_back(0);
    }
}

TEMPLINL
SDDLIST::CList (unsigned n, const T & val) noexcept
    : m_Head (std::make_shared<CNode<T>>(T(), nullptr, nullptr)), m_Tail (std::make_shared<CNode<T>> (T(), nullptr, m_Head))
{
    m_Head->SetSuivant(m_Tail);
    for (unsigned i = 0; i < n; ++i)
    {
        push_front(val);
    }
}

TEMPLINL
SDDLIST::CList (const CList & List) noexcept
    : m_Head (std::make_shared<CNode<T>> (T(), nullptr, nullptr)), m_Tail (std::make_shared<CNode<T>> (T(), nullptr, m_Head))
{
    m_Head->SetSuivant(m_Tail);
    for (iterator It (List.begin()); It != List.end(); ++It)
    {
        push_front(It->GetData());
    }
}

TEMPLINL
SDDLIST::~CList() noexcept
{

}

TEMPLINL
T& SDDLIST::front() const noexcept
{
    iterator It (m_Head);
    ++It;
    return *It;
}

TEMPLINL
T& SDDLIST::back() const noexcept
{
    iterator It (m_Tail);
    --It;
    return *It;
}

TEMPLINL
bool SDDLIST::empty() const noexcept
{
    iterator It (m_Head);
    ++It;
    return It == m_Tail;
}

TEMPLINL
unsigned SDDLIST::size() const noexcept
{
    unsigned size = 0;
    for (iterator It = begin(); It != end(); ++It)
        ++size;
    return size;
}

TEMPLINL
unsigned SDDLIST::max_size() const noexcept
{
    return m_MaxSize;
}

TEMPLINL
CList<T>& SDDLIST::operator= (const CList & List) noexcept
{
    clear();
    for (iterator It = List.begin(); It != List.end(); ++It)
    {
        push_back(It->GetData());
    }
    return (*this);
}

TEMPLINL
void SDDLIST::push_front(const T &val) noexcept
{
    iterator It (m_Head);
    insert(++It, val);
}

TEMPLINL
void SDDLIST::pop_front() noexcept
{
    iterator It (m_Head);
    erase(++It);
}

TEMPLINL
void SDDLIST::push_back (const T &val) noexcept
{
    iterator It (end());
    insert(--It, val);
}

TEMPLINL
void SDDLIST::pop_back() noexcept
{
    iterator It (end());
    --It;
   erase (It);
}

TEMPLINL
void SDDLIST::swap (CList<T> & List) noexcept
{
    CList<T> ListInter (*this);
    *this = List;
    List = ListInter;
}

TEMPLINL
void SDDLIST::clear () noexcept
{
    iterator Next;
    for (iterator It (begin()); It != end(); It = Next)
    {
        Next = ++It;
        It->SetSuivant(nullptr);
        It->SetPrecedent(nullptr);
    }
    m_Head->SetSuivant(m_Tail);
    m_Tail->SetPrecedent(m_Head);
}

TEMPLINL
void SDDLIST::remove (const T & val) noexcept
{
    Ptr_CNode Node = find(val);
    if (Node != nullptr)
    {
        Node->GetSuivant()->SetPrecedent(Node->GetPrecedent());
        Node->GetPrecedent()->SetSuivant(Node->GetSuivant());
        Node->SetSuivant(nullptr);
        Node->SetPrecedent(nullptr);
        remove (val);
    }
}

TEMPLINL
typename SDDLIST::Ptr_CNode SDDLIST::find (const T& val) noexcept
{
    for (Ptr_CNode ptr (m_Head->GetSuivant()); ptr != m_Tail; ptr = ptr->GetSuivant())
    {
        if (ptr->GetData() == val)
        {
            return ptr;
        }
    }
    return nullptr;
}

TEMPLINL
void SDDLIST::unique() noexcept
{
    for(iterator It = begin(); It != end();)
    {
        if(It->GetData() == It->GetSuivant()->GetData() )
        {
            Remove(It->GetSuivant());
        }
        else
        {
            ++It;
        }
    }
}

TEMPLINL
void SDDLIST::sort() noexcept
{
    for(iterator End = end(); End != begin(); --End)
    {
        bool noSwap = true;
        for(iterator Start = begin(); Start != End; ++Start)
        {
            if(Start->GetData() > Start->GetSuivant()->GetData())
            {
                iterator ItSuivant = ++Start;
                //this->swap (Start.GetCurrentNode(), ItSuivant.GetCurrentNode());
                noSwap = false;
            }
        }
        if(noSwap) break;
    }
}

TEMPLINL
void SDDLIST::reverse () noexcept
{
    iterator Start = begin();
    iterator End = end();
    for (; End->GetSuivant() != Start.GetCurrentNode() && End.GetCurrentNode() != Start.GetCurrentNode(); ++Start, --End)
    {
        std::swap(Start, End);
    }
}

TEMPLINL
void SDDLIST::resize (unsigned n, const T& val /* = T() */) noexcept
{
    unsigned taille = size();
    if(n < size())
    {
        pop_back();
        for(; n < taille; ++n)
        {
            pop_back();
        }
    }
    else if (n > size())
    {
        for(; n > taille; --n)
        {
            push_back(val);
        }
    }
}

TEMPLINL
void SDDLIST::merge(CList &list) noexcept
{
    for(iterator It (list.begin()); It != list.end(); ++It)
    {
        push_back(It->GetData());
    }
}

TEMPLINL
void SDDLIST::assign (unsigned n, const T& val) noexcept
{
    resize(n);
    for(iterator It (begin()); It != end(); ++It)
    {
        It->SetData(val);
    }
}

TEMPLINL
typename SDDLIST::iterator SDDLIST::insert(iterator position, const T &val) noexcept
{
    Ptr_CNode Node (std::make_shared<CNode<T>>(val, position.GetCurrentNode(), position->GetPrecedent()));
    position->GetPrecedent()->SetSuivant(Node);
    position->SetPrecedent(Node);
    return position;
}

TEMPLINL
typename SDDLIST::iterator SDDLIST::erase(iterator position) noexcept
{
    iterator precedent (position->GetPrecedent());
    position->GetPrecedent()->SetSuivant(position->GetSuivant());
    position->GetSuivant()->SetPrecedent(position->GetPrecedent());
    position->SetSuivant(nullptr);
    position->SetPrecedent(nullptr);
    return precedent;
}

TEMPLINL
void SDDLIST::splice(iterator position, CList<T> &x) noexcept
{
    for (iterator It = x.begin(); It != x.end(); ++It)
    {
        insert(position++, It->GetData());
    }
}

TEMPLINL
typename SDDLIST::iterator SDDLIST::begin() noexcept
{
    return iterator(m_Head->GetSuivant());
}

TEMPLINL
const typename SDDLIST::iterator SDDLIST::begin() const noexcept
{
    return iterator(m_Head->GetSuivant());
}

TEMPLINL
typename SDDLIST::iterator SDDLIST::end() noexcept
{
    return iterator(m_Tail);
}

TEMPLINL
const typename SDDLIST::iterator SDDLIST::end() const noexcept
{
    return iterator(m_Tail);
}

TEMPLINL
typename SDDLIST::reverse_iterator SDDLIST::rbegin() noexcept
{
    return iterator (back());
}

TEMPLINL
typename SDDLIST::reverse_iterator SDDLIST::rend() noexcept
{
    return iterator (m_Head);
}

TEMPLINL
typename SDDLIST::const_iterator SDDLIST::cbegin() const noexcept
{
    return const_iterator(front());
}

TEMPLINL
typename SDDLIST::const_iterator SDDLIST::cend() const noexcept
{
    return const_iterator(m_Tail);
}

TEMPLINL
typename SDDLIST::const_reverse_iterator SDDLIST::crbegin() const noexcept
{
    return const_iterator (back());
}

TEMPLINL
typename SDDLIST::const_reverse_iterator SDDLIST::crend() const noexcept
{
    return const_iterator(m_Head);
}

TEMPLINL
void SDDLIST::Remove(const Ptr_CNode & Ptr) noexcept
{
    Ptr->GetPrecedent()->SetSuivant(Ptr->GetSuivant());
    Ptr->GetSuivant()->SetPrecedent(Ptr->GetPrecedent());
    Ptr->SetSuivant(nullptr);
    Ptr->SetPrecedent(nullptr);
}

TEMPLINL
void SDDLIST::swap(SDDLIST::Ptr_CNode& PtrA, SDDLIST::Ptr_CNode& PtrB) noexcept
{
    T Temp = PtrA->GetData();
    PtrA->SetData(PtrB->GetData());
    PtrB->SetData(Temp);
}


#endif // CLIST_HXX
