/*!
 * @brief  Realizing the inference using the belief propagation algorithm.  
 * @auther Hisashi Ikari, Waseda University.
 * @file
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/exception/all.hpp>

#include "Probability.h"

using namespace std;
using namespace boost;

namespace bayesian {
    
    typedef boost::shared_ptr< vector<string> > ValuesPtr;

    /*!
     * @brief Defining the random variable.
     */
    class ProbabilityImpl
    {
    public:
        ProbabilityImpl(const std::string& name) : name_(name) { load(); }

        const ProbabilitiesPtr count(const std::string& variable, const ConditionsPtr conditions);
        const ProbabilitiesPtr count(const std::string& variable, const ConditionsPtr conditions, bool uniform);
        const ProbabilitiesPtr count(const std::string& variable, bool num);
        const ProbabilitiesPtr count(const std::string& variable);

        static const long count(const ProbabilitiesPtr probabilities);

    protected:
        void load(); 

    protected:
        const string name_;

        vector<string> titles_;
        vector<ValuesPtr> values_;
        
    };


    Probability::Probability(const string& name) : name_(name)
    {
        impl_ = new ProbabilityImpl(name);
    }


    Probability::~Probability()
    {
        if (impl_) delete impl_;
    }


    const ProbabilitiesPtr Probability::count(const std::string& variable, const ConditionsPtr conditions)
    {
        return impl_->count(variable, conditions);
    }


    const ProbabilitiesPtr Probability::count(const std::string& variable, const ConditionsPtr conditions, bool uniform)
    {
        return impl_->count(variable, conditions, uniform);
    }


    const ProbabilitiesPtr Probability::count(const std::string& variable, bool num)
    {
        return impl_->count(variable, num);
    }


    const ProbabilitiesPtr Probability::count(const std::string& variable)
    {
        return impl_->count(variable);
    }


    void ProbabilityImpl::load()
    {
        titles_.clear();
        values_.clear();

        ifstream* ifs = new ifstream(name_.c_str(), ios::in);

        ValuesPtr row;
        string line;

        bool first = true;
        while (!ifs->eof() && getline(*ifs, line)) {
            if (!first) row = ValuesPtr(new vector<string>);
            split((first ? titles_ : *row), line, is_any_of(","));
            if (!first) values_.push_back(row); 
            if ( first) first = false;
        }

        if (ifs) {
            ifs->close();
            delete ifs;
        }
    }


    const ProbabilitiesPtr ProbabilityImpl::count(const std::string& variable, const ConditionsPtr conditions)
    {
        vector<string>::iterator iters = find(titles_.begin(), titles_.end(), variable); 
        int index = iters - titles_.begin();
        if (index == titles_.size()) index--;

        ProbabilitiesPtr result = ProbabilitiesPtr(new Probabilities);

        for (vector<ValuesPtr>::iterator iterv = values_.begin(); iterv != values_.end(); iterv++) {
            ValuesPtr row = *iterv;

            bool matchValue = true;
            int  matchTitle = 0; 

            for (int col = 0; col < row->size(); col++) {
                for (Conditions::iterator iterk = conditions->begin(); iterk != conditions->end(); iterk++) {
                    if (equals(titles_[col], iterk->first)) {
                        matchTitle++;
                        if (!equals(row->at(col), iterk->second)) {
                            matchValue = false;
                            goto AGGREGATE;       
                        }
                    }
                }
            }

    AGGREGATE: 
            if (matchValue && matchTitle == conditions->size()) {
                if (index < row->size()) {
                    string column = row->at(index);
                    Probabilities::iterator iterp = result->find(column);
                    if (iterp == result->end()) {
                        result->insert(pair<string, double>(column, 1.0));
                    } else {
                        iterp->second = iterp->second + 1;
                    }
                }
            }

        }   

        return result;
    }


    const ProbabilitiesPtr ProbabilityImpl::count(const std::string& variable, const ConditionsPtr conditions, bool frequency)
    {
    }


    const ProbabilitiesPtr ProbabilityImpl::count(const std::string& variable, bool num)
    {
    }


    const ProbabilitiesPtr ProbabilityImpl::count(const std::string& variable)
    {
    }


    const long ProbabilityImpl::count(const ProbabilitiesPtr probabilities)
    {
    }


}; // end of namespace


