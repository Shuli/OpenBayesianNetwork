#include <iostream>
#include <string>

#include <map>
#include <vector>
#include <boost/shared_ptr.hpp>

#include "Probability.h"

using namespace std;
using namespace bayesian;

int main(int argc, char** argv) {

    Probability prob1("simple.utf8.csv");
    ConditionsPtr cond1 = ConditionsPtr(new Conditions);
    cond1->push_back(pair<string, string>("A", "a1"));
    cond1->push_back(pair<string, string>("D", "d1"));
    
    string key1 = "B";
    ProbabilitiesPtr ret1 = prob1.count(key1, cond1);
    for (Probabilities::iterator iter1 = ret1->begin(); iter1 != ret1->end(); iter1++) {
        cout << "name:" << iter1->first << endl;
        cout << "freq:" << iter1->second << endl;
    }
    cout << endl;

    Probability prob2("stock.utf8.csv");
    ConditionsPtr cond2 = ConditionsPtr(new Conditions);
    cond2->push_back(pair<string, string>("業種", "情報・通信業"));
    
    string key2 = "出来高";
    ProbabilitiesPtr ret2 = prob2.count(key2, cond2);
    for (Probabilities::iterator iter2 = ret2->begin(); iter2 != ret2->end(); iter2++) {
        cout << "name:" << iter2->first << endl;
        cout << "freq:" << iter2->second << endl;
    }
    cout << endl;


} 
