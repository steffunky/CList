#ifndef __CNODE_HXX__
#define __CNODE_HXX__

#include "CNode.h"

#define TEMPL template<typename T>
#define TEMPLINL TEMPL inline

#define SDDELEM nsSdD::CNode<T>

TEMPLINL
SDDELEM::CNode (const T & Data,
                const Ptr_CNode & Suivant,
                const Ptr_CNode & Precedent) noexcept
: m_Data (Data), m_Suivant(Suivant), m_Precedent(Precedent)
{

}

TEMPLINL
SDDELEM::~CNode  () noexcept
{

}

TEMPLINL
T SDDELEM::GetData () const noexcept
{
    return m_Data;
}

TEMPLINL
typename SDDELEM::Ptr_CNode SDDELEM::GetSuivant () const noexcept
{
    return m_Suivant;
}

TEMPLINL
typename SDDELEM::Ptr_CNode SDDELEM::GetPrecedent () const noexcept
{
    return m_Precedent;
}

TEMPLINL
void SDDELEM::SetData (const T & Data) noexcept
{
    m_Data = Data;
}

TEMPLINL
void SDDELEM::SetSuivant (const Ptr_CNode & Suivant) noexcept
{
    m_Suivant = Suivant;
}

TEMPLINL
void SDDELEM::SetPrecedent (const Ptr_CNode & Precedent) noexcept
{
    m_Precedent = Precedent;
}

TEMPLINL
nsSdD::CNode<T>& SDDELEM::operator= (const Ptr_CNode & val) noexcept
{
    m_Data = val.GetData();
    m_Suivant = val.GetSuivant();
    m_Precedent = val.GetPrecedent();
}

#endif // CNODE_HXX
