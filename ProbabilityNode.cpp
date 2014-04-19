/*!
 * @brief  Realizing the inference using the belief propagation algorithm.  
 * @auther Hisashi Ikari, Waseda University.
 * @file
 */
#include <string>
#include <vector>
#include <map>

#include <boost/shared_ptr.hpp>
#include <boost/exception/all.hpp>

#include "ProbabilityNode.h"

using namespace std;
using namespace boost;

namespace bayesian {

typedef vector<string> NodeElements;
typedef map<const string, const ProbabilityNodePtr> NodeRelations;
typedef map<string, ProbabilityNodePtr> Nodes;

/*!
 * @brief Defining the random variable.
 */
class ProbabilityNodeImpl
{
public:
    ProbabilityNodeImpl() : depth(-1), received(false) {}

    void addChild(const ProbabilityNodePtr child) {
        children.insert(pair<const string, const ProbabilityNodePtr>(child->name(), child));
    }
    void addParent(const ProbabilityNodePtr parent) {
        parents.insert(pair<const string, const ProbabilityNodePtr>(parent->name(), parent));
    }
    void transportMessage(const ProbabilityNodePtr source);

    double calculatePrior(const string& target);
    double calculateMessageOfPai(const string& source);
    double calculateMessageOfLambda(const string& source);
    double calculateEvidenceOfPai();
    double calculateEvidenceOfLambda();

    double calculateCpt(const string& parent, const string& statep, const string& statec);

    double calculateAllPai(const ConditionsPtr conditions);
    double calculateNormal();    

    ProbabilitiesPtr updateCptOfPai(const ConditionsPtr cond, Nodes::iterator& begin, Nodes::iterator& end, bool initial);
    ProbabilitiesPtr updateCptOfLambda(const ConditionsPtr cond, Nodes::iterator& begin, Nodes::iterator& end, bool initial);

    void updateProbability();

    static ProbabilityNodePtr create(const string& name, const ProbabilityPtr cpt);

protected:
    NodeElements elements;
    NodeRelations parents;
    NodeRelations children;

    Probabilities prior;
    Probabilities eviPai;
    Probabilities eviLambda;
    Probabilities msgPai;
    Probabilities msgLambda;
    Probabilities posterior;
    
    int depth;
    bool received;

};


ProbabilityNode::ProbabilityNode(const std::string& name, const ProbabilityPtr cpt) : name_(name), cpt_(cpt)
{
    impl_ = new ProbabilityNodeImpl;
}


ProbabilityNode::~ProbabilityNode()
{
    if (impl_) delete impl_;
}


ProbabilityNodePtr ProbabilityNodeImpl::create(const string& name, const ProbabilityPtr cpt)
{
    return boost::shared_ptr<ProbabilityNode>(new ProbabilityNode(name, cpt));
}


void ProbabilityNodeImpl::transportMessage(const ProbabilityNodePtr source)
{
}


double ProbabilityNodeImpl::calculatePrior(const string& target)
{
}


double ProbabilityNodeImpl::calculateMessageOfPai(const string& source)
{
}


double ProbabilityNodeImpl::calculateMessageOfLambda(const string& source)
{
}


double ProbabilityNodeImpl::calculateEvidenceOfPai()
{
}


double ProbabilityNodeImpl::calculateEvidenceOfLambda()
{
}


double ProbabilityNodeImpl::calculateCpt(const string& parent, const string& statep, const string& statec)
{
}


double ProbabilityNodeImpl::calculateAllPai(const ConditionsPtr conditions)
{
}


double ProbabilityNodeImpl::calculateNormal()
{
}


ProbabilitiesPtr ProbabilityNodeImpl::updateCptOfPai(const ConditionsPtr cond, Nodes::iterator& begin, Nodes::iterator& end, bool initial)
{
}


ProbabilitiesPtr ProbabilityNodeImpl::updateCptOfLambda(const ConditionsPtr cond, Nodes::iterator& begin, Nodes::iterator& end, bool initial)
{
}


void ProbabilityNodeImpl::updateProbability()
{
}


}; // end of namespace


