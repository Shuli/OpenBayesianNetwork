/*!
 * @brief  Realizing the inference using the belief propagation algorithm.  
 * @auther Hisashi Ikari, Waseda University.
 * @file
 */
#ifndef BAYESIAN_PROBABILITY_H_INCLUDED
#define BAYESIAN_PROBABILITY_H_INCLUDED

namespace bayesian {

    class Probability;
    class ProbabilityImpl;

    typedef std::map<std::string, double> Probabilities; 
    typedef std::vector< std::pair<std::string, std::string> > Conditions;

    typedef boost::shared_ptr<Probability> ProbabilityPtr; 
    typedef boost::shared_ptr<Probabilities> ProbabilitiesPtr; 
    typedef boost::shared_ptr<Conditions> ConditionsPtr; 

    /*!
     * @brief Defining the real data.
     */
    class Probability
    {
    public:
        Probability(const std::string& name);
        ~Probability();

        const ProbabilitiesPtr count(const std::string& variable, const ConditionsPtr conditions);
        const ProbabilitiesPtr count(const std::string& variable, const ConditionsPtr conditions, bool frequency);
        const ProbabilitiesPtr count(const std::string& variable, bool num);
        const ProbabilitiesPtr count(const std::string& variable);

        static const long count(const ProbabilitiesPtr probabilities);

    protected:
        const std::string name_;

    private:
        ProbabilityImpl* impl_;

    };

}; // end of namespace

#endif


