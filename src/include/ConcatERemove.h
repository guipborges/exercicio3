#ifndef CONCAT_E_REMOVE_H
#define CONCAT_E_REMOVE_H
//-----------------------------------------------------------------
#include <iostream>
//-----------------------------------------------------------------
#define TAMANHO 100
#define ALPHABETSIZE 26
//-----------------------------------------------------------------
/*
*   Class Concat and Remove
*
**/
class ConcatERemove
{

    public:
        //----------------
        void getData(std::string &s, std::string &t, int &k);   
        void iniciaConcatERemove();
    //----------------
    private:
        void printAnswer(bool resp);
        bool concatERemove(std::string s, std::string t, int k);
        std::string generatesRandomString(void);
        bool checkIfAlphabets(std::string alphabeta);
        void toLowerCase(std::string s);


};
#endif