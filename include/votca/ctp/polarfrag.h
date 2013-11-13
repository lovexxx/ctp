#ifndef VOTCA_CTP_POLARFRAG_H
#define VOTCA_CTP_POLARFRAG_H

#include <votca/ctp/apolarsite.h>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/base_object.hpp>

namespace votca { namespace ctp {
    
    
// Forward declarations
class PolarSeg;

class PolarFrag : public std::vector<APolarSite*>
{    
public:    
    
   ~PolarFrag() { clear(); /* Polar sites cleaned by PolarSeg */ }
    int getId() const { return _id; }
    const string &getName() const { return _name; }
    const votca::tools::vec &CalcPosCenterOfGeom();
    const votca::tools::vec &CalcPosPolarWeights();
    
    // Serialization interface
    template<class Archive>
    void serialize(Archive &arch, const unsigned int version) {
        arch & boost::serialization::base_object< vector<APolarSite*> >(*this);
        arch & _id;
        arch & _name;
        arch & _pseg;
        arch & _pos;
        return;
    }
    
    friend class PolarSeg;
    friend class boost::serialization::access;
    
    
private:
    
    PolarFrag() 
        : _id(-1), _name(""), _pseg(NULL), _pos(vec(0,0,0)) {}
    PolarFrag(PolarSeg *pseg, int id, string name)
        : _id(id), _name(name), _pseg(pseg), _pos(vec(0,0,0)) {}
    
    int _id;
    string _name;
    PolarSeg *_pseg;
    votca::tools::vec _pos;
};

}}

#endif