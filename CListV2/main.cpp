#include <iostream>			// cout
//#include <ctime>            //srand(), rand()
#include "CNode.h"			// CNode
#include "CDuree.h"			// CDuree
#include "IziAssert.h"      // IZI_ASSERT()
#include "CList.h"          // CList
#include <vector>           //vector<T>
//#include <boost/algorithm/string.hpp> //toupper

using namespace std;
using namespace nsSdD;
using namespace nsUtil;

namespace
{
    template <typename T>
    bool areListsEquals(const CList<T> &list1, const CList<T> &list2)
    {
        if (list1.size() != list2.size())
            return false;
        CIterator<T> elem1;
        CIterator<T> elem2;
        for (elem1 = list1.begin(), elem2 = list2.begin();
              elem1 != list1.end();
              ++elem1, ++elem2)
             if (!(elem1->GetData() == elem2->GetData()))
                return false;
        return true;
    }

    void showResults(vector<bool> &tabRes, vector<string> &tabIndics, const char* typeElem)
    {
        cout << "\033[37mDEBUT COMPTE RENDU POUR : " << typeElem << endl;
        for (unsigned i = 0; i < tabRes.size(); ++i )
        {
             if (tabRes[i])
                 cout << "\033[32mSuccès pour";
            else
             {
                 cout << "\033[31mQuelquechose cloche ";
                 if (i == 9)
                     cout << "sort() (veuillez verifier là où le IZI_ASSERT s'est planté, en effet on suppose que "
                          << "la liste n'est pas triée (generation de 15 valeurs aléatoires))";
             }
            cout << "pour "<< tabIndics[i]<< endl;
        }
        cout << "\033[37mFIN COMPTE RENDU POUR : " << typeElem << endl;
    }

    int Rand (int min, int max)
    {
        return rand()% max + min;
    }

    template <typename T>
    void afficherList(const CList<T> & List) noexcept
    {
        cout << "\n\nAffichage de la liste " << endl;
        for (CIterator<T> It(List.begin()); It != List.end(); ++It)
        {
            cout << It->GetData() << "; ";
        }
        cout << "\nfin de la liste \n\n" << endl;
    }

