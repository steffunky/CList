#ifndef __CLIST_HXX__
#define __CLIST_HXX__

#include "CListV1.h"


#define TEMPL template<typename T>
#define TEMPLINL TEMPL inline

#define SDDLIST nsSdD::CListV1<T>

TEMPLINL
SDDLIST::CListV1 () noexcept
    : m_Head (std::make_shared<CNode<T>>(T(), nullptr, nullptr)), m_Tail (std::make_shared<CNode<T>> (T(), nullptr, m_Head))
{
    m_Head->SetSuivant(m_Tail);
}

TEMPLINL
SDDLIST::CListV1 (unsigned n) noexcept
    : m_Head (std::make_shared<CNode<T>>(T(), nullptr, nullptr)), m_Tail (std::make_shared<CNode<T>> (T(), nullptr, m_Head))
{
    m_Head->SetSuivant(m_Tail);
    for (unsigned i = 0; i < n; ++i)
    {
        push_back(0);
    }
}

TEMPLINL
SDDLIST::CListV1 (unsigned n, const T & val) noexcept
    : m_Head (std::make_shared<CNode<T>>(T(), nullptr, nullptr)), m_Tail (std::make_shared<CNode<T>> (T(), nullptr, m_Head))
{
    m_Head->SetSuivant(m_Tail);
    for (unsigned i = 0; i < n; ++i)
    {
        push_back(val);
    }
}

TEMPLINL
SDDLIST::CListV1 (const CListV1 & List) noexcept
    : m_Head (std::make_shared<CNode<T>> (T(), nullptr, nullptr)), m_Tail (std::make_shared<CNode<T>> (T(), nullptr, m_Head))
{
    m_Head->SetSuivant(m_Tail);
    for (Ptr_CNode Ptr (List.front()); Ptr != List.back()->GetSuivant(); Ptr = Ptr->GetSuivant())
    {
        push_back(Ptr->GetData());
    }
}

TEMPLINL
SDDLIST::~CListV1 (void) noexcept
{
    /*delete m_Head;
    delete m_Tail; */
}

TEMPLINL
typename SDDLIST::Ptr_CNode SDDLIST::front() const noexcept
{
    return m_Head->GetSuivant();
}

TEMPLINL
typename SDDLIST::Ptr_CNode SDDLIST::back () const noexcept
{
    return m_Tail->GetPrecedent();
}

TEMPLINL
bool SDDLIST::empty () const noexcept
{
    return m_Head->GetSuivant() == m_Tail;
}

TEMPLINL
unsigned SDDLIST::size () const noexcept
{
    unsigned size = 0;
    for (Ptr_CNode Ptr (m_Head->GetSuivant()); Ptr != m_Tail; Ptr = Ptr->GetSuivant())
    {
        ++size;
    }
    return size;

}

TEMPLINL
CListV1<T>& SDDLIST::operator= (const CListV1 & List) noexcept
{
    clear();
    for (Ptr_CNode Ptr (List.front()); Ptr != List.back()->GetSuivant(); Ptr = Ptr->GetSuivant())
    {
        push_back(Ptr->GetData());
    }
    return (*this);
}

TEMPLINL
void SDDLIST::push_front (const T & val) noexcept
{
    Ptr_CNode Node (std::make_shared<CNode<T>>(val, m_Head->GetSuivant(), m_Head));
    m_Head->GetSuivant()->SetPrecedent(Node);
    m_Head->SetSuivant(Node);
}

TEMPLINL
void SDDLIST::pop_front () noexcept
{
    remove(m_Head->GetSuivant()->GetData());
}

TEMPLINL
void SDDLIST::push_back (const T & val) noexcept
{
    Ptr_CNode Node (std::make_shared<CNode<T>>(val, m_Tail, m_Tail->GetPrecedent()));
    m_Tail->GetPrecedent()->SetSuivant(Node);
    m_Tail->SetPrecedent(Node);
}

TEMPLINL
void SDDLIST::pop_back () throw()
{
    remove(m_Tail->GetPrecedent()->GetData());
}

TEMPLINL
void SDDLIST::reverse () noexcept
{
    Ptr_CNode Start = m_Head->GetSuivant();
    Ptr_CNode End = m_Tail->GetPrecedent();
    for (; End->GetSuivant() != Start && End != Start; Start = Start->GetSuivant(), End = End->GetPrecedent())
    {
        swap(Start, End);
    }
}

/* Pas sur de devoir les faire étant donnée quelles prennent un iterator en argument
max_size
*/

TEMPLINL
void SDDLIST::swap (CListV1<T> & List) noexcept
{
    CListV1<T> ListInter (*this);
    *this = List;
    List = ListInter;
}

TEMPLINL
void SDDLIST::clear () noexcept
{
    Ptr_CNode Next;
    for (Ptr_CNode Ptr (front()); Ptr != m_Tail; Ptr = Next)
    {
        Next = Ptr->GetSuivant();
        Ptr->SetSuivant(nullptr);
        Ptr->SetPrecedent(nullptr);
    }
    m_Head->SetSuivant(m_Tail);
    m_Tail->SetPrecedent(m_Head);
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
void SDDLIST::resize (unsigned n, const T& val /* = T() */) noexcept
{
    if(n < size())
    {
        for(; n < size(); ++n)
        {
            pop_back();

        }
    }
    else if (n > size())
    {
        for(; n > size(); --n)
        {
            push_back(val);
        }
    }
}

TEMPLINL
void SDDLIST::merge (CListV1 & x) noexcept
{
    for(Ptr_CNode Ptr = x.front(); Ptr != x.back()->GetSuivant(); Ptr = Ptr->GetSuivant())
    {
        push_back(Ptr->GetData());
    }
}

TEMPLINL
void SDDLIST::assign (unsigned n, const T& val) noexcept
{
    resize(n);
    for(Ptr_CNode Ptr (m_Head->GetSuivant()); Ptr != m_Tail; Ptr = Ptr->GetSuivant())
    {
        Ptr->SetData(val);
    }
}

TEMPLINL
void SDDLIST::unique() noexcept
{
    for(Ptr_CNode Ptr = front(); Ptr != back();)
    {
        if( Ptr->GetData() == Ptr->GetSuivant()->GetData() )
        {
            Remove(Ptr->GetSuivant()); // remove le noeud normalement
        }
        else
        {
            Ptr = Ptr->GetSuivant();
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
void SDDLIST::swap(SDDLIST::Ptr_CNode& PtrA, SDDLIST::Ptr_CNode& PtrB) noexcept
{
    T Temp = PtrA->GetData();
    PtrA->SetData(PtrB->GetData());
    PtrB->SetData(Temp);
}

TEMPLINL
unsigned SDDLIST::max_size() const noexcept
{
    return m_MaxSize;
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
void SDDLIST::GetSuivant () noexcept
{
    for (Ptr_CNode Ptr = front(); Ptr != m_Tail; Ptr = Ptr->GetSuivant());
}

#undef TEMPLINL
#undef TEMPL
#undef SDDLIST
#endif // CLIST_HXX
