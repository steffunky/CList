#ifndef __CLIST_HXX__
#define __CLIST_HXX__

#include "CList.h"

#define TEMPL template <class T>
#define TEMPLINL TEMPL inline

#define SDDLIST nsSdD::CList<T>

#define Ptr_CNode shared_ptr<CNode<T>>

TEMPLINL
explicit SDDLIST::CList () throw ()
{

}

TEMPLINL
explicit SDDLIST::CList (size_type n) throw ()
{
    for (unsigned i = 0; i < n; ++i)
    {
        m_Head = new CNode<T> (0, )
    }
}

TEMPLINL
SDDLIST::CList (size_type n, const value_type & val) throw ()
{

}

TEMPLINL
SDDLIST::CList (const CList & List) throw ()
{
    m_Head = List.GetHead();
    m_Tail = List.GetTail();
}

TEMPLINL
SDDLIST::~CList (void) throw ()
{
    delete m_Head;
}

TEMPLINL
Ptr_CNode SDDLIST::GetHead() const throw ()
{
    return m_Head;
}
Ptr_CNode GetTail () const throw ();

TEMPLINL
void SDDLIST::SetHead (const Ptr_CNode & Head) throw ()
{
    m_Head = Head;
}


TEMPLINL
void SDDLIST::SetTail (const Ptr_CNode & Tail) throw ()
{
    m_Tail = Tail;
}

TEMPLINL
bool SDDLIST::Empty () const throw ()
{
    return m_Head->GetNextNode() == nullptr;
}

TEMPLINL
size_type SDDLIST::size () const throw ()
{
    size_type size = 0;
    for (Ptr_CNode Ptr (m_Head->GetNextNode()); Ptr != m_Tail; Ptr = Ptr->GetNextNode())
    {
        ++size;
    }
    return size;

}

TEMPLINL
CList& SDDLIST::operator= (const CList & List) throw ()
{
    for (Ptr_CNode Ptr (List.GetHead()); Ptr != List.GetTail(); Ptr = Ptr->GetNextNode())
    {
        this->push_back(Ptr);
    }
}

TEMPLINL
void SDDLIST::push_front (const Ptr_CNode & Node) throw ()
{
    Node->SetNextNode (m_Head->GetNextNode());
    Node->SetPrecNode (m_Head);
    m_Head->GetNextNode()->SetPrecNode(Node);
    m_Head->SetNextNode(Node);
}

TEMPLINL
void SDDLIST::pop_front () throw ()
{
    this->remove(m_Head->GetNextNode());

}

TEMPLINL
void SDDLIST::push_back (const Ptr_CNode & Node) throw ()
{
    Node->SetNextNode (m_Tail);
    Node->SetPrecNode (m_Tail->GetPrecNode());
    m_Tail->GetPrecNode->SetNextNode(Node);
    m_Tail->SetPrecNode(Node);
}

TEMPLINL
void SDDLIST::pop_back () throw()
{
    this->remove(m_Tail->GetPrecNode());
}
/* Pas sur de devoir les faire étant donnée quelles prennent un iterator en argument
void insert (unsigned Position, const Ptr_CNode & Node) throw ();
void erase (unsigned Position, const Ptr_CNode & Node) throw ();
*/

void swap (const CList & List) throw ()
{
    CList ListInter (this);
    this = List;
    List = ListInter;
}

void clear () throw ()
{

}

void remove (const Ptr_CNode & Node) throw ()
{
    Node->GetNextNode->SetPrecNode(Node->GetPrecNode());
    Node->GetPrecNode->SetNextNode(Node->GetNextNode());
    Node->SetNextNode(nullptr);
    Node->SetPrecNode(nullptr);
}

void unique () throw ()
{

}

void sort () throw ()
{

}

void reverse () throw ()
{

}

#endif // CLIST_HXX
