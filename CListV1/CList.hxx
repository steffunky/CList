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
    for (Ptr_CNode Ptr (List.front()); Ptr != List.back()->GetSuivant(); Ptr = Ptr->GetSuivant())
    {
        push_back(Ptr->GetData());
    }
}

TEMPLINL
SDDLIST::~CList (void) noexcept
{
    /*delete m_Head;
    delete m_Tail; */
}

TEMPLINL
T& SDDLIST::front() const noexcept
{
    return m_Head->GetSuivant()->GetData();
}

TEMPLINL
T& SDDLIST::back () const noexcept
{
    return m_Tail->GetPrecedent()->GetData();
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
CList<T>& SDDLIST::operator= (const CList & List) noexcept
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
    Ptr_CNode Node (m_Head->GetSuivant());
    Node->GetSuivant()->SetPrecedent(Node->GetPrecedent());
    Node->GetPrecedent()->SetSuivant(Node->GetSuivant());
    Node->SetSuivant(nullptr);
    Node->SetPrecedent(nullptr);
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
    Ptr_CNode Node (m_Tail->GetPrecedent());
    Node->GetSuivant()->SetPrecedent(Node->GetPrecedent());
    Node->GetPrecedent()->SetSuivant(Node->GetSuivant());
    Node->SetSuivant(nullptr);
    Node->SetPrecedent(nullptr);
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
void SDDLIST::merge (CList & x) noexcept
{
    for(Ptr_CNode Ptr = x.front(); Ptr != x.back()->GetSuivant(); Ptr = Ptr->GetSuivant())
    {
        push_back(Ptr->GetData());
    }
}

TEMPLINL
void SDDLIST::assign (unsigned n, const T& val) noexcept
{
    resize(n, val);
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
            Remove(Ptr->GetSuivant()->GetData()); // remove le noeud normalement
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
