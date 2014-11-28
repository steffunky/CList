#ifndef __CLIST_HXX__
#define __CLIST_HXX__

#include "CList.h"
#include <utility>

#define TEMPL template<typename T>
#define TEMPLINL TEMPL inline

#define SDDLIST nsSdD::CList<T>

TEMPLINL
SDDLIST::CList () throw ()
    : m_Head (new CNode<T>(0, m_Tail, nullptr)), m_Tail (new CNode<T> (0, nullptr, m_Head))
{

}

TEMPLINL
SDDLIST::CList (unsigned n) throw ()
{
    for (unsigned i = n/2; i--;)
    {
        push_front(new CNode<T>(0, m_Head->GetSuivant(), m_Head));
    }
    for (unsigned i = n/2; i < n; ++i)
    {
        push_back(new CNode<T>(0, m_Tail, m_Tail->GetPrecedent()));
    }
}

TEMPLINL
SDDLIST::CList (unsigned n, const T & val) throw ()
{
    for (unsigned i = n/2; i--;)
    {
        push_front(new CNode<T>(val, m_Head->GetSuivant(), m_Head));
    }
    for (unsigned i = n/2; i < n; ++i)
    {
        push_back(new CNode<T>(val, m_Tail, m_Tail->GetPrecedent()));
    }
}

TEMPLINL
SDDLIST::CList (const CList & List) throw ()
{
    this = List;
}

TEMPLINL
SDDLIST::~CList (void) throw ()
{
    delete m_Head;
    delete m_Tail;
}

TEMPLINL
typename SDDLIST::Ptr_CNode SDDLIST::front() const throw ()
{
    return m_Head->GetSuivant();
}

TEMPLINL
typename SDDLIST::Ptr_CNode SDDLIST::back () const throw ()
{
    m_Tail->GetPrecedent();
}

TEMPLINL
bool SDDLIST::empty () const throw ()
{
    return m_Head->GetSuivant() == nullptr;
}

TEMPLINL
unsigned SDDLIST::size () const throw ()
{
    unsigned size = 0;
    for (Ptr_CNode Ptr (m_Head->GetSuivant()); Ptr != m_Tail->GetPrecedent(); Ptr = Ptr->GetSuivant())
    {
        ++size;
    }
    return size;

}

TEMPLINL
CList<T>& SDDLIST::operator= (const CList & List) throw ()
{
    clear();
    for (Ptr_CNode Ptr (List.GetHead()); Ptr != List.GetTail(); Ptr = Ptr->GetSuivant())
    {
        push_back(Ptr);
    }
}

TEMPLINL
void SDDLIST::push_front (const Ptr_CNode & Node) throw ()
{
    Node->SetSuivant (m_Head->GetSuivant());
    Node->SetPrecedent (m_Head);
    m_Head->GetSuivant()->SetPrecedent(Node);
    m_Head->SetSuivant(Node);
}

TEMPLINL
void SDDLIST::pop_front () throw ()
{
    remove(m_Head->GetSuivant());
}

TEMPLINL
void SDDLIST::push_back (const Ptr_CNode & Node) throw ()
{
    Node->SetSuivant (m_Tail);
    Node->SetPrecedent (m_Tail->GetPrecedent());
    m_Tail->GetPrecedent->SetSuivant(Node);
    m_Tail->SetPrecedent(Node);
}

TEMPLINL
void SDDLIST::pop_back () throw()
{
    remove(m_Tail->GetPrecedent());
}

TEMPLINL
void SDDLIST::reverse () throw ()
{
    Ptr_CNode Start = m_Head->GetSuivant();
    Ptr_CNode End = m_Tail->GetPrecedent();
    for (; End->GetSuivant() == Start; Start = Start->GetSuivant(), End = End->GetPrecedent())
    {
        std::swap(Start, End);
    }
}



/* Pas sur de devoir les faire étant donnée quelles prennent un iterator en argument
void unique () throw ();
resize
merge
assign
max_size
front
back
assign
remove
sort
*/
TEMPLINL
void SDDLIST::swap (CList<T> & List) throw ()
{
    CList ListInter (this);
    this = List;
    List = ListInter;
}

TEMPLINL
void SDDLIST::clear () throw ()
{
    Ptr_CNode Next;
    for (Ptr_CNode Ptr (m_Head->GetSuivant()); Ptr != m_Tail; Ptr = Next)
    {
        Next = Ptr->GetSuivant();
        delete Ptr;
    }
}

TEMPLINL
void SDDLIST::remove (const Ptr_CNode & Node) throw ()
{
    Node->GetSuivant->SetPrecedent(Node->GetPrecedent());
    Node->GetPrecedent->SetSuivant(Node->GetSuivant());
    Node->SetSuivant(nullptr);
    Node->SetPrecedent(nullptr);
}

#endif // CLIST_HXX
