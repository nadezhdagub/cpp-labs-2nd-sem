#ifndef B7_FUNCTOR_HPP
#define B7_FUNCTOR_HPP

class Functor
{
public:
  Functor();

  void operator ()(long long int num);

  void getAll() const;
  long long int getMax() const;
  long long int getMin() const;
  double getMean() const;
  unsigned int getPositive() const;
  unsigned int getNegative() const;
  long long int getOddSum() const;
  long long int getEvenSum() const;
  bool getFirstEqualLast() const;

private:
  long long int max_;
  long long int min_;
  double mean_;
  unsigned int positive_;
  unsigned int negative_;
  long long int oddSum_;
  long long int evenSum_;
  bool firstEqualLast_;
  long long int first_;
  long long int last_;
  unsigned int listCount_;
};



#endif //B7_FUNCTOR_HPP
