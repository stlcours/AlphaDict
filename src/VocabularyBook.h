#ifndef _VOCABULARYBOOK_H_
#define _VOCABULARYBOOK_H_
#include "tinyxml2/tinyxml2.h"

#include <string>
#include <list>
#include "iDB.h"

using namespace std;
using namespace tinyxml2;

#define VB_CAPACITY  5000

struct VBookItem 
{
	string word;
    string expl;
    int count;
    int complexity;
    string date;
};

class VocabularyBook
{
public:
    VocabularyBook();
    VocabularyBook(const string&  bookfile);
    bool load(const string& bookfile);

    bool add(const string& word);
    bool add(const string& word, const string& expl);
    void remove(const int row);
    void clear();
    int size() const;
    int colummCount() const { return 3; }
    string getWord(const int row) const;
    string getExpl(const int row) const;
    VBookItem getItem(const int row) const;
    void setComplexity(const int row, int cmplx);

private:
    static const string s_tblWordColumnName[];
    static const string s_tblWordColumnType[];
    static const int s_tblWordRowLen;
    static const string s_tblWordName;

    VBookItem getItem(const string& word) const;
    void updateCount(const string& word, int count);
    void updateComplexity(const string& word, int cmplx);
    int getCount(const string& word);
    void incCount(const string& word);

    // -1(NPOS) : not found. 
    int findRow(const string& word);

    int m_total;

    bool wordExist(const string& word);

    int m_quantity;
    bool loadDB(const string& bookfile);
    bool loadXml(const string& bookfile);

    mutable vector<struct VBookItem> m_wdlist;
    string m_bookpath;
    int m_cacheRow;
    VBookItem m_cacheItem;
    iDB* m_db;
};

#endif
