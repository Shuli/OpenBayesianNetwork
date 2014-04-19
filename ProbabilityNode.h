/*!
 * @brief  Realizing the inference using the belief propagation algorithm.  
 * @auther Hisashi Ikari, Waseda University.
 * @file
 */
#ifndef BAYESIAN_PROBABILITY_NODE_H_INCLUDED
#define BAYESIAN_PROBABILITY_NODE_H_INCLUDED

#include "Probability.h"

namespace bayesian {

class ProbabilityNode;
class ProbabilityNodeImpl;

typedef boost::shared_ptr<ProbabilityNode> ProbabilityNodePtr;

/*!
 * @brief Defining the random variable.
 */
class ProbabilityNode
{
public:
    ProbabilityNode(const std::string& name, const ProbabilityPtr cpt);
    ~ProbabilityNode();

    const std::string& name() const { return name_; }

    void addChild(const ProbabilityNodePtr child);
    void addParent(const ProbabilityNodePtr parent);

    static const ProbabilityNodePtr create(const std::string& name, const ProbabilityPtr cpt);

protected:
    const std::string name_;
    const ProbabilityPtr cpt_;

private:
    ProbabilityNodeImpl* impl_;

};

}; // end of namespace

#endif


