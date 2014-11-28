#ifndef __CLIST_HXX__
#define __CLIST_HXX__

#include "CList.h"

#include <iostream>
#define TEMPL template<typename T>
#define TEMPLINL TEMPL inline

#define SDDLIST nsSdD::CList<T>

TEMPLINL
SDDLIST::CList () noexcept
    : m_Head (new CNode<T>(0, m_Tail, nullptr)), m_Tail (new CNode<T> (0, nullptr, m_Head))
{

}

TEMPLINL
SDDLIST::CList (unsigned n) noexcept
    : m_Head (new CNode<T>(0, m_Tail, nullptr)), m_Tail (new CNode<T> (0, nullptr, m_Head))
{
    for (unsigned i = 0; i < n; ++i)
    {
        //m_Head = new CNode<T>(0, m_Head, nullptr);
    }
}

TEMPLINL
SDDLIST::CList (unsigned n, const T & val) noexcept
    : m_Head (new CNode<T>(0, m_Tail, nullptr)), m_Tail (new CNode<T> (0, nullptr, m_Head))
{
    /*
    for (unsigned i = n/2; i > 0; --i)
    {
        push_front(val);
    }
    for (unsigned i = n/2; i < n; ++i)
    {
        push_back(val);
    } */
}

TEMPLINL
SDDLIST::CList (const CList & List) noexcept
{
    *this = List;
}

TEMPLINL
SDDLIST::~CList (void) noexcept
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
    return m_Head->GetSuivant() == nullptr;
}

TEMPLINL
unsigned SDDLIST::size () const noexcept
{
    unsigned size = 0;
    for (Ptr_CNode Ptr (m_Head->GetSuivant()); Ptr != m_Tail->GetPrecedent(); Ptr = Ptr->GetSuivant())
    {
        ++size;
    }
    return size;

}

TEMPLINL
CList<T>& SDDLIST::operator= (const CList & List) noexcept
{
    clear();
    for (Ptr_CNode Ptr (List.front()->GetPrecedent()); Ptr != nullptr; Ptr = Ptr->GetSuivant())
    {
        push_back(Ptr->GetData());
    }
    return (*this);
}

TEMPLINL
void SDDLIST::push_front (const T & val) noexcept
{
    Ptr_CNode Node (new CNode<T>(val, m_Head->GetSuivant(), m_Head));
    m_Head->GetSuivant()->SetPrecedent(Node);
    m_Head->SetSuivant(Node);
}

TEMPLINL
void SDDLIST::pop_front () noexcept
{
    remove(m_Head->GetSuivant());
}

TEMPLINL
void SDDLIST::push_back (const T & val) noexcept
{
    Ptr_CNode Node (new CNode<T>(val, m_Tail, m_Tail->GetPrecedent()));
    m_Tail->GetPrecedent()->SetSuivant(Node);
    m_Tail->SetPrecedent(Node);
}

TEMPLINL
void SDDLIST::pop_back () throw()
{
    remove(m_Tail->GetPrecedent());
}

TEMPLINL
void SDDLIST::reverse () noexcept
{
    Ptr_CNode Start = m_Head->GetSuivant();
    Ptr_CNode End = m_Tail->GetPrecedent();
    for (; End->GetSuivant() == Start; Start = Start->GetSuivant(), End = End->GetPrecedent())
    {
        std::swap(Start, End);
    }
}

/* Pas sur de devoir les faire étant donnée quelles prennent un iterator en argument
max_size
*/

TEMPLINL
void SDDLIST::swap (CList<T> & List) noexcept
{
    CList ListInter (this);
    this = List;
    List = ListInter;
}

TEMPLINL
void SDDLIST::clear () noexcept
{
    Ptr_CNode Next;
    for (Ptr_CNode Ptr (m_Head->GetSuivant()); Ptr != m_Tail; Ptr = Next)
    {
        Next = Ptr->GetSuivant();
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
            push_back(new CNode<T>(val));
        }
    }
}

TEMPLINL
void SDDLIST::merge (CList & x) noexcept
{
    for(Ptr_CNode Ptr = x.front(); Ptr != x.back()->GetSuivant(); Ptr = Ptr->GetSuivant())
    {
        push_back(Ptr);
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
    Ptr_CNode Ptr = front();
    for(; Ptr != back();)
    {
        if( Ptr->GetData() == Ptr->GetSuivant()->GetData() )
        {
            remove(Ptr->GetSuivant());
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
                swap (Ptr->GetData(), Ptr->GetSuivant()->GetData());
                noSwap = false;
            }
        }
        if(noSwap) break;
    }
}

#endif // CLIST_HXX
