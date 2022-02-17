/**
 * PersonalFactory.h
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef PERSONAL_FACTORY_H
#define PERSONAL_FACTORY_H

#include "Personal.h"

/**
 * PersonalFactory class - Singleton pattern
 *
 * This class is used to generate Personal interface.
 */
class PersonalFactory {
 private:
  // List of prototypes.
  std::vector<std::shared_ptr<PersonalGPA>> _prototypes;

  /**
   * PersonalFactory default constructor
   *
   * @return void
   */
  PersonalFactory();

 public:
  /**
   * PersonalFactory destructor
   *
   * @return void
   */
  ~PersonalFactory();

 public:
  /**
   * Init a new instance.
   *
   * @return std::shared_ptr<PersonalFactory>
   */
  static std::shared_ptr<PersonalFactory> instance();

  /**
   * Create a new instance of PersonalGPA
   *
   * @param  const std::vector<std::string>&
   *
   * @return std::shared_ptr<PersonalGPA>
   */
  std::shared_ptr<PersonalGPA> create(int, const std::vector<std::string> &);
};
#endif  // PERSONAL_FACTORY_H
