#ifndef __CNODE_HXX__
#define __CNODE_HXX__

#include "CNode.h"

#define TEMPL template<class T>
#define TEMPLINL TEMPL inline

#define SDDELEM nsSdD::CNode<T>

#define Ptr_CNode shared_ptr<CNode<T>>


TEMPLINL
SDDELEM::CNode (const T & Data,
                const Ptr_CNode & NextNode,
                const Ptr_CNode &PrecNode) throw ()
: m_Data (Data), m_NextNode(NextNode), m_PrecNode(PrecNode)
{

}

TEMPLINL
SDDELEM::~CNode  () throw ()
{
    delete m_NextNode;
}

TEMPLINL
T SDDELEM::GetData () const throw ()
{
    return m_Data;
}

TEMPLINL
Ptr_CNode SDDELEM::GetNextNode () const throw ()
{
    return m_NextNode;
}

TEMPLINL
Ptr_CNode SDDELEM::GetPrecNode () const throw ()
{
    return m_PrecNode;
}

TEMPLINL
void SDDELEM::SetData (const T & Data) throw ()
{
    m_Data = Data;
}

TEMPLINL
void SDDELEM::SetNextNode (const Ptr_CNode & NextNode) throw ()
{
    m_NextNode = NextNode;
}

TEMPLINL
void SDDELEM::SetPrecNode (const Ptr_CNode & PrecNode) throw ()
{
    m_PrecNode = PrecNode;
}

#endif // CNODE_HXX
