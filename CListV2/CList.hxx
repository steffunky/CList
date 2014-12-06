#ifndef __CLIST_HXX__
#define __CLIST_HXX__

#include "CList.h"
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
        push_back(val);
    }
}

TEMPLINL
SDDLIST::CList (const CList & List) noexcept
    : m_Head (std::make_shared<CNode<T>> (T(), nullptr, nullptr)), m_Tail (std::make_shared<CNode<T>> (T(), nullptr, m_Head))
{
    m_Head->SetSuivant(m_Tail);
    for (iterator It (List.begin()); It != List.end(); ++It)
    {
        push_back(It->GetData());
    }
}

TEMPLINL
SDDLIST::~CList() noexcept
{

}

TEMPLINL
typename SDDLIST::Ptr_CNode SDDLIST::front() const noexcept
{
    iterator It (m_Head);
    ++It;
    return *It;
}

TEMPLINL
typename SDDLIST::Ptr_CNode SDDLIST::back() const noexcept
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
    unsigned size;
    for (iterator It (begin()); It != end(); ++It, ++size);
    return size;
}

TEMPLINL
unsigned SDDLIST::max_size() const noexcept
{
    return max_size;
}

TEMPLINL
CList<T>& SDDLIST::operator= (const CList & List) noexcept
{
    clear();
    for (iterator It (List.begin()); It != List.end(); ++It)
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
    iterator It (m_Tail);
    --It;
    insert(It, val);
}

TEMPLINL
void SDDLIST::pop_back() noexcept
{
    iterator It (m_Tail);
    erase (--It);
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
void SDDLIST::unique() noexcept
{
    for(iterator It = begin(); It != end();)
    {
        if(It->GetData() == It->GetSuivant()->GetData() )
        {
            Remove(It->GetSuivant()->GetData());
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
    for(Ptr_CNode End = back();End != front(); End = End->GetPrecedent())
    {
        bool noSwap = true;
        for(Ptr_CNode Ptr = front(); Ptr != End; Ptr = Ptr->GetSuivant())
        {
            if(Ptr->GetData() > Ptr->GetSuivant()->GetData())
            {
                Ptr_CNode PtrSuivant = Ptr->GetSuivant();
                swap (Ptr, PtrSuivant);
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
    for (; End->GetSuivant() != *Start && *End != *Start; ++Start, --End)
    {
        swap(Start, End);
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
    for(iterator It = list.begin(); It != list.end(); ++It)
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
    Ptr_CNode pos = position->GetPrecedent();
    Ptr_CNode Node (std::make_shared<CNode<T>>(val, *position, position->GetPrecedent()));
    position->GetPrecedent()->SetSuivant(Node);
    position->SetPrecedent(Node);
    return position;
}

TEMPLINL
typename SDDLIST::iterator SDDLIST::erase(const_iterator position) noexcept
{
    position->GetPrecedent()->SetSuivant(position->GetSuivant());
    position->GetSuivant()->SetPrecedent(position->GetPrecedent());
    position->SetSuivant(nullptr);
    position->SetPrecedent(nullptr);
}

TEMPLINL
void SDDLIST::splice(const_iterator position, CList<T> &x) noexcept
{
    for (iterator It = x.begin(); It != x.end(); ++It)
    {
        insert(position++, It->GetData());
    }
}

TEMPLINL
typename SDDLIST::iterator SDDLIST::begin() noexcept
{
    return iterator(front());
}

TEMPLINL
typename SDDLIST::iterator SDDLIST::end() noexcept
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

#endif // CLIST_HXX