    template <typename T>
    void TestGene(vector<bool> &tabRes,const vector<T> &tabElem, const char* typeElem)
    {

        cout << "DEBUT DES TESTS DE " << typeElem << endl;
        CList<T> liste1(3,tabElem[0]);
        CList<T> liste2(3,tabElem[0]);

       cout << "\33[37mOn créer 1 \033[34mCList\33[37m de " <<   typeElem <<": \033[35mliste1\33[37m "
            << "et une copie de ce " << "\033[34mCList\33[37m de " << typeElem <<" : \033[35mliste2\33[37m" << endl;
       cout << "\33[37mOn vérifie que les 2 " << "\033[34mCList\33[37m " << "soit bien égales" << endl;
       IZI_ASSERT(tabRes[0] = areListsEquals(liste1,liste2));

       // Test push_front() et pop_front()

       cout << "\33[37mOn ajoute un " << typeElem << " au début de la première "<< "\033[34mCList\33[37m" << endl;
       liste1.push_front(tabElem[1]);
       cout << "\33[37mOn vérifie que les 2" << " \033[34mCList\33[37m " << "soit bien différentes" << endl;
       IZI_ASSERT(tabRes[1] = !(areListsEquals(liste1,liste2)));
       cout << "\33[37mOn supprime le " << typeElem << " au début de la première " <<"\033[34mCList\33[37m" << endl;
       liste1.pop_front();
       cout << "\33[37mOn vérifie que les 2" << " \033[34mCList\33[37m " << "soit bien égales" << endl;
       IZI_ASSERT(tabRes[2] = areListsEquals(liste1,liste2));

       // Test push_back() et pop_back()

       cout << "\33[37mOn ajoute un " << typeElem << " à la fin de la première "<< "\033[34mCList\33[37m" << endl;
       liste1.push_back(tabElem[1]);

       cout << "\33[37mOn vérifie que les 2 " << "\033[34mCList\33[37m " << "soit bien différents" << endl;
       IZI_ASSERT(tabRes[3] = !(areListsEquals(liste1,liste2)));
       cout << "\33[37mOn supprime le " << typeElem << " a la fin de la première " <<"\033[34mCList\33[37m" << endl;
       liste1.pop_back();
       cout << "\33[37mOn vérifie que les 2 " << "\033[34mCList\33[37m " << "soit bien égales" << endl;
       IZI_ASSERT(tabRes[4] = areListsEquals(liste1,liste2));

       // Test swap()

       cout << "\33[37mOn créer une \033[34mCList\33[37m de " << typeElem << " : \033[35mlistee3\33[37m "
            << "et une copie de ce " << "\033[34mCList\33[37m de"<< typeElem <<" : \033[35mliste4\33[37m" << endl;
       CList<T> liste3(5,tabElem[2]);
       CList<T> liste4(5,tabElem[2]);
       liste3.push_back(tabElem[3]);
       liste4.push_back(tabElem[3]);

       cout << "\33[37mOn echange les " << "\033[34mCNODE\33[37m " << "de \033[35mliste2\33[37m et \033[35mliste3\33[37m" << endl;
       liste2.swap(liste3);

       cout << "\33[37mOn vérifie que les " << "\033[34mCList\33[37m \033[35mliste2\33[37m et \033[35mliste4\33[37m "
            << "ainsi que \033[35mliste1\33[37m et \033[35mliste3\33[37m " <<"soit bien égales" << endl;

       IZI_ASSERT(tabRes[5] = (areListsEquals(liste2,liste4) && areListsEquals(liste1,liste3)) );

       // test clear()
      cout << "\33[37mOn supprime le contenu " << "de \033[35mliste3\33[37m " << "et on vérifie qu'elle soit vide" << endl;
      liste3.clear();
      IZI_ASSERT(tabRes[6] = liste3.empty());

      //test remove

      cout << "\33[37mOn supprime un " << typeElem << " dont on sait que sa donnée est présente dans la "
           << "\033[34mCList\33[37m :\0CDuree33[35mliste4\33[37m" << endl;
      liste4.remove(liste4.end()->GetData());
      cout << "\33[37mOn vérifie que les " << "\033[34mCList\33[37m \033[35mliste2\33[37m et \033[35mliste4\33[37m "
           << "soit bien différents" << endl;
      IZI_ASSERT(tabRes[7] = !(areListsEquals(liste1,liste2)));

       cout << "\33[37mOn créer une \033[34mCList\33[37m de " << typeElem << " : \033[35mliste5\33[37m "<<
                "dont toutes les données des \033[34mCNODE\33[37m sont les mêmes et on affiche sa taille \n" << endl;

       CList<T> liste5(4,tabElem[4]);

       //test unique()
       cout <<"\t Taille de \033[35mliste5\33[37m : \033[36m" << liste5.size() << '\n' << endl;
       cout << "\33[37mOn applique la fonction qui supprime tout les doublons, la taille doit donc être de \033[36m 1 \033[37m \t"
            << endl;
       liste5.unique();
        IZI_ASSERT(tabRes[8] = (liste5.size() == 1));
       //cout <<"\t Taille de \033[35mliste5\33[37m : \033[36m" << Test5.size() << '\n' << endl;

       cout << "\33[37m On ajoute des valeurs aléatoires à \033[35mliste5\33[37m et on affiche cette \033[34mCList\33[37m" << endl;
       for (int i = 0; i < 15; ++i)
       {
            liste5.push_back(tabElem[6 + i]);
       }

       afficherList(liste5);
       //sort
       CList<T> liste5old = liste5;
       cout << "\33[37mOn range cette \033[34mCList\33[37m avec sort() et on affiche \033[35mliste5\33[37m"
            << endl;
       liste5.sort();

       afficherList(liste5);
       IZI_ASSERT(tabRes[9] = !(areListsEquals(liste5old, liste5)))
       //reverse
       CList<T> liste5sort = liste5;
       cout << "\33[37mOn inverse l'ordre des valeurs de \033[35mliste5sort\33[37m grâce à reverse et on l'affiche" << endl;
       liste5.reverse();
       afficherList(liste5);
       IZI_ASSERT(tabRes[10] = !(areListsEquals(liste5, liste5sort)))

       cout << "\33[37mOn affiche \033[35mliste1\33[37m et \033[35mliste5\33[37m \n," <<
               "on les fusionnes et on affiche le résultat qu'on insert dans \033[35mliste5\33[37m" << endl;

       cout << "\n\n\033[35mliste1\33[37m :"<< endl;
       afficherList(liste1);
       cout <<"\n\n\033[35mliste5\33[37m :" << endl;
       afficherList(liste5);
       unsigned taille1et5;
       cout << "Taille de \033[35mliste1\33[37m + \033[35mliste5\33[37m :" << (taille1et5 = liste1.size() + liste5.size()) << endl;
       liste5.merge(liste1);
       cout << "\n\n \033[35mliste1\33[37m + \033[35mliste5\33[37m" << endl;
       afficherList(liste5);

       IZI_ASSERT( tabRes[11] = (taille1et5 == liste5.size()));
       //faire assign && maxsize

       cout << "\33[37mOn créer une \033[34mCList\33[37m de " << typeElem << " : \033[35mliste6\33[37m  vide"
            << "et une seconde  \033[34mCList\33[37m de " << typeElem << " : \033[35mliste7\33[37m contenant 3 "
            << typeElem << " identiques" << endl;

        CList<T> liste6;
        CList<T> liste7(3,tabElem[5]);

        cout << "\33[37mOn vérifie que les " << "\033[34mCList\33[37m \033[35mliste6\33[37m et \033[35mliste7\33[37m "
             << "soit bien différentes" << endl;
        IZI_ASSERT( tabRes[12] = !(areListsEquals(liste6,liste7)));

        cout << "\33[37mOn assigne 3 valeurs à \033[35mliste6\33[37m (les mêmes que celles de \033[35mliste7\33[37m )"
             << "grâce à assign(3,Val) et on compare les 2 \033[34mCList\33[37m" << endl;
       liste6.assign(3,tabElem[5]);

       IZI_ASSERT( tabRes[13] = areListsEquals(liste6,liste7));

       cout << "\33[37mOn créer une \033[34mCList\33[37m de " << typeElem << " : \033[35mliste8\33[37m  contenant 5"
            << typeElem << ", les mêmes que  \033[35mliste6\33[37m et  \033[35mliste7\33[37m" << endl;
       CList<T> liste8(5,tabElem[5]);
       cout << "\33[37mOn vérifie que les " << "\033[34mCList\33[37m \033[35mliste6\33[37m et \033[35mliste8\33[37m "
            << "soit bien différentes" << endl;

       IZI_ASSERT(!(areListsEquals(liste6,liste8)));

       cout << "On change la taille de \033[35mliste6\33[37m de 3 à 5 " << typeElem  << " , en comblant les 2 cases ajoutées"
            << "avec le même " << typeElem <<" que dans le reste de la \033[34mCList\33[37m grâce à resize(5,Val)" <<
               "et on vérifie que \033[35mliste6\33[37m et \033[35mliste8\33[37m soit bien égaux" << endl;
       liste6.resize(5,tabElem[5]);

       IZI_ASSERT(tabRes[14] = areListsEquals(liste6,liste8));

       cout <<"On tronque maintenant \033[35mliste6\33[37m à 3 éléments, il devrait donc être égal à \033[35mliste7\33[37m"
            <<", on utilise donc resize(3), et on vérifie l'égalité" << endl;

       liste6.resize(3);

       // Test max_size
       IZI_ASSERT(tabRes[15] = areListsEquals(liste6,liste7));

       // test front () back ()
       cout <<"On veut maintenant savoir si begin() et rbegin() renvoient bien des iterators sur le premier et"
            << "le dernier élément de \033[35mliste6\33[37m"
            << endl;
       IZI_ASSERT(tabRes[16] = (liste6.begin()->GetData() == liste6.front() &&
                                       liste6.back() == liste6.rbegin()->GetData()));

       //test it begin, it end
       cout << "La taille maximum de notre \033[34mCList\33[37m donnée par max_size est: " << liste8.max_size() << endl;

       cout <<"On veut savoir si (begin, cbegin, ++rend, ++crend) sont égaux et (end, cend, ++rbegin, ++crbegin) de \033[35mliste5\33[37m aussi"
           << endl;

       cout << "On ajoute un élément à la position CList.begin de \033[35mliste5\33[37m et à la position CList.end(), on vérifie ensuite"
            << "que les valeurs soit bien celles ajoutés" << endl;

       liste5.insert(liste5.begin(), tabElem[1]);
       liste5.insert(liste5.end(), tabElem[1]);
       IZI_ASSERT(tabRes[17] = liste5.begin()->GetData() == liste5.front() && liste5.end()->GetData() == liste5.back())
       cout << "On effectue l'inverse en appliquant erase() sur Clist.begin et erase sur Clist.end";
       liste5.erase(liste5.begin());
       liste5.erase(liste5.end());
       IZI_ASSERT(tabRes[18] = !(liste5.begin()->GetData() == liste5.front() && liste5.end()->GetData() == liste5.back()))

       //test slice
       cout << "Maintenant on va echanger le contenu de \033[35mliste1\33[37m et \033[35mliste5\33[37m et le comparer à leur anciennes valeurs"
            << endl;
       CList<T> liste1ancien = liste1;

       liste1.splice(liste1.end(), liste5);
       IZI_ASSERT(tabRes[19] = (areListsEquals(liste5,liste1ancien)));


       cout << "FIN DES TESTS DE " << typeElem << endl;


    }
}


