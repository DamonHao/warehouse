// applySequence.h modified to use 
// member function templates
#ifndef APPLYMEMBER_H
#define APPLYMEMBER_H
template<class T, template<typename> class Seq>
class SequenceWithApply : public Seq<T*> {
public:
  // 0 arguments, any type of return value:
  template<class R>
  void apply(R (T::*f)()) {
    iterator it = begin();
    while(it != end()) {
      ((*it)->*f)();
      it++;
    }
  }
  // 1 argument, any type of return value:
  template<class R, class A>
  void apply(R(T::*f)(A), A a) {
    iterator it = begin();
    while(it != end()) {
      ((*it)->*f)(a);
      it++;
    }
  }
  // 2 arguments, any type of return value:
  template<class R, class A1, class A2>
  void apply(R(T::*f)(A1, A2), 
    A1 a1, A2 a2) {
    iterator it = begin();
    while(it != end()) {
      ((*it)->*f)(a1, a2);
      it++;
    }
  }
}; ///:~#endif