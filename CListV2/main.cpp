#include <iostream>			// cout
#include <ctime>            //srand(), rand()

#include "CNode.h"			// CNode
#include "CDuree.h"			// CDuree
#include "IziAssert.h"      // IZI_ASSERT()
#include "CList.h"

using namespace std;
using namespace nsSdD;
using namespace nsUtil;

namespace
{
    int Rand (int min, int max)
    {
        return rand()% max + min;
    }

    template <typename T>
    /*void afficher(const CList<T> & List) noexcept
    {
        cout << "Affichage de la liste" << endl;
        for (It; Ptr != List.back()->GetSuivant(); Ptr = Ptr->GetSuivant())
        {
            cout << Ptr->GetData() << endl;
        }
        cout << "fin de la liste" << endl;
    } */

    void TestCDuree()
    {

        cout << "lol" << endl;
        CList<int> listeDuree;
        //afficher(listeDuree);
        /*listeDuree.push_front(2);
        listeDuree.push_front(5);
        //unsigned size = listeDuree.size();
        listeDuree.reverse();
        //afficher(listeDuree);
        bool fal = listeDuree.empty();
        CList<int> liste;
        unsigned maxsize = listeDuree.max_size();
        fal = liste.empty();
        cout << endl << maxsize << endl << fal << endl;
        liste.swap(listeDuree);
        liste.unique();
        listeDuree.push_front(8);
        liste.merge(listeDuree);
        liste.assign(4, 100);
        //afficher(liste);
        //afficher(listeDuree);
        CList<int> liste3;
        liste3.push_back(5);
        liste.sort();
        //afficher(liste3);
        //listeDuree.push_front(4);
        //listeDuree.remove(2);
        //CList<int> listeDuree2(listeDuree);   //copie de listeDuree
        //CList<int> listeDuree3 (5, -3);

       cout << "On créer 1 CListe de " << "\033[34mCDUREE " << "et une copie de ce " << "\033[34mCList" << endl;
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien égaux" << endl;
       IZI_ASSERT(listeDuree == listeDuree2);

       // Test push_front() et pop_front()
       cout << "On ajoute un" << "\033[34mCDUREE " << "au début de la première "<< "\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.push_front(new CDUREE::CDuree(Rand(1,300))));
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien différents" << endl;
       IZI_ASSERT(!(listeDuree == listeDuree2));
       cout << "On supprime le" << "\033[34mCDUREE " << "au début de la première " <<"\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.pop_front());
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien égaux" << endl;
       IZI_ASSERT(!(listeDuree == listeDuree2));
       // Test push_back() et pop_back()
       cout << "On ajoute un" << "\033[34mCDUREE " << "à la fin de la première "<< "\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.push_back(new CDUREE::CDuree(Rand(1,300))));
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien différents" << endl;
       IZI_ASSERT( !(listeDuree == listeDuree2));
       cout << "On supprime le" << "\033[34mCDUREE " << "a la fin de la première " <<"\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.pop_back());
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien égaux" << endl;
       IZI_ASSERT(listeDuree == listeDuree2);
       //Test insert et erase
       //
       //   A DECOMMENTER POUR LA V2
       //
       //

       cout << "On ajoute un" << "\033[34mCDUREE " << "à la 5e position de "<< "\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.insert(5,new CDuree()));
       cout << "On vérifie que les 2" << "\033[34mCList" << "soit bien différents" << endl;
       IZI_ASSERT( !(listeDuree == listeDuree2));
       cout << "On supprime le" << "\033[34mCDUREE " << "à la 5e position de "<< "\033[34mCList" << endl;
       IZI_ASSERT(listeDuree.erase(5));
       */

    }
}
int main()
{
    //srand(time(NULL));
    //TestCDuree();
    cout << "helloword" << endl;
    return 0;
}