int main()
{

    srand(time(NULL));
    // CDUREE
    vector<bool> tabResDuree(21);
    vector<CDuree> tabParamsDuree {CDuree(200),CDuree(10),CDuree(11),CDuree(8),CDuree(5),CDuree(10)};
    for (unsigned i = 0; i< 15 ; ++i)
    {
        tabParamsDuree.push_back(CDuree(Rand(0,300)));
    }
    TestGene<CDuree>(tabResDuree, tabParamsDuree, "\033[34mCDUREE\33[37m");

    // INT
    vector<bool> tabResInt(21);
    vector<int> tabParamsInt {200, 10, 11, 8, 5, 10};
    for (unsigned i = 0; i < 15 ; ++i)
    {
        tabParamsInt.push_back(Rand(0,300));
    }
    TestGene<int>(tabResInt,tabParamsInt, "\033[34mINTEGER\33[37m");
    // PTR
    vector<bool> tabResPtr(21);
    int a = 200, b= 10, c= 11, d= 8, e = 5, f= 10;
    vector<int*> tabParamsPtr {&a,&b,&c,&d,&e,&f};
    int g ;

    //
    for (unsigned i = 0; i < 15 ; ++i)
    {
        g = int(Rand(0,300));
        tabParamsPtr.push_back(&g);
    }
    TestGene<int*>(tabResPtr,tabParamsPtr, "\033[34mPOINTER\33[37m");


    // AFFICHAGE COMPTE RENDU
    vector <string> tabIndics { "contructeur(taille,elem)", "push_front(elem)", "pop_front()", "push_back(elem)","pop_back()",
                               "swap()", "clear()", "remove(val)", "unique()", "sort()", "reverse", "merge(CList)","constructeur()",
                               "assign(taille,elem)", "resize(n,elem) (n > list.size())", "resize(n) (n < list.size())","front() et back()"
                                "begin(), cbegin(), rend(), crend()), end(), cend(), rbegin(), crbegin()", "insert(iterator,val"
                                "erase(iterator)", "slice(CList)"};

    showResults(tabResDuree,tabIndics,"\033[34mCDUREE\33[37m");
    showResults(tabResInt,tabIndics,"\033[34mINTEGER\33[37m");
    showResults(tabResPtr,tabIndics,"\033[34mPOINTER\33[37m");
    cout << "On explique le problème de sort sur les pointeurs car dans la boucle, l'espace ou la variable utilisée pour la génération"
         << " aléatoire reprend le même espace mémoire à chaque boucle."<< endl;

    return 0;
}



